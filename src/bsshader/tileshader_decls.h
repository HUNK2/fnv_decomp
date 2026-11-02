// bsshader/tileshader_decls.h: declares NiPropertyState, NiMaterialPropertyView, NiRendererSpecificPropertyView, TileShader
#ifndef FNV_TILESHADER_DECLS_H
#define FNV_TILESHADER_DECLS_H


class NiPropertyState
{
  public:
    void* m_spProperties[7];
};

class NiMaterialPropertyView
{
  public:
    unsigned char pad[0xAC];
    bool m_bUnknown;
};

class NiRendererSpecificPropertyView
{
  public:
    unsigned char pad[0x18];
    unsigned char m_ucFlags;
};

class TileShader
{
  public:
    void UpdateMaterial(const NiPropertyState* state);
};

void AddToCounterIfIdle(unsigned int, unsigned int);
void UpdateRendererStateCount(unsigned int, unsigned int);

#endif
