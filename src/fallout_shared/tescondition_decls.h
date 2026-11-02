// fallout_shared/tescondition_decls.h: declares PackageList, TESFile, TESObjectREFR, MemoryManager, TESConditionItem and more
#ifndef TESCONDITION_DECLS_H
#define TESCONDITION_DECLS_H


class TESPackage;
class PackageList
{
  public:
    void AddPackage(TESPackage*);
};
class TESForm;
class TESFile
{
  public:
    unsigned int GetChunkID();
};
class TESObjectREFR
{
  public:
    TESObjectREFR* FUN_005693d0();
};
class TESTopic;
template <class T> class BSSimpleList;
class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*>* GetLinkToList();
};
class MemoryManager
{
  public:
    static void* Allocate(unsigned int size);
};

class TESConditionItem
{
  public:
    char opaque[0x1C];
    TESConditionItem();
    ~TESConditionItem();
    bool IsFlagSet();
    void Load(TESFile* file);
    void InitItem(TESForm* form);
    bool Compare(TESConditionItem* other);
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target, bool& result);
};

class DecalDataDeleter
{
  public:
    void* DeleteThis(int doFree);
};

template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    BSSimpleList(T& item);
    ~BSSimpleList();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    void AddHead(T& item);
    void RemoveHead();
};

class PerkEntryConditionSet
{
  public:
    BSSimpleList<TESConditionItem*> m_kConditionItems;
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target);
    bool ContainsTrait(TESObjectREFR* subject, TESObjectREFR* target, bool& result, bool arg3);
    void InitItem(TESForm* form);
    bool Compare(PerkEntryConditionSet* other);
    void InitializeConditionItems();
    void Load(TESFile* file);
};
#endif
