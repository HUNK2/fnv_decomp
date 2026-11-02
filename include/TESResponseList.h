#ifndef FNV_RESPONSELISTWRAPPER_H
#define FNV_RESPONSELISTWRAPPER_H

#include "layout_support.h"
#pragma pack(push, 4)
class TESResponseList
{
  public:
    TESResponse* pHead;  // +0x0
    void ClearResponses();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESResponseList) == 0x4);
FNV_STATIC_ASSERT(offsetof(TESResponseList, pHead) == 0x0);
#endif
