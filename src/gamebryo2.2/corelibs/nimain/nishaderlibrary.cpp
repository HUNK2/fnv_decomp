// gamebryo2.2/corelibs/nimain/nishaderlibrary.cpp: RefCountedNamedObject (1 function)

#include "NiRefObject.h"

class RefCountedNamedObject : public NiRefObject
{
  public:
    char* m_pcName;

    const char* GetName();
};

// @fnv 0x00d47a30
const char* RefCountedNamedObject::GetName()
{
    return m_pcName;
}
