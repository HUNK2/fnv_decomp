
#include "bslineartaskthread_decls.h"
// @fnv 0x008c7720
unsigned int BSLinearTaskThread::ThreadProc()
{
    vfn_08();
    while (!m_bStopRequested)
    {
        m_kWorkAvailableSemaphore.Wait();
        if (m_bStopRequested)
            break;
        vfn_10();
        m_kCompletionSemaphore.Signal();
    }
    vfn_0c();
    m_kCompletionSemaphore.Signal();
    return 0;
}
// @fnv 0x008c76a0
BSLinearTaskThread::BSLinearTaskThread()
{
    m_bStopRequested = false;
}
