// Authored unit-local declarations for gamebryo2.2/corelibs/nimain/nigeometrydata.cpp.
// FNV (Fallout: New Vegas, Gamebryo 2.2 branch) revision of NiGeometryData.
// (m_usVertices +0x8 .. m_bVerticesDirty +0x3C, size 0x40) and the
// community reverse-engineered header (JIP LN NVSE netimmerse.h NiGeometryData).
// NiObject virtual ordering (LoadBinary 19, LinkObject 20, RegisterStreamables 21,
// SaveBinary 22, IsEqual 23, GetViewerStrings 24, ProcessClone 26) and the NiStream
// shape (GetLoadedObject, inline GetFileVersion reading +0xD8, raw-hex version
// comparisons) follow the accepted NiTimeController unit
// (decomp/src/gamebryo2.2/corelibs/nimain/nitimecontroller.h). NiPointer comes
// from layout_support.h; streaming assignments expand the NiPointer idiom
// manually (dec-old before inc-new), matching the original bytes.
// NiAdditionalGeometryData slots 27-34 are order-approximated; IsPacked is slot 35
// (community/JIP-LN-NVSE vtable entry at 0x8C).
#ifndef FNV_NIGEOMETRYDATA_UNIT_H
#define FNV_NIGEOMETRYDATA_UNIT_H


#include "layout_support.h"
#include "NiMemObject.h"
#include "NiRefObject.h"
#include "NiPoint3.h"

class NiAdditionalGeometryData;
class NiBound;
class CloningProcess;
class RgbaColor;
class NiGeometryData;
class NiObjectGroup;
class NiPoint2;
class NiRTTI;
class NiStream;
class NiViewerStringsArray;

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
    // Slots 12-18: further FNV NiObject-level virtuals (order approximated).
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
// NiBound (16 bytes: center + radius).
// ---------------------------------------------------------------------------
class NiBound
{
  public:
    NiPoint3 m_kCenter;    // +0x0
    float m_fBoundRadius;  // +0xC
};
FNV_STATIC_ASSERT(sizeof(NiBound) == 16);
FNV_STATIC_ASSERT(offsetof(NiBound, m_kCenter) == 0);
FNV_STATIC_ASSERT(offsetof(NiBound, m_fBoundRadius) == 12);

// ---------------------------------------------------------------------------
// NiAdditionalGeometryData (only what this unit uses: slot 35 IsPacked and
// the inherited slot 21 RegisterStreamables).
// ---------------------------------------------------------------------------
class NiAdditionalGeometryData : public NiObject
{
  public:
    // Slots 27-34: NiAdditionalGeometryData-level virtuals (order approximated).
    virtual unsigned short GetVertexCount() const;
    virtual void SetVertexCount(unsigned short usVertices);
    virtual bool HasGeometryProperty() const;
    virtual void CopyDataMembers(const NiAdditionalGeometryData* pkSrc);
    virtual void ReserveDataStreams(unsigned int ItemUpdateArray);
    virtual unsigned int GetDataStreamCount() const;
    virtual void* GetDataStream(unsigned int uiIndex);
    virtual bool IsDataStreamValid(unsigned int uiIndex) const;
    void* FUN_00a72590(unsigned int, unsigned int*);
    void* FUN_00a725d0(unsigned int);
    virtual bool IsPacked() const;  // slot 35
};

// ---------------------------------------------------------------------------
// NiStream (only what this unit uses).
// ---------------------------------------------------------------------------
class NiStream : public NiObject
{
  public:
    NiObject* GetLoadedObject();
    inline unsigned int GetFileVersion() const
    {
        return m_uiNifVersion;
    }

    unsigned char m_auPad0[0xD8 - 0x8];
    unsigned int m_uiNifVersion;  // +0xD8
};

// ---------------------------------------------------------------------------
// NiGeometryData.
// ---------------------------------------------------------------------------
class NiGeometryData : public NiObject
{
  public:
    enum Consistency
    {
        MUTABLE = 0,
        STATIC = 16384,
        VOLATILE = 32768,
        CONSISTENCY_MASK = 28672
    };
    enum DataFlags
    {
        NBT_METHOD_NONE = 0,
        NBT_METHOD_NDL = 4096,
        NBT_METHOD_DEPRECATED = 8192,
        NBT_METHOD_ATI = 12288,
        NBT_METHOD_MASK = 61440,
        TEXTURE_SET_MASK = 1
    };

    void SetDataConsistency(Consistency eConsistency);
    void SetDirtyFlags(unsigned int uiDirtyFlags);
    void SetCompressFlags(unsigned char ucCompressFlags);
    bool IsGeometryDataStreamable(bool bWrite);
    virtual void LinkObject(NiStream& kStream);
    virtual bool RegisterStreamables(NiStream& kStream);

    unsigned short m_usVertices;                                 // +0x8
    unsigned short m_usGeometryFlags;                            // +0xA
    unsigned short m_usTrianglePoints;                           // +0xC
    unsigned short m_usDirtyFlags;                               // +0xE
    NiBound m_kBound;                                            // +0x10
    NiPoint3* m_pkVertex;                                        // +0x20
    NiPoint3* m_pkNormal;                                        // +0x24
    RgbaColor* m_pkColor;                                        // +0x28
    NiPoint2* m_pkTexture;                                       // +0x2C
    NiPointer<NiAdditionalGeometryData> m_spAdditionalGeomData;  // +0x30
    void* m_pkGeometryRendererData;                              // +0x34
    unsigned char m_ucKeepFlags;                                 // +0x38
    unsigned char m_ucCompressFlags;                             // +0x39
    bool m_bIsDynamic;                                           // +0x3A
    bool m_bBoundDirty;                                          // +0x3B
    bool m_bVerticesDirty;                                       // +0x3C
};
FNV_STATIC_ASSERT(sizeof(NiGeometryData) == 64);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_usVertices) == 8);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_usGeometryFlags) == 10);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_usTrianglePoints) == 12);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_usDirtyFlags) == 14);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_kBound) == 16);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkVertex) == 32);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkNormal) == 36);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkColor) == 40);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkTexture) == 44);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_spAdditionalGeomData) == 48);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_pkGeometryRendererData) == 52);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_ucKeepFlags) == 56);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_ucCompressFlags) == 57);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_bIsDynamic) == 58);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_bBoundDirty) == 59);
FNV_STATIC_ASSERT(offsetof(NiGeometryData, m_bVerticesDirty) == 60);

#endif
