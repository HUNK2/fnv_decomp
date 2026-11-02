// fallout_shared/bgsexplosion_decls.h: declares TESFormInitFlag, TESObjectLIGH, CombatProcedure, BGSImpactData, EndianConvertibleData and more
#ifndef FNV_BGSEXPLOSION_DECLS_H
#define FNV_BGSEXPLOSION_DECLS_H

#include "TESForm.h"

struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
    static TESForm* GetFormByID(unsigned int formID);
};

class TESObjectLIGH : public TESForm
{
};

class TESFileChunkData16
{
  public:
    bool GetChunkData(unsigned short* data);
};

class CombatController;
class CombatProcedure
{
  public:
    void Initialize(CombatController* controller);
};

class BGSImpactData
{
  public:
    void ReadTypedData(TESFile* file, void* data, unsigned short size);
    char _pdbpad_1[47];
    char Data_pad2f_pad2f_pad2f[24];
    void* m_pDecalTextureSet;
    void* m_pPrimaryImpactSound;
    void* m_pSecondaryImpactSound;
    char ImpactDecalInfo[36];
};

class EndianConvertibleData
{
  public:
    void Endian();
};
class TESSound : public TESForm
{
};
class BGSImpactDataSet : public TESForm
{
};

class EffectSetting
{
  public:
    unsigned char bgsexplosion_padding[0x80];
    TESSound* bgsexplosion_castSound;
    TESSound* bgsexplosion_boltSound;
    TESSound* GetCastSound();
    void SetCastSound(TESSound* sound);
    TESSound* GetBoltSound();
    void SetBoltSound(TESSound* sound);
};

class MagicItem;

class MagicCaster
{
  public:
    MagicItem* GetSelectedMagicItem();
};

class PlayerMover
{
  public:
    unsigned int GetActorStateFlags();
};

int Warning(const char* format, ...);
#endif
