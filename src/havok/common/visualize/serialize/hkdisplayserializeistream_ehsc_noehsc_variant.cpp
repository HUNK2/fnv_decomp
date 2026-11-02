
// src/havok/common/visualize/serialize/hkdisplayserializeistream_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/visualize/serialize/hkdisplayserializeistream.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/visualize/serialize/hkdisplayserializeistream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/serialize/hkdisplayserializeistream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct DdabeTag
{
    bool b;
    DdabeTag() : b(false)
    {}
    DdabeTag(const DdabeTag& o) : b(o.b)
    {}
};
struct DdabeBase
{
    DdabeBase(int a, DdabeTag t);
    virtual void unk00();
};
struct FUN_00ddabe0 : DdabeBase
{
    FUN_00ddabe0(int a);
    virtual void unk00();
};
struct FUN_00ddac60_Obj
{
    int unk00;
    int unk04;
    int unk08;
    float unk0C;
};
void __stdcall FUN_00dd8fe0(FUN_00ddac60_Obj* obj, int a, int b);
void __stdcall FUN_00ddac60(FUN_00ddac60_Obj* obj);
struct ArrayRecord
{
    void* data;
    int size;
    int capacity;
};
struct ArrayPair
{
    ArrayRecord first;
    ArrayRecord second;
};
struct BSAudio
{
};
BSAudio* __cdecl FUN_00c85750();
extern "C" void __cdecl FUN_00c908c0(void*, void*, int, int);
struct FUN_00ddacd0_shell
{
    void __thiscall FUN_00dd8fe0(void* output, int elementSize, int count);
    void __thiscall FUN_00ddac60(void* output);
    void __thiscall FUN_00ddac00(void* output);
    void __thiscall FUN_00ddacd0(ArrayPair* arrays);
};
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};
struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};
struct FUN_00dd9210_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00dd91f0();

    FUN_00dd9210_cls* FUN_00dd9210(unsigned char acFlags);
};

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_set_ps1(float a);
extern "C" __m128 _mm_load_ps1(float const* p);

typedef float hkReal;
typedef signed char hkInt8;

struct hkVector4Q
{
    __m128 m_vComponents;
    void operator=(const hkVector4Q& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void SetAllComponents(hkReal r)
    {
        m_vComponents = _mm_set_ps1(r);
    }
};

struct hkTransformQ
{
    hkVector4Q m_kColumn0;
    hkVector4Q m_kColumn1;
    hkVector4Q m_kColumn2;
    hkVector4Q m_vTranslation;
    void FUN_00c6cd60(const hkTransformQ& t);
};

struct hkSphereQ
{
    hkVector4Q m_pos;
    hkSphereQ(const hkVector4Q& pos, hkReal radius)
    {
        m_pos = pos;
        m_pos.m_vComponents.m128_f32[3] = radius;
    }
};

struct hkMemoryAllocatorQ
{
    virtual void vf00();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct hkMemoryRouterQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorQ* m_pStreamAllocator;
    hkMemoryAllocatorQ& heap()
    {
        return *m_pStreamAllocator;
    }
};

__forceinline hkMemoryRouterQ* getRouterQ()
{
    return (hkMemoryRouterQ*)FUN_00c85750();
}

struct hkGeometryQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    hkGeometryQ();
    __forceinline static void* operator new(unsigned int nbytes)
    {
        return getRouterQ()->heap().AllocateMemoryBlock(nbytes);
    }
    __forceinline static void operator delete(void* p)
    {}
};

struct hkDisplayGeometryQ
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int m_type;
    int unk0C;
    hkTransformQ m_kMotionTransform;

    __forceinline static void* operator new(unsigned int nbytes)
    {
        void* b = getRouterQ()->heap().AllocateMemoryBlock(nbytes);
        static_cast<hkDisplayGeometryQ*>(b)->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
    __forceinline static void operator delete(void* p)
    {}
    __forceinline void SetGeometryTransform(const hkTransformQ& t)
    {
        m_kMotionTransform.FUN_00c6cd60(t);
    }
};

struct hkDisplayConvexQ : hkDisplayGeometryQ
{
    hkGeometryQ* m_pSourceGeometry;
    hkDisplayConvexQ(hkGeometryQ* geom);
};

struct hkDisplaySphereQ : hkDisplayGeometryQ
{
    hkSphereQ m_pSphere;
    int m_iXResolution;
    int m_iYResolution;
    int unk68;
    int unk6C;
    int unk70;
    hkDisplaySphereQ(const hkSphereQ& sphere, int xRes, int yRes);
};

struct hkDisplayBoxQ : hkDisplayGeometryQ
{
    hkVector4Q m_vHalfExtents;
    int unk60;
    hkDisplayBoxQ(const hkVector4Q& halfExtents);
};

struct hkDisplayAABBQ : hkDisplayGeometryQ
{
    hkVector4Q m_kMinimumCorner;
    hkVector4Q m_kMaximumCorner;
    int unk70;
    hkDisplayAABBQ(const hkVector4Q& min, const hkVector4Q& max);
};

struct hkDisplayConeQ : hkDisplayGeometryQ
{
    hkVector4Q m_kStartPosition;
    hkVector4Q m_kAxisEndPoints;
    hkReal m_fConeAngle;
    hkReal m_height;
    int m_iNumSegments;
    int unk7C;
    int unk80;
    hkDisplayConeQ(hkReal coneAngle, hkReal coneHeight, int numSegments, const hkVector4Q& coneAxis,
                   const hkVector4Q& startPos);
};

struct hkDisplaySemiCircleQ : hkDisplayGeometryQ
{
    hkVector4Q m_kCenterPosition;
    hkVector4Q m_vHitNormal;
    hkVector4Q m_kStartPerpendicular;
    hkReal m_fThetaMin;
    hkReal m_fThetaMax;
    hkReal m_fSphereRadius;
    int m_iNumSegments;
    int unk90;
    hkDisplaySemiCircleQ(const hkVector4Q& center, const hkVector4Q& normal, const hkVector4Q& startPerp,
                         hkReal thetaMin, hkReal thetaMax, hkReal radius, int numSegments);
};

struct hkDisplayPlaneQ : hkDisplayGeometryQ
{
    hkVector4Q m_vHitNormal;
    hkVector4Q m_kPerpendicularToNormal;
    hkVector4Q m_kCenterPosition;
    hkVector4Q m_fExtents;
    int unk90;
    hkDisplayPlaneQ(const hkVector4Q& normal, const hkVector4Q& perpToNormal, const hkVector4Q& center,
                    const hkVector4Q& extent);
};

struct hkDisplayCapsuleQ : hkDisplayGeometryQ
{
    hkVector4Q m_fMinimumV;
    hkVector4Q m_fMaximumV;
    hkReal m_fSphereRadius;
    int m_iNumSides;
    int m_iNumHeightSegments;
    int unk7C;
    int unk80;
    hkDisplayCapsuleQ(const hkVector4Q& top, const hkVector4Q& bottom, hkReal radius, int numSides,
                      int numHeightSegments);
};

struct hkDisplayCylinderQ : hkDisplayGeometryQ
{
    hkVector4Q m_fMinimumV;
    hkVector4Q m_fMaximumV;
    hkReal m_fSphereRadius;
    int m_iNumSides;
    int m_iNumHeightSegments;
    int unk7C;
    int unk80;
    hkDisplayCylinderQ(const hkVector4Q& top, const hkVector4Q& bottom, hkReal radius, int numSides,
                       int numHeightSegments);
};

struct hkDisplaySerializeIStreamQ
{
    int unk00;
    void FUN_00dd8fe0(void* buf, int elemSize, int numElems);
    void FUN_00ddac60(hkVector4Q& v);
    void FUN_00ddac80(hkTransformQ& t);
    void FUN_00ddacd0(hkGeometryQ* geom);

    __forceinline hkInt8 readInt8()
    {
        hkInt8 c;
        FUN_00dd8fe0(&c, 1, 1);
        return c;
    }
    __forceinline int readInt32()
    {
        int i;
        FUN_00dd8fe0(&i, 4, 1);
        return i;
    }
    __forceinline hkReal readFloat32()
    {
        hkReal f;
        FUN_00dd8fe0(&f, 4, 1);
        return f;
    }
    __forceinline void ReadVector4(hkVector4Q& v)
    {
        FUN_00ddac60(v);
    }
    __forceinline void ReadTransform(hkTransformQ& t)
    {
        FUN_00ddac80(t);
    }
    __forceinline void ReadGeometry(hkGeometryQ* g)
    {
        FUN_00ddacd0(g);
    }

    void FUN_00ddada0(hkDisplayGeometryQ*& geometry);
};

// @fnv 0x00ddada0
void hkDisplaySerializeIStreamQ::FUN_00ddada0(hkDisplayGeometryQ*& geometry)
{
    hkInt8 type = readInt8();

    switch (type)
    {
    case 6: {
        hkTransformQ transform;
        ReadTransform(transform);
        hkGeometryQ* geom = new hkGeometryQ;
        ReadGeometry(geom);
        geometry = new hkDisplayConvexQ(geom);
        geometry->SetGeometryTransform(transform);
        break;
    }
    case 1: {
        hkTransformQ transform;
        ReadTransform(transform);
        hkReal radius = readFloat32();
        hkVector4Q position;
        ReadVector4(position);
        hkSphereQ sphere(position, radius);
        int xRes = readInt32();
        int yRes = readInt32();
        geometry = new hkDisplaySphereQ(sphere, xRes, yRes);
        geometry->SetGeometryTransform(transform);
        break;
    }
    case 8: {
        hkTransformQ transform;
        ReadTransform(transform);
        hkReal radius = readFloat32();
        hkVector4Q top;
        ReadVector4(top);
        hkVector4Q bottom;
        ReadVector4(bottom);
        int numSides = readInt32();
        int numHeightSegments = readInt32();
        geometry = new hkDisplayCapsuleQ(top, bottom, radius, numSides, numHeightSegments);
        geometry->SetGeometryTransform(transform);
        break;
    }
    case 9: {
        hkTransformQ transform;
        ReadTransform(transform);
        hkReal radius = readFloat32();
        hkVector4Q top;
        ReadVector4(top);
        hkVector4Q bottom;
        ReadVector4(bottom);
        int numSides = readInt32();
        int numHeightSegments = readInt32();
        geometry = new hkDisplayCylinderQ(top, bottom, radius, numSides, numHeightSegments);
        geometry->SetGeometryTransform(transform);
        break;
    }
    case 2: {
        hkTransformQ transform;
        ReadTransform(transform);
        hkVector4Q halfExtents;
        ReadVector4(halfExtents);
        geometry = new hkDisplayBoxQ(halfExtents);
        geometry->SetGeometryTransform(transform);
        break;
    }
    case 3: {
        hkVector4Q minExtent;
        ReadVector4(minExtent);
        hkVector4Q maxExtent;
        ReadVector4(maxExtent);
        geometry = new hkDisplayAABBQ(minExtent, maxExtent);
        break;
    }
    case 4: {
        hkVector4Q startPos;
        ReadVector4(startPos);
        hkVector4Q axis;
        ReadVector4(axis);
        hkReal angle = readFloat32();
        hkReal height = readFloat32();
        int numSegments = readInt32();
        geometry = new hkDisplayConeQ(angle, height, numSegments, axis, startPos);
        break;
    }
    case 5: {
        hkVector4Q center;
        ReadVector4(center);
        hkVector4Q normal;
        ReadVector4(normal);
        hkVector4Q perp;
        ReadVector4(perp);
        hkReal radius = readFloat32();
        hkReal thetaMin = readFloat32();
        hkReal thetaMax = readFloat32();
        int numSegments = readInt32();
        geometry = new hkDisplaySemiCircleQ(center, normal, perp, thetaMin, thetaMax, radius, numSegments);
        break;
    }
    case 7: {
        hkVector4Q center;
        ReadVector4(center);
        hkVector4Q normal;
        ReadVector4(normal);
        hkVector4Q perpToNormal;
        ReadVector4(perpToNormal);
        hkReal e = readFloat32();
        hkVector4Q extent;
        extent.SetAllComponents(e);
        geometry = new hkDisplayPlaneQ(normal, perpToNormal, center, extent);
        break;
    }
    default:
        break;
    }
}
