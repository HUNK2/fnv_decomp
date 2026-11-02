// fallout/ai/processlists_private/processlists_TESBoundObject.h: declares TESBoundObject, Bounds, TESBoundObjectBounds
#ifndef PROCESSLISTS_PRIVATE_TESBOUNDOBJECT_H
#define PROCESSLISTS_PRIVATE_TESBOUNDOBJECT_H

#include "processlists_TESObject.h"
class TESBoundObject : public TESObject
{
  public:
    TESBoundObject();
    virtual ~TESBoundObject();
    virtual NiNode* Clone3DAlt(TESObjectREFR* requester);
    virtual bool ReplaceModelAlt(const char* path);
    struct Bounds
    {
        short x;
        short y;
        short z;
    };
    struct TESBoundObjectBounds
    {
        Bounds kMinBoundsCur;
        Bounds kMaxPoint;
    };
    TESBoundObjectBounds kBoundData;
};
FNV_STATIC_ASSERT(sizeof(TESBoundObject::Bounds) == 6);
FNV_STATIC_ASSERT(sizeof(TESBoundObject::TESBoundObjectBounds) == 12);
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 0x30);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, kBoundData) == 0x24);
#endif
