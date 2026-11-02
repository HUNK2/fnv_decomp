// gamebryo2.2/corelibs/nianimation/niposdata_decls.h: declares AnimationKey, NiObject, NiPosData, NiBinaryStream, NiStream
#ifndef NIPOSDATA_DECLS_H
#define NIPOSDATA_DECLS_H

class NiStream;
class PositionKeyInterpolator;
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
class NiObject
{
  public:
    virtual void LoadBinary(NiStream&);
    unsigned int refs;
};
class NiPosData : public NiObject
{
  public:
    unsigned int m_uiNumKeys;
    PositionKeyInterpolator* m_pKeyArray;
    AnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    void SetColorKeys(PositionKeyInterpolator*, unsigned int, AnimationKey::KeyType);
    virtual void LoadBinary(NiStream&);
};
extern unsigned char DAT_011f375e[];
extern void (*DAT_011f38b8[])(PositionKeyInterpolator*);
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int (*read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void Read(void* data, unsigned int bytes)
    {
        unsigned int size = 4;
        position += read(this, data, bytes, &size, 1);
    }
};
class NiStream
{
  public:
    unsigned char padding[0x24c];
    NiBinaryStream* input;
    AnimationKey::KeyType ReadType()
    {
        unsigned int raw;
        input->Read(&raw, 4);
        return (AnimationKey::KeyType)raw;
    }
};
extern PositionKeyInterpolator* (*DAT_011f3dc8[])(NiStream&, unsigned int);
extern void (*DAT_011f3798[])(PositionKeyInterpolator*, unsigned int, unsigned char);
inline unsigned char GetPosKeySize(AnimationKey::KeyType type)
{
    return DAT_011f375e[type];
}
typedef PositionKeyInterpolator* (*CreatePosKeys)(NiStream&, unsigned int);
typedef void (*FillPosKeys)(PositionKeyInterpolator*, unsigned int, unsigned char);
inline CreatePosKeys GetCreatePosKeys(AnimationKey::KeyType type)
{
    return DAT_011f3dc8[type];
}
inline FillPosKeys GetFillPosKeys(AnimationKey::KeyType type)
{
    return DAT_011f3798[type];
}
#endif
