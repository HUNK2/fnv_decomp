// fallout_shared/magic/effectitem_decls.h: declares TESForm, InterfaceManager, TESFile, BGSImpactData__IMPACT_DATA_DATA, EffectSetting and more
#ifndef FNV_EFFECTITEM_DECLS_H
#define FNV_EFFECTITEM_DECLS_H


class TESForm
{
  public:
    bool GetInitialized() const;
};

class Tile;
class InterfaceManager
{
  public:
    Tile* FUN_00586150();
};

class PerkEntryConditionSet
{
  public:
    void InitItem(TESForm* form);
    void Load(class TESFile* file);
    bool Compare(PerkEntryConditionSet* other);
};

class TESFile
{
  public:
    unsigned int GetChunkID();
    bool GetChunkData(void* data, unsigned int size);
    bool IsEndianConversionRequired();
};

class BGSImpactData__IMPACT_DATA_DATA
{
  public:
    void Endian();
};

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
int __cdecl Warning(const char* format, ...);

class MagicCaster;
class MagicItem;
class EffectItem;

template <class T> class BSStringT
{
  public:
    T* data;
    unsigned int length;
    ~BSStringT();
};

class EffectSetting
{
  public:
    int GetEffectID();
    bool IsFlagSet(unsigned int flags);
    bool IsDetrimental();
    bool IsAssociatedActorValueUsed();
    bool HasAssociatedActorValue();
    int GetAssociatedActorValue();
    BSStringT<char> GetEffectName() const;
};

class MemoryManager
{
  public:
    static void Deallocate(void* pointer);
};

EffectSetting* __cdecl GetUsageMonitorEffectSetting();

#pragma pack(push, 4)
struct MagicEffectEntry
{
    int m_iMagnitude;
    int m_iArea;
    int m_iPayloadInteger;
    int m_eRange;
    int m_eAssociatedActorValue;
    void Endian();
};

class EffectItem
{
  public:
    MagicEffectEntry data;
    EffectSetting* m_pEffectSetting;
    float m_fCost;
    PerkEntryConditionSet Conditions;

    int GetEffectID();
    int GetAffectedActorValue();
    bool IsDetrimental();
    bool IsHostile();
    int GetMagnitude();
    int GetArea();
    int GetDuration();
    int GetRange();
    void* GetScript();
    EffectSetting* GetEffectSetting();
    PerkEntryConditionSet* GetConditions();
    BSStringT<char> GetEffectName();
    bool IsScriptBasedEffect();
    bool Compare(EffectItem* other);
    void InitItem(TESForm* form);
    bool Load(TESFile* file, const char* actorEffect);
    void DestroyContents();
    EffectItem* Delete(unsigned int flags);
};

#pragma pack(push, 4)
class ActiveEffect
{
  public:
    virtual void Destroy(bool);
    unsigned char storage[68];
    ActiveEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect);
    ~ActiveEffect();
};

class ScriptEffect : public ActiveEffect
{
  public:
    virtual void Destroy(bool);
    void* script;
    unsigned int unknown;
    ScriptEffect(MagicCaster* caster, MagicItem* item, EffectItem* effect);
};
#pragma pack(pop)

#pragma pack(push, 4)
class EffectItemListItems
{
  public:
    void* first;
    void* last;
    void AddTail(EffectItem*& item);
};

class EffectItemList
{
  public:
    void* vtable;
    EffectItemListItems Items;
    int hostileCount;
    EffectItem* GetScriptEffect();
    void AddItem(EffectItem* item);
};
#pragma pack(pop)
#pragma pack(pop)

#endif
