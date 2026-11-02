// fallout_shared/tesidlemanager_decls.h: declares IdleAnimationDirectoryEntry, TESAnimGroup, NiFormArray, TESFormInitFlag, TESFormVTable and more
#ifndef TESIDLEMANAGER_DECLS_H
#define TESIDLEMANAGER_DECLS_H


enum ANIM_GROUP_WEAPON_ENUM
{
    ANIM_GROUP_WEAPON_ENUM_AGW_NONE = 0,
    ANIM_GROUP_WEAPON_ENUM_AGW_HAND_TO_HAND = 1,
    ANIM_GROUP_WEAPON_ENUM_AGW_ONE_HAND_MELEE = 2,
    ANIM_GROUP_WEAPON_ENUM_AGW_TWO_HAND_MELEE = 3,
    ANIM_GROUP_WEAPON_ENUM_AGW_ONE_HAND_PISTOL = 4,
    ANIM_GROUP_WEAPON_ENUM_AGW_TWO_HAND_RIFLE = 5,
    ANIM_GROUP_WEAPON_ENUM_AGW_TWO_HAND_AUTOMATIC = 6,
    ANIM_GROUP_WEAPON_ENUM_AGW_TWO_HAND_HANDLE = 7,
    ANIM_GROUP_WEAPON_ENUM_AGW_TWO_HAND_LAUNCHER = 8,
    ANIM_GROUP_WEAPON_ENUM_AGW_ONE_HAND_GRENADE = 9,
    ANIM_GROUP_WEAPON_ENUM_AGW_ONE_HAND_MINE = 10,
    ANIM_GROUP_WEAPON_ENUM_AGW_ONE_HAND_LUNCHBOX_MINE = 11,
    ANIM_GROUP_WEAPON_ENUM_ANIM_GROUP_WEAPON_COUNT = 12
};

template <class T> class BSSimpleList
{
    void* first;
    void* last;

  public:
    BSSimpleList();
    ~BSSimpleList();
    bool IsEmpty();
    T& GetItem();
    void AddHead(T& item);
    void* AddTail(T item);
    void RemoveHead();
};

class IdleAnimationDirectoryEntry
{
    unsigned char unused[0x38];

  public:
    BSSimpleList<const char*>* m_ppFileListsByWeapon[12];
    IdleAnimationDirectoryEntry(const char*);
    void SetWeaponFiles(BSSimpleList<const char*>* files);
};

template <class Key, class Value> class NiTMap
{
    unsigned char unused[0x14];

  public:
    bool GetAt(Key key, Value& value) const;
};

enum ANIM_GROUP_MOVE_ENUM
{
    ANIM_GROUP_MOVE_ENUM_NONE = 0
};

class TESAnimGroup
{
  public:
    static void ParseAnimationGroupFilename(const char* filename, ANIM_GROUP_MOVE_ENUM& move,
                                            ANIM_GROUP_WEAPON_ENUM& weapon, bool& flag);
};

class BGSCameraPath;
template <class T> class NiTMallocInterface;

class TESForm;
class NiFormArray
{
  public:
    TESForm*& FUN_00877a30(unsigned int);
    unsigned int GetSize();
    TESForm* GetFormAt(unsigned int);
};

template <class T, class Interface> class NiTArray : public NiFormArray
{
  public:
    unsigned int GetSize();
    T& GetAt(unsigned int index);
    void SetAt(unsigned int index, T& value);
    void Compact();
};

class BGSCameraPath;

class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};

class TESFormVTable
{
  public:
    virtual void Unknown00();
    virtual void Unknown01();
    virtual void Unknown02();
    virtual void Unknown03();
    virtual void Unknown04();
    virtual void Unknown05();
    virtual void Unknown06();
    virtual void Unknown07();
    virtual void Unknown08();
    virtual void Unknown09();
    virtual void Unknown10();
    virtual void Unknown11();
    virtual void Unknown12();
    virtual void Unknown13();
    virtual void Unknown14();
    virtual void Unknown15();
    virtual void Unknown16();
    virtual void Unknown17();
    virtual void Unknown18();
    virtual void Unknown19();
    virtual void Unknown20();
    virtual void Unknown21();
    virtual void Unknown22();
    virtual void Unknown23();
    virtual void Unknown24();
    virtual void Unknown25();
    virtual void Unknown26();
    virtual void Unknown27();
    virtual void Unknown28();
    virtual void Unknown29();
    virtual void Unknown30();
    virtual void Unknown31();
    virtual void Unknown32();
    virtual void Unknown33();
    virtual void InitItem();
};

class TESForm : public TESFormVTable
{
  public:
    bool GetInitialized() const;
};
class TESObjectREFR;
class IdleReplayDelayEntry;
class TESIdleForm : public TESForm
{
  public:
    bool HasMissingPathArray();
    bool FUN_005ff1d0();
    bool IsIdleFile();
    TESIdleForm* FindIdleFormForObject(TESObjectREFR*, TESObjectREFR*, BSSimpleList<IdleReplayDelayEntry*>*);
};

class TESObject;
class TESForm;
class NiFormArray;

class TESModel
{
  public:
    static const char* GetModelFilePath(TESObject*);
};

class AnimData
{
  public:
    unsigned char unused[0x134];
    BSSimpleList<IdleReplayDelayEntry*> replayDelays;
};
class TESObjectREFR
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual AnimData* GetAnimData();
    const char* GetModelFilePath();
};

class IdleAnimationManager : public NiTMap<const char*, IdleAnimationDirectoryEntry*>
{
  public:
    unsigned char loadedIdles;
    unsigned char padLoadedIdles[3];
    NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> > idleForms;
    NiFormArray* GetIdleFormArray(const char* directory);
    NiFormArray* GetIdleArray(TESForm* form);
    void InitializeIdleAnimations();
    NiFormArray* GetFormArrayForIdleDir(const char*);
    TESIdleForm* FindIdleFormForObject(TESObjectREFR*, TESObjectREFR*);
    IdleAnimationDirectoryEntry* ClearIdleData(const char*, BSSimpleList<const char*>*, bool);
    void InsertOrUpdate(const char*, IdleAnimationDirectoryEntry*);
    BSSimpleList<const char*>* FindIdleArrayEntry(const char* directory, ANIM_GROUP_WEAPON_ENUM weapon);
    static void BuildIdlePath(const char* source, char* destination);
    static TESObject* GetCurrentUsedItem();
    static bool GetUsedItemActivate();
};

extern "C" TESObject* fnv_tesidlemanager_used_item;
extern "C" bool fnv_tesidlemanager_used_item_activate;
extern "C" const char fnv_tesidlemanager_idle_anims[];
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
char* FUN_0040ab30(char*, int);
char* FUN_004812f0(const char*, const char*);
void FUN_00406d50(char*, unsigned int, const char*);
char* strrchr(const char* string, int character);
namespace CRT {
extern "C" char* strrchr(const char* string, int character);
extern "C" int _stricmp(const char* left, const char* right);
}
extern "C" char* strstr(const char* string, const char* substring);
int strcat_s(char* destination, unsigned int size, const char* source);
extern "C" const char fnv_idle_1hm_fast_left[];
extern "C" const char fnv_idle_1hm_left[];
extern "C" const char fnv_idle_1hp_fast_left[];
extern "C" const char fnv_idle_1hp_left[];
template <class T> unsigned int BSStringLength(const T* string);

void* operator new(unsigned int);
class ModelLoader
{
  public:
    BSSimpleList<const char*>* FindNIFFileListEntry(BSSimpleList<const char*>*, BSSimpleList<const char*>*);
    BSSimpleList<const char*>* GetModelFileList(const char*, bool, bool, int);
};
extern ModelLoader* g_modelLoader;
extern bool DAT_011cb71c;
#endif
