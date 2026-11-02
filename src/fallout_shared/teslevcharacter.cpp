// fallout_shared/teslevcharacter.cpp: TESLevCreature, TESLevItem, TESLevCharacter, Entry (8 functions)

#include "teslevcharacter_unit.h"

// @fnv 0x0050ad40
void TESLevCreature::InitItem()
{
    if (GetInitialized())
        return;
    TESLeveledList::InitItem(this);
    TESModelTextureSwap::InitItem(this);
    SetInitializationState(true);
}

// Loads the leveled item's base form data and its leveled list data from the given load buffer.
// @fnv 0x0050b390
void TESLevItem::LoadGame(BGSLoadFormBuffer* buffer)
{
    TESForm::LoadGame(buffer);
    TESLeveledList::LoadGame(buffer);
}

// @fnv 0x0050a930
bool TESLevCharacter::Load(TESFile* file)
{
    unsigned char ucFormType = file->GetTESForm();
    if (ucFormType != 45)
        return false;
    LoadRecordHeader(file);
    do
    {
        switch ((int)file->GetChunkID())
        {
        case 0x44494445: {
            char* editorID = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(editorID, 512);
            SetEditorID_AtRuntime(editorID);
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
                struct Entry
                {
                    unsigned short level;
                    unsigned short pad;
                    TESForm* form;
                    unsigned short count;
                    unsigned short pad2;
                } levelEntry;
                memset(&levelEntry, 0, 12);
                file->GetChunkData(&levelEntry, 12);
                if (file->IsEndianConversionRequired())
                    ((LeveledObject*)&levelEntry)->SwapEndian();
                DAT_011c8e64 = CreateLeveledObject(levelEntry.level, levelEntry.count, levelEntry.form, 0);
                break;
            }
            case 0x44454f43:
                if (DAT_011c8e64)
                {
                    ContainerItemExtra* extra = new ContainerItemExtra;
                    extra->Load(file);
                    DAT_011c8e64->extra = extra;
                    DAT_011c8e64 = 0;
                }
                break;
            }
            break;
        case 0x444c564c: {
            unsigned char chance = 0;
            file->GetChunkData(&chance, 0);
            FUN_0042e680(chance);
            break;
        }
        case 0x464c564c:
            file->GetChunkData(&m_ucChanceNone, 0);
            break;
        case 0x474c564c: {
            unsigned int global = 0;
            file->GetChunkData(&global);
            m_pLevelGlobal = (TESGlobal*)global;
            break;
        }
        case 0x4c444f4d:
        case 0x54444f4d:
        case 0x44534f4d:
        case 0x44444f4d:
            TESModel::LoadModelData(this, file);
            break;
        case 0x53444f4d: {
            void* textureData;
            unsigned int chunkSize = file->GetChunkSize();
            textureData = _alloca(chunkSize);
            file->GetChunkData(textureData, chunkSize);
            ParseTextureSwapData(textureData, chunkSize, ((TESFileFormVersion*)file)->GetFormVersion());
            break;
        }
        }
    } while (file->NextChunk());
    SetInitializationState(false);
    return true;
}

namespace fnv_0050b3c0 {
struct Actor;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESObjectREFR;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    int LoadHeader(SaveLoadFile*);
    int ReadFormData(SaveLoadFile*);
    void SkipData(SaveLoadFile*, unsigned int);
    unsigned int GetFormID();
    void SetForm(TESForm*);
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int GetFormType();
    struct blob4 GetChangeFlags();
    void SetChangeFlags(struct blob4);
    struct blob4 GetOldChangeFlags();
    void SetOldChangeFlags(struct blob4);
    void SetVersion(unsigned char);
    virtual unsigned char GetVersion();
    void SetSkipForm(bool);
    bool GetSkipForm();
    void SetFormPending(bool);
    bool GetFormPending();
    void SetRevertOnly(bool);
    bool GetRevertOnly();
    void SetReconstructedForm(bool);
    bool GetReconstructedForm();
    void SetCellChanged(bool);
    bool GetCellChanged();
    void* __vecDelDtor(unsigned int);
    unsigned int iFormID;
    char Header[9];
    char _pad_1d[3];
    unsigned int iSize;
    TESForm* pForm;
    unsigned int iFlags;
    char m_cReservedBytes[4];
};
typedef char _sizecheck_BGSLoadFormBuffer[sizeof(BGSLoadFormBuffer) == 48 ? 1 : -1];
struct FUN_0050b3c0_shell : public TESLevItem
{
    void FUN_0050b3c0(BGSLoadFormBuffer*);
};

struct TESLeveledList_Revert_Access
{
    void Revert(BGSLoadFormBuffer*);
};

// Reverts the TESForm base and then the leveled list at offset 0x30 using the load game buffer.
// @fnv 0x0050b3c0
void FUN_0050b3c0_shell::FUN_0050b3c0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    TESForm::Revert(reinterpret_cast<unsigned int>(apLoadGameBuffer));
    reinterpret_cast<TESLeveledList_Revert_Access*>(reinterpret_cast<char*>(this) + 0x30)->Revert(apLoadGameBuffer);
}
}  // namespace fnv_0050b3c0

struct FUN_00487650
{
    FUN_00487650();
    ~FUN_00487650();
    virtual void vf();
    int v[6];
};
struct B2_4fe
{
    B2_4fe();
    ~B2_4fe();
    virtual void vf2();
    int w;
};
struct FUN_0050a770 : public TESBoundAnimObject, public FUN_00487650, public B2_4fe
{
    FUN_0050a770();
    ~FUN_0050a770();
};
// @fnv 0x0050a770
FUN_0050a770::FUN_0050a770()
{
    SetFormType((ENUM_FORM_ID)0x2d);
    ClearData();
    SetInitializationState(true);
}

void __cdecl _Deallocate(void*);
struct FUN_0050a820_shell
{
    void FUN_0050a850();
    void* FUN_0050a820(unsigned int);
};
// Calls FUN_0050a850, then deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0050a820
void* FUN_0050a820_shell::FUN_0050a820(unsigned int flags)
{
    FUN_0050a850();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
    void FUN_0050acb0(TESForm*);
};
// Casts apCopy to TESLevCharacter and, if the cast succeeds, calls FUN_004851b0 with apCopy.
// @fnv 0x0050acb0
void FUN_005e78f0_t::FUN_0050acb0(TESForm* apCopy)
{
    TESLevCharacter* pllcopy = dynamic_cast<TESLevCharacter*>(apCopy);
    if (!pllcopy)
        return;
    FUN_004851b0(apCopy);
}

namespace LevCharacterComparison {
class Entry : public TESLevCharacter
{
  public:
    bool FUN_00485270(TESForm*);
    bool FUN_0050acf0(TESForm*);
};

// Returns true if the cast fails or FUN_00485270 returns true for the compared object.
// @fnv 0x0050acf0
bool Entry::FUN_0050acf0(TESForm* other)
{
    TESLevCharacter* compared = dynamic_cast<TESLevCharacter*>(other);
    if (!compared)
        return true;
    if (FUN_00485270(compared))
        return true;
    return false;
}
}
