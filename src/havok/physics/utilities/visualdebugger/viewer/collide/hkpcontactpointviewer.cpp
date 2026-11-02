
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpcontactpointviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpcontactpointviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Prefix32
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct Context
{
    void FUN_00c93920(void* value);
};
struct Secondary
{
    int unk00;
    int unk04;
    int child;
    void FUN_00de2950(Context* context);
};
struct Owner : Prefix32, Secondary
{
};
// Computes the address of the child member (or null if the owner is null) and passes it to context->FUN_00c93920.
// @fnv 0x00de2950
void Secondary::FUN_00de2950(Context* context)
{
    Owner* owner = reinterpret_cast<Owner*>(reinterpret_cast<char*>(this) - sizeof(Prefix32));
    void* value;
    if (owner)
        value = &child;
    else
        value = 0;
    context->FUN_00c93920(value);
}

struct S_00de2980_B2
{
    virtual void f2();
};
struct S_00de2980_World
{
    int ClearValue(S_00de2980_B2* p);
};
struct S_00de2980_B0
{
    virtual void f0();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct S_00de2980_B1
{
    virtual void FUN_00de2980(S_00de2980_World* w);
    int unk04;
};
struct S_00de2980_D : S_00de2980_B0, S_00de2980_B1, S_00de2980_B2
{
    virtual void FUN_00de2980(S_00de2980_World* w);
};

// @fnv 0x00de2980
void S_00de2980_D::FUN_00de2980(S_00de2980_World* pWorld)
{
    pWorld->ClearValue(this);
}

struct DE29B0PartA
{
    virtual void vfuncA();
    int unk04;
};

struct DE29B0PartB
{
    virtual void vfuncB();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

struct DE29B0PartC
{
    virtual void vfuncC();
    int unk04;
};

struct DE29B0Base : DE29B0PartA, DE29B0PartB, DE29B0PartC
{
    DE29B0Base(void* owner);
};

struct DE29B0Listener
{
    virtual void vfuncD();
};

struct FUN_00de29b0 : DE29B0Base, DE29B0Listener
{
    float m_uiFilterValue;
    void* m_ulUserData;

    FUN_00de29b0(void* owner, void* userData);
};

// Initializes the base with owner, sets the float member to 0.0f and stores userData in the pointer member.
// @fnv 0x00de29b0
FUN_00de29b0::FUN_00de29b0(void* owner, void* userData)
    : DE29B0Base(owner), m_uiFilterValue(0.0f), m_ulUserData(userData)
{}

struct hkBaseObject
{
    virtual void base0() throw();
    int unk04;
};
struct hkProcess
{
    virtual void process0() throw();
    virtual void process1() throw();
    virtual void process2() throw();
    virtual void process3() throw();
    virtual void process4() throw();
    virtual void process5() throw();
    virtual void process6() throw();
    int unk04, unk08, unk0c, unk10, unk14;
};
struct ContactArray
{
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
    void** data;
    int size;
};
struct hkpPhysicsContextWorldListener
{
    virtual void world0() throw();
    virtual void world1() throw();
    virtual void world2() throw();
    ContactArray* contacts;
    void FUN_00de2980(void*) throw();
};
struct hkpWorldViewerBase : hkBaseObject, hkProcess, hkpPhysicsContextWorldListener
{
    void FUN_00ddcc60() throw();
};
struct hkpWorldPostSimulationListener
{
    virtual void post0() throw();
    virtual void post1() throw();
    virtual void post2() throw();
    __forceinline ~hkpWorldPostSimulationListener() throw();
};
__forceinline hkpWorldPostSimulationListener::~hkpWorldPostSimulationListener() throw()
{
    ((hkpWorldViewerBase*)((char*)this - 0x28))->FUN_00ddcc60();
}
struct hkpContactPointViewer : hkpWorldViewerBase, hkpWorldPostSimulationListener
{
    __forceinline virtual ~hkpContactPointViewer() throw();
    void DestroyContactPointViewer() throw();
};
__forceinline hkpContactPointViewer::~hkpContactPointViewer() throw()
{
    for (int i = 0; this->contacts && i < this->contacts->size; ++i)
        this->hkpPhysicsContextWorldListener::FUN_00de2980(this->contacts->data[i]);
}
// @fnv 0x00de2a40
void hkpContactPointViewer::DestroyContactPointViewer() throw()
{
    this->hkpContactPointViewer::~hkpContactPointViewer();
}

struct SpawnedSub
{
    virtual void v00();
    virtual void v04(void* apItem);
};

struct SpawnedList
{
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

struct FUN_00de2a00_cls
{
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
    while (list != 0)
    {
        if (i >= list->m_70)
        {
            break;
        }
        m_18.v04(list->m_6c[i]);
        ++i;
        list = m_1c;
    }
}

extern "C"
{
    unsigned __int64 __rdtsc(void);
    void _ReadWriteBarrier(void);
    __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long dwTlsIndex);
}

extern unsigned long DAT_0126835c;

struct StringCursor
{
    int unk0;
    char* m_ptr;
    int unk8;
    char* m_kRayEnd;
};

struct S_00de2fa0_Array
{
    void** m_data;
    int m_iElementCount;
};

struct S_00de2fa0_Arg;

struct S_00de2fa0_Base0
{
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

struct S_00de2fa0_Listener
{
    virtual void PostSimulationCallback(S_00de2fa0_Arg* a) = 0;
};

struct S_00de2fa0 : S_00de2fa0_Base0, S_00de2fa0_Listener
{
    virtual void PostSimulationCallback(S_00de2fa0_Arg* a);
    void FUN_00de2da0(void* elem);
};

// Writes profiler markers to the TLS stream, then iterates the array returned by vfn_0c and calls FUN_00de2da0 on each element.
// @fnv 0x00de2fa0
void S_00de2fa0::PostSimulationCallback(S_00de2fa0_Arg* apArg)
{
    StringCursor* stream = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* p = stream->m_ptr;
    if (p < stream->m_kRayEnd)
    {
        *(const char**)p = "TthkpActiveContactPointViewer::postSimulationCallback";
        _ReadWriteBarrier();
        unsigned uiTimestamp = (unsigned)__rdtsc();
        *(unsigned*)(p + 4) = *(volatile unsigned*)&uiTimestamp;
        stream->m_ptr = p + 12;
    }

    S_00de2fa0_Array* arr = vfn_0c(apArg);
    for (int i = 0; i < arr->m_iElementCount; ++i)
    {
        FUN_00de2da0(arr->m_data[i]);
    }

    StringCursor* stream2 = (StringCursor*)TlsGetValue(DAT_0126835c);
    char* pCursor2 = stream2->m_ptr;
    if (pCursor2 < stream2->m_kRayEnd)
    {
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

struct ProfEntry
{
    const char* name;
    unsigned tsc;
    unsigned unk08;
};

struct ProfList
{
    int unk00;
    ProfEntry* cur;
    int unk08;
    ProfEntry* end;
};

struct Allocator
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();
    virtual void Free(void* p, unsigned size);
};

struct StackHeap
{
    char* top;
    int unk04;
    int unk08;
    int unk0c;
    Allocator* alloc;
};

inline StackHeap* GetStackHeap67()
{
    return (StackHeap*)FUN_00c85750();
}

struct Sub
{
    virtual void unk00();
    virtual int Get();
};

struct Vec67
{
    float x, y, z, w;
};
struct Contact67
{
    Vec67 position, normal;
};
struct Target
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void Draw(const Vec67* a, const Vec67* b, int color, void* body, int tag);
};

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
};
extern "C" __m128 _mm_load_ps(const float*);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_shuffle_ps(__m128, __m128, int);
extern "C" __m128 _mm_add_ss(__m128, __m128);
extern "C" float _mm_cvtss_f32(__m128);
extern "C" void _mm_store_ps(float*, __m128);
static __declspec(noinline) void FUN_00de2aa0(Target* context, Contact67* volatile contact, const Vec67* normal,
                                              int color, void* body, int tag)
{
    __m128 n = _mm_load_ps(&normal->x);
    __m128 sq = _mm_mul_ps(n, n);
    float len = _mm_cvtss_f32(_mm_add_ss(_mm_shuffle_ps(sq, sq, 0xaa), _mm_add_ss(_mm_shuffle_ps(sq, sq, 0x55), sq)));
    if (len < 0.000001f)
        return;
    Vec67 endpoint;
    _mm_store_ps(&endpoint.x, _mm_add_ps(_mm_load_ps(&contact->position.x), n));
    context->Draw(&contact->position, &endpoint, color, body, tag);
}

struct Arr
{

    unsigned short* data;

    int count;

    unsigned cap;

    unsigned short* stk;
    __forceinline unsigned short& operator[](int index)
    {
        return data[index];
    }

    __forceinline void Clear(Allocator* a)
    {
        count = 0;
        if ((cap & 0x80000000) == 0)
            a->Free(data, (cap & 0x3fffffff) * 2);
        data = 0;
        cap = 0x80000000;
    }
};

struct PointContext67
{
    int unk00, unk04, unk08, unk0c;
    int value10;
};

struct Info
{
    int unk00;
    union
    {
        PointContext67* slot[6];
        struct
        {
            int unk04, unk08, unk0c, unk10, unk14;
            unsigned short unk18;
            unsigned char index;
        };
    };
};

struct Obj
{

    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0c();

    virtual void unk10();
    virtual void unk14();
    virtual void unk18();
    virtual void unk1c();

    virtual void unk20();
    virtual void unk24();

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

struct Rec
{
    unsigned char unk00, unk01, unk02;
    unsigned char size;
    int unk04;
    Obj* obj;
};

struct Cont
{

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

struct Node
{

    int unk00, unk04;

    Sub sub;

    int unk0c, unk10, unk14;

    Target* unk18;

    int unk1c, unk20, unk24, unk28;

    float unk2c;

    int unk30;

    void FUN_00de2da0(Cont* c);
};

// Iterates contact records in c, and for each unskipped object whose float value is at least unk2c, draws a point via FUN_00de2aa0.
// @fnv 0x00de2da0
void Node::FUN_00de2da0(Cont* apCont)

{

    union
    {
        volatile unsigned ticks;
        char* f;
    };
    float* value;
    {
        ProfList* pl = (ProfList*)TlsGetValue(DAT_0126835c);

        ProfEntry* eb = pl->cur;

        if (eb < pl->end)
        {

            eb->name = "TthkpContactPointViewer::drawAllContactPointsInIsland";
            _ReadWriteBarrier();

            ticks = (unsigned int)__rdtsc();
            eb->tsc = ticks;

            pl->cur = eb + 1;
        }

        {
            int i = 0;

            {
                int cnt = 0;

                while (cnt < apCont->unk60)
                {

                    char* pEntry = apCont->unk5c[cnt];

                    cnt += 1;
                    _ReadWriteBarrier();

                    if (cnt == apCont->unk60)
                    {
                        f = pEntry + apCont->unk58;
                        _ReadWriteBarrier();
                    }
                    else
                    {
                        f = pEntry + 0x200;
                        _ReadWriteBarrier();
                    }

                    for (; pEntry < f; pEntry += ((Rec*)pEntry)->size)
                    {

                        Obj* pObj = ((Rec*)pEntry)->obj;

                        if (pObj->IsSkipped())
                            continue;

                        {
                            Arr m;

                            m.data = 0;
                            m.count = 0;
                            m.cap = 0x80000000;

                            StackHeap* pStackHeap = GetStackHeap67();

                            {
                                unsigned short* pStackTop = (unsigned short*)pStackHeap->top;

                                pStackHeap->top = pStackHeap->top + 0x200;

                                m.data = pStackTop;
                                m.stk = pStackTop;
                            }
                            m.cap = 0x80000100;

                            pObj->Fill((&m));

                            {
                                i = 0;
                                for (; i < m.count;)
                                {
                                    {
                                        Contact67* y = pObj->GetItem(m[i]);

                                        value = pObj->GetFloat(m[i]);

                                        if (!(*value < unk2c))
                                        {

                                            PointContext67* volatile v = pObj->unk74->slot[pObj->unk74->index];

                                            {
                                                int h = sub.Get();

                                                int color = unk30;
                                                FUN_00de2aa0(unk18, y, &y->normal, color, &v->value10, h);
                                            }
                                        }
                                    }
                                    i++;
                                }
                            }

                            {
                                unsigned short* pStackSaved = m.stk;
                                bool result = pStackSaved == m.data;
                                if (0 != result)
                                    m.count = 0;

                                GetStackHeap67()->top = (char*)pStackSaved;

                                m.Clear(GetStackHeap67()->alloc);
                            }
                        }
                    }
                }
            }
        }

        pl = (ProfList*)TlsGetValue(DAT_0126835c);

        ProfEntry* ea = pl->cur;

        if (ea < pl->end)
        {

            ea->name = "Et";
            _ReadWriteBarrier();

            volatile unsigned int ticks2 = (unsigned int)__rdtsc();
            ea->tsc = ticks2;

            pl->cur = ea + 1;
        }
    }
}
