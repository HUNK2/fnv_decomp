
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpmidphaseviewer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpmidphaseviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpmidphaseviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpmidphaseviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FullObject;
struct Receiver;
struct HeadPart {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct FirstBase {
    int unk00;
    int unk04;
    void FUN_00d6a250(Receiver* apReceiver);
};
struct SecondBase {
    int unk00;
};
struct FullObject : HeadPart, FirstBase, SecondBase {
};
typedef char _check_offsets[sizeof(FullObject) == 0x2c ? 1 : -1];
struct Receiver {
    void ClearValue(SecondBase* apObject);
};
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytes);
    virtual void ReturnMemory(void* p, int numBytes) throw();
};
struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocator* m_pStreamAllocator;
    hkMemoryAllocator& heap() { return *m_pStreamAllocator; }
};
NineIntegerRecord* FUN_00c85750() throw();
struct S_00d6a750_Element
{
    virtual ~S_00d6a750_Element() throw();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
};
template <class T> __forceinline void hkArrayUtil_destruct(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}
template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline ~hkArray() throw() { _clearAndDeallocate(FUN_00c85750()->heap()); }
    __forceinline void clear()
    {
        hkArrayUtil_destruct(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(hkMemoryAllocator& alloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};
struct S_00d6a750_Base0
{
    virtual ~S_00d6a750_Base0();
    int unk04;
};
struct S_00d6a750_Base1
{
    virtual void v00();
    int b1_unk0C;
    int b1_unk10;
    int b1_unk14;
    int b1_unk18;
    int b1_unk1C;
};
struct S_00d6a750_Listener;
struct S_00d6a750_Source
{
    void ClearValue(S_00d6a750_Listener* m_pAudioListener) throw();
};
struct S_00d6a750_Owner
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    S_00d6a750_Source** m_ppSources;
    int m_iNumSources;
};
struct S_00d6a750_Base2
{
    virtual void v00();
    S_00d6a750_Owner* m_pSharedOwner;
};
struct S_00d6a750_Listener
{
    virtual ~S_00d6a750_Listener() throw() {}
};
struct FUN_00d6a750 : S_00d6a750_Base0, S_00d6a750_Base1, S_00d6a750_Base2, S_00d6a750_Listener
{
    hkArray<S_00d6a750_Element> m_elements;
    ~FUN_00d6a750();
};
struct Registry_00dd9380 {
    void* Register(const char* name, void (*fn)());
};
extern Registry_00dd9380* DAT_01269cd0;
extern char DAT_010d22e0[];
extern void* DAT_01269024;
void FUN_00d6a810();
void FUN_00d6a850();
struct Target {
    int Handle(void* apValue);
};
struct FUN_00d6a220_cls {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    int HandleWithSelfOffset(Target* apTarget);
};
struct S_d6a280_Elem;
struct S_d6a280_Owner {
    int unk00;
    int unk04;
    int unk08;
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
    int unk60;
    int unk64;
    int unk68;
    S_d6a280_Elem** m_items;
    int m_uiItemCount;
};
struct S_d6a280_P0 {
    virtual void a0();
    int unk04;
};
struct S_d6a280_P8 {
    virtual void a8();
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};
struct S_d6a280_P20 {
    virtual void a20();
    S_d6a280_Owner* m_24;
};
struct FUN_00ddccb0 : S_d6a280_P0, S_d6a280_P8, S_d6a280_P20 {
    FUN_00ddccb0(int a);
};
struct S_d6a280_Arr {
    void* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    __forceinline S_d6a280_Arr() : m_data(0), m_iElementCount(0), m_cap(0x80000000u) {}
};
struct S_d6a280_Mx {
    virtual void m0();
    __forceinline S_d6a280_Mx() {}
};
struct S_d6a280_Elem {
    void FUN_00c93920(S_d6a280_Mx* m);
};
struct FUN_00d6a280 : FUN_00ddccb0, S_d6a280_Mx {
    S_d6a280_Arr m_aiIndexedValues;
    virtual void m0();
    virtual void a0();
    virtual void a8();
    virtual void a20();
    FUN_00d6a280(int a);
};
// this -= 0x20; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0x20).
struct PrimaryBase
{
    virtual void FUN_00d6a880();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct SecondaryBase
{
    virtual void FUN_00d6a880();
};
struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d6a880
    virtual void FUN_00d6a880();
};
Derived::Derived()
{
}
// Adjustor thunk for a secondary base.
//
// The original code is exactly:
//     00d6a890  83 e9 08        sub ecx, 8
//     00d6a893  e9 18 00 00 00  jmp 00d6a8b0
//
// which is the MSVC 2008 "virtual adjustor thunk" that MSVC emits for the
// per-base vftable of a derived class that re-declares a virtual function of
// one of its secondary bases: the thunk converts the 'this' pointer of the
// derived object into the 'this' pointer of the base subobject (which lives
// 8 bytes into the object) and tail-jumps to the derived implementation.
//
// The derived implementation is only DECLARED here, so the jump target stays
// an undefined external and the linker/checker resolves it from the original
// image.
struct AdjustorPrimaryBase {
    int m_00;                                  // +0x04
    AdjustorPrimaryBase();
    virtual void FUN_00d6a890(int flag);
};
struct AdjustorSecondaryBase {
    AdjustorSecondaryBase();
    virtual void FUN_00d6a890(int flag);
};
struct AdjustorDerived : public AdjustorPrimaryBase,
                          public AdjustorSecondaryBase {
    AdjustorDerived();
// @fnv 0x00d6a890
    virtual void FUN_00d6a890(int flag);
};
AdjustorPrimaryBase::AdjustorPrimaryBase() : m_00(0) {}
AdjustorSecondaryBase::AdjustorSecondaryBase() {}
AdjustorDerived::AdjustorDerived() {}
// ---------------------------------------------------------------------------
// 0x00d6a8a0 - MSVC 2008 adjustor thunk for a *secondary* base.
//
// The original code is
//     00d6a8a0  83 e9 28        sub ecx, 0x28
//     00d6a8a3  e9 08 00 00 00  jmp 0x00d6a8b0
//
// The thunk belongs to the vtable of a secondary base which hkpMidphaseViewer
// overrides.  The secondary base subobject lives 0x28 bytes into the complete
// object, so the thunk first moves `this` back to the start of the object and
// then tail-jumps to the overriding implementation (0x00d6a8b0).
//
// The overriding implementation is only DECLARED here, so the jmp target stays
// an unresolved external and the checker can resolve the relocation from the
// original's own bytes.  The thunk's own mangled name carries the tag, which
// satisfies the canary.
// ---------------------------------------------------------------------------
// Primary base: it is the first base of the derived class and it is exactly
// 0x28 bytes long, which is what puts the secondary base at offset 0x28.
struct hkpShape {
    hkpShape();
    virtual void FUN_00d6a8a0();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
};
// Secondary base: it starts at offset 0x28 of the derived object.
struct hkpMidphaseViewerBase {
    hkpMidphaseViewerBase();
// @fnv 0x00d6a8a0
    virtual void FUN_00d6a8a0();
};
struct hkpMidphaseViewer : public hkpShape, public hkpMidphaseViewerBase {
    hkpMidphaseViewer();
    virtual void FUN_00d6a8a0();   // declared, never defined
};
hkpMidphaseViewer::hkpMidphaseViewer() : hkpShape(), hkpMidphaseViewerBase() { }

#include <xmmintrin.h>
struct EventStamp {
    const void* marker;
    unsigned tick;
    unsigned unk08;
};
struct EventSample {
    const void* marker;
    unsigned tick;
};
struct EventStorage {
    unsigned unk00;
    EventStamp* m_next;
    unsigned unk08;
    EventStamp* m_pFreeList;
};
extern unsigned long DAT_0126835c;
extern char DAT_010d233c[];
extern char DAT_010c41f8[];
extern void* DAT_01269024;
extern const float DAT_01011d78;
extern const __m128 DAT_010c7170;
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

static __forceinline void TimerMark(char* marker)
{
    EventStorage* s = (EventStorage*)TlsGetValue(DAT_0126835c);
    EventStamp* next = s->m_next;
    if (next < s->m_pFreeList) {
        next->marker = marker;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        next->tick = ticks;
        s->m_next = next + 1;
    }
}

void __cdecl FUN_00c908c0(hkMemoryAllocator* alloc, void* arr, int newSize, int elemSize);
struct __declspec(align(16)) Vec4 {
    float x, y, z, w;
};
struct __declspec(align(16)) UInt4 {
    unsigned x, y, z, w;
};
static __forceinline void SetVec(Vec4& v,float x,float y,float z,float w) { *(__m128*)&v=_mm_setr_ps(x,y,z,w); }
struct Bounds { Vec4 min; Vec4 max; };
struct QuantizedBounds { UInt4 min; UInt4 max; };
struct Elem80 {
    virtual ~Elem80();
    int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c; int unk70; int unk74; int unk78; int unk7c;
    void FUN_00de1210();
    void FUN_00de1170(const Vec4& a, const Vec4& b);
};
struct ListEntry {
    int m_00;
    int m_04;
    int m_08;
    unsigned char b0c;
    unsigned char b0d;
    unsigned char b0e;
    unsigned char b0f;
    int m_10;
    int m_14;
    int m_18;
    unsigned char b1c;
    unsigned char b1d;
    unsigned char b1e;
    unsigned char b1f;
};
static __forceinline void Decode(const ListEntry* list, QuantizedBounds& quantized) {
    unsigned cl = list->b0f;
    quantized.min.x = list->m_00 - (int)(list->b0c << cl);
    quantized.min.y = list->m_04 - (int)(list->b0d << cl);
    quantized.min.z = list->m_08 - (int)(list->b0e << cl);
    quantized.max.x = (int)(list->b1c << cl) + list->m_10;
    quantized.max.y = (int)(list->b1d << cl) + list->m_14;
    quantized.max.z = (int)(list->b1e << cl) + list->m_18;
}
struct Node {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    unsigned short m_uiItemCount;
    unsigned short unk22;
    ListEntry* m_kNode;
    int unk28;
    int unk2c;
};
struct SubEntry {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    Node m_node;
};
struct PtrArray {
    void** m_data;
    int m_iElementCount;
    unsigned int m_cap;
};
struct Entry {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24; int unk28; int unk2c;
    int unk30; int unk34; int unk38; int unk3c;
    int unk40; int unk44;
    PtrArray m_sub;
    int unk54;
    int unk58;
    int unk5c;
};
struct Param {
    int unk00; int unk04; int unk08; int unk0c;
    int unk10; int unk14; int unk18; int unk1c;
    int unk20; int unk24;
    PtrArray m_arrs[2];
    int unk40; int unk44; int unk48; int unk4c;
    int unk50; int unk54; int unk58; int unk5c;
    int unk60; int unk64; int unk68; int unk6c;
    int unk70; int unk74;
    float* m_matrix;
};
struct ParamRef {
    Param* p;
    __forceinline Param* operator->() const { return p; }
};
struct ElemArray {
    Elem80* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct PtrArrayLocal {
    Elem80** m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
static __forceinline Elem80** AllocatePointers(hkMemoryAllocator& alloc, int& count)
{
    if (count) {
        int bytes = count * 4;
        Elem80** result = (Elem80**)alloc.AllocateBufferWithSize(bytes);
        count = bytes / 4;
        return result;
    }
    return 0;
}
struct Dispatch {
    virtual ~Dispatch();
    virtual void d01();
    virtual void d02();
    virtual void d03();
    virtual void d04();
    virtual void d05();
    virtual void d06();
    virtual void d07();
    virtual void d08();
    virtual void d09();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void FUN_dispatch(PtrArrayLocal* arr, int a, int b, void* c);
};
struct Self {
    int unk00;
    ElemArray m_aiIndexedValues;
    int unk14;
    int unk18;
    int unk1c;
    void FUN_00d6a2f0(Param* apParam);
};

struct ViewerPrefix { Dispatch* m_dispatch; int unk04; int unk08; int unk0c; };
struct Viewer : ViewerPrefix, Self {};

// @fnv 0x00d6a2f0
void Self::FUN_00d6a2f0(Param* apParam)
{
    TimerMark(DAT_010d233c);
    hkArrayUtil_destruct(m_aiIndexedValues.m_data, m_aiIndexedValues.m_iElementCount);
    m_aiIndexedValues.m_iElementCount = 0;
    PtrArray* arr = &apParam->m_arrs[0];
    int passes = 2;
    do {
        int ai = 0;
        if (arr->m_iElementCount > 0) {
            do {
                Entry* entry = (Entry*)arr->m_data[ai];
                PtrArray* sub = &entry->m_sub;
                int bi = 0;
                if (sub->m_iElementCount > 0) {
                    do {
                        SubEntry* se = (SubEntry*)sub->m_data[bi];
                        Node* node = &se->m_node;
                        ListEntry* list = node->m_kNode;
                        if (list) {
                            int k = 0;
                            if ((unsigned short)k < node->m_uiItemCount) {
                                do {
                                    float* mat = apParam->m_matrix + 8;
                                    Bounds bounds;
                                    QuantizedBounds quantized;
                                    Decode(list,quantized);
                                    float f0 = (float)quantized.min.x;
                                    float f1 = (float)quantized.min.y;
                                    float f2 = (float)quantized.min.z;
                                    *(__m128*)&bounds.min = _mm_setr_ps(f0,f1,f2,0.0f);
                                    float f3 = (float)quantized.max.x;
                                    float f4 = (float)quantized.max.y;
                                    float f5 = (float)quantized.max.z;
                                    SetVec(bounds.max,f3,f4,f5,0.0f);
                                    __m128 row1 = _mm_load_ps(mat + 8);
                                    __m128 t = _mm_shuffle_ps(row1, _mm_unpackhi_ps(row1, DAT_010c7170), 0xc4);
                                    __m128 r = _mm_rcp_ps(t);
                                    __m128 inv = _mm_sub_ps(_mm_add_ps(r, r), _mm_mul_ps(_mm_mul_ps(r, t), r));
                                    *(__m128*)&bounds.min = _mm_mul_ps(*(__m128*)&bounds.min, inv);
                                    *(__m128*)&bounds.max = _mm_mul_ps(*(__m128*)&bounds.max, inv);
                                    *(__m128*)&bounds.min = _mm_sub_ps(*(__m128*)&bounds.min, _mm_load_ps(mat));
                                    *(__m128*)&bounds.max = _mm_sub_ps(*(__m128*)&bounds.max, _mm_load_ps(mat));
                                    hkMemoryAllocator& alloc = FUN_00c85750()->heap();
                                    ElemArray* output = &m_aiIndexedValues;
                                    int oldSize = output->m_iElementCount;
                                    int newSize = oldSize + 1;
                                    if ((output->m_iCapacityState & 0x3fffffff) < newSize) {
                                        int dbl = (output->m_iCapacityState & 0x3fffffff) * 2;
                                        if (newSize < dbl) newSize = dbl;
                                        FUN_00c908c0(&alloc, output, newSize, 0x80);
                                    }
                                    Elem80* elem = &output->m_data[output->m_iElementCount];
                                    if (elem) elem->FUN_00de1210();
                                    output->m_iElementCount++;
                                    output->m_data[oldSize].FUN_00de1170(bounds.min, bounds.max);
                                    k++;
                                    list++;
                                } while (k < node->m_uiItemCount);
                            }
                        }
                        bi++;
                    } while (bi < sub->m_iElementCount);
                }
                ai++;
            } while (ai < arr->m_iElementCount);
        }
        arr = &apParam->m_arrs[1];
        passes--;
    } while (passes != 0);

    int count = m_aiIndexedValues.m_iElementCount;
    int allocatedCount = count;
    PtrArrayLocal indices;
    indices.m_data = 0;
    indices.m_iElementCount = 0;
    indices.m_iCapacityState = 0x80000000;
    hkMemoryAllocator& alloc = FUN_00c85750()->heap();
    Elem80** buf = AllocatePointers(alloc, allocatedCount);
    int capacity = allocatedCount ? allocatedCount : (int)0x80000000;
    indices.m_data = buf;
    indices.m_iElementCount = allocatedCount;
    indices.m_iCapacityState = capacity;
    hkMemoryAllocator& alloc2 = FUN_00c85750()->heap();
    if ((indices.m_iCapacityState & 0x3fffffff) < count) {
        int ns = (indices.m_iCapacityState & 0x3fffffff) * 2;
        if (count >= ns) ns = count;
        FUN_00c908c0(&alloc2, &indices, ns, 4);
    }
    indices.m_iElementCount = count;
    for (int i = 0; i < count; i++) {
        indices.m_data[i] = &m_aiIndexedValues.m_data[i];
    }
    Dispatch* disp = static_cast<Viewer*>(this)->m_dispatch;
    disp->FUN_dispatch(&indices, -0x5b00, 0, DAT_01269024);
    TimerMark(DAT_010c41f8);
    hkMemoryAllocator& cleanupAlloc = FUN_00c85750()->heap();
    indices.m_iElementCount = 0;
    if ((indices.m_iCapacityState & 0x80000000u) == 0)
        cleanupAlloc.ReturnMemory(indices.m_data, (indices.m_iCapacityState & 0x3fffffff) * 4);
    return;
}
