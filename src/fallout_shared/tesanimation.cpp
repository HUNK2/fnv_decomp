// fallout_shared/tesanimation.cpp: TESAnimation, ActorValueOwner (10 functions)

#include "tesanimation_decls.h"
#include "BaseFormComponent.h"

// @fnv 0x0047f9f0
TESAnimation::~TESAnimation()
{
    ClearComponent();
}

// Removes and deletes every filename string from the animation list until it is empty.
// @fnv 0x0047fa50
void TESAnimation::ClearComponent()
{
    while (!m_kKFFileList.IsEmpty())
    {
        const char* filename = m_kKFFileList.GetItem();
        m_kKFFileList.RemoveHead();
        delete const_cast<char*>(filename);
    }
}

// @fnv 0x0047fd90
bool TESAnimation::HasSpecialAnimations()
{
    if (m_kKFFileList.IsEmpty())
    {
        return false;
    }
    return true;
}

// @fnv 0x005f78e0
ActorValueOwner::ActorValueOwner()
{}

// @fnv 0x0047faa0
void TESAnimation::LoadComponent(TESForm* form, TESFile* file)
{
    if (!file || !form)
        return;
    unsigned int chunk = file->GetChunkID();
    switch (chunk)
    {
    case 0x5a46464b: {
        char* pCurrent;
        char* pData = new char[file->GetChunkSize()];
        pCurrent = pData;
        file->GetChunkData(pData, 0);
        while (*pCurrent)
        {
            AddPathToList(pCurrent);
            pCurrent = pCurrent + BSStringLength(pCurrent) + 1;
        }
        delete[] pData;
    }
    break;
    }
}

struct BFC_s
{
    BFC_s();
    virtual void f();
};
struct BSSpinLock_s
{
    BSSpinLock_s();
};
struct FUN_0047f9c0 : public BFC_s
{
    BSSpinLock_s lock;
    virtual void g();
    FUN_0047f9c0();
};
// Empty constructor for the BFC_s-derived class.
// @fnv 0x0047f9c0
FUN_0047f9c0::FUN_0047f9c0()
{}

int __cdecl _stricmp(const char*, const char*);
struct ListNodeStub
{
    bool _ref_008256d0();
    const char** _ref_006815c0();
    ListNodeStub* _ref_00726070();
};
struct FUN_0047fcb0_cls
{
    int pad;
    ListNodeStub list;
    bool ContainsName(const char* apName);
};
// @fnv 0x0047fcb0
bool FUN_0047fcb0_cls::ContainsName(const char* apName)
{
    if (list._ref_008256d0())
        return false;
    ListNodeStub* pNode = &list;
    while (pNode)
    {
        const char* pcName = *pNode->_ref_006815c0();
        if (!_stricmp(pcName, apName))
            return true;
        pNode = pNode->_ref_00726070();
    }
    return false;
}

void* __cdecl operator new(unsigned int);
unsigned int __cdecl BSStringLength(const char*);
struct TaskQueueInterface
{
    static void __cdecl CopyStringToBuffer(char*, unsigned int, const char*);
};
struct SoundListView
{
    void AddTail(char* const&);
};
struct FUN_0047fcb0_stub
{
    bool ContainsName(const char*);
};
struct FUN_0047fd20_cls
{
    int pad;
    SoundListView list;
    void AddPathToList(const char* apPath);
};
// If the path is not already present, allocates a copy of it, copies the string into it and appends it to the list.
// @fnv 0x0047fd20
void FUN_0047fd20_cls::AddPathToList(const char* apPath)
{
    char* pcPathCopy;
    if (!((FUN_0047fcb0_stub*)this)->ContainsName(apPath))
    {
        unsigned int uiSize = BSStringLength(apPath) + 1;
        pcPathCopy = new char[uiSize];
        TaskQueueInterface::CopyStringToBuffer(pcPathCopy, uiSize, apPath);
        list.AddTail(pcPathCopy);
    }
}

struct PackedRecordData;
struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct BGSVoiceType;
struct BipedAnim;
struct CHUNK;
struct ContainerChanges;
struct ContainerItemExtra;
struct InventoryItemEntry;
struct FormRecordHeader;
struct TESFileGroup;
struct HWND__;
struct InventoryChanges;
struct MagicItemForm;
struct NiAVObject;
struct NiColor;
struct NiPoint3;
struct PackageList;
struct SpellItem;
struct TESAIForm;
struct TESActorBase;
struct TESActorBaseData;
struct TESAmmo;
struct TESBoundObject;
struct TESContainer;
struct TESFaction;
struct TESForm;
struct TESHealthForm;
struct TESLevItem;
struct TESLevSpell;
struct TESObject;
struct TESObjectARMO;
struct TESObjectCLOT;
struct TESFormList;
struct TESObjectREFR;
struct TESObjectWEAP;
struct TESPackage;
struct TESWaterForm;
struct blob8
{
    char b[8];
};
struct blob12
{
    char b[12];
};
struct FUN_0047fb50_shell : public TESAnimation
{
    void TESAnimation_CopyComponent(BaseFormComponent*);
};

// Casts apCopyFC to TESAnimation, frees this component, then copies each filename from the source's file list via AddPathToList.
// @fnv 0x0047fb50
void FUN_0047fb50_shell::TESAnimation_CopyComponent(BaseFormComponent* apCopyFC)
{
    TESAnimation* pcopy = dynamic_cast<TESAnimation*>(apCopyFC);
    if (pcopy == 0)
        return;
    ((BaseFormComponent*)this)->Free();
    BSSimpleList<const char*>* pkfFileList = &pcopy->m_kKFFileList;
    while (pkfFileList != 0)
    {
        const char* pkfFilename = pkfFileList->GetItem();
        if (pkfFilename != 0)
            AddPathToList(pkfFilename);
        pkfFileList = pkfFileList->GetNext();
    }
}

int __cdecl CompareNamesNoCase(const char* a, const char* b);

struct ListStepStub
{
    ListStepStub* FUN_00726070();
};

struct ListStepStub2
{
    ListStepStub2* FUN_00726070();
};

struct FUN_0047fbd0_cls : public TESAnimation
{
    bool IsAnimationDifferent(BaseFormComponent* component);
};

// @fnv 0x0047fbd0
bool FUN_0047fbd0_cls::IsAnimationDifferent(BaseFormComponent* component)
{
    const char* x;
    const char* y;
    TESAnimation* other_2 = dynamic_cast<TESAnimation*>(component);
    if (other_2 == 0)
    {
        return true;
    }
    BSSimpleList<const char*>* a = &this->m_kKFFileList;
    BSSimpleList<const char*>* b8 = &other_2->m_kKFFileList;
    while (a != 0 && b8 != 0)
    {
        x = a->GetItem();
        y = b8->GetItem();
        if ((x == 0 && y != 0) || (x != 0 && y == 0))
        {
            return true;
        }
        else
        {
            if (x != 0 && y != 0)
            {
                if (CompareNamesNoCase(x, y) != 0)
                {
                    return true;
                }
            }
        }
        a = (BSSimpleList<const char*>*)((ListStepStub*)a)->FUN_00726070();
        b8 = (BSSimpleList<const char*>*)((ListStepStub2*)b8)->FUN_00726070();
    }
    if (a != 0 || b8 != 0)
    {
        return true;
    }
    return false;
}
