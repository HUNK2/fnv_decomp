#ifndef FNV_INTERFACE_REBASE_FNV_BSTIMER_H
#define FNV_INTERFACE_REBASE_FNV_BSTIMER_H
#include "interface_rebase_layout_support.h"
class GameTimerRecord
{
  public:
    unsigned char m_ucFirstTimerByte;  // +0x0
    unsigned char layoutPadding1[3];
    float m_fFirstTimerValue;           // +0x4
    float m_fSecondTimerValue;          // +0x8
    float fTimeSinceScaleStart;         // +0xC
    float m_fFourthTimerValue;          // +0x10
    unsigned int m_uiFirstTimerValue;   // +0x14
    unsigned int m_uiSecondTimerValue;  // +0x18
    bool m_bFirstTimerFlag;             // +0x1C
    bool m_bSecondTimerFlag;            // +0x1D
    unsigned char layoutPadding1E[2];
};
FNV_STATIC_ASSERT(sizeof(GameTimerRecord) == 0x20);
FNV_STATIC_ASSERT(offsetof(GameTimerRecord, m_ucFirstTimerByte) == 0x0);
FNV_STATIC_ASSERT(offsetof(GameTimerRecord, m_fFirstTimerValue) == 0x4);
FNV_STATIC_ASSERT(offsetof(GameTimerRecord, m_fSecondTimerValue) == 0x8);
FNV_STATIC_ASSERT(offsetof(GameTimerRecord, fTimeSinceScaleStart) == 0xC);
FNV_STATIC_ASSERT(offsetof(GameTimerRecord, m_fFourthTimerValue) == 0x10);
FNV_STATIC_ASSERT(offsetof(GameTimerRecord, m_uiFirstTimerValue) == 0x14);
FNV_STATIC_ASSERT(offsetof(GameTimerRecord, m_uiSecondTimerValue) == 0x18);
FNV_STATIC_ASSERT(offsetof(GameTimerRecord, m_bFirstTimerFlag) == 0x1C);
FNV_STATIC_ASSERT(offsetof(GameTimerRecord, m_bSecondTimerFlag) == 0x1D);
#endif
