// src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils_gs_ehsc_nogs_noehsc_variant_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils_gs_ehsc_nogs_noehsc_variant.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.


// src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.
// src/havok/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/constraint/bilateral/hkpconstraintutils.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
typedef union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
    char m128_i8[16];
    short m128_i16[8];
    int m128_i32[4];
    __int64 m128_i64[2];
    unsigned char m128_u8[16];
    unsigned short m128_u16[8];
    unsigned int m128_u32[4];
} __m128;
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct AudioMgr
{
    int unk00, unk04, unk08;
    hkMemoryAllocator* unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};
struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}
struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
struct Block5
{
    int unk00, unk04, unk08, unk0c, unk10;
};
struct Block5b
{
    int unk00;
    unsigned short unk04;
    unsigned char unk06;
    unsigned char unk07;
    int unk08, unk0c, unk10;
};
struct hkRefObj
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    void FUN_00c90510();
    void FUN_00c905b0();
};
struct CloneDataBase : hkRefObj
{
    int unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    __m128 unk20, unk30, unk40, unk50, unk60, unk70;
};
struct CloneDataA : CloneDataBase
{
    Block5 unk80;
    Block5b unk94;
    Block5 unka8;
    CloneDataA* FUN_00d4f2a0();
    void FUN_00d4f270(hkBool flag);
};
struct CloneDataB : CloneDataBase
{
    Block5 unk80;
    CloneDataB* FUN_00d52fc0();
};
struct SourceDataHeader
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType();
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;
    int unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
};
struct SourceData : SourceDataHeader
{
    __m128 unk20, unk30, unk40, unk50, unk60, unk70, unk80;
};
struct SourceDataB : SourceData
{
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    Block5 unkc0;
};
struct SourceDataA : SourceData
{
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc, unkc0, unkc4, unkc8, unkcc,
        unkd0, unkd4, unkd8, unkdc, unke0, unke4, unke8, unkec, unkf0, unkf4, unkf8;
    Block5 unkfc;
    Block5b unk110;
    Block5 unk124;
};
struct Instance;
struct Instance : hkRefObj
{
    int unk08;
    SourceData* unk0c;
    int unk10;
    void* unk14;
    void* unk18;
    unsigned char unk1c;
    Instance* FUN_00cf3ea0(void* entityA, void* entityB, CloneDataBase* data, int priority);
};
inline void* hkAlloc(int size)
{
    hkRefObj* p = (hkRefObj*)audio()->heap().AllocateMemoryBlock(size);
    p->m_usMemSizeAndFlags = (unsigned short)size;
    return p;
}
Instance* __cdecl CloneInstanceFromSource(Instance* src);
class FnvSink
{
  public:
    virtual void Slot0() throw();
    virtual void Slot1() throw();
    virtual void Slot2() throw();
    virtual void Write(int level, unsigned int hash, const char* msg, const char* file, int line) throw();
};
extern FnvSink* DAT_01268360;
class MsgWriter
{
  public:
    void Init(char* buf, unsigned int cap) throw();
    void Append(const char* s) throw();
    void Finish() throw();
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
};
class FnvInner
{
  public:
    virtual void v00() throw();
    virtual void v04() throw();
    virtual void v08() throw();
    virtual void v0C() throw();
    virtual void v10() throw();
    virtual void v14() throw();
    virtual void v18() throw();
    virtual void v1C() throw();
    virtual unsigned int GetKind() throw();

    char unk04[0x0c];
    __m128 m_20;
    __m128 m_30;
    char unk40[0x10];
    __m128 m_50;
    char unk60[0x30];
    __m128 m_90;
};
class FnvHolder
{
  public:
    char unk00[0x0c];
    FnvInner* m_0c;
};
int FUN_00e5ad40(FnvHolder* a0, __m128* a1, __m128* a2);
struct Ent
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
    int unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c;
    int unk80, unk84, unk88, unk8c, unk90, unk94, unk98, unk9c;
    int unka0, unka4, unka8, unkac, unkb0, unkb4, unkb8, unkbc;
    int unkc0, unkc4, unkc8, unkcc, unkd0, unkd4, unkd8, unkdc;
    int unke0, unke4, unke8, unkec;
    __m128 unkf0;
    int unk100, unk104, unk108, unk10c, unk110, unk114, unk118, unk11c;
    __m128 unk120;
    int unk130, unk134, unk138, unk13c, unk140, unk144, unk148, unk14c;
    int unk150, unk154, unk158, unk15c, unk160, unk164, unk168, unk16c;
    int unk170, unk174, unk178, unk17c, unk180, unk184, unk188, unk18c;
    int unk190, unk194, unk198, unk19c, unk1a0, unk1a4, unk1a8, unk1ac;
    __m128 unk1b0;
    __m128 unk1c0;
    void FUN_00ca8800(__m128* v);
    void OnTrigger(int arg);
    void FUN_00561800(void* p);
};
struct FnvHolder2 : FnvHolder
{
    int unk10;
    Ent* unk14;
    Ent* unk18;
};
struct Conv
{
    __m128 m;
    void FUN_00c7f640(__m128* src, __m128* arg);
};
// Constraint pivots followed by their transformed positions.
struct WorkVectors
{
    __m128 va;
    __m128 vb;
    Conv cb;
    Conv ca;
};
extern "C"
{
    __m128 _mm_load_ps(const float* p);
    __m128 _mm_mul_ps(__m128 a, __m128 b);
    __m128 _mm_add_ps(__m128 a, __m128 b);
    __m128 _mm_sub_ps(__m128 a, __m128 b);
    __m128 _mm_shuffle_ps(__m128 a, __m128 b, int sel);
    __m128 _mm_add_ss(__m128 a, __m128 b);
    __m128 _mm_set_ps1(float x);
    void _mm_store_ss(float* p, __m128 v);
}
extern "C"
{
    const __m128 DAT_010ec7f0 = {{1.0f, 1.0f, 1.0f, 1.0f}};
    const float DAT_010959f4 = 1e-6f;
}
bool* FUN_00e5af80(bool* out, FnvHolder2* h, float t, float t2);

extern "C" __m128 _mm_load_ss(const float*);

class VectorComponentValue
{
  public:
    __forceinline VectorComponentValue(const __m128& x) : m_vValue(x)
    {}
    __forceinline VectorComponentValue(float x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    __forceinline operator float() const
    {
        float s;
        _mm_store_ss(&s, m_vValue);
        return s;
    }
    __forceinline __m128 broadcast() const
    {
        return _mm_shuffle_ps(m_vValue, m_vValue, 0);
    }

  private:
    __m128 m_vValue;
};

class hkVector4
{
  public:
    __forceinline hkVector4()
    {}
    __forceinline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline void setAdd4(const hkVector4& v0, const hkVector4& v1)
    {
        m_vComponents = _mm_add_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void setSub4(const hkVector4& v0, const hkVector4& v1)
    {
        m_vComponents = _mm_sub_ps(v0.m_vComponents, v1.m_vComponents);
    }
    __forceinline void addMul4(const VectorComponentValue& r, const hkVector4& v1)
    {
        m_vComponents = _mm_add_ps(m_vComponents, _mm_mul_ps(r.broadcast(), v1.m_vComponents));
    }
    __forceinline VectorComponentValue dot3(const hkVector4& a) const
    {
        __m128 x2 = _mm_mul_ps(m_vComponents, a.m_vComponents);
        __m128 xySum = _mm_add_ss(_mm_shuffle_ps(x2, x2, 0x55), x2);
        return _mm_add_ss(_mm_shuffle_ps(x2, x2, 0xaa), xySum);
    }
    __forceinline VectorComponentValue getSimdAt3() const
    {
        return _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
    }
    __forceinline float& operator()(int a)
    {
        return reinterpret_cast<float*>(&m_vComponents)[a];
    }
    __m128 m_vComponents;
};

class hkRotation;
class hkMatrix3
{
  public:
    __forceinline hkMatrix3()
    {}
    void transpose();
    void SetFromRotation(const hkRotation& r);
    __forceinline hkVector4& getColumn(int x)
    {
        return (&m_kColumn0)[x];
    }
    __forceinline float& operator()(int r, int c)
    {
        return getColumn(c)(r);
    }
    hkVector4 m_kColumn0;
    hkVector4 m_kColumn1;
    hkVector4 m_kColumn2;
};
class hkRotation : public hkMatrix3
{
  public:
    __forceinline hkRotation(const hkRotation& o)
    {
        m_kColumn0 = o.m_kColumn0;
        m_kColumn1 = o.m_kColumn1;
        m_kColumn2 = o.m_kColumn2;
    }
};
struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
    __forceinline hkRotation& getRotation()
    {
        return m_rotation;
    }
    __forceinline hkVector4& getTranslation()
    {
        return m_vTranslation;
    }
};
struct hkpSetLocalTransformsConstraintAtom
{
    int unk00, unk04, unk08, unk0c;
    hkTransform m_kBodyALocalFrame;
    hkTransform m_kBodyBLocalFrame;
};
struct hkpMotionBase
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void GetInertiaInvLocal(hkMatrix3& inertiaInv);
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
};
struct hkpMotion : hkpMotionBase
{
    hkVector4 m_vCenterOfMassLocal;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    hkVector4 m_kInertiaAndMassInv;
    __forceinline VectorComponentValue getMassInv() const
    {
        return m_kInertiaAndMassInv.getSimdAt3();
    }
};
struct hkpRigidBody
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    hkpMotion m_pMotionState;
    __forceinline hkpMotion* getRigidMotion()
    {
        return &m_pMotionState;
    }
    __forceinline void GetInertiaInvLocal(hkMatrix3& m)
    {
        getRigidMotion()->GetInertiaInvLocal(m);
    }
    __forceinline float getMassInv()
    {
        return getRigidMotion()->getMassInv();
    }
    __forceinline const hkVector4& getCenterOfMassLocal()
    {
        return m_pMotionState.m_vCenterOfMassLocal;
    }
};

// @fnv 0x00e5a800
void __cdecl FUN_00e5a800(Instance* constraint)
{
    SourceData* data = constraint->unk0c;
    hkpSetLocalTransformsConstraintAtom* transformsAtom = 0;
    switch (data->getType())
    {
    case 1:
        transformsAtom = (hkpSetLocalTransformsConstraintAtom*)&data->unk10;
        break;
    case 2:
        transformsAtom = (hkpSetLocalTransformsConstraintAtom*)&data->unk10;
        break;
    default:
        return;
    }

    hkpRigidBody* bodyA = (hkpRigidBody*)constraint->unk14;
    hkpRigidBody* bodyB = (hkpRigidBody*)constraint->unk18;

    const bool useRelativeInertia = true;

    float invInertiaA = 0.0f;
    {
        hkMatrix3 inertiaLocA;
        bodyA->GetInertiaInvLocal(inertiaLocA);
        hkRotation invRot = transformsAtom->m_kBodyALocalFrame.getRotation();
        invRot.transpose();
        inertiaLocA.SetFromRotation(invRot);
        invInertiaA = float(inertiaLocA(1, 1) + inertiaLocA(2, 1)) + float(inertiaLocA(1, 2) + inertiaLocA(2, 2));
        if (useRelativeInertia && bodyA->getMassInv() > 1.192092896e-07f)
        {
            invInertiaA /= bodyA->getMassInv();
        }
    }

    float invInertiaB = 0.0f;
    {
        hkMatrix3 inertiaLocB;
        bodyB->GetInertiaInvLocal(inertiaLocB);
        hkRotation invRot = transformsAtom->m_kBodyBLocalFrame.getRotation();
        invRot.transpose();
        inertiaLocB.SetFromRotation(invRot);
        invInertiaB = float(inertiaLocB(1, 1) + inertiaLocB(2, 1)) + float(inertiaLocB(1, 2) + inertiaLocB(2, 2));
        if (useRelativeInertia && bodyB->getMassInv() > 1.192092896e-07f)
        {
            invInertiaB /= bodyB->getMassInv();
        }
    }

    hkVector4& axisA = transformsAtom->m_kBodyALocalFrame.getRotation().getColumn(0);
    hkVector4 pivotA;
    pivotA.setSub4(transformsAtom->m_kBodyALocalFrame.getTranslation(), bodyA->getCenterOfMassLocal());
    float pivotLengthAlongAxisA = pivotA.dot3(axisA);

    hkVector4& axisB = transformsAtom->m_kBodyBLocalFrame.getRotation().getColumn(0);
    hkVector4 pivotB;
    pivotB.setSub4(transformsAtom->m_kBodyBLocalFrame.getTranslation(), bodyB->getCenterOfMassLocal());
    float pivotLengthAlongAxisB = pivotB.dot3(axisB);

    float invSumInertias = 1.0f / (invInertiaA + invInertiaB);
    float totalPivotLengthAlongAxis = pivotLengthAlongAxisA - pivotLengthAlongAxisB;
    float newPivotLenghtAlongAxisA = totalPivotLengthAlongAxis * invInertiaB * invSumInertias;
    float newPivotLenghtAlongAxisB = -totalPivotLengthAlongAxis * invInertiaA * invSumInertias;

    pivotA.addMul4(newPivotLenghtAlongAxisA - pivotLengthAlongAxisA, axisA);
    pivotB.addMul4(newPivotLenghtAlongAxisB - pivotLengthAlongAxisB, axisB);

    transformsAtom->m_kBodyALocalFrame.getTranslation().setAdd4(pivotA, bodyA->getCenterOfMassLocal());
    transformsAtom->m_kBodyBLocalFrame.getTranslation().setAdd4(pivotB, bodyB->getCenterOfMassLocal());
}
