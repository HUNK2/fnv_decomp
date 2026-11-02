// fallout/ai/combat/combatprocedureattackmelee_timer.h: declares Actor
#ifndef COMBATPROCEDUREATTACKMELEE_TIMER_H
#define COMBATPROCEDUREATTACKMELEE_TIMER_H

class Actor
{
  public:
    static float GetActorScale();
};
class TimeoutTimer
{
  public:
    float m_fStartTime;
    float m_fTimeout;
    bool CheckTimer();
};
#endif
