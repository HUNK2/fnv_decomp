// gamebryo2.2/corelibs/nimain/nishader.cpp: NiShader (10 functions)

#include "nishader_decls.h"
// @fnv 0x00a8f3d0
bool NiShader::Initialize()
{
    return m_bShaderEnabled = true;
}

#pragma optimize("", off)
// @fnv 0x0066b0d0
NiPointer<NiAVObject>& NiPointer<NiAVObject>::operator=(NiAVObject* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            reinterpret_cast<WaitableObject*>(m_pObject)->FUN_00401970();
        m_pObject = object;
        if (m_pObject)
            reinterpret_cast<WaitableObject*>(m_pObject)->FUN_0040f6e0();
    }
    return *this;
}
#pragma optimize("", on)

extern int DAT_0109f584;
extern int DAT_0101dce4;
extern char* DAT_0109b220;
extern volatile long DAT_011f4400;
__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
void __cdecl FUN_00aa1460(void*, unsigned int);

struct FUN_00a8f4d0_shell
{
    int* volatile vtable;
    unsigned int instanceId;
    char* volatile text;
    FUN_00a8f4d0_shell* FUN_00a8f4d0(unsigned char flags);
};

// @fnv 0x00a8f4d0
FUN_00a8f4d0_shell* FUN_00a8f4d0_shell::FUN_00a8f4d0(unsigned char flags)
{
    vtable = &DAT_0109f584;
    char* stringData = text;
    if (stringData != DAT_0109b220)
        InterlockedDecrement(reinterpret_cast<volatile long*>(stringData - 8));
    vtable = &DAT_0101dce4;
    InterlockedDecrement(&DAT_011f4400);
    if (flags & 1)
        FUN_00aa1460(this, 20);
    return this;
}

// @fnv 0x00a8f3e0
int __stdcall FUN_00a8f3e0(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6)
{
    return 0;
}

// @fnv 0x00a8f3f0
int __stdcall FUN_00a8f3f0(int a, int b, int c, int d, int e, int f, int g, int h)
{
    return 0;
}

// @fnv 0x00a8f400
int __stdcall FUN_00a8f400(int arg0, int arg1, int arg2, int arg3)
{
    return 0;
}

// @fnv 0x00a8f410
int __stdcall FUN_00a8f410(int arg0, int arg1)
{
    return 0;
}

// @fnv 0x00a8f420
bool __stdcall FUN_00a8f420(int a, int b, int c, int d, int e, int f)
{
    return false;
}

// @fnv 0x00a8f430
char __stdcall FUN_00a8f430(int a, int b, int c, int d, int e)
{
    return 0;
}

// @fnv 0x00c9a420
bool __stdcall FUN_00c9a420(void* unk00)
{
    return false;
}
