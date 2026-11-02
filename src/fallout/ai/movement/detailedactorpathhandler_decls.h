// fallout/ai/movement/detailedactorpathhandler_decls.h: declares NiPoint3, ActorMover, ActorPathHandler, DetailedActorPathHandler
#ifndef DETAILEDACTORPATHHANDLER_DECLS_H
#define DETAILEDACTORPATHHANDLER_DECLS_H


// Shared classes come from the canonical include/ headers (Actor, MobileObject, TESObjectREFR, TESForm,
// PlayerCharacter, BaseProcess, BSSimpleList). Two leaf types stay unit-local supersets of the canonical ones,
// same layout, because matched functions use members the canonical headers do not declare:
//   NiPoint3: static ZERO (?ZERO@NiPoint3@@2V1@B, 0x011f426c).
//   NiPointer: out-of-line operator= on incomplete T (PathingSolution/PathingRequest), operator-> (0x00559450).
#define NiPointer FNV_NiPointer_Canonical
#define NiPoint3 FNV_NiPoint3_Canonical
#include "layout_support.h"
#include "NiPoint3.h"
#undef NiPoint3
#undef NiPointer

#pragma pack(push, 4)
class NiPoint3
{
  public:
    float x;
    float y;
    float z;
    static const NiPoint3 ZERO;
};
FNV_STATIC_ASSERT(sizeof(NiPoint3) == sizeof(FNV_NiPoint3_Canonical));

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer<T>& operator=(T*);
    T* operator->() const;
    operator T*() const;
};
#pragma pack(pop)

#include "Actor.h"
#include "PlayerCharacter.h"
#include "BaseProcess.h"

#pragma pack(push, 4)
class PathingSolution;
class PathingRequest;
class TESTopicInfo;

class ActorMover
{
  public:
    unsigned int GetPreferredMoveModeType();
};

class ActorPathHandler
{
  public:
    virtual void V00();
    virtual void V01();
    virtual void V02();
    virtual void V03();
    virtual void V04();
    virtual void V05();
    virtual void V06();
    virtual void V07();
    virtual void V08();
    virtual void V09();
    virtual void V10();
    virtual void V11();
    virtual void V12();
    virtual bool CanTransition();
};

class DetailedActorPathHandler
{
  public:
    unsigned char pad00[0x04];
    Actor* pActor;  // +0x04 (canonical Actor)
    ActorMover* m_pActorMover;
    NiPointer<PathingSolution> pCurrentPathingSolution;
    NiPointer<PathingRequest> m_pPathingRequest;
    unsigned char pad14[0x08];
    NiPoint3 m_kPathVector1;
    NiPoint3 m_kPathVector2;
    NiPoint3 m_kPathVector3;
    NiPoint3 m_kActorPosition;
    NiPoint3 m_kPathVector4;
    BSSimpleList<TESTopicInfo*> ActorAvoidEntryList;
    unsigned int ByteAndFlagState;
    unsigned int m_uiPathPointIndex;
    float m_fPathValue1;
    float m_fPathValue2;
    float m_fSplineParameter;
    float m_fPathValue4;
    float m_fPathValue5;
    int m_iPathValue1;
    float m_fPathValue6;
    float m_fPathValue7;
    float m_fPathValue8;
    float m_fPathValue9;
    float m_fPathValue10;
    float m_fPathValue11;
    float m_fPathValue12;
    float m_fPathValue13;
    NiPoint3 m_kPathVector5;
    float m_fPathValue14;
    float m_fPathValue15;
    float m_fPathValue16;
    float m_fPathValue17;
    float m_fPathValue18;
    bool m_bHasPathingSolution;
    bool m_bPathingRequestPending;
    unsigned char padC2[0x02];
    float m_fElapsedTime;
    int eState;
    int m_iPathParameter1;
    int m_iPathParameter2;
    int m_iPathValue2;
    void* m_pPathTargetReference;
    bool m_bPathFlag1;
    bool m_bPathFlag2;
    bool m_bPathFlag3;
    bool m_bPathFlag4;
    bool m_bPathFlag5;
    bool m_bPathFlag6;
    bool m_bPathFlag7;
    unsigned char padE3[1];

    bool GetPathingDelta(NiPoint3& outDelta);
    bool TurnToAngle(float angle, bool keepActorHeading);
    bool StartTurningToAngle(float angle, bool keepActorHeading, bool ignoreInitialRotation);
    void SetInitialPathState();
    void TransitionFrom(ActorPathHandler* previous);
};
#pragma pack(pop)

#endif
