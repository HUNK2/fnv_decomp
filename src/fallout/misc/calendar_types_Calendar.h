// fallout/misc/calendar_types_Calendar.h: declares Calendar

#include "calendar_types_CALENDAR_MONTH.h"
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_CALENDAR_H
#define FNV_CALENDAR_H
#include "layout_support.h"
#include "TESGlobal.h"
class Calendar;
#pragma pack(push, 4)
class Calendar
{
  public:
    TESGlobal* m_pYearGlobal;            // +0x0, 4 bytes
    TESGlobal* m_pMonthGlobal;           // +0x4, 4 bytes
    TESGlobal* m_pDayGlobal;             // +0x8, 4 bytes
    TESGlobal* m_pHourGlobal;            // +0xC, 4 bytes
    TESGlobal* m_pGameDaysPassedGlobal;  // +0x10, 4 bytes
    TESGlobal* pHourGlobal;              // +0x14, 4 bytes
    unsigned int m_uiDaysPassed;         // +0x18, 4 bytes
    bool bUnknown1C;
    char GetGameHour();
    float GetGameTimeScale();
    CALENDAR_MONTH GetCurrentMonth();
    float GetGameTime();
    DAYS_OF_THE_WEEK GetGameDayOfWeek();
    int GetDayOfMonth();
    void ResetCachedValues();
    void Update(float afDeltaTime);
    unsigned int GetGameDaysPassed();
    unsigned int GetGameHoursPassed();
    // void __cdecl Calendar::*()
    // void __cdecl Calendar::*()
    // void __cdecl Calendar::*()
    // void __cdecl Calendar::*(float)
    // void __cdecl Calendar::*()
    // unsigned int __cdecl Calendar::*()
    // SEASON __cdecl Calendar::*()
    // CALENDAR_MONTH __cdecl Calendar::*()
    // char __cdecl Calendar::*()
    // float __cdecl Calendar::*()
    // unsigned int __cdecl Calendar::*()
    // unsigned int __cdecl Calendar::*()
    // float __cdecl Calendar::*()
    // unsigned int __cdecl Calendar::*()
    // DAYS_OF_THE_WEEK __cdecl Calendar::*()
    // const char* __cdecl Calendar::*()
    // float __cdecl Calendar::*()
    // BSStringT<char> __cdecl Calendar::*()
    // float __cdecl Calendar::*()
    // int __cdecl Calendar::*(int, int, int)
    // void* __cdecl Calendar::*(unsigned int)
};
#pragma pack(pop)
// FNV_STATIC_ASSERT(sizeof(Calendar) == 28);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pYearGlobal) == 0);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pMonthGlobal) == 4);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pDayGlobal) == 8);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pHourGlobal) == 12);
FNV_STATIC_ASSERT(offsetof(Calendar, m_pGameDaysPassedGlobal) == 16);
FNV_STATIC_ASSERT(offsetof(Calendar, pHourGlobal) == 20);
FNV_STATIC_ASSERT(offsetof(Calendar, m_uiDaysPassed) == 24);
#endif
