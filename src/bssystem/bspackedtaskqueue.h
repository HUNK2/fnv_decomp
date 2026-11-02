
#include "bspackedtaskqueue_decls.h"
// @fnv 0x0087a7d0
bool PackedTaskQueueProcessor::Process()
{
    m_bIsProcessing = true;
    struct
    {
        unsigned char reserved[3];
        bool success;
        BSPackedTask task;
    } state;
    state.success = true;
    // The input count accessor shares the canonical pointer accessor's code.
    while (state.success || (int)inputSources.operator->() > 0)
    {
        state.success = vfn_10(state.task);
        if (state.success)
            m_pTaskCompletionCallback(state.task);
    }
    m_bIsProcessing = false;
    return state.success;
}
