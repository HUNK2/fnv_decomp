// include/havok/hkClass.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x30.
#ifndef FNV_HAVOK_HKCLASS_H
#define FNV_HAVOK_HKCLASS_H

#include "hkBase.h"
class hkClassEnum;
class hkClassMember;
class hkCustomAttributes;
#pragma pack(push, 1)
class hkClass
{
  public:
    enum SignatureFlags
    {
        SIGNATURE_LOCAL = 1
    };
    enum FlagValues
    {
        FLAGS_NONE = 0,
        FLAGS_NOT_SERIALIZABLE = 1
    };
    char* m_name;                                     // +0x0
    hkClass* m_parent;                                // +0x4
    hkInt32 m_iObjectSize;                            // +0x8
    hkInt32 m_iNumImplementedInterfaces;              // +0xC
    hkSimpleArray<hkClassEnum> m_kDeclaredEnums;      // +0x10
    hkSimpleArray<hkClassMember> m_kDeclaredMembers;  // +0x18
    void* m_pDefaultObject;                           // +0x20
    hkCustomAttributes* m_pCustomAttributes;          // +0x24
    hkUint32 m_flags;                                 // +0x28 (FlagValues)
    hkInt32 m_iDescribedVersion;                      // +0x2C
};
#pragma pack(pop)
typedef char fnv_hk_size_hkClass[(sizeof(hkClass) == 0x30) ? 1 : -1];
#endif
