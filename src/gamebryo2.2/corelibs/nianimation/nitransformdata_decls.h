// gamebryo2.2/corelibs/nianimation/nitransformdata_decls.h: declares AnimationKey, TimedRotationKey, NiTransformData
#ifndef FNV_NITRANSFORMDATA_DECLS_H
#define FNV_NITRANSFORMDATA_DECLS_H


#include "NiObject.h"

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
};

class TimedRotationKey
{
  public:
    void ClearFloatKeys();
};
class PositionKeyInterpolator;
class TimedAnimationKey;

typedef void(__cdecl* NiRotKeyDeleteFunction)(TimedRotationKey*);
typedef void(__cdecl* NiPosKeyDeleteFunction)(PositionKeyInterpolator*);
typedef void(__cdecl* NiFloatKeyDeleteFunction)(TimedAnimationKey*);
extern NiRotKeyDeleteFunction DAT_011f38d0[AnimationKey::NUMKEYTYPES];
extern NiPosKeyDeleteFunction DAT_011f38b8[AnimationKey::NUMKEYTYPES];
extern NiFloatKeyDeleteFunction DAT_011f38a0[AnimationKey::NUMKEYTYPES];
extern unsigned char DAT_011f3764[AnimationKey::NUMKEYTYPES];
extern unsigned char DAT_011f375e[AnimationKey::NUMKEYTYPES];
extern unsigned char DAT_011f3758[AnimationKey::NUMKEYTYPES];

class NiTransformData : public NiObject
{
  public:
    unsigned short m_usNumRotKeys;
    unsigned short m_usNumPosKeys;
    unsigned short m_usNumScaleKeys;
    AnimationKey::KeyType m_eRotationKeyType;
    AnimationKey::KeyType m_ePositionKeyType;
    AnimationKey::KeyType m_eScaleKeyType;
    unsigned char m_ucRotationKeySize;
    unsigned char m_ucPositionKeySize;
    unsigned char m_ucScaleKeySize;
    TimedRotationKey* m_pkRotationKeys;
    PositionKeyInterpolator* m_pkPositionKeys;
    TimedAnimationKey* m_pkScaleKeyArray;

    void SetRotationKeys(TimedRotationKey*, unsigned int, AnimationKey::KeyType);
    void SetPositionKeys(PositionKeyInterpolator*, unsigned int, AnimationKey::KeyType);
    void SetScaleKeys(TimedAnimationKey*, unsigned int, AnimationKey::KeyType);
};

FNV_STATIC_ASSERT(sizeof(NiTransformData) == 0x2c);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_eRotationKeyType) == 0x10);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_pkRotationKeys) == 0x20);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_pkPositionKeys) == 0x24);
FNV_STATIC_ASSERT(offsetof(NiTransformData, m_pkScaleKeyArray) == 0x28);

#endif
