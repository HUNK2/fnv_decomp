// gamebryo2.2/corelibs/nianimation/nicontrollermanager_decls.h: declares NiControllerManagerSequences, NiControllerManager, NiControllerSequence

class NiFixedString;
extern NiFixedString* DAT_011c61e0;
class NiControllerSequence;
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    unsigned int GetSize();
};
class NiControllerManagerSequences : public BSSimpleArray<unsigned int, 1024>
{
  public:
    NiControllerSequence*& FUN_00629ab0(unsigned int);
};
class NiControllerManager
{
  public:
    static NiFixedString* FindSequenceByName();
    bool StopSequence(NiControllerSequence*, float);
    bool ActivateControllerSequence(NiControllerSequence*, int, bool, float, float, NiControllerSequence*);
    void DeactivateAllSequences(float);

  private:
    char padding[0x44];
    NiControllerManagerSequences sequences;
};

class NiControllerSequence
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
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual bool Deactivate(float, bool);
    bool Activate(char, bool, float, float, NiControllerSequence*, bool);
};
