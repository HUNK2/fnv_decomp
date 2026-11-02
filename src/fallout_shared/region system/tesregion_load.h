// fallout_shared/region system/tesregion_load.h: declares TESFile, TESRegionDataManager, TESRegionLoadHandler, TESRegionLoadList
#ifndef TESREGION_LOAD_H
#define TESREGION_LOAD_H

#include <malloc.h>
class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool GetChunkData(unsigned int*);
    bool NextChunk();
};
class TESRegionDataManager
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual bool Load(TESFile*, TESRegion*);
};
class TESRegionLoadHandler
{
  public:
    TESRegionDataManager* GetRegionDataManager();
};
extern TESDataHandler* g_dataHandler;
class TESRegionLoadList
{
  public:
    void Remove(RegionPointList* const&);
};
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
#endif
