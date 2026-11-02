// gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderfactory_decls.h: declares NiShaderFactory, NiD3DShaderFactory, NiMemObject, NiStringMapStorage
#ifndef FNV_NID3DSHADERFACTORY_DECLS_H
#define FNV_NID3DSHADERFACTORY_DECLS_H

class IMemoryHeap;
#include "MemoryManager.h"
class NiShaderFactory
{
  public:
    void* m_ppVirtualMethodTable;
    bool m_shutdown;
    unsigned char m_ucUnknownByte[31];
};
class NiD3DShaderFactory : public NiShaderFactory
{
  public:
    void* m_pOwnerShader;
    void* m_pShaderMapStorage;
    void* m_pShaderLibraryIterator;
    void* m_pShaderLibraryStorage;
    unsigned char m_padding34[76];
    unsigned char m_kShaderMap[128];
    void ShutdownPoint3();
    void InitializePoint3();
    void UpdateShaderMaterialCache(void*);
    void FUN_00aa0390();
    NiShaderFactory* Create();
};
class NiMemObject
{
  public:
    static void* __cdecl operator new(unsigned int);
};
class NiD3DDefaultShader
{
  public:
    static void __cdecl SetShaderName(const char*);
};
struct NiStringMapStorage
{
    void* m_ppVirtualMethodTable;
    unsigned int m_hashSize;
    void* m_hashTable;
    unsigned int m_unused;
    bool m_sState;
};
extern void* DAT_011f4a64;
extern void* DAT_0126fa0c;
extern void* DAT_011f6044;
extern void* DAT_010f0bc0;
extern void* DAT_010f0c20;
extern void* DAT_010f0c80;
extern void* DAT_010f0ca0;
extern void(__stdcall* DAT_00fdf054)(void*);
extern unsigned char kVtbl_NiD3DShaderFactory;
extern MemoryManager g_memoryManager;
extern "C" void* __cdecl NiMalloc(unsigned int);
extern "C" void* __cdecl fnv_zlib_memset(void*, int, unsigned long);
#endif
