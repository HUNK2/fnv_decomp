// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NIBINARYSTREAM_H
#define FNV_NIBINARYSTREAM_H
#include "layout_support.h"
class NiBinaryStream;
#pragma pack(push, 4)
class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;               // +0x0, 4 bytes
    unsigned int m_uiStreamFlags;  // +0x4, 4 bytes
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*,
                                     unsigned int);  // +0x8, 4 bytes
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*,
                                      unsigned int);  // +0xC, 4 bytes
    // NiBinaryStream
    // unsigned int __cdecl NiBinaryStream::*(void*, unsigned int, unsigned int*, unsigned int)
    // unsigned int __cdecl NiBinaryStream::*(const void*, unsigned int, unsigned int*, unsigned int)
    // unsigned int __cdecl NiBinaryStream::*(void*, unsigned int)
    // unsigned int __cdecl NiBinaryStream::*(const void*, unsigned int)
    // unsigned int __cdecl NiBinaryStream::*(char*, unsigned int)
    // unsigned int __cdecl NiBinaryStream::*(const char*)
    // bool __cdecl NiBinaryStream::*()
    // void __cdecl NiBinaryStream::*(bool)
    // void __cdecl NiBinaryStream::*(const unsigned int)
    // void __cdecl NiBinaryStream::*(void*, unsigned int, unsigned int*, unsigned int)
    // NiBinaryStream& __cdecl NiBinaryStream::*(const NiBinaryStream&)
    // void __cdecl NiBinaryStream::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiBinaryStream) == 16);
FNV_STATIC_ASSERT(offsetof(NiBinaryStream, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(NiBinaryStream, m_uiStreamFlags) == 4);
FNV_STATIC_ASSERT(offsetof(NiBinaryStream, m_pfnRead) == 8);
FNV_STATIC_ASSERT(offsetof(NiBinaryStream, m_pfnWrite) == 12);
#endif
