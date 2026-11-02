// fallout/interface/hotkeyswheel_decls.h: declares Tile
#ifndef HOTKEYSWHEEL_DECLS_H
#define HOTKEYSWHEEL_DECLS_H

class Tile
{
  public:
    bool ContainsTrait(int);
    void Set(int, int);
    void Set(int, const char*, bool);
    Tile* GetNamedChild(const char*);
};
class HotkeyWheelDisplay
{
  public:
    Tile* m_pWheelTile;
    Tile* m_ppHotkeySlotTiles[8];
    bool m_bHasHotkeySelection;
    unsigned char pad[3];
    int m_iTileValueIdAtOffset28, m_iTileValueIdAtOffset2C, m_iTileValueIdAtOffset30;
    bool GetVisible();
    void SetVisible(bool);
    void RefreshHotkeyWheel();
    void Initialize(Tile*);
    char inputPadding[0x1b92 - 0x34];
    unsigned short flags;
    unsigned char keyboard[3][28];
    unsigned char controller[28];
    int SetHotkeyItem(int, int);
    int FUN_00a24560(int, int, int);
    int HandleHotkeyInput(int, int);
    int FUN_00a23e10(int, int);
};
template <class T> class BSStringT
{
    T* data;
    unsigned short length, capacity;

  public:
    BSStringT();
    ~BSStringT();
    int __cdecl PrintfString(const char*, ...);
    const char* String();
};
int __cdecl GetTileValueID(const char*, int);
int __cdecl Warning(const char*, ...);
extern const char DAT_0106eaa0[], DAT_0106ea94[], DAT_0106ea84[], DAT_0106ea74[], g_emptyTopicInfoPrompt[];
__forceinline unsigned short HotkeySuppressedMask()
{
    return 8;
}
extern bool DAT_011f35c8;
#endif
