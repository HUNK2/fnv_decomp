// gamebryo2.2/corelibs/nianimation/niposkey_decls.h: declares AnimationKey, PositionKeyInterpolator
#ifndef NIPOSKEY_DECLS_H
#define NIPOSKEY_DECLS_H


#include "NiPoint3.h"

class AnimationKey
{
  public:
    enum KeyType
    {
        NOINTERP,
        LINKEY,
        BEZKEY,
        TCBKEY,
        EULERKEY,
        STEPKEY,
        NUMKEYTYPES
    };
    float m_fTime;
    float GetTime() const
    {
        return m_fTime;
    }
};

class PositionKeyInterpolator : public AnimationKey
{
  public:
    NiPoint3 m_kPositionValue;
    const NiPoint3& GetPos() const
    {
        return m_kPositionValue;
    }
    PositionKeyInterpolator* GetKeyAtIndex(unsigned int index, unsigned char size)
    {
        return reinterpret_cast<PositionKeyInterpolator*>(reinterpret_cast<char*>(this) + index * size);
    }
    static NiPoint3 InterpolatePosition(float time, PositionKeyInterpolator* keys, KeyType type, unsigned int count,
                                        unsigned int& lastIndex, unsigned char size);
};

typedef void(__cdecl* NiPosInterpFunction)(float, const AnimationKey*, const AnimationKey*, void*);
extern "C" const double DAT_010241b0;
extern NiPosInterpFunction DAT_011f3ca8[AnimationKey::NUMKEYTYPES];

#endif
