
// src/fallout/magic/vampirismeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/magic/vampirismeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

class Actor
{
  public:
    virtual ~Actor();
};

class Character : public Actor
{
  public:
    virtual ~Character();
};

class ActiveEffect
{
  public:
    void InitLoadGame(Actor* apActor);
};

class VampirismEffect : public ActiveEffect
{
  public:
    void VampirismEffect_InitLoadGame(Actor* apActor);
};

void ActiveEffect::InitLoadGame(Actor* apActor)
{
    (void)apActor;
}

// Calls ActiveEffect::InitLoadGame with apActor, then dynamic_casts apActor to Character and discards the result.
// @fnv 0x0082d110
void VampirismEffect::VampirismEffect_InitLoadGame(Actor* apActor)
{
    ActiveEffect::InitLoadGame(apActor);
    Character* pcharacter = dynamic_cast<Character*>(apActor);
}

class SpawnedObject
{
  public:
    SpawnedObject(int aA, int aB, int aC);
    int m_unk00;
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    int m_unk30;
    int m_unk34;
    int m_unk38;
    int m_unk3C;
    int m_unk40;
    int m_unk44;
};

class EffectOwner
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17(SpawnedObject* apObj);
    int m_unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;

    SpawnedObject* CreateSpawnedObject();
};

// Allocates a SpawnedObject from m_unk28, m_unk08 and m_unk0C, passes it to v17, and returns it.
// @fnv 0x0082cfb0
SpawnedObject* EffectOwner::CreateSpawnedObject()
{
    SpawnedObject* spawned = new SpawnedObject(m_unk28, m_unk08, m_unk0C);
    v17(spawned);
    return spawned;
}
