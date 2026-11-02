#ifndef FNV_MODIFIERLIST_H
#define FNV_MODIFIERLIST_H

#include "statsmenu_layout_support.h"
class ActorValueModifierList : public BSSimpleList<Modifier*>
{
  public:
    bool m_bAllowZeroValueModifiers;  // +0x8
    unsigned char layoutPadding9[3];
    ModifierPointerList* m_ppModifiedActorValues;  // +0xC
};
FNV_STATIC_ASSERT(sizeof(ActorValueModifierList) == 0x10);
FNV_STATIC_ASSERT(offsetof(ActorValueModifierList, m_bAllowZeroValueModifiers) == 0x8);
FNV_STATIC_ASSERT(offsetof(ActorValueModifierList, m_ppModifiedActorValues) == 0xC);
#endif
