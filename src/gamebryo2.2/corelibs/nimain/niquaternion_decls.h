// gamebryo2.2/corelibs/nimain/niquaternion_decls.h: declares NiBinaryStream, NiStream, RgbaColor, NiQuaternion
#ifndef NIQUATERNION_PRIVATE_DECLS_H
#define NIQUATERNION_PRIVATE_DECLS_H

extern "C" double __cdecl sqrt(double);

class NiBinaryStream;
typedef unsigned int(__cdecl* NiBinaryStreamRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    NiBinaryStreamRead m_pfnRead;
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
};
class NiStream
{
  public:
    unsigned char m_ucUnknownByte[0x24c];
    NiBinaryStream* m_pUnderlyingStream;
};
class RgbaColor
{
  public:
    float r, g, b, a;
    void LoadBinary(NiStream& arStream);
};
class ThreeByThreeMatrix
{
  public:
    float m[3][3];
};
class NiQuaternion
{
  public:
    float m_fVectorX, m_fVectorY, m_fVectorZ, m_fScalarPart;
    void MakeUnitLength();
    void SetRotationFromEulerXYZ(float x, float y, float z);
    void FromRotationMatrix(const ThreeByThreeMatrix& matrix);
    void EnsureCanonicalSign();
    void Slerp(float t, const NiQuaternion& a, const NiQuaternion& b);
    static __declspec(noinline) float CalculateSlerpWeight(float t, float cosine);
};

extern "C" double __cdecl cos(double);
extern "C" double __cdecl sin(double);
#endif
