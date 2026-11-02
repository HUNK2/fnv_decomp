// fallout_shared/bgsradiation_decls.h: declares NiAVObject, BGSDehydrationStage, BSShaderPPLightingProperty, BGSImpactData, BGSCameraPath
#ifndef FNV_BGS_RADIATION_DECLS_H
#define FNV_BGS_RADIATION_DECLS_H

class TESFile;
class SpellItem;
class BGSRadiationStage;
class NiNode;
class NiAVObject
{
  public:
    NiNode* GetParent();
};
class BGSDehydrationStage
{
  public:
    static BGSDehydrationStage** AllocateStageArray(unsigned int count);
    unsigned int FUN_00441110();
    void FUN_0050f9a0(SpellItem*);
};
class NiTexture;
class BSShaderPPLightingProperty
{
  public:
    NiTexture* GetNormalMapTexture();
};
extern unsigned int DAT_011ca87c;
extern BGSRadiationStage** DAT_011ca880;
BGSRadiationStage* FUN_005922a0(unsigned int index);
void InsertRadiationStage(BGSRadiationStage* stage);
extern "C" void* __cdecl __RTDynamicCast(void* source, long vfDelta, void* sourceType, void* targetType,
                                         int isReference);
class BGSImpactData
{
  public:
    void ReadTypedData(TESFile*, void*, unsigned short);
    char _pdbpad_1[47];
    char Data_pad2f_pad2f_pad2f[24];
    void* m_pDecalTextureSet;
    void* m_pPrimaryImpactSound;
    void* m_pSecondaryImpactSound;
    char ImpactDecalInfo[36];
};
class PerkEntryConditionSet;
class BGSCameraPath
{
  public:
    PerkEntryConditionSet* GetConditions();
};
class FUN_005a71d0
{
  public:
    void FUN_00462230();
};
#endif
