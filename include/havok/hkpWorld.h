// include/havok/hkpWorld.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x350.
#ifndef FNV_HAVOK_HKPWORLD_H
#define FNV_HAVOK_HKPWORLD_H

#include "hkBase.h"
#include "hkMultiThreadCheck.h"
#include "hkReferencedObject.h"
class hkpPhantom;
class hkpSimulation;
#pragma pack(push, 1)
class hkpWorld : public hkReferencedObject
{
  public:
    enum ReintegrationRecollideMode
    {
        RR_MODE_REINTEGRATE = 1,
        RR_MODE_RECOLLIDE_BROADPHASE = 2,
        RR_MODE_RECOLLIDE_NARROWPHASE = 4,
        RR_MODE_ALL = 7
    };
    enum MtAccessChecking
    {
        MT_ACCESS_CHECKING_ENABLED = 0,
        MT_ACCESS_CHECKING_DISABLED = 1
    };
    enum CachedAabbUpdate
    {
        SHIFT_BROADPHASE_UPDATE_ENTITY_AABBS = 0,
        SHIFT_BROADPHASE_IGNORE_ENTITY_AABBS = 1
    };
    hkpSimulation* m_pSimulation;  // +0x8
    char padC[0x4];
    hkVector4 m_kGravity;                         // +0x10
    void* m_pFixedIsland;                         // +0x20
    void* m_pFixedRigidBody;                      // +0x24
    hkArray<void*> m_kActiveSimulationIslands;    // +0x28
    hkArray<void*> m_kInactiveSimulationIslands;  // +0x34
    hkArray<void*> m_kDirtySimulationIslands;     // +0x40
    void* m_pMaintenanceManager;                  // +0x4C
    void* m_pMemoryWatchDog;                      // +0x50
    hkBool m_bAssertOnRunningOutOfSolverMemory;   // +0x54
    char pad55[0x3];
    void* m_pJobSemaphore;   // +0x58
    void* m_pKdTreeManager;  // +0x5C
    hkBool m_bUseKdTree;     // +0x60
    char pad61[0x3];
    void* m_pBroadPhaseDispatcher;                      // +0x64
    void* m_pPhantomBroadPhaseListener;                 // +0x68
    void* m_pEntityEntityBroadPhaseListener;            // +0x6C
    void* m_pBroadPhaseBorderListener;                  // +0x70
    void* m_pMultithreadedSimulationJobData;            // +0x74
    void* m_pCollisionInput;                            // +0x78
    void* m_pCollisionFilter;                           // +0x7C
    void* m_pDispatcher;                                // +0x80
    void* m_pConvexListCollisionFilter;                           // +0x84
    void* m_pPendingOperations;                         // +0x88
    hkInt32 m_iPendingOperationCount;                   // +0x8C
    hkInt32 m_iQueuedOperationCount;                    // +0x90
    hkInt32 m_iCriticalOperationsLockCount;             // +0x94
    hkInt32 m_iCriticalOperationsLockCountForPhantoms;  // +0x98
    hkBool m_bBlockExecutingPendingOperations;          // +0x9C
    hkBool m_bBlockExecutingPendingOperationQueues;     // +0x9D
    char pad9E[0x2];
    void* m_pPendingOperationQueues;         // +0xA0
    hkInt32 m_iPendingOperationQueueCount;   // +0xA4
    hkMultiThreadCheck m_kMultiThreadCheck;  // +0xA8
    hkBool m_bProcessActionsInSingleThread;  // +0xB0
    hkBool m_bAllowUnconstrainedIslandJob;   // +0xB1
    char padB2[0x2];
    hkUint32 m_uiMinDesiredIslandSize;         // +0xB4
    void* m_pModifyConstraintCriticalSection;  // +0xB8
    hkInt32 m_iIsLocked;                       // +0xBC
    void* m_pIslandDirtyListCriticalSection;   // +0xC0
    void* m_pPropertyMasterLock;               // +0xC4
    hkBool m_bWantSimulationIslands;           // +0xC8
    char padC9[0x3];
    hkReal m_fSnapCollisionToConvexEdgeThreshold;   // +0xCC
    hkReal m_fSnapCollisionToConcaveEdgeThreshold;  // +0xD0
    hkBool m_bEnableToiWeldRejection;               // +0xD4
    hkBool m_bWantDeactivation;                     // +0xD5
    hkBool m_bActivateOnBodyTransformChange;        // +0xD6
    char padD7[0x1];
    hkReal m_fDeactivationReferenceDistance;     // +0xD8
    hkReal m_fToiCollisionResponseRotateNormal;  // +0xDC
    hkInt32 m_iMaxSectorsPerMidphaseTask;        // +0xE0
    hkBool m_bProcessToisMultithreaded;          // +0xE4
    char padE5[0x3];
    hkInt32 m_iMaxSectorsPerNarrowphaseTask;                 // +0xE8
    hkInt32 m_iMaxEntriesPerMidphaseToiTask;                 // +0xEC
    hkInt32 m_iMaxEntriesPerNarrowphaseToiTask;              // +0xF0
    hkReal m_fSimplifiedToiPenetrationThreshold;             // +0xF4
    hkReal m_fToiPenetrationThreshold;                       // +0xF8
    hkReal m_fHigherToiPenetrationThreshold;                 // +0xFC
    hkReal m_fForcedToiPenetrationThreshold;                 // +0x100
    hkUint32 m_uiLastEntityUid;                              // +0x104
    hkUint32 m_uiLastIslandUid;                              // +0x108
    hkUint32 m_uiLastConstraintUid;                          // +0x10C
    hkArray<hkpPhantom*> m_kPhantoms;                        // +0x110
    hkArray<void*> m_kActionListeners;                       // +0x11C
    hkArray<void*> m_kEntityListenerArray;                   // +0x128
    hkArray<void*> m_kPhantomListeners;                      // +0x134
    hkArray<void*> m_kConstraintListeners;                   // +0x140
    hkArray<void*> m_kWorldDeletionListeners;                // +0x14C
    hkArray<void*> m_kIslandActivationListeners;             // +0x158
    hkArray<void*> m_kWorldPostSimulationListeners;          // +0x164
    hkArray<void*> m_kWorldPostIntegrateListeners;           // +0x170
    hkArray<void*> m_kWorldPostCollideListeners;             // +0x17C
    hkArray<void*> m_kIslandPostIntegrateListeners;          // +0x188
    hkArray<void*> m_kIslandPostCollideListeners;            // +0x194
    hkArray<void*> m_kContactListeners;                      // +0x1A0
    hkArray<void*> m_kContactImpulseLimitBreachedListeners;  // +0x1AC
    void* m_pViolatedConstraintArray;                        // +0x1B8
    void* m_pBroadPhaseBorder;                               // +0x1BC
    void* m_pBroadPhaseQueryCache;                           // +0x1C0
    void* m_pBroadPhaseRegionData;                           // +0x1C4
    char pad1C8[0x148];
    hkVector4 m_kBroadPhaseAabb[2];    // +0x310
    hkInt32 m_iBroadPhaseNumMarkers;   // +0x330
    hkInt32 m_sizeOfToiEventQueue;     // +0x334
    hkInt32 m_iBroadPhaseQuerySize;    // +0x338
    hkInt32 m_iBroadPhaseNumObjects;   // +0x33C
    hkInt8 m_iContactPointGeneration;  // +0x340
    char pad341[0xF];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpWorld[(sizeof(hkpWorld) == 0x350) ? 1 : -1];
#endif
