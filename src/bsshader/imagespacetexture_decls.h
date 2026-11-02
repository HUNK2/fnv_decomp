// bsshader/imagespacetexture_decls.h: declares NonActorMagicCaster, MagicCaster, ImageSpaceTexture, BSTextureManager
#ifndef IMAGESPACETEXTURE_DECLS_H
#define IMAGESPACETEXTURE_DECLS_H

class MagicItem;
class NonActorMagicCaster
{
  public:
    void SetSelectedMagicItem(MagicItem*);
};
class MagicCaster
{
  public:
    void SetSelectedMagicItem(MagicItem*);
};
class NiTexture;
class BSRenderedTexture;
class ImageSpaceTexture
{
  public:
    void SetTexture(NiTexture*);
    void AddRenderedTexture();
};
class BSTextureManager
{
  public:
    void AddRenderedTexture(BSRenderedTexture*);
};
extern BSTextureManager* DAT_011f91a8;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
#endif
