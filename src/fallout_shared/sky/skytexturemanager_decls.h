// fallout_shared/sky/skytexturemanager_decls.h: declares SkyTextureManager, IOManager, BSShaderManager
#ifndef FNV_SKYTEXTUREMANAGER_DECLS_H
#define FNV_SKYTEXTUREMANAGER_DECLS_H

#include "skytexturemanager_task_decls.h"

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* object);
bool __cdecl CleanPath(const char* path, char* output, unsigned int outputSize);

class SkyTextureManager
{
  public:
    static void LoadTextureFromPath(NiPointer<NiTexture>* texture, const char* fileName);
};

// Only the virtual interface used by this unit is required here.
class IOManager
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void Unk_12(SkyTask* task);
};
extern IOManager* DAT_01202d98;

class BSShaderManager
{
  public:
    static void GetTexture(const char* fileName, bool load, NiPointer<NiTexture>& texture, bool useMipmaps,
                           bool keepPixels);
};
#endif
