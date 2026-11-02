// Source layout: GarbageCollector. PC corrections are in generate_headers.py.
#ifndef FNV_GARBAGECOLLECTOR_H
#define FNV_GARBAGECOLLECTOR_H

#include "layout_support.h"
#pragma pack(push, 4)
class GarbageCollector
{
  public:
    static void Remove(TESObjectREFR* reference);
    static NiTObjectArray<TESObjectREFR*> ms_kReferencesQueuedForRemoval;
    static NiTObjectArray<TESObjectREFR*> ObjectGarbageB;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(GarbageCollector) == 0x1);
#endif
