// fallout/ai/creature.h: declares ActorValueOwner, Actor, Creature
#ifndef FNV_LUNA_CREATURE_H
#define FNV_LUNA_CREATURE_H


class BGSLoadFormBuffer;
enum ANIM_GROUP_ENUM
{
    kAnimGroupRun = 3
};

class ActorValueOwner
{
  public:
    virtual int GetBaseActorValue(unsigned int actorValue);
    virtual float GetBaseActorValueFloat(unsigned int actorValue);
    virtual int GetActorValue(unsigned int actorValue);
    virtual float GetCurrentActorValue(unsigned int actorValue);
};

class Actor
{
  public:
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    unsigned char m_pad04[0x64];
    void* pAnimData;
    unsigned char m_pad6C[0x38];
    ActorValueOwner actorValues;
    unsigned char m_padA8[0x98];
    unsigned int m_uiActorFlags;
    unsigned char m_pad144[0x70];
};

class Creature : public Actor
{
  public:
    virtual void LoadGame(BGSLoadFormBuffer* buffer);
    virtual float CalculateRunSpeed();
    virtual float GetAnimationSpeedMultiplier(ANIM_GROUP_ENUM group);
};

#endif
