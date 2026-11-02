// bsshader/bsshader_compile_decls.h: declares _FILETIME, NiBinaryStream, FileFinder, ShaderBufferCollection, ShaderBufferTableBuilder and more
#ifndef BSSHADER_COMPILE_DECLS_H
#define BSSHADER_COMPILE_DECLS_H

#include "bsshader_decls.h"
class IMemoryHeap;
#include "MemoryManager.h"

extern MemoryManager g_memoryManager;
extern "C" unsigned int __security_cookie;
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" int strcpy_s(char*, unsigned int, const char*);
extern "C" int strcat_s(char*, unsigned int, const char*);
extern "C" int sprintf_s(char*, unsigned int, const char*, ...);
struct _iobuf;
extern "C" _iobuf* fopen(const char*, const char*);
extern "C" unsigned int fwrite(const void*, unsigned int, unsigned int, _iobuf*);
extern "C" int fclose(_iobuf*);
struct _D3DXMACRO
{
    const char* Name;
    const char* Definition;
};
struct _FILETIME
{
    unsigned int dwLowDateTime, dwHighDateTime;
};
class BSFile;
class NiBinaryStream
{
  public:
    unsigned int Read(void*, unsigned int);
};
class FileFinder
{
  public:
    static BSFile* GetFile(const char*, NiFile::OpenMode, unsigned int, unsigned int);
    static bool GetFileTime(const char*, _FILETIME&, unsigned int);
};
class ShaderBufferRecord;
class ShaderBufferCollection
{
  public:
    ShaderBufferRecord* Get(const char*);
};
class ShaderBufferTableBuilder
{
  public:
    void Add(const char*, char*, unsigned int);
};
class ID3DXBuffer;
class ID3DXConstantTable;
class ID3DXInclude;
extern "C" long __stdcall D3DXCompileShader(const char*, unsigned int, const _D3DXMACRO*, ID3DXInclude*, const char*,
                                            const char*, unsigned long, ID3DXBuffer**, ID3DXBuffer**,
                                            ID3DXConstantTable**);
class NiMemObjectAllocation
{
  public:
    static void* operator new(unsigned int);
};
class NiD3DVertexShader
{
  public:
    // This aliases the constructor entry: MSVC inline assembly cannot name a constructor.
    NiD3DVertexShader* Construct(GraphicsRenderer*);
};
extern GraphicsRenderer* g_pkRenderer;
extern char DAT_011f9200[260];
extern bool DAT_011f941e;
extern bool DAT_011ae638;
extern bool DAT_011f94a7;
extern ShaderBufferCollection* DAT_011f9498;
extern ShaderBufferTableBuilder* DAT_011f9494;
void BuildShaderCachePath(char*, const char*, const char*, const char*);
void HasFileInArchives(const char*);

// Pooled strings, the include vtable and the compiler exception handler.

int FUN_00f2d322(void*, void*, void*, void*);
extern const unsigned char DAT_01011584[];
extern const unsigned char DAT_01012630[];
extern const unsigned char DAT_01063ec8[];
extern const unsigned char DAT_0106e798[];
extern const unsigned char DAT_01094d90[];
extern const unsigned char DAT_010bc610[];
extern const unsigned char DAT_010bc754[];
extern const unsigned char DAT_010bc784[];
extern const unsigned char DAT_010bc7b8[];
extern const unsigned char DAT_010bc7e4[];
extern const unsigned char DAT_010bc7fc[];
extern const unsigned char DAT_010bc808[];
extern const unsigned char DAT_010bc820[];
extern const unsigned char DAT_010bc824[];
extern const unsigned char DAT_010bc828[];
extern const unsigned char DAT_010bc82c[];
extern const unsigned char DAT_010bc860[];
extern const unsigned char DAT_010bc868[];
void FUN_00ec8660();
#endif
