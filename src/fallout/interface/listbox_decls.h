// fallout/interface/listbox_decls.h: declares ListBox_int_
#ifndef FNV_LISTBOX_DECLS_H
#define FNV_LISTBOX_DECLS_H

class Tile;
class ListBox_int_
{
  public:
    bool ContainsKey(Tile* tile);
};
class SoundPlaybackHandle
{
  public:
    unsigned int soundID;
    unsigned char success;
    unsigned int state;
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle& other);
};
#endif
