// fallout_shared/imagespacemodifierinstance_effects.h: declares NiAVObject, ImageSpaceManager, ImageSpaceModifierInstanceDRB, ImageSpaceModifierInstanceDOF
#ifndef FNV_IMAGESPACEMODIFIERINSTANCE_EFFECTS_H
#define FNV_IMAGESPACEMODIFIERINSTANCE_EFFECTS_H

class NiBound;
// Call declarations only; no NiAVObject member data is accessed here.
class NiAVObject : public NiObject
{
  public:
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
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void UpdateWorldBound();
    const NiBound& GetBoundingVolume() const;
};
class ImageSpaceManager
{
  public:
    static ImageSpaceManager* FUN_004e3270();
    void SetIfHigherPriority(float, unsigned int, float, float, float, float, const NiPoint2&);
    void ApplyDepthOfFieldModifier(float, unsigned int, float, float, const NiBound&);
    void SetDepthOfFieldParameters(float, unsigned int, float, float, float);
    void SetDistanceEffect(float, unsigned int, float, const NiBound&);
};
enum ImageSpaceModifierInstanceDRB__DepthOfFieldMode
{
    ImageSpaceModifierInstanceDRB__DepthOfFieldMode_DOF_FRONT_BACK = 0,
    ImageSpaceModifierInstanceDRB__DepthOfFieldMode_DOF_FRONT = 1,
    ImageSpaceModifierInstanceDRB__DepthOfFieldMode_DOF_BACK = 2,
    ImageSpaceModifierInstanceDRB__DepthOfFieldMode_DOF_NONE = 3
};
#pragma pack(push, 4)
class ImageSpaceModifierInstanceDRB : public ImageSpaceModifierInstanceTemp, public NiMemObjectAllocation
{
  public:
    enum DepthOfFieldMode
    {
        DOF_FRONT_BACK,
        DOF_FRONT,
        DOF_BACK,
        DOF_NONE
    };
    ImageSpaceModifierInstanceDRB(float, float, NiAVObject*, float, DepthOfFieldMode, float, float, float, float, float,
                                  float, const NiPoint2&);
    static ImageSpaceModifierInstanceDRB* Trigger(float, float, DepthOfFieldMode, float, float, float, float, float,
                                                  const NiPoint2&, float);
    void Apply();
    // base ImageSpaceModifierInstanceTemp at +0x0, size 32
    float m_fRampUp;         // +0x20, 4 bytes
    float fStart;            // +0x24, 4 bytes
    float m_fRampDown;       // +0x28, 4 bytes
    float m_fRampDownStart;  // +0x2C, 4 bytes
    NiPoint2 Center;         // +0x30, 8 bytes
    float fDistance;         // +0x38, 4 bytes
    float fImpulseRadiusSquared;            // +0x3C, 4 bytes
    DepthOfFieldMode Mode;   // +0x40, 4 bytes
    // ImageSpaceModifierInstanceDRB
    // void __cdecl ImageSpaceModifierInstanceDRB::*()
    // Trigger
    // void __cdecl ImageSpaceModifierInstanceDRB::*(float)
    // void __cdecl ImageSpaceModifierInstanceDRB::*(float)
    // void __cdecl ImageSpaceModifierInstanceDRB::*(float)
    // void __cdecl ImageSpaceModifierInstanceDRB::*(float)
    // void __cdecl ImageSpaceModifierInstanceDRB::*(const NiPoint2&)
    // float __cdecl ImageSpaceModifierInstanceDRB::*()
    // float __cdecl ImageSpaceModifierInstanceDRB::*()
    // float __cdecl ImageSpaceModifierInstanceDRB::*()
    // float __cdecl ImageSpaceModifierInstanceDRB::*()
    // NiPoint2 __cdecl ImageSpaceModifierInstanceDRB::*()
    // void __cdecl ImageSpaceModifierInstanceDRB::*(float)
    // float __cdecl ImageSpaceModifierInstanceDRB::*()
    // void __cdecl ImageSpaceModifierInstanceDRB::*(float)
    // float __cdecl ImageSpaceModifierInstanceDRB::*()
    // void __cdecl ImageSpaceModifierInstanceDRB::*(ImageSpaceModifierInstanceDRB::DepthOfFieldMode)
    // ImageSpaceModifierInstanceDRB::DepthOfFieldMode __cdecl ImageSpaceModifierInstanceDRB::*()
    // void __cdecl ImageSpaceModifierInstanceDRB::*(char*)
    // void __cdecl ImageSpaceModifierInstanceDRB::*()
    // ImageSpaceModifierInstanceDRB& __cdecl ImageSpaceModifierInstanceDRB::*(const ImageSpaceModifierInstanceDRB&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceModifierInstanceDRB) == 68);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, m_fRampUp) == 32);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, fStart) == 36);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, m_fRampDown) == 40);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, m_fRampDownStart) == 44);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, Center) == 48);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, fDistance) == 56);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, fImpulseRadiusSquared) == 60);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDRB, Mode) == 64);
enum ImageSpaceModifierInstanceDOF__DepthOfFieldMode
{
    ImageSpaceModifierInstanceDOF__DepthOfFieldMode_DOF_FRONT_BACK = 0,
    ImageSpaceModifierInstanceDOF__DepthOfFieldMode_DOF_FRONT = 1,
    ImageSpaceModifierInstanceDOF__DepthOfFieldMode_DOF_BACK = 2,
    ImageSpaceModifierInstanceDOF__DepthOfFieldMode_DOF_FRONT_BACK_MASK = 3,
    ImageSpaceModifierInstanceDOF__DepthOfFieldMode_DOF_FRONT_MASK = 4,
    ImageSpaceModifierInstanceDOF__DepthOfFieldMode_DOF_BACK_MASK = 5,
    ImageSpaceModifierInstanceDOF__DepthOfFieldMode_DOF_NONE = 6
};
#pragma pack(push, 4)
class ImageSpaceModifierInstanceDOF : public ImageSpaceModifierInstanceTemp, public NiMemObjectAllocation
{
  public:
    enum DepthOfFieldMode
    {
        DOF_FRONT_BACK,
        DOF_FRONT,
        DOF_BACK,
        DOF_FRONT_BACK_MASK,
        DOF_FRONT_MASK,
        DOF_BACK_MASK,
        DOF_NONE
    };
    ImageSpaceModifierInstanceDOF(float, float, DepthOfFieldMode, float, float, float, NiAVObject*, float);
    ~ImageSpaceModifierInstanceDOF();
    void DestroyMembers();
    void* ScalarDeletingDestructor(unsigned int);
    static ImageSpaceModifierInstanceDOF* CreateAndRegister(float, float, DepthOfFieldMode, float, float, float);
    void Apply();
    // base ImageSpaceModifierInstanceTemp at +0x0, size 32
    float fDistance;        // +0x20, 4 bytes
    float fImpulseRadiusSquared;           // +0x24, 4 bytes
    float m_fMaskConstant;  // +0x28, 4 bytes
    DepthOfFieldMode Mode;  // +0x2C, 4 bytes
    // ImageSpaceModifierInstanceDOF
    // void __cdecl ImageSpaceModifierInstanceDOF::*()
    // void __cdecl ImageSpaceModifierInstanceDOF::*(float)
    // float __cdecl ImageSpaceModifierInstanceDOF::*()
    // void __cdecl ImageSpaceModifierInstanceDOF::*(float)
    // float __cdecl ImageSpaceModifierInstanceDOF::*()
    // void __cdecl ImageSpaceModifierInstanceDOF::*(ImageSpaceModifierInstanceDOF::DepthOfFieldMode)
    // ImageSpaceModifierInstanceDOF::DepthOfFieldMode __cdecl ImageSpaceModifierInstanceDOF::*()
    // void __cdecl ImageSpaceModifierInstanceDOF::*(float)
    // float __cdecl ImageSpaceModifierInstanceDOF::*()
    // Trigger
    // void __cdecl ImageSpaceModifierInstanceDOF::*(char*)
    // void __cdecl ImageSpaceModifierInstanceDOF::*()
    // ImageSpaceModifierInstanceDOF& __cdecl ImageSpaceModifierInstanceDOF::*(const ImageSpaceModifierInstanceDOF&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImageSpaceModifierInstanceDOF) == 48);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDOF, fDistance) == 32);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDOF, fImpulseRadiusSquared) == 36);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDOF, m_fMaskConstant) == 40);
FNV_STATIC_ASSERT(offsetof(ImageSpaceModifierInstanceDOF, Mode) == 44);
#endif
