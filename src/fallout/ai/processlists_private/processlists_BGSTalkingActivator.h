// Unit-private PC declarations from public JohnnyGuitar BGSTalkingActivator.hpp.
#ifndef FNV_PROCESSLISTS_BGSTALKINGACTIVATOR_H
#define FNV_PROCESSLISTS_BGSTALKINGACTIVATOR_H

#include "processlists_TESObjectACTI.h"
class TESObjectREFR;
class BGSVoiceType;
class BGSTalkingActivator : public TESObjectACTI
{
  public:
    // These are distinct appended virtuals in the public PC declaration.
    virtual bool IsRadioStationObject() const;
    virtual bool GetReflectedByAutoWater() const;
    TESObjectREFR* m_pTempRef;     // +0x90
    BGSVoiceType* m_kFactionList;  // +0x94
    // Exact public PC declaration/address: BGSTalkingActivator.cpp, 00516BF0.
    TESObjectREFR* GetTempRef() const;
};
FNV_STATIC_ASSERT(sizeof(BGSTalkingActivator) == 0x98);
FNV_STATIC_ASSERT(offsetof(BGSTalkingActivator, m_pTempRef) == 0x90);
FNV_STATIC_ASSERT(offsetof(BGSTalkingActivator, m_kFactionList) == 0x94);
#endif
