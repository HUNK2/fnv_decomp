// fallout_shared/facegen/bsfacegenmorph.cpp: BSFaceGenMorphStatistical, BSFaceGenMorphDifferential, GeometryVertexBuffer (14 functions)

#include "bsfacegenmorph_decls.h"

// @fnv 0x00660970
BSFaceGenMorphStatistical::BSFaceGenMorphStatistical(unsigned int count, unsigned int firstIndex)
{
    m_ppVirtualMethodTable = (void**)DAT_01065cd0;
    m_uiVertexCount = count;
    m_uiFirstIndex = firstIndex;
    if (m_uiVertexCount)
        m_puiVertexIndices = new unsigned long[m_uiVertexCount];
    else
        m_puiVertexIndices = 0;
}

// Constructor: stores the global pointer and count, and allocates an array of NiPoint3 of size count (or null when count is zero).
// @fnv 0x00660700
BSFaceGenMorphDifferential::BSFaceGenMorphDifferential(unsigned int count)
{
    m_ppVirtualMethodTable = (void**)DAT_01065cc4;
    m_uiVertexCount = count;
    if (m_uiVertexCount)
        m_pkDeltas = new NiPoint3[m_uiVertexCount];
    else
        m_pkDeltas = 0;
}

// @fnv 0x0065b390
void GeometryVertexBuffer::SetVertex(unsigned int index, const NiPoint3& vertex)
{
    ((MagicCaster*)this)->MagicCaster::SetSelectedMagicItem((MagicItem*)index);
    char* pVertex = m_pkDeltas + index * stride;
    NiPoint3& result = *(NiPoint3*)pVertex;
    result = vertex;
}

// Applies a weighted morph differential to the geometry's vertex positions when geom is valid and weight is in (0,1].
// @fnv 0x00660860
void BSFaceGenMorphDifferential::ApplyDifferentialMorph(NiTriBasedGeom* geom, BSFaceGenBaseMorphExtraData* extra,
                                                        float weight)
{
    if (!geom || weight <= 0.0 || weight > 1.0)
        return;
    NiGeometryData* pData = geom->FUN_005495f0();
    GeometryVertexBuffer localC;
    pData->FUN_00a67410(localC);
    NiPoint3 localD;
    unsigned int ItemUpdateArray = MinUnsigned(pData->GetVertexCount(), m_uiVertexCount);
    for (unsigned int i = 0; i < ItemUpdateArray; ++i, localC.AddToA())
    {
        localC.CopyV3(localD);
        localD += m_pkDeltas[i] * weight;
        localC.SetPoint(localD);
    }
}

// @fnv 0x00660a90
void BSFaceGenMorphStatistical::ApplyDifferentialMorph(NiTriBasedGeom* geom, BSFaceGenBaseMorphExtraData* extra,
                                                       float weight)
{
    if (!geom || weight <= 0.0 || weight > 1.0 || !extra->FUN_0084e3a0())
        return;
    NiPoint3* pData = extra->FUN_0084e3a0();
    NiGeometryData* pGeomData = geom->FUN_005495f0();
    GeometryVertexBuffer localC;
    pGeomData->FUN_00a67410(localC);
    NiPoint3 localD;
    unsigned int ItemUpdateArray;
    for (unsigned int i = 0; i < m_uiVertexCount; ++i)
    {
        ItemUpdateArray = m_puiVertexIndices[i];
        localC.FUN_00534570(ItemUpdateArray, localD);
        localD += (pData[m_uiFirstIndex + i] - pData[ItemUpdateArray]) * weight;
        localC.SetVertex(ItemUpdateArray, localD);
    }
}

extern int DAT_01065cb8;

// @fnv 0x00660690
void** __fastcall FUN_00660690(void** p)
{
    *p = &DAT_01065cb8;
    return p;
}

// Returns the smaller of a 16-bit value and a 32-bit value, comparing them as unsigned integers.
// @fnv 0x00660940
unsigned int __cdecl MinUnsigned(unsigned short ausValue, unsigned int auValue)
{
    return ausValue < auValue ? ausValue : auValue;
}

extern "C" void _Deallocate(void*);

struct FUN_006606b0_shell
{
    void __thiscall SetVTable();
    void* __thiscall Destroy(unsigned int flags);
};

// @fnv 0x006606b0
void* __thiscall FUN_006606b0_shell::Destroy(unsigned int flags)
{
    SetVTable();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

void _Deallocate(void*);
struct S006607F0
{
    void FUN_00660820();
    void* DeallocateIfFlagged(unsigned int);
};
// Calls FUN_00660820, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x006607f0
void* S006607F0::DeallocateIfFlagged(unsigned int flags)
{
    FUN_00660820();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00660820 {
extern int _DAT_01065cc4;
void __cdecl _Deallocate(void*);
struct FUN_006606b0_shell
{
    void SetVTable();
};
struct FUN_00660820_shell
{
    void* vtable;
    void* ptr;
    void FUN_00660820();
};
// Sets the vtable to _DAT_01065cc4, deallocates ptr if non-null, then calls SetVTable on this.
// @fnv 0x00660820
void FUN_00660820_shell::FUN_00660820()
{
    vtable = (void*)&_DAT_01065cc4;
    if (ptr != 0)
    {
        void* tmp = ptr;
        _Deallocate(tmp);
    }
    ((FUN_006606b0_shell*)this)->SetVTable();
}
}  // namespace fnv_00660820

void __cdecl _Deallocate(void*);
struct FUN_00660a20_holder
{
    void FUN_00660a50();
    void* DestroyIfFlagged(unsigned int);
};
// Calls FUN_00660a50, then deallocates this if bit 0 of flags is set, and returns this.
// @fnv 0x00660a20
void* FUN_00660a20_holder::DestroyIfFlagged(unsigned int flags)
{
    FUN_00660a50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

namespace fnv_00660a50 {
struct FUN_006606b0_shell
{
    void SetVTable();
};
extern int _DAT_01065cd0;
void __cdecl _Deallocate(void*);
struct FUN_00660a50_shell
{
    int field0;
    void* field4;
    void FUN_00660a50();
};
// Sets field0 to the address of _DAT_01065cd0, frees field4 if non-null, then calls SetVTable on this.
// @fnv 0x00660a50
void FUN_00660a50_shell::FUN_00660a50()
{
    field0 = (int)&_DAT_01065cd0;
    if (field4 != 0)
    {
        void* tmp = field4;
        _Deallocate(tmp);
    }
    ((FUN_006606b0_shell*)this)->SetVTable();
}
}  // namespace fnv_00660a50

extern int DAT_01065cb8;

struct FUN_006606e0_shell
{
    void SetVTable();
};

// @fnv 0x006606e0
void FUN_006606e0_shell::SetVTable()
{
    *reinterpret_cast<int*>(this) = (int)&DAT_01065cb8;
}

struct B65EB90Entry
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    B65EB90Entry& operator=(const B65EB90Entry& kRight);
};

class FUN_0065eb90
{
  public:
    float m_fValue;
    int unk04;
    int unk08;
    int unk0C;
    B65EB90Entry m_akEntries[3];

    FUN_0065eb90& operator=(const FUN_0065eb90& kRight);
};

// Copies m_fValue, unk04, unk08, unk0C and the three m_akEntries from kRight into this object and returns *this.
// @fnv 0x0065eb90
FUN_0065eb90& FUN_0065eb90::operator=(const FUN_0065eb90& kRight)
{
    m_fValue = kRight.m_fValue;
    unk04 = kRight.unk04;
    unk08 = kRight.unk08;
    unk0C = kRight.unk0C;
    for (unsigned int i = 0; i < 3; i++)
        m_akEntries[i] = kRight.m_akEntries[i];
    return *this;
}
