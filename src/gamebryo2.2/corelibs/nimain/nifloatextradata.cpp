
// src/gamebryo2.2/corelibs/nimain/nifloatextradata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nifloatextradata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct GlobalObjectO2_00a7b610
{
};

extern GlobalObjectO2_00a7b610 g_011f5f40;

// @fnv 0x00a9a420
GlobalObjectO2_00a7b610* __cdecl NiFloatExtraData_GetRTTI()
{
    return &g_011f5f40;
}

struct NiFloatExtraData
{
    void* m_ppVirtualMethodTable;
    void* Destroy(unsigned int flags);
};

extern void* DAT_010a0ec4;
extern void __cdecl FUN_00a7b300();
extern void __cdecl operator delete(void*, unsigned int);

// @fnv 0x00a9a4b0
void* NiFloatExtraData::Destroy(unsigned int flags)
{
    this->m_ppVirtualMethodTable = &DAT_010a0ec4;
    FUN_00a7b300();
    if (flags & 1)
        operator delete(this, 0x10);
    return this;
}

struct NiObject
{
};
struct FUN_00a9a3f0_Class
{
    char _pad[12];
    float m_fValue;
    bool MatchesFloatValue(NiObject* pObject);
};
// Returns true if pObject is non-null and its float at offset 12 equals m_fValue, otherwise false.
// @fnv 0x00a9a3f0
bool FUN_00a9a3f0_Class::MatchesFloatValue(NiObject* pObject)
{
    NiFloatExtraData* pExtra = (NiFloatExtraData*)pObject;
    if (!pExtra)
        return false;
    if (m_fValue != *(float*)((char*)pExtra + 12))
        return false;
    return true;
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct NiExtraData
{
    void FUN_00a7b2e0();
    void FUN_00a7b330(void*, void*);
    void* CloneFloatExtraData(void*);
};
// @fnv 0x00a9a430
void* NiExtraData::CloneFloatExtraData(void* kCloning)
{
    NiFloatExtraData* pkObject;
    pkObject = (NiFloatExtraData*)BSFadeNode::operator new(0x10);
    if (pkObject)
    {
        ((NiExtraData*)pkObject)->FUN_00a7b2e0();
        *(float*)((char*)pkObject + 0xc) = 0.0f;
        pkObject->m_ppVirtualMethodTable = &DAT_010a0ec4;
    }
    else
    {
        pkObject = 0;
    }
    this->FUN_00a7b330(pkObject, kCloning);
    *(float*)((char*)pkObject + 0xc) = *(float*)((char*)this + 0xc);
    return pkObject;
}

namespace fnv_00a9a480 {
struct NiExtraData
{
    void FUN_00a7b2e0();
};

struct BSFadeNode
{
    static void* operator new(unsigned int size);
};

// @fnv 0x00a9a480
void* __cdecl NiFloatExtraData_CreateObject()
{
    void* p = BSFadeNode::operator new(0x10);
    if (p)
    {
        reinterpret_cast<NiExtraData*>(p)->FUN_00a7b2e0();
        *reinterpret_cast<float*>(reinterpret_cast<char*>(p) + 0xc) = 0.0f;
        *reinterpret_cast<void**>(p) = &DAT_010a0ec4;
        return p;
    }
    return 0;
}
}  // namespace fnv_00a9a480

namespace fnv_00a9a4e0 {
struct NiStream;
struct NiBinaryStream
{
    void* _00;
    int m_pos;
    int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    int(__cdecl* write)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct NiStream
{
    char _pad[0x250];
    NiBinaryStream* m_pBackingStream;
};
struct NiExtraData
{
    char _pad[0xc];
    void SaveBinary(NiStream&);
};
struct Cls_00a9a4e0 : NiExtraData
{
    float m_fValue;
    void FUN_00a9a4e0(NiStream&);
};
// Calls NiExtraData::SaveBinary then writes the 4-byte m_fValue to the stream and advances its position.
// @fnv 0x00a9a4e0
void Cls_00a9a4e0::FUN_00a9a4e0(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    NiBinaryStream* __restrict output = stream.m_pBackingStream;
    unsigned int size = 4;
    output->m_pos += output->write(output, &m_fValue, 4, &size, 1);
}
}  // namespace fnv_00a9a4e0

struct StrArr
{
    char _pad00[8];
    unsigned short m_pRayCursor;
    unsigned short m_nextIndex;
    unsigned short _pad0c;
    unsigned short m_growSize;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct A89C70StringArray : StrArr
{
};

struct A89C70Base
{
    void* m_ppVirtualMethodTable;
    char _pad04[8];

    void GetViewerStrings(A89C70StringArray* strings);
};

char* __cdecl _FUN_00a7d330(GlobalObjectO2_00a7b610* object);
char* __cdecl FUN_00a7d550(char const* name, float value);

struct FUN_00a9a520_shell : A89C70Base
{
    float m_fValue;

    void AppendViewerStrings(A89C70StringArray* strings);
};

// @fnv 0x00a9a520
void FUN_00a9a520_shell::AppendViewerStrings(A89C70StringArray* strings)
{
    GetViewerStrings(strings);

    char* value =
        _FUN_00a7d330(reinterpret_cast<GlobalObjectO2_00a7b610*>(*reinterpret_cast<unsigned int*>(&g_011f5f40)));

    unsigned int index = strings->m_nextIndex;

    if (index >= strings->m_pRayCursor)
        strings->SetSize(index + strings->m_growSize);

    strings->SetAt(index, value);

    value = FUN_00a7d550("m_fValue", m_fValue);

    index = strings->m_nextIndex;

    if (index >= strings->m_pRayCursor)
        strings->SetSize(index + strings->m_growSize);

    strings->SetAt(index, value);
}
