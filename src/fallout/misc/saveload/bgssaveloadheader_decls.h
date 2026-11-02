// fallout/misc/saveload/bgssaveloadheader_decls.h: declares SaveLoadHeader, BGSSaveLoadManager, BGSLoadGameBuffer, SaveLoadFile, NiPixelData and more
#ifndef FNV_BGSSAVELOADHEADER_DECLS_H
#define FNV_BGSSAVELOADHEADER_DECLS_H


class SaveLoadFile;
class NiPixelFormat;
class NiTexture;

class SaveLoadHeader
{
  public:
    void ReadHeaderFromFile(SaveLoadFile* file, bool temporary, unsigned int kind, unsigned int unused);
    NiTexture* LoadTextureFromFile(SaveLoadFile* file, unsigned int offset, unsigned int width, unsigned int height);
    static int ReadHeaderFromFile(SaveLoadFile* file);
};

class BGSSaveLoadManager
{
  public:
    void GetFullPath(char* filename, char* fullPath, bool temporary);
};

class BGSLoadGameBuffer
{
  public:
    BGSLoadGameBuffer();
    void FUN_008464f0(SaveLoadFile* file);
    void FUN_008463c0();
    void ReadAndVerifySize(SaveLoadFile* file);
    char* GetCombinedValue();
    void ReadDataBlock(void* buffer, unsigned int size);
    int Load();
};

class SaveLoadFile
{
  public:
    unsigned int Read(void* buffer, unsigned int size);
    void SetFilePosition(int offset);
    void AdvancePosition(unsigned int size);
};

class NiPixelData
{
  public:
    NiPixelData(unsigned int width, unsigned int height, const NiPixelFormat& format, unsigned int flags,
                unsigned int extra);
    void* FUN_0064dac0(int zero1, int zero2, unsigned int size);
};

class BSFadeNode
{
  public:
    BSFadeNode(const char* name, void* rectangle);
    void* FUN_0043b1b0();
    void FUN_004381b0();
};

class FUN_004f31d0_holder
{
  public:
    void InitIntArray();
};

class NiMemObject
{
  public:
    static void* operator new(unsigned int size);
};

int __cdecl FUN_00ecbf05(const char* path, int mode);
void* __cdecl FUN_00846520(char* path, bool temporary, unsigned int size);
int __cdecl FUN_00408b20(const char* path, const char* prefix);
NiTexture* __cdecl FUN_00a5ff10(void* pixelData, void* renderedTexture);
extern int(__cdecl* DAT_00fdf0d4)(char* path);
extern unsigned int DAT_011aa2e8;
extern char* DAT_011a2224;

extern "C" unsigned int __cdecl strlen(const char* string);
extern "C" void* __cdecl fnv_zlib_memset(void* destination, int value, unsigned int size);
extern "C" unsigned int __security_cookie;
extern "C" void __fastcall __security_check_cookie(unsigned int cookie);

#endif
