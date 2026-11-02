
// src/havok/physics/dynamics/constraint/bilateral/stiffspring/hkpstiffspringconstraintdata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/bilateral/stiffspring/hkpstiffspringconstraintdata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpStiffSpringConstraintData.h"

// @fnv 0x00d4f090
void __stdcall FUN_00d4f090(char a, int* pData)
{
    if (a)
    {
        pData[1] = 1;
        pData[0] = 8;
    }
    else
    {
        pData[1] = 0;
        pData[0] = 0;
    }
}

extern "C" void* __cdecl FUN_00d21a60(void* a, int b, int c);

struct FUN_00d4f070_t
{
    void* FUN_00d4f070(int a);
};

// @fnv 0x00d4f070
void* FUN_00d4f070_t::FUN_00d4f070(int aiIndex)
{
    return FUN_00d21a60((char*)this + 0x10, 0x38, aiIndex);
}

// @fnv 0x00d4f0e0
int __cdecl FUN_00d4f0e0()
{
    return 8;
}

struct S00d4f0c0
{
    unsigned char pad[0x44];
    float f44;
    void* CheckPositive(bool* p);
};

// @fnv 0x00d4f0c0
void* S00d4f0c0::CheckPositive(bool* pbPositive)
{
    bool b = f44 > 0.0f;
    *pbPositive = b;
    return pbPositive;
}
