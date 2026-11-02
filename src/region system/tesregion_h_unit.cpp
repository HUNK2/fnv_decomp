
// Header unit for region system/tesregion.h.
// No @fnv markers here; the covered getter is defined and marked in the
// header. This translation unit only forces the covered COMDAT to be
// emitted so its bytes can be compared against the original.
#include "tesregion.h"

void TESRegion_UnitReference()
{
    TESRegion* pRegion = 0;
    NiColor* pColor = pRegion->GetDiffuseColor();
    (void)pColor;
}
