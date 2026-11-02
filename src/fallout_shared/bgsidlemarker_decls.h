// fallout_shared/bgsidlemarker_decls.h: declares TESForm, TESFormInitFlag, BGSIdleCollection, TESFile, BGSIdleMarker
#ifndef FNV_BGSIDLEMARKER_DECLS_H
#define FNV_BGSIDLEMARKER_DECLS_H


class TESFile;
class TESIdleForm;

class TESForm
{
  public:
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(void* component);
    virtual bool CompareWithBase(void* component);
    virtual ~TESForm();
#define FNV_TESFORM_SLOT(n) virtual void vfn_##n();
    FNV_TESFORM_SLOT(5)
    FNV_TESFORM_SLOT(6)
    FNV_TESFORM_SLOT(7) FNV_TESFORM_SLOT(8) FNV_TESFORM_SLOT(9) FNV_TESFORM_SLOT(10) FNV_TESFORM_SLOT(11)
        FNV_TESFORM_SLOT(12) FNV_TESFORM_SLOT(13) FNV_TESFORM_SLOT(14) FNV_TESFORM_SLOT(15) FNV_TESFORM_SLOT(16)
            FNV_TESFORM_SLOT(17) FNV_TESFORM_SLOT(18) FNV_TESFORM_SLOT(19) FNV_TESFORM_SLOT(20) FNV_TESFORM_SLOT(21)
                FNV_TESFORM_SLOT(22) FNV_TESFORM_SLOT(23) FNV_TESFORM_SLOT(24) FNV_TESFORM_SLOT(25) FNV_TESFORM_SLOT(26)
                    FNV_TESFORM_SLOT(27) FNV_TESFORM_SLOT(28) FNV_TESFORM_SLOT(29) FNV_TESFORM_SLOT(30)
                        FNV_TESFORM_SLOT(31) FNV_TESFORM_SLOT(32) FNV_TESFORM_SLOT(33) FNV_TESFORM_SLOT(34)
                            FNV_TESFORM_SLOT(35) FNV_TESFORM_SLOT(36) FNV_TESFORM_SLOT(37) FNV_TESFORM_SLOT(38)
                                FNV_TESFORM_SLOT(39) FNV_TESFORM_SLOT(40) FNV_TESFORM_SLOT(41) FNV_TESFORM_SLOT(42)
                                    FNV_TESFORM_SLOT(43) FNV_TESFORM_SLOT(44) FNV_TESFORM_SLOT(45) FNV_TESFORM_SLOT(46)
                                        FNV_TESFORM_SLOT(47) FNV_TESFORM_SLOT(48) FNV_TESFORM_SLOT(49)
                                            FNV_TESFORM_SLOT(50) FNV_TESFORM_SLOT(51) FNV_TESFORM_SLOT(52)
                                                FNV_TESFORM_SLOT(53) FNV_TESFORM_SLOT(54)
                                                    FNV_TESFORM_SLOT(55) virtual void readOBNDSubRecord(TESFile* file);
    FNV_TESFORM_SLOT(57)
    FNV_TESFORM_SLOT(58)
    FNV_TESFORM_SLOT(59) FNV_TESFORM_SLOT(60) FNV_TESFORM_SLOT(61) FNV_TESFORM_SLOT(62) FNV_TESFORM_SLOT(63)
        FNV_TESFORM_SLOT(64) FNV_TESFORM_SLOT(65) FNV_TESFORM_SLOT(66) FNV_TESFORM_SLOT(67) FNV_TESFORM_SLOT(68)
            FNV_TESFORM_SLOT(69) FNV_TESFORM_SLOT(70) FNV_TESFORM_SLOT(71) FNV_TESFORM_SLOT(72) FNV_TESFORM_SLOT(73)
                FNV_TESFORM_SLOT(74) FNV_TESFORM_SLOT(75)
                    FNV_TESFORM_SLOT(76) virtual bool SetEditorID_AtRuntime(const char* editorID);
#undef FNV_TESFORM_SLOT

    bool IsInCombat();
    void SetInitializationState(bool initialized);
    void LoadRecordHeader(TESFile* file);
};

class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};

class BGSIdleCollection
{
  public:
    void InitItem(TESForm* form);
};

class TESFile
{
  public:
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void* data, unsigned int size);
    bool GetChunkData(unsigned int* value);
    bool NextChunk();
    bool IsEndianConversionRequired();
};

class ChunkPayload16
{
  public:
    unsigned int data[4];
    void FUN_0067ff10();
};

class ChunkPayloadWrapper16
{
  public:
    unsigned int data[4];
    void LoadFromPTFile(ChunkPayload16* payload);
};

class BGSIdleMarker
{
  public:
    BGSIdleMarker();
    void FUN_005e9530();
    void InitItem();
    bool Load(TESFile* file);
};

template <int N> struct EndianSizeTag
{
};

void BSEndian(unsigned int* value, EndianSizeTag<4> tag);
void* __cdecl operator new[](unsigned int size);
void __cdecl operator delete[](void* pointer);
extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);
extern "C" void* __cdecl _alloca(unsigned int size);
#pragma intrinsic(_alloca)

extern unsigned int BGSQuestPerkEntry_vtbl;

#endif
