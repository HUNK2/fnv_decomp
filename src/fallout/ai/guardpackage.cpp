// fallout/ai/guardpackage.cpp: GuardActorPackageData, std (6 functions)

#include "guardpackage_decls.h"
// @fnv 0x00408840
double std::abs(float value)
{
    return FUN_00408860(value);
}
// Reads eState, a second dword, iWarningCount and a trailing value from the load buffer.
// @fnv 0x009f28b0
void GuardActorPackageData::LoadGame(BGSLoadFormBuffer* buffer)
{
    buffer->ReadTypedData(&eState, 4);
    buffer->ReadTypedData(&m_fWarningTimer, 4);
    buffer->ReadTypedData(&iWarningCount, 4);
    buffer->ReadFormIdentifier(&pWarningTarget);
}
// Resolves the stored form reference to an Actor and, if found, calls the reference helper with true.
// @fnv 0x009f2900
void GuardActorPackageData::InitLoadGame(BGSLoadFormBuffer* buffer)
{
    pWarningTarget =
        pWarningTarget ? dynamic_cast<Actor*>(TESForm::GetFormByID((unsigned int)pWarningTarget)) : 0;
    if (pWarningTarget)
        ((TESObjectREFRHelper*)pWarningTarget)->SetTargetingState(true);
}

struct FUN_009f2800Stub
{
    void FUN_009f2830();
    void* DestroyIfFlagged(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_009f2830, frees this when bit 0 of flags is set, and returns this.
// @fnv 0x009f2800
void* FUN_009f2800Stub::DestroyIfFlagged(unsigned int flags)
{
    FUN_009f2830();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
    void SerializeFormData(void*, int);
};
struct FUN_009f2850_holder
{
    int unk00;
    int unk04;
    void* unk08;
    int unk0C;
    int unk10;
    void SaveToBuffer(BGSSaveFormBuffer*);
};
// @fnv 0x009f2850
void FUN_009f2850_holder::SaveToBuffer(BGSSaveFormBuffer* apSaveGameBuffer)
{
    apSaveGameBuffer->SaveData(&unk04, 4, 0);
    apSaveGameBuffer->SaveData(&unk10, 4, 0);
    apSaveGameBuffer->SaveData(&unk0C, 4, 0);
    apSaveGameBuffer->SerializeFormData(unk08, 0);
}

extern int DAT_010933c8;

struct FUN_0067d970_Class
{
    void FUN_0067d970();
};

// @fnv 0x009f2830
void FUN_009f2800Stub::FUN_009f2830()
{
    *reinterpret_cast<int*>(this) = reinterpret_cast<int>(&DAT_010933c8);
    reinterpret_cast<FUN_0067d970_Class*>(this)->FUN_0067d970();
}
