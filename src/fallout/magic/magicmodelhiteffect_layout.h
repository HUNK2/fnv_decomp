// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_MAGICMODELHITEFFECT_H
#define FNV_MAGICMODELHITEFFECT_H

#include "layout_support.h"
#include "NiObject.h"
#include "magichiteffect_classes.h"
#include "TESObjectREFR.h"
#include "layout_support.h"
class BGSLoadGameSubBuffer;
class BSTempEffect;
class MagicHitEffect;
class MagicModelHitEffect;
class NiAVObject;
// BSTempEffect and MagicHitEffect: magichiteffect_classes.h (shared by the magic hit-effect units).
#pragma pack(push, 4)
class BGSLoadGameSubBuffer
{
  public:
    char* pBuffer;  // +0x0, 4 bytes
    // BGSLoadGameSubBuffer
    // void __cdecl BGSLoadGameSubBuffer::*(char*)
    // void __cdecl BGSLoadGameSubBuffer::*()
    // void __cdecl BGSLoadGameSubBuffer::*(TESForm*)
    // void __cdecl BGSLoadGameSubBuffer::*(TESForm*)
    // void __cdecl BGSLoadGameSubBuffer::*(TESForm*)
    // void __cdecl BGSLoadGameSubBuffer::*(TESForm*)
    // void __cdecl BGSLoadGameSubBuffer::*(TESForm*)
    // void __cdecl BGSLoadGameSubBuffer::*(BGSSaveGameBuffer*)
    // void __cdecl BGSLoadGameSubBuffer::*(BGSLoadGameBuffer*)
    // char* __cdecl BGSLoadGameSubBuffer::*()
    // BGSLoadFormBuffer* __cdecl BGSLoadGameSubBuffer::*(TESForm*)
    // void __cdecl BGSLoadGameSubBuffer::*(BGSSaveFormBuffer*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSLoadGameSubBuffer) == 4);
FNV_STATIC_ASSERT(offsetof(BGSLoadGameSubBuffer, pBuffer) == 0);
#pragma pack(push, 4)
// MagicModelHitEffect: PC vftable 57 slots (same as MagicHitEffect); the overrides below are the slots whose PC
class MagicModelHitEffect : public MagicHitEffect
{
  public:
    virtual bool Update(float afTime);                                                              // v94
    virtual int GetType();                                                                          // v9C
    virtual bool IsSaveable();                                                                      // vA0
    virtual unsigned short GetSaveSize();                                                           // vA4
    virtual void SaveGame();                                                                        // vAC
    virtual void SaveGame(BGSSaveGameBuffer* apBuffer);                                             // vA8
    virtual bool LoadGame();                                                                        // vB4
    virtual void LoadGame(BGSLoadGameBuffer* apBuffer);                                             // vB0
    virtual void InitLoadGame(BGSLoadGameBuffer* apBuffer);                                         // vB8
    virtual void ApplyLoadBuffer(BGSLoadGameBuffer* apBuffer);                                      // vBC
    virtual bool Init();                                                                            // vC4
    virtual void AttachToTarget();                                                                  // vCC
    virtual unsigned short GetSaveSize(ActiveEffect* apEffect, TESObjectREFR* apTarget);            // vD0
    virtual void SaveGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);                         // vD4
    virtual void LoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);                         // vD8
    virtual void InitLoadGame(ActiveEffect* apEffect, TESObjectREFR* apTarget);                     // vDC
    virtual void FinishLoadGameTES(ActiveEffect* apEffect, TESObjectREFR* apTarget, void* apData);  // vE0
    bool m_bFirstPerson;                                                                            // +0x28, 1 bytes
    bool b3rdPerson;                                                                                // +0x29, 1 bytes
    unsigned char layoutPadding2A[2];
    const char* pFilename;                      // +0x2C, 4 bytes
    NiPointer<NiAVObject> spRetainedObject;     // +0x30, 4 bytes
    NiPointer<NiAVObject> m_spTargetObject;     // +0x34, 4 bytes
    BGSLoadGameSubBuffer m_kLoadGameSubBuffer;  // +0x38, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(MagicModelHitEffect) == 60);
FNV_STATIC_ASSERT(offsetof(MagicModelHitEffect, m_bFirstPerson) == 40);
FNV_STATIC_ASSERT(offsetof(MagicModelHitEffect, b3rdPerson) == 41);
FNV_STATIC_ASSERT(offsetof(MagicModelHitEffect, pFilename) == 44);
FNV_STATIC_ASSERT(offsetof(MagicModelHitEffect, spRetainedObject) == 48);
FNV_STATIC_ASSERT(offsetof(MagicModelHitEffect, m_spTargetObject) == 52);
FNV_STATIC_ASSERT(offsetof(MagicModelHitEffect, m_kLoadGameSubBuffer) == 56);
#endif
