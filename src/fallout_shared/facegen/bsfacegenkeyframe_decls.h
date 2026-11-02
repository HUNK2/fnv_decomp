// fallout_shared/facegen/bsfacegenkeyframe_decls.h: declares BSFaceGenKeyframe, OSGlobals, BSFaceGenManager, BSFaceGenKeyframeMultiple
#ifndef FNV_BSFACEGENKEYFRAME_DECLS_H
#define FNV_BSFACEGENKEYFRAME_DECLS_H


#include "layout_support.h"

#pragma pack(push, 4)
class BSFaceGenKeyframe
{
  public:
    BS_FACEGEN_MORPH_TYPE eType;
    float fTime;

    BSFaceGenKeyframe(BS_FACEGEN_MORPH_TYPE type);
    virtual ~BSFaceGenKeyframe();
    virtual void UnknownSlot1() = 0;
    virtual bool SetType(BS_FACEGEN_MORPH_TYPE type);
    virtual float vfn_0c();
    float GetTime();
    virtual bool vfn_10(float time);
    bool SetTime(float time);
};
#pragma pack(pop)

FNV_STATIC_ASSERT(sizeof(BSFaceGenKeyframe) == 0xC);

class OSGlobals
{
  public:
    unsigned int GetUptimeMilliseconds();
};

class BSFaceGenManager
{
  public:
    static void ApplyFaceGenValues(float* quantities, unsigned int count, bool initialize);
    static void NormalizeFaceGenValues(float* quantities, unsigned int count);
};

class BSFaceGenKeyframeMultiple : public BSFaceGenKeyframe
{
  public:
    virtual ~BSFaceGenKeyframeMultiple();
    BSFaceGenKeyframeMultiple(BS_FACEGEN_MORPH_TYPE type, unsigned int count);
    float* m_pfFaceGenValues;
    unsigned int m_uiFaceGenValueCount;

    virtual void UnknownSlot5() = 0;
    virtual void UnknownSlot6() = 0;
    virtual void UnknownSlot7() = 0;
    virtual bool ClearData(bool initialize);
    virtual void UnknownSlot9() = 0;
    virtual void UnknownSlot10() = 0;
    virtual void UnknownSlot11() = 0;
    virtual float GetAttributeStrength();
    virtual void UnknownSlot13() = 0;
    virtual void NormalizeFaceGenValues();
    virtual void UnknownSlot15() = 0;
    virtual bool HasNonzeroQuantity();
    virtual void UnknownSlot17() = 0;
    virtual void UnknownSlot18() = 0;
    virtual bool IsQuantityInRange(unsigned int quantity);
    virtual void ApplyFaceGenValues(unsigned int count, bool initialize);
};

FNV_STATIC_ASSERT(sizeof(BSFaceGenKeyframeMultiple) == 0x14);

#endif
