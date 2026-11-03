// fallout_shared/tesdatahandler_files.h: declares NiFile, FILETIME, TESRecordHeader, BSFile, TESFile and more
#ifndef FNV_TESDATAHANDLER_FILES_H
#define FNV_TESDATAHANDLER_FILES_H

class NiFile
{
  public:
    enum OpenMode
    {
        READ_ONLY = 0,
        WRITE_ONLY = 1
    };
};
struct FILETIME
{
    unsigned int low, high;
};
struct WIN32_FIND_DATAA
{
    unsigned int attributes;
    FILETIME created, accessed, written;
    unsigned int sizeHigh, sizeLow, reserved0, reserved1;
    char name[260];
    char alternate[14];
};
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char*, WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void*, WIN32_FIND_DATAA*);
extern "C" __declspec(dllimport) int __stdcall FindClose(void*);
struct TESRecordHeader
{
    unsigned int type, size, flags, formID;
};
class BSFile
{
  public:
    BSFile(const char*, NiFile::OpenMode, unsigned int, bool);
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void Seek(int, int);
    virtual void vfn_24();
    virtual unsigned int GetSize();
    bool IsOpen();
    unsigned char fileData[0x154];
};
class TESFile
{
  public:
    unsigned int error;
    unsigned char data004[12];
    BSFile* stream;
    unsigned char data014[12];
    char fileName[260];
    char directory[260];
    unsigned int data228;
    unsigned int bufferSize;
    unsigned char data230[40];
    unsigned int currentChunk;
    unsigned int data25c;
    unsigned int fileSize;
    unsigned char data264[56];
    WIN32_FIND_DATAA fileData;
    unsigned char data3dc[12];
    unsigned int fileFlags;
    bool OpenTESFile(const char*, const char*, NiFile::OpenMode, bool);
    void GetZeroByte();
    void LoadFormAndUpdateFlag();
    void SetGroupMode(bool);
    void SetField3DC(float);
    int GetTESForm();
    unsigned int GetFormID();
    unsigned char GetFileCompileIndex();
    TESRecordHeader* GetRecordHeader();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetNextChunk();
    bool IsEndianConversionRequired();
    bool GetChunkData(void*, unsigned int);
    static void SetTempIDOwnerForForm(unsigned int, TESFile*);
    float GetFileVersion();
    ~TESFile();
    void SetBufferSize(int);
    TESFile* GetParentTESFile();
    int ReadTESInfo();
    bool CheckMasterFiles(BSSimpleList<TESFile*>*, bool);
    bool GetIsChecked();
    void SetChecked(bool);
    bool IsMasterFile();
    bool IsValidFileVersion();
    unsigned int FUN_00471ad0();
    TESFile* GetMasterFile(unsigned int);
    const char* FUN_00471a60(unsigned int);
    bool HasMasterFileChanged();
    const char* GetName();
    bool GetActive();
    void SetCompileIndex(unsigned char);
    bool OpenTESFile(NiFile::OpenMode, bool);
    unsigned int GetFieldAt3E0();
    BSSimpleList<TESFile*>* TESFile_GetMasterList();
    TESForm* FUN_0044edb0();
    bool GetByteAt428();
};
void FUN_0040fbe0(const char*, ...);
void FUN_0043b2b0(bool);
const char* PrepareScriptMessage(const char*, bool);
class CompileWarningSetting
{
  public:
    const char* GetText();
};
extern CompileWarningSetting DAT_011c4024, DAT_011c4048;
extern bool DAT_011c54b9;
extern unsigned int DAT_011c3f24, DAT_011c3f28;
extern TESObjectCELL* DAT_011c3f30;
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
char* FUN_0040ab30(char*, int);
class Archive;
class ArchiveManager
{
  public:
    static Archive* PluginFile(const char*, unsigned short, bool);
};
Archive* FindArchiveByName(const char*);
class TESTopic : public TESForm
{
  public:
    TESTopic(int);
    unsigned char topicData[0x30];
    static void RemoveQuestInfo(TESQuest*);
    static void ReorderTopics(bool, BSSimpleList<TESTopic*>*);
};
class PlayerCharacter
{
  public:
    BSSimpleList<TESTopic*>* GetSelfOffset6A8();
    class PlayerBase* FUN_00464e10();
};
class PlayerBase
{
  public:
    void FUN_008d50e0();
};
extern PlayerCharacter* g_thePlayer;
class IdleAnimationManager
{
  public:
    void InitializeIdleAnimations();
};
extern IdleAnimationManager* DAT_011cb6a0;
void FUN_00408df0();
void ValidateFactionReactions();

class Calendar
{
  public:
    void ResetCachedValues();
    void FUN_00867890();
};
extern Calendar g_calendar;
class TESDataHandler;
extern TESDataHandler* g_dataHandler;

class TESTopicInfo : public TESForm
{
  public:
    TESTopicInfo(int);
    unsigned char infoData[0x38];
};
class ExtraDataList
{
  public:
    void CallExtraDataListMethod35(TESObjectCELL*);
};
class BGSSaveLoadGame
{
  public:
    bool FUN_00469570();
};
extern BGSSaveLoadGame* g_BGSSaveLoadGame;
class TESSaveLoadGame
{
  public:
    bool FUN_0047c850();
};
extern TESSaveLoadGame* g_TESSaveLoadGame;
class ActorDeletionQueue
{
  public:
    void FUN_0096d470(MobileObject*, int);
};
extern ActorDeletionQueue DAT_011e0e80;
class GameSettingCollection
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28(TESFile*, const char*);
    static GameSettingCollection* Instance();
};
class NavMeshInfoMap : public TESForm
{
  public:
    NavMeshInfoMap();
    unsigned char mapData[0x28];
};
template <class T> class NiPointer
{
    T* pointer;

  public:
    NiPointer(T*);
    NiPointer(const NiPointer&);
    ~NiPointer();
    T* Get();
};
class NavMeshCollection
{
  public:
    NavMeshCollection();
    unsigned int data[4];
    void AppendNavMesh(NiPointer<NavMesh>);
};
template <int N> struct EndianSizeTag
{
};
void BSEndian(unsigned int*, EndianSizeTag<3>);
bool FUN_00484b40(unsigned int);
struct FormTypeDescription
{
    const char* name;
    unsigned int data[2];
};
extern FormTypeDescription DAT_01187004[];
extern TESWorldSpace* DAT_011c3f34;
extern TESTopic* g_loadingTopic;
extern TESTopicInfo* DAT_011c3f38;
extern "C" void* _alloca(unsigned int);
#pragma intrinsic(_alloca)

NiPointer<NavMesh> MakeNavMeshPointer(NavMesh*);

int strcat_s(char*, unsigned int, const char*);
extern "C" __declspec(dllimport) char* __stdcall lstrcpyA(char*, const char*);
extern "C" __declspec(dllimport) char* __stdcall lstrcatA(char*, const char*);
char* strchr(char*, int);
int FUN_00ec4835(const void*, const void*, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" int* _errno();

extern "C" int _mbsnicmp(const unsigned char*, const unsigned char*, unsigned int);
extern "C" int _mbsicmp(const unsigned char*, const unsigned char*);
int FUN_00404dc0(const char*, const char*);
class RecursiveSpinLock
{
  public:
    RecursiveSpinLock();
    void Lock(const char*);
    void Unlock();
    unsigned int thread, count;
};
extern RecursiveSpinLock DAT_011c4000;
class BSFlags
{
  public:
    unsigned int flags;
    void Clear(unsigned int);
};

class BSThread
{
  public:
    BSThread();
    virtual ~BSThread();
    virtual void Run();
    unsigned int GetThreadID();
    unsigned char threadData[0x2c];
};
class FAMThread : public BSThread
{
  public:
    FAMThread();
    virtual void Run();
    void* event;
    RecursiveSpinLock lock;
    unsigned int state;
    void* work;
    void* result;
    unsigned int threadID;
};
extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void*, int, int, const char*);

#endif
