// Source layout: CombatProcedure. PC corrections are in generate_headers.py.
#ifndef FNV_COMBATPROCEDURE_H
#define FNV_COMBATPROCEDURE_H

#include "layout_support.h"
#pragma pack(push, 4)
class CombatProcedure
{
  public:
    void** m_ppVirtualMethodTable;                                   // +0x0
    CombatController* m_pCombatController;             // +0x4
    CombatProcedure__COMBAT_PROCEDURE_STATUS eStatus;  // +0x8
    const char* m_pcProcedureName;                     // +0xC
    void Initialize(CombatController*);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(CombatProcedure) == 0x10);
FNV_STATIC_ASSERT(offsetof(CombatProcedure, m_ppVirtualMethodTable) == 0x0);
FNV_STATIC_ASSERT(offsetof(CombatProcedure, m_pCombatController) == 0x4);
FNV_STATIC_ASSERT(offsetof(CombatProcedure, eStatus) == 0x8);
FNV_STATIC_ASSERT(offsetof(CombatProcedure, m_pcProcedureName) == 0xC);
#endif
