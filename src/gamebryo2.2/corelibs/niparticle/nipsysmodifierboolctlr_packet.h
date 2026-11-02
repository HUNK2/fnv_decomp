// gamebryo2.2/corelibs/niparticle/nipsysmodifierboolctlr_packet.h: declares NiFixedString, NiTimeController
#ifndef NIPSYSMODIFIERBOOLCTLR_PACKET_H
#define NIPSYSMODIFIERBOOLCTLR_PACKET_H


class NiFixedString
{
  public:
    const char* value;
};
extern NiFixedString EmptyFS;

class NiTimeController
{
  public:
    void SetControllerActive(bool);
};

extern void* NiPSysModifierCtlr_vtable[];
extern void* DAT_012027c8;

#endif
