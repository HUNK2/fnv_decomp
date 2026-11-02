// gamebryo2.2/corelibs/nianimation/nifloatinterpolator_decls.h: declares AnimationKey, NiMemObject, NiFloatData, NiFloatInterpolator
#ifndef NIFLOATINTERPOLATOR_DECLS_H
#define NIFLOATINTERPOLATOR_DECLS_H

class AnimationKey
{
  public:
    enum KeyType
    {
        NOINTERP = 0
    };
};
class TimedAnimationKey;
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class NiFloatData : public NiMemObject
{
    char layout[24];

  public:
    NiFloatData();
    void SetColorKeys(TimedAnimationKey*, unsigned int, AnimationKey::KeyType);
};
template <class T> class NiPointer
{
    T* pointer;

  public:
    T* operator->() const;
    NiPointer& operator=(T*);
};
class NiFloatInterpolator
{
    char layout[16];
    NiPointer<NiFloatData> m_spFloatData;
    unsigned int m_uiLastKeyIndex;

  public:
    void SetAnimationKeys(TimedAnimationKey*, unsigned int, AnimationKey::KeyType);
};
#endif
