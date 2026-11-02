// fallout/ai/movement/virtualactorpathhandler.h: declares VirtualActorPathHandler
#ifndef FNV_VIRTUALACTORPATHHANDLER_H
#define FNV_VIRTUALACTORPATHHANDLER_H

#include "virtualactorpathhandler_decls.h"
#include "NiPoint3.h"
extern "C" const NiPoint3 NiPoint3_ZERO;
class VirtualActorPathHandler
{
  public:
    bool GetPathingDelta(NiPoint3& delta);
};
// @fnv 0x009ea710
bool VirtualActorPathHandler::GetPathingDelta(NiPoint3& delta)
{
    delta = NiPoint3_ZERO;
    return false;
}
#endif
