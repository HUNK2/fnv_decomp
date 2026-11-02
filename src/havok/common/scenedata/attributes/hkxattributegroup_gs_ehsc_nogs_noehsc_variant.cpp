
// src/havok/common/scenedata/attributes/hkxattributegroup_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/scenedata/attributes/hkxattributegroup.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/scenedata/attributes/hkxattributegroup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/scenedata/attributes/hkxattributegroup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkxAttributeGroup.h"
__forceinline void* __cdecl operator new(unsigned int, void* pvWhere) throw()
{
    return pvWhere;
}
struct FUN_00cb0c00_class
{
    void FUN_00cb0c00() throw();
};
class hkReferencedObject
{
  public:
    void FUN_00c90510() throw();
    void removeReference() throw();
};
struct hkMemoryAllocatorE5CD;
void __cdecl FUN_00c908c0(hkMemoryAllocatorE5CD& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();
void FUN_00d2cc70(void* pvDst, void* pvSrc, unsigned int uiNumBytes) throw();
struct FUN_00cb0bd0
{
    char* m_pcString;
    FUN_00cb0bd0(const FUN_00cb0bd0& kOther) throw();
    ~FUN_00cb0bd0() throw()
    {
        ((FUN_00cb0c00_class*)this)->FUN_00cb0c00();
    }
};
struct hkRefVariantE5CD
{
    hkReferencedObject* m_pRetainedObject;
    hkRefVariantE5CD(const hkRefVariantE5CD& kOther) throw()
    {
        if (kOther.m_pRetainedObject)
            kOther.m_pRetainedObject->FUN_00c90510();
        m_pRetainedObject = kOther.m_pRetainedObject;
    }
    ~hkRefVariantE5CD() throw()
    {
        if (m_pRetainedObject)
            m_pRetainedObject->removeReference();
        m_pRetainedObject = 0;
    }
};
struct hkxAttributeE5CD
{
    FUN_00cb0bd0 m_name;
    hkRefVariantE5CD m_uiFilterValue;
};
template <typename T> __forceinline void hkDestructE5CD(T* t, int n)
{
    for (int i = 0; i < n; ++i)
        t[i].~T();
}
template <typename T> __forceinline void hkConstructWithArrayE5CD(T* t, int n, const T* s)
{
    for (int i = 0; i < n; ++i)
        new (t + i) T(s[i]);
}
struct hkArrayE5CD
{
    hkxAttributeE5CD* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void GrowArrayCapacity(hkMemoryAllocatorE5CD& kAlloc, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap2 = 2 * iCapacity;
            int iNewSize = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewSize, sizeof(hkxAttributeE5CD));
        }
    }
    void SpliceArray(hkMemoryAllocatorE5CD& kAlloc, int iIndex, int iNumDel, const hkxAttributeE5CD* pkInsert,
                     int iNumToInsert);
};
// Adapted from unverified 2026-10-25 attempts by two prior contributors.
struct NameReference
{
    unsigned int encoded;
    int FUN_00cb0a80();
};
struct TextWriter
{
    void** virtualMethods;
};
extern "C" const char str_010c9308[];
typedef void(__thiscall* WriteMethod)(TextWriter*, const char*, int);
struct AttributeFormatter
{
    int unknown00;
    int unknown04;
    TextWriter* output;
    AttributeFormatter* WriteName(NameReference* name);
};

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct AttributeObj
{
    void* unk00;
    int unk04;
    hkQuaternion* m_quaternion;
};

struct S00e5cb40_Os
{
    int unk00;
    int unk04;
    int unk08;
    void FUN_00cb1600(char* buf, int size);
    S00e5cb40_Os& FUN_00cc01c0(const char* s);
    S00e5cb40_Os& WriteName(const hkStringPtr& s);
    void FUN_00cc00e0();
};

struct S00e5cb40_Err
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void report(int level, unsigned int id, char* buf, const char* file, int line);
};

extern "C" S00e5cb40_Err* DAT_01268360;

struct S00e5cb40_Grp : hkxAttributeGroup
{
    AttributeObj* FUN_00e5c670(const char* name);
    int FUN_00e5cb40(const char* name, bool warnIfNotFound, hkQuaternion* out);
};

// @fnv 0x00e5cb40
int S00e5cb40_Grp::FUN_00e5cb40(const char* name, bool warnIfNotFound, hkQuaternion* out)
{
    AttributeObj* attr = FUN_00e5c670(name);
    if (attr)
    {
        *(__m128*)out = *(__m128*)attr->m_quaternion;
        return 0;
    }
    if (warnIfNotFound)
    {
        char buf[512];
        S00e5cb40_Os os;
        os.FUN_00cb1600(buf, sizeof(buf));
        os.FUN_00cc01c0("Quaternion attribute ")
            .FUN_00cc01c0(name)
            .FUN_00cc01c0(" not found in ")
            .WriteName(m_name)
            .FUN_00cc01c0(" attribute group");
        DAT_01268360->report(1, 0xabbaab81, buf, ".\\Attributes\\hkxAttributeGroup.cpp", 0xb3);
        os.FUN_00cc00e0();
    }
    return 1;
}
