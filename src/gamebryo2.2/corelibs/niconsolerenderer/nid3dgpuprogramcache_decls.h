// gamebryo2.2/corelibs/niconsolerenderer/nid3dgpuprogramcache_decls.h: declares NiD3DGPUProgramCache
extern "C" unsigned int fnv_particle_shader_renderer_level;
extern unsigned int DAT_011f91bc;
class NiD3DGPUProgramCache
{
  public:
    static const char* GetVertexShaderProfile();
    static const char* GetPixelShaderProfile(bool usePixelLevel);
};
