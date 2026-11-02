// include/havok/hkpWorldCinfo.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0xF0.
#ifndef FNV_HAVOK_HKPWORLDCINFO_H
#define FNV_HAVOK_HKPWORLDCINFO_H

#include "hkBase.h"
#include "hkAabb.h"
#include "hkReferencedObject.h"
class hkWorldMemoryAvailableWatchDog;
class hkpCollisionFilter;
class hkpConvexListFilter;
#pragma pack(push, 1)
class hkpWorldCinfo : public hkReferencedObject
{
  public:
    enum SolverType
    {
        SOLVER_TYPE_INVALID = 0,
        SOLVER_TYPE_2ITERS_SOFT = 1,
        SOLVER_TYPE_2ITERS_MEDIUM = 2,
        SOLVER_TYPE_2ITERS_HARD = 3,
        SOLVER_TYPE_4ITERS_SOFT = 4,
        SOLVER_TYPE_4ITERS_MEDIUM = 5,
        SOLVER_TYPE_4ITERS_HARD = 6,
        SOLVER_TYPE_8ITERS_SOFT = 7,
        SOLVER_TYPE_8ITERS_MEDIUM = 8,
        SOLVER_TYPE_8ITERS_HARD = 9,
        SOLVER_TYPE_MAX_ID = 10
    };
    enum SimulationType
    {
        SIMULATION_TYPE_INVALID = 0,
        SIMULATION_TYPE_DISCRETE = 1,
        SIMULATION_TYPE_CONTINUOUS = 2,
        SIMULATION_TYPE_MULTITHREADED = 3
    };
    enum ContactPointGeneration
    {
        CONTACT_POINT_ACCEPT_ALWAYS = 0,
        CONTACT_POINT_REJECT_DUBIOUS = 1,
        CONTACT_POINT_REJECT_MANY = 2
    };
    enum BroadPhaseBorderBehaviour
    {
        BROADPHASE_BORDER_ASSERT = 0,
        BROADPHASE_BORDER_FIX_ENTITY = 1,
        BROADPHASE_BORDER_REMOVE_ENTITY = 2,
        BROADPHASE_BORDER_DO_NOTHING = 3
    };
    enum TreeUpdateType
    {
        REBUILD_ACTIVE = 0,
        REBUILD_ALL = 1
    };
    char pad8[0x8];
    hkVector4 m_kGravity;                      // +0x10
    hkInt32 m_iBroadPhaseQuerySize;            // +0x20
    hkReal m_fContactRestingVelocity;          // +0x24
    hkInt8 m_iBroadPhaseBorderBehaviour;       // +0x28 (BroadPhaseBorderBehaviour)
    hkBool m_bPostponeAndSortBorderCallbacks;  // +0x29
    char pad2A[0x6];
    hkAabb m_kBroadPhaseWorldAabb;                      // +0x30
    hkBool m_bUseKdTree;                                // +0x50
    hkBool m_bUseMultipleTree;                          // +0x51
    hkInt8 m_iTreeUpdateType;                           // +0x52 (TreeUpdateType)
    hkBool m_bAutoUpdateKdTree;                         // +0x53
    hkReal m_fCollisionTolerance;                       // +0x54
    hkpCollisionFilter* m_pCollisionFilter;             // +0x58
    hkpConvexListFilter* m_pConvexListCollisionFilter;            // +0x5C
    hkReal m_fExpectedMaxLinearVelocity;                // +0x60
    hkInt32 m_sizeOfToiEventQueue;                      // +0x64
    hkReal m_fExpectedMinPsiDeltaTime;                  // +0x68
    hkWorldMemoryAvailableWatchDog* m_pMemoryWatchDog;  // +0x6C
    hkInt32 m_iBroadPhaseNumMarkers;                    // +0x70
    hkInt8 m_iContactPointGeneration;                   // +0x74 (ContactPointGeneration)
    hkBool m_bAllowToSkipConfirmedCallbacks;            // +0x75
    char pad76[0x2];
    hkReal m_fSolverTau;                                // +0x78
    hkReal m_fSolverDamp;                               // +0x7C
    hkInt32 m_iSolverIterations;                        // +0x80
    hkInt32 m_iSolverMicrosteps;                        // +0x84
    hkReal m_fMaxConstraintViolation;                   // +0x88
    hkBool m_bForceCoherentConstraintOrderingInSolver;  // +0x8C
    char pad8D[0x3];
    hkReal m_fSnapCollisionToConvexEdgeThreshold;   // +0x90
    hkReal m_fSnapCollisionToConcaveEdgeThreshold;  // +0x94
    hkBool m_bEnableToiWeldRejection;               // +0x98
    hkBool m_bEnableDeprecatedWelding;              // +0x99
    char pad9A[0x2];
    hkReal m_fValue;                                       // +0x9C
    hkInt32 m_iValue;                                      // +0xA0
    hkUint8 m_uiDeactivationNumInactiveFramesSelectFlag0;  // +0xA4
    hkUint8 m_uiDeactivationNumInactiveFramesSelectFlag1;  // +0xA5
    hkUint8 m_ucDeactivationIntegrateCounter;              // +0xA6
    hkBool m_bActivateOnBodyTransformChange;               // +0xA7
    hkReal m_fDeactivationReferenceDistance;               // +0xA8
    hkReal m_fToiCollisionResponseRotateNormal;            // +0xAC
    hkInt32 m_iMaxSectorsPerMidphaseTask;                  // +0xB0
    hkBool m_bProcessToisMultithreaded;                    // +0xB4
    char padB5[0x3];
    hkInt32 m_iMaxSectorsPerNarrowphaseTask;      // +0xB8
    hkInt32 m_iMaxEntriesPerMidphaseToiTask;      // +0xBC
    hkReal m_fSimplifiedToiPenetrationThreshold;  // +0xC0
    hkReal m_fToiPenetrationThreshold;            // +0xC4
    hkReal m_fHigherToiPenetrationThreshold;      // +0xC8
    hkReal m_fForcedToiPenetrationThreshold;      // +0xCC
    hkBool m_bRigidBodyFlag;                      // +0xD0
    hkInt8 m_iMaxEntriesPerNarrowphaseToiTask;    // +0xD1 (SimulationType)
    hkBool m_bEnableSimulationIslands;            // +0xD2
    char padD3[0x1];
    hkUint32 m_uiMinDesiredIslandSize;       // +0xD4
    hkBool m_bProcessActionsInSingleThread;  // +0xD8
    hkBool m_bAllowUnconstrainedIslandJob;   // +0xD9
    char padDA[0x2];
    hkReal m_fFrameMarkerPsiSnap;      // +0xDC
    hkBool m_bFireCollisionCallbacks;  // +0xE0
    char padE1[0xF];
};
#pragma pack(pop)
typedef char fnv_hk_size_hkpWorldCinfo[(sizeof(hkpWorldCinfo) == 0xF0) ? 1 : -1];
#endif
