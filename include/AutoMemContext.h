// Source layout: AutoMemContext. PC corrections are in generate_headers.py.
#ifndef FNV_AUTOMEMCONTEXT_H
#define FNV_AUTOMEMCONTEXT_H

#include "layout_support.h"
#pragma pack(push, 4)
class AutoMemContext
{
  public:
    MEM_CONTEXT m_eMemoryContext;  // +0x0
    AutoMemContext(MEM_CONTEXT context, bool track, const char* file, int line);
    ~AutoMemContext();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(AutoMemContext) == 0x4);
FNV_STATIC_ASSERT(offsetof(AutoMemContext, m_eMemoryContext) == 0x0);
#endif
