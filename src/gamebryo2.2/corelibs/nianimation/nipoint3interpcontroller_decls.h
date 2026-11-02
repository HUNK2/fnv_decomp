// gamebryo2.2/corelibs/nianimation/nipoint3interpcontroller_decls.h: declares NiKeyBasedInterpolator, NiBoolInterpController
class NiStream;
class NiBoolInterpolator;
class NiKeyBasedInterpolator
{
  public:
    NiKeyBasedInterpolator();
};
class NiBoolInterpController
{
  public:
    NiBoolInterpolator* LinkObject(NiStream*);
};
extern unsigned char DAT_0109a914;
extern unsigned int DAT_0109a0b4;
extern unsigned int DAT_011f404c;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);

inline void* operator new(unsigned int, NiBoolInterpController& p)
{
    return &p;
}
