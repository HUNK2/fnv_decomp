// fallout_shared/tesweatherlist.h: declares TESWeatherList
#ifndef FNV_TESWEATHERLIST_H
#define FNV_TESWEATHERLIST_H


class WeatherEntry;

template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    T& GetItem();
    BSSimpleList<T>* GetNext();
    void RemoveAll();
};

class TESWeatherList : public BSSimpleList<WeatherEntry*>
{
  public:
    void ClearWeatherSounds();
};

void __cdecl operator delete(void* pointer);

#endif
