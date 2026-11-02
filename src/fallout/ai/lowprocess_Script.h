// Source layout: Script. PC corrections are in generate_headers.py.
#ifndef FNV_SCRIPT_H
#define FNV_SCRIPT_H
#include "lowprocess_support.h"
#include "ScriptHeaderData.h"
#include "lowprocess_TESForm.h"
#pragma pack(push, 4)
class Script : public TESForm
{
  public:
    static bool GetLocalData(TESForm*, ExtraDataList*, unsigned int);
    bool Run(TESObjectREFR*, ScriptLocals*, TESObjectREFR*, bool);
    void* FUN_0055b980();
    ScriptHeaderData m_kHeader;                                          // +0x18
    char* m_pText;                                                    // +0x2C
    char* m_data;                                                     // +0x30
    float m_fValueAtOffset34;                                         // +0x34
    float fValueAtOffset38;                                           // +0x38
    float m_fValueAtOffset3C;                                         // +0x3C
    TESQuest* m_pOwnerQuest;                                          // +0x40
    BSSimpleList<ScriptReferencedObject*> m_kReferencedObjectList;  // +0x44
    BSSimpleList<ScriptVariableInfo*> m_kVariableList;                    // +0x4C
    Script();
    virtual ~Script();
    virtual void InitializeComponent();
    char* GetData();
    ScriptReferencedObject* GetReferencedForm(unsigned int index, ScriptLocals* locals);
    ScriptHeaderData* GetHeader();
    const char* GetVariableName(unsigned int index);
    static bool GetValue(double& value, const char* data, unsigned int& offset, TESObjectREFR* reference,
                         TESObjectREFR* container, Script* script, ScriptLocals* locals, bool skip);
    void CopyScriptContents(Script* script);
    void SetScriptData(unsigned int size, char* data);
    BSSimpleList<ScriptReferencedObject*>* GetReferencedObjectList();
    BSSimpleList<ScriptVariableInfo*>* GetVariableList();
    void InitItem(TESForm* form);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Script) == 0x54);
FNV_STATIC_ASSERT(offsetof(Script, m_kHeader) == 0x18);
FNV_STATIC_ASSERT(offsetof(Script, m_pText) == 0x2C);
FNV_STATIC_ASSERT(offsetof(Script, m_data) == 0x30);
FNV_STATIC_ASSERT(offsetof(Script, m_fValueAtOffset34) == 0x34);
FNV_STATIC_ASSERT(offsetof(Script, fValueAtOffset38) == 0x38);
FNV_STATIC_ASSERT(offsetof(Script, m_fValueAtOffset3C) == 0x3C);
FNV_STATIC_ASSERT(offsetof(Script, m_pOwnerQuest) == 0x40);
FNV_STATIC_ASSERT(offsetof(Script, m_kReferencedObjectList) == 0x44);
FNV_STATIC_ASSERT(offsetof(Script, m_kVariableList) == 0x4C);
#endif
