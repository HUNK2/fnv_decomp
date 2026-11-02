// tesregiondatasound_decls.h: declares TESFile, TESForm, BGSMusicType, RegionDataEntry, RegionSoundEntry and more
#ifndef TESREGIONDATASOUND_DECLS_H
#define TESREGIONDATASOUND_DECLS_H

void* __cdecl operator new(unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete(void*);
void __cdecl operator delete[](void*);
class TESFile
{
  public:
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool IsEndianConversionRequired();
    bool GetChunkData(unsigned int*);
    bool GetChunkData(void*, unsigned int);
};
class TESForm
{
  public:
    virtual void vfn_00();
    static TESForm* GetFormByID(unsigned int);
    static void RemapFormIDForFile(unsigned int&, TESFile*);
};
class BGSMusicType : public TESForm
{
};
class RegionDataEntry
{
  public:
    unsigned int data;
    void Endian();
};
class RegionSoundEntry
{
  public:
    unsigned int sound, flags, chance;
    RegionSoundEntry();
    void Endian();
};
template <class T> class BSSimpleList
{
  public:
    T item;
    void* next;
    void AddTail(T const&);
};
class ScriptVariableInfo;
class ContainerItemExtraFileData
{
  public:
    void Endian();
};
class TESDataHandler
{
  public:
    unsigned int FUN_004615d0(unsigned int);
};
extern TESDataHandler* g_dataHandler;
int __cdecl Warning(const char*, ...);
class TESRegionDataSound
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
    virtual BGSMusicType* GetMusicType();
    virtual void SetMusicType(BGSMusicType*);
    unsigned int pad4;
    RegionDataEntry Data;
    BSSimpleList<RegionSoundEntry*> Sounds;
    unsigned int incidental;
    BSSimpleList<unsigned int> Battle;
    bool LoadRegionSoundData(TESFile*);
};
#endif
