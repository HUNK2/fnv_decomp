// bsshader/bsshaderpplightingproperty_passes_1x.cpp: free functions (1 function)

#include "bsshaderpplightingproperty_passes_1x_decls.h"

int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);

struct NiGeometry
{
    char pad00[0x08];
    const char* m_kName;
    char pad0C[0x0C];
    NiGeometry* m_pParentNode;
};

struct FUN_00bdac00_t : BSShaderPPLightingProperty
{
    void* FUN_00bdac00(NiGeometry*, ShadowSceneLight*, unsigned short*, bool, bool*, bool, bool, bool, bool, bool,
                       bool);
};

// @fnv 0x00bdac00
void* FUN_00bdac00_t::FUN_00bdac00(NiGeometry* apGeom, ShadowSceneLight* apLight, unsigned short* asCount,
                                   bool abUpdateList, bool* abFirst, bool abSkinned, bool abMultitexture,
                                   bool abFacegenBlend, bool abVertexColors, bool abTreeBranch, bool abHair)
{
    if (!abSkinned)
    {
        if (!abTreeBranch)
        {
            if (!abVertexColors)
            {
                if (!abFacegenBlend)
                {
                    if (abUpdateList == 1)
                        pRenderPassList->Add(apGeom, 330, *abFirst, 0, 0, 0, 0, 0);
                    else
                        (*asCount)++;
                }
                else
                {
                    if (abUpdateList == 1)
                        pRenderPassList->Add(apGeom, 331, *abFirst, 0, 0, 0, 0, 0);
                    else
                        (*asCount)++;
                }
            }
            else if (!abHair)
            {
                if (abUpdateList == 1)
                    pRenderPassList->Add(apGeom, 334, *abFirst, 0, 0, 0, 0, 0);
                else
                    (*asCount)++;
            }
            else
            {
                if (abUpdateList == 1)
                    pRenderPassList->Add(apGeom, 332, *abFirst, 0, 0, 0, 0, 0);
                else
                    (*asCount)++;
            }
        }
        else
        {
            if (abUpdateList == 1)
                pRenderPassList->Add(apGeom, 337, *abFirst, 0, 0, 0, 0, 0);
            else
                (*asCount)++;
        }
    }
    else
    {
        if (!abFacegenBlend)
        {
            if (!abVertexColors)
            {
                if (abUpdateList == 1)
                    pRenderPassList->Add(apGeom, 333, *abFirst, 0, 0, 0, 0, 0);
                else
                    (*asCount)++;
            }
            else if (!abHair)
            {
                if (abUpdateList == 1)
                    pRenderPassList->Add(apGeom, 335, *abFirst, 0, 0, 0, 0, 0);
                else
                    (*asCount)++;
            }
            else
            {
                if (abUpdateList == 1)
                    pRenderPassList->Add(apGeom, 338, *abFirst, 0, 0, 0, 0, 0);
                else
                    (*asCount)++;
            }
        }
        else if (!abVertexColors)
        {
            if (abUpdateList == 1)
                pRenderPassList->Add(apGeom, 336, *abFirst, 0, 0, 0, 0, 0);
            else
                (*asCount)++;
        }
        else
        {
            char szName[128];
            if (apGeom)
            {
                if (apGeom->m_pParentNode && apGeom->m_pParentNode->m_kName)
                {
                    if (apGeom->m_kName)
                        _sprintf_s(szName, 128, DAT_010bc5f4, apGeom->m_pParentNode->m_kName, apGeom->m_kName);
                    else
                        _sprintf_s(szName, 128, DAT_010bc5e8, apGeom->m_pParentNode->m_kName);
                }
                else if (apGeom->m_kName)
                {
                    _sprintf_s(szName, 128, DAT_01019f08, apGeom->m_kName);
                }
                else
                {
                    _sprintf_s(szName, 128, DAT_010250cc);
                }
            }
            else
            {
                _sprintf_s(szName, 128, DAT_010250cc);
            }
            char szError[255];
            _sprintf_s(szError, 255, DAT_010bc580, szName, apGeom);
        }
    }
    *abFirst = false;
    return 0;
}
