// bsshader/bsshaderlightingproperty_math.h: declares bsshaderlightingproperty_Color3, bsshaderlightingproperty_Color4, bsshaderlightingproperty_VirtualProperty
#ifndef BSSHADERLIGHTINGPROPERTY_MATH_H
#define BSSHADERLIGHTINGPROPERTY_MATH_H

struct bsshaderlightingproperty_Color3
{
    float r, g, b;
    bsshaderlightingproperty_Color3()
    {}
    bsshaderlightingproperty_Color3 operator*(float scale) const
    {
        bsshaderlightingproperty_Color3 v = *this;
        v.r *= scale;
        v.g *= scale;
        v.b *= scale;
        return v;
    }
    void operator*=(float scale)
    {
        r *= scale;
        g *= scale;
        b *= scale;
    }
};
struct bsshaderlightingproperty_Color4
{
    float r, g, b, a;
    bsshaderlightingproperty_Color4()
    {}
    bsshaderlightingproperty_Color4(float x, float y, float z, float w) : r(x), g(y), b(z), a(w)
    {}
    bsshaderlightingproperty_Color4(const bsshaderlightingproperty_Color3& c, float w) : r(c.r), g(c.g), b(c.b), a(w)
    {}
};
class bsshaderlightingproperty_VirtualProperty
{
  public:
    virtual void vfn_000();
    virtual void vfn_004();
    virtual void vfn_008();
    virtual void vfn_00c();
    virtual void vfn_010();
    virtual void vfn_014();
    virtual void vfn_018();
    virtual void vfn_01c();
    virtual void vfn_020();
    virtual void vfn_024();
    virtual void vfn_028();
    virtual void vfn_02c();
    virtual void vfn_030();
    virtual void vfn_034();
    virtual void vfn_038();
    virtual void vfn_03c();
    virtual void vfn_040();
    virtual void vfn_044();
    virtual void vfn_048();
    virtual void vfn_04c();
    virtual void vfn_050();
    virtual void vfn_054();
    virtual void vfn_058();
    virtual void vfn_05c();
    virtual void vfn_060();
    virtual void vfn_064();
    virtual void vfn_068();
    virtual void vfn_06c();
    virtual void vfn_070();
    virtual void vfn_074();
    virtual void vfn_078();
    virtual void vfn_07c();
    virtual void vfn_080();
    virtual void vfn_084();
    virtual void vfn_088();
    virtual void vfn_08c();
    virtual void vfn_090();
    virtual void vfn_094();
    virtual void vfn_098();
    virtual void vfn_09c();
    virtual void vfn_0a0();
    virtual void vfn_0a4();
    virtual void vfn_0a8();
    virtual void vfn_0ac();
    virtual void vfn_0b0();
    virtual void vfn_0b4();
    virtual void vfn_0b8();
    virtual void vfn_0bc();
    virtual void vfn_0c0();
    virtual void vfn_0c4();
    virtual void vfn_0c8();
    virtual void vfn_0cc();
    virtual void vfn_0d0();
    virtual void vfn_0d4();
    virtual void vfn_0d8();
    virtual void vfn_0dc();
    virtual void vfn_0e0();
    virtual void vfn_0e4();
    virtual void vfn_0e8();
    virtual void vfn_0ec();
    virtual void vfn_0f0();
    virtual void vfn_0f4();
    virtual void vfn_0f8();
    virtual void vfn_0fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual float vfn_10c();
    unsigned char padding[0x18];
    int type;
};
extern bsshaderlightingproperty_Color4 DAT_011a9bd0;
extern class NiGeometry** DAT_011f91e0;
extern bool DAT_011f941e, DAT_011f9427;
extern float DAT_011f947c, DAT_011f9190;
void FUN_00bb95b0(unsigned int, bsshaderlightingproperty_Color4);
void FUN_00bb95e0(unsigned int, bsshaderlightingproperty_Color4, bsshaderlightingproperty_Color4);
void ApplyLighting30Packet(bsshaderlightingproperty_Color4*, bool);
extern const double DAT_01012070;
inline bsshaderlightingproperty_VirtualProperty* bsshaderlightingproperty_FilterProperty(
    bsshaderlightingproperty_VirtualProperty* p)
{
    if (p && p->type >= 8 && p->type <= 12)
        return p;
    return 0;
}
#endif
