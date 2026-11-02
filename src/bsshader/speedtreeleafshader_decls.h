#ifndef SPEEDTREELEAFSHADER_DECLS_H
#define SPEEDTREELEAFSHADER_DECLS_H

#include "layout_support.h"
#include "NiRefObject.h"

class NiD3DVertexShader;
class NiD3DPixelShader;
class NiD3DPass;
class NiD3DShaderDeclaration;
class NiD3DShaderConstantMap;

template <> class NiPointer<NiD3DShaderDeclaration>
{
  public:
    NiD3DShaderDeclaration* m_pObject;
    ~NiPointer();
};

template <> class NiPointer<NiD3DShaderConstantMap>
{
  public:
    NiD3DShaderConstantMap* m_pObject;
    ~NiPointer();
    NiPointer& operator=(NiD3DShaderConstantMap* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                reinterpret_cast<NiRefObject*>(m_pObject)->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                reinterpret_cast<NiRefObject*>(m_pObject)->IncRefCount();
        }
        return *this;
    }
};

template <> class NiPointer<NiD3DVertexShader>
{
  public:
    NiD3DVertexShader* m_pObject;
    NiPointer();
    ~NiPointer();
};

template <> class NiPointer<NiD3DPixelShader>
{
  public:
    NiD3DPixelShader* m_pObject;
    NiPointer();
    ~NiPointer();
};

template <> class NiPointer<NiD3DPass>
{
  public:
    NiD3DPass* m_pObject;
    NiPointer();
    ~NiPointer();
};

extern "C" void* __cdecl fnv_zlib_memset(void* destination, int value, unsigned int size);

extern "C"
{
    extern float DAT_01200638;
    extern float DAT_0120063C;
    extern float DAT_01200640;
    extern float DAT_01200644;
    extern float DAT_01200648;
    extern float DAT_0120064C;
    extern float DAT_01200650;
    extern float DAT_01200654;
    extern float DAT_01200658;
    extern float DAT_0120065C;
    extern float DAT_01200660;
    extern float DAT_01200664;
    extern float DAT_01200668;
    extern float DAT_0120066C;
    extern float DAT_01200670;
    extern float DAT_01200674;

    extern const char DAT_010A1E50[];
    extern const char DAT_01011584[];
    extern const char DAT_010AF568[];
    extern const char DAT_010AF5E4[];
    extern const char DAT_010AF60C[];
    extern const char DAT_010B8C34[];
    extern const char DAT_010B92D0[];
    extern const char DAT_010B92DC[];
    extern const char DAT_010B92E8[];
    extern const char DAT_010B92F8[];
    extern unsigned char DAT_011F941E;
    extern const unsigned char DAT_011F918C[];
    extern const unsigned char DAT_011FA0C0[];
    extern const unsigned char DAT_011FA0D0[];
    extern const unsigned char DAT_011FA0E0[];
    extern const unsigned char DAT_011FA280[];
    extern const unsigned char DAT_011FA290[];
    extern const unsigned char DAT_01200618[];

    void FUN_00b79930();
}

#endif
