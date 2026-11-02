
// Provisional build file (plan B2): exact copies of the bstempeffectdebris recipe for other original addresses.
// Twin_<addr>/FUN_<addr> are placeholder names; the original identities of these functions are unknown.
//
// fallout_shared/tempeffects/bstempeffectdebris.cpp
//
// Out-of-line definitions for BSTempEffectDebris. The foreground-element
// flag is stored in the object itself, so the accessor is a plain field
// read and the setter a plain field write.
//

#include "bstempeffectdebris.h"

struct Twin_007e6580 : public BSTempEffectDebris
{
    void SetIsForegroundEffect(bool foregroundElement);
};
// @fnv 0x007e6580
void Twin_007e6580::SetIsForegroundEffect(bool foregroundElement)
{
    m_bShouldDelete = foregroundElement;
}
