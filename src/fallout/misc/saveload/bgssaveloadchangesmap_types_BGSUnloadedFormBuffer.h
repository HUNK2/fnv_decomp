// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSUNLOADEDFORMBUFFER_H
#define FNV_BGSUNLOADEDFORMBUFFER_H

#include "layout_support.h"
class FormBufferContext;
#pragma pack(push, 4)
class FormBufferContext
{
  public:
    char* pBuffer;  // +0x0, 4 bytes
    FormBufferContext(char* buffer);
    // FormBufferContext
    // void __cdecl FormBufferContext::*(char*)
    // char* __cdecl FormBufferContext::*()
    // BGSLoadFormBuffer* __cdecl FormBufferContext::*()
    // Initialize
    // ENUM_FORM_ID __cdecl FormBufferContext::*()
    // SIZE_TYPE __cdecl FormBufferContext::*()
    // unsigned char __cdecl FormBufferContext::*()
    // unsigned int __cdecl FormBufferContext::*()
    // unsigned int __cdecl FormBufferContext::*()
    // void __cdecl FormBufferContext::*()
    // void __cdecl FormBufferContext::*()
    // char* __cdecl FormBufferContext::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FormBufferContext) == 4);
FNV_STATIC_ASSERT(offsetof(FormBufferContext, pBuffer) == 0);
#endif
