// fallout/ai/actorpackage_getters.h: declares EffectSetting
class TESSound;
class EffectSetting
{
  public:
    unsigned char padding[0x88];
    TESSound* hitSound;
    TESSound* GetHitSound();
};
