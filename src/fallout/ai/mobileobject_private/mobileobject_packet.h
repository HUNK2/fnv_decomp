// fallout/ai/mobileobject_private/mobileobject_packet.h: declares ExtraDismemberedLimbs, bhkCharacterController, MobileObjectRemovalState

#include "../../../../include/ExtraDataList.h"
class ExtraDismemberedLimbs
{
  public:
    bool IsBitSet(int limb);
};
class bhkCharacterController
{
  public:
    void SetInactive();
    void FUN_00c70c90(int);
    float& GetVectorElement(int);
};
bhkCharacterController* CopyCharacterControllerVector(bhkCharacterController*, const NiPoint3&);

#pragma pack(push, 1)
struct MobileObjectRemovalState
{
    unsigned char padding0, padding1, padding2;
    bool removed;
    bhkCharacterController* controller;
};
#pragma pack(pop)
