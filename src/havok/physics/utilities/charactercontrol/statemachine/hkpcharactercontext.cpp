
// src/havok/physics/utilities/charactercontrol/statemachine/hkpcharactercontext.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/charactercontrol/statemachine/hkpcharactercontext.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_0102e388;
extern int DAT_010c8198;
struct hkReferencedObject
{
    void removeReference();
};
struct FUN_00ca95e0_class
{
    int m_p;
    int m_uiX;
    int m_uiY;
    int m_uiZ;
    void FUN_00ca95e0();
};
// @fnv 0x00ca95e0
void FUN_00ca95e0_class::FUN_00ca95e0()
{
    m_p = (int)&DAT_010c8198;
    ((hkReferencedObject*)m_uiZ)->removeReference();
    m_p = (int)&DAT_0102e388;
}

struct FUN_00ca9670_cls
{
    void __thiscall FUN_00ca9670(float a, float b, float c);
};
// @fnv 0x00ca9670
void __thiscall FUN_00ca9670_cls::FUN_00ca9670(float a, float b, float c)
{
    *(float*)((char*)this + 0x24) = a;
    *(float*)((char*)this + 0x20) = b;
    *(float*)((char*)this + 0x1c) = c;
}

struct FUN_00ca9660_cls
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0C;
    unsigned int unk10;
    unsigned int unk14;
    unsigned char m_18;

    void FUN_00ca9660(unsigned char value);
};

// @fnv 0x00ca9660
void FUN_00ca9660_cls::FUN_00ca9660(unsigned char value)
{
    m_18 = value;
}

struct FUN_00ca9690_cls
{
    int unk00;
    int unk04;
    int m_08;

    void FUN_00ca9690(int value);
};

// @fnv 0x00ca9690
void FUN_00ca9690_cls::FUN_00ca9690(int value)
{
    m_08 = value;
}

extern int DAT_010c8198;
void __fastcall FUN_00c90510(void*);

struct hkpCharacterContext
{
    int* vtbl;
    short unk04;
    short unk06;
    int unk08;
    void* unk0C;
    int unk10;
    int unk14;
    unsigned char unk18;
    float unk1C;
    float unk20;
    float unk24;

    hkpCharacterContext* Initialize(void* arg0, int arg1);
};

// @fnv 0x00ca9580
hkpCharacterContext* hkpCharacterContext::Initialize(void* arg0, int arg1)
{
    unk06 = 1;
    unk0C = arg0;
    vtbl = &DAT_010c8198;
    unk10 = arg1;
    unk14 = arg1;
    unk08 = 0;
    unk18 = 1;

    float& f20 = unk20;
    f20 = 20.0f;
    unk1C = 625.0f;
    unk24 = 1.0f;
    FUN_00c90510(unk0C);

    return this;
}

// @fnv 0x00ca9600
int __fastcall FUN_00ca9600(char* object)
{
    return *reinterpret_cast<int*>(object + 0x10);
}

class hkpCharacterContextCA96;
struct hkpCharacterInputCA96;
struct hkpCharacterOutputCA96;

class hkpCharacterStateCA96
{
  public:
    virtual ~hkpCharacterStateCA96() throw();
    virtual int getType() const throw();
    virtual void update(hkpCharacterContextCA96& kContext, const hkpCharacterInputCA96& kInput,
                        hkpCharacterOutputCA96& kOutput) throw();
    virtual void change(hkpCharacterContextCA96& kContext, const hkpCharacterInputCA96& kInput,
                        hkpCharacterOutputCA96& kOutput) throw();
    virtual void enterState(hkpCharacterContextCA96& kContext, int iPrevState, const hkpCharacterInputCA96& kInput,
                            hkpCharacterOutputCA96& kOutput) throw();
    virtual void leaveState(hkpCharacterContextCA96& kContext, int iNextState, const hkpCharacterInputCA96& kInput,
                            hkpCharacterOutputCA96& kOutput) throw();
};

class hkpCharacterStateManagerCA96
{
  public:
    hkpCharacterStateCA96* FUN_00cbc510(int iState) const throw();
};

class hkpCharacterContextCA96
{
  public:
    int unk00;
    int unk04;
    int m_iCurrentState;
    const hkpCharacterStateManagerCA96* pCharacterStateManager;
    int m_iPreviousState;

    void SetState(int iState, const hkpCharacterInputCA96& kInput, hkpCharacterOutputCA96& kOutput);
};

// Leaves the current state, stores the new state id, then enters the new state via the state manager.
// @fnv 0x00ca9610
void hkpCharacterContextCA96::SetState(int iState, const hkpCharacterInputCA96& kInput, hkpCharacterOutputCA96& kOutput)
{
    int iPrevState = m_iPreviousState;
    pCharacterStateManager->FUN_00cbc510(m_iPreviousState)->leaveState(*this, iState, kInput, kOutput);
    m_iPreviousState = iState;
    pCharacterStateManager->FUN_00cbc510(iState)->enterState(*this, iPrevState, kInput, kOutput);
}

struct FnvCpu_FUN_00ca9810_CpuAllocator
{
    virtual void slot00();
    virtual void slot04();
    virtual void Invoke(void* block, unsigned int size);
};
struct FnvCpu_FUN_00ca9810_CpuAllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00ca9810_CpuAllocator* allocator;
};
FnvCpu_FUN_00ca9810_CpuAllocatorHolder* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00ca9810_CpuObject
{
    unsigned int unk00;
    unsigned short size;
    void FUN_00ca95e0();
    FnvCpu_FUN_00ca9810_CpuObject* Destroy(unsigned int flags);
};
// Calls FUN_00ca95e0, then if bit 0 of flags is set, invokes the allocator from FUN_00c85750 on this with size, and returns this.
// @fnv 0x00ca9810
FnvCpu_FUN_00ca9810_CpuObject* FnvCpu_FUN_00ca9810_CpuObject::Destroy(unsigned int flags)
{
    FUN_00ca95e0();
    if (flags & 1)
    {
        FnvCpu_FUN_00ca9810_CpuAllocatorHolder* pAllocatorHolder = FUN_00c85750();
        pAllocatorHolder->allocator->Invoke(this, size);
    }
    return this;
}

#include <xmmintrin.h>
class VectorComponentValue
{
  public:
    __m128 m_vValue;
    inline VectorComponentValue()
    {}
    inline VectorComponentValue(__m128 x) : m_vValue(x)
    {}
    inline VectorComponentValue(const float& x)
    {
        m_vValue = _mm_load_ss(&x);
    }
    inline float getReal() const
    {
        float r;
        _mm_store_ss(&r, m_vValue);
        return r;
    }
    inline operator float() const
    {
        return getReal();
    }
};

typedef const VectorComponentValue& hkSimdRealParameter;

class hkVector4
{
  public:
    __m128 m_vComponents;
    inline hkVector4()
    {}
    inline hkVector4(__m128 q) : m_vComponents(q)
    {}
    inline void operator=(const hkVector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
    inline void setSub4(const hkVector4& a, const hkVector4& b)
    {
        m_vComponents = _mm_sub_ps(a.m_vComponents, b.m_vComponents);
    }
    inline void mul4(hkSimdRealParameter r)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), m_vComponents);
    }
    inline void addMul4(hkSimdRealParameter r, const hkVector4& a)
    {
        m_vComponents =
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), a.m_vComponents), m_vComponents);
    }
    inline VectorComponentValue length3() const
    {
        __m128 mul = _mm_mul_ps(m_vComponents, m_vComponents);
        __m128 y = _mm_shuffle_ps(mul, mul, 0x55);
        __m128 z = _mm_shuffle_ps(mul, mul, 0xaa);
        __m128 sum = _mm_add_ss(z, _mm_add_ss(y, mul));
        return _mm_sqrt_ss(sum);
    }
};

struct PhysicsDataBlock
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    float m_pStepInfo;
    float m_fSecondScalar;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    hkVector4 m_fVelocity;
};

struct Vector4Data
{
    hkVector4 m_fVelocity;
};

struct Context;

struct State
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void unk10();
    virtual void unk14();
    virtual void change(Context* ctx, const PhysicsDataBlock& input, Vector4Data& output);
    virtual void update(Context* ctx, const PhysicsDataBlock& input, Vector4Data& output);
};

struct StateManager
{
    State* GetReferenceTimeStep(int state);
};

struct Context
{
    int unk00;
    int unk04;
    int unk08;
    StateManager* pCharacterStateManager;
    int m_iPreviousState;
    int m_iStateIndex;
    char m_filterParameters;
    char pad19;
    char pad1A;
    char pad1B;
    float m_characterWidth;
    float m_fSurfaceFriction;
    float m_fGain;

    void FUN_00ca96a0(const PhysicsDataBlock& input, Vector4Data& output);
};

// @fnv 0x00ca96a0
void Context::FUN_00ca96a0(const PhysicsDataBlock& input, Vector4Data& output)
{
    output.m_fVelocity = input.m_fVelocity;

    pCharacterStateManager->GetReferenceTimeStep(m_iPreviousState)->update(this, input, output);

    if (m_iPreviousState == m_iStateIndex)
    {
        pCharacterStateManager->GetReferenceTimeStep(m_iPreviousState)->change(this, input, output);
    }

    m_iStateIndex = m_iPreviousState;

    if (m_filterParameters)
    {
        float length = output.m_fVelocity.length3();
        if (length > m_fSurfaceFriction)
        {
            float fClampScale = m_fSurfaceFriction / length;
            output.m_fVelocity.mul4(fClampScale);
        }

        float grav = input.m_fSecondScalar;
        hkVector4 vDelta;
        vDelta.setSub4(output.m_fVelocity, input.m_fVelocity);
        vDelta.mul4(grav);
        float fDeltaLength = vDelta.length3();
        float fDeltaRatio = fDeltaLength / m_characterWidth;
        output.m_fVelocity = input.m_fVelocity;

        float fBlendFactor;
        if (fDeltaRatio > 1.0f && m_iPreviousState != 1)
        {
            fBlendFactor = (input.m_pStepInfo * m_fGain) / fDeltaRatio;
        }
        else
        {
            fBlendFactor = input.m_pStepInfo * m_fGain;
        }

        output.m_fVelocity.addMul4(fBlendFactor, vDelta);
    }
}
