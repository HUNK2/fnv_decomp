// fallout/misc/saveload/bgsloadgamesubbuffer_decls.h: declares BGSLoadGameBuffer, BGSLoadFormBuffer, MobileObject, MiddleHighProcess, QuantityData and more
#ifndef BGSLOADGAMESUBBUFFER_DECLS_H
#define BGSLOADGAMESUBBUFFER_DECLS_H


class BGSLoadGameBuffer
{
  public:
    void** m_ppVirtualMethodTable;
    ~BGSLoadGameBuffer();
    char* ReadTypedData(char* value);
    char* GetCombinedValue();
};

class BGSLoadFormBuffer
{
  public:
    void** m_ppVirtualMethodTable;
    char padding[44];
    BGSLoadFormBuffer();
    void FUN_008a8150(unsigned char);
    void SetBuffer(char*, unsigned int, unsigned int);
    int ReadElementCount();
};

class TESObjectREFR;
class BSTreeNode;

template <> class NiPointer<TESForm>
{
  public:
    TESForm* m_pObject;
    operator TESForm*() const;
};

template <class T1, class T2> class LockFreeMap
{
  public:
    struct ThreadSafeHashTableNode;
    template <class BoundingVolumeNode> class ThreadSafePointer : public NiPointer<TESForm>
    {
      public:
        ThreadSafePointer();
    };
};

class TargetDoorController;
class bhkCharacterController;

class MobileObject
{
  public:
    bhkCharacterController* GetPhysicsCharacterController();
};

class MiddleHighProcess
{
  public:
    TargetDoorController* GetObjectToAcquire();
    void ReadAnimationState(BGSLoadFormBuffer* buffer);
    char _pdbpad_1[199];
    char DeadDetectList_padc7_padc7_padc7[8];
    char RefListChairBed_padcf_padcf_padcf[8];
    float m_kNinthUnshownMember;
    float m_kEighthUnshownMember;
    bool m_bPackageStateFlag2;
    bool m_bPackageStateFlag;
    bool m_bPackageStateFlag3;
    bool m_bPackageStateFlag4;
    char PackageReference[24];
    char m_kPackageTargetPosition[12];
    int m_ePackageObjectType;
    void* m_pPackageIdleForm;
    bool m_kSecondUnshownMember;
    char _pdbpad_111[3];
    void* pWeapon;
    void* pAmmo;
    char m_pQueuedWeaponFile[4];
    char m_pWeaponData[4];
    bool m_bFirstWeaponFlag;
    bool m_bSecondWeaponFlag;
    bool m_bThirdWeaponFlag;
    bool m_bFourthWeaponFlag;
    bool m_bFifthWeaponFlag;
    bool m_bSixthWeaponFlag;
    bool m_bSeventhWeaponFlag;
    char _pdbpad_12b[1];
    void* m_pActorNode;
    void* m_pActorObject;
    bool m_bFirstActorFlag;
    bool m_bAdditionalActorFlag;
    char _pdbpad_136[2];
    char m_pCharacterController[4];
    char m_cCharacterControllerState;
    unsigned char m_ucFurnitureInteractionState;
    char _pdbpad_13e[2];
    void* m_pFurnitureReference;
    unsigned char m_ucFurnitureMarkerIndex;
    char _pdbpad_145[3];
    char FurnitureMarker[16];
    void* m_pCombatTarget;
    void* m_pEquippedWeapon;
    void* m_pFirstMagicItem;
    void* m_pSecondMagicItem;
    bool m_bWeaponOut;
    char _pdbpad_169[3];
    void* m_pEffectShader;
    float m_fFirstEffectShaderValue;
    float m_fSecondEffectShaderValue;
    void* m_pFaceGenAnimationData;
    bool m_bFirstFaceGenFlag;
    bool m_kSixthUnshownMember;
    bool m_bThirdFaceGenFlag;
    bool m_kSeventhUnshownMember;
    bool m_kFifthUnshownMember;
    char _pdbpad_181[3];
    unsigned int m_uiAnimationStateFlags;
    bool m_bAiming;
    bool m_bAimStateFlag;
    bool m_bCombatStateFlag;
    bool m_bFourthStateFlag;
    unsigned char m_ucProcessState;
    bool m_bEquipStateFlag;
    char _pdbpad_18e[2];
    int m_iIdleState;
    void* m_pCurrentIdleForm;
    float m_fIdleAnimationTime;
    bool m_kThirdUnshownMember;
    bool m_kFourthUnshownMember;
    char _pdbpad_19e[2];
    void* m_pLipSyncAnimation;
    unsigned int m_uiLipSyncState;
    int m_iProjectileCount;
    void* m_pArrowProjectileList;
    char m_kDeferredHideLimbList[8];
    void* m_pActiveEffectList;
    void* m_pMagicTarget;
    void* pCurrentAnimation;
    char m_apAnimGroupSequences[12];
    float m_fAnimationTime;
    float m_fAnimationSpeed;
    unsigned char m_ucAnimationState;
    bool m_bFirstAnimationFlag;
    bool m_bAnimationStateFlag;
    char _pdbpad_1db[1];
    char m_apBodyPartNodes[60];
    void* m_pFirstAttachedObject;
    void* m_pSecondAttachedObject;
    char m_pLightingProperty[4];
    void* m_pBound;
    bool m_kFieldAfterWeaponFlags;
    char _pdbpad_229[1];
    short m_sBoundDataValue;
    unsigned int m_kEleventhUnshownMember;
    void* m_pkPaddedFloatRecordList;
    float m_kTenthUnshownMember;
    float m_fFirstFaceGenValue;
    float m_fSecondFaceGenValue;
    void* m_pData;
    int m_iFaceGenNodeIndex;
    void* m_pFirstFaceGenNode;
    void* m_pSecondFaceGenNode;
    void* m_pFaceGenObject;
    void* m_pAdditionalFaceGenData;
    unsigned int m_uiFaceGenDataFlags;
};

class QuantityData
{
  public:
    void SetQuantity(unsigned int quantity);
};

class ActorPackageContext
{
  public:
    void AddToProcedureIndex(int index);
};

class TESRecipe
{
  public:
    void SetSkill(int);
};
extern unsigned int __cdecl ReadEncodedInteger(char*, unsigned int&);
class Animation
{
  public:
    void Load(BGSLoadFormBuffer*);
};
class TESBoundObject;
class NiAVObject;
class ExtraDataList
{
  public:
    void SetSavedAnimation(char*);
    void SetSavedHavokData(char*);
};
class TESObjectREFR : public TESForm
{
  public:
    NiAVObject* Get3DSimple();
    ExtraDataList* GetExtraData();
    TESBoundObject* GetObjectReference();
    void RestoreAnimation(BGSLoadFormBuffer*);
};
class PlayerCharacter : public TESObjectREFR
{
  public:
    Animation* GetAnimation(bool);
};
extern PlayerCharacter* g_thePlayer;
template <> class NiTPointerMap<unsigned int, unsigned int>
{
  public:
    void RemoveAll();
};
class BGSReconstructFormsInAllFilesMap
{
  public:
    void* GetFirstPos();
};
class QueuedMap
{
  public:
    void GetNextEntry(void*&, TESForm*&,
                      LockFreeMap<TESObjectREFR*, BSTreeNode*>::ThreadSafePointer<
                          LockFreeMap<TESObjectREFR*, BSTreeNode*>::ThreadSafeHashTableNode>&);
};
extern void __cdecl LogWarning(const char* message, ...);

#endif
