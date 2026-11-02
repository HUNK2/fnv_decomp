// gamebryo2.2/corelibs/nimain/nitribasedgeomdata.cpp: NiTriBasedGeomData (12 functions)

#include "nitribasedgeomdata_decls.h"
// Constructs a NiTriBasedGeomData by initializing the NiGeometryData base and storing the triangle count in m_usTriangles.
// @fnv 0x00a8a920
NiTriBasedGeomData::NiTriBasedGeomData(unsigned short ausVertexCount, NiPoint3* apVertices, NiPoint3* apNormals,
                                       RgbaColor* d, NiPoint2* apTextureCoords, unsigned short f,
                                       NiGeometryData__DataFlags aeDataFlags, unsigned short ausTriangleCount)
    : NiGeometryData(ausVertexCount, apVertices, apNormals, d, apTextureCoords, f, aeDataFlags),
      m_usTriangles(ausTriangleCount)
{}

void __fastcall FUN_00a67c00(void* pThis);
extern void* vftable_NiTriBasedGeomData;

// @fnv 0x00a8a970
NiTriBasedGeomData* __fastcall InitializeTriBasedGeomData(NiTriBasedGeomData* pThis)
{
    FUN_00a67c00(pThis);
    *(unsigned short*)((char*)pThis + 0x40) = 0;
    *(void**)pThis = &vftable_NiTriBasedGeomData;
    return pThis;
}

struct NiAVObject;
struct NiBinaryStream;
struct NiFixedString;
struct NiObject;
struct NiObjectGroup;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiThread;
struct FUN_00a8aa30_shell : public NiTriBasedGeomData
{
    void FUN_00a8aa30(NiStream*);
};

struct FakeBinaryStream
{
    int pad;
    unsigned int position;
    unsigned int(__cdecl* read)(void*, void*, unsigned int, unsigned int*, unsigned int);
};

// Loads NiGeometryData binary data from the stream, then reads 2 bytes from the stream's binary reader into this+0x40.
// @fnv 0x00a8aa30
void FUN_00a8aa30_shell::FUN_00a8aa30(NiStream* kStream)
{
    reinterpret_cast<NiGeometryData*>(this)->LoadBinary(*kStream);
    FakeBinaryStream* __restrict input =
        *reinterpret_cast<FakeBinaryStream**>(reinterpret_cast<char*>(kStream) + 0x24c);
    unsigned int size = 2;
    input->position += input->read(input, reinterpret_cast<char*>(this) + 0x40, 2, &size, 1);
}

struct NiAVObject;
struct NiBinaryStream;
struct NiFixedString;
struct NiObject;
struct NiObjectGroup;
struct NiSearchPath;
struct NiStream;
struct NiTexture;
struct NiThread;
struct FUN_00a8aa70_shell : public NiTriBasedGeomData
{
    void FUN_00a8aa70(NiStream*);
};

struct NiBinaryStream_Save
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    void* m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(void*, const void*, unsigned int, unsigned int*, unsigned int);
};

// @fnv 0x00a8aa70
void FUN_00a8aa70_shell::FUN_00a8aa70(NiStream* kStream)
{
    NiGeometryData::SaveBinary(*kStream);
    NiBinaryStream_Save* __restrict output = *(NiBinaryStream_Save**)((char*)kStream + 0x250);
    unsigned int size = 2;
    output->m_uiStreamFlags += output->m_pfnWrite(output, (char*)this + 0x40, 2, &size, 1);
}

extern char const* const g_011f4a70_arg1;

// @fnv 0x00a8a9f0
char const* const* __cdecl FUN_00a8a9f0()
{
    return &g_011f4a70_arg1;
}

struct StrArr
{
    void* m_pkArray;
    void* m_reserved;
    unsigned short m_uiCapacity;
    unsigned short m_uiSize;
    unsigned short m_reserved2;
    unsigned short m_uiGrowSize;

    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, char*& rString);
};

template <class T> struct NiTPrimitiveArray : public StrArr
{
};

struct FUN_00a8aab0_shell
{
    unsigned char m_auiShapeKeys[0x40];
    unsigned short m_usTriangles;

    void RegisterFields(NiTPrimitiveArray<char*>* pkStrings);
    void AppendTrianglesInfo(NiTPrimitiveArray<char*>* pkStrings);
};

extern char const* const g_011f4a70_arg1;
char* __cdecl _FUN_00a7d330(char const* pString);
char* __cdecl FUN_00a7d490(char const* pString, unsigned short usValue);

// Calls RegisterFields, then appends a string from g_011f4a70_arg1 and a formatted m_usTriangles entry to pkStrings, growing it when full.
// @fnv 0x00a8aab0
void FUN_00a8aab0_shell::AppendTrianglesInfo(NiTPrimitiveArray<char*>* pkStrings)
{
    RegisterFields(pkStrings);

    char* pString = _FUN_00a7d330(g_011f4a70_arg1);

    unsigned int uiSize = pkStrings->m_uiSize;
    unsigned int uiCapacity = pkStrings->m_uiCapacity;
    if (uiSize >= uiCapacity)
    {
        unsigned int uiGrowSize = pkStrings->m_uiGrowSize;
        pkStrings->SetSize(uiSize + uiGrowSize);
    }

    pkStrings->SetAt(uiSize, pString);

    pString = FUN_00a7d490("m_usTriangles", m_usTriangles);

    uiSize = pkStrings->m_uiSize;
    uiCapacity = pkStrings->m_uiCapacity;
    if (uiSize >= uiCapacity)
    {
        unsigned int uiGrowSize = pkStrings->m_uiGrowSize;
        pkStrings->SetSize(uiSize + uiGrowSize);
    }

    pkStrings->SetAt(uiSize, pString);
}

extern void* vftable_0109f2f4[];

struct FUN_00a8a990_shell
{
    void* vptr;
    void DestroyGeometryData();
    void FUN_00a8a990();
};

// @fnv 0x00a8a990
void FUN_00a8a990_shell::FUN_00a8a990()
{
    vptr = vftable_0109f2f4;
    DestroyGeometryData();
}

struct S_00a8a9c0_Base
{
    virtual void v00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    bool FUN_00a67840(const S_00a8a9c0_Base* pkObject);
};
struct S_00a8a9c0 : S_00a8a9c0_Base
{
    unsigned short m_usTriangles;
    unsigned char MatchesTriangleCount(const S_00a8a9c0_Base* pkObject);
};
// Returns false if FUN_00a67840 fails, otherwise returns whether m_usTriangles equals the passed object's m_usTriangles.
// @fnv 0x00a8a9c0
unsigned char S_00a8a9c0::MatchesTriangleCount(const S_00a8a9c0_Base* pkObject)
{
    if (!FUN_00a67840(pkObject))
        return false;
    return m_usTriangles == ((const S_00a8a9c0*)pkObject)->m_usTriangles;
}

extern int DAT_0109f2f4;

void __cdecl FUN_00aa1460(void* apMemory, unsigned int auiSize);

struct FUN_00a8aa00_cls
{
    int m_vptr;
    int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned short m_usTriangles;

    void BaseCleanup();

    FUN_00a8aa00_cls* Destroy(unsigned char acFlags);
};

// Sets the vtable pointer, calls BaseCleanup, and frees the object with FUN_00aa1460 when acFlags bit 0 is set; returns this.
// @fnv 0x00a8aa00
FUN_00a8aa00_cls* FUN_00a8aa00_cls::Destroy(unsigned char acFlags)
{
    m_vptr = (int)&DAT_0109f2f4;
    BaseCleanup();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0x44);
    }
    return this;
}

struct FUN_00a8a9b0 : NiGeometryData
{
    virtual bool RegisterStreamables(NiStream&);
};
// @fnv 0x00a8a9b0
bool FUN_00a8a9b0::RegisterStreamables(NiStream& kStream)
{
    return NiGeometryData::RegisterStreamables(kStream);
}

// @fnv 0x00d3dd00
void __stdcall FUN_00d3dd00(int a, int b, int c, int d)
{}

void FUN_00a677e0();
// @fnv 0x00a8a9a0
void FUN_00a8a9a0()
{
    FUN_00a677e0();
}
