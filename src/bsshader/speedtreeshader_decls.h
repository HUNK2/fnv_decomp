// bsshader/speedtreeshader_decls.h: declares NiD3DShaderConstantMap, SpeedTreeLeafShaderConstantMapSetup
#ifndef SPEEDTREESHADER_DECLS_H
#define SPEEDTREESHADER_DECLS_H

class NiD3DShaderConstantMap
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual unsigned int vfn_08(const char*, unsigned int, unsigned int, unsigned int, unsigned int, const char*,
                                unsigned int, unsigned int, const void*, bool);
};
class SpeedTreeLeafShaderConstantMapSetup
{
  public:
    static void ConfigureShaderConstantMap(NiD3DShaderConstantMap*, int);
};
extern float DAT_01200678[4];
extern float DAT_01200688[64];
#endif
