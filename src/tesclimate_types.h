// tesclimate_types.h: declares TESFile, FileEntryList, TESModel, TESTexture, TESWeather and more
#ifndef FNV_TESCLIMATE_TYPES_H
#define FNV_TESCLIMATE_TYPES_H

#include "tesclimate_form.h"
class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool NextChunk();
};
extern int __cdecl Warning();
extern unsigned int __cdecl SetWarningState(bool);
class BSFileEntry;
class TESWeather;
class TESModelTextureSwap;
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;
};
class TESModel : public BaseFormComponent
{
  public:
    TESModel();
    virtual ~TESModel();
    virtual const char* GetModelFilePath() const;
    virtual void SetModelFilePath(const char* path);
    virtual TESModelTextureSwap* GetAsModelMaterialSwap() const;
    BSStringT<char> m_kModelFilePath;
    FileEntryList m_pTextureSwapData;
    unsigned char cFlags;
    unsigned char layoutPadding15[3];
    static void LoadModelData(TESModel* model, TESFile* file);
};
class TESTexture : public BaseFormComponent
{
  public:
    TESTexture();
    virtual ~TESTexture();
    BSStringT<char> FullNameComponent;
    void AssignTextureName(const char* path);
    static void ReadTextureData(TESTexture* texture, TESFile* file);
};
class TESWeather : public TESForm
{
};
class WeatherEntry
{
  public:
    TESWeather* m_pWeatherObject;
    unsigned int m_uiWeatherChance;
    TESGlobal* m_pWeatherChanceGlobal;
    WeatherEntry();
};
class TESWeatherList : public BSSimpleList<WeatherEntry*>
{
  public:
    TESWeatherList();
    ~TESWeatherList();
    static void LoadWeatherEntries(TESWeatherList* weatherList, TESFile* file, TESForm* form);
};
class TESClimate : public TESForm
{
  public:
    TESClimate();
    virtual ~TESClimate();
    void ResetFormData();
    void MakeDefault();
    bool Load(TESFile* file);
    void SetMoonPhaseDays(unsigned int days);
    void SetUsesMasser(bool value);
    void SetUsesSecunda(bool value);
    TESModel m_kStarsModel;
    TESWeatherList weatherList;
    TESTexture m_kSunTextures[2];
    unsigned char m_ucTimeSettings[6];
    unsigned char layoutPadding56[2];
};
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(sizeof(TESTexture) == 12);
FNV_STATIC_ASSERT(sizeof(TESWeatherList) == 8);
FNV_STATIC_ASSERT(sizeof(WeatherEntry) == 12);
FNV_STATIC_ASSERT(sizeof(TESClimate) == 88);
FNV_STATIC_ASSERT(offsetof(TESClimate, m_kStarsModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESClimate, weatherList) == 48);
FNV_STATIC_ASSERT(offsetof(TESClimate, m_kSunTextures) == 56);
FNV_STATIC_ASSERT(offsetof(TESClimate, m_ucTimeSettings) == 80);
extern int __cdecl Warning(const char* format, ...);
#endif
