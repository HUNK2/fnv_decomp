// Source layout: TESTexture. PC corrections are in generate_headers.py.
#ifndef FNV_TESTEXTURE_H
#define FNV_TESTEXTURE_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#pragma pack(push, 4)
class TESTexture : public BaseFormComponent
{
  public:
    BSStringT<char> FullNameComponent;  // +0x4
    static void ReadTextureData(TESTexture* texture, TESFile* file);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESTexture) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESTexture, FullNameComponent) == 0x4);
#endif
