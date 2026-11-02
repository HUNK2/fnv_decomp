// fallout/ai/combat/combattimer_decls.h: declares BGSLoadFormBuffer, BGSLoadGameBuffer, Actor
#ifndef COMBATTIMER_DECLS_H
#define COMBATTIMER_DECLS_H

class BGSLoadFormBuffer
{
  public:
    void ReadTypedData(void*, unsigned int);
};
class BGSLoadGameBuffer : public BGSLoadFormBuffer
{
};
class Actor
{
  public:
    static float GetActorScale();
};
extern float DAT_0108e360;
extern float DAT_011f1bf0;
class CombatTargetTimestamp
{
  public:
    float fTimeStamp;
    void LoadGame(BGSLoadGameBuffer*);
};
class TimeoutTimer
{
  public:
    float m_fStartTime;
    float m_fTimeout;
    void LoadGame(BGSLoadFormBuffer*);
};
#endif
