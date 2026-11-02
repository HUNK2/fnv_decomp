// include/havok/hkpConstraintInstance.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x38.
#ifndef FNV_HAVOK_HKPCONSTRAINTINSTANCE_H
#define FNV_HAVOK_HKPCONSTRAINTINSTANCE_H

#include "hkBase.h"
#include "hkReferencedObject.h"
#include "hkpConstraintInstanceSmallArraySerializeOverrideType.h"
class hkpConstraintData;
class hkpEntity;
class hkpModifierConstraintAtom;
#pragma pack(push, 1)
class hkpConstraintInstance : public hkReferencedObject
{
  public:
    enum ConstraintPriority
    {
        PRIORITY_INVALID = 0,
        PRIORITY_PSI = 1,
        PRIORITY_SIMPLIFIED_TOI_UNUSED = 2,
        PRIORITY_TOI = 3,
        PRIORITY_TOI_HIGHER = 4,
        PRIORITY_TOI_FORCED = 5
    };
    enum InstanceType
    {
        TYPE_NORMAL = 0,
        TYPE_CHAIN = 1
    };
    enum AddReferences
    {
        DO_NOT_ADD_REFERENCES = 0,
        DO_ADD_REFERENCES = 1
    };
    enum CloningMode
    {
        CLONE_INSTANCES_ONLY = 0,
        CLONE_DATAS_WITH_MOTORS = 1,
        CLONE_FORCE_SHALLOW = 2
    };
    enum OnDestructionRemapInfo
    {
        ON_DESTRUCTION_REMAP = 0,
        ON_DESTRUCTION_REMOVE = 1,
        ON_DESTRUCTION_RESET_REMOVE = 2
    };
    void* m_pOwnerObject;                              // +0x8
    hkpConstraintData* m_data;                         // +0xC
    hkpModifierConstraintAtom* m_pConstraintModifier;  // +0x10
    hkpEntity* m_kActorEntries[2];                     // +0x14
    hkUint8 m_priority;                                // +0x1C (ConstraintPriority)
    hkBool m_bWantRuntime;                             // +0x1D
    hkUint8 m_eDestructionRemapInfo;                   // +0x1E (OnDestructionRemapInfo)
    char pad1F[0x1];
    hkpConstraintInstanceSmallArraySerializeOverrideType m_kListeners;  // +0x20
    hkStringPtr m_name;                                                 // +0x28
    hkUlong m_ulUserData;                                               // +0x2C
    void* m_pConstraintInternal;                                        // +0x30
    hkUint32 m_uiUniqueId;                                              // +0x34
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpConstraintInstance[(sizeof(hkpConstraintInstance) == 0x38) ? 1 : -1];
#endif
