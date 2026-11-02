// fallout/ai/character_packet.h: declares Character, MiddleHighProcess
#ifndef FNV_CHARACTER_PACKET_H
#define FNV_CHARACTER_PACKET_H
class Character
{
  public:
    unsigned char layoutPadding000[0x1C1];
    bool m_bActorGuard;
    bool GetActorGuard();
    void SetActorGuardState(bool guard);
};
class MiddleHighProcess
{
  public:
    unsigned char layoutPadding000[0x1D4];
    float m_fAnimationSpeed;
    float GetVisibilityAlpha();
};
#endif
