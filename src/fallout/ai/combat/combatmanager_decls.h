// fallout/ai/combat/combatmanager_decls.h: declares CombatThreatMap, SettingT_GameSettingCollection_
#ifndef FNV_COMBATMANAGER_DECLS_H
#define FNV_COMBATMANAGER_DECLS_H


#include "combatmanager_types_CombatManager.h"
#include "PlayerCharacter.h"
#include "AutoMemContext.h"

class BGSLoadGameBuffer;

class ActorCombatGroup
{
  public:
    bool ContainsActor(Actor* actor);
    unsigned int GetCount();
    CombatTargetTimestamp GetLastDetectedTimestamp(Actor* actor);
    Actor* GetIntAt(int index);
    void RemoveActorsNotInGroup(BGSLoadGameBuffer* buffer);
};

class CombatThreatMap
{
  public:
    void ProcessAllProjectiles(BGSLoadGameBuffer* buffer);
};

class SettingT_GameSettingCollection_
{
  public:
    SETTING_VALUE* Float();
};

extern PlayerCharacter* g_thePlayer;
extern SettingT_GameSettingCollection_ originalRuntimeFloatSetting413;

typedef ActorCombatGroup*(__thiscall* ActorGetCombatGroupProc)(Actor* actor);

#endif
