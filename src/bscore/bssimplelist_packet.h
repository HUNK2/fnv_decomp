// bscore/bssimplelist_packet.h: declares BGSCameraPath, QuantityData, TESObjectDOOR, MersenneTwister, BGSHeadPart and more
#ifndef FNV_BSSIMPLELIST_PACKET_H
#define FNV_BSSIMPLELIST_PACKET_H

#include "bssimplelist_decls.h"
class TESTopic;
class PerkEntryConditionSet;
class BGSCameraShot;
class TESClass;
class TerminalMenuItem;
class TESTopicInfoData
{
  public:
    char prefix[8];
    BSSimpleList<TESTopic*> topics;
    BSSimpleList<TESTopic*>* GetLinkToList();
};
class BGSCameraPath
{
  public:
    char prefix[24];
    PerkEntryConditionSet* GetConditions();
    BSSimpleList<BGSCameraShot*>* GetShotList();
};
class QuantityData
{
  public:
    QuantityData();
    void SetQuantity(unsigned int);
};
class TESObjectDOOR
{
  public:
    void ClearRandomTeleportList();
};
class MersenneTwister
{
  public:
    static MersenneTwister* GetRandomGenerator();
    unsigned int IntInRange(int, int);
};
class BGSHeadPart
{
  public:
    void AddExtraPart(BGSHeadPart*);
};
class BGSTerminal
{
  public:
    void AddMenuItem(TerminalMenuItem*);
};
class TESWeather
{
  public:
    class WeatherSound;
};
template <> class BSSimpleList<TESWeather::WeatherSound*>
{
  public:
    TESWeather::WeatherSound* m_item;
    BSSimpleList* m_pkNext;
    BSSimpleList(TESWeather::WeatherSound*, BSSimpleList*);
};
class ActorCause;
class SpellItem;
class ScriptVariableInfo;
class Tile;
class InterfaceManager
{
  public:
    void FUN_00500a20(Tile*);
};
template <> void BSSimpleList<ActorCause*>::RemoveAll();
template <> void BSSimpleList<SpellItem*>::AddHead(SpellItem*&);
template <> class BSSimpleList<ScriptVariableInfo*>
{
  public:
    void AddTail(ScriptVariableInfo* const&);
};
#endif
