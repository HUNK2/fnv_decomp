// Source layout: NiFixedString. PC corrections are in generate_headers.py.
#ifndef FNV_NIFIXEDSTRING_H
#define FNV_NIFIXEDSTRING_H
#include "layout_support.h"
#pragma pack(push, 4)
class NiFixedString
{
  public:
    char* m_kHandle;  // +0x0
    operator const char*() const;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiFixedString) == 0x4);
FNV_STATIC_ASSERT(offsetof(NiFixedString, m_kHandle) == 0x0);
#endif
