// fallout_shared/tesweatherlist_decls.h: declares TESForm, TESGlobal, WeatherEntry, TESWeatherList, ContainerItemExtraFileData
#ifndef FNV_TESWEATHERLIST_DECLS_H
#define FNV_TESWEATHERLIST_DECLS_H


#include "layout_support.h"

class TESFile;
class TESForm
{
  public:
    virtual void vfn_0();
    unsigned int GetFormID();
    static TESForm* GetFormByID(unsigned int);
    static void RemapFormIDForFile(unsigned int&, TESFile*);
};
class TESWeather;
class TESGlobal : public TESForm
{
};

class WeatherEntry
{
  public:
    TESWeather* m_weather;
    unsigned int m_uiFilterValue;
    TESGlobal* m_otherWeather;
    WeatherEntry();
};

template <> class BSSimpleList<WeatherEntry*>
{
  public:
    WeatherEntry* m_item;
    BSSimpleList<WeatherEntry*>* m_pkNext;
    WeatherEntry*& GetItem();
    BSSimpleList<WeatherEntry*>* GetNext();
    void RemoveAll();
    void AddHead(WeatherEntry* const& item);
    void Sort(int(__cdecl* compare)(WeatherEntry*, WeatherEntry*));
};

class TESWeatherList : public BSSimpleList<WeatherEntry*>
{
  public:
    void ClearWeatherSounds();
    static void LoadWeatherEntries(TESWeatherList* list, TESFile* file, TESForm* form);
};

class FUN_00582570
{
  public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    FUN_00582570();
};

class ContainerItemExtraFileData
{
  public:
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    void Endian();
};

int __cdecl CompareSecondElement(WeatherEntry* left, WeatherEntry* right);
int __cdecl Warning(const char* format, ...);
extern "C" void* __cdecl __RTDynamicCast(void* object, long vfDelta, void* sourceType, void* targetType,
                                         int isReference);
extern "C" const char DAT_010318b4[];
extern "C" const char DAT_01031858[];
extern "C" const char DAT_0118629c[];

void* __cdecl operator new(unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete(void* pointer);
void __cdecl operator delete[](void* pointer);
extern "C" const char DAT_01183028[];
extern "C" const char DAT_01183ad4[];

#endif
