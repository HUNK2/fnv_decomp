// gamebryo2.2/corelibs/nianimation/niinterpolator_decls.h: declares NiObject, NiInterpolator
#ifndef NIINTERPOLATOR_PRIVATE_DECLS_H
#define NIINTERPOLATOR_PRIVATE_DECLS_H
class NiObject
{
  public:
    NiObject();
    void* m_pVTable;
    unsigned int m_uiRefCount;
};
class NiInterpolator : public NiObject
{
  public:
    NiInterpolator();
    float m_fLastTime;
};
extern const float DAT_01015f5c;
extern void* NiInterpolator_VTable[];
#endif
