
// Provisional build file (plan B2): exact copies of the nishaderlibrary recipe for other original addresses.
// Twin_<addr>/FUN_<addr> are placeholder names; the original identities of these functions are unknown.
#include "NiRefObject.h"

class RefCountedNamedObject : public NiRefObject
{
  public:
    char* m_pcName;

    const char* GetName();
};

struct Twin_0044ddc0 : public RefCountedNamedObject
{
    const char* GetName();
};
// @fnv 0x0044ddc0
const char* Twin_0044ddc0::GetName()
{
    return m_pcName;
}

struct Twin_00aa7870 : public RefCountedNamedObject
{
    const char* GetName();
};
// @fnv 0x00aa7870
const char* Twin_00aa7870::GetName()
{
    return m_pcName;
}
