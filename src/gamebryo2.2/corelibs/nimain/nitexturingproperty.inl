
#include "nitexturingproperty_decls.h"

// @fnv 0x00ae8b80
unsigned char AudioLoadTask::GetFileIndex()
{
    return 2;
}

// @fnv 0x0060aeb0
void NiTexturingProperty::SetBaseMapFilterMode(FilterMode mode)
{
    Map* map = (Map*)m_kStringArray.GetAt(0);
    if (!map)
    {
        map = new Map;
        m_kStringArray.SetAt(0, (ActorCombatGroup*&)map);
    }
    map->FUN_0060af60(mode);
}

// @fnv 0x004f3200
void NiTexturingProperty::SetBaseMapClampMode(ClampMode mode)
{
    Map* map = (Map*)m_kStringArray.GetAt(0);
    if (!map)
    {
        map = new Map;
        m_kStringArray.SetAt(0, (ActorCombatGroup*&)map);
    }
    map->FUN_004f32b0(mode);
}
