// bscore/console/bssemaphore_console_decls.h: declares CountingSemaphore
#ifndef BSSEMAPHORE_CONSOLE_DECLS_H
#define BSSEMAPHORE_CONSOLE_DECLS_H

class CountingSemaphore
{
  public:
    volatile int iCount;
    void* hSemaphore;
    int m_iMaximumCount;
    CountingSemaphore(int count, int maxCount);
};
typedef void*(__stdcall* BSSemaphoreCreateProc)(void*, int, int, const char*);
extern "C" BSSemaphoreCreateProc DAT_00fdf0b4;
#endif
