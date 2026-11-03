
#include "effectitem_decls.h"

// @fnv 0x00403ea0
int EffectItem::GetAffectedActorValue()
{
    return EffectItem_IsActorValueUsed() ? m_eAssociatedActorValue : -1;
}
