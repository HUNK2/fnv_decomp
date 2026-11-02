// Private declaration copy; original: relay_work/queue/queue058/01_fallout_interface_menus_statsmenu_cpp/include/TESTexture.h
// Source layout: TESTexture. PC corrections are in generate_headers.py.
#ifndef FNV_TESTEXTURE_H
#define FNV_TESTEXTURE_H

#include "statsmenu_layout_support.h"
#include "statsmenu_BaseFormComponent.h"
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> FullNameComponent;  // +0x4
};
FNV_STATIC_ASSERT(sizeof(TESTexture) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESTexture, FullNameComponent) == 0x4);
#endif
