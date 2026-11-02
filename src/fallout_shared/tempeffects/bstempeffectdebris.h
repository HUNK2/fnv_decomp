//
// fallout_shared/tempeffects/bstempeffectdebris.h
//
// Temporary-effect debris object. It extends the BSTempEffect chain with the
// optional 3D node that plays the effect, the source filename the effect was
// spawned from, the two debris-counter flags and the flag marking the effect
// as a foreground (non-debris-counter) element.
//
// Standalone build: the base chain sizes come from the MSVC 2008 layout
// evidence - NiObject is 8 bytes, NiAVObject adds nothing and BSTempEffect is
// 24 bytes, so BSTempEffectDebris is 36 bytes with m_bShouldDelete at
// offset 34 (0x22).
//

#ifndef FNV_BSTEMPEFFECTDEBRIS_H
#define FNV_BSTEMPEFFECTDEBRIS_H


class TESObjectCELL;

class NiObject
{
  public:
    NiObject() : m_uiRefCount(0)
    {}
    virtual ~NiObject()
    {}

    // The compiler-inserted vptr plus the reference count make NiObject
    // exactly 8 bytes; Gamebryo stores no separate vtable member.
    unsigned int m_uiRefCount;
};

class NiAVObject : public NiObject
{
  public:
    virtual ~NiAVObject()
    {}
};

// Mirrors Gamebryo's intrusive smart pointer; only the raw handle matters for
// the debris effect's own layout.
template <class T> class NiPointer
{
  public:
    NiPointer() : m_pObject(0)
    {}
    ~NiPointer()
    {}
    NiPointer<T>& operator=(T* object)
    {
        m_pObject = object;
        return *this;
    }

    T* m_pObject;
};

class BSTempEffect : public NiAVObject
{
  public:
    BSTempEffect() : duration(0.0f), cell(0), unk10(0.0f), unk14(0)
    {}
    virtual ~BSTempEffect()
    {}

    virtual bool ShouldDelete();

    float duration;
    TESObjectCELL* cell;
    float unk10;
    unsigned char unk14;
    unsigned char pad15[3];
};

class BSTempEffectDebris : public BSTempEffect
{
  public:
    BSTempEffectDebris()
        : m_pSceneObject(), pFilename(0), m_bForegroundEffect(false), bForceDelete(false), m_bShouldDelete(false)
    {}
    virtual ~BSTempEffectDebris()
    {}

    virtual bool ShouldDelete();
    void SetIsForegroundEffect(bool foregroundElement);

    NiPointer<NiAVObject> m_pSceneObject;
    const char* pFilename;
    bool m_bForegroundEffect;
    bool bForceDelete;
    bool m_bShouldDelete;
    unsigned char pad23;
};

#endif