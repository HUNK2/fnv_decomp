// bsshader/bsshadermanager.h: declares BSShaderManager
#ifndef FNV_BSSHADERMANAGER_H
#define FNV_BSSHADERMANAGER_H

#include "bsshadermanager_decls.h"
class BSShaderManager
{
  public:
    enum etShaderLevel
    {
        BSSM_SV_NONE = 0,
        BSSM_SV_1_X = 1,
        BSSM_SV_2_0 = 2,
        BSSM_SV_2_A96 = 3,
        BSSM_SV_2_B96 = 4,
        BSSM_SV_2_A = 5,
        BSSM_SV_2_B = 6,
        BSSM_SV_3_0 = 7,
        BSSM_SV_COUNT = 7
    };
    static etShaderLevel __cdecl GetSupportedShaderLevel(bool particleShader);
};
// @fnv 0x004dc060
BSShaderManager::etShaderLevel __cdecl BSShaderManager::GetSupportedShaderLevel(bool particleShader)
{
    return static_cast<etShaderLevel>(particleShader ? DAT_011f91bc : fnv_particle_shader_renderer_level);
}
#endif
