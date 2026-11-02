// gamebryo2.2/corelibs/nianimation/niblendfloatinterpolator_pre.h: declares NiBinaryStream

class NiStream;
class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
};

extern float DAT_0109696c;
extern float DAT_0109a918;
