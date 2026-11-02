// gamebryo2.2/corelibs/nimain/nishaderconstantmapentry_decls.h: declares NiFixedString, NiShaderConstantMapEntry
#ifndef NISHADERCONSTANTMAPENTRY_DECLS_H
#define NISHADERCONSTANTMAPENTRY_DECLS_H

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern volatile long DAT_011f4400;
extern unsigned char kVtbl_NiRefObject;
extern unsigned char kVtbl_NiShaderConstantMapEntry;
class NiFixedString
{
  public:
    char* m_kHandle;
};
extern NiFixedString EmptyFS;
class NiShaderConstantMapEntry
{
  public:
    void* m_pVTable;
    unsigned int m_uiRefCount;
    bool m_bEnableState;
    NiFixedString m_kControlPoint;
    unsigned int m_uiValue0, m_uiValue1, m_uiValue2;
    unsigned int m_uiValue3, m_uiValue4;
    NiFixedString m_kSecondaryString;
    unsigned int m_uiValue5, m_uiValue6;
    void* m_pConstantData;
    bool m_bFlag0, m_bFlag1, m_bFlag2;
    NiShaderConstantMapEntry();
};
#endif
