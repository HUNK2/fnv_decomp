
#include "bhklimitedhingeconstraint_decls.h"
// @fnv 0x00caade0
void bhkLimitedHingeConstraint::PopulateOutput(bhkLimitedHingeOutput* output)
{
    FUN_00c9fb70(output);
    output->first.FUN_004b4db0(GetFirst());
    output->second.FUN_004b4db0(GetSecond());
}
