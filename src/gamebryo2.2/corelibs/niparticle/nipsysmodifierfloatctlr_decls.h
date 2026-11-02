// gamebryo2.2/corelibs/niparticle/nipsysmodifierfloatctlr_decls.h: declares NiMemObject, NiObject, NiStream, NiFloatInterpolator, NiPSysModifierCtlr and more
#ifndef NIPSYSMODIFIERFLOATCTLR_DECLS_H
#define NIPSYSMODIFIERFLOATCTLR_DECLS_H

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiMemObject
{
  public:
    static void* operator new(unsigned int) throw();
};
class NiObject
{
  public:
    virtual void vfn_0();
    virtual void DeleteThis();
    long refs;
};
class NiFloatData;
class NiStream
{
  public:
    unsigned char pad[0xd8];
    unsigned int version;
    NiObject* GetLoadedObject();
};
class NiFloatInterpolator : public NiObject, public NiMemObject
{
  public:
    unsigned char pad[16];
    NiFloatInterpolator(NiFloatData*) throw();
};
class NiPSysModifierCtlr
{
  public:
    unsigned char pad[0x34];
    NiObject* interpolator;
    void LinkObject(NiStream&);
};
class NiPSysModifierFloatCtlr : public NiPSysModifierCtlr
{
  public:
    void LinkObject(NiStream&);
};
#endif
