// bshavok/bhklimitedhingeconstraint_decls.h: declares bhkLimitedHingeVector, bhkLimitedHingeOutput, bhkLimitedHingeConstraint
#ifndef BHKLIMITEDHINGECONSTRAINT_DECLS_H
#define BHKLIMITEDHINGECONSTRAINT_DECLS_H

extern float DAT_01267e30;
class bhkLimitedHingeVector
{
  public:
    float value[4];
    void FUN_004b4db0(const float*);
};
class bhkLimitedHingeOutput
{
  public:
    char prefix[16];
    bhkLimitedHingeVector first;
    bhkLimitedHingeVector second;
};
class bhkLimitedHingeConstraint
{
  public:
    char prefix[8];
    char* m_pHavokObject;
    void FUN_00c9fb70(bhkLimitedHingeOutput*);
    void PopulateOutput(bhkLimitedHingeOutput*);
    const float* GetFirst() const
    {
        return this && m_pHavokObject ? (const float*)(m_pHavokObject + 0x20) : &DAT_01267e30;
    }
    const float* GetSecond() const
    {
        return this && m_pHavokObject ? (const float*)(m_pHavokObject + 0x30) : &DAT_01267e30;
    }
};
#endif
