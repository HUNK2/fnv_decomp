
#include "effectitem_decls.h"

// @fnv 0x00403ea0
int EffectItem::GetAffectedActorValue()
{
    return FUN_00403ee0() ? m_eAssociatedActorValue : -1;
}
