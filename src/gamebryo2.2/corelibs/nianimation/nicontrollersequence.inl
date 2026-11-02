
#include "nicontrollersequence_decls.h"
// @fnv 0x00a5d3f0
NiControllerSequence__IDTag& NiControllerSequence__IDTag::operator=(const NiControllerSequence__IDTag& rhs)
{
    ShaderBufferRecord* result;
    NiTStringPointerMap<ShaderBufferRecord*>* map = *(NiTStringPointerMap<ShaderBufferRecord*>**)&rhs;
    if (map->GetAt((const char*)this, result))
        return *(NiControllerSequence__IDTag*)result;
    return Clone(rhs);
}
