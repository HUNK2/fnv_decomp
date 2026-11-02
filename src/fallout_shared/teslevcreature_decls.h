// fallout_shared/teslevcreature_decls.h: declares TESFileFormVersion, TESFile, ContainerItemExtra, TESForm, LeveledObject and more
#pragma once

#include <malloc.h>
#include <string.h>
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESFile : public TESFileFormVersion
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool NextChunk();
    bool IsEndianConversionRequired();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData(unsigned int*);
};
class ContainerItemExtra
{
  public:
    char data[12];
    ContainerItemExtra();
    bool Load(TESFile*);
};
class TESForm
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void LoadBounds(TESFile*);
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual bool SetEditorID(const char*);
    char formData[0x2c];
    void LoadRecordHeader(TESFile*);
    void SetInitializationState(bool);
};
class LeveledObject
{
  public:
    unsigned short level, pad;
    TESForm* form;
    unsigned short count, pad2;
    void SwapEndian();
};
struct LeveledEntry
{
    unsigned int a, b;
    ContainerItemExtra* extra;
};
class TESLeveledList
{
  public:
    char data[13];
    unsigned char flags;
    char pad[2];
    TESForm* global;
    char tail[8];
    LeveledObject* CreateLeveledObject(unsigned short, unsigned short, TESForm*, ContainerItemExtra*);
    void FUN_0042e680(unsigned char);
};
class TESModel
{
  public:
    char data[24];
    static void LoadModelData(TESModel*, TESFile*);
};
class TESModelTextureSwap : public TESModel
{
  public:
    bool ParseTextureSwapData(void*, unsigned int, unsigned int);
};
class TESLevCreature : public TESForm, public TESLeveledList, public TESModelTextureSwap
{
  public:
    bool Load(TESFile*);
};
extern LeveledEntry* DAT_011c8eec;
