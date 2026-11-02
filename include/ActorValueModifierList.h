#ifndef FNV_MODIFIERLIST_H
#define FNV_MODIFIERLIST_H
#include "layout_support.h"
#pragma pack(push, 4)
class ActorValueModifierList : public BSSimpleList<Modifier*>
{
  public:
    bool m_bAllowZeroValueModifiers;  // +0x8
    unsigned char layoutPadding9;
    unsigned short layoutPaddingA;
    ModifierPointerList* m_ppModifiedActorValues;  // +0xC
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ActorValueModifierList) == 0x10);
FNV_STATIC_ASSERT(offsetof(ActorValueModifierList, m_bAllowZeroValueModifiers) == 0x8);
FNV_STATIC_ASSERT(offsetof(ActorValueModifierList, m_ppModifiedActorValues) == 0xC);
#endif
