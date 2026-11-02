// include/havok/hkpFirstPersonGun.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x20.
#ifndef FNV_HAVOK_HKPFIRSTPERSONGUN_H
#define FNV_HAVOK_HKPFIRSTPERSONGUN_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#pragma pack(push, 1)
class hkpFirstPersonGun : public hkReferencedObject
{
  public:
    enum Type
    {
        WEAPON_TYPE_INVALID = 0,
        WEAPON_TYPE_BALLGUN = 1,
        WEAPON_TYPE_GRENADEGUN = 2,
        WEAPON_TYPE_GRAVITYGUN = 3,
        WEAPON_TYPE_MOUNTEDBALLGUN = 4,
        WEAPON_TYPE_TWEAKERGUN = 5,
        WEAPON_TYPE_MISSILEGUN = 6,
        WEAPON_TYPE_RAYCASTGUN = 7,
        WEAPON_TYPE_SPHEREGUN = 8,
        WEAPON_TYPE_STICKYGUN = 9,
        WEAPON_TYPE_NUM_TYPES = 10
    };
    enum KeyboardKey
    {
        KEY_F1 = 112,
        KEY_F2 = 113,
        KEY_F3 = 114,
        KEY_F4 = 115,
        KEY_F5 = 116,
        KEY_F6 = 117,
        KEY_F7 = 118,
        KEY_F8 = 119,
        KEY_F9 = 120,
        KEY_F10 = 121,
        KEY_F11 = 122,
        KEY_F12 = 123
    };
    hkUint8 m_type;  // +0x8
    char pad9[0x3];
    hkStringPtr m_name;       // +0xC
    hkUint8 m_uiKeyboardKey;  // +0x10 (KeyboardKey)
    char pad11[0x3];
    hkArray<void*> m_kListeners;  // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpFirstPersonGun[(sizeof(hkpFirstPersonGun) == 0x20) ? 1 : -1];
#endif
