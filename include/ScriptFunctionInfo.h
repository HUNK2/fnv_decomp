#ifndef FNV_SCRIPT_FUNCTION_H
#define FNV_SCRIPT_FUNCTION_H

#include "layout_support.h"
#pragma pack(push, 4)
class ScriptFunctionInfo
{
  public:
    char* pFunctionName;          // +0x0
    char* m_pShortName;           // +0x4
    SCRIPT_OUTPUT m_eOutputType;  // +0x8
    char* m_pDescription;         // +0xC
    bool m_bRequiresReference;    // +0x10
    unsigned char layoutPadding11;
    unsigned short m_usParameterCount;          // +0x12
    ScriptParameter* pParameters;              // +0x14
    FNVScriptExecuteFunction m_pfnExecute;      // +0x18
    FNVScriptCompileFunction m_pfnCompile;      // +0x1C
    FNVScriptConditionFunction m_pfnCondition;  // +0x20
    bool m_bFunctionFlag;                       // +0x24
    bool m_bSetsExecutionFlag;                  // +0x25
    unsigned short layoutPadding26;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ScriptFunctionInfo) == 0x28);
FNV_STATIC_ASSERT(offsetof(ScriptFunctionInfo, pFunctionName) == 0x0);
FNV_STATIC_ASSERT(offsetof(ScriptFunctionInfo, m_pShortName) == 0x4);
FNV_STATIC_ASSERT(offsetof(ScriptFunctionInfo, m_eOutputType) == 0x8);
FNV_STATIC_ASSERT(offsetof(ScriptFunctionInfo, m_pDescription) == 0xC);
FNV_STATIC_ASSERT(offsetof(ScriptFunctionInfo, m_bRequiresReference) == 0x10);
FNV_STATIC_ASSERT(offsetof(ScriptFunctionInfo, m_usParameterCount) == 0x12);
FNV_STATIC_ASSERT(offsetof(ScriptFunctionInfo, pParameters) == 0x14);
FNV_STATIC_ASSERT(offsetof(ScriptFunctionInfo, m_pfnExecute) == 0x18);
FNV_STATIC_ASSERT(offsetof(ScriptFunctionInfo, m_pfnCompile) == 0x1C);
FNV_STATIC_ASSERT(offsetof(ScriptFunctionInfo, m_pfnCondition) == 0x20);
FNV_STATIC_ASSERT(offsetof(ScriptFunctionInfo, m_bFunctionFlag) == 0x24);
FNV_STATIC_ASSERT(offsetof(ScriptFunctionInfo, m_bSetsExecutionFlag) == 0x25);
#endif
