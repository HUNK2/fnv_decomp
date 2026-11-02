// src/havok/common/visualize/shape/hkdisplaycone_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-11-01 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/common/visualize/shape/hkdisplaycone.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/common/visualize/shape/hkdisplaycone.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/shape/hkdisplaycone.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include <xmmintrin.h>
struct __declspec(align(16)) Vertex
{
    __m128 value;
};
struct Edge
{
    int polygon, end, start, adjacent;
};
template <class T> struct DynamicArray
{
    T* data;
    int size;
    unsigned int capacityAndFlags;
    DynamicArray() : data(0), size(0), capacityAndFlags(0x80000000u)
    {}
};
struct GeometryBuffers
{
    DynamicArray<Vertex> vertices;
    DynamicArray<Edge> edges;
    GeometryBuffers() : vertices(), edges()
    {}
    static void* operator new(unsigned int, void* position)
    {
        return position;
    }
};
struct Allocator
{
    virtual void unused();
    virtual void* __thiscall Allocate(unsigned int);
};
struct GlobalContext
{
    int unk00, unk04, unk08, unk0c;
    Allocator* allocator;
};
extern "C" GlobalContext* __cdecl FUN_00c85750();
extern "C" void __cdecl ResizeAudioStream(Allocator*, DynamicArray<Vertex>*, int);
extern "C" void __cdecl FUN_00c908c0(Allocator*, DynamicArray<Edge>*, int, int);
struct ForwardArg
{
    GeometryBuffers* value;
};
struct MeshBuilder;
extern "C" void __fastcall FUN_00de54b0(MeshBuilder*, ForwardArg);
struct MeshBuilder
{
    int unk00;
    int unk04;
    GeometryBuffers* geometry;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    Vertex initialVertex;
    int unk70, unk74, unk78, unk7c;
    volatile int segmentCount;
    void __thiscall InitializeGeometry();
};
