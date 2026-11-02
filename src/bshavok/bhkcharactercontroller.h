
#include "bhkcharactercontroller_decls.h"

// @fnv 0x00560d30
float& bhkCharacterController::GetVectorElement(int index)
{
    return components[index];
}

// @fnv 0x00931ed0
GlobalObject_008c71b0 MobileObject::GetVectorElement()
{
    bhkCharacterController* controller = GetPhysicsCharacterController();
    return controller ? controller->FUN_0070c440() : GlobalObject_008c71b0(0);
}
