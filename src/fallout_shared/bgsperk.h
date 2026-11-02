// Fallout shared perk entry declarations, reconstructed to the PC release layout.
#ifndef FNV_FALL_SHARED_BGSPERK_H
#define FNV_FALL_SHARED_BGSPERK_H


#include <stddef.h>

#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]

FNV_STATIC_ASSERT(sizeof(void*) == 4);
FNV_STATIC_ASSERT(sizeof(long) == 4);

class PerkEntryPointData
{
  public:
    unsigned char m_ucEntryPoint;
    unsigned char m_ucFunction;
    unsigned char m_ucConditionCount;
};

template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    ~BSSimpleList();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    void RemoveAll();
    void RemoveHead();
    void Remove(const T& item);
    void AddTail(const T& item);
    void AddHead(T& item);
    void SetItem(const T& item);
};

class TESFullName;
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* name, class TESFile* file);
};

class Actor;
class BGSPerkEntry;
class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool IsEndianConversionRequired();
    bool GetChunkData(void* data, unsigned int size);
    bool GetChunkData(unsigned int* data);
    bool GetChunkData();
    bool NextChunk();
};
class TESForm
{
  public:
    TESForm();
    virtual ~TESForm();
    virtual void InitItem();
    virtual bool Load(TESFile* file);
    void LoadRecordHeader(TESFile* file);
    void SetInitializationState(bool initialized);
    unsigned char layoutData[0x14];
};

class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};

class PatrolActorPackageData
{
  public:
    bool IsPatrolling();
};

class PerkEntryFunctionType
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual int GetFunctionType();
};

class RegionDataEntry
{
  public:
    void Endian();
};

class PerkEntryConditionSet
{
  public:
    void* pFirstCondition;
    void* pNextCondition;
    PerkEntryConditionSet();
    ~PerkEntryConditionSet();
    void InitItem(TESForm* form);
    void Load(TESFile* file);
};

class TESFullName
{
  public:
    unsigned char data[0xC];
    TESFullName();
};

class TESDescription
{
  public:
    unsigned char data[0x8];
    TESDescription();
};

class TESIcon
{
  public:
    unsigned char data[0xC];
    TESIcon();
};

class PerkData
{
  public:
    bool m_bTrait;
    unsigned char cLevel;
    unsigned char m_ucRankCount;
    bool bPlayable;
    bool bHidden;
    unsigned char padding[3];
};

class BGSPerk : public TESForm
{
  public:
    TESFullName tESFullNameComponent;
    TESDescription tESDescriptionComponent;
    TESIcon tESIconComponent;
    PerkData Data;
    PerkEntryConditionSet m_kConditions;
    BSSimpleList<BGSPerkEntry*> m_kEntryList;
    BGSPerk();
    virtual void InitItem();
    virtual bool Load(TESFile* file);
    void ApplyPerkEntries(Actor* actor, unsigned char rank, bool alternate);
};

class BGSEntryPointFunctionData
{
  public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void InitItem(TESForm* form);
};

class BGSPerkEntry
{
  public:
    unsigned char m_ucRank;               // +0x4
    unsigned char m_ucRegionPriority;  // +0x5
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual bool CheckConditionFilters(unsigned int count, TESForm** subjects);
    virtual unsigned char GetFunction();
    virtual void* GetFunctionData();
    virtual void InitItem(TESForm* form);
    virtual void Save();
    virtual bool Load(TESFile* file);
    virtual void Copy(BGSPerkEntry* entry);
    virtual bool Compare(BGSPerkEntry* entry);
    virtual void ClearData();
    virtual void ApplyEntryPointEffect(Actor* actor, bool apply);
    virtual ~BGSPerkEntry();
};

class BGSEntryPointPerkEntry : public BGSPerkEntry
{
  public:
    PerkEntryPointData Data;  // +0x8
    unsigned char layoutPaddingB[1];
    BGSEntryPointFunctionData* m_pFunctionData;  // +0xC
    PerkEntryConditionSet* m_pConditions;                 // +0x10
    virtual bool CheckConditionFilters(unsigned int count, TESForm** subjects);
    virtual unsigned char GetFunction();
    virtual void* GetFunctionData();
    virtual void ClearData();
    virtual void InitItem(TESForm* form);
    virtual BGSPerkEntry* Duplicate();
    virtual bool Compare(BGSPerkEntry* entry);
    virtual void Save();
    virtual bool Load(TESFile* file);
    virtual unsigned char GetEntryPoint();
    virtual void ApplyEntryPointEffect(Actor* actor, bool apply);
    virtual void RemoveEntryPointEffect(Actor* actor, bool remove);
    BGSEntryPointPerkEntry& operator=(const BGSEntryPointPerkEntry& entry);
};

class BGSQuestPerkEntry : public BGSPerkEntry
{
  public:
    unsigned char Data[8];
    virtual bool Load(TESFile* file);
};

#ifndef __GNUC__
FNV_STATIC_ASSERT(sizeof(BGSPerkEntry) == 0x8);
FNV_STATIC_ASSERT(sizeof(BGSEntryPointPerkEntry) == 0x14);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointPerkEntry, Data) == 0x8);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointPerkEntry, m_pFunctionData) == 0xC);
FNV_STATIC_ASSERT(offsetof(BGSEntryPointPerkEntry, m_pConditions) == 0x10);
#endif

#endif
