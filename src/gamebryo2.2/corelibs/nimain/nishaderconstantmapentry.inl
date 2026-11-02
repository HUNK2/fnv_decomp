
#include "nishaderconstantmapentry_decls.h"
// @fnv 0x00e81ba0
NiShaderConstantMapEntry::NiShaderConstantMapEntry()
{
    m_pVTable = &kVtbl_NiRefObject;
    m_uiRefCount = 0;
    InterlockedIncrement(&DAT_011f4400);
    m_pVTable = &kVtbl_NiShaderConstantMapEntry;
    m_bEnableState = true;
    m_kControlPoint = EmptyFS;
    m_uiValue1 = 0;
    m_uiValue2 = 0;
    m_uiValue3 = 0;
    m_uiValue4 = 0;
    *reinterpret_cast<char* volatile*>(&m_kSecondaryString.m_kHandle) = EmptyFS.m_kHandle;
    volatile NiShaderConstantMapEntry* ordered = this;
    ordered->m_uiValue5 = 0;
    ordered->m_uiValue6 = 0;
    ordered->m_pConstantData = 0;
    ordered->m_bFlag0 = false;
    ordered->m_bFlag1 = false;
    ordered->m_bFlag2 = false;
}
