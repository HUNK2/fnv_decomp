// fallout/ai/highprocess.h: declares BaseProcess, HighProcess
#ifndef FNV_LUNA_HIGH_PROCESS_H
#define FNV_LUNA_HIGH_PROCESS_H


#include "highprocess_packet_decls.h"

class MobileObject;
class TESIdleForm;
class MuzzleFlash;
class DetectionEvent;
class LipSyncAnimation;
class DialogueItem;
class TESObjectREFR;
typedef int DIALOGUE_EMOTION;
class BaseProcess
{
  public:
    enum POSTANIM_ACTION
    {
        PostAnimNone = 0
    };
    enum FADE_STATE
    {
        FadeNone = 0
    };
};

class HighProcess
{
  public:
    unsigned char layoutGap_0[564];
    float m_kTenthUnshownMember;
    unsigned char layoutGap_238[144];
    float fSocialTalkTimer;
    unsigned char layoutGap_2cc[44];
    float m_fSocialTalkDelay;
    unsigned char layoutGap_2fc[16];
    TESObjectREFR* m_pSocialTalkTarget;
    float m_fReferenceTimer;
    SoundPlaybackHandle AudioPlaybackHandle[2];
    bool iProcessIndex;
    unsigned char layoutGap_32d[3];
    float m_fFirstProcessValue;
    float m_fSecondProcessValue;
    unsigned char layoutGap_338[4];
    float m_fAwarenessValue;
    unsigned char layoutGap_340[8];
    bool m_bAlertState;
    bool bDetectAlert;
    unsigned char layoutGap_34a[2];
    float fAwarePlayerTimer;
    TESIdleForm* m_pCurrentIdleForm;
    unsigned char layoutGap_354[16];
    bool bTalkingtoPC;
    unsigned char layoutGap_365[7];
    int m_iProcessState;
    MobileObject* m_pSavedReference;
    bool m_bSavedReferenceFlag;
    bool m_bDialogueFlag;
    unsigned char layoutGap_376[42];
    bool bMovementStoped;
    unsigned char layoutGap_3a1[24];
    bool iLocalState;
    unsigned char layoutGap_3ba[6];
    float m_fSecondLipSyncParameter;
    float m_fLipSyncTimer;
    float m_fLipSyncValue;
    LipSyncAnimation* pLipSyncAnimation;
    bool m_bLipSyncEnabled;
    bool m_bLipSyncPlaying;
    unsigned char layoutGap_3d2[2];
    MuzzleFlash* m_pMuzzleFlash;
    unsigned char layoutGap_3d8[4];
    DetectionEvent* m_pDetectionEvent;
    bool m_bTrackedReferenceFlag;
    unsigned char layoutGap_3e1[7];
    BaseProcess::FADE_STATE m_iSecondSerializedValue;
    unsigned char layoutGap_3ec[44];
    float fHeadTrackChangeTimer;
    TESObjectREFR* coordinate;
    bool m_bDetectionFlag;
    unsigned char layoutGap_421[3];
    BaseProcess::POSTANIM_ACTION ePostAnimAction;
    unsigned char layoutGap_428[24];
    float m_fSecondReferenceValue;
    bool iCount;
    bool pTargetObject;
    unsigned char layoutGap_446[14];
    DialogueItem* pSubtitleItem;
    unsigned char layoutGap_458[1];
    bool m_bSubtitleActive;

    void SetActorSoundHandle(ACTOR_SOUND_HANDLE index, SoundPlaybackHandle handle);
    SoundPlaybackHandle GetActorSoundHandle(ACTOR_SOUND_HANDLE index);
    void StopAllActorSounds();
    float GetProcessBlendAmount(void);
    BaseProcess::POSTANIM_ACTION GetPostAnimationAction(void);
    MobileObject* GetMobileObject(void);
    float GetProcessBlendWeight(void);
    bool IsDetectionEnabled(void);
    TESIdleForm* GetSelectedIdleForm(void);
    BaseProcess::FADE_STATE GetCurrentFadeState(void);
    void ClearPostAnimActions(void);
    MuzzleFlash* GetMuzzleFlash(void);
    float GetLightLevel(void);
    void SetLightLevel(float value);
    void SetFloatProperty(float value);
    float GetCurrentAlpha(void);
    float GetRadiationRate(void);
    void SetRadiationRate(float value);
    bool IsProcessStateActive(void);
    float GetControllerPhase(void);
    void UpdateActorLighting(float value);
    bool IsAsleep(void);
    float GetDetectionStrength(void);
    bool IsCurrentlyDetected(void);
    bool IsDetecting(void);
    bool HasAssignedAnimation(void);
    bool IsMovementStopped(void);
    float GetDetectionProgress(void);
    void SetDetectionLevel(float value);
    DIALOGUE_EMOTION GetCurrentDialogueEmotion(void);
    bool GetPlantedExplosive(void);
    float UpdateProcessTiming(void);
    DetectionEvent* FindDetectionEventForActor(int index);
    void SetEssentialFlag(bool value);
    void SetAnimationEnabled(bool value);
    float GetFirstProcessFloat(void);
    void SetCurrentDialogueItem(DialogueItem* value);
    void SetIdleForm(TESIdleForm* value);
    void ResetMovementState(void);
    void SetSubtitleActive(bool value);
    void SetActorProcessEnabled(bool value);
    LipSyncAnimation* GetLipSync(void);
    bool IsActorTalking(void);
    void SetDialogueState(bool value);
    void SetDialogueEmotion(DIALOGUE_EMOTION value);
    void AssignLipSyncAnimation(LipSyncAnimation* value);
    void SetLipSyncValue(float value);
    void SetTalkingState(bool value);
    void UpdateActorProcess(float value);
    TESObjectREFR* GetRelatedReference(void);
    TESObjectREFR* GetPreviousReference(void);
    bool HasCombatStarted(void);
    bool IsCombatTargetValid(void);
    void SetActorTargetReference(TESObjectREFR* value);
    bool CanFireWeapon(void);
    DialogueItem* GetCurrentDialogueItem(void);
    void SetCombatEnabled(bool value);
    void SetCombatAlerted(bool value);
};

// @fnv 0x008d9090
float HighProcess::GetProcessBlendAmount(void)
{
    return fAwarePlayerTimer;
}

// @fnv 0x004727d0
BaseProcess::POSTANIM_ACTION HighProcess::GetPostAnimationAction(void)
{
    return ePostAnimAction;
}

// @fnv 0x0051f510
MobileObject* HighProcess::GetMobileObject(void)
{
    return m_pSavedReference;
}

// @fnv 0x008d94b0
float HighProcess::GetProcessBlendWeight(void)
{
    return m_fLipSyncTimer;
}

// @fnv 0x008d9530
bool HighProcess::IsDetectionEnabled(void)
{
    return bTalkingtoPC;
}

// @fnv 0x006214b0
TESIdleForm* HighProcess::GetSelectedIdleForm(void)
{
    return m_pCurrentIdleForm;
}

// @fnv 0x008d9610
BaseProcess::FADE_STATE HighProcess::GetCurrentFadeState(void)
{
    return m_iSecondSerializedValue;
}

// @fnv 0x008d96b0
void HighProcess::ClearPostAnimActions(void)
{
    ePostAnimAction = BaseProcess::PostAnimNone;
}

// @fnv 0x008d9300
MuzzleFlash* HighProcess::GetMuzzleFlash(void)
{
    return m_pMuzzleFlash;
}

// @fnv 0x008d94f0
float HighProcess::GetLightLevel(void)
{
    return m_fLipSyncValue;
}

// @fnv 0x008d94d0
void HighProcess::SetLightLevel(float value)
{
    m_fLipSyncTimer = value;
}

// @fnv 0x008d9510
void HighProcess::SetFloatProperty(float value)
{
    m_fLipSyncValue = value;
}

// @fnv 0x008d95b0
float HighProcess::GetCurrentAlpha(void)
{
    return m_fSecondLipSyncParameter;
}

// @fnv 0x008d9010
float HighProcess::GetRadiationRate(void)
{
    return m_fSecondProcessValue;
}

// @fnv 0x008d9030
void HighProcess::SetRadiationRate(float value)
{
    m_fSecondProcessValue = value;
}

// @fnv 0x008d91e0
bool HighProcess::IsProcessStateActive(void)
{
    return iLocalState;
}

// @fnv 0x008d97a0
float HighProcess::GetControllerPhase(void)
{
    return m_fSecondReferenceValue > m_kTenthUnshownMember ? m_fSecondReferenceValue : m_kTenthUnshownMember;
}

// @fnv 0x008d90e0
void HighProcess::UpdateActorLighting(float value)
{
    m_fAwarenessValue = value;
}

// @fnv 0x008d8da0
bool HighProcess::IsAsleep(void)
{
    return m_bSubtitleActive;
}

// @fnv 0x008d93f0
float HighProcess::GetDetectionStrength(void)
{
    return m_fSocialTalkDelay;
}

// @fnv 0x008d9650
bool HighProcess::IsCurrentlyDetected(void)
{
    return pTargetObject;
}

// @fnv 0x008d8f10
bool HighProcess::IsDetecting(void)
{
    return iProcessIndex;
}

// @fnv 0x008d9050
bool HighProcess::HasAssignedAnimation(void)
{
    return m_bSavedReferenceFlag;
}

// @fnv 0x008d9180
bool HighProcess::IsMovementStopped(void)
{
    return bMovementStoped;
}

// @fnv 0x008d9740
float HighProcess::GetDetectionProgress(void)
{
    return fHeadTrackChangeTimer;
}

// @fnv 0x008d9760
void HighProcess::SetDetectionLevel(float value)
{
    fHeadTrackChangeTimer = value;
}

// @fnv 0x008d8de0
DIALOGUE_EMOTION HighProcess::GetCurrentDialogueEmotion(void)
{
    return m_iProcessState;
}

// @fnv 0x008d9720
bool HighProcess::GetPlantedExplosive(void)
{
    return iCount;
}

// @fnv 0x008d9100
float HighProcess::UpdateProcessTiming(void)
{
    return m_fAwarenessValue;
}

// @fnv 0x008d9390
DetectionEvent* HighProcess::FindDetectionEventForActor(int index)
{
    return m_pDetectionEvent;
}

// @fnv 0x008d8ff0
void HighProcess::SetEssentialFlag(bool value)
{
    bDetectAlert = value;
}

// @fnv 0x008d9070
void HighProcess::SetAnimationEnabled(bool value)
{
    m_bSavedReferenceFlag = value;
}

// @fnv 0x008d9320
float HighProcess::GetFirstProcessFloat(void)
{
    return fSocialTalkTimer;
}

// @fnv 0x008d9690
void HighProcess::SetCurrentDialogueItem(DialogueItem* value)
{
    pSubtitleItem = value;
}

// @fnv 0x008d9410
void HighProcess::SetIdleForm(TESIdleForm* value)
{
    m_pCurrentIdleForm = value;
}

// @fnv 0x008d91a0
void HighProcess::ResetMovementState(void)
{
    bMovementStoped = BaseProcess::PostAnimNone;
}

// @fnv 0x008d9160
void HighProcess::SetSubtitleActive(bool value)
{
    m_bDialogueFlag = value;
}

// @fnv 0x008d9550
void HighProcess::SetActorProcessEnabled(bool value)
{
    bTalkingtoPC = value;
}

// @fnv 0x008d9240
LipSyncAnimation* HighProcess::GetLipSync(void)
{
    return pLipSyncAnimation;
}

// @fnv 0x008d92a0
bool HighProcess::IsActorTalking(void)
{
    return m_bLipSyncPlaying;
}

// @fnv 0x008d9220
void HighProcess::SetDialogueState(bool value)
{
    m_bLipSyncEnabled = value;
}

// @fnv 0x008d8e00
void HighProcess::SetDialogueEmotion(DIALOGUE_EMOTION value)
{
    m_iProcessState = value;
}

// @fnv 0x008d9260
void HighProcess::AssignLipSyncAnimation(LipSyncAnimation* value)
{
    pLipSyncAnimation = value;
}

// @fnv 0x008d8f70
void HighProcess::SetLipSyncValue(float value)
{
    m_fReferenceTimer = value;
}

// @fnv 0x008d9280
void HighProcess::SetTalkingState(bool value)
{
    m_bLipSyncPlaying = value;
}

// @fnv 0x008d8fb0
void HighProcess::UpdateActorProcess(float value)
{
    m_fFirstProcessValue = value;
}

// @fnv 0x008d9830
TESObjectREFR* HighProcess::GetRelatedReference(void)
{
    return coordinate;
}

// @fnv 0x008d8e20
TESObjectREFR* HighProcess::GetPreviousReference(void)
{
    return m_pSocialTalkTarget;
}

// @fnv 0x008d9430
bool HighProcess::HasCombatStarted(void)
{
    return m_bTrackedReferenceFlag;
}

// @fnv 0x008d9810
bool HighProcess::IsCombatTargetValid(void)
{
    return m_bDetectionFlag;
}

// @fnv 0x008d8e40
void HighProcess::SetActorTargetReference(TESObjectREFR* value)
{
    m_pSocialTalkTarget = value;
}

// @fnv 0x008d92c0
bool HighProcess::CanFireWeapon(void)
{
    return m_bAlertState;
}

// @fnv 0x008d9670
DialogueItem* HighProcess::GetCurrentDialogueItem(void)
{
    return pSubtitleItem;
}

// @fnv 0x008d8dc0
void HighProcess::SetCombatEnabled(bool value)
{
    m_bSubtitleActive = value;
}

// @fnv 0x008d8f30
void HighProcess::SetCombatAlerted(bool value)
{
    iProcessIndex = value;
}

// @fnv 0x008d9570
void HighProcess::StopAllActorSounds()
{
    m_fSecondLipSyncParameter = originalRuntimeFloatSetting244.Float()->f;
}

// @fnv 0x008d8e60
SoundPlaybackHandle HighProcess::GetActorSoundHandle(ACTOR_SOUND_HANDLE index)
{
    return AudioPlaybackHandle[index];
}

// @fnv 0x008d8ea0
void HighProcess::SetActorSoundHandle(ACTOR_SOUND_HANDLE index, SoundPlaybackHandle handle)
{
    AudioPlaybackHandle[index] = handle;
}

#endif
