// fallout_shared/bgsplaceablewater_decls.h: declares TESWaterForm, BGSImpactData, TESFileFormVersion, TESFileGetChunkData
#ifndef FNV_BGSPLACEABLEWATER_DECLS_H
#define FNV_BGSPLACEABLEWATER_DECLS_H


#include "TESForm.h"

class TESWaterForm : public TESForm
{
    char _pdbpad_18[20];
    bool m_bNeedsUpdate;
    char _pdbpad_2d[3];
    char m_pRenderedTexture[4];
    char m_kTextureScrollLayer0[16];
    char m_kTextureScrollLayer1[16];
    char m_kTextureScrollLayer2[16];
    char m_kNoiseMapTexture[12];
    unsigned char m_ucOpacity;
    unsigned char cFlags;
    char _pdbpad_72[2];
    char m_kMaterialId[8];
    void* m_pWaterSound;
    void* m_pWaterForm;
    char Data[196];
    char m_apWaterForms[12];
    int m_iCurrentTextureSelection1;
    int m_iCurrentTextureSelection2;
    unsigned int m_uiNoiseFrequencyX;
    unsigned int m_uiNoiseFrequencyY;
    int m_iNoiseOctaveCount;
    float m_fNoiseAmplitude;
    float m_fNoiseLacunarity;
    float fSideOffset;
    float m_fDistanceScale;
    void* m_pWaterSpell;
    char m_kNoiseTextureData[4];
    void* m_pPlaceableAutoWater;
    void* m_pPlaceableWater;
    int m_iRadiationMagnitude;
    int m_iHealthMagnitude;
    bool m_bResetNoiseTextures;
    char _pdbpad_191[3];
};

class BGSImpactData
{
  public:
    void ReadTypedData(TESFile*, void*, unsigned short);
    char _pdbpad_1[47];
    char Data_db_pad2f_pad2f_pad2f[24];
    void* m_pDecalTextureSet;
    void* m_pPrimaryImpactSound;
    void* m_pSecondaryImpactSound;
    char ImpactDecalInfo[36];
};

class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};

class TESFileGetChunkData : public TESFile
{
  public:
    bool GetChunkData();
};

extern TESWaterForm* DAT_011ca53c;
TESForm* GetFormByID(unsigned int formID);

#endif
