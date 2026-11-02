// fallout_shared/sky/skytexturemanager.cpp: SkyTextureManager, SkyTask (5 functions)

#include "skytexturemanager_decls.h"
#include "AutoMemContext.h"

// @fnv 0x0063fb70
void SkyTextureManager::LoadTextureFromPath(NiPointer<NiTexture>* texture, const char* fileName)
{
    struct TextureRequest
    {
        SkyTask* task;
        const char* path;
    } request;
    char standardizedPath[260];
    request.path = 0;
    if (fileName)
    {
        CleanPath(fileName, standardizedPath, sizeof(standardizedPath));
        request.path = standardizedPath;
    }
    request.task = new SkyTask(texture, fileName);
    DAT_01202d98->Unk_12(request.task);
}

// Creates a sky memory context and requests the sky texture via BSShaderManager::GetTexture using GetFileName().
// @fnv 0x0063fac0
void SkyTask::Run()
{
    AutoMemContext context(MEM_CONTEXT_MEM_CONTEXT_SKY, true,
                           "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout Shared\\sky\\SkyTextureManager.cpp", 50);
    BSShaderManager::GetTexture(GetFileName(), true, *apTextureOutput, true, false);
}

extern unsigned int _data_011c16bc;
struct QBase
{
    virtual ~QBase();
    char p[0x2c];
    QBase(int);
};
struct FUN_0063fa10 : public QBase
{
    void* spTexture;
    void FUN_00c3cee0(const char*);
    void LookupFileEntryByArchive(int);
    FUN_0063fa10(void* tex, const char* name);
    virtual ~FUN_0063fa10();
};
// @fnv 0x0063fa10
FUN_0063fa10::FUN_0063fa10(void* apTexture, const char* name) : QBase(3)
{
    spTexture = apTexture;
    FUN_00c3cee0(name);
    LookupFileEntryByArchive(1);
}

struct FUN_00c3d0e0_stub
{
    bool FUN_00c3d0e0(char*, unsigned int, const char*);
};

struct FUN_0063fb40_shell
{
    bool GetDescription(char*, unsigned int);
};

// @fnv 0x0063fb40
bool FUN_0063fb40_shell::GetDescription(char* apDescription, unsigned int aiBufferSize)
{
    return ((FUN_00c3d0e0_stub*)this)->FUN_00c3d0e0(apDescription, aiBufferSize, "skytask");
}

void __cdecl _Deallocate(void*);
struct FUN_0063fa90_shell
{
    void FUN_00905c30();
    void* DeleteIfFlagged(unsigned int);
};
// Calls FUN_00905c30, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x0063fa90
void* FUN_0063fa90_shell::DeleteIfFlagged(unsigned int flags)
{
    FUN_00905c30();
    if (flags & 1)
        _Deallocate(this);
    return this;
}
