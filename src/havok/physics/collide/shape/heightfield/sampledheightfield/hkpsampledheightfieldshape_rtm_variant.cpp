
// src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/heightfield/sampledheightfield/hkpsampledheightfieldshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpSampledHeightFieldShape.h"
#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged
union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; unsigned __int64 m128_u64[2]; };
extern "C" __m128 _mm_load_ps1(const float*);
extern float DAT_01012068;
extern double DAT_01012070;
struct Cls_00d24670 {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
    virtual void v30();
    virtual float getH(int x, int y);
    virtual void getFlip(bool& flip);
    void FUN_00d24670(int x, int y, float fx, float fy, __m128* nrm, float* height, int* flag);
};
struct hkInfoD260 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    float m_fScalar;
};
class hkBoolD260 {
public:
    hkBoolD260(bool b) { m_cBooleanValue = (char)b; }
    hkBoolD260(const hkBoolD260& o) { m_cBooleanValue = o.m_cBooleanValue; }

    char m_cBooleanValue;
};
class hkCollectorD260 {
public:
    hkCollectorD260(hkInfoD260* info) : m_fScalar(info->m_fScalar), m_bHasHit(false), m_info(info) {}
    virtual void AddHit(void* hit);

    float m_fScalar;
    bool m_bHasHit;
    hkInfoD260* m_info;
};
struct FUN_00d24b50_Obj {
    void __thiscall FUN_00d24b50(void* object, int flags, hkBoolD260 flag2, float f, hkCollectorD260* collector);
};
class hkShapeD260 : public FUN_00d24b50_Obj {
public:
    hkBoolD260 __thiscall FUN_00d26080(void* object, hkInfoD260* info);
};
struct S00d261b0_Elem {
    __m128 v00;
    float f10;
    int i14;
    int unk18;
    int unk1c;
    int m_slots[8];
    int m_idx40;
};
struct S00d261b0_cls {
    int unk00;
    float f04;
    unsigned char b08;
    S00d261b0_Elem* p0c;
    void UpdateMinValue(int a0, int a1);
};
extern int DAT_010ce310;
struct Arg3 {
    int unk00;
    float m_04;
};
struct Local12 {
    void* m_00;
    float m_04;
    const Arg3* m_08;
};
struct Val1 {
    unsigned char m_00;
    Val1() : m_00(0) {}
    Val1(const Val1& o) : m_00(o.m_00) {}
};
struct Host {
    void FUN_00d24b50(int a1, int a2, Val1 v, float f, Local12* pLocal);
    void FUN_00d260d0(int a1, int a2, const Arg3* a3);
};
struct __declspec(align(16)) RayData {
    float x; float y; float z; float w;
    float endX; float endY; float endZ; float endW;
    float extraX; float extraY; float extraZ; float extraW;
};
struct Input {
    RayData base;
    float f30;
    float f34;
};
struct Obj {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    float unk24;

    void FUN_00d24b50(RayData* data, void* arg2, hkBoolD260 arg3, float arg4, void* arg5);
    void FUN_00d26120(Input* input, void* arg2, void* arg3);
};
extern "C" __m128 _mm_mul_ps(__m128, __m128);
__declspec(align(16)) const hkVector4 halfScale = {0.5f, 0.5f, 0.5f, 0.5f};
struct SampledHeightField : hkpSampledHeightFieldShape {
    virtual void slot01();
    virtual void slot02();
    virtual void slot03();
    virtual void slot04();
    virtual void slot05();
    virtual void slot06();
    virtual void slot07();
    virtual void slot08();
    virtual void slot09();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual float getHeightAt(int x, int z);
    void FUN_00d249f0(hkUlong transform, float tolerance, hkUlong aabb);
};
void __cdecl FUN_00d26230(hkUlong, const hkVector4&, const hkVector4&, float, hkUlong);

inline void* operator new(unsigned int,void* p) throw() { return p; }
extern "C" { __m128 _mm_set_ps(float,float,float,float); __m128 _mm_setr_ps(float,float,float,float); __m128 _mm_mul_ps(__m128,__m128); __m128 _mm_load_ss(const float*); __m128 _mm_shuffle_ps(__m128,__m128,int); }



struct hkVec4
{
    __m128 m_vComponents;
    void set(float x, float y, float z, float w = 0.0f)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
    void operator=(const hkVec4& v) { m_vComponents = v.m_vComponents; }
    void mul4(const hkVec4& a) { m_vComponents = _mm_mul_ps(m_vComponents, a.m_vComponents); }
    void setMul4(float r, const hkVec4& a) { __m128 s = _mm_load_ss(&r); __m128 t = _mm_shuffle_ps(s, s, 0); m_vComponents = _mm_mul_ps(t, a.m_vComponents); }
    float& operator()(int i) { return m_vComponents.m128_f32[i]; }
    const float& operator()(int i) const { return m_vComponents.m128_f32[i]; }
};

float FUN_00d97440() throw();

enum HeightFieldType { HEIGHTFIELD_STORAGE = 0, HEIGHTFIELD_COMPRESSED = 1, HEIGHTFIELD_USER = 2 };

template <typename ENUM, typename STORAGE>
struct hkEnumT
{
    hkEnumT() {}
    hkEnumT(ENUM e) { m_kStorage = static_cast<STORAGE>(e); }
    void operator=(ENUM e) { m_kStorage = static_cast<STORAGE>(e); }
    STORAGE m_kStorage;
};

struct hkBoolT
{
    hkBoolT() {}
    hkBoolT(bool b) { m_cBooleanValue = static_cast<char>(b); }
    char m_cBooleanValue;
};

struct hkSampledHeightFieldShapeCinfo
{
    hkVec4 m_vScale;
    int m_iXResolution;
    int m_iZResolution;
    float m_fMinHeight;
    float m_fMaxHeight;
    char m_bUseProjectionBasedHeight;
};

struct hkRefObj
{
    hkRefObj() : m_sReferenceCount(1) {}
    virtual ~hkRefObj();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct hkShapeBase : hkRefObj
{
    hkShapeBase(unsigned int type) : m_ulUserData(0), m_type(type) {}
    unsigned long m_ulUserData;
    unsigned int m_type;
};

struct hkHeightFieldBase : hkShapeBase
{
    hkHeightFieldBase(unsigned int type) : hkShapeBase(type) {}
};

struct HeightField : hkHeightFieldBase
{
    __forceinline HeightField(const hkSampledHeightFieldShapeCinfo& ci, HeightFieldType hfType);
    virtual ~HeightField();
    HeightField* FUN_00d248a0(const hkSampledHeightFieldShapeCinfo& ci, HeightFieldType hfType);
    int m_iXResolution;
    int m_iZResolution;
    float m_fHeightScale;
    char m_bUseProjectionBasedHeight;
    hkEnumT<HeightFieldType, unsigned char> m_ucHeightFieldType;
    hkVec4 m_kHeightScaleVector;
    hkVec4 m_kInverseScale;
    hkVec4 m_kOffset;
    hkVec4 SetCenterPosition;
};

__forceinline HeightField::HeightField(const hkSampledHeightFieldShapeCinfo& ci, HeightFieldType hfType)
    : hkHeightFieldBase(13), m_ucHeightFieldType(hfType)
{
    m_iXResolution = ci.m_iXResolution;
    m_iZResolution = ci.m_iZResolution;
    m_bUseProjectionBasedHeight = ci.m_bUseProjectionBasedHeight;

    SetCenterPosition.set(ci.m_iXResolution - 1.0f, ci.m_fMaxHeight - ci.m_fMinHeight, ci.m_iZResolution - 1.0f);
    SetCenterPosition.mul4(ci.m_vScale);

    if (ci.m_fMinHeight > ci.m_fMaxHeight)
    {
        m_fHeightScale = -1.0f;
        SetCenterPosition(1) = -1.0f;
    }
    else
    {
        m_fHeightScale = (ci.m_fMaxHeight + ci.m_fMinHeight) * 0.5 * ci.m_vScale(1);
    }

    m_kHeightScaleVector = ci.m_vScale;
    m_kInverseScale.set(1.0f / ci.m_vScale(0), 1.0f / ci.m_vScale(1), 1.0f / ci.m_vScale(2));

    hkVec4 offset;
    offset.setMul4(FUN_00d97440(), m_kHeightScaleVector);
    offset.m_vComponents.m128_f32[1] = 0.0f;
    m_kOffset = offset;
}

// @fnv 0x00d248a0
HeightField* HeightField::FUN_00d248a0(const hkSampledHeightFieldShapeCinfo& ci, HeightFieldType hfType) { __assume(this != 0); return new(this) HeightField(ci,hfType); }
