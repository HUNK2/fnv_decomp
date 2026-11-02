
// src/fallout_shared/bgsmovablestatic_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/fallout_shared/bgsmovablestatic.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

#include "bgsmovablestatic_decls.h"

class TESFile;

class TESSound;

class TESForm
{
  public:
    virtual void unk004();
    virtual void unk008();
    virtual void unk00C();
    virtual void unk010();
    virtual void unk014();
    virtual void unk018();
    virtual void unk01C();
    virtual void unk020();
    virtual void unk024();
    virtual void unk028();
    virtual void unk02C();
    virtual void unk030();
    virtual void unk034();
    virtual void unk038();
    virtual void unk03C();
    virtual void unk040();
    virtual void unk044();
    virtual void unk048();
    virtual void unk04C();
    virtual void unk050();
    virtual void unk054();
    virtual void unk058();
    virtual void unk05C();
    virtual void unk060();
    virtual void unk064();
    virtual void unk068();
    virtual void unk06C();
    virtual void unk070();
    virtual void unk074();
    virtual void unk078();
    virtual void unk07C();
    virtual void unk080();
    virtual void unk084();
    virtual void unk088();
    virtual void unk08C();
    virtual void unk090();
    virtual void unk094();
    virtual void unk098();
    virtual void unk09C();
    virtual void unk0A0();
    virtual void unk0A4();
    virtual void unk0A8();
    virtual void unk0AC();
    virtual void unk0B0();
    virtual void unk0B4();
    virtual void unk0B8();
    virtual void unk0BC();
    virtual void unk0C0();
    virtual void unk0C4();
    virtual void unk0C8();
    virtual void unk0CC();
    virtual void unk0D0();
    virtual void unk0D4();
    virtual void unk0D8();
    virtual void unk0DC();
    virtual void unk0E0();
    virtual void unk0E4();
    virtual void unk0E8();
    virtual void unk0EC();
    virtual void unk0F0();
    virtual void unk0F4();
    virtual void unk0F8();
    virtual void unk0FC();
    virtual void unk100();
    virtual void unk104();
    virtual void unk108();
    virtual void unk10C();
    virtual void unk110();
    virtual void unk114();
    virtual void unk118();
    virtual void unk11C();
    virtual void unk120();
    virtual void unk124();
    virtual void unk128();
    virtual void unk12C();
    virtual void unk130();
    virtual const char* GetName();
    bool GetInitialized();
    TESFile* GetFile(int a);
    unsigned int GetFormID();
    void SetInitializationState(bool b);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
};

class TESSound : public TESForm
{
};

class TESBoundObject : public TESForm
{
  public:
    int unk24;
    int unk28;
    int unk2c;
};

class TESModelTextureSwap
{
  public:
    virtual ~TESModelTextureSwap();
    void InitItem(TESForm* form);
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
};

class BGSDestructibleObjectForm
{
  public:
    virtual ~BGSDestructibleObjectForm();
    void InitItem(TESForm* form);
    int unk08;
};

class unkOwnerBase
{
  public:
    virtual ~unkOwnerBase();
    int unk04;
    int unk08;
};

class TESObjectSTAT : public TESBoundObject, public TESModelTextureSwap
{
  public:
    void FUN_004fbb70();
    union
    {
        unsigned int soundFormID;
        TESSound* m_pSoundEffect;
    } sound;
};

class BGSMovableStaticOwner : public unkOwnerBase, public BGSDestructibleObjectForm, public TESObjectSTAT
{
};

void FixupFormID(unsigned int* formID, TESFile* file);
TESForm* LookupForm(unsigned int formID);
void FNV_Warning(const char* fmt, ...);

// @fnv 0x004fbb70
void TESObjectSTAT::FUN_004fbb70()
{
    if (GetInitialized())
        return;

    ((BGSMovableStaticOwner*)((char*)this - 0x14))
        ->BGSDestructibleObjectForm::InitItem(
            ((BGSMovableStaticOwner*)((char*)this - 0x14))
                ? (TESForm*)((char*)((BGSMovableStaticOwner*)((char*)this - 0x14)) + 0x14)
                : (TESForm*)0);
    ((BGSMovableStaticOwner*)((char*)this - 0x14))
        ->TESModelTextureSwap::InitItem(((BGSMovableStaticOwner*)((char*)this - 0x14))
                                            ? (TESForm*)((char*)((BGSMovableStaticOwner*)((char*)this - 0x14)) + 0x14)
                                            : (TESForm*)0);

    unsigned int soundID = sound.soundFormID;
    if (soundID)
    {
        FixupFormID(&soundID, GetFile(-1));
        sound.m_pSoundEffect = dynamic_cast<TESSound*>(LookupForm(soundID));
        if (!sound.m_pSoundEffect)
            FNV_Warning("MASTERFILE: Could not find looping sound (%08X) for movable static '%s' (%08X).", soundID,
                        ((TESForm*)((char*)((BGSMovableStaticOwner*)((char*)this - 0x14)) + 0x14))->GetName(),
                        GetFormID());
    }

    SetInitializationState(true);
}
