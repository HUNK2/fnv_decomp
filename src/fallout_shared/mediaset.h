// fallout_shared/mediaset.h: declares MediaSet, MediaSetEntry
#ifndef FNV_MEDIASET_LOCAL_H
#define FNV_MEDIASET_LOCAL_H

#include "layout_support.h"
#include "TESForm.h"
#include "TESFullName.h"
class MediaSet : public TESForm, public TESFullName
{
  public:
    class MediaSetEntry
    {
      public:
        BSStringT<char> Name;
        float Attenuation;
        float Percent;
        MediaSetEntry();
    };
    enum MEDIASETTYPE
    {
        BATTLE = 0,
        LAYER_LOCATION = 1,
        LAYER_DUNGEON = 2,
        INCIDENTAL = 3,
        SETTYPE_COUNT = 4
    };
    unsigned int m_uiMediaValue1;
    unsigned int m_uiMediaValue2;
    unsigned int m_uiMediaValue3;
    bool bEffectFlag;
    bool m_bActorStateFlag;
    bool m_bCountWasNonzero;
    bool m_bConditionWasTrue;
    char m_cMediaState;
    TESFullName m_kFullName;
    MEDIASETTYPE Type;
    MediaSetEntry m_kMediaSetEntry1;
    MediaSetEntry m_kMediaSetEntry2;
    MediaSetEntry m_kMediaSetEntry3;
    MediaSetEntry m_kMediaSetEntry4;
    MediaSetEntry m_kMediaSetEntry5;
    MediaSetEntry m_kMediaSetEntry6;
    char m_cMediaFlag;
    float m_fMediaParameter1;
    float fSkillValueBonus;
    float m_fMediaParameter3;
    float m_fMediaValue;
    TESSound* m_pSound1;
    TESSound* m_pSound2;
    bool Update(unsigned int auiTime, bool abForce, MediaLocationController* apController);
};
FNV_STATIC_ASSERT(sizeof(MediaSet) == 0xC4);
FNV_STATIC_ASSERT(offsetof(MediaSet, m_kFullName) == 0x38);
FNV_STATIC_ASSERT(offsetof(MediaSet, m_kMediaSetEntry1) == 0x48);
FNV_STATIC_ASSERT(sizeof(MediaSet::MediaSetEntry) == 0x10);
FNV_STATIC_ASSERT(offsetof(MediaSet::MediaSetEntry, Name) == 0);
FNV_STATIC_ASSERT(offsetof(MediaSet::MediaSetEntry, Attenuation) == 8);
FNV_STATIC_ASSERT(offsetof(MediaSet::MediaSetEntry, Percent) == 12);
#endif
