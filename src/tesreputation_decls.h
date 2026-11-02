// tesreputation_decls.h: declares BGSMessageIcon, ReputationLimitData, TESReputation, TESFullNameLoader, TESTextureLoader
#ifndef FNV_REPUTATION_LOCAL_H
#define FNV_REPUTATION_LOCAL_H

#include "TESForm.h"
#include "TESFullName.h"
#include "TESIcon.h"
#include "TESFile.h"

class BGSMessageIcon : public BaseFormComponent
{
  public:
    TESIcon Icon;
    static void LoadMessageIconChunk(BGSMessageIcon* component, TESFile* file);
};

class ReputationLimitData
{
  public:
    float m_fMaximumReputation;
    void Endian();
};

enum ReputationType
{
    ReputationType_REPUTATION_NEGATIVE = 0,
    ReputationType_REPUTATION_POSITIVE = 1
};

class TESReputation : public TESForm, public TESFullName, public TESIcon, public BGSMessageIcon
{
  public:
    ReputationLimitData data;
    float m_fFirstReputationValue;
    float m_fSecondReputationValue;
    ReputationType m_eReputationType;
    virtual void ResetFormData();
    virtual bool Load(TESFile* file);
    void ReadTypedData(TESFile* file, void* buffer, unsigned short size);
    float GetUnsignedIntegerPointer(ReputationType type);
    static unsigned int* GetUnsignedIntegerPointer(unsigned int* value);
};

class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* component, TESFile* file);
};
class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture* component, TESFile* file);
};
FNV_STATIC_ASSERT(sizeof(BGSMessageIcon) == 16);
FNV_STATIC_ASSERT(offsetof(BGSMessageIcon, Icon) == 4);
FNV_STATIC_ASSERT(sizeof(ReputationLimitData) == 4);
FNV_STATIC_ASSERT(offsetof(ReputationLimitData, m_fMaximumReputation) == 0);
FNV_STATIC_ASSERT(sizeof(TESReputation) == 80);
FNV_STATIC_ASSERT(offsetof(TESReputation, data) == 64);
FNV_STATIC_ASSERT(offsetof(TESReputation, m_fFirstReputationValue) == 68);
FNV_STATIC_ASSERT(offsetof(TESReputation, m_fSecondReputationValue) == 72);
FNV_STATIC_ASSERT(offsetof(TESReputation, m_eReputationType) == 76);
#endif
