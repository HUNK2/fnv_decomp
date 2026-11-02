#ifndef FNV_TESOBJECTCONT_MATCH_DECLS_H
#define FNV_TESOBJECTCONT_MATCH_DECLS_H

class TESObjectCONT_TESScriptableInitCall
{
  public:
    void InitItem(TESForm*);
};

class TESSound : public TESForm
{
};

class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};

class ContainerItemExtra
{
  public:
    unsigned int opaque0;
    unsigned int opaque4;
    unsigned int opaque8;
    ContainerItemExtra();
    bool Load(TESFile*);
};

struct ContainerItemExtraOwner
{
    unsigned int opaque0;
    unsigned int opaque4;
    ContainerItemExtra* item;
};

class CombatController;
class CombatProcedure
{
  public:
    void Initialize(CombatController*);
};

class EffectSetting
{
  public:
    void SetAreaSound(TESSound*);
};

class BGSVoiceType;
class BGSTalkingActivator
{
  public:
    void SetVoiceType(BGSVoiceType*);
};

struct CNTOChunkData
{
    unsigned int formID;
    unsigned int count;
    void FUN_00462230();
};

extern "C" ContainerItemExtraOwner* DAT_011c9348;

int __cdecl Warning(const char*, ...);

#endif
