// include/havok/hkpSimulation.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x2C.
#ifndef FNV_HAVOK_HKPSIMULATION_H
#define FNV_HAVOK_HKPSIMULATION_H

#include "hkBase.h"
#include "hkReferencedObject.h"
class hkpWorld;
#pragma pack(push, 1)
class hkpSimulation : public hkReferencedObject
{
  public:
    enum FindContacts
    {
        FIND_CONTACTS_DEFAULT = 0,
        FIND_CONTACTS_EXTRA = 1
    };
    enum ResetCollisionInformation
    {
        RESET_TOI = 1,
        RESET_TIM = 2,
        RESET_AABB = 4,
        RESET_ALL = 7
    };
    enum LastProcessingStep
    {
        INTEGRATE = 0,
        COLLIDE = 1
    };
    hkUint32 m_eLastProcessingStep;  // +0x8
    hkpWorld* m_pOwningWorld;        // +0xC
    hkUint8 m_bHasStepped;           // +0x10 (LastProcessingStep)
    char pad11[0x3];
    hkReal m_fElapsedSimulationTime;  // +0x14
    hkReal m_fSimulationTime;         // +0x18
    hkReal m_fStepDeltaTime;          // +0x1C
    hkReal m_fFrameMarkerTime;        // +0x20
    hkReal m_fFrameMarkerPsiSnap;     // +0x24
    hkUint32 m_uiSimulationType;      // +0x28
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpSimulation[(sizeof(hkpSimulation) == 0x2C) ? 1 : -1];
#endif
