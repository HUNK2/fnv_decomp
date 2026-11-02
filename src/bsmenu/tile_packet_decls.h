// bsmenu/tile_packet_decls.h: declares Menu, TileListBoxCalls, Tile, Value, LoadingMenu
#ifndef TILE_PACKET_DECLS_H
#define TILE_PACKET_DECLS_H

class Menu
{
  public:
    char menuFields[0x1c];
    bool m_bIsSpecial;
    static float GetMenuScale();
};
class TileListBoxCalls
{
  public:
    float GetFloat(int);
};
class Tile
{
  public:
    char tileFields[0x35];
    bool m_bSpeechChallengeFailure;
    char tileUnknown36[0x1ec];
    unsigned short floatFlags;
    class Value
    {
      public:
        int m_iValueId;
        Tile* pTile;
        float fValue;
        __forceinline float GetFloat()
        {
            return fValue;
        }
    };
    static float GetInterfaceScale();
    bool IsPointInside(float, float);
    bool GetSpeechChallengeFailure();
    void SetSpeechChallengeFailure(bool);
    static void UpdateAll(bool);
    void Set(int, int);
    void Set(int, unsigned int);
    void Set(int, float, bool);
    Menu* GetMenu();
    bool IsMenuRendered();
    Value* GetValue(int);
    float GetFloat(int);
};
template <class T> class NiTPointerList;
template <> class NiTPointerList<Tile*>
{
  public:
    Tile*& GetPrev(NiTListItem<Tile*>*&);
};
class LoadingMenu
{
  public:
    char menuFields[0x222];
    unsigned short floatFlags;
    bool GetFloat(int);
};
#endif
