// Source layout: _FILETIME. PC corrections are in generate_headers.py.
#ifndef FNV_UNIT_TESFORM__FILETIME_H
#define FNV_UNIT_TESFORM__FILETIME_H
#include "tesform_layout_support.h"
class _FILETIME
{
  public:
    unsigned long dwHighDateTime;  // +0x0
    unsigned long dwLowDateTime;   // +0x4
};
FNV_STATIC_ASSERT(sizeof(_FILETIME) == 0x8);
FNV_STATIC_ASSERT(offsetof(_FILETIME, dwHighDateTime) == 0x0);
FNV_STATIC_ASSERT(offsetof(_FILETIME, dwLowDateTime) == 0x4);
#endif
