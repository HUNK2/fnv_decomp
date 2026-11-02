// bsshader/bsshaderpplightingproperty.h: declares BGSTerrainManager, BSShaderPPLightingProperty
#ifndef FNV_BSSHADERPPLIGHTINGPROPERTY_UNIT_H
#define FNV_BSSHADERPPLIGHTINGPROPERTY_UNIT_H

class BGSTerrainManager
{
    unsigned char layoutPadding[0x1c];
    unsigned int minLevel;

  public:
    unsigned int GetMinLevel();
};
// @fnv 0x00441110
unsigned int BGSTerrainManager::GetMinLevel()
{
    return minLevel;
}

class BSShaderPPLightingProperty
{
    unsigned char layoutPadding[0x0a];
    unsigned short diffuseTexture;

  public:
    unsigned short GetDiffuseTextureIndex();
};
// @fnv 0x0047d3f0
unsigned short BSShaderPPLightingProperty::GetDiffuseTextureIndex()
{
    return diffuseTexture;
}
#endif
