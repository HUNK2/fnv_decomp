// Source layout: Setting. PC corrections are in generate_headers.py.
#ifndef FNV_SETTING_H
#define FNV_SETTING_H
#include "layout_support.h"
#include "SETTING_VALUE.h"
#pragma pack(push, 4)
class Setting
{
  public:
    SETTING_VALUE uValue;  // +0x4
    const char* pKey;      // +0x8
    Setting(const char* key, float value);
    Setting(const char* key, int value);
    Setting(const char* key, char* value);
    virtual ~Setting();
    virtual bool IsPrefSetting();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(Setting) == 0xC);
FNV_STATIC_ASSERT(offsetof(Setting, uValue) == 0x4);
FNV_STATIC_ASSERT(offsetof(Setting, pKey) == 0x8);
#endif
