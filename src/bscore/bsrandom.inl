
// bscore/bsrandom.inl
//
// Inline helpers over the MersenneTwister random-number service. The original file
// defines each helper on a single line; the bodies below are expanded for
// review but compile to the same /Od out-of-line comdat copies.
#include "bsrandom.h"

// @fnv 0x00476c00
inline MersenneTwister* MersenneTwister::GetRandomGenerator()
{
    static MersenneTwister s_instance;
    return &s_instance;
}

// @fnv 0x00476b70
float RandomFloat(float lo, float hi)
{
    return MersenneTwister::GetRandomGenerator()->Float(lo, hi);
}

// @fnv 0x005c5420
float RandomFloat0To1()
{
    return MersenneTwister::GetRandomGenerator()->Float0To1();
}

// @fnv 0x004dff00
bool RandomBoolean(float chance)
{
    return MersenneTwister::GetRandomGenerator()->Bool(chance);
}

// @fnv 0x004dff60
float MersenneTwister::Float0To1()
{
    unsigned int value = GetRandomUInt();
    return (float)(value * (1.0 / 4294967296.0));
}

// @fnv 0x004dff20
bool MersenneTwister::Bool(float chance)
{
    return chance >= Float0To1();
}

#include "bsrandom_singleton.h"
// @fnv 0x0049fef0
bsrandom_singleton::MersenneTwister* bsrandom_singleton::MersenneTwister::GetRandomGenerator()
{
    if (!DAT_011c57f8)
        DAT_011c57f8 = new MersenneTwister;
    return DAT_011c57f8;
}
