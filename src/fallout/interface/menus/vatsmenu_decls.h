// fallout/interface/menus/vatsmenu_decls.h: declares TileListBoxCalls, VATSMenu

class TileListBoxCalls
{
  public:
    float GetFloat(int);
};
int GetTileValueID(const char*, int);
class VATSMenu
{
  public:
    char padding[12];
    TileListBoxCalls* tile;
    int GetSelectedTargetIndex();
    unsigned int Create();
    char _pdbpad_10[24];
    char m_pTiles[128];
    void* m_pAdditionalHudTile;
    bool m_bStateFlag8;
    char _pdbpad_ad[3];
    char m_acMenuText[48];
    float m_fOverrideActionPoints;
    float m_fValue1;
    float m_fValue2;
    float m_fValue3;
    float m_fValue4;
    float m_fValue5;
    bool m_bFirstFlag;
    bool m_bStateFlag1;
    bool m_bStateFlag2;
    bool m_bStateFlag3;
    float m_fHitChance;
    void* m_pTargetChance;
    bool m_bStateFlag4;
    char _pdbpad_105[3];
    void* m_pSelectedChance;
    bool m_bStateFlag5;
    bool m_bStateFlag9;
    bool m_bAdditionalStateFlag;
    bool m_bStateFlag10;
    bool m_bStateFlag6;
    char _pdbpad_111[3];
    unsigned int m_uiTargetCount;
    bool m_bStateFlag7;
    char _pdbpad_119[3];
    char m_acTargetText[40];
};
