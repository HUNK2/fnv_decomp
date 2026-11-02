// bscore/console/memorypool_console_decls.h: declares MemoryPool
#ifndef MEMORYPOOL_CONSOLE_DECLS_H
#define MEMORYPOOL_CONSOLE_DECLS_H

class MemoryPool
{
  public:
    const char* pDescription;
    char* m_pPoolBase;
    bool CommitPage(unsigned int pageIndex, char*& page);
};
extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void*, unsigned long, unsigned long, unsigned long);
#endif
