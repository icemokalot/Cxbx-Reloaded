// ******************************************************************
// *
// *    .,-:::::    .,::      .::::::::.    .,::      .:
// *  ,;;;'````'    `;;;,  .,;;  ;;;'';;'   `;;;,  .,;; 
// *  [[[             '[[,,[['   [[[__[[\.    '[[,,[['  
// *  $$$              Y$$$P     $$""""Y$$     Y$$$P    
// *  `88bo,__,o,    oP"``"Yo,  _88o,,od8P   oP"``"Yo,  
// *    "YUMMMMMP",m"       "Mm,""YUMMMP" ,m"       "Mm,
// *
// *   Cxbx->Win32->CxbxKrnl->Xapi.1.0.4361.cpp
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
// *  (c) 2002-2003 Aaron Robinson <caustik@caustik.com>
// *
// *  All rights reserved
// *
// ******************************************************************

// ******************************************************************
// * RtlCreateHeap
// ******************************************************************
SOOVPA<10> RtlCreateHeap_1_0_4361 =
{
    0,  // Large == 0
    10, // Count == 10

    {
        // RtlCreateHeap+0x13 : push 0x0C
        { 0x13, 0x6A }, // (Offset,Value)-Pair #1
        { 0x14, 0x0C }, // (Offset,Value)-Pair #2

        // RtlCreateHeap+0x1B : rep stosd
        { 0x1B, 0xF3 }, // (Offset,Value)-Pair #3
        { 0x1C, 0xAB }, // (Offset,Value)-Pair #4

        // RtlCreateHeap+0x4E : retn
        { 0x4E, 0xC3 }, // (Offset,Value)-Pair #5

        // RtlCreateHeap+0x8D : jnz +0x08
        { 0x8D, 0x75 }, // (Offset,Value)-Pair #6
        { 0x8E, 0x08 }, // (Offset,Value)-Pair #7

        // RtlCreateHeap+0xA4 : cmp [ebp-38h], esi
        { 0xA4, 0x39 }, // (Offset,Value)-Pair #8
        { 0xA5, 0x75 }, // (Offset,Value)-Pair #9
        { 0xA6, 0xC8 }, // (Offset,Value)-Pair #10
    }
};

// ******************************************************************
// * RtlAllocateHeap
// ******************************************************************
SOOVPA<11> RtlAllocateHeap_1_0_4361 =
{
    0,  // Large == 0
    11, // Count == 11

    {
        // RtlAllocateHeap+0x1E : or ecx, [esi+0x18]
        { 0x1E, 0x0B }, // (Offset,Value)-Pair #1
        { 0x1F, 0x4E }, // (Offset,Value)-Pair #2
        { 0x20, 0x18 }, // (Offset,Value)-Pair #3

        // RtlAllocateHeap+0x29 : jnz +0x01
        { 0x29, 0x75 }, // (Offset,Value)-Pair #4
        { 0x2A, 0x01 }, // (Offset,Value)-Pair #5

        // RtlAllocateHeap+0x2B : inc eax
        { 0x2B, 0x40 }, // (Offset,Value)-Pair #6

        // RtlAllocateHeap+0x73 : sub eax, 0x08
        { 0x73, 0x83 }, // (Offset,Value)-Pair #7
        { 0x74, 0xE8 }, // (Offset,Value)-Pair #8
        { 0x75, 0x08 }, // (Offset,Value)-Pair #9

        // RtlAllocateHeap+0xA5 : shl edi, cl
        { 0xA5, 0xD3 }, // (Offset,Value)-Pair #10
        { 0xA6, 0xE7 }, // (Offset,Value)-Pair #11
    }
};

// ******************************************************************
// * RtlFreeHeap
// ******************************************************************
SOOVPA<12> RtlFreeHeap_1_0_4361 =
{
    0,  // Large == 0
    12, // Count == 12

    {
        // RtlFreeHeap+0x1F : test ecx, ecx
        { 0x1F, 0x85 }, // (Offset,Value)-Pair #1
        { 0x20, 0xC9 }, // (Offset,Value)-Pair #2

        // RtlFreeHeap+0x4B : test byte ptr [edi+5], 0x08
        { 0x4B, 0xF6 }, // (Offset,Value)-Pair #3
        { 0x4C, 0x47 }, // (Offset,Value)-Pair #4
        { 0x4D, 0x05 }, // (Offset,Value)-Pair #5
        { 0x4E, 0x08 }, // (Offset,Value)-Pair #6

        // RtlFreeHeap+0x5B : push 0
        { 0x5B, 0x6A }, // (Offset,Value)-Pair #7
        { 0x5C, 0x00 }, // (Offset,Value)-Pair #8

        // RtlFreeHeap+0x8F : cmp [edx], edx
        { 0x8F, 0x39 }, // (Offset,Value)-Pair #9
        { 0x90, 0x12 }, // (Offset,Value)-Pair #10

        // RtlFreeHeap+0xA4 : shl ebx, cl
        { 0xA4, 0xD3 }, // (Offset,Value)-Pair #11
        { 0xA5, 0xE3 }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * XGetDevices
// ******************************************************************
SOOVPA<14> XGetDevices_1_0_4361 =
{
    0,  // Large == 0
    14, // Count == 14

    {
        // XGetDevices+0x07 : mov edx, [esp+arg_0]
        { 0x07, 0x8B }, // (Offset,Value)-Pair #1
        { 0x08, 0x54 }, // (Offset,Value)-Pair #2
        { 0x09, 0x24 }, // (Offset,Value)-Pair #3
        { 0x0A, 0x08 }, // (Offset,Value)-Pair #4

        // XGetDevices+0x0D : and [edx+4], 0
        { 0x0D, 0x83 }, // (Offset,Value)-Pair #5
        { 0x0E, 0x62 }, // (Offset,Value)-Pair #6
        { 0x0F, 0x04 }, // (Offset,Value)-Pair #7
        { 0x10, 0x00 }, // (Offset,Value)-Pair #8

        // XGetDevices+0x11 : mov cl, al
        { 0x11, 0x8A }, // (Offset,Value)-Pair #9
        { 0x12, 0xC8 }, // (Offset,Value)-Pair #10

        // XGetDevices+0x16 : call KfLowerIrql
        { 0x16, 0xFF }, // (Offset,Value)-Pair #11
        { 0x17, 0x15 }, // (Offset,Value)-Pair #12

        // XGetDevices+0x1F : retn 4
        { 0x1F, 0xC2 }, // (Offset,Value)-Pair #13
        { 0x20, 0x04 }, // (Offset,Value)-Pair #14
    }
};

// ******************************************************************
// * XInputOpen
// ******************************************************************
SOOVPA<12> XInputOpen_1_0_4361 =
{
    0,  // Large == 0
    12, // Count == 12

    {
        // XInputOpen+0x14 : push 0x57
        { 0x14, 0x6A }, // (Offset,Value)-Pair #1
        { 0x15, 0x57 }, // (Offset,Value)-Pair #2

        // XInputOpen+0x1D : jmp +0x33
        { 0x1D, 0xEB }, // (Offset,Value)-Pair #3
        { 0x1E, 0x33 }, // (Offset,Value)-Pair #4

        // XInputOpen+0x33 : add edx, 0x10
        { 0x33, 0x83 }, // (Offset,Value)-Pair #5
        { 0x34, 0xC2 }, // (Offset,Value)-Pair #6
        { 0x35, 0x10 }, // (Offset,Value)-Pair #7

        // XInputOpen+0x47 : jmp +0x06
        { 0x47, 0x75 }, // (Offset,Value)-Pair #8
        { 0x48, 0x06 }, // (Offset,Value)-Pair #9

        // XInputOpen+0x52 : leave
        { 0x52, 0xC9 }, // (Offset,Value)-Pair #10

        // XInputOpen+0x53 : retn 0x10
        { 0x53, 0xC2 }, // (Offset,Value)-Pair #11
        { 0x54, 0x10 }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * XInputGetCapabilities
// ******************************************************************
SOOVPA<14> XInputGetCapabilities_1_0_4361 =
{
    0,  // Large == 0
    14, // Count == 14

    {
        // XInputGetCapabilities+0x03 : sub esp, 0x48
        { 0x03, 0x83 }, // (Offset,Value)-Pair #1
        { 0x04, 0xEC }, // (Offset,Value)-Pair #2
        { 0x05, 0x48 }, // (Offset,Value)-Pair #3

        // XInputGetCapabilities+0x24 : test byte ptr [esi+4], 2
        { 0x24, 0xF6 }, // (Offset,Value)-Pair #4
        { 0x25, 0x46 }, // (Offset,Value)-Pair #5
        { 0x26, 0x04 }, // (Offset,Value)-Pair #6
        { 0x27, 0x02 }, // (Offset,Value)-Pair #7

        // XInputGetCapabilities+0x3A : stosb
        { 0x3A, 0xAA }, // (Offset,Value)-Pair #8

        // XInputGetCapabilities+0x7D : mov [ebp+var_48], 0x30
        { 0x7D, 0xC6 }, // (Offset,Value)-Pair #9
        { 0x7E, 0x45 }, // (Offset,Value)-Pair #10
        { 0x7F, 0xB8 }, // (Offset,Value)-Pair #11
        { 0x80, 0x30 }, // (Offset,Value)-Pair #12

        // XInputGetCapabilities+0xEE : cmp [eax], ebx
        { 0xEE, 0x39 }, // (Offset,Value)-Pair #13
        { 0xEF, 0x18 }, // (Offset,Value)-Pair #14
    }
};

// ******************************************************************
// * XInputGetState
// ******************************************************************
SOOVPA<12> XInputGetState_1_0_4361 =
{
    0,  // Large == 0
    12, // Count == 12

    {
        // XInputGetState+0x0E : mov ecx, [edx+0x0A3]
        { 0x0E, 0x8B }, // (Offset,Value)-Pair #1
        { 0x0F, 0x8A }, // (Offset,Value)-Pair #2
        { 0x10, 0xA3 }, // (Offset,Value)-Pair #3

        // XInputGetState+0x1D : push 0x57
        { 0x1D, 0x6A }, // (Offset,Value)-Pair #4
        { 0x1E, 0x57 }, // (Offset,Value)-Pair #5

        // XInputGetState+0x20 : jmp +0x3E
        { 0x20, 0xEB }, // (Offset,Value)-Pair #6
        { 0x21, 0x3E }, // (Offset,Value)-Pair #7

        // XInputGetState+0x2E : mov ebx, 0x048F
        { 0x2E, 0xBB }, // (Offset,Value)-Pair #8
        { 0x2F, 0x8F }, // (Offset,Value)-Pair #9
        { 0x30, 0x04 }, // (Offset,Value)-Pair #10

        // XInputGetState+0x6C : retn 8
        { 0x6C, 0xC2 }, // (Offset,Value)-Pair #11
        { 0x6D, 0x08 }, // (Offset,Value)-Pair #12
    }
};

// ******************************************************************
// * CreateThread
// ******************************************************************
SOOVPA<8> CreateThread_1_0_4361 =
{
    0,  // Large == 0
    8,  // Count == 8

    {
        // CreateThread+0x0A : mov eax, ds:10130h
        { 0x0A, 0xA1 }, // (Offset,Value)-Pair #1
        { 0x0B, 0x30 }, // (Offset,Value)-Pair #2
        { 0x0C, 0x01 }, // (Offset,Value)-Pair #3

        // CreateThread+0x1C : and ecx, 0xFFFFFF01
        { 0x1C, 0x81 }, // (Offset,Value)-Pair #4
        { 0x1D, 0xE1 }, // (Offset,Value)-Pair #5
        { 0x1E, 0x01 }, // (Offset,Value)-Pair #6

        // CreateThread+0x6B : retn 0x18
        { 0x6B, 0xC2 }, // (Offset,Value)-Pair #7
        { 0x6C, 0x18 }  // (Offset,Value)-Pair #8
    }
};

// ******************************************************************
// * CloseHandle
// ******************************************************************
SOOVPA<10> CloseHandle_1_0_4361 =
{
    0,  // Large == 0
    10, // Count == 10

    {
        // CloseHandle+0x00 : push [esp+4]
        { 0x00, 0xFF }, // (Offset,Value)-Pair #1
        { 0x01, 0x74 }, // (Offset,Value)-Pair #2
        { 0x02, 0x24 }, // (Offset,Value)-Pair #3
        { 0x03, 0x04 }, // (Offset,Value)-Pair #4

        // CloseHandle+0x04 : call ds:[addr]
        { 0x04, 0xFF }, // (Offset,Value)-Pair #5
        { 0x05, 0x15 }, // (Offset,Value)-Pair #6

        // CloseHandle+0x11 : jmp +0x08
        { 0x11, 0xEB }, // (Offset,Value)-Pair #7
        { 0x12, 0x08 }, // (Offset,Value)-Pair #8

        // CloseHandle+0x1B : retn 4
        { 0x1B, 0xC2 }, // (Offset,Value)-Pair #9
        { 0x1C, 0x04 }  // (Offset,Value)-Pair #10
    }
};

// ******************************************************************
// * XapiInitProcess
// ******************************************************************
SOOVPA<7> XapiInitProcess_1_0_4361 =
{
    0,  // Large == 0
    7,  // Count == 7

    {
        // XapiInitProcess+0x00 : sub esp, 30h
        { 0x05, 0x30 }, // (Offset,Value)-Pair #1

        // XapiInitProcess+0x0F : push 0x0C
        { 0x0F, 0x6A }, // (Offset,Value)-Pair #2
        { 0x10, 0x0C }, // (Offset,Value)-Pair #3

        // XapiInitProcess+0x17 : repe stosd
        { 0x17, 0xF3 }, // (Offset,Value)-Pair #4
        { 0x18, 0xAB }, // (Offset,Value)-Pair #5

        // XapiInitProcess+0x42 : jnz +0x0B
        { 0x42, 0x75 }, // (Offset,Value)-Pair #6
        { 0x43, 0x0B }, // (Offset,Value)-Pair #7
    }
};


// ******************************************************************
// * XapiThreadStartup
// ******************************************************************
SOOVPA<10> XapiThreadStartup_1_0_4361 =
{
    0,  // Large == 0
    10, // Count == 10

    {
        // XapiThreadStartup+0x00 : push 0x18
        { 0x00, 0x6A }, // (Offset,Value)-Pair #1
        { 0x01, 0x18 }, // (Offset,Value)-Pair #2

        // XapiThreadStartup+0x10 : mov eax, fs:[0x28]
        { 0x10, 0x64 }, // (Offset,Value)-Pair #3
        { 0x11, 0xA1 }, // (Offset,Value)-Pair #4
        { 0x12, 0x28 }, // (Offset,Value)-Pair #5

        // XapiThreadStartup+0x3F : repe movsd
        { 0x3F, 0xF3 }, // (Offset,Value)-Pair #6
        { 0x40, 0xA5 }, // (Offset,Value)-Pair #7

        // XapiThreadStartup+0x7C : jmp +0x0C
        { 0x7C, 0xEB }, // (Offset,Value)-Pair #8
        { 0x7D, 0x0C }, // (Offset,Value)-Pair #9

        // XapiThreadStartup+0x86 : retn
        { 0x86, 0xC3 }, // (Offset,Value)-Pair #10
    }
};

// ******************************************************************
// * XapiSetupPerTitleDriveLetters
// ******************************************************************
SOOVPA<10> XapiSetupPerTitleDriveLetters_1_0_4361 =
{
    0,  // Large == 0
    10, // Count == 10

    {
        // XapiSetupPerTitleDriveLetters+0x09 : lea eax, [ebp-0x0C]
        { 0x09, 0x8D }, // (Offset,Value)-Pair #1
        { 0x0A, 0x45 }, // (Offset,Value)-Pair #2
        { 0x0B, 0xF4 }, // (Offset,Value)-Pair #3

        // XapiSetupPerTitleDriveLetters+0x17 : edd esp, 0x0C
        { 0x17, 0x83 }, // (Offset,Value)-Pair #4
        { 0x18, 0xC4 }, // (Offset,Value)-Pair #5
        { 0x19, 0x0C }, // (Offset,Value)-Pair #6

        // XapiSetupPerTitleDriveLetters+0x35 : jl 0x1A
        { 0x35, 0x7C }, // (Offset,Value)-Pair #7
        { 0x36, 0x1A }, // (Offset,Value)-Pair #8

        // XapiSetupPerTitleDriveLetters+0x52 : retn 0x08
        { 0x52, 0xC2 }, // (Offset,Value)-Pair #9
        { 0x53, 0x08 }, // (Offset,Value)-Pair #10
    }
};

// ******************************************************************
// * XAPI_1_0_4361
// ******************************************************************
OOVPATable XAPI_1_0_4361[] =
{
    // RtlCreateHeap
    {
        (OOVPA*)&RtlCreateHeap_1_0_4361,

        xapi::EmuRtlCreateHeap,

        #ifdef _DEBUG_TRACE
        "RtlCreateHeap"
        #endif
    },
    // RtlAllocateHeap
    {
        (OOVPA*)&RtlAllocateHeap_1_0_4361,

        xapi::EmuRtlAllocateHeap,

        #ifdef _DEBUG_TRACE
        "RtlAllocateHeap"
        #endif
    },
    // RtlFreeHeap
    {
        (OOVPA*)&RtlFreeHeap_1_0_4361,

        xapi::EmuRtlFreeHeap,

        #ifdef _DEBUG_TRACE
        "RtlFreeHeap"
        #endif
    },
    // XInitDevices (* unchanged since 1.0.4034 *)
    {
        (OOVPA*)&XInitDevices_1_0_4034,

        xapi::EmuXInitDevices,

        #ifdef _DEBUG_TRACE
        "EmuXInitDevices"
        #endif
    },
    // XGetDevices
    {
        (OOVPA*)&XGetDevices_1_0_4361,

        xapi::EmuXGetDevices,

        #ifdef _DEBUG_TRACE
        "EmuXGetDevices"
        #endif
    },
    // XInputOpen
    {
        (OOVPA*)&XInputOpen_1_0_4361,

        xapi::EmuXInputOpen,

        #ifdef _DEBUG_TRACE
        "EmuXInputOpen"
        #endif
    },
    // XInputGetCapabilities
    {
        (OOVPA*)&XInputGetCapabilities_1_0_4361,

        xapi::EmuXInputGetCapabilities,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetCapabilities"
        #endif
    },
    // XInputGetState
    {
        (OOVPA*)&XInputGetState_1_0_4361,

        xapi::EmuXInputGetState,

        #ifdef _DEBUG_TRACE
        "EmuXInputGetState"
        #endif
    },
    /* Too High Level
    // CreateThread
    {
        (OOVPA*)&CreateThread_1_0_4361,

        xapi::EmuCreateThread,

        #ifdef _DEBUG_TRACE
        "EmuCreateThread" 
        #endif
    },
    */
    /* Too High Level
    // CloseHandle
    {
        (OOVPA*)&CloseHandle_1_0_4361,

        xapi::EmuCloseHandle,

        #ifdef _DEBUG_TRACE
        "EmuCloseHandle" 
        #endif
    },
    */
    //* Too High Level
    // XapiInitProcess
    {
        (OOVPA*)&XapiInitProcess_1_0_4361,

        xapi::EmuXapiInitProcess,

        #ifdef _DEBUG_TRACE
        "EmuXapiInitProcess" 
        #endif
    },
    //*/
    // XapiThreadStartup
    {
        (OOVPA*)&XapiThreadStartup_1_0_4361,

        xapi::EmuXapiThreadStartup,

        #ifdef _DEBUG_TRACE
        "XapiThreadStartup"
        #endif
    },
    /* Too High Level
    // XapiSetupPerTitleDriveLetters
    {
        (OOVPA*)&XapiSetupPerTitleDriveLetters_1_0_4361,

        xapi::XapiSetupPerTitleDriveLetters,

        #ifdef _DEBUG_TRACE
        "XapiSetupPerTitleDriveLetters"
        #endif
    },
    //*/
    // XapiBootToDash (* unchanged since 1.0.3911 *)
    {
        (OOVPA*)&XapiBootDash_1_0_3911,

        xapi::EmuXapiBootDash,

        #ifdef _DEBUG_TRACE
        "EmuXapiBootDash"
        #endif
    },
    //* Too High Level
    // __rtinit (* unchanged since 1.0.3911 *)
    {
        (OOVPA*)&__rtinit_1_0_3911,

        xapi::Emu__rtinit,

        #ifdef _DEBUG_TRACE
        "Emu__rtinit",
        #endif
    },
    //*/
    //* Too High Level
    // __cinit (* unchanged since 1.0.3911 *)
    {
        (OOVPA*)&__cinit_1_0_3911,

        xapi::Emu__cinit,

        #ifdef _DEBUG_TRACE
        "Emu__cinit",
        #endif
    },
    //*/
};

// ******************************************************************
// * XAPI_1_0_4361_SIZE
// ******************************************************************
uint32 XAPI_1_0_4361_SIZE = sizeof(XAPI_1_0_4361);
