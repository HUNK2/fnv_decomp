// gamebryo2.2/corelibs/nimain/nitexturingproperty_decls.h: declares MemoryManager, NiMemObject, NiBinaryStream, NiStream, NiProperty and more
#ifndef NITEXTURINGPROPERTY_DECLS_H
#define NITEXTURINGPROPERTY_DECLS_H

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiStream;
class NiTexture;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* p = 0) : m_pObject(p)
    {}
    NiPointer& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
class BGSCameraPath;
class MemoryManager
{
  public:
    void* Allocate(unsigned int);
};
extern MemoryManager g_memoryManager;
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
};
class NiBinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);
    unsigned int BinaryRead(void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = m_pfnRead(this, p, n, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
    unsigned int Read(void* p, unsigned int n)
    {
        unsigned int size = n;
        return BinaryRead(p, n, &size, 1);
    }
};
class NiStream
{
  public:
    unsigned char prefix[0xd8];
    unsigned int m_uiNifVersion;
    unsigned char middle[0x170];
    NiBinaryStream* m_pUnderlyingStream;
    void SetLinkIDCount(unsigned int);
    void ResetStreamState();
};
template <class T> inline void ReadBinaryValue(NiStream& s, T& value)
{
    s.m_pUnderlyingStream->Read(&value, sizeof(T));
}
class NiProperty : public NiMemObject
{
  public:
    virtual ~NiProperty();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    unsigned char net[16];
    void LoadBinary(NiStream&);
    void IncRefCount()
    {
        InterlockedIncrement((volatile long*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (!InterlockedDecrement((volatile long*)&m_uiRefCount))
            DeleteThis();
    }
};
template <class T> class NiTMallocInterface
{
};
template <class T, class A> class NiTArray
{
  public:
    virtual ~NiTArray();
    T* m_pBase;
    unsigned short m_usMaxSize, m_usSize, m_usESize, m_usGrowBy;
    NiTArray(unsigned int, unsigned int);
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
template <class T> class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
  public:
    NiTPrimitiveArray(unsigned int size, unsigned int grow = 1) throw();
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
    void SetAt(unsigned int i, T& value)
    {
        if (i >= m_usSize)
        {
            m_usSize = (unsigned short)(i + 1);
            if (value)
                ++m_usESize;
        }
        else if (value)
        {
            if (!m_pBase[i])
                ++m_usESize;
        }
        else if (m_pBase[i])
            --m_usESize;
        m_pBase[i] = value;
    }
    void SetAtGrow(unsigned int i, T& value)
    {
        if (i >= m_usMaxSize)
            SetSize(i + m_usGrowBy);
        SetAt(i, value);
    }
};
class TextureMapTransform
{
  public:
    unsigned char data[0x48];
    TextureMapTransform() throw();
    void LoadBinary(NiStream&);
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
};
class NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
};
class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString& operator=(const char*);
};
extern NiFixedString EmptyFS;
inline NiFixedString& NiFixedString::operator=(const char* string)
{
    if (m_kHandle != string)
    {
        char* old = m_kHandle;
        m_kHandle = NiGlobalStringTable::AddString(string);
        if (old != EmptyFS.m_kHandle)
            InterlockedDecrement(reinterpret_cast<volatile long*>(old - 8));
    }
    return *this;
}
template <class T> class NiFlags
{
  public:
    T m_uiObjectFlags;
    NiFlags() : m_uiObjectFlags(0)
    {}
};
class NiTexturingProperty : public NiProperty
{
  public:
    enum ApplyMode
    {
        APPLY_REPLACE,
        APPLY_DECAL,
        APPLY_MODULATE,
        APPLY_HILIGHT,
        APPLY_HILIGHT2
    };
    enum ClampMode
    {
        CLAMP_S_CLAMP_T,
        CLAMP_S_WRAP_T,
        WRAP_S_CLAMP_T,
        WRAP_S_WRAP_T
    };
    enum FilterMode
    {
        FILTER_NEAREST,
        FILTER_BILERP,
        FILTER_TRILERP
    };
    class Map : public NiMemObject, public NiFlags<unsigned short>
    {
      public:
        virtual ~Map();
        virtual void LoadBinary(NiStream&);
        virtual void SaveBinary(NiStream&);
        virtual unsigned int GetClassID();
        NiPointer<NiTexture> m_spTexture;
        TextureMapTransform* m_pTextureTransform;
        Map(ClampMode clamp = WRAP_S_WRAP_T, FilterMode filter = FILTER_BILERP, unsigned int index = 0)
            : m_spTexture(0), m_pTextureTransform(0)
        {
            SetClampMode(clamp);
            SetFilterMode(filter);
            SetTextureIndex(index);
        }
        static void* operator new(unsigned int n)
        {
            return g_memoryManager.Allocate(n);
        }
        void SetClampMode(ClampMode mode)
        {
            m_uiObjectFlags = (m_uiObjectFlags & ~0x3000) | (mode << 12);
        }
        void SetFilterMode(FilterMode mode)
        {
            m_uiObjectFlags = (m_uiObjectFlags & ~0x0f00) | (mode << 8);
        }
        void SetTextureIndex(unsigned int i)
        {
            m_uiObjectFlags = (m_uiObjectFlags & ~0xff) | i;
        }
    };
    class BumpMap : public Map
    {
      public:
        float m_fLumaScale, m_fLumaOffset, m_fBumpMat00, m_fBumpMat01, m_fBumpMat10, m_fBumpMat11;
        BumpMap() throw();
    };
    class ParallaxMap : public Map
    {
      public:
        float m_fParallaxOffset;
        ParallaxMap() throw();
    };
    class ShaderMap : public Map
    {
      public:
        unsigned int m_uiID;
        ShaderMap(unsigned int id = 0) : m_uiID(id)
        {}
        virtual ~ShaderMap();
        virtual void LoadBinary(NiStream&);
        virtual void SaveBinary(NiStream&);
        virtual unsigned int GetClassID();
    };
    unsigned short m_uiObjectFlags;
    NiTPrimitiveArray<Map*> m_kStringArray;
    NiTPrimitiveArray<ShaderMap*>* m_pShaderMaps;
    NiTexturingProperty() throw();
    static NiPointer<NiTexturingProperty> ms_pDefaultProperty;
    static NiFixedString ms_kTextureMapNames[10];
    void LoadBinary(NiStream&);
    static void InitializePoint3();
    void SetApplyMode(ApplyMode mode)
    {
        m_uiObjectFlags = (m_uiObjectFlags & ~0xe) | (mode << 1);
    }
    void SetMultiTexture(bool multi)
    {
        if (multi)
            m_uiObjectFlags |= 1;
        else
            m_uiObjectFlags &= ~1;
    }
    void UpdateMultiTexture()
    {
        unsigned int size = m_kStringArray.m_usSize;
        for (unsigned int i = 1; i < size; ++i)
            if (m_kStringArray.m_pBase[i])
            {
                SetMultiTexture(true);
                return;
            }
        SetMultiTexture(false);
    }
};
// The PC linker folded this SetAt specialization with BGSCameraPath*.
// Keep its canonical external binding while exposing the map-array operation.
inline void SetMapAt(NiTPrimitiveArray<NiTexturingProperty::Map*>& maps, unsigned int i, NiTexturingProperty::Map*& map)
{
    reinterpret_cast<NiTArray<BGSCameraPath*, NiTMallocInterface<BGSCameraPath*> >*>(&maps)->SetAt(
        i, reinterpret_cast<BGSCameraPath*&>(map));
}
typedef char CheckPropertySize[sizeof(NiTexturingProperty) == 0x30 ? 1 : -1];
typedef char CheckMapSize[sizeof(NiTexturingProperty::Map) == 0x10 ? 1 : -1];
#endif
