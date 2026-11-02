#ifndef FNV_IMAGESPACEEFFECTPARAM_H
#define FNV_IMAGESPACEEFFECTPARAM_H
class ImageSpaceEffectParam
{
  public:
    float r, g, b, a;
    ImageSpaceEffectParam(float red, float green, float blue, float alpha);
};
// @fnv 0x00414430
ImageSpaceEffectParam::ImageSpaceEffectParam(float red, float green, float blue, float alpha)
{
    r = red;
    g = green;
    b = blue;
    a = alpha;
}
#endif
