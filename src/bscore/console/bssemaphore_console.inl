
#include "bssemaphore_console_decls.h"

// @fnv 0x0086c6a0
CountingSemaphore::CountingSemaphore(int count, int maxCount)
{
    iCount = count;
    m_iMaximumCount = maxCount;
    hSemaphore = DAT_00fdf0b4(0, iCount, m_iMaximumCount, 0);
}
