// bsaudio/bsaudiodefines_decls.h: declares NiAVObject, SoundMessageRecord
#ifndef FNV_BSAUDIODEFINES_DECLS_H
#define FNV_BSAUDIODEFINES_DECLS_H

#include "layout_support.h"
class NiAVObject
{
  public:
    virtual void vfn_0();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    __forceinline void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
template <> class NiPointer<NiAVObject>
{
  public:
    NiAVObject* m_pObject;
    __forceinline operator NiAVObject*() const
    {
        return m_pObject;
    }
    __forceinline ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};
void __cdecl FUN_00c45830(NiAVObject*);
class SoundMessageRecord
{
  public:
    unsigned int fields[4];
    NiPointer<NiAVObject> pObject;
    ~SoundMessageRecord();
};
#endif
