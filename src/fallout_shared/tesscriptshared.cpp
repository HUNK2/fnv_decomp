// fallout_shared/tesscriptshared.cpp: free functions (1 function)

#include "layout_support.h"

class ScriptLocalVariable
{
  public:
    unsigned int uiID;
    unsigned char layoutPadding4[4];
    double fValue;
    bool m_bIsString;
    unsigned char layoutPadding11[7];
    ScriptLocalVariable();
};

class ScriptVariableInfo
{
  public:
    ScriptLocalVariable data;
    BSStringT<char> m_kName;
    ScriptVariableInfo();
};

// @fnv 0x005e28b0
ScriptVariableInfo::ScriptVariableInfo()
{}
