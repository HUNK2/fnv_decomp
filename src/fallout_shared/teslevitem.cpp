// fallout_shared/teslevitem.cpp: TESLevItem, LevItemCopyEntry, LevItemComparison (10 functions)

#include "teslevitem_decls.h"
// @fnv 0x0050b8d0
int TESLevItem::GetMaxLevelDifference()
{
    return g_011c8f00.Int()->i;
}

// @fnv 0x0050b560
bool TESLevItem::Load(TESFile* file)
{
    unsigned char ucFormType = file->GetTESForm();
    if (ucFormType != 0x34)
        return false;
    LoadRecordHeader(file);
    do
    {
        switch ((int)file->GetChunkID())
        {
        case 0x44494445: {
            char* pEditorId = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(pEditorId, 512);
            SetEditorID_AtRuntime(pEditorId);
            break;
        }
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4f4c564c:
        case 0x44454f43:
            switch ((int)file->GetChunkID())
            {
            case 0x4f4c564c: {
                LeveledObject entry;
                memset(&entry, 0, 12);
                file->GetChunkData(&entry, 12);
                if (file->IsEndianConversionRequired())
                    entry.SwapEndian();
                DAT_011c8f1c = list.CreateLeveledObject(entry.level, entry.count, entry.form, 0);
                break;
            }
            case 0x44454f43:
                if (DAT_011c8f1c)
                {
                    ContainerItemExtra* extra = new ContainerItemExtra;
                    extra->Load(file);
                    *(ContainerItemExtra**)((char*)DAT_011c8f1c + 8) = extra;
                    DAT_011c8f1c = 0;
                }
                break;
            }
            break;
        case 0x444c564c: {
            unsigned char chance = 0;
            file->GetChunkData(&chance, 0);
            list.FUN_0042e680(chance);
            break;
        }
        case 0x464c564c:
            file->GetChunkData(&list.flags, 0);
            break;
        case 0x474c564c: {
            unsigned int global = 0;
            file->GetChunkData(&global);
            list.global = global;
            break;
        }
        }
    } while (file->NextChunk());
    SetInitializationState(false);
    return true;
}

// @fnv 0x0050b890
void TESLevItem::InitItem()
{
    if (GetInitialized())
        return;
    list.InitItem(this);
    SetInitializationState(true);
}

struct B1_4fe : public TESForm
{
    B1_4fe();
    ~B1_4fe();
    char pad[0x18];
};
struct FUN_00487650
{
    FUN_00487650();
    ~FUN_00487650();
    virtual void vf();
    int v;
};
struct FUN_0050b400 : public B1_4fe, public FUN_00487650
{
    FUN_0050b400();
    ~FUN_0050b400();
};
// Initializes the form by setting its form type to 0x34 and clearing its data.
// @fnv 0x0050b400
FUN_0050b400::FUN_0050b400()
{
    SetFormType((ENUM_FORM_ID)0x34);
    ClearData();
}

struct FUN_004855a0_shell
{
    void TESForm_StartForm();
};
struct FUN_00488400_shell
{
    void SaveLeveledList();
};
struct FUN_00485680_shell
{
    void TESForm_CloseForm();
};

void FUN_004855a0_shell::TESForm_StartForm()
{}
void FUN_00488400_shell::SaveLeveledList()
{}
void FUN_00485680_shell::TESForm_CloseForm()
{}

struct FUN_0050b530_shell : public B1_4fe, public FUN_00487650
{
    void FUN_0050b530();
};

// Calls TESForm_StartForm, TESForm::ClearData, SaveLeveledList on the member at offset 0x30, then TESForm_CloseForm.
// @fnv 0x0050b530
void FUN_0050b530_shell::FUN_0050b530()
{
    ((FUN_004855a0_shell*)this)->TESForm_StartForm();
    TESForm::ClearData();
    ((FUN_00488400_shell*)((char*)this + 0x30))->SaveLeveledList();
    ((FUN_00485680_shell*)this)->TESForm_CloseForm();
}

struct BGSSaveFormBuffer;
struct FUN_00484d60_holder
{
    char pad[0x30];
    void SaveIfChanged(BGSSaveFormBuffer*);
};
struct FUN_00488c50_holder
{
    char dummy;
    void SaveLeveledListEntries(BGSSaveFormBuffer*);
};
struct FUN_0050adb0_shell : FUN_00484d60_holder, FUN_00488c50_holder
{
    void FUN_0050adb0(BGSSaveFormBuffer*);
};
// @fnv 0x0050adb0
void FUN_0050adb0_shell::FUN_0050adb0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    FUN_00484d60_holder::SaveIfChanged(apSaveGameBuffer);
    FUN_00488c50_holder::SaveLeveledListEntries(apSaveGameBuffer);
}

struct S_0050b490
{
    void FUN_0050b4c0();
    void* DestroyIfFlagged(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_0050b4c0, deallocates this when flags has bit 1 set, and returns this.
// @fnv 0x0050b490
void* S_0050b490::DestroyIfFlagged(unsigned int flags)
{
    FUN_0050b4c0();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_0050b4c0 : public B1_4fe, public FUN_00487650
{
    ~FUN_0050b4c0();
};
// Empty destructor for a class deriving from B1_4fe and FUN_00487650.
// @fnv 0x0050b4c0
FUN_0050b4c0::~FUN_0050b4c0()
{}

struct LevItemCopyEntry : public ::TESLevItem
{
    void TESForm_CopyAllComponents(::TESForm* source);
    void TESLevItem_CopyFrom(::TESForm* source);
};

// Casts the source TESForm to a TESLevItem and, if valid, calls TESForm_CopyAllComponents to copy the source into this entry.
// @fnv 0x0050b800
void LevItemCopyEntry::TESLevItem_CopyFrom(::TESForm* source)
{
    ::TESLevItem* sourceItem;
    sourceItem = dynamic_cast< ::TESLevItem*>(source);
    if (!sourceItem)
        return;
    TESForm_CopyAllComponents(source);
}

struct LevItemComparison : public ::TESLevItem
{
    bool TESLevItem_Compare(::TESForm*);
};

// @fnv 0x0050b840
bool LevItemComparison::TESLevItem_Compare(::TESForm* other)
{
    ::TESLevItem* pLevItem = dynamic_cast< ::TESLevItem*>(other);
    if (!pLevItem)
        return true;
    if (TESForm::Compare(pLevItem))
        return true;
    return false;
}
