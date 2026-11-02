// fallout/ai/movement/actormover_fnv_decls.h: declares NiNode, ActorPathHandler, ActorMover
#ifndef FNV_ACTORMOVER_FNV_DECLS_H
#define FNV_ACTORMOVER_FNV_DECLS_H

#include "../../../../include/layout_support.h"
#include "../../../../include/Actor.h"
#include "../../../../include/BaseProcess.h"
#include "../../../../include/PlayerCharacter.h"
#include "NiPoint3.h"
extern "C" const NiPoint3 NiPoint3_ZERO;
class NiNode
{
  public:
    bool FUN_009dc530();
};
template <> class NiPointer<NiNode>
{
  public:
    NiNode* p;
    NiNode* operator->() const;
};
class ActorPathHandler
{
  public:
    enum PATH_HANDLER_RESULT
    {
        RESULT_NONE
    };
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual PATH_HANDLER_RESULT vfn_0c(float);
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual bool vfn_34();
};
class ActorMover
{
  public:
    void* vtable;
    NiPoint3 m_kLookAtTargetPosition, m_kPathingDelta;
    void* request;
    NiPointer<NiNode> m_pActorNode;
    ActorPathHandler* m_pPathHandler;
    unsigned char padding28[0x10];
    unsigned int m_uiMovementFlags, m_uiMovementMode;
    unsigned char middle[0x2c];
    int eState;
    bool bPathingFailed, m_bHasMovementData, m_bMovementComplete, m_bHasLookAtTarget;
    bool m_bMovementActive, m_bMovementStateFlag, m_bMovementPaused, m_bHasPathingDelta;
    void ClearMovementPath();
    void RefreshMovementState();
    void StopMoving();
    bool HasLookAtTarget();
    bool IsMovementActive();
    void ResetMovementData();
    unsigned int GetPreferredMoveModeType();
    unsigned int GetActorStateFlags();
    void RunProcedure();
    void UpdateMovement(float);
    void HandlePathingResult(ActorPathHandler::PATH_HANDLER_RESULT);
    bool GetPathingDelta(NiPoint3&);
    void UpdateMovementStatus(bool);
    bool HasActiveMovement();
    void ForceStopMoving();

  protected:
    void SetMovementMode(bool);

  private:
    void DebugOnStopMoving();
};
#endif
