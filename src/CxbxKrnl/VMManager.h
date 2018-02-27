// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;;
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Win32->CxbxKrnl->VMManager.h
// *
// *  This file is part of the Cxbx project.
// *
// *  Cxbx and Cxbe are free software; you can redistribute them
// *  and/or modify them under the terms of the GNU General Public
// *  License as published by the Free Software Foundation; either
// *  version 2 of the license, or (at your option) any later version.
// *
// *  This program is distributed in the hope that it will be useful,
// *  but WITHOUT ANY WARRANTY; without even the implied warranty of
// *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// *  GNU General Public License for more details.
// *
// *  You should have recieved a copy of the GNU General Public License
// *  along with this program; see the file COPYING.
// *  If not, write to the Free Software Foundation, Inc.,
// *  59 Temple Place - Suite 330, Bostom, MA 02111-1307, USA.
// *
// *  (c) 2017      ergo720
// *
// *  All rights reserved
// *
// ******************************************************************

#ifndef VMMANAGER_H
#define VMMANAGER_H


#include "PhysicalMemory.h"

#define XbAllocateVirtualMemoryStub(addr, zero_bits, size, allocation_type, protect) \
		g_VMManager.XbAllocateVirtualMemory(addr, zero_bits, size, allocation_type, protect, true)
#define XbAllocateVirtualMemoryReal(addr, zero_bits, size, allocation_type, protect) \
		g_VMManager.XbAllocateVirtualMemory(addr, zero_bits, size, allocation_type, protect, false)
#define XbFreeVirtualMemoryStub(addr, size, free_type) \
		g_VMManager.XbFreeVirtualMemory(addr, size, free_type, true)
#define XbFreeVirtualMemoryReal(addr, size, free_type) \
		g_VMManager.XbFreeVirtualMemory(addr, size, free_type, false)


/* VMATypes */
enum VMAType
{
	// vma represents an unmapped region of the address space
	Free,
	// memory reserved by XbAllocateVirtualMemory
	Reserved,
	// vma represents allocated memory
	Allocated,
	// mark this vma as non-mergeable
	Lock,
};


/* VirtualMemoryArea struct */
struct VirtualMemoryArea
{
	// vma starting address
	VAddr base = 0;
	// vma size
	size_t size = 0;
	// vma kind of memory
	VMAType type = VMAType::Free;
	// initial vma permissions for user allocations, only used by NtQueryVirtualMemory
	DWORD permissions = XBOX_PAGE_NOACCESS;
	// this allocation was served by VirtualAlloc
	bool bFragmented = false;
	// tests if this area can be merged to the right with 'next'
	bool CanBeMergedWith(const VirtualMemoryArea& next) const;
};


typedef std::map<VAddr, VirtualMemoryArea>::iterator VMAIter;


/* struct representing a particular memory region of interest. Used to track and speed up searches of free areas */
typedef struct _MemoryRegion
{
	VMAIter LastFree;
	std::map<VAddr, VirtualMemoryArea> RegionMap;
}MemoryRegion, *PMemoryRegion;


/* enum describing the memory regions available for allocations on the Xbox */
enum MemoryRegionType
{
	User,
	Contiguous,
	System,
	Devkit,
	COUNT,
};


/* VMManager class */
class VMManager : public PhysicalMemory
{
	public:
		// constructor
		VMManager() {};
		// destructor
		~VMManager()
		{
			DeleteCriticalSection(&m_CriticalSection);
			FlushViewOfFile((void*)CONTIGUOUS_MEMORY_BASE, CHIHIRO_MEMORY_SIZE);
			FlushFileBuffers(m_hContiguousFile);
			FlushViewOfFile((void*)PAGE_TABLES_BASE, PAGE_TABLES_SIZE);
			FlushFileBuffers(m_hPTFile);
			UnmapViewOfFile((void *)CONTIGUOUS_MEMORY_BASE);
			UnmapViewOfFile((void*)XBOX_WRITE_COMBINED_BASE);
			UnmapViewOfFile((void*)PAGE_TABLES_BASE);
			CloseHandle(m_hContiguousFile);
			CloseHandle(m_hPTFile);
		}
		// initializes the memory manager to the default configuration
		void Initialize(HANDLE memory_view, HANDLE PT_view);
		// retrieves memory statistics
		void MemoryStatistics(xboxkrnl::PMM_STATISTICS memory_statistics);
		// allocates a block of memory
		VAddr Allocate(size_t size, PAddr low_addr = 0, PAddr high_addr = MAXULONG_PTR, ULONG Alignment = PAGE_SIZE,
			DWORD protect = PAGE_EXECUTE_READWRITE, bool bNonContiguous = true);
		// allocates a block of memory and zeros it
		VAddr AllocateZeroed(size_t size);
		// allocates memory in the system region
		VAddr AllocateSystemMemory(PageType BusyType, DWORD perms, size_t size, /*bool bDebugRange,*/ bool bAddGuardPage);
		// deallocate a block of memory
		void Deallocate(VAddr addr);
		// deallocate stack memory
		void DeallocateStack(VAddr addr);
		// changes the protections of a memory region
		void Protect(VAddr target, size_t size, DWORD new_perms);
		// query if a VAddr is valid
		bool QueryVAddr(VAddr addr);
		// translate a VAddr
		PAddr TranslateVAddr(VAddr addr);
		// retrieves the protection status of an address
		DWORD QueryProtection(VAddr addr);
		// retrieves the size of an allocation
		size_t QuerySize(VAddr addr);
		// xbox implementation of NtAllocateVirtualMemory
		xboxkrnl::NTSTATUS XbAllocateVirtualMemory(VAddr* addr, ULONG zero_bits, size_t* size, DWORD allocation_type,
			DWORD protect, bool bStub);
		// xbox implementation of NtFreeVirtualMemory
		xboxkrnl::NTSTATUS XbFreeVirtualMemory(VAddr* addr, size_t* size, DWORD free_type, bool bStub);

	
	private:
		// an array of structs used to track the free/allocated vma's in the various memory regions
		MemoryRegion m_MemoryRegionArray[MemoryRegionType::COUNT];
		// handle of the contiguous file mapping
		HANDLE m_hContiguousFile = NULL;
		// handle of the PT file mapping
		HANDLE m_hPTFile = NULL;
		// critical section lock to synchronize accesses
		CRITICAL_SECTION m_CriticalSection;
		// amount of image virtual memory in use
		size_t m_ImageMemoryInUse = 0;
		// amount of non - image virtual memory in use
		size_t m_NonImageMemoryInUse = 0;
		// the allocation granularity of the host. Needed by MapViewOfFileEx and VirtualAlloc
		DWORD m_AllocationGranularity;
	
		// set up the pfndatabase
		void InitializePfnDatabase();
		// set up the pfn database after a quick reboot (a new xbe is launched)
		void ReinitializePfnDatabase();
		// construct a vma
		void ConstructVMA(VAddr Start, size_t Size, MemoryRegionType Type, VMAType VMAType, bool bFragFlag, DWORD perms = XBOX_PAGE_NOACCESS);
		// initialize a memory region struct
		void ConstructMemoryRegion(VAddr Start, VAddr End, MemoryRegionType Type);
		// map a memory block with MapViewOfFileEx or VirtualAlloc if allowed
		VAddr MapMemoryBlock(MemoryRegionType Type, PFN_COUNT size, bool* bVAllocFlag, DWORD perms, PFN low_pfn,
			PFN high_pfn, PFN* result);
		// creates a vma representing the memory block to remove
		void UnMapMemoryBlock(VAddr target);
		// convert VirtualProtect protection flags to file mapping protection flags
		void ConvertVProtectToMapViewProtection(DWORD* perms);
		// changes access permissions for a range of vma's, splitting them if necessary
		void ReprotectVMARange(VAddr target, size_t size, DWORD new_perms);
		// checks if a VAddr is valid; returns false if not
		bool IsValidVirtualAddress(const VAddr addr);
		// translates a VAddr to its corresponding PAddr; it must be valid
		PAddr TranslateVAddrToPAddr(const VAddr addr);
		// removes a vma block from the mapped memory
		VMAIter Unmap(VMAIter vma_handle);
		// carves a vma of a specific size at the specified address by splitting free vma's
		VMAIter CarveVMA(VAddr base, size_t size, MemoryRegionType Type);
		// splits the edges of the given range of non-free vma's so that there is a vma split at each end of the range
		VMAIter CarveVMARange(VAddr base, size_t size);
		// gets the iterator of a vma in m_Vma_map
		VMAIter GetVMAIterator(VAddr target, MemoryRegionType Type);
		// splits a parent vma into two children
		VMAIter SplitVMA(VMAIter vma_handle, u32 offset_in_vma, MemoryRegionType Type);
		// merges the specified vma with adjacent ones if possible
		VMAIter MergeAdjacentVMA(VMAIter vma_handle);
		// changes access permissions for a vma
		VMAIter ReprotectVMA(VMAIter vma_handle, DWORD new_perms);
		// acquires the critical section
		void Lock();
		// releases the critical section
		void Unlock();
		// destructs a vma if not free already
		VMAIter DestructVMA(VMAIter vma_handle, VAddr addr, size_t size);
		// changes the size/base of a vma
		void ResizeVMA(VMAIter vma_handle, size_t offset, bool bStart);
};


extern VMManager g_VMManager;

#endif
