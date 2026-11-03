// gamebryo2.2/corelibs/nimain/nitrishape.cpp: NiTriShape (16 functions)

#include "nitrishape_decls.h"

// @fnv 0x00A74410
NiTriShape::NiTriShape(unsigned short numVertices, NiPoint3* vertices, NiPoint3* normals, RgbaColor* colors,
                       NiPoint2* textures, unsigned short numTriangles, NiGeometryData__DataFlags dataFlags,
                       unsigned short sharedNormalsArraySize, unsigned short* m_kNavMeshTriangleList)
    : NiTriBasedGeom(new NiTriShapeData(numVertices, vertices, normals, colors, textures, numTriangles, dataFlags,
                                        sharedNormalsArraySize, m_kNavMeshTriangleList))
{}

void __fastcall FUN_00a89760(void* pThis);

struct FUN_00a74530_DelHelper : NiMemObject
{
    static void operator delete(void*, size_t);
};

// Calls FUN_00a89760 on pThis, frees pThis with operator delete when flags has bit 0 set, and returns pThis.
// @fnv 0x00a74530
void* __fastcall DestroyNiTriShape(void* pThis, int, unsigned int flags)
{
    FUN_00a89760(pThis);
    if (flags & 1)
        FUN_00a74530_DelHelper::operator delete(pThis, 0xc4);
    return pThis;
}

struct CloningProcess;
struct NiObject;
struct NiRenderer;
struct blob16
{
    char b[16];
};
struct BSScissorTriShape : public NiTriShape
{
    virtual void __vslot_0();
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSScissorTriShape*, CloningProcess*);
    virtual void GetViewerStrings(void*);
    void SetScissorRect(int, int, int, int);
    struct blob16 GetScissorRect();
    virtual void RenderImmediate(NiRenderer*);
    void __local_vftable_ctor_closure();
    char _pad_c4[44];
    char pDataToSerialize[16];
};
typedef char _sizecheck_BSScissorTriShape[sizeof(BSScissorTriShape) == 256 ? 1 : -1];
struct FUN_00a74600_shell : public NiTriShape
{
    void FUN_00a74600(NiRenderer*);
};

void NiGeometry_RenderImmediate();

// Calls NiGeometry_RenderImmediate on this, then if the renderer's state at offset 0x200 is 1 or 2 and byte 0x208 is 1, invokes renderer vtable slot 0x1b4 with this.
// @fnv 0x00a74600
void FUN_00a74600_shell::FUN_00a74600(NiRenderer* apkRenderer)
{
    ((void(__thiscall*)(NiTriShape*, NiRenderer*))NiGeometry_RenderImmediate)(this, apkRenderer);
    int state = *(int*)((char*)apkRenderer + 0x200);
    if ((state == 1 || state == 2) && *((char*)apkRenderer + 0x208) == 1)
    {
        ((void(__thiscall*)(NiRenderer*, NiTriShape*))(*(void***)apkRenderer)[0x1b4 / 4])(apkRenderer, this);
    }
}

struct NiTriStrips
{
    NiTriStrips();
    virtual ~NiTriStrips();
    char pad[0xc0];
};
struct FUN_00a744a0 : NiTriStrips
{
    FUN_00a744a0();
    virtual ~FUN_00a744a0();
};
// @fnv 0x00a744a0
FUN_00a744a0::FUN_00a744a0()
{}

namespace fnv_00a744d0 {
struct BSFadeNode
{
    static void* operator new(unsigned int);
};
struct NiTriStrips : BSFadeNode
{
    NiTriStrips() throw();
    virtual ~NiTriStrips() throw();
    char pad[0xc0];
};
struct NiTriShapeX : NiTriStrips
{
    NiTriShapeX() throw()
    {}
    virtual ~NiTriShapeX();
};
// Allocates and constructs a NiTriShapeX and returns it as a NiTriStrips pointer.
// @fnv 0x00a744d0
NiTriStrips* __cdecl CreateNiTriShapeX()
{
    return new NiTriShapeX;
}
}  // namespace fnv_00a744d0

extern const char g_011f5b34_arg1[];
// @fnv 0x00a74520
const char* __cdecl NiTriShape_GetRTTI()
{
    return g_011f5b34_arg1;
}

namespace fnv_00a74560 {
struct CloningProcess;
struct NiObject;
struct NiRenderer;
struct NiStream;
struct blob12
{
    char b[12];
};
struct blob16
{
    char b[16];
};
struct BSResizableTriShape : public NiTriShape
{
    virtual void __vslot_0();
    virtual void SetLocalBound(struct blob16);
    virtual void* GetBoundingVolume();
    virtual void* GetRTTI();
    virtual NiObject* MakeClone(CloningProcess*);
    void CopyMemberData(BSResizableTriShape*, CloningProcess*);
    virtual void LoadBinary(NiStream*);
    virtual void LinkObject(NiStream*);
    virtual bool RegisterStreamables(NiStream*);
    virtual void SaveBinary(NiStream*);
    virtual bool IsEqual(NiObject*);
    static NiObject* CreateObject();
    virtual void GetViewerStrings(void*);
    void SetNumPrimitives(unsigned int);
    unsigned int GetNumPrimitives();
    virtual BSResizableTriShape* IsResizableTriShape();
    virtual void RenderImmediate(NiRenderer*);
    virtual void RenderWithRenderer(NiRenderer*);
    virtual void UpdateWorldBound();
    void __local_vftable_ctor_closure();
    char _pad_c4[44];
    unsigned int m_uiValueBeforeLocalBound;
    char LocalBound[16];
    char _pad_104[12];
};
typedef char _sizecheck_BSResizableTriShape[sizeof(BSResizableTriShape) == 272 ? 1 : -1];
struct NiPoint3
{
    static struct blob12 ComponentProduct(void*, void*);
    float Length();
    float SqrLength();
    float XYLength();
    float SqrXYLength();
    float Dot(void*);
    void Unitize();
    float GetLengthSquared();
    struct blob12 Cross(void*);
    struct blob12 CrossProduct(void*);
    struct blob12 Perpendicular();
    static void LoadBinary(NiStream*, NiPoint3*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, NiPoint3*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    static void InitializePoint3();
    static void ShutdownPoint3();
    static void ProcessPointArray(NiPoint3*, unsigned int, unsigned int);
    static void ComputeMagnitude(NiPoint3*);
    static float VectorLength(void*);
    static void PointsPlusEqualFloatTimesPoints(NiPoint3*, float, void*, unsigned int);
    static void WeightedPointsPlusWeightedPoints(NiPoint3*, float, void*, unsigned int);
    static unsigned int* InitSqrtTable();
    float x;
    float y;
    float z;
};
typedef char _sizecheck_NiPoint3[sizeof(NiPoint3) == 12 ? 1 : -1];
struct FUN_00a74560_shell : public NiTriShape
{
    void GetTriangleVertices(unsigned short, NiPoint3**, NiPoint3**, NiPoint3**);
};

struct TriListHelper
{
    unsigned short* GetTriangleList();
};
// @fnv 0x00a74560
void FUN_00a74560_shell::GetTriangleVertices(unsigned short ausTriangleIndex, NiPoint3** pkP0, NiPoint3** pkP1,
                                             NiPoint3** pkP2)
{
    NiTriShapeData* pkModelData = *(NiTriShapeData**)((char*)this + 0xb8);
    NiPoint3* pkVertex = *(NiPoint3**)((char*)pkModelData + 0x20);
    unsigned short* pusTriList = ((TriListHelper*)pkModelData)->GetTriangleList();
    unsigned short usIndexOffset = ausTriangleIndex * 3;
    *pkP0 = &pkVertex[pusTriList[usIndexOffset++]];
    *pkP1 = &pkVertex[pusTriList[usIndexOffset++]];
    *pkP2 = &pkVertex[pusTriList[usIndexOffset++]];
}
}  // namespace fnv_00a74560

namespace fnv_00a74640 {
struct BSFadeNode
{
    static void* operator new(unsigned int);
};
struct NiTriStrips : BSFadeNode
{
    NiTriStrips() throw();
    virtual ~NiTriStrips();
    char pad[0xc0];
};
struct NiTriShapeX : NiTriStrips
{
    NiTriShapeX() throw()
    {}
    virtual ~NiTriShapeX();
};
struct CloningProcess;
struct FUN_00a74640
{
    void FUN_00a9b140(NiTriStrips*, CloningProcess&);
    NiTriStrips* Clone(CloningProcess& kCloning);
};
// @fnv 0x00a74640
NiTriStrips* FUN_00a74640::Clone(CloningProcess& kCloning)
{
    NiTriStrips* pkClone = new NiTriShapeX;
    FUN_00a9b140(pkClone, kCloning);
    return pkClone;
}
}  // namespace fnv_00a74640

struct FUN_00a804e0
{
    FUN_00a804e0(void* a);
    virtual ~FUN_00a804e0();
};
struct FUN_00a89720 : FUN_00a804e0
{
    FUN_00a89720(void* a);
    virtual ~FUN_00a89720();
};
// @fnv 0x00a89720
FUN_00a89720::FUN_00a89720(void* a) : FUN_00a804e0(a)
{}

struct FUN_00a80610_This
{
    void __thiscall NiGeometry_RenderImmediate(void*);
};
struct FUN_00a745c0_This
{
    void __thiscall NiTriShape_RenderImmediate(void*);
};
// Calls NiGeometry_RenderImmediate on the renderer, then if renderer state at 0x200 is 1 or 2 and byte at 0x208 is 1, invokes vtable slot 107 with this.
// @fnv 0x00a745c0
void __thiscall FUN_00a745c0_This::NiTriShape_RenderImmediate(void* apkRenderer)
{
    void* pkRenderer = apkRenderer;
    ((FUN_00a80610_This*)this)->NiGeometry_RenderImmediate(pkRenderer);
    if ((*(int*)((char*)pkRenderer + 0x200) == 1 || *(int*)((char*)pkRenderer + 0x200) == 2) &&
        *(char*)((char*)pkRenderer + 0x208) == 1)
    {
        ((void(__thiscall**)(void*, void*))(*(void***)pkRenderer))[107](pkRenderer, this);
    }
}

namespace fnv_00a74690 {
struct StrArr
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct BaseA
{
    void NiTriBasedGeom_GetViewerStrings(StrArr*);
};
char* FUN_00a7d330(const char*);
extern const char* const g_011f5b34_arg1;
struct FUN_00a74690_shell : BaseA
{
    void NiTriShape_GetViewerStrings(StrArr* pkStrings);
};
// Calls the base handler, resolves g_011f5b34_arg1 to a string, grows pkStrings if its index reached the size, then stores the string at that index.
// @fnv 0x00a74690
void FUN_00a74690_shell::NiTriShape_GetViewerStrings(StrArr* pkStrings)
{
    NiTriBasedGeom_GetViewerStrings(pkStrings);
    char* pStr = FUN_00a7d330(g_011f5b34_arg1);
    unsigned int uiIndex = *(unsigned short*)((char*)pkStrings + 0xa);
    if (uiIndex >= *(unsigned short*)((char*)pkStrings + 8))
        pkStrings->SetSize(uiIndex + *(unsigned short*)((char*)pkStrings + 0xe));
    pkStrings->SetAt(uiIndex, pStr);
}
}  // namespace fnv_00a74690

struct FUN_00a74480 : public NiTriBasedGeom
{
    explicit FUN_00a74480(NiTriBasedGeomData* geometry);
    virtual ~FUN_00a74480();
};
// @fnv 0x00a74480
FUN_00a74480::FUN_00a74480(NiTriBasedGeomData* geometry) : NiTriBasedGeom(geometry)
{}

extern void __cdecl FUN_00a9b140();

// @fnv 0x00a744c0
void __cdecl FUN_00a744c0()
{
    FUN_00a9b140();
}

void FUN_00a9b190();
// @fnv 0x00a74500
void FUN_00a74500()
{
    FUN_00a9b190();
}

void FUN_00a89770();
// @fnv 0x00a74510
void FUN_00a74510()
{
    FUN_00a89770();
}

class NiStream;

void FUN_00a74780(NiStream& stream);

// @fnv 0x00a98eb0
void FUN_00a98eb0(NiStream& stream)
{
    FUN_00a74780(stream);
}

void __cdecl FUN_00a9b1a0();

// @fnv 0x00a71d10
void __cdecl FUN_00a71d10()
{
    FUN_00a9b1a0();
}
