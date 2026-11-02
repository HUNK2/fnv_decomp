#ifndef FNV_SETTING_AUTHORED_BODIES_H
#define FNV_SETTING_AUTHORED_BODIES_H


#include "setting_declarations.h"

// @fnv 0x0044f570
template <> void SettingT<INISettingCollection>::EnsureCollection()
{
    if (!ms_pCollection)
        ms_pCollection = new INISettingCollection;
}

// @fnv 0x0044f560
template <> INISettingCollection* SettingT<INISettingCollection>::GetCollection()
{
    EnsureCollection();
    return ms_pCollection;
}

// @fnv 0x004de490
template <> INIPrefSettingCollection* SettingT<INIPrefSettingCollection>::GetCollection()
{
    EnsureCollection();
    return ms_pCollection;
}

// @fnv 0x005e02b0
template <> Setting* SettingCollectionList<Setting>::GetPtr(const char* key)
{
    Setting* result = 0;
    Get(key, result);
    return result;
}

#endif
