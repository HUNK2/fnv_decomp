// fallout_shared/tesgrass.h: declares TESGrass
#ifndef FNV_TESGRASS_H
#define FNV_TESGRASS_H

class TESGrass
{
  public:
    enum GRASS_WATER_STATE
    {
        GWS_ABOVE_ONLY_ATLEAST,
        GWS_ABOVE_ONLY_ATMOST,
        GWS_BELOW_ONLY_ATLEAST,
        GWS_BELOW_ONLY_ATMOST,
        GWS_BOTH_ATLEAST,
        GWS_BOTH_ATMOST,
        GWS_BOTH_ATMOST_ABOVE,
        GWS_BOTH_ATMOST_BELOW,
        GWS_COUNT
    };
    unsigned char layoutPrefix[0x4c];
    unsigned short m_usUnitsFromSurface;
    unsigned short layoutPadding4e;
    GRASS_WATER_STATE m_eWaterState;
    unsigned short GetUnitsFromSurface();
    void SetUnderwater(GRASS_WATER_STATE state);
};
// @fnv 0x0082d680
unsigned short TESGrass::GetUnitsFromSurface()
{
    return m_usUnitsFromSurface;
}
// @fnv 0x0058e430
void TESGrass::SetUnderwater(GRASS_WATER_STATE state)
{
    m_eWaterState = state;
}
#endif
