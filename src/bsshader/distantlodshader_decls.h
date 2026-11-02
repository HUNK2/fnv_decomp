// bsshader/distantlodshader_decls.h: declares NiMemObject, NiRefObject, NiD3DShaderConstantMap, DistantLODShader, NiD3DShader
#ifndef DISTANTLODSHADER_DECLS_H
#define DISTANTLODSHADER_DECLS_H

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class NiMemObject
{
  public:
    static void* operator new(unsigned int size);
};

class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

class GraphicsRenderer;
extern const float DAT_011ad860;
extern const float DAT_011fa280[];
extern const float DAT_011fa290[];
class NiD3DShaderConstantMap : public NiRefObject
{
  public:
    NiD3DShaderConstantMap(void* renderer, int programType);
    virtual unsigned int AddEntry(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*,
                                  unsigned int, unsigned int, const void*, bool);
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual void vfn_6();
    virtual void vfn_7();
    virtual void vfn_8();
    virtual void vfn_9();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual unsigned int LookupSequenceByKey(const char*);

  private:
    unsigned char m_data[0x3C];
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    NiPointer& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

class DistantLODShader
{
  public:
    unsigned char m_uiStandInValue[0x18];
    GraphicsRenderer* m_pOwnerShader;
    unsigned char m_iValueAfterStandIn[0x14];
    NiPointer<NiD3DShaderConstantMap> m_spFirstShaderConstantMap;
    NiPointer<NiD3DShaderConstantMap> m_spSecondShaderConstantMap;
    unsigned char m_pAuxiliaryObject[0x5C];
    const void* m_pDiffuseDirection;
    unsigned int m_uiInstanceData;
    unsigned short m_usInstanceDataCount;
    unsigned char m_pad3[2];
    unsigned char m_afAmbientColor[0x10];
    unsigned char m_diffuseDirection[0x10];
    unsigned char m_afDiffuseColor[0x10];
    unsigned char m_alphaTestRef[0x10];
    unsigned char m_eyeVector[0x10];
    unsigned char m_eyeRightVector[0x10];
    void UpdateShaderConstants();
};

class BSShader
{
  public:
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual void vfn_4();
    virtual void vfn_5();
    virtual void vfn_6();
    virtual void vfn_7();
    virtual void vfn_8();
    virtual void vfn_9();
    virtual void vfn_10();
    virtual void vfn_11();
    virtual void vfn_12();
    virtual void vfn_13();
    virtual void vfn_14();
    virtual void vfn_15();
    virtual void vfn_16();
    virtual void vfn_17();
    virtual void vfn_18();
    virtual void vfn_19();
    virtual void vfn_20();
    virtual void vfn_21();
    virtual void vfn_22();
    virtual void vfn_23();
    virtual void vfn_24();
    virtual void vfn_25();
    virtual void vfn_26();
    virtual void vfn_27();
    virtual void vfn_28();
    virtual void vfn_29();
    virtual void vfn_30();
    virtual void vfn_31();
    virtual void vfn_32();
    virtual void vfn_33();
    virtual void vfn_34();
    virtual void vfn_35();
    virtual void vfn_36();
    virtual void vfn_37();
    virtual void vfn_38();
    virtual void vfn_39();
    virtual void vfn_40();
    virtual void vfn_41();
    virtual void vfn_42();
    virtual void vfn_43();
    virtual void vfn_44();
    virtual void vfn_45();
    virtual void vfn_46();
    virtual void vfn_47();
    virtual void vfn_48();
    virtual void vfn_49();
    virtual void vfn_50();
    virtual void vfn_51();
    virtual void vfn_52();
    virtual void vfn_53();
    virtual void vfn_54();
    virtual void vfn_55();
    virtual void vfn_56();
    virtual void vfn_57();
    virtual void vfn_58();
    virtual void vfn_59();
    virtual void vfn_60();
    virtual void vfn_61();
    virtual void vfn_62();
    virtual void vfn_63();
    virtual void vfn_64();
    virtual void vfn_65();
    virtual void vfn_66();
    virtual void vfn_67();
    virtual void vfn_68();
    virtual void vfn_69();
    virtual void vfn_70();
    virtual void vfn_71();
    virtual void vfn_72();
    virtual void vfn_73();
    virtual void vfn_74();
    virtual void vfn_75();
    virtual void vfn_76();
    virtual void vfn_77();
    bool Initialize();
};
class NiD3DShader
{
  public:
    bool Initialize();
};
#endif
