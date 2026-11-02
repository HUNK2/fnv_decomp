// gamebryo2.2/corelibs/nianimation/nisingleinterpcontroller_decls.h: declares NiObject, NiStream, NiInterpolator, NiTimeController, NiInterpController and more
#pragma once

class CloningProcess;
class NiStream;
class NiObject;
class NiObject
{
  public:
    virtual void vfn_00();
    virtual void DeleteThis();
    long refCount;
};
class NiStream
{
  public:
    unsigned char data[0xd8];
    unsigned int version;
    NiObject* DeserializeObject();
};
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
class NiInterpolator
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void ProcessClone(CloningProcess&);
};
class NiTimeController
{
  public:
    virtual void ProcessClone(CloningProcess&);
    unsigned char data[48];
};
class NiInterpController : public NiTimeController
{
  public:
    virtual void LoadBinary(NiStream&);
};
class NiSingleInterpController : public NiInterpController
{
  public:
    NiInterpolator* m_spControllerInterpolator;
    virtual void ProcessClone(CloningProcess&);
    virtual void LoadBinary(NiStream&);
};
