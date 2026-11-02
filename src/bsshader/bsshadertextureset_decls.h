// bsshader/bsshadertextureset_decls.h: declares BSShaderProperty, NiObjectCall
#ifndef BSSHADERTEXTURESET_DECLS_H
#define BSSHADERTEXTURESET_DECLS_H

class BSShaderProperty
{
  public:
    enum TextureTypeEnum
    {
        TEXTYPE_DIFFUSE = 0,
        TEXTYPE_NORMAL = 1,
        TEXTYPE_GLOW = 2,
        TEXTYPE_HEIGHT = 3,
        TEXTYPE_ENV = 4,
        TEXTYPE_ENV_MASK = 5,
        TEXTYPE_SPECULAR = 6,
        TEXTYPE_COUNT = 7
    };
};

class NiObjectCall : public NiObject
{
  public:
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
};

template <> class NiPointer<NiTexture>
{
  public:
    NiTexture* m_pObject;

    FNV_FORCEINLINE NiPointer() : m_pObject(0)
    {}

    FNV_FORCEINLINE ~NiPointer()
    {
        if (m_pObject)
        {
            NiTexture* object = m_pObject;
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)) == 0)
                object->DeleteThis();
        }
    }
};

void __cdecl NiFree(void* memory);

#endif
