// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/bsmenu/tilerect.h
//
// Covered function (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x00709960  TileRect::GetType  (16 bytes)
//
// The canonical bsmenu/tile.h unit has not landed yet, so the Tile base is
// polymorphic 0x38-byte base whose nested enumType enumerates the tile
// classes. The canonical header restores `class TileRect : public Tile`
// with the real Tile members and this check-time copy retires.
#ifndef FNV_TILERECT_H
#define FNV_TILERECT_H


#include "layout_support.h"

#pragma pack(push, 4)
class Tile
{
  public:
    virtual ~Tile();
    virtual void Init(Tile*, const char*, Tile*);
    void Set(int, float, bool);
    void SetTileType(int);

    // Tile::enumType). TileRect::GetType returns eRect.
    enum enumType
    {
        eNullType = 0,
        eFirstType = 901,
        eRect = 901,
        eImage = 902,
        eText = 903,
        e3D = 904,
        eLine = 905,
        eHotRect = 906,
        eWindow = 907,
        eRadial = 908,
        eLastType = 908,
        eTemplate = 999,
    };

  private:
    // +0x4..+0x37: Tile base extent. The canonical tile.h owns these members
    unsigned char layoutPadding4[0x34];
};
#pragma pack(pop)

#pragma pack(push, 4)
class TileRect : public Tile
{
  public:
    virtual ~TileRect();
    virtual void Init(Tile*, const char*, Tile*);
    virtual int GetType();
    virtual const char* GetTypeName();
    virtual NiNode* CalculateNode();
    virtual Tile* SetTraitValue(int, float, const char*);

    bool m_bTextureLoaded;  // +0x38
};
#pragma pack(pop)

FNV_STATIC_ASSERT(sizeof(TileRect) == 0x3C);
FNV_STATIC_ASSERT(offsetof(TileRect, m_bTextureLoaded) == 0x38);

#endif
