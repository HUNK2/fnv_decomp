// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIGEOMETRYDATA_DATAFLAGS_H
#define FNV_NIGEOMETRYDATA_DATAFLAGS_H

#include "layout_support.h"
enum NiGeometryData__DataFlags
{
    NiGeometryData__DataFlags_NBT_METHOD_NONE = 0,
    NiGeometryData__DataFlags_NBT_METHOD_NDL = 4096,
    NiGeometryData__DataFlags_NBT_METHOD_DEPRECATED = 8192,
    NiGeometryData__DataFlags_NBT_METHOD_ATI = 12288,
    NiGeometryData__DataFlags_NBT_METHOD_MASK = 61440,
    NiGeometryData__DataFlags_TEXTURE_SET_MASK = 1
};
#endif
