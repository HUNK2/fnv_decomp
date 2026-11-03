// fallout/interface/interface_rebase_packet_decl_interface_rtti_variant.h: declares EffectSetting, InterfaceManager
#ifndef FNV_INTERFACE_REBASE_CURRENT_PACKET_H
#define FNV_INTERFACE_REBASE_CURRENT_PACKET_H

class Tile;
class NiNode;
class TESSound;
class EffectSetting
{
  public:
    TESSound* GetCastSound();
};
class InterfaceManager
{
  public:
    bool FUN_009373f0();  // declared for the original code (decl_variants.py)

  public:
    char padding[0x4d0];
    float screenAspectRatio;
    static float UpdateInterfaceState();
    static void Initialize(unsigned int, bool);
    Tile* FUN_00586150();
    Tile* FUN_004fd400();
    bool FUN_00706d90();
};
InterfaceManager* InterfaceManager_Instance();
float FUN_00715da0();
float FUN_00706e20();
float FUN_00706e50();
bool FUN_00707b50();
unsigned int FUN_00702440();
bool FUN_00705100();
unsigned int FUN_00706f20();

extern bool DAT_011d9514;
extern bool DAT_011c70eb;

#endif
