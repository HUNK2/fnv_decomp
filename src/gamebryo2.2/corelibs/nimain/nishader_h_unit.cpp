
#include "nishader.h"

// 1 Nov: the included file leaves optimization off (#pragma optimize("", off) never closed); functions added below build
// with the unit's own flags (/O2). Nothing of this unit's own follows the include, so no accepted function is affected.
#pragma optimize("", on)
