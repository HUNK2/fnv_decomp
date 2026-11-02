
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-29 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct hkpSweptTransformDisplayViewer {
    int FindEntryIndex(int);
    void RemoveWorldData(int);
    void FUN_00d64950(int a);
};
extern "C" void FUN_00d64650();
void __fastcall FUN_00d647f0(void* self);
extern "C" int g_ptr_0x1268fd0;
int __cdecl FUN_00d64970();
struct D63FF0Entry {
    void* m_key;
};
struct D63FF0Container {
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
    D63FF0Entry** m_entries;
    int m_iNumberOfEntries;

    int FindEntryIndex(void* key) const;
};
struct SweptList {
    int unk00;
    void** m_04;
    int m_08;
};
struct SweptArg {
    int unk00;
    int unk04;
    int m_08;
    int unk0C;
    unsigned char m_10;
    unsigned char m_11;
    unsigned char m_12;
    unsigned char m_13;
};
struct SweptVObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(void* p, int g, int z);
};
class SweptTransformItem {
public:
    int unk00;
    int unk04;
    SweptList** m_08;

    void FUN_00d64120(SweptArg* a1);
};
extern "C" int g_ptr_0x1268fd0;
struct FUN_00d647b0_Pool
{
    int unk00;     int unk04;     int unk08;     int unk0C;     int unk10;     int unk14;     int unk18;     int unk1C;
    int unk20;     int unk24;     int unk28;     int unk2C;     int unk30;     int unk34;     int unk38;     int unk3C;
    int unk40;     int unk44;     int unk48;     int unk4C;     int unk50;     int unk54;     int unk58;     int unk5C;
    int unk60;     int unk64;     int unk68;
    int* m_items;
    int m_uiItemCount;
};
struct FUN_00d647b0_Listener
{
    int unk00;
};
typedef void (__thiscall* FUN_00d647b0_Handler)(FUN_00d647b0_Listener* self, int item);
struct FUN_00d647b0_cls
{
    int unk00;     int unk04;     int unk08;     int unk0C;     int unk10;     int unk14;     int unk18;
    FUN_00d647b0_Pool* m_kNodePool;

    void NotifyItems();
};
struct SweptHeap
{
	virtual ~SweptHeap();
	virtual void* AllocateMemoryBlock(int n);
	virtual void ReleaseBlock(void* p, int n);
	virtual void* AllocateBufferWithSize(int& n);
	virtual void ReturnMemory(void* p, int n);
};
struct SweptRouter
{
	int unk0;
	int unk4;
	int unk8;
	int unkC;
	SweptHeap* m_pStreamAllocator;
	SweptHeap& heap() { return *m_pStreamAllocator; }
};
__declspec(nothrow) SweptRouter& __cdecl FUN_00c85750();
template <int SIZE> __forceinline void SweptMemCpyOne(void* dst, const void* src) { for (int i = 0; i < SIZE / 4; i++) ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i]; }
template <typename T>
struct SweptArray
{
	T* m_data;
	int m_iElementCount;
	int m_iCapacityState;

	__forceinline ~SweptArray() throw() { _clearAndDeallocate(FUN_00c85750().heap()); }

	__forceinline void clear() throw() { m_iElementCount = 0; }
	__forceinline void _clearAndDeallocate(SweptHeap& alloc) throw()
	{
		clear();
		if ((m_iCapacityState & 0x80000000) == 0)
			alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
		m_data = 0;
		m_iCapacityState = 0x80000000;
	}
	T& operator[](int i) { return m_data[i]; }
	__forceinline void removeAt(int index)
	{
		m_iElementCount--;
		if (m_iElementCount != index)
			SweptMemCpyOne<sizeof(T)>(m_data + index, m_data + m_iElementCount);
	}
};
struct SweptEntityListener { virtual void EntityAddedCallback(void* entity); };
struct SweptPostSimListener { virtual void postSimulationCallback(void* world); };
struct SweptWorld
{
	void AddEntityListener(SweptEntityListener* listener);
	void AddPostSimulationListener(SweptPostSimListener* listener);
};
struct SweptWorldData
{
	SweptWorld* m_pOwningWorld;
	SweptArray<unsigned long> m_kEntityIDs;

	static void operator delete(void* p, unsigned int nbytes) { FUN_00c85750().heap().ReleaseBlock(p, nbytes); }
};
struct SweptViewerBase
{
	virtual ~SweptViewerBase();
	int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24;
};
struct SweptViewer : SweptViewerBase, SweptEntityListener, SweptPostSimListener
{
	SweptArray<SweptWorldData*> m_kWorldDataList;

	void ClearSweptEntry(int index);
	void RemoveWorldData(int index);
};
#include <xmmintrin.h>
struct __declspec(align(16)) D64020Vector4 {
    float m_f[4];
};
struct __declspec(align(16)) D64020Rotation {
    D64020Vector4 m_kColumn0;
    D64020Vector4 m_kColumn1;
    D64020Vector4 m_kColumn2;

    void set(const D64020Vector4& quat);
};
struct __declspec(align(16)) D64020Transform {
    D64020Rotation m_rotation;
    D64020Vector4 m_vTranslation;
};
inline __m128 D64020RotateDir(const D64020Rotation& m, const D64020Vector4& v)
{
    const __m128 b = *(const __m128*)v.m_f;
    const __m128 b0 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(0, 0, 0, 0));
    const __m128 r0 = _mm_mul_ps(*(const __m128*)m.m_kColumn0.m_f, b0);
    const __m128 b1 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(1, 1, 1, 1));
    const __m128 r1 = _mm_mul_ps(*(const __m128*)m.m_kColumn1.m_f, b1);
    const __m128 b2 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(2, 2, 2, 2));
    const __m128 r2 = _mm_mul_ps(*(const __m128*)m.m_kColumn2.m_f, b2);
    return _mm_add_ps(_mm_add_ps(r0, r1), r2);
}
extern int g_D64020Color;
struct D64020DisplayHandler {
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void displayFrame(const D64020Transform& transform, unsigned long id, int tag);
};
struct D64020Constraint {
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    D64020Vector4 m_kPivotA;
    D64020Vector4 m_kPivotB;
    D64020Vector4 m_kRotationA;
    D64020Vector4 m_kRotationB;
    D64020Vector4 m_localPivot;
};
class D64020Primary {
public:
    virtual void unk00();

    D64020DisplayHandler* m_pDisplayHandler;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};
class D64020Secondary {
public:
    virtual void DisplayConstraintPivots(D64020Constraint* constraint);
};
class D64020Viewer : public D64020Primary, public D64020Secondary {
public:
    virtual void DisplayConstraintPivots(D64020Constraint* constraint);
};
// sub ecx,8; jmp FUN_00d649c0 == MSVC adjustor thunk for the secondary base's override.
struct PrimaryBase
{
    virtual void FUN_00d64980();
    int unk04;
};
struct SecondaryBase
{
    virtual void FUN_00d64980();
};
struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d64980
    virtual void FUN_00d64980();
};
Derived::Derived()
{
}
// FUN_00d64990 : MSVC this-adjusting thunk  (sub ecx, 0x28 ; jmp <impl>)
//
// Two bases declare the same virtual, so the derived class overrides one
// function for both of them and the compiler emits one adjustor thunk per
// secondary base.  The first base is padded to 40 bytes so the second
// base lands at +0x28.  The override is DECLARED ONLY, so this thunk
// is the single defined function symbol carrying the name FUN_00d64990; a defined
// key function makes the vftable that references the thunk be emitted here.
struct A1_00d64990 {
    A1_00d64990();
    virtual void FUN_00d64990();
    char pad[0x24];
};
struct A2_00d64990 {
    A2_00d64990();
// @fnv 0x00d64990
    virtual void FUN_00d64990();
};
struct Own_00d64990 : A1_00d64990, A2_00d64990 {
    Own_00d64990();
    virtual void key_fn();     // key function - defined, so the vftable is emitted
    void FUN_00d64990();             // the shared override - declared only
};
Own_00d64990::Own_00d64990() { }
void Own_00d64990::key_fn() { }
Own_00d64990* make_00d64990() { static Own_00d64990 o; return &o; }
struct D649A0Primary {
    virtual void vfunc00();
    virtual void FUN_00d649a0();

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
};
struct D649A0Secondary {
    virtual void FUN_00d649a0();
};
struct D649A0Object : D649A0Primary, D649A0Secondary {
    D649A0Object();

// @fnv 0x00d649a0
    virtual void FUN_00d649a0();
};
D649A0Object::D649A0Object()
{
}
// FUN_00d649b0 : MSVC this-adjusting thunk  (sub ecx, 0x20 ; jmp <impl>)
//
// Two bases declare the same virtual, so the derived class overrides one
// function for both of them and the compiler emits one adjustor thunk per
// secondary base.  The first base is padded to 32 bytes so the second
// base lands at +0x20.  The override is DECLARED ONLY, so this thunk
// is the single defined function symbol carrying the name FUN_00d649b0; a defined
// key function makes the vftable that references the thunk be emitted here.
struct A1_00d649b0 {
    A1_00d649b0();
    virtual void FUN_00d649b0();
    char pad[0x1c];
};
struct A2_00d649b0 {
    A2_00d649b0();
// @fnv 0x00d649b0
    virtual void FUN_00d649b0();
};
struct Own_00d649b0 : A1_00d649b0, A2_00d649b0 {
    Own_00d649b0();
    virtual void key_fn();     // key function - defined, so the vftable is emitted
    void FUN_00d649b0();             // the shared override - declared only
};
Own_00d649b0::Own_00d649b0() { }
void Own_00d649b0::key_fn() { }
Own_00d649b0* make_00d649b0() { static Own_00d649b0 o; return &o; }
struct S_00d649c0_Heap {
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct S_00d649c0_Router {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00d649c0_Heap* m_pStreamAllocator;
    __forceinline S_00d649c0_Heap& heap() { return *m_pStreamAllocator; }
};
struct FUN_00d649c0 {
    virtual ~FUN_00d649c0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00d649c0();
    static void operator delete(void* p, unsigned int)
    {
        FUN_00d649c0* b = static_cast<FUN_00d649c0*>(p);
        FUN_00c85750().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

struct Alloc { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void release(void* p, int n); };
struct BSAudio { int unk00; int unk04; int unk08; int unk0c; Alloc* unk10; };

void __cdecl ResizeAudioStream(void *,void *,int);
struct FUN_008cd6a0_Class { void FUN_00cb2d90(void *); };
struct ErrBuf { void FUN_00cb1600(char* b, int n); void FUN_00cc01c0(const char* s); void FUN_00cc00e0(); int unk00; int unk04; int unk08; };
struct TmpA { void FUN_00ddfb70(); int unk00; int unk04; };
struct TmpB { void FUN_00ddfb80(TmpA* a); void FUN_00de0f90(int a, void* b); int unk00; int unk04; int unk08; int unk0c; int unk10; };
struct Reporter { virtual void v0(); virtual void v1(); virtual void v2(); virtual void report(int a, int b, const char* msg, const char* file, int line); };
extern Reporter* DAT_01268360;
extern int DAT_01268fd0; extern int DAT_01268fd4; extern int DAT_01268fd8;
struct Shape { virtual void release(int f); int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; };
struct Disp { virtual void v0(); virtual void add(void* a, void* b, void* c, int d, int e); virtual void v2(); virtual void tag(int a, void* b, int c); };
__declspec(align(16)) struct Mat { float a0,a1,a2,a3,b0,b1,b2,b3,c0,c1,c2,c3,d0,d1,d2,d3; };
__declspec(align(16)) struct V4 { float x; float y; float z; float w; };
struct Arr { int* data; int size; int cap; };
struct Entry { int unk00; Arr unk04; };
struct Arg {
    int unk00; int unk04; int unk08; int unk0c;
    union { int unk10; struct { unsigned char byte10, unk11, unk12, unk13; }; };
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
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    unsigned char motionType, unkE9, unkEA, unkEB;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    __m128 position0, position1, rotation0, rotation1, center;
};

struct OwnerBase {
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    Disp* display;
    int unk1c;
    int unk20;
    int unk24;
};
struct Self {
    int unk00; int unk04; Entry** unk08;
    void FUN_00d642c0(Arg* a);
};

struct Owner : OwnerBase, Self {};
struct DisplayPrefix { Disp* display; int unk1c, unk20, unk24; };
// @fnv 0x00d642c0
void Self::FUN_00d642c0(Arg* a)
{
     
    if (a->unk10 == 0) return;
     int idx = ((hkpSweptTransformDisplayViewer*)((char*)this - sizeof(OwnerBase)))->FindEntryIndex(a->unk08);
    if (idx < 0) return;
    SweptArray<Shape*> list;
    Entry* e; e = unk08[idx];
    list.m_data = 0; list.m_iElementCount = 0; list.m_iCapacityState = 0x80000000; TmpA ta; ta.FUN_00ddfb70();
    TmpB tb; tb.FUN_00ddfb80(&ta);
    tb.FUN_00de0f90(a->unk10, &list);
    for (int j = list.m_iElementCount - 1; j >= 0; j--) { Shape* s = (Shape*)list.m_data[j];
        if (s->unk50 == 6 && 0 == s->unk08) {
            char buf[512];
            ErrBuf eb;
            
            eb.FUN_00cb1600(buf, 0x200);
            eb.FUN_00cc01c0("Unable to build display geometry from hkpShape geometry data");
            DAT_01268360->report(0, -1, (const char*)&buf, ".\\VisualDebugger\\Viewer\\Dynamics\\hkpSweptTransformDisplayViewer.cpp", 0xa8);
            eb.FUN_00cc00e0();
            list.removeAt(j);
        } }
    if (0 < list.m_iElementCount && 5 != a->motionType) {
        unsigned char* id1 = (unsigned char*)&a->unk11;
        Arr* ids = &e->unk04;
        SweptRouter* b = &FUN_00c85750();
        if (ids->size == (ids->cap & 0x3fffffff)) ResizeAudioStream(b->m_pStreamAllocator, ids, 4);
        int* slot1 = ids->data + ids->size;
        for (int k = 0; k < 1; ++k) slot1[k] = (int)id1; ++ids->size;
        Mat m1; Mat m2;
        ((FUN_008cd6a0_Class*)&m1)->FUN_00cb2d90(&a->rotation0);
        __m128 v = a->center;
        
        __m128 p1 = _mm_sub_ps(a->position0,
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_load_ps(&m1.b0), _mm_shuffle_ps(v, v, 0x55)), _mm_mul_ps(_mm_load_ps(&m1.a0), _mm_shuffle_ps(v, v, 0))), _mm_mul_ps(_mm_load_ps(&m1.c0), _mm_shuffle_ps(v, v, 0xaa))));
        _mm_store_ps(&m1.d0, p1);
        ((FUN_008cd6a0_Class*)&m2)->FUN_00cb2d90(&a->rotation1);
        __m128 w = a->center;
        __m128 p2r = _mm_sub_ps(a->position1,
            _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(w, w, 0xaa), _mm_load_ps(&m2.c0)), _mm_add_ps(_mm_mul_ps(_mm_load_ps(&m2.b0), _mm_shuffle_ps(w, w, 0x55)), _mm_mul_ps(_mm_load_ps(&m2.a0), _mm_shuffle_ps(w, w, 0)))));
                _mm_store_ps(&m2.d0, p2r);
        Disp* d = ((DisplayPrefix*)((char*)this - sizeof(DisplayPrefix)))->display; d->add(&list, &m1, id1, DAT_01268fd0, 0);
        d = ((DisplayPrefix*)((char*)this - sizeof(DisplayPrefix)))->display;
        d->tag(DAT_01268fd8, id1, DAT_01268fd0);
        unsigned char* id2 = &a->unk12;
        b = &FUN_00c85750();
        if (ids->size == (ids->cap & 0x3fffffff)) ResizeAudioStream(b->m_pStreamAllocator, ids, 4);
        int* slot2 = ids->data + ids->size;
        for (int k = 0; k < 1; ++k) slot2[k] = (int)id2; ++ids->size;
        d = ((DisplayPrefix*)((char*)this - sizeof(DisplayPrefix)))->display;
        d->add(&list, &m2, id2, DAT_01268fd0, 0);
        d = ((DisplayPrefix*)((char*)this - sizeof(DisplayPrefix)))->display;
        d->tag(DAT_01268fd4, id2, DAT_01268fd0);
    }
    for (int i = 0; i < list.m_iElementCount; i++) { Shape* s = (Shape*)list.m_data[i];
        if (0 != s) s->release(1); }
}

#include <windows.h>
extern DWORD DAT_0126835c;
extern int DAT_01268fd0;

struct S_00d63e40_TimerCommand {
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00d63e40_MonitorStream {
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00d63e40_Timer(const char* name)
{
    S_00d63e40_MonitorStream* s = (S_00d63e40_MonitorStream*)TlsGetValue(DAT_0126835c);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00d63e40_TimerCommand* h = (S_00d63e40_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        unsigned int t;
        __asm {
            rdtsc
            mov dword ptr[t], eax
        }
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct __declspec(align(16)) S_00d63e40_V4 {
    float x, y, z, w;
    __m128& q() { return *(__m128*)this; }
    const __m128& q() const { return *(const __m128*)this; }
};

struct S_00d63e40_Mat3 {
    S_00d63e40_V4 c0;
    S_00d63e40_V4 c1;
    S_00d63e40_V4 c2;
    S_00d63e40_V4 t;
    void FUN_00cb2d90(const S_00d63e40_V4* q);
};

struct S_00d63e40_Handler {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void display(const S_00d63e40_Mat3* xf, const char* id, int tag);
};

struct __declspec(align(16)) S_00d63e40_Entity {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    char unk10;
    char id0;
    char id1;
    char unk13;
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
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    S_00d63e40_V4 pos0;
    S_00d63e40_V4 pos1;
    S_00d63e40_V4 rot0;
    S_00d63e40_V4 rot1;
    S_00d63e40_V4 com;

};

struct S_00d63e40_Array {
    S_00d63e40_Entity** m_data;
    int m_iElementCount;
};

struct S_00d63e40_Island {
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
    S_00d63e40_Array entities;

};
struct S_00d63e40_World {
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
    S_00d63e40_Island** islands;
    int numIslands;

};

struct S_00d63e40_WorldPad {
    S_00d63e40_World* w;
    S_00d63e40_World* val() const { return w; }
};

struct S_00d63e40_Base0 {
    virtual void b0();
    virtual void b1();
    int unk04;
    int unk08;
    S_00d63e40_Handler* handler;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};

struct S_00d63e40_Listener {
    virtual void l0();
    virtual void FUN_00d63e40(S_00d63e40_WorldPad world);
};

struct S_00d63e40_S : S_00d63e40_Base0, S_00d63e40_Listener {
    virtual void l0();
    virtual void FUN_00d63e40(S_00d63e40_WorldPad world);
};

// @fnv 0x00d63e40
void S_00d63e40_S::FUN_00d63e40(S_00d63e40_WorldPad world)
{
    S_00d63e40_Timer("TthkpSweptTransformDisplayViewer");
    for (int i = 0; i < world.val()->numIslands; i++)
    {
        S_00d63e40_Array& arr = world.val()->islands[i]->entities;
        for (int j = 0; j < arr.m_iElementCount; j++)
        {
            S_00d63e40_Entity* e = arr.m_data[j];
            S_00d63e40_Mat3 m;
            m.FUN_00cb2d90(&e->rot0);
            __m128 c = e->com.q();
            __m128 r = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(c, c, 0x55), m.c1.q()), _mm_mul_ps(_mm_shuffle_ps(c, c, 0), m.c0.q())), _mm_mul_ps(_mm_shuffle_ps(c, c, 0xaa), m.c2.q()));
            m.t.q() = _mm_sub_ps(e->pos0.q(), r);
            handler->display(&m, &e->id0, DAT_01268fd0);
            m.FUN_00cb2d90(&e->rot1);
            c = e->com.q();
            r = _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(c, c, 0x55), m.c1.q()), _mm_mul_ps(_mm_shuffle_ps(c, c, 0), m.c0.q())), _mm_mul_ps(_mm_shuffle_ps(c, c, 0xaa), m.c2.q()));
            m.t.q() = _mm_sub_ps(e->pos1.q(), r);
            handler->display(&m, &e->id1, DAT_01268fd0);
        }
    }
    S_00d63e40_Timer("Et");
}
