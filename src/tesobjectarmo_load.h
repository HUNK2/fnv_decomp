// tesobjectarmo_load.h: declares TESFileFormVersion, TESFullNameLoader, TESObjectARMOOldBipedModel, TESObjectARMOOldData
#ifndef TESOBJECTARMO_LOAD_H
#define TESOBJECTARMO_LOAD_H
#include "TESFile.h"
extern "C" void* __cdecl _alloca(unsigned int);
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class TESFileFormVersion
{
  public:
    unsigned short GetFormVersion();
};
class TESFileChunkData16
{
  public:
    bool GetChunkData(unsigned short*);
};
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName*, TESFile*);
};
class TESTexture1024
{
  public:
    void SetTexture(const char*);
};
// Legacy formats retained for records written before the current armor layout.
struct TESObjectARMOOldBipedModel
{
    unsigned short slots;
    unsigned char flags;
    void FUN_00512810();
};
struct TESObjectARMOOldData
{
    unsigned short rating;
    void FUN_00512810();
};
#endif
