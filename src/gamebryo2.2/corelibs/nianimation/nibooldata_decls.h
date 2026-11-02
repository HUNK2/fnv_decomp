// gamebryo2.2/corelibs/nianimation/nibooldata_decls.h: declares NiObject, NiBinaryStream, AnimationKey, BooleanKey, NiBoolData
#ifndef FNV_NIBOOLDATA_DECLS_H
#define FNV_NIBOOLDATA_DECLS_H

#include "layout_support.h"
#include "NiRefObject.h"

class NiStream;
class NiRTTI;
class NiObject : public NiRefObject
{
  public:
    virtual const NiRTTI* GetRTTI() const;
    virtual NiNode* GetNiNode();
    virtual void* GetFadeNode();
    virtual void* GetMultiBoundNode();
    virtual void* GetNiGeometry();
    virtual void* GetTriBasedGeom();
    virtual void* GetTriStrips();
    virtual void* GetTriShape();
    virtual void* GetSegmentedTriShape();
    virtual void* GetResizableTriShape();
    virtual void* GetNiParticles();
    virtual void* GetNiLines();
    virtual void* GetCollisionObject();
    virtual void* GetBlendCollisionObject();
    virtual void* GetRigidBody();
    virtual void* GetLimitedHingeConstraint();
    virtual NiObject* MakeClone(void*);
    virtual void LoadBinary(NiStream&);
};

class NiBinaryStream
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(NiBinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    inline unsigned int BinaryRead(void* buffer, unsigned int bytes, unsigned int* sizes, unsigned int count)
    {
        unsigned int read = (*m_pfnRead)(this, buffer, bytes, sizes, count);
        m_uiStreamFlags += read;
        return read;
    }
};
#include "nibooldata_stream_layout.h"

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
    float m_fTime;
};

extern unsigned char DAT_011f3776[AnimationKey::NUMKEYTYPES];
typedef AnimationKey*(__cdecl* NiBoolLoadFunction)(NiStream&, unsigned int);
typedef void(__cdecl* NiBoolFillFunction)(AnimationKey*, unsigned int, unsigned char);
typedef void(__cdecl* NiBoolDeleteFunction)(AnimationKey*);
extern NiBoolLoadFunction DAT_011f3e28[AnimationKey::NUMKEYTYPES];
extern NiBoolFillFunction DAT_011f37f8[AnimationKey::NUMKEYTYPES];
extern NiBoolDeleteFunction DAT_011f3918[AnimationKey::NUMKEYTYPES];

class BooleanKey : public AnimationKey
{
  public:
    bool m_bValue;
    static inline unsigned char GetKeySize(KeyType type)
    {
        return DAT_011f3776[type];
    }
    static inline NiBoolLoadFunction GetLoadFunction(KeyType type)
    {
        return DAT_011f3e28[type];
    }
    static inline NiBoolFillFunction GetFillDerivedFunction(KeyType type)
    {
        return DAT_011f37f8[type];
    }
    static inline NiBoolDeleteFunction GetDeleteFunction(KeyType type)
    {
        return DAT_011f3918[type];
    }
};

template <class T> inline void ReadBinaryValue(NiBinaryStream& input, T& value)
{
    unsigned int size = sizeof(T);
    input.BinaryRead(&value, size, &size, 1);
}
template <class T> inline void ReadBinaryValue(NiStream& stream, T& value)
{
    ReadBinaryValue(*stream.m_pUnderlyingStream, value);
}

inline void ReadBinaryValue(NiBinaryStream& input, AnimationKey::KeyType& type)
{
    unsigned int storedType;
    unsigned int size = sizeof(storedType);
    unsigned int bytesRead = (*input.m_pfnRead)(&input, &storedType, size, &size, 1);
    type = static_cast<AnimationKey::KeyType>(storedType);
    input.m_uiStreamFlags += bytesRead;
}
inline void ReadBinaryValue(NiStream& stream, AnimationKey::KeyType& type)
{
    ReadBinaryValue(*stream.m_pUnderlyingStream, type);
}

class NiBoolData : public NiObject
{
  public:
    unsigned int m_uiNumKeys;
    BooleanKey* m_pKeyArray;
    AnimationKey::KeyType m_eRequestType;
    unsigned char m_ucKeyDataSize;
    virtual void LoadBinary(NiStream& stream);
    void SetColorKeys(BooleanKey*, unsigned int, AnimationKey::KeyType);
};
FNV_STATIC_ASSERT(sizeof(NiBoolData) == 24);
FNV_STATIC_ASSERT(offsetof(NiBoolData, m_uiNumKeys) == 8);
FNV_STATIC_ASSERT(offsetof(NiBoolData, m_ucKeyDataSize) == 20);
FNV_STATIC_ASSERT(sizeof(NiBinaryStream) == 16);
#endif
