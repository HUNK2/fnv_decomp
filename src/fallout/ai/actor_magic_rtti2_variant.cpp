
// src/fallout/ai/actor_magic_rtti2_variant.cpp - RTTI variant unit created 2026-11-01 by rtti_variants.py for paused functions whose original code needs
// polymorphic classes (TESActorBase). The skeleton of src/fallout/ai/actor_magic.cpp with those classes made polymorphic; move the functions to
// their real unit once its classes are.

#include "actor_magic_decls_rtti2_actor_magic.h"
#include "actor_magic_actor.h"
#include "BaseProcess.h"
// HighProcess call targets used by actor magic (canonical HighProcess
// header has no method declarations yet; only calls are emitted here,
// so no layout is required).
class HighProcess
{
  public:
    int GetProcessLevel();
    void SetMaxAlpha(float fAlpha);
    void ProcessActorWithFlag(Actor*, bool);
};
class NiNode;
struct BSShaderRenderUtility
{
    static void SetAlphaOnNode(NiNode* pNode, float fAlpha);
};
// Node getter behind 0x00950bb0. It reads a node pointer at +0x694, which
// only exists on PlayerCharacter-sized objects, so it is declared here on
// a minimal PlayerCharacter until its canonical home is confirmed.
class PlayerCharacter
{
  public:
    NiNode* GetNode(bool bFirstPerson);
};

extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting704;

class TESCreature
{
  public:
    unsigned char FUN_005f9ad0();
    signed char GetCreatureType();
};

struct ActorCreatureStandIn
{
    float FUN_0088b850();
// @fnv 0x008d4750
    float FUN_008d4750()
    {
        float j = 0.0f;
        TESCreature* p = dynamic_cast< ::TESCreature*>(((::Actor*)this)->GetActorBase());
        if (!p)
        {
            j = FUN_0088b850();
        }
        else
        {
            j = (float)p->FUN_005f9ad0();
            if (p->GetCreatureType() == 7)
            {
                j *= originalRuntimeFloatSetting704.Float()->f;
            }
        }
        return j;
    }
};

float (ActorCreatureStandIn::*fnv_008d4750_entry)() = &ActorCreatureStandIn::FUN_008d4750;
