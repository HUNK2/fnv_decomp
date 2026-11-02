// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSLOADGAMEBUFFER_TYPES_H
#define FNV_BGSLOADGAMEBUFFER_TYPES_H

#include "layout_support.h"
class SaveLoadFile;
class BGSLoadGameBuffer;
#pragma pack(push, 4)
class BGSLoadGameBuffer
{
  public:
    BGSLoadGameBuffer();
    ~BGSLoadGameBuffer();
    void ReadAndVerifySize(SaveLoadFile* file);
    void ReadDataBlock(void* data, unsigned int size);
    char* LoadString(char* prefix);
    void** m_ppVirtualMethodTable;               // +0x0, 4 bytes
    char* pBuffer;                 // +0x4, 4 bytes
    unsigned int iBufferSize;      // +0x8, 4 bytes
    unsigned int m_uiReadOffset;  // +0xC, 4 bytes
    // BGSLoadGameBuffer
    // void __cdecl BGSLoadGameBuffer::*()
    // Load
    // void __cdecl BGSLoadGameBuffer::*()
    // void __cdecl BGSLoadGameBuffer::*(char*, unsigned int, unsigned int)
    // char* __cdecl BGSLoadGameBuffer::*()
    // char* __cdecl BGSLoadGameBuffer::*(char*)
    // int __cdecl BGSLoadGameBuffer::*()
    // void __cdecl BGSLoadGameBuffer::*(unsigned int)
    // void __cdecl BGSLoadGameBuffer::*(void*, unsigned int, unsigned int)
    // void __cdecl BGSLoadGameBuffer::*(void*, unsigned int)
    // BGSLoadGameBuffer& __cdecl BGSLoadGameBuffer::*(const BGSLoadGameBuffer&)
    // void* __cdecl BGSLoadGameBuffer::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSLoadGameBuffer) == 16);
FNV_STATIC_ASSERT(offsetof(BGSLoadGameBuffer, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(BGSLoadGameBuffer, pBuffer) == 4);
FNV_STATIC_ASSERT(offsetof(BGSLoadGameBuffer, iBufferSize) == 8);
FNV_STATIC_ASSERT(offsetof(BGSLoadGameBuffer, m_uiReadOffset) == 12);
#endif
