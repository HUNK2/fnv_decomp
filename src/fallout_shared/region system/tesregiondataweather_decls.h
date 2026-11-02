// fallout_shared/region system/tesregiondataweather_decls.h: declares TESRegion, TESWeatherList, TESRegionDataWeather
#ifndef TESREGIONDATAWEATHER_DECLS_H
#define TESREGIONDATAWEATHER_DECLS_H

#include "TESForm.h"
class TESRegion : public TESForm
{
};
class TESWeatherList
{
  public:
    void* entries[2];
    static void LoadWeatherEntries(TESWeatherList*, TESFile*, TESForm*);
};
class TESRegionDataWeather
{
  public:
    unsigned char base[8];
    TESWeatherList weatherList;
    void LoadWeatherData(TESFile*, TESRegion*);
};
int Warning();
int Warning(const char*, ...);
unsigned int SetWarningState(bool);
#endif
