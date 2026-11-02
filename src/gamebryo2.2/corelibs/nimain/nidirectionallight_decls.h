// gamebryo2.2/corelibs/nimain/nidirectionallight_decls.h: declares NiPoint3, NiColor, NiLight, NiDirectionalLight
#ifndef NIDIRECTIONALLIGHT_DECLS_H
#define NIDIRECTIONALLIGHT_DECLS_H

class CloningProcess;
struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {}
    NiPoint3(float a, float b, float c) : x(a), y(b), z(c)
    {}
};
struct NiColor
{
    float r, g, b;
};
class NiLight
{
  public:
    NiLight();
    void CopyMemberData(NiLight*, CloningProcess&);
    void* vptr;
    char pad04[0x99];
    unsigned char m_ucEffectCategory;
    char pad9e[0x26];
    float m_fDimmer;
    NiColor m_kAmb, m_kDiff, m_kSpec;
    char padec[4];
};
extern void* NiDirectionalLight_vtable[];
class NiDirectionalLight : public NiLight
{
  public:
    NiDirectionalLight();
    void CopyMemberData(NiDirectionalLight*, CloningProcess&);
    NiPoint3 m_kWorldDir;
};
#endif
