#ifndef FNV_GAME_CONSTANTS_H
#define FNV_GAME_CONSTANTS_H

// Record and dialogue values used by the reconstructed game layer.
enum
{
    kInvalidTopicInfoIndex = 0xffff,
    kInventoryChangesCreateSourceLine = 0x71d,
    kExtraContainerChangesType = 0x15,
    kCompressedRecordFlag = 0x40000,
    kThreadSafeFileMapBuckets = 37,
    kRemappedRumorsSubtype = 5,
    kAnyPreviousTopicFormID = 0xd3,
    kScriptBlockCount = 38,
    kScriptIfActiveFlag = 1,
    kScriptIfConditionPassedFlag = 2,
    kScriptGlobalVariable = 'G',
    kScriptReferenceVariable = 'r',
    kScriptLongVariable = 'l',
    kScriptShortVariable = 's',
    kScriptFloatVariable = 'f',
    kTopicInfoFormType = 0x46,
    kNextScriptChunk = 0x5458454e,
    kScriptVariableDataChunk = 0x44534c53,
    kScriptVariableNameChunk = 0x52564353,
    kScriptHeaderChunk = 0x52484353,
    kScriptCompiledDataChunk = 0x41444353,
    kScriptFormReferenceChunk = 0x4f524353,
    kScriptVariableReferenceChunk = 0x56524353,
    kScriptVariableNameReadSize = 0x200,
    kConditionDataChunk = 0x41445443,
    kTopicInfoDataChunk = 0x41544144,
    kAdditionalTopicChunk = 0x454d414e,
    kTopicInfoQuestChunk = 0x49545351,
    kTopicInfoSpeakerChunk = 0x4d414e41,
    kTopicInfoDifficultyChunk = 0x4d414e44,
    kTopicInfoPerkSkillChunk = 0x4d414e4b,
    kPreviousTopicInfoChunk = 0x4d414e50,
    kTopicInfoPromptChunk = 0x4d414e52,
    kConversationLinkFromChunk = 0x464c4354,
    kConversationLinkToChunk = 0x544c4354,
    kConversationFollowUpChunk = 0x55464354,
    kTopicInfoPromptReadSize = 256
};
const unsigned int kNoPreviousTopicInfo = 0xffffffffu;
#endif
