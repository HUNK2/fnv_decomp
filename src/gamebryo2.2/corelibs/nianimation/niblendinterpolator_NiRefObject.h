// Source layout: NiRefObject. PC corrections are in generate_headers.py.
#ifndef FNV_NIBLENDINTERPOLATOR_PRIVATE_FNV_NIREFOBJECT_H
#define FNV_NIBLENDINTERPOLATOR_PRIVATE_FNV_NIREFOBJECT_H
#include "niblendinterpolator_layout_support.h"
#include "niblendinterpolator_NiMemObject.h"
class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;  // +0x4
    virtual ~NiRefObject();
    virtual void DeleteThis();
    FNV_FORCEINLINE void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    FNV_FORCEINLINE void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};
FNV_STATIC_ASSERT(sizeof(NiRefObject) == 0x8);
FNV_STATIC_ASSERT(offsetof(NiRefObject, m_uiRefCount) == 0x4);
#endif
