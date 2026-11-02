
// Fallout: New Vegas - original source reconstruction.
// Source unit: fallout/ai/movement/playermover.cpp
//
// PlayerMover extends the ActorMover base with player-specific movement
// state: a side-step vector, the current move mode, the pending turn
// direction bits and the minimum turn timer.
//
// Notes on declarations:
// - NiPoint3 carries its static ZERO (bsaudio/bsaudiodefines.h precedent);
//   the canonical task NiPoint3.h omits it, so the identical-layout local
//   declaration below stands in and the canonical header is blocked by its
//   own include guard (FNV_NIPOINT3_H).
//   minimal base below is sized to the PC subobject (0x88 bytes, pActor at
//   +0x28) as observed in the PC disassembly.
//   fallout/misc/saveload/bgsloadformbuffer.cpp declaration.

#include "playermover_layout.h"

#define FNV_NIPOINT3_H
#pragma pack(push, 4)
class NiPoint3
{
  public:
    static const NiPoint3 ZERO;
    float Length() const;
    NiPoint3 operator+(const NiPoint3&) const;
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiPoint3) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiPoint3, x) == 0x0);
FNV_STATIC_ASSERT(offsetof(NiPoint3, y) == 0x4);
FNV_STATIC_ASSERT(offsetof(NiPoint3, z) == 0x8);

#include "playermover_actor.h"
#include "playermover_decls.h"

class BGSLoadGameBuffer
{
  public:
    void ReadDataBlock(void* apData, unsigned int auSize);
};

class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
};

#pragma pack(push, 4)
class ActorMover
{
  public:
    void Revert(BGSLoadFormBuffer* apBuffer);
    void LoadGame(BGSLoadFormBuffer* apBuffer);
    void InitLoadGame(BGSLoadFormBuffer* apBuffer);

    unsigned char layoutPadding00[0x28];
    Actor* pActor;  // +0x28
    unsigned char layoutPadding2C[0x5C];
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ActorMover) == 0x88);
FNV_STATIC_ASSERT(offsetof(ActorMover, pActor) == 0x28);

#pragma pack(push, 4)
class PlayerMover : public ActorMover
{
  public:
    void Revert(BGSLoadFormBuffer* apBuffer);
    void LoadGame(BGSLoadFormBuffer* apBuffer);
    void InitLoadGame(BGSLoadFormBuffer* apBuffer);
    void SetMovementValue(float fTimeSinceScaleStart);
    void Update(float fTimeSinceScaleStart);
    void SetMoverMode(unsigned int auMode);
    void UpdatePlayerStatus(unsigned int auMode, bool abSet);
    void SetSideVec(const NiPoint3& arSideVec);
    void ClearMode(unsigned int auMode);

    NiPoint3 m_kSideVec;    // +0x88
    unsigned int ByteAndFlagState;  // +0x94
    unsigned int m_uiMode;  // +0x98
    float m_fValue;         // +0x9C
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PlayerMover) == 0xA0);
FNV_STATIC_ASSERT(offsetof(PlayerMover, m_kSideVec) == 0x88);
FNV_STATIC_ASSERT(offsetof(PlayerMover, ByteAndFlagState) == 0x94);
FNV_STATIC_ASSERT(offsetof(PlayerMover, m_uiMode) == 0x98);
FNV_STATIC_ASSERT(offsetof(PlayerMover, m_fValue) == 0x9C);

// @fnv 0x009ea6a0
void PlayerMover::Revert(BGSLoadFormBuffer* apBuffer)
{
    ActorMover::Revert(apBuffer);
    m_kSideVec = NiPoint3::ZERO;
    ByteAndFlagState = 0;
    m_fValue = -1.0f;
    m_uiMode = 0;
}

// @fnv 0x009ea610
void PlayerMover::LoadGame(BGSLoadFormBuffer* apBuffer)
{
    ActorMover::LoadGame(apBuffer);
    apBuffer->ReadDataBlock(&m_kSideVec, sizeof(m_kSideVec));
    apBuffer->ReadDataBlock(&ByteAndFlagState, sizeof(ByteAndFlagState));
    apBuffer->ReadDataBlock(&m_uiMode, sizeof(m_uiMode));
    apBuffer->ReadDataBlock(&m_fValue, sizeof(m_fValue));
}

// @fnv 0x009ea680
void PlayerMover::InitLoadGame(BGSLoadFormBuffer* apBuffer)
{
    ActorMover::InitLoadGame(apBuffer);
}

// @fnv 0x009ea2f0
void PlayerMover::SetMovementValue(float afDelta)
{
    if (m_fValue > 0.0)
    {
        m_fValue -= afDelta;
        if (!pActor->Unk_85())
            ByteAndFlagState |= m_uiMode;
    }
}

// @fnv 0x009e9e50
void PlayerMover::Update(float fTimeSinceScaleStart)
{
    NiPoint3 delta = NiPoint3::ZERO;
    Animation* animation = g_thePlayer->GetAnimation(false);
    if (!g_thePlayer->FUN_004eaf60())
    {
        Animation* firstPerson = g_thePlayer->GetAnimation(true);
        if (!animation || firstPerson->FUN_004301b0(1) == animation->FUN_004301b0(1))
            animation = firstPerson;
    }
    if (!g_thePlayer->PlaceAtPosition(delta))
    {
        if (animation)
        {
            if (g_thePlayer->FUN_0050d4a0())
                animation->GetMovementDelta(&delta, g_thePlayer, true, false);
            else
                animation->GetMovementDelta(&delta, g_thePlayer, false, true);
        }
        struct ControllerState
        {
            bhkCharacterController* controller;
            PlayerMoverControllerState* state;
        } character;
        character.controller = g_thePlayer->GetPhysicsCharacterController();
        character.state = character.controller ? &character.controller->state : 0;
        if (character.state && character.state->FUN_008b7320())
            delta = NiPoint3::ZERO;
        if ((ByteAndFlagState & 0xF) && !g_thePlayer->GetIsDying() && !g_thePlayer->FUN_0050d4a0())
        {
            switch (g_thePlayer->GetAnimAction())
            {
            default:
                break;
            }
            struct MovementLengths
            {
                float sideLength;
                float deltaLength;
            } lengths;
            lengths.sideLength = m_kSideVec.Length();
            lengths.deltaLength = delta.Length();
            if (lengths.sideLength > 0.0 && lengths.deltaLength > 0.0 && !(ByteAndFlagState & 0x40))
            {
                float sideX = m_kSideVec.x / lengths.sideLength;
                float sideY = m_kSideVec.y / lengths.sideLength;
                delta.x = sideX * lengths.deltaLength;
                delta.y = sideY * lengths.deltaLength;
            }
        }
        if ((ByteAndFlagState & 3) && (ByteAndFlagState & 0xC) && !g_thePlayer->GetIsDying())
        {
            switch (reinterpret_cast<PlayerMoverProcess*>(reinterpret_cast<PlayerQuestData*>(g_thePlayer)->GetLogDate())
                        ->GetKnockedState())
            {
            default:
                if (delta.y != 0.0)
                {
                    float displacement = m_kSideVec.x * fTimeSinceScaleStart * g_thePlayer->GetScale();
                    float angle = displacement / delta.y * 0.7853981852531433;
                    if (ByteAndFlagState & 4)
                        delta.x += -std::abs(cos(1.5707963705062866 - angle) * delta.y);
                    else if (ByteAndFlagState & 8)
                        delta.x += std::abs(cos(1.5707963705062866 - angle) * delta.y);
                    delta.y = cos(angle) * delta.y;
                }
            case 13:
            case 14:
                break;
            }
        }
    }
    if (g_thePlayer->FUN_0050d4a0())
    {
        NiPoint3 position =
            *reinterpret_cast<NiPoint3*>(reinterpret_cast<TESTopicInfo*>(g_thePlayer)->GetAddTopicList()) + delta;
        g_thePlayer->SetPos(&position);
    }
    else
    {
        g_thePlayer->Move(fTimeSinceScaleStart, &delta, g_thePlayer->GetActorStateFlags());
        struct GroundHeight
        {
            float height;
            TESObjectCELL* cell;
        } ground;
        ground.cell = reinterpret_cast<TESObjectCELL*>(reinterpret_cast<LowProcess*>(g_thePlayer)->GetTarget());
        if (ground.cell && !ground.cell->IsCellInterior())
        {
            ground.height = 0.0f;
            NiPoint3 position = *g_thePlayer->GetPos();
            if (ground.cell->GetLandscape()->GetLandHeightAtPosition(position, ground.height))
            {
                if (ground.height - position.z > 32.0)
                {
                    position.z = ground.height + 32.0;
                    g_thePlayer->SetPos(&position);
                }
            }
        }
    }
}

// @fnv 0x009ea3e0
void PlayerMover::SetMoverMode(unsigned int auMode)
{
    bool changed = (ByteAndFlagState & 0x400) != (auMode & 0x400);
    if (auMode & 0x30)
    {
        m_fValue = DAT_011cdf28.Float()->f;
        m_uiMode = auMode & 0x30;
    }
    ByteAndFlagState = auMode;
    if (changed && TESAnimGroup::IsAimAnimation(g_thePlayer->GetAnimation(false)->FUN_004301b0(4)))
    {
        struct AimAnimationState
        {
            ANIM_GROUP_ENUM group;
            unsigned short groupID;
            Animation* animation;
            NiControllerSequence* sequence;
        } aimState;
        aimState.group = g_thePlayer->IsAlert() ? (ANIM_GROUP_ENUM)20 : (ANIM_GROUP_ENUM)17;
        aimState.animation = g_thePlayer->GetAnimation(false);
        aimState.sequence = aimState.animation->GetControllerSequence(4);
        aimState.groupID = g_thePlayer->GetAnimGroup(aimState.group, 0, false, aimState.animation);
        if (!aimState.sequence ||
            aimState.groupID != reinterpret_cast<TESActorBaseData*>(aimState.sequence->GetAnimGroup())->FUN_0047d3b0())
            aimState.animation->BlendOut(4, false);
        aimState.animation = g_thePlayer->GetAnimation(true);
        aimState.sequence = aimState.animation->GetControllerSequence(4);
        aimState.groupID = g_thePlayer->GetAnimGroup(aimState.group, 0, false, aimState.animation);
        if (!aimState.sequence ||
            aimState.groupID != reinterpret_cast<TESActorBaseData*>(aimState.sequence->GetAnimGroup())->FUN_0047d3b0())
            aimState.animation->BlendOut(4, false);
    }
}

// @fnv 0x009ea360
void PlayerMover::UpdatePlayerStatus(unsigned int auMode, bool abSet)
{
    if (abSet)
        ByteAndFlagState |= auMode;
    else
        ByteAndFlagState &= ~auMode;
}

// Stores the given side vector into the player mover's side vector member.
// @fnv 0x009ea570
void PlayerMover::SetSideVec(const NiPoint3& arSideVec)
{
    m_kSideVec = arSideVec;
}

// @fnv 0x009ea3b0
void PlayerMover::ClearMode(unsigned int auMode)
{
    ByteAndFlagState &= ~auMode;
}

struct FUN_009e9de0_shell : PlayerMover
{
    void FUN_009e9de0(unsigned int auMode);
};

// @fnv 0x009e9de0
void FUN_009e9de0_shell::FUN_009e9de0(unsigned int auMode)
{
    ClearMode(auMode);
}

struct FUN_009e9dc0_shell : PlayerMover
{
    void FUN_009e9dc0(unsigned int auMode);
};

// @fnv 0x009e9dc0
void FUN_009e9dc0_shell::FUN_009e9dc0(unsigned int auMode)
{
    UpdatePlayerStatus(auMode, true);
}

struct FUN_009daef0
{
    virtual ~FUN_009daef0();
};

struct FUN_009e9e30_shell : FUN_009daef0
{
    void FUN_009e9e30();
};

// @fnv 0x009e9e30
void FUN_009e9e30_shell::FUN_009e9e30()
{
    *reinterpret_cast<int*>(this) = 0x0109297c;
    FUN_009daef0::~FUN_009daef0();
}

void __cdecl _Deallocate(void*);
struct FUN_009e9e00_shell : FUN_009e9e30_shell
{
    void* FUN_009e9e00(unsigned int);
};
// Calls FUN_009e9e30, then deallocates this object if auFlags has bit 0 set, and returns this.
// @fnv 0x009e9e00
void* FUN_009e9e00_shell::FUN_009e9e00(unsigned int auFlags)
{
    FUN_009e9e30();
    if (auFlags & 1)
        _Deallocate(this);
    return this;
}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
struct FUN_009df100_shell : PlayerMover
{
    void FUN_009df100(BGSSaveFormBuffer* apBuffer);
};
struct FUN_009ea5a0_shell : PlayerMover
{
    void FUN_009ea5a0(BGSSaveFormBuffer* apBuffer);
};
// @fnv 0x009ea5a0
void FUN_009ea5a0_shell::FUN_009ea5a0(BGSSaveFormBuffer* apBuffer)
{
    ((FUN_009df100_shell*)this)->FUN_009df100(apBuffer);
    apBuffer->SaveData(&m_kSideVec, 0xC, 0);
    apBuffer->SaveData(&ByteAndFlagState, 4, 0);
    apBuffer->SaveData(&m_uiMode, 4, 0);
    apBuffer->SaveData(&m_fValue, 4, 0);
}
