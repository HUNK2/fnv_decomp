// src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/collectioncollection3/hkpcollectioncollectionagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" void __cdecl InitAndReturnTail(void*, void*, void*);
extern "C" void __cdecl FUN_00d34db0(void*, void*, void*);
extern "C" void __cdecl FUN_00d34d30(void*, void*, void*);
extern "C" void __cdecl ForwardCall(void*, void*, void*);
extern "C" void __cdecl FUN_00d34d80(void*, void*, void*);
extern "C" void __cdecl FUN_00d35770(void*, void*, void*);
extern "C" void __cdecl FUN_00da6dc0(void*, void*, void*);
struct FUN_00d36270_s {
    void* m_vt;
    void* m_kPointA;
    void* m_kPointB;
    void* m_iThirdValue;
    void* m_iFourthElementInteger;
    void* m_usTrailingValue;
    void* m_f;
    void* m_g;
    void* m_h;
    void* m_i;
    void* m_iUnknownValue;
    void* m_k;
    unsigned char m_flag;
};
void FUN_00d36270(FUN_00d36270_s* self);
void __cdecl FUN_00da35f0(void*, float, float, void*);
void __cdecl FUN_00d34d80(void* apUnused, void* b, float afValue1, float afValue2, void* e);
struct FUN_00cf5830_cls {
    int unk00;
    int unk04;
    int unk08;
    int m_0c;
    int unk10;
    unsigned short unk14;
    unsigned short m_16;

    int FUN_00cf5830();
};
struct __declspec(align(16)) D36270Data {
    void* vtable;
    void* a;
    void* b;
    void* c;
    void* d;
    void* e;
    void* f;
    void* g;
    void* h;
    void* i;
    void* j;
    void* k;
    unsigned char flag0;
    unsigned char flag1;
    unsigned char flag2;
};
void FUN_00d36270(D36270Data*);
struct D362Script {
    void AddEntry(D36270Data*, int row, int column);
};
extern unsigned char DAT_01268ad5;
void FUN_00d362c0(D362Script* script);
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
extern "C" void __cdecl FUN_00d97250(void*, void*, void*);
extern "C" const char str_010ceca8[];
struct S00d34d30_Obj
{
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6(const char* s);
    virtual void m7();
};
void __cdecl FUN_00d34d30(void* a, void* b, void* c, void* d);
struct Obj {
    virtual void* m00();
    virtual void* m04();
    virtual void* m08();
    virtual void* m0c();
    virtual void* m10();
};
struct Local {
    void* f0;
    void* f1;
    void* f2;
    void* f3;
    void* f4;
    void* f5;
    void* f6;
    void* f7;
};
extern "C" void __cdecl FUN_00da4900(void*, void*);
void __cdecl FUN_00d34db0(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7);
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" {
__m128 _mm_load_ps(const float* p);
void _mm_store_ps(float* p, __m128 v);
__m128 _mm_add_ps(__m128 a, __m128 b);
__m128 _mm_sub_ps(__m128 a, __m128 b);
__m128 _mm_mul_ps(__m128 a, __m128 b);
__m128 _mm_min_ps(__m128 a, __m128 b);
__m128 _mm_max_ps(__m128 a, __m128 b);
__m128 _mm_add_ss(__m128 a, __m128 b);
__m128 _mm_sqrt_ss(__m128 a);
__m128 _mm_shuffle_ps(__m128 a, __m128 b, unsigned int imm8);
__m128 _mm_set_ps1(float a);
}
extern __m128 DAT_010ec7f0;
extern const __m128 DAT_011b6d70;
// AABB quantization clip max
extern __m128 DAT_01267e30;
typedef unsigned int hkpShapeKey;
struct hkFloat4
{
    float x;
    float y;
    float z;
    float w;
};
struct hkSimdRealq
{
    __m128 m_vValue;
};
struct hkVector4q
{
    __m128 m_vComponents;

    __forceinline void setSub4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setAdd4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void mul4(const hkVector4q& a) { m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents); }
    __forceinline void setMin4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_min_ps(a.m_vComponents, b.m_vComponents); }
    __forceinline void setMax4(const hkVector4q& a, const hkVector4q& b) { m_vComponents = _mm_max_ps(a.m_vComponents, b.m_vComponents); }

    __forceinline void setInterpolate4(const hkVector4q& a, const hkVector4q& b, const hkVector4q& t)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(_mm_load_ps(DAT_010ec7f0.m128_f32), t.m_vComponents), a.m_vComponents), _mm_mul_ps(t.m_vComponents, b.m_vComponents));
    }

    __forceinline void setAddMul4(const hkVector4q& a, const hkVector4q& b, const hkSimdRealq& r)
    {
        m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), b.m_vComponents), a.m_vComponents);
    }

    __forceinline hkSimdRealq getSimdAt3() const
    {
        hkSimdRealq r;
        r.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return r;
    }

    __forceinline hkSimdRealq length3() const
    {
        const __m128 sq = _mm_mul_ps(m_vComponents, m_vComponents);
        const __m128 s = _mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq));
        hkSimdRealq r;
        r.m_vValue = _mm_sqrt_ss(s);
        return r;
    }
};
union hkVector4u
{
    hkFloat4 m_f;
    hkVector4q m_v;
};
struct hkTransformq
{
    hkVector4q m_kColumn0;
    hkVector4q m_kColumn1;
    hkVector4q m_kColumn2;
    hkVector4q m_vTranslation;
};
__forceinline void SetTransformedPoint(hkVector4q& out, const hkTransformq& t, const hkVector4q& b)
{
    const __m128 b0 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x00);
    const __m128 r0 = _mm_mul_ps(b0, t.m_kColumn0.m_vComponents);
    const __m128 b1 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0x55);
    const __m128 r1 = _mm_mul_ps(b1, t.m_kColumn1.m_vComponents);
    const __m128 b2 = _mm_shuffle_ps(b.m_vComponents, b.m_vComponents, 0xaa);
    const __m128 r2 = _mm_mul_ps(b2, t.m_kColumn2.m_vComponents);
    out.m_vComponents = _mm_add_ps(_mm_add_ps(r1, r0), _mm_add_ps(r2, t.m_vTranslation.m_vComponents));
}
struct hkMotionStateq
{
    hkTransformq m_kMotionTransform;
    hkVector4q m_vCenterOfMass0;
    hkVector4q m_vCenterOfMass1;
    hkVector4q m_qRotation0;
    hkVector4q m_qRotation1;
    hkFloat4 m_vCenterOfMassLocal;
    hkVector4q m_kDeltaAngle;
};
struct SweptTransformSamples
{
    const hkMotionStateq* m_kMotionState;
    int unk04;
    int unk08;
    int unk0C;
    hkTransformq m_kTransforms[4];
    int m_numQsTransforms;
    int unk114;
    int unk118;
    int unk11C;
    hkTransformq m_kMotionTransform;
    hkTransformq m_shapeToMotion;
};
void __cdecl FUN_00cbec90(const hkMotionStateq* motionState, SweptTransformSamples* out);
struct hkAabbq
{
    hkVector4q m_kMinimumCorner;
    hkVector4q m_kMaximumCorner;
};
struct hkAabbUint32
{
    unsigned int m_kMinimumCorner[3];
    union {
        struct { unsigned char m_ucExpansionMin[3]; unsigned char m_ucExpansionShift; };
        hkpShapeKey m_uiCollisionShapeKey;
    };
    union {
        unsigned int m_kMaximumCorner[4];
        struct { unsigned int m_maxX; unsigned int m_maxY; unsigned int m_maxZ;
                 unsigned char m_ucExpansionMax[3]; unsigned char m_expansionMaxXYZ; };
    };
};
typedef hkAabbUint32 hkAabbUint32Key;
struct hkpShapeBufferq
{
    int m_data[128];
};
class hkpShapeq
{
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void getAabb(const void* localToWorld, float tolerance, hkAabbq& out) const;
};
class hkpShapeContainerq
{
public:
    virtual void v00();
    virtual void v04();
    virtual hkpShapeKey GetFirstKey() const;
    virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey) const;
    virtual void v10();
    virtual const hkpShapeq* GetShapeForKey(hkpShapeKey key, hkpShapeBufferq& buffer) const;
};
struct hkpCdBodyq
{
    const hkpShapeq* m_pCollisionShape;
    hkpShapeKey m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyq* m_parent;

    __forceinline const hkpCdBodyq* getRootCollidable() const
    {
        const hkpCdBodyq* body = this;
        while (body->m_parent)
        {
            body = body->m_parent;
        }
        return body;
    }
};
struct hkpCollisionQualityInfoq
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int m_iQualityInfoValue10;
};
struct hkpProcessCollisionInputq
{
    int unk00;
    int unk04;
    float m_fScalar;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkVector4q m_kAabbMin;
    hkVector4q m_kAabbMaximum;
    hkVector4q m_kAabbScale;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    hkpCollisionQualityInfoq* m_pCollisionQualityInfo;
};
union hkVec4F
{
    __m128 m_vComponents;
    float m_f[4];
    __forceinline float operator()(int i) const { return m_f[i]; }
};
static __forceinline void convertToUint32WithClip(const hkVector4q& a, const hkVector4q& b, const hkVector4q& scale,
                                                  const __m128& maxVal, const __m128& minVal, unsigned int* out)
{
    hkVec4F x;
    x.m_vComponents = _mm_add_ps(a.m_vComponents, b.m_vComponents);
    x.m_vComponents = _mm_mul_ps(x.m_vComponents, scale.m_vComponents);
    x.m_vComponents = _mm_min_ps(x.m_vComponents, maxVal);
    x.m_vComponents = _mm_max_ps(x.m_vComponents, minVal);
    out[0] = fnv_FloatToInt(x(0));
    out[1] = fnv_FloatToInt(x(1));
    out[2] = fnv_FloatToInt(x(2));
    out[3] = fnv_FloatToInt(x(3));
}
struct BoundingVolumeData : hkAabbUint32
{
    unsigned short m_uiNumChildShapeAabbs;
    unsigned short m_uiCapacityChildShapeAabbs;
    hkAabbUint32* m_pChildShapeAabbs;
    hkpShapeKey* m_pChildShapeKeys;

    __forceinline bool isValid() const { return m_kMinimumCorner[0] <= m_kMaximumCorner[0]; }
};
struct hkpCollidableq : hkpCdBodyq
{
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    BoundingVolumeData m_kBoundingVolumeData;
};
void __cdecl FUN_00cf8690(hkAabbUint32Key* out, const hkAabbUint32* in);
struct hkAabbUint32Less
{
    unsigned char m_unused;
};
void __cdecl FUN_00d36360(hkAabbUint32Key* arr, int iStart, int iEnd, hkAabbUint32Less cmp);
static __forceinline void expandAabbUint32(hkAabbUint32Key* out, const hkAabbUint32* in)
{
    int shift = in->m_ucExpansionShift;
    unsigned int x = in->m_kMinimumCorner[0] - (in->m_ucExpansionMin[0] << shift);
    unsigned int y = in->m_kMinimumCorner[1] - (in->m_ucExpansionMin[1] << shift);
    unsigned int z = in->m_kMinimumCorner[2] - (in->m_ucExpansionMin[2] << shift);
    out->m_kMinimumCorner[0] = x;
    out->m_kMinimumCorner[1] = y;
    out->m_kMinimumCorner[2] = z;
    unsigned int maxX = in->m_kMaximumCorner[0] + (in->m_ucExpansionMax[0] << shift);
    unsigned int maxY = in->m_kMaximumCorner[1] + (in->m_ucExpansionMax[1] << shift);
    unsigned int maxZ = in->m_kMaximumCorner[2] + (in->m_ucExpansionMax[2] << shift);
    out->m_kMaximumCorner[0] = maxX;
    out->m_kMaximumCorner[1] = maxY;
    out->m_kMaximumCorner[2] = maxZ;
}
static __forceinline void copyCachedAabbs(const BoundingVolumeData& bvd, int useContinuous, hkAabbUint32Key* aabbsOut, int& numAabbs)
{
    const hkAabbUint32* childAabbs = bvd.m_pChildShapeAabbs;
            const hkpShapeKey* keys = bvd.m_pChildShapeKeys;
            hkAabbUint32Key* out = aabbsOut;
            for (int i = 0; i < bvd.m_uiNumChildShapeAabbs; i++)
            {
                if (useContinuous)
                {
                    expandAabbUint32(out, childAabbs);
                }
                else
                {
                    FUN_00cf8690(out, childAabbs);
                }
                numAabbs++;
                out->m_uiCollisionShapeKey = *keys++;
                childAabbs++;
                out++;
            }
}
int __cdecl FUN_00d351c0(const hkpCdBodyq* body, int useCache, const hkpShapeContainerq* container, const hkpProcessCollisionInputq* input, hkAabbUint32Key* aabbsOut);
typedef unsigned int hkUint32;
struct hkStringQ {
    static __forceinline void memCpy16NonEmpty(void* dst, const void* src, int numQuads)
    {
        const hkUint32* src32 = reinterpret_cast<const hkUint32*>(src);
        hkUint32* dst32 = reinterpret_cast<hkUint32*>(dst);
        do
        {
            dst32[0] = src32[0];
            dst32[1] = src32[1];
            dst32[2] = src32[2];
            dst32[3] = src32[3];
            dst32 += 4;
            src32 += 4;
        } while (--numQuads > 0);
    }
};
struct __declspec(align(16)) SortEntry {
    hkUint32 m_key;
    hkUint32 unk04;
    hkUint32 unk08;
    hkUint32 unk0C;
    hkUint32 unk10;
    hkUint32 unk14;
    hkUint32 unk18;
    hkUint32 unk1C;
    SortEntry() {}
    SortEntry(const SortEntry& o) { hkStringQ::memCpy16NonEmpty(this, &o, sizeof(SortEntry) / 16); }
    void operator=(const SortEntry& o) { hkStringQ::memCpy16NonEmpty(this, &o, sizeof(SortEntry) / 16); }
};
struct SortEntryLess {
    bool operator()(const SortEntry& a, const SortEntry& b) const { return a.m_key < b.m_key; }
};
template <typename T>
__forceinline void hkSwap(T& x, T& y)
{
    T t(y);
    y = x;
    x = t;
}
void __cdecl FUN_00d36360(SortEntry* pArr, int d, int h, SortEntryLess cmpLess);
extern "C" __m128 _mm_set_ss(float);
struct hkpAgent3ProcessInputq
{
    const hkpCdBodyq* m_pBodyA;
    const hkpCdBodyq* m_pBodyB;
    void* m_pContactManager;
    const hkpProcessCollisionInputq* m_pRayCastInput;
};
static __forceinline void interpolateCenter(hkVector4q& out, const hkVector4q& a, const hkVector4q& b, const hkSimdRealq& t)
{
    out.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, _mm_shuffle_ps(t.m_vValue,t.m_vValue,0)), a.m_vComponents), _mm_mul_ps(b.m_vComponents, _mm_shuffle_ps(t.m_vValue,t.m_vValue,0)));
}
static __forceinline void convertLowerCurrent(const hkVector4q& in, const hkVector4q& offset, const hkVector4q& scale,
                                                  const __m128& maxVal, const __m128& minVal, hkAabbUint32Key* out)
{
    hkVec4F x;
    x.m_vComponents = _mm_add_ps(offset.m_vComponents, in.m_vComponents);
    x.m_vComponents = _mm_mul_ps(x.m_vComponents, scale.m_vComponents);
    x.m_vComponents = _mm_min_ps(x.m_vComponents, maxVal);
    x.m_vComponents = _mm_max_ps(x.m_vComponents, minVal);
    out->m_kMinimumCorner[0] = fnv_FloatToInt(x(0));
    out->m_kMinimumCorner[1] = fnv_FloatToInt(x(1));
    out->m_kMinimumCorner[2] = fnv_FloatToInt(x(2));
    out->m_ucExpansionShift = fnv_FloatToInt(x(3));
}
static __forceinline void convertUpperCurrent(const hkVector4q& in, const hkVector4q& offset, const hkVector4q& scale,
                                                  const __m128& maxVal, const __m128& minVal, unsigned int* out)
{
    hkVec4F x;
    x.m_vComponents = _mm_add_ps(offset.m_vComponents, _mm_load_ps(in.m_vComponents.m128_f32));
    x.m_vComponents = _mm_mul_ps(x.m_vComponents, scale.m_vComponents);
    x.m_vComponents = _mm_min_ps(x.m_vComponents, maxVal);
    x.m_vComponents = _mm_max_ps(x.m_vComponents, minVal);
    out[0] = fnv_FloatToInt(x(0));
    out[1] = fnv_FloatToInt(x(1));
    out[2] = fnv_FloatToInt(x(2));
    out[3] = fnv_FloatToInt(x(3));
}
static __forceinline void quantizeAabb(const hkAabbq& aabb, const hkpProcessCollisionInputq* in, hkAabbUint32Key* out) {
 __m128 maxVal=DAT_011b6d70;
 convertLowerCurrent(aabb.m_kMinimumCorner,in->m_kAabbMin,in->m_kAabbScale,maxVal,DAT_01267e30,out);
 convertUpperCurrent(aabb.m_kMaximumCorner,in->m_kAabbMaximum,in->m_kAabbScale,maxVal,DAT_01267e30,out->m_kMaximumCorner);
}
void __cdecl FUN_00d34e10(const hkpAgent3ProcessInputq& input, const hkpShapeContainerq* container, const hkpCdBodyq* body, const hkpShapeKey* keys, int numKeys, hkAabbUint32Key* __restrict aabbsOut);
