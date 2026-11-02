// Authored unit-local declarations for gamebryo2.2/corelibs/nimain/nitimecontroller.cpp.
// FNV (Fallout: New Vegas, Gamebryo 2.2 branch) revision of NiTimeController.
// size 0x18). NiStream member offsets (+0xD8 file version, +0x24C binary
// stream, +0x284/0x286/0x288 legacy flag cache) and the NiBinaryStream
// function-pointer read idiom are taken from matcher task evidence for this
// unit. The NiObject/NiObjectNET/NiTimeController virtual ordering below
// reproduces the observed PC vtable slots used by this unit (NiObject
// LoadBinary 19, LinkObject 20, RegisterStreamables 21, SaveBinary 22,
// IsEqual 23, GetViewerStrings 24, ProcessClone 26; NiTimeController
// Start 35, Stop 36, Update 37 pure, SetTarget 38, ComputeScaledTime 41,
// ResetControllerState 42, IsTransformInterpolator 44 pure).
// NiPointer comes from layout_support.h. NOTE: the FNV 2.2 NiPointer
// assignment inlines dec-old before inc-new (see LinkObject below), which is
// the order the original bytes exhibit.
#ifndef FNV_NITIMECONTROLLER_UNIT_H
#define FNV_NITIMECONTROLLER_UNIT_H


#include "layout_support.h"

class CloningProcess;
class NiGeometryData;
class NiObject;
class NiObjectGroup;
class NiObjectNET;
class NiRTTI;
class NiStream;
class NiTimeController;
class NiViewerStringsArray;

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
// NiObject. Virtual order matches the FNV PC vtable used by this unit.
// ---------------------------------------------------------------------------
class NiObject : public NiRefObject
{
  public:
    virtual ~NiObject();
    virtual const NiRTTI* GetRTTI() const;
    virtual NiObject* MakeClone(CloningProcess& kCloning);
    virtual void CopyMemberData(NiObject* pkDest, CloningProcess& kCloning);
    virtual void PostLinkObject(NiStream& kStream);
    virtual bool StreamCanSkip();
    virtual bool GetStreamableRTTIName(char* acName, unsigned int uiMaxSize) const;
    virtual unsigned int GetBlockAllocationSize() const;
    virtual NiObjectGroup* GetGroup() const;
    virtual void SetGroup(NiObjectGroup* pkGroup);
    virtual void AddViewerStrings(NiViewerStringsArray* pkViewerStrings);
    // Slots 12-18: further FNV NiObjectNET-level virtuals (order approximated).
    virtual void SetName(unsigned int uiName);
    virtual bool AddExtraData(NiObject* pkExtra);
    virtual NiObject* GetExtraData() const;
    virtual bool RemoveExtraDataByName(NiObject* pkExtra);
    virtual void UpdateModelBound();
    virtual bool ResizeExtraData(unsigned short usSize);
    virtual void GetNumChildren();
    // Streaming / cloning.
    virtual void LoadBinary(NiStream& kStream);                            // slot 19
    virtual void LinkObject(NiStream& kStream);                            // slot 20
    virtual bool RegisterStreamables(NiStream& kStream);                   // slot 21
    virtual void SaveBinary(NiStream& kStream);                            // slot 22
    virtual bool IsEqual(NiObject* pkObject);                              // slot 23
    virtual void GetViewerStrings(NiViewerStringsArray* pkViewerStrings);  // slot 24
    virtual void InsertExtraData(NiObject* pkExtra);                       // slot 25
    virtual void ProcessClone(CloningProcess& kCloning);                   // slot 26
};

// ---------------------------------------------------------------------------
// NiFixedString (4 bytes: string-table pointer).
// ---------------------------------------------------------------------------
class NiFixedString
{
  public:
    const char* m_pString;  // +0x0
};

// ---------------------------------------------------------------------------
// NiObjectNET.
// ---------------------------------------------------------------------------
class NiObjectNET : public NiObject
{
  public:
    virtual ~NiObjectNET();

    void AddController(NiTimeController* pkControl);
    inline NiTimeController* GetControllers() const
    {
        return m_pControllers.m_pObject;
    }
    void ReplaceControllers(NiTimeController* pkControl);

    NiFixedString m_kName;                       // +0x8
    NiPointer<NiTimeController> m_pControllers;  // +0xC
    void* m_ppExtraData;                         // +0x10
    unsigned short m_usExtraDataCount;           // +0x14
    unsigned short m_usMaxSize;                  // +0x16
};
FNV_STATIC_ASSERT(sizeof(NiObjectNET) == 0x18);
FNV_STATIC_ASSERT(offsetof(NiObjectNET, m_pControllers) == 0xC);

// ---------------------------------------------------------------------------
// NiGeometryData (only what the controller attach path uses).
// ---------------------------------------------------------------------------
class NiGeometryData : public NiObject
{
  public:
    enum Consistency
    {
        STATIC = 0
    };
    void SetDataConsistency(Consistency eConsistency);
};

// ---------------------------------------------------------------------------
// NiGeometry (only what the controller attach path uses: the model-data
// pointer is read at +0xB8 in FNV 2.2).
// ---------------------------------------------------------------------------
class NiGeometry : public NiObjectNET
{
  public:
    unsigned char m_auPad[0xB8 - 0x18];
    NiGeometryData* m_spGeometryData;  // +0xB8
    inline NiGeometryData* GetModelData() const
    {
        return m_spGeometryData;
    }
};

// ---------------------------------------------------------------------------
// NiBinaryStream function-pointer read idiom (NiBinaryStream.h shape).
// ---------------------------------------------------------------------------
class NiBinaryStream : public NiMemObject
{
  public:
    NiBinaryStream();
    virtual ~NiBinaryStream();

    typedef unsigned int (*NIBINARYSTREAM_READFN)(NiBinaryStream* pkThis, void* pvBuffer, unsigned int uiBytes,
                                                  unsigned int* puiComponentSizes, unsigned int uiNumComponents);
    typedef unsigned int (*NIBINARYSTREAM_WRITEFN)(NiBinaryStream* pkThis, const void* pvBuffer, unsigned int uiBytes,
                                                   unsigned int* puiComponentSizes, unsigned int uiNumComponents);

    inline unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                                   unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }

    unsigned int m_uiStreamFlags;       // +0x4
    NIBINARYSTREAM_READFN m_pfnRead;    // +0x8
    NIBINARYSTREAM_WRITEFN m_pfnWrite;  // +0xC
};

// Release-mode diagnostics (Gamebryo NiRTLib.h shape: asserts vanish,
// verified reads still execute).
#define NIASSERT(x) ((void)0)
#define NIVERIFYEQUALS(x, y) (x)

template <class T> void NiBinaryStreamLoad(NiBinaryStream& is, T* pValue, unsigned int uiNumEls = 1)
{
    NIASSERT(uiNumEls > 0);
    unsigned int uiSize = sizeof(T);
    NIVERIFYEQUALS(is.BinaryRead(pValue, sizeof(T) * uiNumEls, &uiSize, 1), sizeof(T) * uiNumEls);
}

// ---------------------------------------------------------------------------
// NiStream (only what this unit uses).
// ---------------------------------------------------------------------------
class NiStream : public NiObject
{
  public:
    void ResetStreamState();
    NiObject* GetLoadedObject();
    inline unsigned int GetFileVersion() const
    {
        return m_uiNifVersion;
    }
    inline void SetLastNiTimeControllerFlags(unsigned short usFlags)
    {
        m_usTimeControllerFlags = usFlags;
    }

    unsigned char m_auPad0[0xD8 - 0x8];
    unsigned int m_uiNifVersion;  // +0xD8
    unsigned char m_auPad1[0x24C - 0xDC];
    NiBinaryStream* m_pUnderlyingStream;  // +0x24C
    unsigned char m_auPad2[0x284 - 0x250];
    unsigned short m_usAVObjectFlags;        // +0x284
    unsigned short m_usTimeControllerFlags;  // +0x286
    unsigned short m_usPropertyFlags;        // +0x288
};

template <class T> void ReadBinaryValue(NiStream& kStream, T& value)
{
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &value, 1);
}

// ---------------------------------------------------------------------------
// NiTimeController.
// ---------------------------------------------------------------------------
class NiTimeController : public NiObject
{
  public:
    enum AnimType
    {
        APP_TIME,
        APP_INIT
    };
    enum CycleType
    {
        LOOP,
        REVERSE,
        CLAMP,
        MAX_CYCLE_TYPES
    };

    // Slots 27-34: FNV-virtualized accessors (order approximated).
    virtual void SetFrequency(float fFreq);
    virtual float GetFrequency() const;
    virtual void SetSequenceTime(float fPhase);
    virtual float GetPhase() const;
    virtual void SetBeginKeyTime(float fBegin);
    virtual float GetBeginKeyTime() const;
    virtual void SetEndKeyTime(float m_fEndValue);
    virtual float GetEndKeyTime() const;

    virtual void Start(float fTime);                   // slot 35
    virtual void Stop();                               // slot 36
    virtual void Update(float fTime) = 0;              // slot 37
    virtual void SetTarget(NiObjectNET* pkTarget);     // slot 38
    virtual bool IsTransformController() const;        // slot 39
    virtual bool IsGeometryController() const;         // slot 40
    virtual float ComputeScaledTime(float fTime);      // slot 41
    virtual void ResetControllerState();               // slot 42
    virtual void ResetModifierData();                  // slot 43
    virtual bool IsTransformInterpolator() const = 0;  // slot 44

    virtual void LoadBinary(NiStream& kStream);
    virtual void LinkObject(NiStream& kStream);
    virtual void ProcessClone(CloningProcess& kCloning);

    inline NiTimeController* GetNext() const
    {
        return m_spNextController.m_pObject;
    }
    inline void SetControllerActive(bool bForceUpdate)
    {
        if (bForceUpdate)
            m_uiObjectFlags |= FORCEUDPATE_MASK;
        else
            m_uiObjectFlags &= ~FORCEUDPATE_MASK;
    }
    inline void SetComputeScaledTime(bool bComputeScaledTime)
    {
        if (bComputeScaledTime)
            m_uiObjectFlags |= COMPUTESCALEDTIME_MASK;
        else
            m_uiObjectFlags &= ~COMPUTESCALEDTIME_MASK;
    }

    enum
    {
        ANIMTYPE_MASK = 0x0001,
        CYCLETYPE_MASK = 0x0006,
        ACTIVE_MASK = 0x0008,
        DIRECTION_MASK = 0x0010,
        MANAGERCONTROLLED_MASK = 0x0020,
        COMPUTESCALEDTIME_MASK = 0x0040,
        FORCEUDPATE_MASK = 0x0080
    };

    unsigned short m_uiObjectFlags;                         // +0x8
    float m_fFrequency;                              // +0xC
    float m_fPhase;                                  // +0x10
    float m_fLoKeyTime;                              // +0x14
    float m_fHiKeyTime;                              // +0x18
    float m_fStartTime;                              // +0x1C
    float m_fLastTime;                               // +0x20
    float m_fWeightAdjustedLastTime;                 // +0x24
    float m_fControllerTime;                         // +0x28
    NiObjectNET* m_pkTarget;                         // +0x2C
    NiPointer<NiTimeController> m_spNextController;  // +0x30
};
FNV_STATIC_ASSERT(sizeof(NiTimeController) == 0x34);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_uiObjectFlags) == 0x8);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_fFrequency) == 0xC);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_pkTarget) == 0x2C);
FNV_STATIC_ASSERT(offsetof(NiTimeController, m_spNextController) == 0x30);

#endif
