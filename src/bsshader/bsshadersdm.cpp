// bsshader/bsshadersdm.cpp: BSShaderInitializer (3 functions)

#include "bsshadersdm_decls.h"

// @fnv 0x00bc2940
void BSShaderInitializer::InitializeMultiBounds()
{
    if (!DAT_01201f70)
    {
        BSFadeNode::InitializeMultiBounds();
        BSShaderRenderUtility::InitializeMultiBounds();
        DAT_01201f70 = true;
    }
}

void __stdcall FUN_00bc2660(float, float);
void __stdcall FUN_00bc1cc0(float, float);
// Calls FUN_00bc2660 with a and b when flag is false, otherwise calls FUN_00bc1cc0 with a and c.
// @fnv 0x00bc28b0
void __stdcall DispatchFloatPair(float afFirst, float afSecond, float afThird, bool abUseThird)
{
    if (!abUseThird)
    {
        FUN_00bc2660(afFirst, afSecond);
        return;
    }
    FUN_00bc1cc0(afFirst, afThird);
}

struct StrArr
{
    char _pad[8];
    unsigned short m8;
    unsigned short mA;
    char _padC[2];
    unsigned short mE;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
void __stdcall WriteToSettingArray(StrArr*);
char* _FUN_00a7d330(const char*);
struct GlobalObjectO2_00a7b610
{
    const char* f0;
};
extern GlobalObjectO2_00a7b610 g_01201f68;
// @fnv 0x00bc28f0
void __stdcall FUN_00bc28f0(StrArr* pStrArr)
{
    WriteToSettingArray(pStrArr);
    char* pStr = _FUN_00a7d330(g_01201f68.f0);
    unsigned int uiIndex = pStrArr->mA;
    unsigned int cnt = pStrArr->m8;
    if (uiIndex >= cnt)
    {
        pStrArr->SetSize(pStrArr->mE + uiIndex);
    }
    pStrArr->SetAt(uiIndex, pStr);
}
