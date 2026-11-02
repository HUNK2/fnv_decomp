// gamebryo2.2/corelibs/nianimation/niblendboolinterpolator_NiBinaryStream.h: declares NiBinaryStream
#ifndef FNV_NIBLENDBOOLINTERPOLATOR_NIBINARYSTREAM_H
#define FNV_NIBLENDBOOLINTERPOLATOR_NIBINARYSTREAM_H


extern float DAT_0109696c;
extern unsigned char DAT_0109a914;

class NiBinaryStream;
#pragma pack(push, 4)
class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
};
#pragma pack(pop)
#endif
