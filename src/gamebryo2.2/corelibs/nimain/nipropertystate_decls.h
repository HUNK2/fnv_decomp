// gamebryo2.2/corelibs/nimain/nipropertystate_decls.h: declares NiPropertyState
#ifndef NIPROPERTYSTATE_DECLS_H
#define NIPROPERTYSTATE_DECLS_H

#include "NiProperty.h"
class NiPropertyState
{
  public:
    NiProperty* m_spProperties[7];
    NiPropertyState& operator=(const NiPropertyState& other);
};
#endif
