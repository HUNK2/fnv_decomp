// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/bsmenu/tiletext.h
//
// Covered function (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x00a0bbd0  TileText::GetType                  (16 bytes)
//
// The canonical tree does not carry bsmenu/tile.h yet, so the Tile base and
// its enumType are declared here to keep the translation unit self-contained.
// (type index 131285). Canonical additions requested from the operator:
//   - a canonical generated bsmenu/tile.h layout for Tile once the base class
//     is reconstructed.
#ifndef FNV_TILETEXT_H
#define FNV_TILETEXT_H


#include "layout_support.h"

#pragma pack(push, 4)

class Tile
{
  public:
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
};

class TileText : public Tile
{
  public:
    virtual int GetType();
};

#pragma pack(pop)

#endif
