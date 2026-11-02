// Authored declarations for the EnchantmentItem magic-effect unit
// (fallout_shared/magic/enchantmentitem.h). The canonical generated headers
// do not yet carry these magic temp-effect declarations, so this header keeps
// the translation unit self-contained. Canonical additions requested from the
// operator:
//   - a canonical generated enchantmentitem.h layout for MagicHitEffect and
//     MagicShaderHitEffect once more of each class is reconstructed.
// `virtual TEMP_EFFECT_TYPE GetType()`) and the CodeView TEMP_EFFECT_TYPE
// enumerators, whose values are reproduced verbatim.
#ifndef FNV_ENCHANTMENTITEM_H
#define FNV_ENCHANTMENTITEM_H

enum TEMP_EFFECT_TYPE
{
    TEMP_EFFECT_DECAL = 0,
    TEMP_EFFECT_GEOMETRY_DECAL = 1,
    TEMP_EFFECT_PARTICLE = 2,
    TEMP_EFFECT_DEFAULT = 3,
    MAGIC_HIT_EFFECT_DEFAULT = 4,
    MAGIC_HIT_EFFECT_MODEL = 5,
    MAGIC_HIT_EFFECT_SHADER = 6
};

class MagicHitEffect
{
  public:
    virtual TEMP_EFFECT_TYPE GetType();
};

class MagicShaderHitEffect : public MagicHitEffect
{
  public:
    virtual TEMP_EFFECT_TYPE GetType();
};

#endif
