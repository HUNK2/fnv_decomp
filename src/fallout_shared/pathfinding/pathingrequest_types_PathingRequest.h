// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_PATHINGREQUEST_H
#define FNV_PATHINGREQUEST_H

#include "layout_support.h"
class Actor;
template <class T, unsigned int N> class BSSimpleArray;
#include "InventoryChanges.h"
#include "NiPoint3.h"
#include "NiRefObject.h"
#include "PathingLocation.h"
#include "layout_support.h"
class BGSLoadFormBuffer;
class PathingActorData;
class PathingAvoidNodeArray;
class PathingRequest;
enum PATHING_REQUEST_TYPE
{
    PATHING_REQUEST_STANDARD = 0
};
#pragma pack(push, 4)
class PathingActorData
{
  public:
    PathingActorData();
    TESActorBase* m_pActorBaseFormItem;                    // +0x0, 4 bytes
    InventoryChanges* m_pInventoryChangesValue;  // +0x4, 4 bytes
    bool m_bCanIgnoreLocks;                      // +0x8, 1 bytes
    unsigned char layoutPadding9[3];
    // PathingActorData
    // PathingActorData& __cdecl PathingActorData::*(const PathingActorData&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingActorData) == 12);
FNV_STATIC_ASSERT(offsetof(PathingActorData, m_pActorBaseFormItem) == 0);
FNV_STATIC_ASSERT(offsetof(PathingActorData, m_pInventoryChangesValue) == 4);
FNV_STATIC_ASSERT(offsetof(PathingActorData, m_bCanIgnoreLocks) == 8);
#pragma pack(push, 4)
class PathingInfo
{
  public:
    unsigned int m_uiRefCount;
    PathingInfo();
    virtual ~PathingInfo();
    virtual void DeleteThis();
};
class PathingRequestLocation : public PathingLocation
{
  public:
    PathingRequestLocation();
    ~PathingRequestLocation();
};
class PathingRequestCenter : public NiPoint3
{
  public:
    PathingRequestCenter();
};
class PathingRequestAvoidPointer
{
  public:
    PathingAvoidNodeArray* m_pObject;
    PathingRequestAvoidPointer(PathingAvoidNodeArray*);
    ~PathingRequestAvoidPointer();
};
class PathingRequest : public PathingInfo
{
  public:
    PathingRequest();
    void CopyTo(PathingRequest*);
    PathingLocation* GetOrigin();
    PathingLocation* FUN_006a9540();
    float GetActorRadius();
    float GetFloatAtOffset68();
    PathingActorData* FUN_006c9900();
    float GetCenterRadius();
    NiPoint3 FUN_006a7910();
    float GetTargetRadius();
    float GetSmoothingRandomness();
    BSSimpleArray<void*, 1024>* GetString();
    float GetGoalZDelta();
    void SetOrigin(PathingLocation*);
    void SetDestination(PathingLocation*);
    void SetActorRadius(float);
    void FUN_006d3ae0(float);
    void FUN_006e29b0(PathingActorData*);
    void SetCenterRadius(float);
    void FUN_006e2980(NiPoint3&, float);
    void SetSmoothingRandomness(float);
    void SetAvoidNodeArray(BSSimpleArray<void*, 1024>*);
    void SetGoalZDelta(float);

    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    static PathingRequest* CreateRequestForType(PATHING_REQUEST_TYPE);
    void LoadGame(BGSLoadFormBuffer* buffer);
    void InitLoadGame(BGSLoadFormBuffer* buffer);
    // base NiRefObject at +0x0, size 8
    Actor* pActor;                                        // +0x8, 4 bytes
    PathingRequestLocation Origin;                        // +0xC, 40 bytes
    PathingRequestLocation Destination;                   // +0x34, 40 bytes
    PathingActorData PathingActorState;                   // +0x5C, 12 bytes
    float m_fFirstValueAfterActorData;                    // +0x68, 4 bytes
    float m_fSecondValueAfterActorData;                   // +0x6C, 4 bytes
    float PathingActorSpatialData;                        // +0x70, 4 bytes
    float fWeaponSpread;                                  // +0x74, 4 bytes
    float m_fCenterRadius;                                // +0x78, 4 bytes
    PathingRequestCenter Center;                          // +0x7C, 12 bytes
    float m_fFloatAfterCenter;                           // +0x88, 4 bytes
    float m_fPathingRadius;                               // +0x8C, 4 bytes
    float m_fAvoidanceRadius;                             // +0x90, 4 bytes
    PathingRequestAvoidPointer m_pPathingAvoidNodeArray;  // +0x94, 4 bytes
    bool bCantOpenDoors;                                  // +0x98, 1 bytes
    bool bFaceTargetAtGoal;                               // +0x99, 1 bytes
    bool PathingOptions;                                  // +0x9A, 1 bytes
    bool bAllowIncompletePath;                            // +0x9B, 1 bytes
    bool m_bAllowDoorTraversal;                           // +0x9C, 1 bytes
    bool bCanSwim;                                        // +0x9D, 1 bytes
    bool bCanFly;                                         // +0x9E, 1 bytes
    bool m_bCanWalk;                                      // +0x9F, 1 bytes
    bool m_bCanJump;                                      // +0xA0, 1 bytes
    bool m_bCanClimb;                                     // +0xA1, 1 bytes
    bool m_bCanUseDoors;                                  // +0xA2, 1 bytes
    bool m_bCanRun;                                       // +0xA3, 1 bytes
    bool bIgnoreLocks;                                    // +0xA4, 1 bytes
    unsigned char layoutPaddingA5[3];
    int m_iRequestType;    // +0xA8, 4 bytes
    bool m_bCanOpenDoors;  // +0xAC, 1 bytes
    unsigned char layoutPaddingAD[3];
    // PathingRequest
    // void __cdecl PathingRequest::*()
    // PathingRequest& __cdecl PathingRequest::*(const PathingRequest&)
    // PathingRequest* __cdecl PathingRequest::*(PATHING_REQUEST_TYPE)
    // SetOrigin
    // GetOrigin
    // void __cdecl PathingRequest::*(const PathingLocation&)
    // void __cdecl PathingRequest::*()
    // GetDestination
    // void __cdecl PathingRequest::*(float)
    // float __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(float)
    // float __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(float)
    // float __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(float)
    // float __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(NiPoint3&, float)
    // float __cdecl PathingRequest::*()
    // NiPoint3 __cdecl PathingRequest::*()
    // SetActorLockData
    // GetActorLockData
    // void __cdecl PathingRequest::*(float)
    // bool __cdecl PathingRequest::*()
    // float __cdecl PathingRequest::*()
    // PathingAvoidNodeArray* __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(PathingAvoidNodeArray*)
    // float __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(float)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // void __cdecl PathingRequest::*(float)
    // void __cdecl PathingRequest::*()
    // bool __cdecl PathingRequest::*()
    // float __cdecl PathingRequest::*()
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // int __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(int)
    // bool __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*(bool)
    // void __cdecl PathingRequest::*(Actor*)
    // float __cdecl PathingRequest::*()
    // void __cdecl PathingRequest::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PathingRequest) == 176);
FNV_STATIC_ASSERT(offsetof(PathingRequest, pActor) == 8);
FNV_STATIC_ASSERT(offsetof(PathingRequest, Origin) == 12);
FNV_STATIC_ASSERT(offsetof(PathingRequest, Destination) == 52);
FNV_STATIC_ASSERT(offsetof(PathingRequest, PathingActorState) == 92);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_fFirstValueAfterActorData) == 104);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_fSecondValueAfterActorData) == 108);
FNV_STATIC_ASSERT(offsetof(PathingRequest, PathingActorSpatialData) == 112);
FNV_STATIC_ASSERT(offsetof(PathingRequest, fWeaponSpread) == 116);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_fCenterRadius) == 120);
FNV_STATIC_ASSERT(offsetof(PathingRequest, Center) == 124);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_fFloatAfterCenter) == 136);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_fPathingRadius) == 140);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_fAvoidanceRadius) == 144);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_pPathingAvoidNodeArray) == 148);
FNV_STATIC_ASSERT(offsetof(PathingRequest, bCantOpenDoors) == 152);
FNV_STATIC_ASSERT(offsetof(PathingRequest, bFaceTargetAtGoal) == 153);
FNV_STATIC_ASSERT(offsetof(PathingRequest, PathingOptions) == 154);
FNV_STATIC_ASSERT(offsetof(PathingRequest, bAllowIncompletePath) == 155);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_bAllowDoorTraversal) == 156);
FNV_STATIC_ASSERT(offsetof(PathingRequest, bCanSwim) == 157);
FNV_STATIC_ASSERT(offsetof(PathingRequest, bCanFly) == 158);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_bCanWalk) == 159);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_bCanJump) == 160);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_bCanClimb) == 161);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_bCanUseDoors) == 162);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_bCanRun) == 163);
FNV_STATIC_ASSERT(offsetof(PathingRequest, bIgnoreLocks) == 164);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_iRequestType) == 168);
FNV_STATIC_ASSERT(offsetof(PathingRequest, m_bCanOpenDoors) == 172);
#endif
