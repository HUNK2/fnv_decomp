// Source layout: SettingT<GameSettingCollection>. PC corrections are in generate_headers.py.
#ifndef FNV_SETTINGT_GAMESETTINGCOLLECTION__H
#define FNV_SETTINGT_GAMESETTINGCOLLECTION__H
#include "layout_support.h"
#include "Setting.h"
#pragma pack(push, 4)
template <> class SettingT<GameSettingCollection> : public Setting
{
  public:
    SettingT(const char* key, float value);
    SettingT(const char* key, int value);
    SettingT(const char* key, char* value);
    virtual ~SettingT();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SettingT<GameSettingCollection>) == 0xC);
#endif
