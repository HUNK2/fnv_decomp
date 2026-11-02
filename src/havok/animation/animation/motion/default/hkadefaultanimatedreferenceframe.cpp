
// src/havok/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/motion/default/hkadefaultanimatedreferenceframe.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00e41080_Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    float unk30;

    float __thiscall GetUnk30();
};

// Returns the float stored at offset 0x30 of this object.
// @fnv 0x00e41080
float __thiscall FUN_00e41080_Obj::GetUnk30()
{
    return unk30;
}

#include <xmmintrin.h>
struct E41090Vector4
{
    __m128 m_vComponents;

    void set(float x, float y, float z, float w)
    {
        m_vComponents = _mm_setr_ps(x, y, z, w);
    }
};

struct E41090Bool
{
    char m_cBooleanValue;
    E41090Bool& operator=(bool b)
    {
        m_cBooleanValue = (char)b;
        return *this;
    }
};

struct FUN_00e41090
{
    FUN_00e41090();

    int unk00;
    int unk04;
    float unk08;
    int unk0C;
    E41090Bool unk10;
    E41090Bool unk11;
    E41090Bool unk12;
    E41090Bool unk13;
    int unk14;
    int unk18;
    int unk1C;
    E41090Vector4 m_vStart;
    E41090Vector4 m_vEnd;
};

// @fnv 0x00e41090
FUN_00e41090::FUN_00e41090()
{
    unk00 = 0;
    unk04 = 0;
    unk08 = 0.0f;
    unk0C = 2;
    unk10 = false;
    unk11 = true;
    unk12 = false;
    unk13 = false;
    m_vStart.set(0.0f, 0.0f, 1.0f, 0.0f);
    m_vEnd.set(1.0f, 0.0f, 0.0f, 0.0f);
}
