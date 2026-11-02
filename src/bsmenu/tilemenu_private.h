// bsmenu/tilemenu_private.h: declares Tile, TileRect, TileMenu
#ifndef FNV_TILEMENU_H
#define FNV_TILEMENU_H

#include "layout_support.h"

class TileShaderProperty;
class Tile__Value;
class NiColorAlpha;
class Tile
{
  public:
    virtual ~Tile();
    virtual void Init(Tile* parent, const char* name, Tile* replacedChild);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual const char* GetTypeStr();
    virtual bool Unk_05(float arg0, float arg1);
    virtual Tile* SetTraitValue(int valueID, float floatValue, const char* strValue);
    virtual void ClearTextures();
    virtual TileShaderProperty* GetShaderProperty();
    virtual void SetAlphaAndOverlayColor(NiNode* node, float alpha, NiColorAlpha* color);
    void Set(int trait, float value, bool clearActions);
    void SetTileType(int flags);
    float GetFloat(int trait);
    void Release();
    __forceinline bool IsSpecial()
    {
        return (uiFlags & 0x2000) != 0;
    }
    NiTPointerListBase<NiTPointerAllocator<unsigned int>, Tile*> m_kChildTileList;
    BSSimpleArray<Tile__Value*, 8> m_kValues;
    BSStringT<char> StringProvider;
    Tile* pParent;
    NiPointer<NiNode> m_pRenderedNodeEntry;
    unsigned int uiFlags;
    bool m_bFlagAfterUiFlags;
    bool m_bSpeechChallengeFailure;
    unsigned char layoutPadding36[2];
};
FNV_STATIC_ASSERT(sizeof(Tile) == 56);
class TileRect : public Tile
{
  public:
    virtual ~TileRect();
    virtual NiNode* CalculateNode();
    bool m_bTextureLoaded;
    unsigned char layoutPadding39[3];
};
FNV_STATIC_ASSERT(sizeof(TileRect) == 60);
class TileMenu : public TileRect
{
  public:
    virtual ~TileMenu();
    virtual void Init(Tile* parent, const char* name, Tile* replacedChild);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual Tile* SetTraitValue(int valueID, float floatValue, const char* strValue);
    __forceinline float GetTraitFloat(int id)
    {
        return ((TileListBoxCalls*)this)->GetFloat(id);
    }
    Menu* pMenu;
};
FNV_STATIC_ASSERT(sizeof(TileMenu) == 64);
FNV_STATIC_ASSERT(offsetof(TileMenu, pMenu) == 60);
#endif
