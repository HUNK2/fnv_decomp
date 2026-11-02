// gamebryo2.2/corelibs/nimain/niobject_declarations.h: declares NiObject
#ifndef FNV_NIOBJECT_UNIT_DECLARATIONS_H
#define FNV_NIOBJECT_UNIT_DECLARATIONS_H

#include "niobject_nirefobject.h"

class NiRTTI;

// Unit-private declaration view. NiObject's supplied canonical layout is
// NiRefObject with no additional fields. The bundled headers stay unchanged.
class NiObject : public NiRefObject
{
  public:
    NiObject* DynamicCast(const NiRTTI* rtti);
    bool IsKindOfType(const NiRTTI* rtti) const;
};

typedef char niobject_object_size_check[(sizeof(NiObject) == 8) ? 1 : -1];

#endif
