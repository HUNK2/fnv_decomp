// Source layout: GarbageCollector. PC corrections are in generate_headers.py.
#ifndef FNV_GARBAGECOLLECTOR_H
#define FNV_GARBAGECOLLECTOR_H

#include "processlists_layout_support.h"
class GarbageCollector
{
  public:
    static void Remove(TESObjectREFR* reference);
    static void Add(BSTempEffect* effect);
    static NiTObjectArray<TESObjectREFR*> ms_kReferencesQueuedForRemoval;
    static NiTObjectArray<TESObjectREFR*> ObjectGarbageB;
};
FNV_STATIC_ASSERT(sizeof(GarbageCollector) == 0x1);
#endif
