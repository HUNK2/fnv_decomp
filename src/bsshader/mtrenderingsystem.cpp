// bsshader/mtrenderingsystem.cpp: TaskThreadManager, AILinearTaskThread (4 functions)

#include "mtrenderingsystem_decls.h"
// @fnv 0x004ea970
TaskThreadManager* TaskThreadManager::GetSingleton()
{
    return &DAT_01200088;
}
// @fnv 0x008c7190
void AILinearTaskThread::ExecuteTask()
{
    if (m_pTaskFunction)
        m_pTaskFunction();
}

#pragma optimize("gty", on)
// @fnv 0x00ba3720
void TaskThreadManager::StartRenderingTaskThread()
{
    if (DAT_011f94b4)
        LaunchWorkerThread(1, DAT_01200080, FUN_00ba3190, "Rendering Task Thread 2", 0x20000);
}
#pragma optimize("", off)

#pragma optimize("gty", on)
// Ends all rendered textures, then advances the renderer state from 1 to 3 or from 3 to 0 and increments frameCount when the matching check passes.
// @fnv 0x00b6b730
void TaskThreadManager::EndRenderingTaskThread()
{
    NiRenderer* renderer = NiRenderer::ms_pRenderer;
    BSRenderedTexture::EndAll();
    if (renderer->state == 1 && renderer->vfn_180())
        renderer->state = 3;
    if (renderer->state == 3 && renderer->vfn_184())
    {
        ++renderer->frameCount;
        renderer->state = 0;
    }
}
#pragma optimize("", off)
