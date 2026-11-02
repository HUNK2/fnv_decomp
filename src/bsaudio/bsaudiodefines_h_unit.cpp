
// Fallout: New Vegas - original source reconstruction.
// Compiled translation unit for the bsaudiodefines.h header unit.
//
// The original build compiled bsaudio/bsaudiodefines.h inside an audio
// translation unit. This translation unit plays that role for the matcher
// build: it includes the header unit and references the covered functions
// so the compiler emits their bodies the same way the original
// translation unit did.
//
// Compiler: MSVC9 SP1 15.00.30729.01, flags /Od /Oy- /GS /EHsc /Gy
#include "bsaudiodefines.h"

typedef NiTPointerListBase<NiTPointerAllocator<unsigned int>, SoundMessageRecord*> BSSoundMessageList;

void BSAudioDefinesEmitCoveredFunctions()
{
    // Qualified calls: keep the inline bodies in this object file.
    BSAudioDefinition kDebug;
    kDebug = kDebug;
    BSSoundInfo* pInfo = 0;
    BSSoundInfo kCopy(pInfo);
    pInfo->~BSSoundInfo();
    BSSoundMessageList* pList = 0;
    pList->RemoveHead();
}
