// fallout_shared/bgsterminal_decls.h: declares TESFileFormVersion, TESFile, TESFormInitFlag, TESForm, TESBoundAnimObject and more
#ifndef BGSTERMINAL_DECLS_H
#define BGSTERMINAL_DECLS_H

class TESFile;
class Script;
class TESForm;
class TESSound;
class BGSNote;
class BGSTerminal;
class TerminalMenuItem;
class ScriptVariableInfo;
class ScriptReferencedObject;
extern "C" void* memset(void*, int, unsigned int);
extern "C" void* _alloca(unsigned int);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
template <class T> class BSStringT
{
  public:
    T* data;
    unsigned short length, capacity;
    bool Set(const T*, unsigned int);
};
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    void AddTail(T const&);
    T& GetItem();
    BSSimpleList* GetNext();
    bool IsEmpty();
    bool AddHead(T&);
    bool IsInList(T&);
};
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESFile : public TESFileFormVersion
{
  public:
    unsigned int GetChunkSize();
    unsigned int GetChunkID();
    bool NextChunk();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData(unsigned int*);
    bool IsEndianConversionRequired();
};
class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
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
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void readOBNDSubRecord(TESFile*);
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
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
    virtual const char* GetEditorID();
    virtual bool SetEditorID(const char*);
    unsigned char formData[0x14];
};
class TESForm : public TESFormInitFlag
{
  public:
    void LoadRecordHeader(TESFile*);
    void SetInitializationState(bool);
    TESFile* GetFile(int);
    unsigned int GetFormID();
    static void RemapFormIDForFile(unsigned int&, TESFile*);
    static TESForm* GetFormByID(unsigned int);
};
class TESBoundAnimObject : public TESForm
{
  public:
    unsigned char boundData[0x18];
};
class TESFullName
{
  public:
    void* vtable;
    BSStringT<char> name;
};
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName*, TESFile*);
};
class TESModel
{
  public:
    void* vtable;
    unsigned char modelData[0x14];
    static void LoadModelData(TESModel*, TESFile*);
};
class TESModelTextureSwap : public TESModel
{
  public:
    BSSimpleList<void*> swaps;
    bool ParseTextureSwapData(void*, unsigned int, unsigned int);
};
class TESScriptableForm
{
  public:
    void* vtable;
    Script* script;
    bool resolved;
    void SetScript(Script*);
    void InitItem(TESForm*);
};
class BGSDestructibleObjectForm
{
  public:
    void* vtable;
    void* data;
    static void LoadDestructibleData(BGSDestructibleObjectForm*, TESFile*);
};
class TESObjectACTI : public TESBoundAnimObject,
                      public TESFullName,
                      public TESModelTextureSwap,
                      public TESScriptableForm,
                      public BGSDestructibleObjectForm
{
  public:
    unsigned char activatorData[0x20];
    void ResetFormData();
    virtual void InitItem();
    void SetLoopingSound(TESSound*);
};
class TESDescription
{
  public:
    void* vtable;
    unsigned int text;
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
};
class ScriptHeaderData
{
  public:
    unsigned int variableCount, m_uiReferenceID, dataSize, lastID;
    bool quest, effect, compiled;
    void Endian();
};
class Script : public TESForm
{
  public:
    ScriptHeaderData header;
    unsigned char scriptData[0x28];
    ScriptHeaderData* GetHeader();
    BSSimpleList<ScriptVariableInfo*>* GetVariableList();
    BSSimpleList<ScriptReferencedObject*>* GetReferencedObjectList();
    void SetScriptData(unsigned int, char*);
    void InitItem(TESForm*);
};
class ScriptVariableInfo
{
  public:
    unsigned char data[0x18];
    BSStringT<char> m_kName;
    ScriptVariableInfo();
    void Load(TESFile*);
};
class ScriptReferencedObject
{
  public:
    BSStringT<char> name;
    TESForm* form;
    unsigned int variableID;
    ScriptReferencedObject();
};
class PerkEntryConditionSet
{
  public:
    BSSimpleList<void*> conditions;
    void Load(TESFile*);
    void InitItem(TESForm*);
};
class TerminalMenuItem
{
  public:
    BSStringT<char> ResponseText, m_kMenuText;
    Script m_kScript;
    PerkEntryConditionSet Conditions;
    BGSNote* m_pNote;
    BGSTerminal* m_pTerminal;
    char cFlags;
    TerminalMenuItem();
};
class TerminalCompareData
{
  public:
    unsigned char m_ucByte0, cFlags, m_ucByte2, m_ucType;
};
class BGSTerminal : public TESObjectACTI, public TESDescription
{
  public:
    BSSimpleList<TerminalMenuItem*> m_kMenuItems;
    BGSNote* pPassword;
    TerminalCompareData Data;
    void ResetFormData();
    bool Load(TESFile*);
    void InitItem();
    void FUN_00500a20(BGSNote*);
    void AddMenuItem(TerminalMenuItem*);
    BSSimpleList<TerminalMenuItem*>* FUN_00461150();
};
extern ScriptVariableInfo* DAT_011c83d4;
typedef char terminal_size_check[sizeof(BGSTerminal) == 0xa8 ? 1 : -1];
typedef char menu_item_size_check[sizeof(TerminalMenuItem) == 0x78 ? 1 : -1];
class BGSNote : public TESForm
{
};
int Warning();
int Warning(const char*, ...);
unsigned int SetWarningState(bool);
class MessageHandler
{
  public:
    static void SetWarningCount(int);
};
// PC caller and note-list layout identify the covered 0x00966c10 span as
// PlayerCharacter::HasNote; the supplied BGSTerminal candidate is incorrect.
class PlayerCharacter
{
  public:
    unsigned char layoutPadding0[0x5e4];
    BSSimpleList<BGSNote*> notes;
    bool HasNote(BGSNote*);
};
#endif
