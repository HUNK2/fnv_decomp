// fallout/ai/combat/combattimer.cpp: free functions (4 functions)

#include "combattimer_decls.h"
// Reads a 4-byte timestamp from the load buffer and, if it is within the relative range, offsets it by the current game time.
// @fnv 0x009a5ff0
void CombatTargetTimestamp::LoadGame(BGSLoadGameBuffer* pLoadBuffer)
{
    pLoadBuffer->ReadTypedData(&fTimeStamp, 4);
    if (fTimeStamp < DAT_0108e360 && fTimeStamp > -DAT_0108e360)
        fTimeStamp = Actor::GetActorScale() + fTimeStamp;
}
// @fnv 0x009a5f20
void TimeoutTimer::LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(&m_fStartTime, 4);
    buffer->ReadTypedData(&m_fTimeout, 4);
    if (m_fStartTime < DAT_0108e360 && m_fStartTime > -DAT_0108e360)
        m_fStartTime = m_fStartTime + DAT_011f1bf0;
}

struct BGSSaveFormBuffer
{
    void __thiscall SaveData(void* data, int size, int unk);
};

struct FUN_009a5eb0_shell
{
    float m_fStartTime;
    float field_4;
    void __thiscall FUN_009a5eb0(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x009a5eb0
void FUN_009a5eb0_shell::FUN_009a5eb0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    float foffsetStartTime = this->m_fStartTime;
    if (this->m_fStartTime < DAT_0108e360 && -DAT_0108e360 < this->m_fStartTime)
        foffsetStartTime -= DAT_011f1bf0;
    apSaveGameBuffer->SaveData(&foffsetStartTime, 4, 0);
    apSaveGameBuffer->SaveData(&this->field_4, 4, 0);
}

namespace fnv_009a5f90 {
struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};

struct FUN_009a5f90_shell
{
    float fTimeStamp;
    void SaveTimeStamp(BGSSaveFormBuffer* apSaveGameBuffer);
};

// @fnv 0x009a5f90
void FUN_009a5f90_shell::SaveTimeStamp(BGSSaveFormBuffer* apSaveGameBuffer)
{
    float fSavedTimeStamp = fTimeStamp;
    if (fTimeStamp < DAT_0108e360 && fTimeStamp > -DAT_0108e360)
    {
        fSavedTimeStamp -= Actor::GetActorScale();
    }
    apSaveGameBuffer->SaveData(&fSavedTimeStamp, 4, 0);
}
}  // namespace fnv_009a5f90
