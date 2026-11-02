
#include "memorypool_console_decls.h"
// @fnv 0x00aa6610
bool MemoryPool::CommitPage(unsigned int pageIndex, char*& page)
{
    page = m_pPoolBase + (pageIndex << 12);
    return VirtualAlloc(page, 4096, 4096, 4) != 0;
}
