// fallout_shared/bgsquestobjective_decls.h: declares BGSQuestObjective
#ifndef BGSQUESTOBJECTIVE_DECLS_H
#define BGSQUESTOBJECTIVE_DECLS_H

class TESForm;
class TESQuest;
class RegionObjectEntry
{
  public:
    void InitItem(TESForm*);
};
class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
};
template <class T> class BSStringT
{
  public:
    char storage[8];
    BSStringT& operator=(const char*);
};
extern const char g_emptyTopicInfoPrompt[];
class BGSQuestObjective
{
  public:
    void* vtable;
    unsigned int iIndex;
    BSStringT<char> m_kDisplayText;
    TESQuest* m_pOwnerQuest;
    char targetList[8];
    unsigned char bInitialized;
    char pad[3];
    unsigned int state;
    BGSQuestObjective();
    void Initialize();
    void InitItem(TESQuest*);
    BSSimpleList<RegionObjectEntry*>* GetTargetList();
};
#endif
