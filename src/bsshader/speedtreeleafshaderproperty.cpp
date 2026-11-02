
// src/bsshader/speedtreeleafshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/speedtreeleafshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);

extern long DAT_011f4400;

// Base of the object: a NiRefObject-like polymorphic base whose constructor is
struct NiRefObject
{
    virtual void v0();

    int m_kPointA;

    NiRefObject();
};

struct FUN_00bb33c0 : NiRefObject
{
    int m_kPointB;
    unsigned short m_iThirdValue;

    FUN_00bb33c0();
    virtual ~FUN_00bb33c0();
};

NiRefObject::NiRefObject()
{
    m_kPointA = 0;
    InterlockedIncrement(&DAT_011f4400);
}

// @fnv 0x00bb33c0
FUN_00bb33c0::FUN_00bb33c0()
{
    m_kPointB = 0;
    m_iThirdValue = 0;
}
