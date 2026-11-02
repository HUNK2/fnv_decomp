// fallout_shared/tesammo_load.h: declares TESFileFormVersion, TESTextureLoader, CombatProcedure, TESRegionGrassObject, BGSImpactData and more

#include "tesammo_decls.h"
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture*, TESFile*);
};
class CombatController;
class CombatProcedure
{
  public:
    void Initialize(CombatController*);
};
class TESLandTexture;
class TESRegionGrassObject
{
  public:
    void AssignLandTexture(TESLandTexture*);
};
class BGSImpactData
{
  public:
    void ReadTypedData(TESFile*, void*, unsigned short);
};
class EncounterZoneData
{
  public:
    void Endian();
};
class TESAmmoNVEndian
{
  public:
    void SwapEndianFields();
};
class ActorCause;
class ScriptVariableInfo;
