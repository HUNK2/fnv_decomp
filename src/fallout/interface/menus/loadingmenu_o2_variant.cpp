
// src/fallout/interface/menus/loadingmenu_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/fallout/interface/menus/loadingmenu.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

#include "loadingmenu_packet.h"
class BSSystemUtility
{
  public:
    static int s_iUpdateEnabled;
    static BSSystemUtility* ms_pSystemUtility;
};
class CountingSemaphore
{
  public:
    int iCount;
    void* hSemaphore;
    int m_iMaximumCount;
    CountingSemaphore();
    ~CountingSemaphore();
    void Wait();
    void Signal();
};
class LoadingMenuThread : public BSThread
{
  public:
    CountingSemaphore m_kFirstSemaphore;
    CountingSemaphore m_kSecondSemaphore;
    volatile bool m_bFirstThreadFlag;
    volatile bool m_bSecondThreadFlag;
    volatile bool m_bThirdThreadFlag;
    LoadingMenuThread();
    unsigned int ThreadProc();
};
