// fallout_shared/bgsmovablestatic_decls.h: declares BGSMovableStatic
#ifndef FNV_BGSMOVABLESTATIC_DECLS_H
#define FNV_BGSMOVABLESTATIC_DECLS_H

class TESSound;
class BGSMovableStatic
{
  public:
    unsigned char layoutPadding00[0x58];
    TESSound* m_pSoundEffect;
    void ResetFormData();
    char _pdbpad_5c[16];
    void* pSoundLoop_db;
    char data[1];
    char _pdbpad_71[3];
};
#endif
