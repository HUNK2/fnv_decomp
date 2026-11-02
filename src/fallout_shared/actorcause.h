// Authored header for fallout_shared/actorcause.cpp.
#ifndef FNV_ACTORCAUSE_H
#define FNV_ACTORCAUSE_H


#include "layout_support.h"

#pragma pack(push, 4)

class BGSLoadGameBuffer;

class ActorCause
{
  public:
    // Reverts the cause list built since the last completed load-game snapshot.
    static void ClearActorCauseList(BGSLoadGameBuffer* buffer);

  protected:
    static BSSimpleList<ActorCause*> ms_kActorCauseList;
};

#pragma pack(pop)

#endif
