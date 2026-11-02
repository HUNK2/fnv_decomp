// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSSAVELOADFILE_H
#define FNV_BGSSAVELOADFILE_H

#include "layout_support.h"
class SaveLoadFile;
#pragma pack(push, 4)
class SaveLoadFile
{
  public:
    char m_cFileName[260];          // +0x0, 260 bytes
    BSFile* pFile;                  // +0x104, 4 bytes
    unsigned int m_uiBufferSize;    // +0x108, 4 bytes
    unsigned int m_uiFilePosition;  // +0x10C, 4 bytes
    // void __cdecl SaveLoadFile::*(const char*, bool, unsigned int)
    // void __cdecl SaveLoadFile::*()
    // unsigned int __cdecl SaveLoadFile::*(void*, unsigned int)
    // unsigned int __cdecl SaveLoadFile::*(const void*, unsigned int)
    // bool __cdecl SaveLoadFile::*()
    // unsigned int __cdecl SaveLoadFile::*()
    // unsigned int __cdecl SaveLoadFile::*()
    // void __cdecl SaveLoadFile::*(int)
    // void __cdecl SaveLoadFile::*(int)
    // const char* __cdecl SaveLoadFile::*()
    // SaveLoadFile* __cdecl SaveLoadFile::*(const char*, bool, unsigned int)
    // void __cdecl SaveLoadFile::*(const char*)
    // const char* __cdecl SaveLoadFile::*()
    // BSFile* __cdecl SaveLoadFile::*()
    // unsigned int __cdecl SaveLoadFile::*()
    // void* __cdecl SaveLoadFile::*(unsigned int)
    SaveLoadFile(const char*, bool, unsigned int);
    unsigned int Read(void*, unsigned int);
    unsigned int GetFilePosition();
    void SetFilePosition(int);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SaveLoadFile) == 272);
FNV_STATIC_ASSERT(offsetof(SaveLoadFile, m_cFileName) == 0);
FNV_STATIC_ASSERT(offsetof(SaveLoadFile, pFile) == 260);
FNV_STATIC_ASSERT(offsetof(SaveLoadFile, m_uiBufferSize) == 264);
FNV_STATIC_ASSERT(offsetof(SaveLoadFile, m_uiFilePosition) == 268);
#endif
