// Source layout: NiFixedString. PC corrections are in generate_headers.py.
#ifndef FNV_NITRANSFORMDATA_FNV_NIFIXEDSTRING_H
#define FNV_NITRANSFORMDATA_FNV_NIFIXEDSTRING_H
#include "nitransformdata_layout_support.h"
class NiFixedString
{
  public:
    char* m_kHandle;  // +0x0
};
FNV_STATIC_ASSERT(sizeof(NiFixedString) == 0x4);
FNV_STATIC_ASSERT(offsetof(NiFixedString, m_kHandle) == 0x0);
#endif
