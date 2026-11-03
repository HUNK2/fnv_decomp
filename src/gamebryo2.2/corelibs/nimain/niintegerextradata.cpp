// gamebryo2.2/corelibs/nimain/niintegerextradata.cpp: NiIntegerExtraData, ExtraDataOwner (7 functions)

#include "niintegerextradata_decls.h"
// Calls NiExtraData::LoadBinary then reads m_iValue from the stream.
// @fnv 0x00a99d30
void NiIntegerExtraData::LoadBinary(NiStream& stream)
{
    NiExtraData::LoadBinary(stream);
    stream.m_pUnderlyingStream->Read(&m_iValue);
}

extern char const* const g_01202de0_arg1;

// @fnv 0x00a99c60
char const* const* __cdecl NiIntegerExtraData_GetRTTI()
{
    return &g_01202de0_arg1;
}

extern "C" void __cdecl FUN_00a7b300();
extern int DAT_010a0d24;

struct FUN_00a99c70_shell
{
    int* m_val;
    void __thiscall FUN_00a99c70();
};

// @fnv 0x00a99c70
void __thiscall FUN_00a99c70_shell::FUN_00a99c70()
{
    m_val = &DAT_010a0d24;
    FUN_00a7b300();
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

struct NiExtraDataShell : NiExtraData
{
    void __thiscall FUN_00a7b2e0();
};

// @fnv 0x00a99cd0
NiExtraData* NiIntegerExtraData_CreateObject()
{
    NiExtraData* pExtraData = static_cast<NiExtraData*>(BSFadeNode::operator new(0x10));
    if (pExtraData)
    {
        static_cast<NiExtraDataShell*>(pExtraData)->FUN_00a7b2e0();
        *reinterpret_cast<int**>(pExtraData) = &DAT_010a0d24;
        *reinterpret_cast<int*>(reinterpret_cast<char*>(pExtraData) + 0xc) = 0;
        return pExtraData;
    }
    return 0;
}

void __cdecl operator delete(void*, unsigned int);
struct FUN_00a99d00_shell
{
    void* __thiscall Destroy(unsigned int);
};
// @fnv 0x00a99d00
void* __thiscall FUN_00a99d00_shell::Destroy(unsigned int auiFlags)
{
    *(int**)this = &DAT_010a0d24;
    FUN_00a7b300();
    if (auiFlags & 1)
        ::operator delete(this, 0x10);
    return this;
}

struct StrArr
{
    unsigned char m_pad00[8];
    unsigned short m_uiCapacity;
    unsigned short m_uiSize;
    unsigned char m_pad0C[2];
    unsigned short m_uiGrowSize;

    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};

struct A89C70StringArray : StrArr
{
};

struct A89C70Base
{
    void __thiscall GetViewerStrings(A89C70StringArray*);
};

void* __cdecl _FUN_00a7d330(void*);
char* __cdecl FUN_00a7d4d0(char const*, int);

struct FUN_00a99d70_shell
{
    void __thiscall NiIntegerExtraData_GetViewerStrings(A89C70StringArray*);
};

// Appends the base viewer strings plus a formatted "m_iValue" entry to the string array, growing it as needed.
// @fnv 0x00a99d70
void FUN_00a99d70_shell::NiIntegerExtraData_GetViewerStrings(A89C70StringArray* apViewerStrings)
{
    reinterpret_cast<A89C70Base*>(this)->GetViewerStrings(apViewerStrings);

    char* pString = static_cast<char*>(_FUN_00a7d330(const_cast<char*>(g_01202de0_arg1)));

    unsigned int index = apViewerStrings->m_uiSize;
    if (index >= apViewerStrings->m_uiCapacity)
        apViewerStrings->SetSize(index + apViewerStrings->m_uiGrowSize);
    apViewerStrings->SetAt(index, pString);

    pString = FUN_00a7d4d0("m_iValue", *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x0c));

    index = apViewerStrings->m_uiSize;
    if (index >= apViewerStrings->m_uiCapacity)
        apViewerStrings->SetSize(index + apViewerStrings->m_uiGrowSize);
    apViewerStrings->SetAt(index, pString);
}

extern "C" void* __cdecl FUN_00aa13e0(unsigned int);
struct ExtraDataOwner
{
    int unk00;
    int unk04;
    int unk08;
    int m_iValue;
    void __thiscall FUN_00a7b330(NiIntegerExtraData*, unsigned int);
    NiIntegerExtraData* __thiscall CreateIntegerExtraData(unsigned int);
};
// @fnv 0x00a99c80
NiIntegerExtraData* ExtraDataOwner::CreateIntegerExtraData(unsigned int argument)
{
    NiIntegerExtraData* result;
    NiIntegerExtraData* allocated = (NiIntegerExtraData*)FUN_00aa13e0(16);
    if (allocated != 0)
    {
        ((NiExtraDataShell*)allocated)->FUN_00a7b2e0();
        *(void**)allocated = &DAT_010a0d24;
        allocated->m_iValue = 0;
        result = allocated;
    }
    else
    {
        result = 0;
    }
    FUN_00a7b330(result, argument);
    result->m_iValue = m_iValue;
    return result;
}
