
// src/havok/physics/vehicle/hkpvehicledata_rtm_variant.cpp - RTM variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/vehicle/hkpvehicledata.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with). Declarations copied from that unit's skeleton.

// src/havok/physics/vehicle/hkpvehicledata.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/hkpvehicledata.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpVehicleData.h"

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C"
{
    void _ReadWriteBarrier();
    __m128 _mm_add_ps(__m128, __m128);
    __m128 _mm_mul_ps(__m128, __m128);
    __m128 _mm_and_ps(__m128, __m128);
    __m128 _mm_shuffle_ps(__m128, __m128, unsigned int);
    __m128 _mm_set_ps1(float);
    __m128 _mm_load_ss(const float*);
    __m128 _mm_load_ps1(const float*);
    void _mm_store_ss(float*, __m128);
}

extern __m128 DAT_01017d10;

struct hkMemoryAllocator;
struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    __forceinline hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};
NineIntegerRecord* FUN_00c85750();
void __cdecl FUN_00c908c0(hkMemoryAllocator& alloc, void* array, int numElements, int sizeElem);

struct SimdReal
{
    __m128 m_vValue;
    SimdReal()
    {}
    __forceinline SimdReal(float value)
    {
        m_vValue = _mm_load_ss(&value);
    }
    __forceinline operator float() const
    {
        float f;
        _mm_store_ss(&f, m_vValue);
        return f;
    }
};

struct QuadStorage
{
    __m128 m_vComponents;
};
struct FourFloatVector : QuadStorage
{
    __forceinline void operator=(const FourFloatVector& v)
    {
        m_vComponents = v.m_vComponents;
    }
    __forceinline float& operator()(int i)
    {
        return m_vComponents.m128_f32[i];
    }
    __forceinline const float& operator()(int i) const
    {
        return m_vComponents.m128_f32[i];
    }
    __forceinline void setAbs4(const FourFloatVector& v)
    {
        m_vComponents = _mm_and_ps(v.m_vComponents, DAT_01017d10);
    }
    __forceinline void setMul4(const SimdReal& r, const FourFloatVector& v)
    {
        m_vComponents = _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), v.m_vComponents);
    }
    __forceinline void addMul4(const SimdReal& r, const FourFloatVector& v)
    {
        m_vComponents =
            _mm_add_ps(m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), v.m_vComponents));
    }
    __forceinline void setAddMul4(const FourFloatVector& a, const FourFloatVector& b, const SimdReal& r)
    {
        m_vComponents =
            _mm_add_ps(a.m_vComponents, _mm_mul_ps(_mm_shuffle_ps(r.m_vValue, r.m_vValue, 0), b.m_vComponents));
    }
    __forceinline SimdReal getSimdAt3() const
    {
        SimdReal s;
        s.m_vValue = _mm_shuffle_ps(m_vComponents, m_vComponents, 0xff);
        return s;
    }
};

struct FloatMatrix3
{
    FourFloatVector m_kColumn0;
    FourFloatVector m_kColumn1;
    FourFloatVector m_kColumn2;
    __forceinline FourFloatVector& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    __forceinline const FourFloatVector& getColumn(int i) const
    {
        return (&m_kColumn0)[i];
    }
    void FUN_00cd5610(const FloatMatrix3& a, const FloatMatrix3& b);
};

template <class T> struct Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void GrowArrayCapacity(hkMemoryAllocator& alloc, int n)
    {
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(alloc, this, newSize, sizeof(T));
        }
    }
    __forceinline void _setSize(hkMemoryAllocator& alloc, int n)
    {
        GrowArrayCapacity(alloc, n);
        m_iElementCount = n;
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        _setSize(FUN_00c85750()->heap(), n);
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return m_data[i];
    }
};

struct Motion
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0C;
    FloatMatrix3 m_rotation;
    FourFloatVector m_vTranslation;
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
    int unk88;
    int unk8C;
    FourFloatVector m_vCenterOfMassLocal;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    FourFloatVector m_kInertiaAndMassInv;

    float FUN_00c86430() const;
    __forceinline SimdReal getMassInv() const
    {
        return m_kInertiaAndMassInv.getSimdAt3();
    }
};

struct RigidBody
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
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    Motion m_pMotionState;

    __forceinline float GetMassValue() const
    {
        return m_pMotionState.FUN_00c86430();
    }
    __forceinline SimdReal getMassInv() const
    {
        return m_pMotionState.getMassInv();
    }
    __forceinline const FloatMatrix3& getRotation() const
    {
        return m_pMotionState.m_rotation;
    }
    __forceinline const FourFloatVector& getCenterOfMassLocal() const
    {
        return m_pMotionState.m_vCenterOfMassLocal;
    }
};

struct SuspensionWheelParameters
{
    FourFloatVector m_vHardpointChassisSpace;
    FourFloatVector m_vDirectionChassisSpace;
    float m_fRestLength;
    int unk24;
    int unk28;
    int unk2C;
};

struct WheelComponentParams
{
    float m_fSphereRadius;
    float m_fViscosityFriction;
    float m_fMaxFriction;
    float m_fSlipAngle;
    float m_fSlipVelocity;
    float m_fMaxContactBodyAcceleration;
    float m_fForceFeedbackMultiplier;
    float m_fMaxFrictionForce;
    float m_fFrictionEqualizer;
    signed char m_iAxle;
    char unk25;
    char unk26;
    char unk27;
};

struct FrictionCinfo
{
    FourFloatVector m_akFrictionVectors[2];
    FourFloatVector m_kVectorA;
    FourFloatVector m_kVectorB;
    FourFloatVector m_kVectorC;
    FourFloatVector m_kVectorD;
    FloatMatrix3 m_kFrictionMatrix;
    float m_fMaxVelocityForPositionalFriction;
    float m_fAxisFrictionTuning4[2];
    float m_fAxisFrictionTuning6[2];
    float m_fChassisUnitInertiaRoll;
};

void __cdecl FUN_00e593f0(const FrictionCinfo& ci, hkpVehicleFrictionDescription& out);

__forceinline Array<WheelComponentParams>& wheelParamsOf(hkpVehicleData& d)
{
    return reinterpret_cast<Array<WheelComponentParams>&>(d.m_kWheelParams);
}
__forceinline Array<signed char>& wheelsPerAxleOf(hkpVehicleData& d)
{
    return reinterpret_cast<Array<signed char>&>(d.m_kNumWheelsPerAxle);
}
__forceinline const FloatMatrix3& orientationOf(const hkpVehicleData& d)
{
    return reinterpret_cast<const FloatMatrix3&>(d.m_kChassisOrientation);
}
__forceinline FourFloatVector& inertiaInvDiagOf(hkpVehicleData& d)
{
    return reinterpret_cast<FourFloatVector&>(d.m_vChassisUnitInertiaAndMassInv);
}

__forceinline void initVehicleComponents(hkpVehicleData& self,
                                         const Array<SuspensionWheelParameters>& suspensionWheelParams,
                                         const RigidBody* chassis)
{
    self.m_bWheelsUseChassisForGround = true;
    _ReadWriteBarrier();

    int axle = 0;
    if (self.m_iWheelCount > 0)
    {
        _ReadWriteBarrier();
        Array<WheelComponentParams>& wheels = wheelParamsOf(self);
        int remaining = self.m_iWheelCount;
        int i = 0;
        do
        {
            if (wheels[i].m_iAxle + 1 > axle)
            {
                axle = wheels[i].m_iAxle + 1;
            }
            ++i;
        } while (--remaining);
    }

    if (axle > wheelsPerAxleOf(self).GetLogicalSize())
    {
        wheelsPerAxleOf(self).SetSizeAndGrow(axle);
    }
    {
        for (int i = 0; i < wheelsPerAxleOf(self).GetLogicalSize(); i++)
        {
            wheelsPerAxleOf(self)[i] = 0;
        }
    }
    {
        Array<WheelComponentParams>& params = wheelParamsOf(self);
        for (int i = 0; i < self.m_iWheelCount; i++)
        {
            int axleIdx = params[i].m_iAxle;
            wheelsPerAxleOf(self)[axleIdx]++;
        }
    }

    {
        FourFloatVector absUp;
        absUp.setAbs4(orientationOf(self).getColumn(0));
        FourFloatVector absForward;
        absForward.setAbs4(orientationOf(self).getColumn(1));
        FourFloatVector absRight;
        absRight.setAbs4(orientationOf(self).getColumn(2));

        FourFloatVector ptr;
        ptr.setMul4(self.m_fTorqueMin / self.m_fTorqueRollFactor, absUp);
        ptr.addMul4(self.m_fChassisMass / self.m_fTorqueYawFactor, absForward);
        ptr.addMul4(self.m_fTorqueMax / self.m_fExtraTorqueFactor, absRight);
        ptr(3) = 1.0f;

        float idx = 1.0f / chassis->GetMassValue();
        inertiaInvDiagOf(self).setMul4(idx, ptr);
    }

    {
        FrictionCinfo ci;
        ci.m_kVectorA = chassis->getCenterOfMassLocal();
        {
            const FloatMatrix3& r = chassis->getRotation();
            FloatMatrix3 tmp;
            tmp.m_kColumn0.setMul4(inertiaInvDiagOf(self)(0), r.m_kColumn0);
            tmp.m_kColumn1.setMul4(inertiaInvDiagOf(self)(1), r.m_kColumn1);
            tmp.m_kColumn2.setMul4(inertiaInvDiagOf(self)(2), r.m_kColumn2);
            ci.m_kFrictionMatrix.FUN_00cd5610(tmp, r);
        }
        ci.m_fMaxVelocityForPositionalFriction = chassis->getMassInv();
        ci.m_kVectorD.setAbs4(orientationOf(self).getColumn(0));
        ci.m_fChassisUnitInertiaRoll = self.m_fChassisUnitInertiaRoll;
        ci.m_kVectorC.setAbs4(orientationOf(self).getColumn(1));
        ci.m_fAxisFrictionTuning4[0] = 0.0f;
        ci.m_fAxisFrictionTuning4[1] = 0.0f;
        ci.m_kVectorB.setAbs4(orientationOf(self).getColumn(2));

        for (int i = 0; i < self.m_iWheelCount; i++)
        {
            const SuspensionWheelParameters& sp = suspensionWheelParams[i];
            const WheelComponentParams& wp = wheelParamsOf(self)[i];
            int numAxles = wp.m_iAxle;
            ci.m_fAxisFrictionTuning6[numAxles] = wp.m_fSphereRadius;
            ci.m_akFrictionVectors[numAxles].setAddMul4(sp.m_vHardpointChassisSpace, sp.m_vDirectionChassisSpace,
                                                    sp.m_fRestLength);
            ci.m_fAxisFrictionTuning4[numAxles] += wp.m_fViscosityFriction * wp.m_fSphereRadius;
        }

        FUN_00e593f0(ci, self.m_kFrictionDescription);
    }
}

// @fnv 0x00e39ab0
void __fastcall FUN_00e39ab0(hkpVehicleData* self, int, const Array<SuspensionWheelParameters>& suspensionWheelParams,
                             const RigidBody* chassis)
{
    initVehicleComponents(*self, suspensionWheelParams, chassis);
}
