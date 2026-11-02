// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <windows.h>
struct S_0082f1f0_Lock
{
    CRITICAL_SECTION m_cs;
    void FUN_0082f1f0();
};

// @fnv 0x0082f1f0
void S_0082f1f0_Lock::FUN_0082f1f0()
{
    LeaveCriticalSection(&m_cs);
}
