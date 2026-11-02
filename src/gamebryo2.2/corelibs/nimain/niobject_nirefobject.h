// gamebryo2.2/corelibs/nimain/niobject_nirefobject.h: declares NiRefObject
#ifndef FNV_NIOBJECT_UNIT_NIREFOBJECT_H
#define FNV_NIOBJECT_UNIT_NIREFOBJECT_H

#include <stddef.h>
#include "niobject_nimemobject.h"

// Declaration-only dependency view of supplied include/NiRefObject.h.
// No definitions of its destructor, DeleteThis, or reference-count methods.
class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;
    virtual ~NiRefObject();
    virtual void DeleteThis();
};

typedef char niobject_refobject_size_check[(sizeof(NiRefObject) == 8) ? 1 : -1];
typedef char niobject_refcount_offset_check[(offsetof(NiRefObject, m_uiRefCount) == 4) ? 1 : -1];

#endif
