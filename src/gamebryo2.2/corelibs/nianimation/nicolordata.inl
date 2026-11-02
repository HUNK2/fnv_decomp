
#define NiColorData NiColorData_OLD
#include "nicolordata_decls.h"
#undef NiColorData
class NiColorData : public NiObject {
public:
    NiColorData();
    virtual ~NiColorData();
    unsigned int m_uiNumKeys;
    ColorAnimationKey* m_pKeyArray;
    AnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    void SetColorKeys(ColorAnimationKey*, unsigned int, AnimationKey::KeyType);
};
// @fnv 0x0052d0e0
NiColorData::NiColorData()
{
    m_uiNumKeys = 0;
    m_pKeyArray = 0;
    m_eRequestType = AnimationKey::NOINTERP;
}
