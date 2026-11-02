// fallout/interface/menus/containermenu_packet.h: declares SaveLoadFile, BGSLoadGameBuffer, BGSAcousticSpace, TESEnchantableForm, BGSQuestObjective and more
#ifndef CONTAINERMENU_PACKET_H
#define CONTAINERMENU_PACKET_H

class SaveLoadFile
{
  public:
    void SetFilePosition(int);
    unsigned Read(void*, unsigned);
    unsigned GetFilePosition();
};
class BGSLoadGameBuffer
{
  public:
    char data[16];
    BGSLoadGameBuffer();
    ~BGSLoadGameBuffer();
    void ReadAndVerifySize(SaveLoadFile*);
    void ReadDataBlock(void*, unsigned);
    char* GetCombinedValue();
    char* LoadString(char*);
};
class TESSound;
class TESLandTexture;
class TESQuest;
class SpellItem;
enum MagicSystem__CastingType
{
    castingZero
};
class BGSAcousticSpace
{
  public:
    void SetNoonSound(TESSound*);
};
class TESEnchantableForm
{
  public:
    void SetCastingType(MagicSystem__CastingType);
};
class BGSQuestObjective
{
  public:
    void SetOwnerQuest(TESQuest*);
};
class TESRegionGrassObject
{
  public:
    void AssignLandTexture(TESLandTexture*);
};
class BGSDehydrationStage
{
  public:
    void FUN_0050f9a0(SpellItem*);
};
class TESFile
{
  public:
    bool NextChunk();
};
class TESConditionItem
{
  public:
    void SetObjectType(int);
};
class TESRecipe
{
  public:
    void SetSkillLevel(int);
    void SetSkill(int);
};
class InterfaceManager
{
  public:
    void FUN_00984f60(unsigned);
};
class SaveHeaderOps
{
  public:
    void QueueWeapon(const char*);
};
class TESIdleForm;
class TESResponse
{
  public:
    void SetSpeakerIdle(TESIdleForm*);
};
extern char* DAT_011a2224;
extern const char ENGLISH[];
extern "C" unsigned __cdecl strlen(const char*);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned);
int FUN_00408b20(const char*, const char*);
#endif
