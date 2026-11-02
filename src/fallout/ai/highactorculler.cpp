// fallout/ai/highactorculler.cpp: HighActorCuller (1 function)

#include "highactorculler_decls.h"

// @fnv 0x008d6d40
void HighActorCuller::Operate(MobileObject* mobile)
{
    NiAVObject* object = mobile->Get3DSimple();
    if (object)
    {
        m_kFadeNodeCuller.Process(object);
        BSFadeNode* fade = object->GetFadeNode();
        if (fade && !fade->FUN_00552470())
        {
            NiBound bound = fade->GetBoundingVolume();
            m_spMultiBoundSphere->SetGridPosition(bound.GetNavMeshData());
            m_spMultiBoundSphere->FUN_00819a50(bound.FUN_0084d030());
            BSPortalGraph* graph = 0;
            if (g_TES->GetInteriorCell())
                graph = static_cast<HighActorCullerCell*>(g_TES->GetInteriorCell())->FUN_009d9f20();
            else if (g_TES->GetParentWorldSpace())
                graph = g_TES->GetParentWorldSpace()->FUN_006698d0();
            if (graph)
            {
                NiTPointerList<BSOcclusionPlane*>& occluders = graph->GetOccluderList();
                void* position = occluders.GetHeadPos();
                while (position)
                {
                    BSOcclusionPlane* plane = occluders.GetNext(position);
                    if (plane && plane->GetCullResult() == 1)
                    {
                        if (!m_pMultiBoundNode->CheckProcStateAndPlane(m_kFadeNodeCuller.GetCamera()->FUN_0045bb80(),
                                                                       m_kFadeNodeCuller, plane))
                            fade->SetTaskFlag(true);
                    }
                }
            }
        }
    }
}
