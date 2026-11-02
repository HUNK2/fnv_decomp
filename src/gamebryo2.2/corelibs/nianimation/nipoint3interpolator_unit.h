#ifndef FNV_NIPOINT3INTERPOLATOR_UNIT_H
#define FNV_NIPOINT3INTERPOLATOR_UNIT_H


#include "NiObject.h"

class NiObjectNET;

class NiPoint3
{
  public:
    float x;
    float y;
    float z;

    __forceinline NiPoint3& operator=(const NiPoint3& source)
    {
        unsigned int* destWords = reinterpret_cast<unsigned int*>(this);
        const unsigned int* sourceWords = reinterpret_cast<const unsigned int*>(&source);
        destWords[0] = sourceWords[0];
        destWords[1] = sourceWords[1];
        destWords[2] = sourceWords[2];
        return *this;
    }
};

class NiInterpolator : public NiObject
{
  public:
    float m_fLastTime;
};

class NiKeyBasedInterpolator : public NiInterpolator
{
};

class AnimationKey
{
  public:
    enum KeyType
    {
        NOINTERP = 0,
        LINKEY = 1,
        BEZKEY = 2,
        TCBKEY = 3,
        EULERKEY = 4,
        STEPKEY = 5,
        NUMKEYTYPES = 6
    };
};

class PositionKeyInterpolator
{
  public:
    static NiPoint3 InterpolatePosition(float time, PositionKeyInterpolator* keys, AnimationKey::KeyType type,
                                        unsigned int numKeys, unsigned int& lastIdx, unsigned char keySize);
};

class NiPosData : public NiObject
{
  public:
    unsigned int m_uiNumKeys;
    PositionKeyInterpolator* m_pKeyArray;
    AnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    unsigned char m_padding15[3];
};

class NiPoint3Interpolator : public NiKeyBasedInterpolator
{
  public:
    union
    {
        struct
        {
            NiPoint3 m_kValue;
            NiPosData* m_spPosData;
            unsigned int m_uiLastKeyIndex;
        };
        struct
        {
            void* state0c;
            class StateNode* state10;
            float state14, state18;
            int state1c, state20, state24;
            class ImageSpaceModifierInstanceDOF* state28;
            ImageSpaceModifierInstanceDOF* state2c;
            int state30, state34;
            bool state38;
            char pad39[3];
            int state3c;
            class TESBoundObject* state40;
            class ExtraDataList* state44;
        };
    };

    virtual bool Update(float time, NiObjectNET* target, NiPoint3& value);
    void CreateObject(int, bool);
};

extern "C" float DAT_011a9424;
extern "C" float DAT_011a9428;
extern "C" float DAT_011a942c;

#endif
