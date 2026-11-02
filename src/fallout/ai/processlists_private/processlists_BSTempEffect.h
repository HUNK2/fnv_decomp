// fallout/ai/processlists_private/processlists_BSTempEffect.h: declares BSTempEffect, _Type
#ifndef PROCESSLISTS_PRIVATE_BSTEMPEFFECT_H
#define PROCESSLISTS_PRIVATE_BSTEMPEFFECT_H

#include "processlists_NiObject.h"
class BGSSaveGameBuffer;
class BGSLoadGameBuffer;
class BSTempEffect : public NiObject
{
  public:
    struct _Type
    {
        enum Type
        {
            GEO_DECAL = 1,
            PARTICLE = 2,
            SIMPLE_DECAL = 3,
            MAGIC_HIT = 4,
            MAGIC_MODEL_HIT = 5,
            MAGIC_SHADER_HIT = 6
        };
    };
    typedef _Type::Type Type;
    BSTempEffect();
    virtual ~BSTempEffect();
    virtual void Initialize();
    virtual void Detach();
    virtual bool Update(float time);
    virtual NiNode* Get3D() const;
    virtual Type GetType() const;
    virtual bool IsSaveable() const;
    virtual unsigned int GetSaveSize();
    virtual void SaveGameBGS(BGSSaveGameBuffer* buffer);
    virtual void SaveGameTES();
    virtual void LoadGameBGS(BGSLoadGameBuffer* buffer);
    virtual bool LoadGameTES();
    virtual void SetTarget(TESForm* target);
    virtual void ApplyLoadBuffer(BGSLoadGameBuffer* buffer);
    virtual bool IsFirstPerson() const;
    float m_fParticleParameter5;
    TESObjectCELL* pCell;
    float m_fFirstFloatValue;
    bool bInitialized;
};
FNV_STATIC_ASSERT(sizeof(BSTempEffect) == 0x18);
FNV_STATIC_ASSERT(offsetof(BSTempEffect, m_fParticleParameter5) == 8);
FNV_STATIC_ASSERT(offsetof(BSTempEffect, pCell) == 0xc);
FNV_STATIC_ASSERT(offsetof(BSTempEffect, m_fFirstFloatValue) == 0x10);
FNV_STATIC_ASSERT(offsetof(BSTempEffect, bInitialized) == 0x14);
// Genuine external specialization declaration. The supplied generic inline
// destructor remains unchanged; this declaration avoids re-emitting its body.
template <> NiPointer<BSTempEffect>::~NiPointer();
#endif
