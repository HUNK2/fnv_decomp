#ifndef FNV_SHADOWSCENENODE_H
#define FNV_SHADOWSCENENODE_H

#include "shadowscenenode_fog_decls.h"

// @fnv 0x00b54110
void ShadowSceneNode::SetFogPropertyForIndex(BSFogProperty* property)
{
    if (!property)
    {
        m_spFogProperty = new BSFogProperty;
        m_spFogProperty->SetFog(500000.0f, 500000.0f);
        m_spFogProperty->SetPower(1.0f);
        m_spFogProperty->SetWaterFog(500000.0f, 500000.0f);
        m_spFogProperty->SetColor(NiColor(0.5f, 0.5f, 0.5f));
        m_spFogProperty->SetWaterColor(NiColor(0.5f, 0.5f, 0.5f));
    }
    else
    {
        m_spFogProperty = property;
    }
}
#endif
