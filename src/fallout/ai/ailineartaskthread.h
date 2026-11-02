
#include "ailineartaskthread_decls.h"
// @fnv 0x008c7630
AILinearTaskThread::AILinearTaskThread(void(__cdecl* taskFunction)())
{
    m_pTaskFunction = taskFunction;
}
