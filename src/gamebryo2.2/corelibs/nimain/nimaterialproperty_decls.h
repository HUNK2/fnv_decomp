// gamebryo2.2/corelibs/nimain/nimaterialproperty_decls.h: declares NiProperty, NiColor, NiBinaryStream, NiStream, NiMaterialProperty
#ifndef FNV_NIMATERIALPROPERTY_DECLS_H
#define FNV_NIMATERIALPROPERTY_DECLS_H


#include "NiObjectNET.h"

class NiStream;

// Private declaration of the canonical NiProperty layout with its stream API.
#ifndef FNV_NIPROPERTY_H
#define FNV_NIPROPERTY_H
class NiProperty : public NiObjectNET
{
  public:
    virtual void LoadBinary(NiStream& stream);
};
FNV_STATIC_ASSERT(sizeof(NiProperty) == 0x18);
#endif

class NiColor
{
  public:
    float r, g, b;
    NiColor() : r(0.0f), g(0.0f), b(0.0f)
    {}
    void LoadBinary(NiStream& stream);
};
FNV_STATIC_ASSERT(sizeof(NiColor) == 12);

class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int Read(void* buffer, unsigned int bytes, unsigned int* componentSizes, unsigned int componentCount)
    {
        unsigned int read = (*m_pfnRead)(this, buffer, bytes, componentSizes, componentCount);
        m_uiStreamFlags += read;
        return read;
    }

    unsigned int Read(void* buffer, unsigned int bytes)
    {
        unsigned int componentSize = bytes;
        return Read(buffer, bytes, &componentSize, 1);
    }
};
FNV_STATIC_ASSERT(sizeof(NiBinaryStream) == 0x10);

// Only the stream prefix used by this unit is required.
class NiStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiBSVersion;
    unsigned char streamFields[0x244];
    NiBinaryStream* m_pUnderlyingStream;
};
FNV_STATIC_ASSERT(offsetof(NiStream, m_pUnderlyingStream) == 0x24c);

template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    stream.m_pUnderlyingStream->Read(&value, sizeof(T));
}

class NiMaterialProperty : public NiProperty
{
  public:
    int m_iIndex;
    NiColor m_spec;
    NiColor m_emit;
    NiColor* m_external_emit;
    float m_fShine;
    float m_fAlpha;
    float m_fEmitMult;
    unsigned int m_uiRevID;
    void* m_pMaterialData;
    virtual void LoadBinary(NiStream& stream);
};
FNV_STATIC_ASSERT(sizeof(NiMaterialProperty) == 0x4c);
FNV_STATIC_ASSERT(offsetof(NiMaterialProperty, m_spec) == 0x1c);
FNV_STATIC_ASSERT(offsetof(NiMaterialProperty, m_emit) == 0x28);
FNV_STATIC_ASSERT(offsetof(NiMaterialProperty, m_fShine) == 0x38);
FNV_STATIC_ASSERT(offsetof(NiMaterialProperty, m_fAlpha) == 0x3c);
FNV_STATIC_ASSERT(offsetof(NiMaterialProperty, m_fEmitMult) == 0x40);

#endif
