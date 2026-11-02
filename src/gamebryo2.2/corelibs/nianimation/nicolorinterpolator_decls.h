// gamebryo2.2/corelibs/nianimation/nicolorinterpolator_decls.h: declares AnimationKey, NiMemObject, NiColorData, NiColorInterpolator
#ifndef FNV_NICOLORINTERPOLATOR_DECLS_H
#define FNV_NICOLORINTERPOLATOR_DECLS_H

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
        STEPKEY
    };
};
class ColorAnimationKey;
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class NiColorData : public NiMemObject
{
    char storage[24];

  public:
    NiColorData();
    void SetColorKeys(ColorAnimationKey*, unsigned int, AnimationKey::KeyType);
};
template <class T> class NiPointer
{
    T* m_pObject;

  public:
    T* operator->() const;
    NiPointer& operator=(T*);
};
class NiColorInterpolator
{
    char prefix[28];
    NiPointer<NiColorData> m_spColorData;
    unsigned int m_uiLastKeyIndex;

  public:
    void SetAnimationKeys(ColorAnimationKey*, unsigned int, AnimationKey::KeyType);
};
#endif
