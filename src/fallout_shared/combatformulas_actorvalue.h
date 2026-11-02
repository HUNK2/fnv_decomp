// Source layout: ActorValueOwner. PC corrections are in generate_headers.py.
#ifndef FNV_ACTORVALUEOWNER_H
#define FNV_ACTORVALUEOWNER_H

#include "layout_support.h"
#pragma pack(push, 4)
class ActorValueOwner
{
  public:
    virtual int GetBaseActorValue(ActorValue::Index actorValue);
    virtual float GetBaseActorValueFloat(ActorValue::Index actorValue);
    virtual int GetActorValue(ActorValue::Index actorValue);
    virtual float GetCurrentActorValue(ActorValue::Index actorValue);
    virtual float GetPermanentActorValueFloat(ActorValue::Index actorValue);
    virtual float GetTemporaryActorValue(ActorValue::Index actorValue);
    virtual float GetDamageActorValue(ActorValue::Index actorValue);
    virtual int GetPermanentActorValue(ActorValue::Index actorValue);
    virtual float GetPermanentActorValueAdjustment(ActorValue::Index actorValue);
    virtual TESForm* GetActorValueOwnerForm();
    virtual unsigned short GetActorValueOwnerType();
    Actor* GetActorOwner();
    float GetActorValueFloatByIndex(ActorValue::Index index);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ActorValueOwner) == 0x4);
#endif
