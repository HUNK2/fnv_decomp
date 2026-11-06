
#include "bhklimitedhingeconstraint_decls.h"
// @fnv 0x00caade0
void bhkLimitedHingeConstraint::PopulateOutput(bhkLimitedHingeOutput* output)
{
    reinterpret_cast<void (__thiscall*)(bhkLimitedHingeConstraint*, bhkLimitedHingeOutput*)>(bhkConvexShape_CopyCinfo)(this, output);
    output->first.FUN_004b4db0(GetFirst());
    output->second.FUN_004b4db0(GetSecond());
}
