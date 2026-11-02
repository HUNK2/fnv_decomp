// Reconstructed source: bsmenu/tileimage.h
// TileImage identifies itself to the BS menu tile system by reporting its image type.
#ifndef TILEIMAGE_H
#define TILEIMAGE_H

#include "layout_support.h"

class TileImage
{
  public:
    virtual int GetType();
};

// @fnv 0x0070b670
int TileImage::GetType()
{
    return 0x386;
}

#endif  // TILEIMAGE_H
