// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSSAVELOADHEADER_H
#define FNV_BGSSAVELOADHEADER_H

#include "layout_support.h"
class SaveLoadHeader;
#pragma pack(push, 4)
class SaveLoadHeader
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SaveLoadHeader) == 1);
#endif
