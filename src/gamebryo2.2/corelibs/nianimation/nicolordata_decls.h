// gamebryo2.2/corelibs/nianimation/nicolordata_decls.h: declares AnimationKey, NiColorData
#ifndef NICOLORDATA_DECLS_H
#define NICOLORDATA_DECLS_H

#include "NiObject.h"
class AnimationKey
{
  public:
    enum KeyType
    {
        NOINTERP,
        LINKEY,
        BEZKEY,
        TCBKEY,
        EULERKEY,
        STEPKEY,
        NUMKEYTYPES
    };
};
class ColorAnimationKey;
typedef void(__cdecl* NiColorDeleteFunction)(ColorAnimationKey*);
extern NiColorDeleteFunction DAT_011f38e8[];
extern unsigned char DAT_011f376a[];
class NiColorData : public NiObject
{
  public:
    unsigned int m_uiNumKeys;
    ColorAnimationKey* m_pKeyArray;
    AnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    void SetColorKeys(ColorAnimationKey*, unsigned int, AnimationKey::KeyType);
};
#endif
