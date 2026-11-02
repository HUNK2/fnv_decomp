// fallout_shared/aiformulas_decls.h: declares AIFormulas
#ifndef FNV_AIFORMULAS_DECLS_H
#define FNV_AIFORMULAS_DECLS_H

union SETTING_VALUE
{
    float f;
};
class GameSettingCollection;
template <class T> class SettingT
{
  public:
    SETTING_VALUE* Float();
};
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting326;
extern SettingT<GameSettingCollection> originalRuntimeFloatSetting314;
float __cdecl FUN_00406ce0(float);
float __cdecl FUN_004e4450(float);
class AIFormulas
{
  public:
    static float __cdecl CalculateSkillValue(float, float, float);
};
#endif
