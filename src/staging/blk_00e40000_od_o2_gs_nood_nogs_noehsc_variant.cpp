
// src/staging/blk_00e40000_od_o2_gs_nood_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /Gy (unit src/staging/blk_00e40000_od.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/staging/blk_00e40000_od.cpp - STAGING unit created 2026-10-16 by stage_units.py for functions with no attributed unit
// (128 KB address window, od code style). Not a real source path: move functions to their real units once identified.
#include "../../include/layout_support.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

struct hkVector4
{
    __m128 m_vComponents;
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

class hkOstream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pStreamWriter;
    hkOstream(char* buf, int bufSize);     // FUN_00cb1600
    ~hkOstream();                          // FUN_00cc00e0
    hkOstream& operator<<(const char* s);  // FUN_00cc01c0
    hkOstream& operator<<(const void* p);  // WriteName
};

class hkError
{
  public:
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual int message(int type, int id, const char* description, const char* file, int line);
};
extern hkError* DAT_01268360;

extern const char str_010ecd48[];
extern const char str_010eccfc[];
extern const char str_010ecd0c[];
extern const char str_010eccc8[];

struct VectorAttribute
{
    const char* m_name;
    int m_type;
    hkVector4* m_uiFilterValue;
};

struct AttributeHolder
{
    VectorAttribute* FUN_00e5c650(const char* name);
    int FUN_00e5ca80(const char* name, unsigned char warn, hkVector4& out);
};

// @fnv 0x00e5ca80
int AttributeHolder::FUN_00e5ca80(const char* name, unsigned char warn, hkVector4& out)
{
    VectorAttribute* attr = FUN_00e5c650(name);
    if (attr)
    {
        out = *attr->m_uiFilterValue;
        return 0;
    }
    if (warn)
    {
        char assertBuf[512];
        hkOstream ostr(assertBuf, sizeof(assertBuf));
        ostr << str_010ecd48 << name << str_010eccfc << (const void*)this << str_010ecd0c;
        DAT_01268360->message(1, 0xabbaab81, assertBuf, str_010eccc8, 0xa2);
    }
    return 1;
}
