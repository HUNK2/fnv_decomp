// gamebryo2.2/corelibs/niconsolerenderer/niconsolerenderer.h: declares HeightLocals, WidthLocals
#ifndef FNV_NICONSOLERENDERER_H
#define FNV_NICONSOLERENDERER_H

#include "niconsolerenderer_types_NiConsoleRenderer.h"
#include "niconsolerenderer_vtable.h"
#include "niconsolerenderer_packet.h"
#pragma optimize("", off)

// @fnv 0x004dee10
unsigned int GraphicsRenderer::GetRenderTargetWidth()
{
    struct HeightLocals
    {
        NiRenderTargetGroup* group;
        NiConsoleRendererHeightArray* array;
    } local;
    local.group = ((NiConsoleRendererRendererVTable*)this)->slot50();
    if (local.group == 0)
        return 0;
    local.array = ((NiConsoleRendererGroupVTable*)local.group)->slot44(0);
    if (local.array == 0)
        return 0;
    return local.array->GetSize();
}

// @fnv 0x004dee70
unsigned int GraphicsRenderer::GetRenderTargetHeight()
{
    struct WidthLocals
    {
        NiRenderTargetGroup* group;
        MagicCaster* caster;
    } local;
    local.group = ((NiConsoleRendererRendererVTable*)this)->slot50();
    if (local.group == 0)
        return 0;
    local.caster = ((NiConsoleRendererWidthGroupVTable*)local.group)->slot44(0);
    if (local.caster == 0)
        return 0;
    return (unsigned int)local.caster->GetSelectedMagicItem();
}

#pragma optimize("", on)
// @fnv 0x00b6b2a0
bool GraphicsRenderer::BeginUsingRenderTargetGroup(NiRenderTargetGroup* group, unsigned int clear)
{
    if ((m_iRendererState != 1 && m_iRendererState != 2) || m_bRendererFlagA)
        return false;
    if (!group)
    {
        NiD3DDefaultShader::SetShaderName(DAT_010ae590);
        return false;
    }
    fnv_EnterCriticalSection(&m_acRendererDataC);
    bool result = ((NiConsoleRendererPacketVTable*)this)->BeginGroup(group, clear);
    if (result)
        m_bRendererFlagA = true;
    else
        fnv_LeaveCriticalSection(&m_acRendererDataC);
    return result;
}
// @fnv 0x00a6fa30
bool GraphicsRenderer::MapScreenCoordinates(unsigned int x, unsigned int y, float& outX, float& outY,
                                            NiRenderTargetGroup* group)
{
    if (!group)
        group = ((NiConsoleRendererPacketVTable*)this)->GetDefaultGroup();
    unsigned int width = ((NiConsoleRendererPacketGroup*)group)->GetWidth(0);
    unsigned int height = ((NiConsoleRendererPacketGroup*)group)->GetHeight(0);
    if (width && height)
    {
        outX = (float)x / (float)width;
        outY = 1.0f - (float)y / (float)height;
        return true;
    }
    return false;
}
#endif
