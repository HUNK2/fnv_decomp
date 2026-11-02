// fallout/interface/interface_rebase_packet.h: declares EffectSetting, InterfaceManager
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
    char padding[0x4d0];
    float screenAspectRatio;
    static float UpdateInterfaceState();
    static void Initialize(unsigned int, bool);
    Tile* FUN_00586150();
    Tile* FUN_004fd400();
    bool FUN_00706d90();
};
InterfaceManager* FUN_004b7210();
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
