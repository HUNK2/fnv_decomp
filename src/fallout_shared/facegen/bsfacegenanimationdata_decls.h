
extern "C" const double DAT_010231b0;
extern const double DAT_01064f58;
extern const double DAT_01064f50;
class NiQuaternion
{
  public:
    float q[4];
    void SetRotationFromEulerXYZ(float, float, float);
    bool operator!=(const NiQuaternion&) const;
    static const NiQuaternion IDENTITY;
};
class RotationValues
{
  public:
    float FUN_005dd4e0(unsigned);
};
void* __cdecl operator new(unsigned);
enum BS_FACEGEN_MORPH_TYPE
{
    PHONEME = 0,
    EXPRESSION = 1,
    MODIFIER = 2,
    CUSTOM = 3
};
template <class T> class NiTPointerList;
class BSFaceGenKeyframe
{
  public:
    virtual ~BSFaceGenKeyframe();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10(float);
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20(bool);
    virtual void vfn_24();
    virtual void vfn_28();
    virtual bool vfn_2c(BSFaceGenKeyframe*);
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    int type;
    float time;
    bool SetTime(float);
};
class BSFaceGenKeyframeMultiple : public BSFaceGenKeyframe
{
  public:
    float* quantities;
    unsigned count;
    BSFaceGenKeyframeMultiple(BS_FACEGEN_MORPH_TYPE, unsigned);
    virtual ~BSFaceGenKeyframeMultiple();
    bool FUN_0064a4d0(unsigned, float);
    bool InsertIntoKeyframeList(NiTPointerList<BSFaceGenKeyframe*>*);
};

class BSFaceGenAnimationData
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
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
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4(float, bool, bool, bool, bool, bool);
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8(BS_FACEGEN_MORPH_TYPE, float, bool);
    virtual void vfn_fc();
    virtual void vfn_100(bool, bool, bool, bool);
    virtual void vfn_104(bool, bool, bool, bool);
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    char pad[8];
    BSFaceGenKeyframeMultiple* target;
    char data[0x179];
    bool changed, p18a, dirty, p18c, p18d, dead;
    void AddModifierKeyframe(float*, float);
    void AddKeyframe(BS_FACEGEN_MORPH_TYPE, float, bool);
    void InsertPhonemeKeyframe(float*, float);
    void SetExpressionWeight(int, float);
    bool CalculateRotationQuaternion(NiQuaternion&);
    void FadeOutMorphs(float, bool, bool, bool, bool);
    void ClearTransitionTarget();
    void SetMorphFlags(bool, bool, bool, bool);
    void SetStateFlags(bool, bool);
};
