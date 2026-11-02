// gamebryo2.2/corelibs/nianimation/nifloatdata_decls.h: declares NiObject, AnimationKey, NiFloatData
#ifndef NIFLOATDATA_DECLS_H
#define NIFLOATDATA_DECLS_H

class TimedAnimationKey;
class NiStream;
class NiObject
{
  public:
    virtual void LoadBinary(NiStream&);
    unsigned int refCount;
};
class AnimationKey
{
  public:
    enum KeyType
    {
        NiAnimationKey__KeyType_NOINTERP = 0,
        NiAnimationKey__KeyType_LINKEY = 1,
        NiAnimationKey__KeyType_BEZKEY = 2,
        NiAnimationKey__KeyType_TCBKEY = 3,
        NiAnimationKey__KeyType_EULERKEY = 4,
        NiAnimationKey__KeyType_STEPKEY = 5,
        NiAnimationKey__KeyType_NUMKEYTYPES = 6
    };
};
class NiFloatData : public NiObject
{
  public:
    unsigned int m_uiNumKeys;
    TimedAnimationKey* m_pKeyArray;
    AnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    void SetColorKeys(TimedAnimationKey*, unsigned int, AnimationKey::KeyType);
    virtual void LoadBinary(NiStream&);
};
extern unsigned char DAT_011f3758[];
extern void(__cdecl* DAT_011f38a0[])(TimedAnimationKey*);
#endif
