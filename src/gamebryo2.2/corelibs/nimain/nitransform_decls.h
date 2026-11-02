// gamebryo2.2/corelibs/nimain/nitransform_decls.h: declares NiPoint3, NiColor, NiBinaryStream, NiStream, NiTransform
#ifndef NITRANSFORM_DECLS_H
#define NITRANSFORM_DECLS_H
class NiStream;
class NiPoint3
{
  public:
    float x, y, z;
    static const NiPoint3 ZERO;
    void LoadBinary(NiStream&);
};
class NiColor
{
  public:
    float r, g, b;
    void LoadBinary(NiStream&);
};
class ThreeByThreeMatrix
{
  public:
    float m[3][3];
    void LoadBinary(NiStream&);
    void ResetToIdentity()
    {
        m[0][0] = 1.0f;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = 1.0f;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.0f;
    }
};
struct NiBinaryStream
{
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* write)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data)
    {
        unsigned int size = 4;
        position += read(this, data, 4, &size, 1);
    }
};
class NiStream
{
  public:
    char pad[0x24c];
    NiBinaryStream* input;
};
class NiTransform
{
  public:
    ThreeByThreeMatrix m_kOrientation;
    NiPoint3 m_kTranslation;
    float m_fScale;
    void ResetToIdentity();
    void LoadBinary(NiStream&);
};
#endif