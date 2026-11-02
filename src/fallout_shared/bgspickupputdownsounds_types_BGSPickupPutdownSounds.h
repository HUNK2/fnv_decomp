// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSPICKUPPUTDOWNSOUNDS_H
#define FNV_BGSPICKUPPUTDOWNSOUNDS_H

#include "layout_support.h"
#include "BaseFormComponent.h"
class BGSPickupPutdownSounds;
#pragma pack(push, 4)
class BGSPickupPutdownSounds : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    TESSound* m_pPickupSound;   // +0x4, 4 bytes
    TESSound* m_pPutdownSound;  // +0x8, 4 bytes
    void InitItem(TESForm* owner);
    // BGSPickupPutdownSounds
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*()
    // void __cdecl BGSPickupPutdownSounds::*(TESFile*)
    // void __cdecl BGSPickupPutdownSounds::*(BaseFormComponent*)
    // bool __cdecl BGSPickupPutdownSounds::*(BaseFormComponent*)
    // void __cdecl BGSPickupPutdownSounds::*(TESForm*)
    // GetPickupSound
    // GetPutdownSound
    // void __cdecl BGSPickupPutdownSounds::*(TESSound*)
    // void __cdecl BGSPickupPutdownSounds::*(TESSound*)
    // BGSPickupPutdownSounds& __cdecl BGSPickupPutdownSounds::*(const BGSPickupPutdownSounds&)
    // void* __cdecl BGSPickupPutdownSounds::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSPickupPutdownSounds) == 12);
FNV_STATIC_ASSERT(offsetof(BGSPickupPutdownSounds, m_pPickupSound) == 4);
FNV_STATIC_ASSERT(offsetof(BGSPickupPutdownSounds, m_pPutdownSound) == 8);
#endif
