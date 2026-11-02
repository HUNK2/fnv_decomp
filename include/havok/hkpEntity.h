// include/havok/hkpEntity.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x220.
#ifndef FNV_HAVOK_HKPENTITY_H
#define FNV_HAVOK_HKPENTITY_H

#include "hkBase.h"
#include "hkpEntitySmallArraySerializeOverrideType.h"
#include "hkpEntitySpuCollisionCallback.h"
#include "hkpMaterial.h"
#include "hkpMaxSizeMotion.h"
#include "hkpWorldObject.h"
class hkLocalFrame;
class hkpConstraintInstance;
class hkpEntityExtendedListeners;
#pragma pack(push, 1)
class hkpEntity : public hkpWorldObject
{
  public:
    enum SpuCollisionCallbackEventFilter
    {
        SPU_SEND_NONE = 0,
        SPU_SEND_CONTACT_POINT_ADDED = 1,
        SPU_SEND_CONTACT_POINT_PROCESS = 2,
        SPU_SEND_CONTACT_POINT_REMOVED = 4,
        SPU_SEND_CONTACT_POINT_ADDED_OR_PROCESS = 3
    };
    hkpMaterial m_iMaterialIndex;                                                 // +0x8C
    void* m_pEntityUserData;                                                      // +0x98
    hkReal m_fBulletSpread;                                                       // +0x9C
    void* m_pShape;                                                               // +0xA0
    hkUint32 m_uiFilterInfo;                                                      // +0xA4
    hkUint16 m_usStorageIndex;                                                    // +0xA8
    hkUint16 m_usNextProcessCallbackDelay;                                        // +0xAA
    hkpEntitySmallArraySerializeOverrideType m_eSmallArraySerializeOverrideType;  // +0xAC
    hkArray<hkpConstraintInstance*> m_kSlaveConstraints;                          // +0xB4
    hkArray<hkUint8> m_pByteBuffer;                                               // +0xC0
    void* m_pSimulationIsland;                                                    // +0xCC
    hkInt8 m_iAutoRemoveLevel;                                                    // +0xD0
    hkUint8 m_ucNumShapeKeysInContactPointProperties;                             // +0xD1
    hkUint8 m_ucResponseModifierFlags;                                            // +0xD2
    char padD3[0x1];
    hkUint32 m_uiUniqueId;                                         // +0xD4
    hkpEntitySpuCollisionCallback m_kSpuCollisionCallback;         // +0xD8
    hkpMaxSizeMotion m_pMotionState;                               // +0xE0
    hkpEntitySmallArraySerializeOverrideType m_kContactListeners;  // +0x200
    hkpEntitySmallArraySerializeOverrideType m_ppActions;          // +0x208
    hkLocalFrame* m_pLocalFrame;                                   // +0x210
    hkpEntityExtendedListeners* m_pExtendedListeners;              // +0x214
    char pad218[0x8];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpEntity[(sizeof(hkpEntity) == 0x220) ? 1 : -1];
#endif
