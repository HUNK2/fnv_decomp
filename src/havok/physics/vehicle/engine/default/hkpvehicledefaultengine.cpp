
// src/havok/physics/vehicle/engine/default/hkpvehicledefaultengine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/vehicle/engine/default/hkpvehicledefaultengine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpVehicleDefaultEngine.h"

struct DriverInput
{
    hkReal m_fPrimaryValue;
};

struct RealValue
{
    hkReal m_fValue;
};

struct RealPair
{
    hkReal m_fFirstValueBeforeSteeringAngle;
    hkReal m_fSecondValueBeforeSteeringAngle;
};

class EngineHelper : public hkpVehicleDefaultEngine
{
  public:
    void CalculateEngineTorque(const hkReal deltaTime, const void* vehicle,
                               const DriverInput& filteredDriverInputOutput, const RealValue& transmissionOutput,
                               RealPair& engineOutput);
};

// Computes net engine torque from RPM, accelerator input, and transmission output, storing results in engineOutput.
// @fnv 0x00e440a0
void EngineHelper::CalculateEngineTorque(const hkReal deltaTime, const void* vehicle,
                                         const DriverInput& filteredDriverInputOutput,
                                         const RealValue& transmissionOutput, RealPair& engineOutput)
{
    engineOutput.m_fSecondValueBeforeSteeringAngle = transmissionOutput.m_fValue;
    const hkReal acceleratorPedal = filteredDriverInputOutput.m_fPrimaryValue;

    if (engineOutput.m_fSecondValueBeforeSteeringAngle < m_fMinRPM)
    {
        const hkReal clutchSlip = m_fClutchSlipRPM * acceleratorPedal;
        const hkReal halfMinRPM = m_fMinRPM * 0.5;
        if (engineOutput.m_fSecondValueBeforeSteeringAngle < halfMinRPM)
        {
            engineOutput.m_fSecondValueBeforeSteeringAngle = clutchSlip + m_fMinRPM;
        }
        else
        {
            engineOutput.m_fSecondValueBeforeSteeringAngle =
                m_fMinRPM +
                ((engineOutput.m_fSecondValueBeforeSteeringAngle - halfMinRPM) * clutchSlip) / (m_fMinRPM - halfMinRPM);
        }
    }

    hkReal grossTorque;
    hkReal resistanceTorque;

    const hkReal dRPM = engineOutput.m_fSecondValueBeforeSteeringAngle - m_fOptRPM;
    if (dRPM < 0.0f)
    {
        const hkReal invDenom = 1.0f / (m_fMinRPM - m_fOptRPM);
        const hkReal resFactor = (m_fResistanceFactorAtMinRPM - m_fResistanceFactorAtOptRPM) * invDenom;
        resistanceTorque = (m_fResistanceFactorAtOptRPM + dRPM * resFactor) * m_fMaxTorque;

        const hkReal tqFactor = ((m_fTorqueFactorAtMinRPM - 1.0f) * invDenom) * invDenom;
        grossTorque = (1.0f + tqFactor * (dRPM * dRPM)) * m_fMaxTorque;

        const hkReal transRPM = transmissionOutput.m_fValue;
        if (transRPM < m_fMinRPM)
        {
            resistanceTorque *= transRPM / m_fMinRPM;
        }
    }
    else if (engineOutput.m_fSecondValueBeforeSteeringAngle < m_fMaxRPM)
    {
        const hkReal invDenom = 1.0f / (m_fMaxRPM - m_fOptRPM);
        const hkReal resFactor = (m_fResistanceFactorAtMaxRPM - m_fResistanceFactorAtOptRPM) * invDenom;
        resistanceTorque = (m_fResistanceFactorAtOptRPM + dRPM * resFactor) * m_fMaxTorque;

        const hkReal tqFactor = ((m_fTorqueFactorAtMaxRPM - 1.0f) * invDenom) * invDenom;
        grossTorque = (1.0f + tqFactor * (dRPM * dRPM)) * m_fMaxTorque;
    }
    else
    {
        engineOutput.m_fSecondValueBeforeSteeringAngle = m_fMaxRPM;
        grossTorque = 0.0f;
        resistanceTorque = m_fResistanceFactorAtMaxRPM * m_fMaxTorque;
    }

    engineOutput.m_fFirstValueBeforeSteeringAngle = acceleratorPedal * grossTorque - resistanceTorque;
}
