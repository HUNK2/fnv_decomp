// Source layout: NiRefObject. PC corrections are in generate_headers.py.
#ifndef FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_FNV_NIREFOBJECT_H
#define FNV_INTERFACE_REBASE_IFNV_EARLY_FOLDED_FNV_NIREFOBJECT_H
#include "interface_rebase_layout_support.h"
#include "interface_rebase_NiMemObject.h"
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
