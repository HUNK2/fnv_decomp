// gamebryo2.2/corelibs/nianimation/nibsplinedata_decls.h: declares NiBSplineBasis_float_3_, NiBSplineBasisData, NiBinaryStream, NiStream, NiObject and more
#ifndef FNV_NIBSPLINEDATA_DECLS_H
#define FNV_NIBSPLINEDATA_DECLS_H

#include "NiRefObject.h"

class NiBSplineBasis_float_3_
{
  public:
    int count;
    float weights[4];
    void Compute(float, int&, int&);
};
class NiBSplineBasisData
{
  public:
    NiBSplineBasis_float_3_& GetBSplineBasis();
};
class NiStream;
class NiBinaryStream;

typedef unsigned int(__cdecl* NiBinaryStreamRead)(NiBinaryStream*, void*, unsigned int, const unsigned int&,
                                                  unsigned int);
typedef unsigned int(__cdecl* NiBinaryStreamWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*,
                                                   unsigned int);
#pragma pack(push, 4)
class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    NiBinaryStreamRead m_pfnRead;
    NiBinaryStreamWrite m_pfnWrite;
};
class NiStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned char m_opaque004[0x248];
    NiBinaryStream* m_pUnderlyingStream;
};
class NiObject : public NiRefObject
{
};
class __declspec(novtable) NiBSplineData : public NiObject
{
  public:
    float* m_pfControlPoints;
    short* m_psCompactControlPoints;
    unsigned int m_uiControlPointCount;
    unsigned int m_uiCompactControlPointCount;
    void ReadGroup(NiStream& stream);
    void CalculateSplineValue(float, float*, unsigned int, NiBSplineBasisData*, unsigned int, float, float);
    virtual void LoadBinary(NiStream& stream);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBinaryStream) == 16);
FNV_STATIC_ASSERT(offsetof(NiStream, m_pUnderlyingStream) == 0x24c);
FNV_STATIC_ASSERT(sizeof(NiStream) == 0x250);
FNV_STATIC_ASSERT(sizeof(NiObject) == 8);
FNV_STATIC_ASSERT(offsetof(NiBSplineData, m_pfControlPoints) == 8);
FNV_STATIC_ASSERT(offsetof(NiBSplineData, m_psCompactControlPoints) == 12);
FNV_STATIC_ASSERT(offsetof(NiBSplineData, m_uiControlPointCount) == 16);
FNV_STATIC_ASSERT(offsetof(NiBSplineData, m_uiCompactControlPointCount) == 20);
FNV_STATIC_ASSERT(sizeof(NiBSplineData) == 24);

void* __cdecl FUN_00aa1070(unsigned int size);
void __cdecl FUN_00a89650(const short*, unsigned int, float, float, float*, unsigned int);
#endif
