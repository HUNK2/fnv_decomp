// bscore/bsrandom.h
//
// Engine random-number service. The class wraps a 624-word Mersenne Twister
// state (m_uiSeed/m_uiLastValue/mt/mti) recovered from the original type records;
// members not covered by the bsrandom.inl unit are declared here and resolved
// against their canonical addresses by the unit manifest.

#ifndef FNV_BSCORE_BSRANDOM_H
#define FNV_BSCORE_BSRANDOM_H


class MersenneTwister
{
  public:
    MersenneTwister();
    void Init(unsigned int seed);
    void Seed(unsigned int seed);
    unsigned int GetRandomUInt();
    unsigned int GetRandomUInt(unsigned int bound);
    bool Bool(float chance);
    float Float(float lo, float hi);
    float Float0To1();
    float FloatNeg1To1();
    float FloatNegPiToPi();
    float FloatTwoPi();
    void Kill();
    static MersenneTwister* GetRandomGenerator();

    unsigned int m_uiSeed;
    unsigned int m_uiLastValue;
    unsigned int mt[624];
    unsigned int mti;
};

#endif
