// REVIEW-ONLY declaration closure. Requires selector_same_tu_types.h in existing modelloader.cpp.
// No function definitions, global objects, baseline changes or alternate TU.
#ifndef MODELLOADER_ADDON_GETTER_DECLARATIONS_H
#define MODELLOADER_ADDON_GETTER_DECLARATIONS_H


// Real public internal type. This declaration is ONLY for nonintegral STRUCTs;
// the actual source selects STRUCT as base for these instantiations. No helpers.
namespace _BitfieldInternal {
template <class TYPE, class STRUCT> class BitfieldBase : public STRUCT
{
};
}

class BGSAddonNode : public TESBoundObject, public TESModelTextureSwap
{
  public:
    struct _AddonNodeFlags
    {
        enum Flags
        {
            IS_MASTER_PARTICLE_SYSTEM = 1u << 0
        };
        bool bIsMasterParticleSystem : 1;
    };
    typedef _AddonNodeFlags::Flags AddonNodeFlags;
    struct AddonData
    {
        unsigned short m_usAddonNodeIndex;
        // Exact resolved public Bitfield<_AddonNodeFlags> type, no new alias.
        _BitfieldInternal::BitfieldBase<unsigned char, _AddonNodeFlags> m_ucEntryType;
    };
    unsigned int uiIndex;
    TESSound* SoundAssetTmp;
    AddonData kData;
    unsigned int uiParticleSystemIndex;
    bool IsMasterParticleSystem() const;
};

typedef char Assert_AddonFlags_Size[(sizeof(BGSAddonNode::_AddonNodeFlags) == 1) ? 1 : -1];
typedef char Assert_AddonData_Size[(sizeof(BGSAddonNode::AddonData) == 4) ? 1 : -1];
typedef char Assert_AddonData_Flags[(offsetof(BGSAddonNode::AddonData, m_ucEntryType) == 2) ? 1 : -1];
typedef char Assert_Addon_Size[(sizeof(BGSAddonNode) == 0x60) ? 1 : -1];
typedef char Assert_Addon_Index[(offsetof(BGSAddonNode, uiIndex) == 0x50) ? 1 : -1];
typedef char Assert_Addon_Sound[(offsetof(BGSAddonNode, SoundAssetTmp) == 0x54) ? 1 : -1];
typedef char Assert_Addon_Data[(offsetof(BGSAddonNode, kData) == 0x58) ? 1 : -1];
typedef char Assert_Addon_ParticleIndex[(offsetof(BGSAddonNode, uiParticleSystemIndex) == 0x5C) ? 1 : -1];
#endif
