// fallout_shared/tesobjectarma_load.h: declares TESFile, TESFileFormVersion, ArmorData, BIPED_MODEL_OLD, RegionDataEntry and more
#ifndef TESOBJECTARMA_LOAD_H
#define TESOBJECTARMA_LOAD_H

#include <malloc.h>
class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData(unsigned int*);
    bool IsEndianConversionRequired();
    bool NextChunk();
};
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
enum ENUM_FORM_ID
{
    FORM_ARMO = 24
};
struct ArmorData
{
    unsigned char bytes[12];
    void FUN_00535aa0();
};
struct BIPED_MODEL_OLD
{
    unsigned short m_uiBipedModelFlags;
    unsigned char m_ucBipedModelData;
    void FUN_00512810();
};
class RegionDataEntry
{
  public:
    void Endian();
};
class TESFullName;
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName*, TESFile*);
};
class TESModel
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void SetModelFilePath(const char*);
    unsigned char storage[20];
    static void LoadModelData(TESModel*, TESFile*);
    static void LoadTextureSwapData(TESModel*, TESFile*);
};
class TESModelTextureSwap : public TESModel
{
  public:
    unsigned char textureSwapList[8];
    static void ReadTextureSwapChunk(TESModelTextureSwap*, TESFile*);
};
class TESTexture1024
{
  public:
    unsigned char storage[12];
    void SetTexture(const char*);
};
class BGSMessageIcon
{
  public:
    unsigned char storage[16];
    void SetMessageIconTextureName(const char*);
};
class BGSEquipType
{
  public:
    unsigned char storage[8];
};
// The equipment setter is folded with this canonically bound scalar setter.
class TESResponse
{
  public:
    void SetEmotionValue(unsigned int);
};
#endif
