// Authored unit-local declarations for
// gamebryo2.2/corelibs/nianimation/nifloatinterpolator.cpp.
//
// NiInterpolator/NiKeyBasedInterpolator/NiFloatInterpolator/NiFloatData member
// CodeView layouts, member order and layout asserts unchanged); only the
// virtuals actually used by this unit's bytes are declared, so the
// NiFloatInterpolator vtable is the symbol bound in manifest.json.
// NiStream exposes only m_pUnderlyingStream (+0x24C) and DeserializeObject, and the
// NiBinaryStream read idiom plus the NiRefObject IncRefCount/DecRefCount
// bodies follow the accepted corelibs/nimain/nitimecontroller.cpp unit.
#ifndef FNV_NIFLOATINTERPOLATOR_UNIT_H
#define FNV_NIFLOATINTERPOLATOR_UNIT_H


#include <float.h>
#include <stddef.h>

#define FNV_NIFI_SIZE_ASSERT(type, size) typedef char fnv_nifi_size_##type[(sizeof(type) == (size)) ? 1 : -1]
#define FNV_NIFI_OFFSET_ASSERT(type, member, offset)                                                                   \
    typedef char fnv_nifi_offset_##type##_##member[(offsetof(type, member) == (offset)) ? 1 : -1]

#define FNV_FORCEINLINE __forceinline

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);

class NiStream;

// ---------------------------------------------------------------------------
// NiMemObject / NiRefObject.
// ---------------------------------------------------------------------------
class NiMemObject
{
  public:
    virtual ~NiMemObject();
};

class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;  // +0x4
    virtual ~NiRefObject();
    virtual void DeleteThis();
    FNV_FORCEINLINE void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    FNV_FORCEINLINE void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

// ---------------------------------------------------------------------------
// NiObject.
// ---------------------------------------------------------------------------
class NiObject : public NiRefObject
{
  public:
    virtual ~NiObject();
    virtual void LoadBinary(NiStream& kStream);
};

// ---------------------------------------------------------------------------
// NiPointer (single reference counted pointer). The destructor is instantiated
// by the owning units; this unit only needs the retaining constructor, and a
// non-trivial destructor here would add an unwind funclet to the covered
// NiFloatInterpolator constructor, which the original bytes do not have.
// ---------------------------------------------------------------------------
template <class T> class NiPointer
{
  public:
    T* m_pObject;

    FNV_FORCEINLINE NiPointer(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
};

// ---------------------------------------------------------------------------
// NiStream (only what this unit uses).
// ---------------------------------------------------------------------------
class NiBinaryStream : public NiMemObject
{
  public:
    typedef unsigned int (*NIBINARYSTREAM_READFN)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                  unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    unsigned int m_uiStreamFlags;     // +0x4
    NIBINARYSTREAM_READFN m_pfnRead;  // +0x8

    FNV_FORCEINLINE unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                                            unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

class NiStream
{
  public:
    NiObject* DeserializeObject();

    unsigned char m_auPadStreamHeader[0x24C];
    NiBinaryStream* m_pUnderlyingStream;  // +0x24C
};
FNV_NIFI_OFFSET_ASSERT(NiStream, m_pUnderlyingStream, 0x24C);

// ---------------------------------------------------------------------------
// NiFloatData.
// ---------------------------------------------------------------------------
class TimedAnimationKey;

enum NiAnimationKey__KeyType
{
    NiAnimationKey__KeyType_NOINTERP = 0,
    NiAnimationKey__KeyType_LINKEY = 1,
    NiAnimationKey__KeyType_BEZKEY = 2,
    NiAnimationKey__KeyType_TCBKEY = 3,
    NiAnimationKey__KeyType_EULERKEY = 4,
    NiAnimationKey__KeyType_STEPKEY = 5,
    NiAnimationKey__KeyType_NUMKEYTYPES = 6
};

class NiFloatData : public NiObject
{
  public:
    unsigned int m_uiNumKeys;                // +0x8, 4 bytes
    TimedAnimationKey* m_pKeyArray;          // +0xC, 4 bytes
    NiAnimationKey__KeyType m_eRequestType;  // +0x10, 4 bytes
    unsigned char m_ucKeyDataSize;           // +0x14, 1 bytes
    unsigned char m_auPadKeySize[3];
};
FNV_NIFI_SIZE_ASSERT(NiFloatData, 24);
FNV_NIFI_OFFSET_ASSERT(NiFloatData, m_uiNumKeys, 8);
FNV_NIFI_OFFSET_ASSERT(NiFloatData, m_pKeyArray, 12);
FNV_NIFI_OFFSET_ASSERT(NiFloatData, m_eRequestType, 16);
FNV_NIFI_OFFSET_ASSERT(NiFloatData, m_ucKeyDataSize, 20);

// ---------------------------------------------------------------------------
// ---------------------------------------------------------------------------
class NiInterpolator : public NiObject
{
  public:
    virtual ~NiInterpolator();
    virtual void LoadBinary(NiStream& kStream);

    float m_fLastTime;  // +0x8, 4 bytes
};
FNV_NIFI_SIZE_ASSERT(NiInterpolator, 12);
FNV_NIFI_OFFSET_ASSERT(NiInterpolator, m_fLastTime, 8);

class NiKeyBasedInterpolator : public NiInterpolator
{
  public:
    NiKeyBasedInterpolator();
    virtual ~NiKeyBasedInterpolator();
    virtual void LoadBinary(NiStream& kStream);
};
FNV_NIFI_SIZE_ASSERT(NiKeyBasedInterpolator, 12);

class NiFloatInterpolator : public NiKeyBasedInterpolator
{
  public:
    NiFloatInterpolator(NiFloatData* pkFloatData);
    virtual ~NiFloatInterpolator();
    virtual void LoadBinary(NiStream& kStream);

    float m_fFloatValue;                   // +0xC, 4 bytes
    NiPointer<NiFloatData> m_spFloatData;  // +0x10, 4 bytes
    unsigned int m_uiLastKeyIndex;         // +0x14, 4 bytes
};
FNV_NIFI_SIZE_ASSERT(NiFloatInterpolator, 24);
FNV_NIFI_OFFSET_ASSERT(NiFloatInterpolator, m_fFloatValue, 12);
FNV_NIFI_OFFSET_ASSERT(NiFloatInterpolator, m_spFloatData, 16);
FNV_NIFI_OFFSET_ASSERT(NiFloatInterpolator, m_uiLastKeyIndex, 20);

// Release-mode diagnostics: asserts vanish, the verified read still runs.
#define NIASSERT(x) ((void)0)
#define NIVERIFYEQUALS(x, y) (x)

template <class T> FNV_FORCEINLINE void NiBinaryStreamLoad(NiBinaryStream& is, T* pValue, unsigned int uiNumEls = 1)
{
    NIASSERT(uiNumEls > 0);
    unsigned int uiSize = sizeof(T);
    NIVERIFYEQUALS(is.BinaryRead(pValue, sizeof(T) * uiNumEls, &uiSize, 1), sizeof(T) * uiNumEls);
}

template <class T> FNV_FORCEINLINE void ReadBinaryValue(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &value, 1);
}

#endif