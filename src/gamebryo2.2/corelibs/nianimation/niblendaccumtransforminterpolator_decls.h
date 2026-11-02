
class NiObjectNET;
class NiPoint3
{
  public:
    float x, y, z;
};
class NiQuaternion
{
  public:
    float w, x, y, z;
};
extern NiPoint3 DAT_011a8400;
extern NiQuaternion DAT_011f3704;
extern float DAT_01096b8c;
extern float DAT_0109696c;
class NiQuatTransform
{
  public:
    NiPoint3 m_kTranslate;
    NiQuaternion m_kRotate;
    float m_fScale;
    void TransformBy(NiQuatTransform&);
    NiQuatTransform CombineTransforms(const NiQuatTransform&);
    bool IsMarkedInvalid() const
    {
        return m_fScale == -3.4028234663852886e38 && m_kRotate.x == -3.4028234663852886e38 &&
               m_kTranslate.x == -3.4028234663852886e38;
    }
};
struct AccumItem
{
    float time;
    NiQuatTransform value, accum;
    float rotation[9];
};
class NiBlendAccumTransformInterpolator
{
  public:
    char prefix[12];
    unsigned char m_uiObjectFlags, m_ucArraySize, m_ucInterpCount, m_ucSingleIdx;
    char rest[16];
    float m_fSingleInterpolatorTime;
    char rest2[12];
    NiQuatTransform m_kAccumulatedTransform;
    AccumItem* m_pAccumulationData;
    bool m_bHasAccumulation;
    void UpdateAccumulation(float, NiObjectNET*);
    bool UpdateAccumulatedTransform(float, NiObjectNET*, NiQuatTransform&);
};
