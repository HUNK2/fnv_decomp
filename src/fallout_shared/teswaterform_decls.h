// fallout_shared/teswaterform_decls.h: declares TESSound, EffectItem, WaterListPrefix, WaterEffectList, WaterSpellPrefix and more
#ifndef FNV_TESWATERFORM_DECLS_H
#define FNV_TESWATERFORM_DECLS_H


#define IsFormInitialized                                                                                              \
    unusedWaterDeclaration();                                                                                          \
    unsigned int GetDataSizeAdjustment();                                                                              \
    bool IsFormInitialized
#include "TESForm.h"
#undef IsFormInitialized

class SpellItem;
class TESConditionItem;
class TESEffectShader;
class TESSound : public TESForm
{
};
class EffectItem
{
  public:
    int GetAffectedActorValue();
    int GetMagnitude();
    EffectSetting* GetEffectSetting();
};
struct WaterListPrefix
{
    unsigned int prefix;
};
class WaterEffectList : public WaterListPrefix, public BSSimpleList<EffectItem*>
{
};
struct WaterSpellPrefix
{
    unsigned int prefix[3];
};
class SpellItem : public TESForm, public WaterSpellPrefix, public WaterEffectList
{
};
namespace ActorValue {
enum Index
{
    ActorValue__Index_VALUE_NONE = -1
};
}
typedef ActorValue::Index ActorValue__Index;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
};
class TESFormInitFlag
{
  public:
    bool IsFormInitialized() const;
};
class EffectSetting
{
  public:
    bool IsFlagSet(unsigned int);
    void SetEnchantEffectShader(TESEffectShader*);
};
TESForm* __cdecl GetFormByID(unsigned int);
int __cdecl Warning(const char*, ...);
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);
extern int DAT_01184118;

extern float g_splatterDefaultSecond;
extern float DAT_010249d8;
extern float DAT_0101b268;
extern float DAT_010313d4;
extern float DAT_01013974;
extern float DAT_01018180;
extern float DAT_010231a4;
extern float DAT_010162c0;
extern float DAT_010231a8;
extern float DAT_010181bc;
extern float DAT_01013d84;
extern float DAT_0101b2d0;
extern float DAT_01022958;

class BGSImpactData
{
  public:
    void ReadTypedData(TESFile*, void*, unsigned short);
};
class TESFullName;
class TESTexture;
class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture*, TESFile*);
};
template <int N> struct EndianSizeTag
{
};
void BSEndian(unsigned int*, EndianSizeTag<4>);
#include <malloc.h>
#endif
