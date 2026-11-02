#ifndef FNV_DIALOGUEPACKAGE_DECLS_H
#define FNV_DIALOGUEPACKAGE_DECLS_H

// Canonical classes (Actor/MobileObject/TESObjectREFR/TESForm/PlayerCharacter/BaseProcess) come from include/.
// NiPointer stays unit-local: the matched 004d52d0 calls NiPointer::operator-> out of line (0x00559450),
// which the canonical layout_support.h NiPointer does not declare. Members are declared only (out-of-line
// calls, as /Od emits for the original inline helpers).
#define NiPointer FNV_NiPointer_Canonical
#include "../../../include/layout_support.h"
#undef NiPointer
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    ~NiPointer();
    NiPointer<T>& operator=(T* object);
    T* operator->() const;
};

// Paths name include/ explicitly: src/fallout/ai has unit headers of the same names (playercharacter.h, baseprocess.h).
#include "../../../include/PlayerCharacter.h"
#include "../../../include/BaseProcess.h"

class NiNode;
class BGSTerrainManager;
BGSTerrainManager* LoadBGSTerrainManager(const char* path);
BGSTerrainManager* LoadBGSTerrainManager(const NiPointer<NiNode>& path);

#endif
