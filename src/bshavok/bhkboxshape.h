// bshavok/bhkboxshape.h: declares bhkBoxShape
#ifndef BHKBOXSHAPE_H
#define BHKBOXSHAPE_H


class NiRTTI;
class hkVector4;

class bhkBoxShape
{
  public:
    unsigned int m_uiRefCount;
    void* m_pHavokObject;
    void* pInfo;
    unsigned int m_uiMaterial;

    void Init(const hkVector4& halfExtents);
    virtual const NiRTTI* GetRTTI() const;
    static const NiRTTI ms_kRTTI;
};

// @fnv 0x0056e7f0
const NiRTTI* bhkBoxShape::GetRTTI() const
{
    return &ms_kRTTI;
}

#endif
