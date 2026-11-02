// Hand-authored partial HUDMainMenu layout for the members this translation
// and the generated include/HUDMainMenu.h. AssignTileByID is covered by this
// unit but is not yet emitted by the canonical header generator, so its
// declaration lives here; a canonical generated header supersedes this file.
#ifndef FNV_HUDMAINMENU_H
#define FNV_HUDMAINMENU_H

#include "layout_support.h"
#include "Menu.h"
class HUDMainMenu : public Menu
{
  public:
    Tile* m_pTiles[87];  // +0x28
    int GetClass();
    void AssignTileByID(int aTileID, Tile* apTile);
    void* m_pAdditionalHudTile;
    float m_fMessageDisplayTimer;
    char m_kMessageList[8];
    unsigned int m_uiMessageCount;
    char m_kSubtitleArray[16];
    void* m_pCurrentSubtitle;
    char m_kTargetDisplayData[12];
    void* m_pCrosshairReference;
    int m_iHudValueFirstBeforeMode;
    int m_iHudValueSecondBeforeMode;
    int m_eHudMenuMode;
    char m_kMenuData[52];
    bool m_bHudModeActive;
    char _pdbpad_1fd[3];
    void* m_pHudAnimationSequence;
    bool m_bSequenceActive;
    bool m_bHudAnimationActive;
    char _pdbpad_206[2];
    unsigned int m_uiHudAnimationCounter;
    void* m_pRegionObjectListObj;
    int m_iHudValueFirstAfterUpdateList;
    int m_iHudValueSecondAfterUpdateList;
    int m_iHudValueThirdAfterUpdateList;
    void* m_pTargetActor;
    bool m_bTargetActorVisible;
    char _pdbpad_221[3];
    char m_cBuffer[32];
    unsigned int m_uiHudValueFirstAfterActor;
    unsigned int m_uiHudValueSecondAfterActor;
    int m_iHudValueFirstAfterUnsignedValues;
    int m_iHudValueSecondAfterUnsignedValues;
    bool m_bQuestObjectiveUpdatesEnabled;
    char _pdbpad_255[3];
    char m_kQuestObjectives[8];
    bool m_bQuestObjectiveUpdatePending;
    bool m_bXPUpdatePending;
    char _pdbpad_262[2];
    char m_kXPUpdates[8];
    char m_kRadiationUpdates[8];
    float m_fRadiationUpdateTimer;
};
FNV_STATIC_ASSERT(offsetof(HUDMainMenu, m_pTiles) == 0x28);
#endif
