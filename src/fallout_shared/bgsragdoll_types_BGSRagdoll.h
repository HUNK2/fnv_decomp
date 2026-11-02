// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSRAGDOLL_H
#define FNV_BGSRAGDOLL_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "bgsragdoll_form.h"
#include "layout_support.h"
class BGSBodyPartData;
class BGSRagdoll;
class BSFileEntry;
class FootIK_DATA;
class FootIK_DATA__FootIKSystem_DATA;
class FootIK_DATA__FootIK_Leg_DATA;
class GrabIK_DATA;
class GrabIK_DATA__GrabIK_Arm_DATA;
class LookIK_DATA;
class LookIK_DATA__LookIK_Head_DATA;
class RagdollFeedbackProfile;
class PoseMatching_DATA__PoseMatching_System_DATA;
class RagdollAnimationData;
class RagdollFeedbackData__RagdollFeedbackSystemData;
class SaveMetadata;
class TESModel;
class FileEntryList;
class TESActorBase;
class TESObjectREFR;
class SandboxProcedureData;
template <class T> class NiTNewInterface
{
};
template <class T, class Allocator> class NiTArray
{
  public:
    T& GetAt(unsigned int index);
};
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int GetSize();
    T& GetAt(int index);
    void Clear(bool freeBuffer);
    void SetSize(unsigned int size, bool keep);
};
#pragma pack(push, 4)
class FileEntryList
{
  public:
    unsigned char m_ucFileEntryCount;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSFileEntry** m_ppFileEntries;  // +0x4, 4 bytes
    // void __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*()
    // bool __cdecl FileEntryList::*()
    // void __cdecl FileEntryList::*(CHUNK_ID, const char*)
    // void __cdecl FileEntryList::*(TESFile*, TESForm*, const char*)
    // void __cdecl FileEntryList::*(FileEntryList*)
    // unsigned char __cdecl FileEntryList::*()
    // BSFileEntry** __cdecl FileEntryList::*()
    // void* __cdecl FileEntryList::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FileEntryList) == 8);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ucFileEntryCount) == 0);
FNV_STATIC_ASSERT(offsetof(FileEntryList, m_ppFileEntries) == 4);
#pragma pack(push, 4)
class TESModel : public BaseFormComponent
{
  public:
    // base BaseFormComponent at +0x0, size 4
    BSStringT<char> m_kModelFilePath;  // +0x4, 8 bytes
    FileEntryList m_pTextureSwapData;  // +0xC, 8 bytes
    unsigned char cFlags;              // +0x14, 1 bytes
    unsigned char layoutPadding15[3];
    static void LoadModelData(TESModel* model, TESFile* file);
    // TESModel
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*()
    // void __cdecl TESModel::*(CHUNK_ID, CHUNK_ID)
    // void __cdecl TESModel::*(BaseFormComponent*)
    // bool __cdecl TESModel::*(BaseFormComponent*)
    // void __cdecl TESModel::*(CHUNK_ID)
    // GetModelLength
    // bool __cdecl TESModel::*(CHUNK_ID)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // void __cdecl TESModel::*(TESModel*, TESFile*)
    // bool __cdecl TESModel::*()
    // char __cdecl TESModel::*()
    // void __cdecl TESModel::*(char)
    // bool __cdecl TESModel::*()
    // void __cdecl TESModel::*(bool)
    // unsigned int __cdecl TESModel::*()
    // void __cdecl TESModel::*(unsigned int)
    // bool __cdecl TESModel::*()
    // FileEntryList* __cdecl TESModel::*()
    // TESModel& __cdecl TESModel::*(const TESModel&)
    // void __cdecl TESModel::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESModel) == 24);
FNV_STATIC_ASSERT(offsetof(TESModel, m_kModelFilePath) == 4);
FNV_STATIC_ASSERT(offsetof(TESModel, m_pTextureSwapData) == 12);
FNV_STATIC_ASSERT(offsetof(TESModel, cFlags) == 20);
#pragma pack(push, 2)
class SaveMetadata
{
  public:
    union
    {
        void* layoutPointer;
        struct
        {
            unsigned short m_usFootIndexCount;    // +0x0, 2 bytes
            unsigned short m_usLegDataCount;      // +0x2, 2 bytes
            unsigned short m_usHeadDataCount;     // +0x4, 2 bytes
            unsigned short m_usGrabArmDataCount;  // +0x6, 2 bytes
            bool m_bRagdollAnimationEnabled;      // +0x8, 1 bytes
            bool m_bFootIKEnabled;                // +0x9, 1 bytes
            bool m_bLookIKEnabled;                // +0xA, 1 bytes
            bool m_bGrabIKEnabled;                // +0xB, 1 bytes
            bool m_bRagdollFeedbackEnabled;       // +0xC, 1 bytes
            unsigned char layoutPaddingD[1];
        };
    };
    void SwapEndianFourShorts();
    // void __cdecl SaveMetadata::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SaveMetadata) == 14);
FNV_STATIC_ASSERT(offsetof(SaveMetadata, m_usFootIndexCount) == 0);
FNV_STATIC_ASSERT(offsetof(SaveMetadata, m_usLegDataCount) == 2);
FNV_STATIC_ASSERT(offsetof(SaveMetadata, m_usHeadDataCount) == 4);
FNV_STATIC_ASSERT(offsetof(SaveMetadata, m_usGrabArmDataCount) == 6);
FNV_STATIC_ASSERT(offsetof(SaveMetadata, m_bRagdollAnimationEnabled) == 8);
FNV_STATIC_ASSERT(offsetof(SaveMetadata, m_bFootIKEnabled) == 9);
FNV_STATIC_ASSERT(offsetof(SaveMetadata, m_bLookIKEnabled) == 10);
FNV_STATIC_ASSERT(offsetof(SaveMetadata, m_bGrabIKEnabled) == 11);
FNV_STATIC_ASSERT(offsetof(SaveMetadata, m_bRagdollFeedbackEnabled) == 12);
#pragma pack(push, 4)
class RagdollFeedbackData__RagdollFeedbackSystemData
{
  public:
    float m_fFeedbackParameter1;             // +0x0, 4 bytes
    float fHeirGain;                         // +0x4, 4 bytes
    float m_fFeedbackParameter3;             // +0x8, 4 bytes
    float fVelGain;                          // +0xC, 4 bytes
    float m_fFeedbackParameter5;             // +0x10, 4 bytes
    float fSnapGain;                         // +0x14, 4 bytes
    float m_fFeedbackParameter7;             // +0x18, 4 bytes
    float m_fFeedbackParameter8;             // +0x1C, 4 bytes
    float m_fFeedbackParameter9;             // +0x20, 4 bytes
    float m_fFeedbackParameter10;            // +0x24, 4 bytes
    float m_fFeedbackParameter11;            // +0x28, 4 bytes
    float m_fFeedbackParameter12;            // +0x2C, 4 bytes
    float m_fFeedbackParameter13;            // +0x30, 4 bytes
    unsigned int ThreeFloatsAndTwoIntegers;  // +0x34, 4 bytes
    unsigned int m_uiFeedbackParameter14;    // +0x38, 4 bytes
    void FUN_005ee380();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RagdollFeedbackData__RagdollFeedbackSystemData) == 60);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, m_fFeedbackParameter1) == 0);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, fHeirGain) == 4);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, m_fFeedbackParameter3) == 8);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, fVelGain) == 12);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, m_fFeedbackParameter5) == 16);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, fSnapGain) == 20);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, m_fFeedbackParameter7) == 24);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, m_fFeedbackParameter8) == 28);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, m_fFeedbackParameter9) == 32);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, m_fFeedbackParameter10) == 36);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, m_fFeedbackParameter11) == 40);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, m_fFeedbackParameter12) == 44);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, m_fFeedbackParameter13) == 48);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, ThreeFloatsAndTwoIntegers) == 52);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackData__RagdollFeedbackSystemData, m_uiFeedbackParameter14) == 56);
#pragma pack(push, 4)
class RagdollAnimationData
{
  public:
    RagdollAnimationData();
    ~RagdollAnimationData();
    bool bEnabled;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    RagdollFeedbackData__RagdollFeedbackSystemData m_kRagdollFeedbackData;  // +0x4, 60 bytes
    BSSimpleArray<short, 1024> m_kFootIndices;                              // +0x40, 16 bytes
    // RagdollAnimationData
    // bool __cdecl RagdollAnimationData::*(const RagdollAnimationData&)
    // void __cdecl RagdollAnimationData::*(const RagdollAnimationData&)
    // void __cdecl RagdollAnimationData::*()
    // RagdollAnimationData& __cdecl RagdollAnimationData::*(const RagdollAnimationData&)
    // void* __cdecl RagdollAnimationData::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RagdollAnimationData) == 80);
FNV_STATIC_ASSERT(offsetof(RagdollAnimationData, bEnabled) == 0);
FNV_STATIC_ASSERT(offsetof(RagdollAnimationData, m_kRagdollFeedbackData) == 4);
FNV_STATIC_ASSERT(offsetof(RagdollAnimationData, m_kFootIndices) == 64);
#pragma pack(push, 4)
class FootIK_DATA__FootIKSystem_DATA
{
  public:
    float fOnOffGain;                  // +0x0, 4 bytes
    float fGroundAscendingGain;        // +0x4, 4 bytes
    float fGroundDescendingGain;       // +0x8, 4 bytes
    float fFootRaisedGain;             // +0xC, 4 bytes
    float fFootPlantedGain;            // +0x10, 4 bytes
    float m_fAdditionalFeedbackGain1;  // +0x14, 4 bytes
    float m_fAdditionalFeedbackGain2;  // +0x18, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FootIK_DATA__FootIKSystem_DATA) == 28);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIKSystem_DATA, fOnOffGain) == 0);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIKSystem_DATA, fGroundAscendingGain) == 4);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIKSystem_DATA, fGroundDescendingGain) == 8);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIKSystem_DATA, fFootRaisedGain) == 12);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIKSystem_DATA, fFootPlantedGain) == 16);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIKSystem_DATA, m_fAdditionalFeedbackGain1) == 20);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIKSystem_DATA, m_fAdditionalFeedbackGain2) == 24);
#pragma pack(push, 4)
class FootIK_DATA__FootIK_Leg_DATA
{
  public:
    short m_sFirstLegValue;   // +0x0, 2 bytes
    short m_sSecondLegValue;  // +0x2, 2 bytes
    short m_sThirdLegValue;   // +0x4, 2 bytes
    bool m_bFourthLegValue;   // +0x6, 1 bytes
    unsigned char layoutPadding7[1];
    float ShortBooleanFloatComponents;               // +0x8, 4 bytes
    float BooleanFloatComponentData;                 // +0xC, 4 bytes
    float SixFloatParameterBlock;                    // +0x10, 4 bytes
    float SixFloatAndFloatTripletData;               // +0x14, 4 bytes
    float m_fFourthComponentValue;                   // +0x18, 4 bytes
    float m_fFifthFloatValue;                          // +0x1C, 4 bytes
    float ThreeFloatScalarsAndTwoFloatTriples[3];    // +0x20, 12 bytes
    float TwoFloatAndTwoThreeElementFloatArrays[3];  // +0x2C, 12 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FootIK_DATA__FootIK_Leg_DATA) == 56);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIK_Leg_DATA, m_sFirstLegValue) == 0);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIK_Leg_DATA, m_sSecondLegValue) == 2);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIK_Leg_DATA, m_sThirdLegValue) == 4);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIK_Leg_DATA, m_bFourthLegValue) == 6);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIK_Leg_DATA, ShortBooleanFloatComponents) == 8);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIK_Leg_DATA, BooleanFloatComponentData) == 12);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIK_Leg_DATA, SixFloatParameterBlock) == 16);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIK_Leg_DATA, SixFloatAndFloatTripletData) == 20);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIK_Leg_DATA, m_fFourthComponentValue) == 24);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIK_Leg_DATA, m_fFifthFloatValue) == 28);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIK_Leg_DATA, ThreeFloatScalarsAndTwoFloatTriples) == 32);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA__FootIK_Leg_DATA, TwoFloatAndTwoThreeElementFloatArrays) == 44);
#pragma pack(push, 4)
class FootIK_DATA
{
  public:
    FootIK_DATA();
    ~FootIK_DATA();
    bool bEnabled;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    FootIK_DATA__FootIKSystem_DATA m_kRagdollFeedbackData;         // +0x4, 28 bytes
    BSSimpleArray<const char*, 1024> m_kFootNames;                 // +0x20, 16 bytes
    BSSimpleArray<FootIK_DATA__FootIK_Leg_DATA, 1024> m_kLegData;  // +0x30, 16 bytes
    // FootIK_DATA
    // bool __cdecl FootIK_DATA::*(const FootIK_DATA&)
    // void __cdecl FootIK_DATA::*(const FootIK_DATA&)
    // void __cdecl FootIK_DATA::*()
    // FootIK_DATA& __cdecl FootIK_DATA::*(const FootIK_DATA&)
    // void* __cdecl FootIK_DATA::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FootIK_DATA) == 64);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA, bEnabled) == 0);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA, m_kRagdollFeedbackData) == 4);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA, m_kFootNames) == 32);
FNV_STATIC_ASSERT(offsetof(FootIK_DATA, m_kLegData) == 48);
#pragma pack(push, 4)
class LookIK_DATA__LookIK_Head_DATA
{
  public:
    short m_sFirstHeadValue;                      // +0x0, 2 bytes
    short m_sSecondHeadValue;                     // +0x2, 2 bytes
    float ShortPairTwoVectorTwoScalarData[3];     // +0x4, 12 bytes
    float ShortPairTwoVectorThreeScalarData[3];   // +0x10, 12 bytes
    float ShortAndTwoFloatTriplesAndThreeFloats;  // +0x1C, 4 bytes
    float VectorPairScalarData;                   // +0x20, 4 bytes
    float FloatTripleAndThreeFloats;              // +0x24, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(LookIK_DATA__LookIK_Head_DATA) == 40);
FNV_STATIC_ASSERT(offsetof(LookIK_DATA__LookIK_Head_DATA, m_sFirstHeadValue) == 0);
FNV_STATIC_ASSERT(offsetof(LookIK_DATA__LookIK_Head_DATA, m_sSecondHeadValue) == 2);
FNV_STATIC_ASSERT(offsetof(LookIK_DATA__LookIK_Head_DATA, ShortPairTwoVectorTwoScalarData) == 4);
FNV_STATIC_ASSERT(offsetof(LookIK_DATA__LookIK_Head_DATA, ShortPairTwoVectorThreeScalarData) == 16);
FNV_STATIC_ASSERT(offsetof(LookIK_DATA__LookIK_Head_DATA, ShortAndTwoFloatTriplesAndThreeFloats) == 28);
FNV_STATIC_ASSERT(offsetof(LookIK_DATA__LookIK_Head_DATA, VectorPairScalarData) == 32);
FNV_STATIC_ASSERT(offsetof(LookIK_DATA__LookIK_Head_DATA, FloatTripleAndThreeFloats) == 36);
#pragma pack(push, 4)
class LookIK_DATA
{
  public:
    LookIK_DATA();
    ~LookIK_DATA();
    bool bEnabled;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSSimpleArray<const char*, 1024> m_kLookNames;                   // +0x4, 16 bytes
    BSSimpleArray<LookIK_DATA__LookIK_Head_DATA, 1024> m_kHeadData;  // +0x14, 16 bytes
    // LookIK_DATA
    // bool __cdecl LookIK_DATA::*(const LookIK_DATA&)
    // void __cdecl LookIK_DATA::*(const LookIK_DATA&)
    // void __cdecl LookIK_DATA::*()
    // LookIK_DATA& __cdecl LookIK_DATA::*(const LookIK_DATA&)
    // void* __cdecl LookIK_DATA::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(LookIK_DATA) == 36);
FNV_STATIC_ASSERT(offsetof(LookIK_DATA, bEnabled) == 0);
FNV_STATIC_ASSERT(offsetof(LookIK_DATA, m_kLookNames) == 4);
FNV_STATIC_ASSERT(offsetof(LookIK_DATA, m_kHeadData) == 20);
#pragma pack(push, 4)
class GrabIK_DATA__GrabIK_Arm_DATA
{
  public:
    short m_sFirstArmValue;   // +0x0, 2 bytes
    short m_sSecondArmValue;  // +0x2, 2 bytes
    short m_sThirdArmValue;   // +0x4, 2 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(GrabIK_DATA__GrabIK_Arm_DATA) == 6);
FNV_STATIC_ASSERT(offsetof(GrabIK_DATA__GrabIK_Arm_DATA, m_sFirstArmValue) == 0);
FNV_STATIC_ASSERT(offsetof(GrabIK_DATA__GrabIK_Arm_DATA, m_sSecondArmValue) == 2);
FNV_STATIC_ASSERT(offsetof(GrabIK_DATA__GrabIK_Arm_DATA, m_sThirdArmValue) == 4);
#pragma pack(push, 4)
class GrabIK_DATA
{
  public:
    GrabIK_DATA();
    ~GrabIK_DATA();
    bool bEnabled;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSSimpleArray<const char*, 1024> m_kGrabNames;                     // +0x4, 16 bytes
    BSSimpleArray<GrabIK_DATA__GrabIK_Arm_DATA, 1024> m_kGrabArmData;  // +0x14, 16 bytes
    // GrabIK_DATA
    // bool __cdecl GrabIK_DATA::*(const GrabIK_DATA&)
    // void __cdecl GrabIK_DATA::*(const GrabIK_DATA&)
    // void __cdecl GrabIK_DATA::*()
    // GrabIK_DATA& __cdecl GrabIK_DATA::*(const GrabIK_DATA&)
    // void* __cdecl GrabIK_DATA::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(GrabIK_DATA) == 36);
FNV_STATIC_ASSERT(offsetof(GrabIK_DATA, bEnabled) == 0);
FNV_STATIC_ASSERT(offsetof(GrabIK_DATA, m_kGrabNames) == 4);
FNV_STATIC_ASSERT(offsetof(GrabIK_DATA, m_kGrabArmData) == 20);
#pragma pack(push, 4)
class PoseMatching_DATA__PoseMatching_System_DATA
{
  public:
    short m_sFirstRagdollFeedbackIndex;   // +0x0, 2 bytes
    short m_sSecondRagdollFeedbackIndex;  // +0x2, 2 bytes
    short m_sThirdRagdollFeedbackIndex;   // +0x4, 2 bytes
    bool ShortTripleFloatPairRecord;      // +0x6, 1 bytes
    unsigned char layoutPadding7[1];
    float ShortFlagFloatRecord;     // +0x8, 4 bytes
    float FourFloatRecord;          // +0xC, 4 bytes
    float FourFloatParameterBlock;  // +0x10, 4 bytes
    float m_fFourthParameter;       // +0x14, 4 bytes
    void FUN_005ee580();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(PoseMatching_DATA__PoseMatching_System_DATA) == 24);
FNV_STATIC_ASSERT(offsetof(PoseMatching_DATA__PoseMatching_System_DATA, m_sFirstRagdollFeedbackIndex) == 0);
FNV_STATIC_ASSERT(offsetof(PoseMatching_DATA__PoseMatching_System_DATA, m_sSecondRagdollFeedbackIndex) == 2);
FNV_STATIC_ASSERT(offsetof(PoseMatching_DATA__PoseMatching_System_DATA, m_sThirdRagdollFeedbackIndex) == 4);
FNV_STATIC_ASSERT(offsetof(PoseMatching_DATA__PoseMatching_System_DATA, ShortTripleFloatPairRecord) == 6);
FNV_STATIC_ASSERT(offsetof(PoseMatching_DATA__PoseMatching_System_DATA, ShortFlagFloatRecord) == 8);
FNV_STATIC_ASSERT(offsetof(PoseMatching_DATA__PoseMatching_System_DATA, FourFloatRecord) == 12);
FNV_STATIC_ASSERT(offsetof(PoseMatching_DATA__PoseMatching_System_DATA, FourFloatParameterBlock) == 16);
FNV_STATIC_ASSERT(offsetof(PoseMatching_DATA__PoseMatching_System_DATA, m_fFourthParameter) == 20);
#pragma pack(push, 4)
class RagdollFeedbackProfile
{
  public:
    RagdollFeedbackProfile();
    ~RagdollFeedbackProfile();
    bool bEnabled;  // +0x0, 1 bytes
    unsigned char layoutPadding1[3];
    BSStringT<char> m_kAnimationFileName;                                // +0x4, 8 bytes
    PoseMatching_DATA__PoseMatching_System_DATA m_kRagdollFeedbackData;  // +0xC, 24 bytes
    // RagdollFeedbackProfile
    // bool __cdecl RagdollFeedbackProfile::*(const RagdollFeedbackProfile&)
    // void __cdecl RagdollFeedbackProfile::*(const RagdollFeedbackProfile&)
    // void __cdecl RagdollFeedbackProfile::*()
    // RagdollFeedbackProfile& __cdecl RagdollFeedbackProfile::*(const RagdollFeedbackProfile&)
    // void* __cdecl RagdollFeedbackProfile::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(RagdollFeedbackProfile) == 36);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackProfile, bEnabled) == 0);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackProfile, m_kAnimationFileName) == 4);
FNV_STATIC_ASSERT(offsetof(RagdollFeedbackProfile, m_kRagdollFeedbackData) == 12);
#pragma pack(push, 4)
class BGSRagdoll : public TESForm, public TESModel
{
  public:
    // base TESForm at +0x0, size 24
    // base TESModel at +0x18, size 24
    SaveMetadata ActorAnimationData;  // +0x30, 14 bytes
    unsigned char layoutPadding3E[2];
    RagdollAnimationData m_kRagdollAnimationData;      // +0x40, 80 bytes
    FootIK_DATA m_kFootIKData;                         // +0x90, 64 bytes
    LookIK_DATA m_kLookIKData;                         // +0xD0, 36 bytes
    GrabIK_DATA m_kGrabIKData;                         // +0xF4, 36 bytes
    RagdollFeedbackProfile m_kRagdollFeedbackProfile;  // +0x118, 36 bytes
    int m_iRagdollType;                                // +0x13C, 4 bytes
    BGSBodyPartData* m_pBodyPartDataCur;               // +0x140, 4 bytes
    TESActorBase* m_pActorBase;                        // +0x144, 4 bytes
    BGSRagdoll();
    void ResetFormData();
    virtual bool Load(TESFile* file);
    void InitItem(void);
    // BGSRagdoll
    // void __cdecl BGSRagdoll::*()
    // void __cdecl BGSRagdoll::*()
    // void __cdecl BGSRagdoll::*()
    // void __cdecl BGSRagdoll::*()
    // bool __cdecl BGSRagdoll::*(TESFile*)
    // void __cdecl BGSRagdoll::*()
    // void __cdecl BGSRagdoll::*(TESForm*)
    // bool __cdecl BGSRagdoll::*(TESForm*)
    // int __cdecl BGSRagdoll::*()
    // RagdollAnimationData& __cdecl BGSRagdoll::*()
    // BGSRagdoll& __cdecl BGSRagdoll::*(const BGSRagdoll&)
    // void __cdecl BGSRagdoll::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSRagdoll) == 328);
FNV_STATIC_ASSERT(offsetof(BGSRagdoll, ActorAnimationData) == 48);
FNV_STATIC_ASSERT(offsetof(BGSRagdoll, m_kRagdollAnimationData) == 64);
FNV_STATIC_ASSERT(offsetof(BGSRagdoll, m_kFootIKData) == 144);
FNV_STATIC_ASSERT(offsetof(BGSRagdoll, m_kLookIKData) == 208);
FNV_STATIC_ASSERT(offsetof(BGSRagdoll, m_kGrabIKData) == 244);
FNV_STATIC_ASSERT(offsetof(BGSRagdoll, m_kRagdollFeedbackProfile) == 280);
FNV_STATIC_ASSERT(offsetof(BGSRagdoll, m_iRagdollType) == 316);
FNV_STATIC_ASSERT(offsetof(BGSRagdoll, m_pBodyPartDataCur) == 320);
FNV_STATIC_ASSERT(offsetof(BGSRagdoll, m_pActorBase) == 324);
#endif
