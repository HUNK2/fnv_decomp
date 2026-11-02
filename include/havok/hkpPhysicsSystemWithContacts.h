// include/havok/hkpPhysicsSystemWithContacts.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x50.
#ifndef FNV_HAVOK_HKPPHYSICSSYSTEMWITHCONTACTS_H
#define FNV_HAVOK_HKPPHYSICSSYSTEMWITHCONTACTS_H

#include "hkBase.h"
#include "hkpPhysicsSystem.h"
class hkpSerializedAgentNnEntry;
#pragma pack(push, 1)
class hkpPhysicsSystemWithContacts : public hkpPhysicsSystem
{
  public:
    hkArray<hkpSerializedAgentNnEntry*> m_kSerializedAgentEntries;  // +0x44
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpPhysicsSystemWithContacts[(sizeof(hkpPhysicsSystemWithContacts) == 0x50) ? 1 : -1];
#endif
