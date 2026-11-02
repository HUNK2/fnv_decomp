// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PACK_TARG_TYPE_H
#define FNV_PACK_TARG_TYPE_H

#include "layout_support.h"
enum PACK_TARG_TYPE
{
    PACK_TARG_TYPE_PTT_NONE = -1,
    PACK_TARG_TYPE_PTT_REFERENCE = 0,
    PACK_TARG_TYPE_PTT_OBJECT = 1,
    PACK_TARG_TYPE_PTT_TYPE = 2,
    PACK_TARG_TYPE_PTT_LINKEDREF = 3
};
#endif
