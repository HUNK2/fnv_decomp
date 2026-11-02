// include/BSSaveDataSystemUtility__SaveDataEntry.h: declares BSSaveDataSystemUtility__SaveDataEntry
#ifndef FNV_BSSAVEDATASYSTEMUTILITY__SAVEDATAENTRY_H
#define FNV_BSSAVEDATASYSTEMUTILITY__SAVEDATAENTRY_H

#include "layout_support.h"
#pragma pack(push, 4)
class BSSaveDataSystemUtility__SaveDataEntry
{
  public:
    char m_kName[32];  // +0x0
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSSaveDataSystemUtility__SaveDataEntry) == 0x20);
FNV_STATIC_ASSERT(offsetof(BSSaveDataSystemUtility__SaveDataEntry, m_kName) == 0x0);
#endif
