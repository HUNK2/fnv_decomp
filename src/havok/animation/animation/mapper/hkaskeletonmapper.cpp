
// src/havok/animation/animation/mapper/hkaskeletonmapper.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/mapper/hkaskeletonmapper.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkaSkeletonMapper.h"

struct FUN_00ce4ab0Allocator
{
    virtual void FUN_00ce4ab0Unused1() = 0;
    virtual void FUN_00ce4ab0Unused2() = 0;
    virtual void FUN_00ce4ab0Free(void* object, unsigned short size) = 0;
};

struct FUN_00ce4ab0Router
{
    unsigned char pad[16];
    FUN_00ce4ab0Allocator* allocator;
};

FUN_00ce4ab0Router* _D1A0E0GetMemoryRouter();
void FUN_00ce29e0();

struct FUN_00ce4ab0Class
{
    FUN_00ce4ab0Class* Destroy(unsigned int flags);
};

// Calls FUN_00ce29e0, then if flags has bit 0 set frees this through the memory router allocator using the size at offset 4, and returns this.
// @fnv 0x00ce4ab0
FUN_00ce4ab0Class* FUN_00ce4ab0Class::Destroy(unsigned int flags)
{
    FUN_00ce29e0();

    if (flags & 1)
    {
        FUN_00ce4ab0Router* router = _D1A0E0GetMemoryRouter();
        unsigned short size = *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(this) + 4);

        router->allocator->FUN_00ce4ab0Free(this, size);
    }

    return this;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" __m128 _mm_sqrt_ss(__m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
extern "C" void _mm_store_ss(float*, __m128);

struct hkaBone
{
    hkStringPtr m_name;
    hkBool m_bLockTranslation;
};

class hkaSkeleton : public hkReferencedObject
{
  public:
    hkStringPtr m_name;
    hkArray<hkInt16> m_kParentIndices;
    hkArray<hkaBone> m_kBones;
};

class hkaSkeletonMapperDataSimpleMapping
{
  public:
    hkInt16 m_sBoneA;
    hkInt16 m_sBoneB;
    int unk04;
    int unk08;
    int unk0c;
    hkQsTransform m_kAFromBTransform;
};

struct hkOstream
{
    int unk00;
    int unk04;
    int unk08;
    hkOstream* FUN_00cb1600(void* buf, int size);
    void FUN_00cc00e0();
    hkOstream& FUN_00cc01c0(const char*);
    hkOstream& WriteName(const hkStringPtr&);
    hkOstream& WriteFloat(hkReal);
};

struct hkError
{
    virtual void unk00() = 0;
    virtual void unk04() = 0;
    virtual void unk08() = 0;
    virtual int message(int type, int id, const char* description, const char* file, int line) = 0;
};

extern int DAT_01268360;

static inline float getTranslationError(const hkVector4& t)
{
    __m128 v = *(const __m128*)&t;
    __m128 v2 = _mm_mul_ps(v, v);
    __m128 v1 = _mm_shuffle_ps(v2, v2, 0x55);
    __m128 v0 = _mm_shuffle_ps(v2, v2, 0xaa);
    v1 = _mm_add_ss(v1, v2);
    v0 = _mm_add_ss(v0, v1);
    v0 = _mm_sqrt_ss(v0);
    float len;
    _mm_store_ss(&len, v0);
    return len;
}

// For ragdoll mappings, warns if locked-translation bones are misaligned or if no bone in skeleton B has translation locked.
// @fnv 0x00ce2ae0
void ValidateRagdollMapping(hkaSkeletonMapperData* apMapperData)
{
    if (apMapperData->m_eMappingType == hkaSkeletonMapperData::HK_RAGDOLL_MAPPING)
    {
        for (int iIndex = 0; iIndex < apMapperData->m_kSimpleMappings.m_iElementCount; ++iIndex)
        {
            const hkaSkeletonMapperDataSimpleMapping& mapping = apMapperData->m_kSimpleMappings.m_data[iIndex];
            const hkaBone& boneA = apMapperData->m_pSkeletonA->m_kBones.m_data[mapping.m_sBoneA];
            const hkaBone& boneB = apMapperData->m_pSkeletonB->m_kBones.m_data[mapping.m_sBoneB];

            if (boneB.m_bLockTranslation)
            {
                float len = getTranslationError(mapping.m_kAFromBTransform.m_vTranslation);
                if (len > 0.01f)
                {
                    int buf[128];
                    hkOstream str;
                    str.FUN_00cb1600(buf, sizeof(buf));
                    str.FUN_00cc01c0("Bones A:")
                        .WriteName(boneA.m_name)
                        .FUN_00cc01c0(" and B:")
                        .WriteName(boneB.m_name)
                        .FUN_00cc01c0(" are not fully aligned (error :")
                        .WriteFloat(len)
                        .FUN_00cc01c0(").");
                    ((hkError*)DAT_01268360)
                        ->message(1, 0xabbaefbf, (char*)buf, ".\\Mapper\\hkaSkeletonMapper.cpp", 499);
                    str.FUN_00cc00e0();
                }
            }
        }
    }

    if (apMapperData->m_eMappingType == hkaSkeletonMapperData::HK_RAGDOLL_MAPPING)
    {
        hkaSkeleton* skeletonB = apMapperData->m_pSkeletonB;
        for (int iIndex = 0; iIndex < skeletonB->m_kBones.m_iElementCount; ++iIndex)
        {
            if (skeletonB->m_kBones.m_data[iIndex].m_bLockTranslation)
                return;
        }

        int buf[128];
        hkOstream str;
        str.FUN_00cb1600(buf, sizeof(buf));
        str.FUN_00cc01c0(
            "None of the bones in skeleton have translations locked - did you forget to lock translations ?.");
        ((hkError*)DAT_01268360)->message(1, 0xabba77a5, (char*)buf, ".\\Mapper\\hkaSkeletonMapper.cpp", 521);
        str.FUN_00cc00e0();
    }
}

#include <math.h>
// Clamps the input to the domain of asin and returns the result, substituting the sign of pi/2 when the magnitude is at least 1.0f.
// @fnv 0x00ce0c40
float ClampAsin(float angle)
{
    float original = angle;
    angle = fabsf(angle);
    if (angle >= 1.0f)
    {
        if (original > 0.0f)
            angle = 1.5707963705062866f;
        else
            angle = -1.5707963705062866f;
    }
    else
    {
        return asinf(original);
    }
    return angle;
}
