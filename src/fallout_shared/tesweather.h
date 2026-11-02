// Unit-local PC header for fallout_shared/tesweather.cpp.
// TESTexture1024, TESModel, FileEntryList, ImageSpaceModifierParameterData,
// constructor/method declarations added so this TU can bind the real
// call targets. PC TESWeather ends at +0x36C: the constructor builds no
#ifndef FNV_TESWEATHER_UNIT_H
#define FNV_TESWEATHER_UNIT_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESTexture.h"

class BSFileEntry;
class TESImageSpaceModifier;
class TESModel;
class TESWeather;
class TESWeather__WeatherSound;
class TESWeather__WeatherSoundList;

extern "C" void* memset(void* dst, int val, unsigned int size);
void __cdecl operator delete(void* ptr);

#pragma pack(push, 4)
class TESImageSpaceModifiableCountForm_6_ : public BaseFormComponent
{
  public:
    TESImageSpaceModifier* m_pImageSpaceModifier[6];  // +0x4, 24 bytes
    TESImageSpaceModifiableCountForm_6_();
    void InitItem(TESForm* form);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESImageSpaceModifiableCountForm_6_) == 28);
FNV_STATIC_ASSERT(offsetof(TESImageSpaceModifiableCountForm_6_, m_pImageSpaceModifier) == 4);

#pragma pack(push, 4)
class TESTexture1024 : public TESTexture
{
  public:
    TESTexture1024();
    ~TESTexture1024();
    void SetTexture(const char* texturePath);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESTexture1024) == 12);

#pragma pack(push, 4)
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);

#pragma pack(push, 4)
class TESModel : public BaseFormComponent
{
  public:
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    TESModel();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);

#pragma pack(push, 4)
class ImageSpaceModifierParameterData
{
  public:
    float m_afFirstParameterSet[15];        // +0x0, 60 bytes
    float m_afSecondParameterSet[3];        // +0x3C, 12 bytes
    float m_afThirdParameterSet[3];         // +0x48, 12 bytes
    float m_afFourthParameterSet[4];        // +0x54, 16 bytes
    float m_afColorAndAlphaParameters[12];  // +0x64, 48 bytes
    unsigned int ShaderConstantData;        // +0x94, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceModifierParameterData) == 152);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierParameterData, m_afFirstParameterSet) == 0);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierParameterData, m_afSecondParameterSet) == 60);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierParameterData, m_afThirdParameterSet) == 72);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierParameterData, m_afFourthParameterSet) == 84);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierParameterData, m_afColorAndAlphaParameters) == 100);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierParameterData, ShaderConstantData) == 148);

// Scaffold exposing TESForm::IsFormInitialized, which the task closure
// TESForm.h does not declare (cf. TESFormInitFlag in bgsimpactdata.h).
struct TESFormInitFlag : public TESForm
{
    bool IsFormInitialized() const;
};

#pragma pack(push, 4)
class TESWeather__WeatherSoundList : public BSSimpleList<TESWeather__WeatherSound*>
{
  public:
    TESWeather__WeatherSoundList();
    void ClearWeatherSounds();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESWeather__WeatherSoundList) == 8);

#pragma pack(push, 4)
class TESWeather : public TESForm, public TESImageSpaceModifiableCountForm_6_
{
  public:
    TESTexture1024 m_kCloudLayerTextures[4];   // +0x34, 48 bytes
    unsigned char m_aucCloudLayerSpeeds[4];    // +0x64, 4 bytes
    unsigned int m_auiCloudLayerColors[4][6];  // +0x68, 96 bytes
    TESModel m_kWeatherModel;                  // +0xC8, 24 bytes
    unsigned char m_aucWeatherFlags[15];       // +0xE0, 15 bytes
    unsigned char layoutPaddingEF[1];
    float m_afFogDistances[6];                                            // +0xF0, 24 bytes
    unsigned int m_auiWeatherColors[10][6];                               // +0x108, 240 bytes
    TESWeather__WeatherSoundList soundList;                               // +0x1F8, 8 bytes
    float m_afHdrParameters[14];                                          // +0x200, 56 bytes
    ImageSpaceModifierParameterData m_akImageSpaceModifierParameters[2];  // +0x238, 304 bytes
    int m_iCloudLayerCount;                                               // +0x368, 4 bytes
    TESWeather();
    void ResetFormData();
    void InitItem();
    void ClearData();
    void MakeDefault();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESWeather) == 876);
FNV_STATIC_ASSERT(offsetof(TESWeather, m_kCloudLayerTextures) == 52);
FNV_STATIC_ASSERT(offsetof(TESWeather, m_aucCloudLayerSpeeds) == 100);
FNV_STATIC_ASSERT(offsetof(TESWeather, m_auiCloudLayerColors) == 104);
FNV_STATIC_ASSERT(offsetof(TESWeather, m_kWeatherModel) == 200);
FNV_STATIC_ASSERT(offsetof(TESWeather, m_aucWeatherFlags) == 224);
FNV_STATIC_ASSERT(offsetof(TESWeather, m_afFogDistances) == 240);
FNV_STATIC_ASSERT(offsetof(TESWeather, m_auiWeatherColors) == 264);
FNV_STATIC_ASSERT(offsetof(TESWeather, soundList) == 504);
FNV_STATIC_ASSERT(offsetof(TESWeather, m_afHdrParameters) == 512);
FNV_STATIC_ASSERT(offsetof(TESWeather, m_akImageSpaceModifierParameters) == 568);
FNV_STATIC_ASSERT(offsetof(TESWeather, m_iCloudLayerCount) == 872);
#endif
