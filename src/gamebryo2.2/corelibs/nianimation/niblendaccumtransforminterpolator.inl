// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niblendaccumtransforminterpolator.inl
//
// Covered functions (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0x00496340  NiBlendAccumTransformInterpolator::ResetAccumulation  (111 bytes)
#ifndef FNV_NIBLENDACCUMTRANSFORMINTERPOLATOR_INL
#define FNV_NIBLENDACCUMTRANSFORMINTERPOLATOR_INL


// Authored declarations for the gamebryo2.2 nianimation unit. The canonical
// generated headers do not carry the Gamebryo transform classes yet, so this
// header keeps the translation unit self-contained. Class, member and static
// from NiBlendInterpolator (48 bytes) and holds m_kAccumulatedTransform at
// +0x30, m_pAccumulationData at +0x50 and m_bHasAccumulation at +0x54; the byte compared here
// at +0xE is the inherited NiBlendInterpolator::m_ucInterpCount.

class NiPoint3
{
public:
    static const NiPoint3 ZERO;

    float x;
    float y;
    float z;
};

class NiQuaternion
{
public:
    static const NiQuaternion IDENTITY;

    float m_fVectorX;
    float m_fVectorY;
    float m_fVectorZ;
    float m_fScalarPart;
};

class NiQuatTransform
{
public:
    NiQuatTransform();

    void GetTransformScale(const NiPoint3& kTranslate);
    void SetLocalRotation(const NiQuaternion& kRotate);
    void SetScale(float fScale);

protected:
    NiPoint3 m_kTranslate;      // +0x0
    NiQuaternion m_kRotate;     // +0xC
    float m_fScale;             // +0x1C
};

class NiMemObject
{
};

class NiRefObject : public NiMemObject
{
public:
    virtual ~NiRefObject();

protected:
    unsigned int m_uiRefCount;
};

class NiObject : public NiRefObject
{
};

class NiInterpolator : public NiObject
{
public:
    virtual ~NiInterpolator();

protected:
    float m_fLastTime;          // +0x8
};

class NiBlendInterpolator : public NiInterpolator
{
public:
    virtual ~NiBlendInterpolator();

    class InterpArrayItem;

protected:
    unsigned char m_uiObjectFlags;                 // +0xC
    unsigned char m_ucArraySize;            // +0xD
    unsigned char m_ucInterpCount;         // +0xE
    unsigned char m_ucSingleIdx;            // +0xF
    char m_cHighPriority;                   // +0x10
    char m_cNextHighPriority;               // +0x11
    InterpArrayItem* m_pInterpArray;       // +0x14
    NiInterpolator* m_pSingleInterpolator; // +0x18
    float m_fWeightThreshold;               // +0x1C
    float m_fSingleInterpolatorTime;                    // +0x20
    float m_fHighSumOfWeights;              // +0x24
    float m_fNextHighSumOfWeights;          // +0x28
    float m_fTrailingValue;               // +0x2C
};

class NiBlendAccumTransformInterpolator : public NiBlendInterpolator
{
public:
    class AccumulationData;

    void ResetAccumulation();

protected:
    NiQuatTransform m_kAccumulatedTransform;  // +0x30
    AccumulationData* m_pAccumulationData;                // +0x50
    bool m_bHasAccumulation;                                 // +0x54
};

// @fnv 0x00496340
void NiBlendAccumTransformInterpolator::ResetAccumulation()
{
    if (m_ucInterpCount == 1)
    {
        // A single interpolator contributes no accumulation, so the
        // accumulated transform is left invalid.
        NiQuatTransform kTransform;
        m_kAccumulatedTransform = kTransform;
    }
    else
    {
        m_kAccumulatedTransform.GetTransformScale(NiPoint3::ZERO);
        m_kAccumulatedTransform.SetLocalRotation(NiQuaternion::IDENTITY);
        m_kAccumulatedTransform.SetScale(1.0f);
    }
    m_bHasAccumulation = true;
}

#endif
