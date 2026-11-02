// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpcontactpointviewer_rtmfull_variant.cpp - variant unit created 2026-11-01 by rtm_route.py: community reworks of src/havok/physics/utilities/visualdebugger/viewer/collide/hkpcontactpointviewer.cpp that match byte for byte only
// with VC9 RTM (cl 15.00.21022.08, the compiler the game was built with) and /MT /O2 /GS /EHsc /Gy (unit lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton.


// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpcontactpointviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpcontactpointviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Prefix32 { int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; };
struct Context { void FUN_00c93920(void* value); };
struct Secondary {
 int unk00; int unk04; int child;
 void FUN_00de2950(Context* context);
};
struct Owner : Prefix32, Secondary {};
// Computes the address of the child member (or null if the owner is null) and passes it to context->FUN_00c93920.
// @fnv 0x00de2950
void Secondary::FUN_00de2950(Context* context) {
 Owner* owner = reinterpret_cast<Owner*>(reinterpret_cast<char*>(this) - sizeof(Prefix32));
 void* value;
 if (owner)
  value = &child;
 else
  value = 0;
 context->FUN_00c93920(value);
}

struct S_00de2980_B2 { virtual void f2(); };
struct S_00de2980_World { int ClearValue(S_00de2980_B2* p); };
struct S_00de2980_B0 { virtual void f0(); int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C; };
struct S_00de2980_B1 { virtual void FUN_00de2980(S_00de2980_World* w); int unk04; };
struct S_00de2980_D : S_00de2980_B0, S_00de2980_B1, S_00de2980_B2 {
    virtual void FUN_00de2980(S_00de2980_World* w);
};

// @fnv 0x00de2980
void S_00de2980_D::FUN_00de2980(S_00de2980_World* pWorld)
{
    pWorld->ClearValue(this);
}

struct DE29B0PartA {
    virtual void vfuncA();
    int unk04;
};

struct DE29B0PartB {
    virtual void vfuncB();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct DE29B0PartC {
    virtual void vfuncC();
    int unk04;
};

struct DE29B0Base : DE29B0PartA, DE29B0PartB, DE29B0PartC {
    DE29B0Base(void* owner);
};

struct DE29B0Listener {
    virtual void vfuncD();
};

struct FUN_00de29b0 : DE29B0Base, DE29B0Listener {
    float m_uiFilterValue;
    void* m_ulUserData;

    FUN_00de29b0(void* owner, void* userData);
};

// Initializes the base with owner, sets the float member to 0.0f and stores userData in the pointer member.
// @fnv 0x00de29b0
FUN_00de29b0::FUN_00de29b0(void* owner, void* userData) : DE29B0Base(owner), m_uiFilterValue(0.0f), m_ulUserData(userData)
{
}

struct hkBaseObject { virtual void base0() throw(); int unk04; };
struct hkProcess { virtual void process0() throw(); virtual void process1() throw(); virtual void process2() throw(); virtual void process3() throw(); virtual void process4() throw(); virtual void process5() throw(); virtual void process6() throw(); int unk04, unk08, unk0c, unk10, unk14; };
struct ContactArray { int unk00; int unk04; int unk08; int unk0c; int unk10; int unk14; int unk18; int unk1c; int unk20; int unk24; int unk28; int unk2c; int unk30; int unk34; int unk38; int unk3c; int unk40; int unk44; int unk48; int unk4c; int unk50; int unk54; int unk58; int unk5c; int unk60; int unk64; int unk68; void** data; int size; };
struct hkpPhysicsContextWorldListener { virtual void world0() throw(); virtual void world1() throw(); virtual void world2() throw(); ContactArray* contacts; void FUN_00de2980(void*) throw(); };
struct hkpWorldViewerBase : hkBaseObject, hkProcess, hkpPhysicsContextWorldListener { void FUN_00ddcc60() throw(); };
struct hkpWorldPostSimulationListener { virtual void post0() throw(); virtual void post1() throw(); virtual void post2() throw(); __forceinline ~hkpWorldPostSimulationListener() throw(); };
__forceinline hkpWorldPostSimulationListener::~hkpWorldPostSimulationListener() throw() {
    ((hkpWorldViewerBase*)((char*)this - 0x28))->FUN_00ddcc60();
}
struct hkpContactPointViewer : hkpWorldViewerBase, hkpWorldPostSimulationListener {
    __forceinline virtual ~hkpContactPointViewer() throw();
    void DestroyContactPointViewer() throw();
};
__forceinline hkpContactPointViewer::~hkpContactPointViewer() throw() {
    for (int i = 0; this->contacts && i < this->contacts->size; ++i)
        this->hkpPhysicsContextWorldListener::FUN_00de2980(this->contacts->data[i]);
}
// @fnv 0x00de2a40
void hkpContactPointViewer::DestroyContactPointViewer() throw() {
    this->hkpContactPointViewer::~hkpContactPointViewer();
}

struct SpawnedSub {
    virtual void v00();
    virtual void v04(void* apItem);
};

struct SpawnedList {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    void** m_6c;
    int m_70;
};

struct FUN_00de2a00_cls {
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    SpawnedSub m_18;
    SpawnedList* m_1c;

    void ProcessSpawnedList();
};

// Iterates the entries of m_1c up to m_70 and passes each m_6c element to m_18.v04.
// @fnv 0x00de2a00
void FUN_00de2a00_cls::ProcessSpawnedList()
{
    SpawnedList* list = m_1c;
    int i = 0;
    while (list != 0) {
        if (i >= list->m_70) {
            break;
        }
        m_18.v04(list->m_6c[i]);
        ++i;
        list = m_1c;
    }
}

extern "C" {
    unsigned __int64 __rdtsc(void);
    void _ReadWriteBarrier(void);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
}

extern unsigned long DAT_0126835c;

struct StringCursor {
    int unk0;
    char* m_ptr;
    int unk8;
    char* m_kRayEnd;
};

struct S_00de2fa0_Array {
    void** m_data;
    int m_iElementCount;
};

struct S_00de2fa0_Arg;

struct S_00de2fa0_Base0 {
    virtual void vfn_00() = 0;
    virtual void vfn_04() = 0;
    virtual void vfn_08() = 0;
    virtual S_00de2fa0_Array* vfn_0c(S_00de2fa0_Arg* a) = 0;
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

struct S_00de2fa0_Listener {
    virtual void PostSimulationCallback(S_00de2fa0_Arg* a) = 0;
};

struct S_00de2fa0 : S_00de2fa0_Base0, S_00de2fa0_Listener {
    virtual void PostSimulationCallback(S_00de2fa0_Arg* a);
    void FUN_00de2da0(void* elem);
};

// Writes profiler markers to the TLS stream, then iterates the array returned by vfn_0c and calls FUN_00de2da0 on each element.
// @fnv 0x00de2fa0
void S_00de2fa0::PostSimulationCallback(S_00de2fa0_Arg* apArg) {
    StringCursor* stream = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* p = stream->m_ptr;
    if (p < stream->m_kRayEnd) {
        *(const char**)p = "TthkpActiveContactPointViewer::postSimulationCallback";
        _ReadWriteBarrier();
        unsigned uiTimestamp = (unsigned)__rdtsc();
        *(unsigned*)(p + 4) = *(volatile unsigned*)&uiTimestamp;
        stream->m_ptr = p + 12;
    }

    S_00de2fa0_Array* arr = vfn_0c(apArg);
    for (int i = 0; i < arr->m_iElementCount; ++i) {
        FUN_00de2da0(arr->m_data[i]);
    }

    StringCursor* stream2 = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* pCursor2 = stream2->m_ptr;
    if (pCursor2 < stream2->m_kRayEnd) {
        *(const char**)pCursor2 = "Et";
        _ReadWriteBarrier();
        unsigned uiTimestamp2 = (unsigned)__rdtsc();
        *(unsigned*)(pCursor2 + 4) = *(volatile unsigned*)&uiTimestamp2;
        stream2->m_ptr = pCursor2 + 12;
    }
}

struct HkArrayRaw
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapFlags;
};

struct HkArrayPairBlock
{
    HkArrayRaw m_arrA;
    HkArrayRaw m_arrB;
};

struct HkAllocator
{
    virtual void v00();
    virtual void* Alloc(unsigned int cb);
};

struct HkAllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    HkAllocator* m_pAllocator;
};

struct HkDisplayConvexObj
{
    int unk00;
    unsigned short m_u04;
    unsigned short unk06;

    HkDisplayConvexObj* FUN_00de1d20(HkArrayPairBlock* a1);
};

HkAllocHolder* __cdecl FUN_00c85750() throw();
void __cdecl ResizeAudioStream(HkAllocator* a1, HkArrayRaw* a2, int a3);

struct FUN_00de4340_cls
{
    int unk00;
    int unk04;
    int unk08;
    HkDisplayConvexObj* m_pConvex;

    HkDisplayConvexObj* GetOrCreateConvex(HkArrayRaw* a1);
};

// Lazily allocates a pair block and a convex object, stores the convex in m_pConvex, appends it to a1, and returns m_pConvex.
// @fnv 0x00de4340
HkDisplayConvexObj* FUN_00de4340_cls::GetOrCreateConvex(HkArrayRaw* a1)
{
    int zero = 0;
    if (m_pConvex == (HkDisplayConvexObj*)zero)
    {
        HkArrayPairBlock* pPairBlock = (HkArrayPairBlock*)zero;
        HkAllocHolder* h = FUN_00c85750();
        void* pMemory = h->m_pAllocator->Alloc(0x18);
        if (pMemory != (void*)zero)
        {
            HkArrayPairBlock* p = (HkArrayPairBlock*)pMemory;
            *(void* volatile*)&p->m_arrA.m_pData = (void*)zero;
            *(volatile int*)&p->m_arrA.m_iArrayLength = zero;
            unsigned int uiCapFlag = 0x80000000u;
            *(volatile unsigned int*)&p->m_arrA.m_uCapFlags = uiCapFlag;
            *(void* volatile*)&p->m_arrB.m_pData = (void*)zero;
            *(volatile int*)&p->m_arrB.m_iArrayLength = zero;
            p->m_arrB.m_uCapFlags = uiCapFlag;
            pPairBlock = p;
        }

        h = FUN_00c85750();
        pMemory = h->m_pAllocator->Alloc(0x60);
        ((HkDisplayConvexObj*)pMemory)->m_u04 = 0x60;
        m_pConvex = ((HkDisplayConvexObj*)pMemory)->FUN_00de1d20(pPairBlock);

        h = FUN_00c85750();
        if (a1->m_iArrayLength == (int)(a1->m_uCapFlags & 0x3fffffffu))
        {
            ResizeAudioStream(h->m_pAllocator, a1, 4);
        }
        int iIndex = a1->m_iArrayLength;
        HkDisplayConvexObj** data = (HkDisplayConvexObj**)a1->m_pData;
        HkDisplayConvexObj** slot = data + iIndex;
        *slot = *(HkDisplayConvexObj* volatile*)&m_pConvex;
        a1->m_iArrayLength++;
    }
    return m_pConvex;
}

extern "C" void _ReadBarrier();
extern "C" void _WriteBarrier();
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);

extern "C" unsigned __int64 __rdtsc();

extern unsigned long DAT_0126835c;

struct ProfEntry { const char* name; unsigned tsc; unsigned unk08; };

struct ProfList { int unk00; ProfEntry* cur; int unk08; ProfEntry* end; };

struct Allocator { virtual void unk00(); virtual void unk04(); virtual void unk08(); virtual void unk0c(); virtual void Free(void* p, unsigned size); };

struct StackHeap { char* top; int unk04; int unk08; int unk0c; Allocator* alloc; };

inline StackHeap* GetStackHeap67() { return (StackHeap*)FUN_00c85750(); }

struct Sub { virtual void unk00(); virtual int Get(); };

struct Vec67 { float x,y,z,w; };
struct Contact67 { Vec67 position,normal; };
struct Target {
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20();
    virtual void Draw(const Vec67* a,const Vec67* b,int color,void* body,int tag);
};

union __declspec(intrin_type) __declspec(align(16)) __m128 { float m128_f32[4]; };
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_mul_ps(__m128,__m128);
extern "C" __m128 _mm_add_ps(__m128,__m128);
extern "C" __m128 _mm_shuffle_ps(__m128,__m128,int);
extern "C" __m128 _mm_add_ss(__m128,__m128);
extern "C" float _mm_cvtss_f32(__m128);
extern "C" void _mm_store_ps(float*,__m128);
__declspec(noinline) void FUN_00de2aa0(Target* context, Contact67* volatile contact, const Vec67* normal, int color, void* body, int tag);

struct Arr {

    unsigned short* data;

    int count;

    unsigned cap;

    unsigned short* stk;
__forceinline unsigned short& operator[](int index) { return data[index]; }

    __forceinline void Clear(Allocator* a) {
        count=0;
        if ((cap & 0x80000000) == 0) a->Free(data,(cap & 0x3fffffff)*2);
        data=0;cap=0x80000000;
    }

};

struct PointContext67 { int unk00,unk04,unk08,unk0c; int value10; };

struct Info { int unk00; union { PointContext67* slot[6]; struct { int unk04,unk08,unk0c,unk10,unk14; unsigned short unk18; unsigned char index; }; }; };

struct Obj {

    virtual void unk00(); virtual void unk04(); virtual void unk08(); virtual void unk0c();

    virtual void unk10(); virtual void unk14(); virtual void unk18(); virtual void unk1c();

    virtual void unk20(); virtual void unk24();

    virtual float* GetFloat(unsigned short i);

    virtual Contact67* GetItem(unsigned short i);

    virtual void Fill(Arr* arr);

    virtual int IsSkipped();

        int field04;

    int field08;

    int field0c;

    int field10;

    int field14;

    int field18;

    int field1c;

    int field20;

    int field24;

    int field28;

    int field2c;

    int field30;

    int field34;

    int field38;

    int field3c;

    int field40;

    int field44;

    int field48;

    int field4c;

    int field50;

    int field54;

    int field58;

    int field5c;

    int field60;

    int field64;

    int field68;

    int field6c;

    int field70;

    Info* unk74;

};

struct Rec { unsigned char unk00,unk01,unk02; unsigned char size; int unk04; Obj* obj; };

struct Cont {

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

    char** unk5c;

    int unk60;

};

struct Node {

    int unk00,unk04;

    Sub sub;

    int unk0c,unk10,unk14;

    Target* unk18;

    int unk1c,unk20,unk24,unk28;

    float unk2c;

    int unk30;

    void FUN_00de2da0(Cont* c);

};

// @fnv 0x00de2da0
void Node::FUN_00de2da0(Cont* c)

{

    union { volatile unsigned ticks; char* f; }; float* value;  { ProfList* pl = (ProfList*)TlsGetValue(DAT_0126835c);     

     ProfEntry* eb = pl->cur;

    if (eb < pl->end) {

        eb->name = "TthkpContactPointViewer::drawAllContactPointsInIsland"; _ReadWriteBarrier();

        ticks = (unsigned int)__rdtsc();
        eb->tsc = ticks;

        pl->cur = eb + 1;

    }

    { int i = 0;

    { int cnt = 0;

    while (cnt < c->unk60) {

        char* e = c->unk5c[cnt];

        cnt += 1; _ReadWriteBarrier();

        if (cnt == c->unk60) { f = e + c->unk58; _ReadWriteBarrier(); } else { f = e + 0x200; _ReadWriteBarrier(); }

        for (; e < f; e += ((Rec*)e)->size) {

            Obj* o = ((Rec*)e)->obj;

            if (o->IsSkipped()) continue;

            { Arr m;

            m.data = 0; m.count = 0; m.cap = 0x80000000;

            StackHeap* q = GetStackHeap67();

            { unsigned short* s = (unsigned short*)q->top;

            q->top = q->top + 0x200;

            m.data = s; m.stk = s; } m.cap = 0x80000100;

             o->Fill((&m));

            { i = 0; for (; i < m.count; ) { { Contact67* y = o->GetItem(m[i]);

                 value = o->GetFloat(m[i]);

                if (!(*value < unk2c)) {

                    PointContext67* volatile v = o->unk74->slot[o->unk74->index];

                    { int h = sub.Get();

                    int color=unk30; 
                    FUN_00de2aa0(unk18, y, &y->normal, color, &v->value10, h); }

                } } i++; } }

            { unsigned short* saved=m.stk; bool result = saved == m.data; if (0 != result) m.count = 0;

            GetStackHeap67()->top = (char*)saved;

            m.Clear(GetStackHeap67()->alloc); } }
        }

    } } }

    pl = (ProfList*)TlsGetValue(DAT_0126835c);

    ProfEntry* ea = pl->cur;

    if (ea < pl->end) {

        ea->name = "Et"; _ReadWriteBarrier();

        volatile unsigned int ticks2 = (unsigned int)__rdtsc();
        ea->tsc = ticks2;

        pl->cur = ea + 1;

    } }

}
#pragma optimize("", on)

extern "C" {

__m128 _mm_sub_ps(__m128 a, __m128 b);

__m128 _mm_mul_ss(__m128 a, __m128 b);

__m128 _mm_sub_ss(__m128 a, __m128 b);

__m128 _mm_sqrt_ss(__m128 a);

__m128 _mm_rsqrt_ss(__m128 a);

__m128 _mm_cmpeq_ss(__m128 a, __m128 b);

__m128 _mm_andnot_ps(__m128 a, __m128 b);

__m128 _mm_setzero_ps(void);

__m128 _mm_set_ss(float a);


__m128 _mm_load_ss(float const* p);



void _mm_store_ss(float* p, __m128 a);

}

#include <math.h>

extern const float DAT_01011d78;

extern const float DAT_01017718;

extern const float DAT_01016248;

extern const float DAT_01019de0;

extern const float DAT_010c69c4;
extern const float DAT_010c69c0 = -(1.0f - 0.85f);

extern const __m128 DAT_010ec7f0;

struct ContactArrowVector67 {

    __m128 m_vComponents;

};



static inline void markContactArrowProfile67(const char* name)

{

    StringCursor* s = (StringCursor*)TlsGetValue(DAT_0126835c);

    ProfEntry* p = (ProfEntry*)s->m_ptr;

    if (p < (ProfEntry*)s->m_kRayEnd) {

        p->name = name;
        unsigned int ticks;
        __asm {
            rdtsc
            mov dword ptr[ticks], eax
        }
        p->tsc = ticks;

        s->m_ptr = (char*)(p + 1);

    }

}

static inline __m128 contactArrowDot3_67(const __m128& a, const __m128& b)

{

    __m128 m = _mm_mul_ps(a, b);

    return _mm_add_ss(_mm_shuffle_ps(m, m, 0xaa), _mm_add_ss(_mm_shuffle_ps(m, m, 0x55), m));

}

static inline float contactArrowAbs67(float r) { return (float)fabs(r); }

// @fnv 0x00de2aa0
static __declspec(noinline) void FUN_00de2aa0(Target* self, Contact67* contact, const Vec67* direction, int color, void* id, int tag)

{

    const ContactArrowVector67& dir = *(const ContactArrowVector67*)direction;
    const ContactArrowVector67& from = *(const ContactArrowVector67*)&contact->position;

    markContactArrowProfile67("TthkContactPointViewer_displayArrow");

    float lenSq;

    _mm_store_ss(&lenSq, contactArrowDot3_67(dir.m_vComponents, dir.m_vComponents));

    if (lenSq < 1.1920928955078125e-07f) {

        markContactArrowProfile67("Et");

        return;

    }

    ContactArrowVector67 to;

    struct ArrowGeometry { ContactArrowVector67 p1; float perp[4]; } geometry;

    to.m_vComponents = _mm_add_ps(from.m_vComponents, dir.m_vComponents);

    int min = 0;

    int ok1 = 1;

    int ok2 = 2;

    float a0 = contactArrowAbs67(((const float*)&dir)[0]);

    float a1 = contactArrowAbs67(((const float*)&dir)[1]);

    float a2 = contactArrowAbs67(((const float*)&dir)[2]);

    if (a1 < a0) {

        ok1 = 0;

        min = 1;

        a0 = a1;

    }

    if (a2 < a0) {

        ok2 = min;

    }

    _mm_store_ps(geometry.perp, _mm_setzero_ps());

    geometry.perp[ok1] = ((const float*)&dir)[ok2];

    geometry.perp[ok2] = -((const float*)&dir)[ok1];

    ContactArrowVector67 ort;

    ort.m_vComponents = *(const __m128*)geometry.perp;

    {

        __m128 len2 = contactArrowDot3_67(ort.m_vComponents, ort.m_vComponents);

        __m128 r = _mm_rsqrt_ss(len2);

        __m128 zero = _mm_cmpeq_ss(len2, _mm_set_ss(DAT_01011d78));

        __m128 t = _mm_sub_ss(_mm_set_ss(DAT_01017718), _mm_mul_ss(_mm_mul_ss(len2, r), r));

        __m128 inv = _mm_andnot_ps(zero, _mm_mul_ss(_mm_mul_ss(_mm_set_ss(DAT_01016248), r), t));

        ort.m_vComponents = _mm_mul_ps(_mm_shuffle_ps(inv, inv, 0), ort.m_vComponents);

    }

    __m128 len = _mm_sqrt_ss(contactArrowDot3_67(dir.m_vComponents, dir.m_vComponents));

    ort.m_vComponents = _mm_mul_ps(ort.m_vComponents, _mm_shuffle_ps(len, len, 0));

    float cc = DAT_01019de0;

    __m128 t0 = _mm_load_ss(&cc);

    __m128 t = _mm_shuffle_ps(t0, t0, 0);

    ContactArrowVector67 p;

    p.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_sub_ps(DAT_010ec7f0, t), from.m_vComponents), _mm_mul_ps(t, to.m_vComponents));

    float f1 = DAT_010c69c4;

    __m128 r1 = _mm_load_ss(&f1);

    geometry.p1.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(r1, r1, 0), ort.m_vComponents), p.m_vComponents);

    float f2 = DAT_010c69c0;

    __m128 r2 = _mm_load_ss(&f2);

    ContactArrowVector67 p2;

    p2.m_vComponents = _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(r2, r2, 0), ort.m_vComponents), p.m_vComponents);

    self->Draw((const Vec67*)&from, (const Vec67*)&to, color, id, tag);

    self->Draw((const Vec67*)&to, (const Vec67*)&geometry.p1, color, id, tag);

    self->Draw((const Vec67*)&to, (const Vec67*)&p2, color, id, tag);

    markContactArrowProfile67("Et");

}
