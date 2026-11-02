
// src/fallout/ai/combat/combatdialoguemanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/ai/combat/combatdialoguemanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct CombatController
{
};
struct AlchemyItem
{
    int FUN_004030b0(int, int, bool);
};
struct TESAmmoInitCalls
{
    unsigned int GetFieldBC(unsigned int);
};
struct CombatDialogueHandler
{
    bool FUN_00983970(CombatController*, int, int, bool);
    bool TryStartDialogue(unsigned int, CombatController*);
};
// Calls FUN_004030b0 with the dialogue type, topic and interrupt flag, passes the result through GetFieldBC, then calls TryStartDialogue with the combat controller.
// @fnv 0x00983970
bool CombatDialogueHandler::FUN_00983970(CombatController* apCombatController, int aiDialogueType, int aiDialogueTopic,
                                         bool abInterrupt)
{
    return TryStartDialogue(
        ((TESAmmoInitCalls*)apCombatController)
            ->GetFieldBC(
                ((AlchemyItem*)apCombatController)->FUN_004030b0(aiDialogueType, aiDialogueTopic, abInterrupt)),
        apCombatController);
}
