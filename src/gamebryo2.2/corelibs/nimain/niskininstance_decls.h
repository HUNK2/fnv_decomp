// gamebryo2.2/corelibs/nimain/niskininstance_decls.h: declares NiObject, NiStream, NiSkinInstance
#pragma once

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiStream;
class NiObject
{
  public:
    virtual ~NiObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
};
class NiStream
{
  public:
    char padding[0xd8];
    unsigned int m_uiNifVersion;
    void ResetStreamState();
    unsigned int ReadUnsignedInteger();
    NiObject* GetLoadedObject();
    unsigned int GetLinkID();
};
template <class T> class NiPointer
{
  public:
    T* p;
    __forceinline void operator=(T* value)
    {
        if (p != value)
        {
            T* old = p;
            if (old && InterlockedDecrement((volatile long*)&old->m_uiRefCount) == 0)
                old->DeleteThis();
            p = value;
            if (value)
                InterlockedIncrement((volatile long*)&value->m_uiRefCount);
        }
    }
};
void* _NiMalloc(unsigned int);
class NiSkinInstance : public NiObject
{
  public:
    NiPointer<NiObject> m_pSkinData;
    NiPointer<NiObject> m_pkSkinMeshPartition;
    NiObject* m_pRootParent;
    NiObject** m_ppBones;
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
};
