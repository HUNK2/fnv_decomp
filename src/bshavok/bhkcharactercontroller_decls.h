// bshavok/bhkcharactercontroller_decls.h: declares bhkCharacterController, MobileObject
#ifndef BHKCHARACTERCONTROLLER_PACKET_DECLS_H
#define BHKCHARACTERCONTROLLER_PACKET_DECLS_H

class GlobalObject_008c71b0
{
  public:
    int value;
    GlobalObject_008c71b0(int initial);
};
class bhkCharacterController
{
  public:
    float components[4];
    float& GetVectorElement(int index);
    GlobalObject_008c71b0 FUN_0070c440();
};
class MobileObject
{
  public:
    bhkCharacterController* GetPhysicsCharacterController();
    GlobalObject_008c71b0 GetVectorElement();
};
#endif
