// fallout/ai/spectatorpackage.cpp: SpectatorPackage (1 function)
#include "spectatorpackage_decls.h"

// @fnv 0x009f9c80
int SpectatorPackage::IsComplete(const SpectatorPackage& other)
{
    if (&other != this)
    {
        FUN_009f9c20(this);
        if (FUN_009f9bb0(this, &other) < 0)
            return 0x8007000e;
    }
    return 0;
}
