// fallout_shared/tesconditionfunctions_conditionfn_class_faction.h: declares Node, TESAttributes, TESClass, TESReactionForm, Reaction and more
#ifndef CONDITIONFN_CLASS_FACTION_DECLARATIONS_H
#define CONDITIONFN_CLASS_FACTION_DECLARATIONS_H
// Separate, uncompiled candidates. Do not replace any accepted source body.
// Concrete component/member layouts use JIP PC facts; genuine method
// declarations and binding facts are independently established by JohnnyGuitar.
#include "tesconditionfunctions_conditionfn_dep_TESForm.h"
#include "tesconditionfunctions_conditionfn_dep_TESFullName.h"
#include "tesconditionfunctions_conditionfn_dep_TESDescription.h"
#include "tesconditionfunctions_conditionfn_dep_TESTexture.h"

template <class Item> class tList
{
  public:
    struct Node
    {
        Item* data;
        Node* next;
    };

  private:
    Node m_listHead;
};
FNV_STATIC_ASSERT(sizeof(tList<TESForm>) == 8);

class TESAttributes : public BaseFormComponent
{
  public:
    unsigned char attributes[7];
    unsigned char padB;
};
FNV_STATIC_ASSERT(sizeof(TESAttributes) == 12);

class TESClass : public TESForm
{
  public:
    TESFullName fullName;
    TESDescription description;
    TESTexture texture;
    TESAttributes attributes;
    unsigned int tagSkills[4];
    unsigned int classFlags;
    unsigned int services;
    unsigned char teaches;
    unsigned char trainingLevel;
    unsigned char pad5E[2];
    bool IsTagSkill(ActorValue::Index aeSkill) const;
};
FNV_STATIC_ASSERT(sizeof(TESClass) == 96);
FNV_STATIC_ASSERT(offsetof(TESClass, tagSkills) == 68);

class TESReactionForm : public BaseFormComponent
{
  public:
    struct Reaction
    {
        TESFaction* faction;
        int modifier;
        unsigned int reaction;
    };
    tList<Reaction> reactions;
    unsigned char unkC;
    unsigned char padD[3];
};
FNV_STATIC_ASSERT(sizeof(TESReactionForm) == 16);

class TESReputation;
class TESFaction : public TESForm
{
  public:
    struct Rank;
    TESFullName fullName;
    TESReactionForm reaction;
    unsigned int factionFlags;
    TESReputation* reputation;
    tList<Rank> ranks;
    unsigned int numMajorCrimes;
    unsigned int numMinorCrimes;
    bool GetPCAnEnemy() const;
};
FNV_STATIC_ASSERT(sizeof(TESFaction) == 76);
FNV_STATIC_ASSERT(offsetof(TESFaction, factionFlags) == 52);

#endif
