#ifndef FNV_COMBATTIMER_H
#define FNV_COMBATTIMER_H
#include "lowprocess_support.h"
#pragma pack(push, 4)
class TimeoutTimer
{
  public:
    void FUN_00910b10();
    bool CheckTimer();
    void LoadGame(BGSLoadFormBuffer*);
    float m_fStartTime;  // +0x0
    float m_fTimeout;  // +0x4
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TimeoutTimer) == 0x8);
FNV_STATIC_ASSERT(offsetof(TimeoutTimer, m_fStartTime) == 0x0);
FNV_STATIC_ASSERT(offsetof(TimeoutTimer, m_fTimeout) == 0x4);
#endif
