#ifndef BSSHADERLIGHTINGPROPERTY_GLOBALS_H
#define BSSHADERLIGHTINGPROPERTY_GLOBALS_H

class RecursiveSpinLock
{
  public:
    unsigned int m_lock;
    void Lock(const char* name);
};
extern unsigned int DAT_011c5f84;
inline bool bsshaderlightingproperty_IsActive(ShadowSceneLight* light)
{
    return light && *(unsigned short*)((char*)light + 0x110) != 0xff &&
           !(*(unsigned int*)(*(char**)((char*)light + 0xf8) + 0x30) & 1);
}
#endif
