// bscore/bssimplearray_private_decls.h: declares BSSimpleArrayPacketEffect, BSSimpleArrayPacketDebug, NiNode, PacketNodeRecord, PathingGraphNode and more
#ifndef FNV_BSSIMPLEARRAY_PRIVATE_DECLS_H
#define FNV_BSSIMPLEARRAY_PRIVATE_DECLS_H


typedef int(__cdecl* BSSimpleArrayCompare)(const void*, const void*);
// Canonical placeholder for the runtime copy routine at 0x00ec7230 (_memmove is 0x00ec44d0).
void* __cdecl FUN_00ec7230(void*, const void*, unsigned int);
extern "C" void* __cdecl bsearch(const void*, const void*, unsigned int, unsigned int, BSSimpleArrayCompare);

template <class T, unsigned int N> class BSSimpleArray
{
  public:
    virtual ~BSSimpleArray() = 0;

  protected:
    virtual T* _Allocate(unsigned int count);
    virtual void _Deallocate(T* items);
    virtual T* _Reallocate(T* items, unsigned int count);

  public:
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

    void FUN_006b3eb0(unsigned int, bool);
    void ReleaseElements(T* items, unsigned int count);
    void InitializeItems(T* items, unsigned int count);
    unsigned int BinarySearch(T& value, BSSimpleArrayCompare compare);
    unsigned int ReserveIndex();
    unsigned int Add(T& value);
    void InsertInSortedOrder(T& value, BSSimpleArrayCompare compare);
    void Insert(unsigned int index, T& value);
    void Clear(bool freeBuffer);
    T& GetAt(unsigned int index);
    void SetSize(unsigned int size, bool shrinkBuffer);
    template <unsigned int M> void CopyTo(BSSimpleArray<T, M>* destination);
    template <class U> unsigned int Find(U& value, unsigned int start, bool(__cdecl* compare)(T&, U&));

  private:
    void UpdateEntryValue(T* destination, T* source, unsigned int count);
    void ReallocateStorage(unsigned int newCapacity, unsigned int preserveCount);

  protected:
    void _InitialSetup(unsigned int capacity, unsigned int initialSize);
};

extern unsigned int DAT_0106c264;
extern unsigned int DAT_0106f798;
extern unsigned int DAT_01073e50;
class BSSimpleArrayPacketEffect
{
  public:
    void FUN_007883b0(unsigned int, bool);
};
extern unsigned int DAT_0109504c;
class BSSimpleArrayPacketDebug
{
  public:
    void InitArray(unsigned int, bool);
};

class NiAVObject;
class TESObjectREFR;
class NiNode;
template <class T> class NiTNewInterface;
template <class T, class Allocator> class NiTArray
{
  public:
    T& GetAt(unsigned int);
};
template <class T> class NiPointer
{
  public:
    T* operator->() const;
};
class NiNode
{
    char prefix[0x9c];
    NiTArray<TESObjectREFR*, NiTNewInterface<TESObjectREFR*> > children;

  public:
    NiAVObject* GetAt(unsigned int);
};

class PacketNodeRecord
{
    char storage[0x30];
};
class PathingGraphNode
{
    char storage[0x3c];
};
class BSSimpleArrayPacketNode
{
  public:
    void FUN_006d0510(unsigned int);
};
class BSSimpleArrayPacketReserve
{
  public:
    unsigned int FUN_00761540();
};

#include <stddef.h>
#define FNV_BSSA_JOIN_I(a, b) a##b
#define FNV_BSSA_JOIN(a, b) FNV_BSSA_JOIN_I(a, b)
#define FNV_BSSA_ASSERT(x) typedef char FNV_BSSA_JOIN(bssimplearray_assert_, __LINE__)[(x) ? 1 : -1]
namespace Tile {
class Value;
}
class BGSBodyPart;
class BGSReconstructFormsMap;
class OffsetData
{
  public:
    unsigned int iOffset;
    BGSReconstructFormsMap* m_pFormLookupMap;
};
class ScrapHeapBuffer
{
  public:
    void Deallocate(void* memory);
};
template <class T, unsigned int N> class BSScrapArray : public BSSimpleArray<T, N>
{
  public:
    ScrapHeapBuffer* m_pAllocator;

  protected:
    virtual void _Deallocate(T* items);
};
template <class T> class NiRect
{
  public:
    T m_fMinimumU, m_fMaximumU, m_fMinimumV, m_fMaximumV;
};
class ButtonIcon
{
  public:
    float m_fGlyphWidthInPixels, m_fHorizontalOffset, m_fGlyphVerticalOffset, m_fHorizontalSpacing;
    NiRect<float> m_kTextureCoordinates;
};
enum SANDBOX_PROCEDURE
{
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_NONE = -1,
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_SIT = 0,
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_SLEEP = 1,
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_EAT = 2,
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_WANDER = 3,
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_USE_IDLE_MARKER = 4,
    SANDBOX_PROCEDURE_SANDBOX_PROCEDURE_DIALOGUE = 5,
    SANDBOX_PROCEDURE_NUM_SANDBOX_PROCEDURES = 6
};
class SandboxProcedureData
{
  public:
    TESObjectREFR* pTarget;
    SANDBOX_PROCEDURE eProcedure;
    int m_iActivityState, m_iProcedureData;
    SandboxProcedureData();
};
class NiPoint3
{
  public:
    float x, y, z;
};
enum PathingAvoidNode__AVOID_NODE_TYPE
{
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_SPHERE = 0,
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_CYLINDER = 1,
    PathingAvoidNode__AVOID_NODE_TYPE_AVOID_NODE_SPHERE_ACTOR = 2
};
class PathingAvoidanceNode
{
  public:
    NiPoint3 m_kLocation, TwoComponentVector;
    float fRadius, m_fPathingCostCur;
    PathingAvoidNode__AVOID_NODE_TYPE eType;
};

// This real specialization isolates its private helper ABI from legacy accepted declarations.
template <> class BSSimpleArray<PathingAvoidanceNode, 1024>
{
  public:
    virtual ~BSSimpleArray();

  protected:
    virtual PathingAvoidanceNode* _Allocate(unsigned int count);
    virtual void _Deallocate(PathingAvoidanceNode* items);
    virtual PathingAvoidanceNode* _Reallocate(PathingAvoidanceNode* items, unsigned int count);
    void _InitialSetup(unsigned int capacity, unsigned int initialSize);

  public:
    PathingAvoidanceNode* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;

  private:
    void InitializeItems(PathingAvoidanceNode* items, unsigned int count);
};

typedef BSSimpleArray<Tile::Value*, 8> BSSimpleArrayTileLayout;
typedef BSScrapArray<OffsetData, 1024> BSScrapArrayOffsetLayout;
FNV_BSSA_ASSERT(sizeof(BSSimpleArrayTileLayout) == 16);
FNV_BSSA_ASSERT(offsetof(BSSimpleArrayTileLayout, pBuffer) == 4);
FNV_BSSA_ASSERT(offsetof(BSSimpleArrayTileLayout, iSize) == 8);
FNV_BSSA_ASSERT(offsetof(BSSimpleArrayTileLayout, SimpleArrayStorage) == 12);
FNV_BSSA_ASSERT(sizeof(BSScrapArrayOffsetLayout) == 20);
FNV_BSSA_ASSERT(offsetof(BSScrapArrayOffsetLayout, m_pAllocator) == 16);
typedef BSSimpleArray<PathingAvoidanceNode, 1024> BSSimpleArrayAvoidLayout;
FNV_BSSA_ASSERT(sizeof(BSSimpleArrayAvoidLayout) == 16);
FNV_BSSA_ASSERT(offsetof(BSSimpleArrayAvoidLayout, pBuffer) == 4);
FNV_BSSA_ASSERT(offsetof(BSSimpleArrayAvoidLayout, iSize) == 8);
FNV_BSSA_ASSERT(offsetof(BSSimpleArrayAvoidLayout, SimpleArrayStorage) == 12);
FNV_BSSA_ASSERT(sizeof(OffsetData) == 8);
FNV_BSSA_ASSERT(offsetof(OffsetData, iOffset) == 0);
FNV_BSSA_ASSERT(offsetof(OffsetData, m_pFormLookupMap) == 4);
FNV_BSSA_ASSERT(sizeof(NiRect<float>) == 16);
FNV_BSSA_ASSERT(offsetof(NiRect<float>, m_fMinimumU) == 0);
FNV_BSSA_ASSERT(offsetof(NiRect<float>, m_fMaximumU) == 4);
FNV_BSSA_ASSERT(offsetof(NiRect<float>, m_fMinimumV) == 8);
FNV_BSSA_ASSERT(offsetof(NiRect<float>, m_fMaximumV) == 12);
FNV_BSSA_ASSERT(sizeof(ButtonIcon) == 32);
FNV_BSSA_ASSERT(offsetof(ButtonIcon, m_fGlyphWidthInPixels) == 0);
FNV_BSSA_ASSERT(offsetof(ButtonIcon, m_fHorizontalOffset) == 4);
FNV_BSSA_ASSERT(offsetof(ButtonIcon, m_fGlyphVerticalOffset) == 8);
FNV_BSSA_ASSERT(offsetof(ButtonIcon, m_fHorizontalSpacing) == 12);
FNV_BSSA_ASSERT(offsetof(ButtonIcon, m_kTextureCoordinates) == 16);
FNV_BSSA_ASSERT(sizeof(SandboxProcedureData) == 16);
FNV_BSSA_ASSERT(offsetof(SandboxProcedureData, pTarget) == 0);
FNV_BSSA_ASSERT(offsetof(SandboxProcedureData, eProcedure) == 4);
FNV_BSSA_ASSERT(offsetof(SandboxProcedureData, m_iActivityState) == 8);
FNV_BSSA_ASSERT(offsetof(SandboxProcedureData, m_iProcedureData) == 12);
FNV_BSSA_ASSERT(sizeof(NiPoint3) == 12);
FNV_BSSA_ASSERT(offsetof(NiPoint3, x) == 0);
FNV_BSSA_ASSERT(offsetof(NiPoint3, y) == 4);
FNV_BSSA_ASSERT(offsetof(NiPoint3, z) == 8);
FNV_BSSA_ASSERT(sizeof(PathingAvoidanceNode) == 36);
FNV_BSSA_ASSERT(offsetof(PathingAvoidanceNode, m_kLocation) == 0);
FNV_BSSA_ASSERT(offsetof(PathingAvoidanceNode, TwoComponentVector) == 12);
FNV_BSSA_ASSERT(offsetof(PathingAvoidanceNode, fRadius) == 24);
FNV_BSSA_ASSERT(offsetof(PathingAvoidanceNode, m_fPathingCostCur) == 28);
FNV_BSSA_ASSERT(offsetof(PathingAvoidanceNode, eType) == 32);

#endif
