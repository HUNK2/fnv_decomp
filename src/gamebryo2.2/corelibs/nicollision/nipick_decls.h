// gamebryo2.2/corelibs/nicollision/nipick_decls.h: declares NiAVObject, NiNode, MemoryManager, NiPick, Record and more
#ifndef FNV_NIPICK_DECLS_H
#define FNV_NIPICK_DECLS_H

#include "NiPoint3.h"
#include "NiObjectNET.h"

// Only the inherited reference-counting API is used by this unit.
class NiAVObject : public NiObjectNET
{
};
class NiNode : public NiAVObject
{
};
class MemoryManager
{
  public:
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
void NiFree(void*);
extern void* DAT_010f16ec[];
extern void* DAT_010f16dc[];

class NiPick
{
  public:
    enum PickType
    {
        FIND_ALL = 0,
        FIND_FIRST = 1
    };
    enum SortType
    {
        SORT = 0,
        NO_SORT = 1
    };
    enum IntersectType
    {
        BOUND_INTERSECT = 0,
        TRIANGLE_INTERSECT = 1
    };
    enum CoordinateType
    {
        MODEL_COORDINATES = 0,
        WORLD_COORDINATES = 1
    };
    class Record
    {
      public:
        NiPointer<NiAVObject> m_pReferencedObject;
        NiPointer<NiNode> m_pParentNode;
        NiPoint3 m_vPoint;
        float m_fHitDistance;
        unsigned short m_usFlags;
        unsigned short m_ausPadding[3];
        float m_texture[2];
        NiPoint3 m_vHitNormal;
        float m_kDiffuseColor[4];
    };
    class Results
    {
      public:
        void** m_ppVirtualMethodTable;
        Record** m_pBase;
        unsigned short m_usMaxSize;
        unsigned short m_usSize;
        unsigned short m_usESize;
        unsigned short m_usGrowBy;
        unsigned int m_uiValidCount;

        Record* GetAt(unsigned int index) const
        {
            return m_pBase[index];
        }
        void SetAt(unsigned int index, Record* record)
        {
            if (index >= m_usSize)
            {
                m_usSize = (unsigned short)(index + 1);
                ++m_usESize;
            }
            else if (!m_pBase[index])
            {
                ++m_usESize;
            }
            m_pBase[index] = record;
        }
        void InvokeCallbacks();
        void FindHighestPriorityCallback();
        void Clear() throw();
    };
    PickType m_ePickMode;
    SortType m_eSortMode;
    IntersectType m_eIntersectionMode;
    CoordinateType m_eCoordinateSpace;
    bool m_bFrontFacingOnly;
    bool m_bObserveCull;
    NiPointer<NiAVObject> m_spRootNode;
    Results m_kResults;
    Record* m_pLastRecord;
    bool m_bIncludeTexture;
    bool m_bIncludeNormal;
    bool m_bSmoothNormal;
    bool m_bIncludeColor;
    NiAVObject* GetRoot() const
    {
        return m_spRootNode.m_pObject;
    }
    bool PerformPick(const NiPoint3&, const NiPoint3&, bool);
    ~NiPick();
};
FNV_STATIC_ASSERT(sizeof(NiPick::Record) == 68);
FNV_STATIC_ASSERT(offsetof(NiPick::Record, m_fHitDistance) == 20);
FNV_STATIC_ASSERT(sizeof(NiPick::Results) == 20);
FNV_STATIC_ASSERT(offsetof(NiPick::Results, m_uiValidCount) == 16);
FNV_STATIC_ASSERT(sizeof(NiPick) == 52);
FNV_STATIC_ASSERT(offsetof(NiPick, m_spRootNode) == 20);
FNV_STATIC_ASSERT(offsetof(NiPick, m_kResults) == 24);

namespace NiPickIntersections {
bool FindIntersections(const NiPoint3&, const NiPoint3&, NiPick&, NiAVObject*);
}
#endif
