
#include "nicontrollermanager_decls.h"
// @fnv 0x0047a510
NiFixedString* NiControllerManager::FindSequenceByName() { return DAT_011c61e0; }

// @fnv 0x0047b220
bool NiControllerManager::StopSequence(NiControllerSequence* sequence,float easeOut) { return sequence->Deactivate(easeOut,false); }
// @fnv 0x0047aab0
bool NiControllerManager::ActivateControllerSequence(NiControllerSequence* sequence,int priority,bool startOver,float weight,float easeIn,NiControllerSequence* sync) { return sequence->Activate((char)priority,startOver,weight,easeIn,sync,false); }
// @fnv 0x0048fef0
void NiControllerManager::DeactivateAllSequences(float easeOut) {
 for(unsigned int i=0;i<sequences.GetSize();++i) {
  NiControllerSequence* sequence=sequences.FUN_00629ab0(i);
  StopSequence(sequence,easeOut);
 }
}
