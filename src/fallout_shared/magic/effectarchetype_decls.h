// fallout_shared/magic/effectarchetype_decls.h: declares EffectSetting, AnimIdle, EffectArchetypeEntry

class MagicCaster;
class MagicItem;
class EffectItem;
class TESBoundObject;
class EffectSetting
{
  public:
    int GetArchetype();
};
class AnimIdle
{
  public:
    int GetSection();
};
class ActiveEffect
{
  public:
    void InitFromSource(TESBoundObject*);
};
typedef ActiveEffect*(__cdecl* EffectFactory)(MagicCaster*, MagicItem*, EffectItem*);
struct EffectArchetypeEntry
{
    EffectFactory factory;
    unsigned int reserved[3];
};
extern EffectArchetypeEntry DAT_01183324[];
class MagicEffectSystem
{
  public:
    static ActiveEffect* Activate(MagicCaster*, MagicItem*, EffectItem*, TESBoundObject*);
};
