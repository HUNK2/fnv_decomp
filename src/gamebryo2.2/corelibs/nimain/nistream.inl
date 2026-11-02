#include "nistream_decls.h"

// @fnv 0x0043d050
void NiStream::SaveLinkID(const NiObject* object)
{
    unsigned int linkID = vfn_2c(object);
    FUN_0044adf0(*this, linkID);
}
