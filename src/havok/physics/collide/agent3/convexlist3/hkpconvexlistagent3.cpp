
// src/havok/physics/collide/agent3/convexlist3/hkpconvexlistagent3.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/convexlist3/hkpconvexlistagent3.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

void __cdecl FUN_00da3510(void* a, void* b);

// @fnv 0x00d32b20
void __cdecl CallIfNotFlagged(int aiUnused, int pObject, int c)
{
    if (!(*(char*)(pObject + 0xb) & 0x20))
        FUN_00da3510((void*)(pObject + 0x10), (void*)c);
}

void __cdecl SetFlagAndCall(int, int, int);
void __cdecl FUN_00d32cd0(int, int, int);
void __cdecl FUN_00d32ca0(int, int, int);
void __cdecl FUN_00d32bd0(int, int, int);
void __cdecl FUN_00d32be0(int, int, int);
void __cdecl FUN_00d32c00(int, int, int);
void __cdecl FUN_00d32c20(int, int, int);
void __cdecl FUN_00d32c40(int, int, int);
void __cdecl FUN_00d32ae0(int, int, int);
void __cdecl FUN_00d32b40(int, int, int);
void __cdecl FUN_00d32ba0(int, int, int);
struct FUN_00d33140_t
{
    void* m_ppVirtualMethodTable;
    int m_04;
    void* m_08;
    void* m_0c;
    void* m_10;
    void* m_14;
    void* m_18;
    void* m_1c;
    void* m_20;
    void* m_24;
    void* m_28;
    void* m_2c;
    char m_30;
};
// Fills the struct at a with function pointers for its slots, stores a pointer in m_04 and sets m_30 to 1.
// @fnv 0x00d33140
void __cdecl FUN_00d33140(int apStruct)
{
    FUN_00d33140_t* p = (FUN_00d33140_t*)apStruct;
    p->m_ppVirtualMethodTable = (void*)&SetFlagAndCall;
    p->m_2c = (void*)&FUN_00d32cd0;
    p->m_28 = (void*)&FUN_00d32ca0;
    p->m_08 = (void*)&FUN_00d32bd0;
    p->m_0c = (void*)&FUN_00d32be0;
    p->m_10 = (void*)&FUN_00d32c00;
    p->m_14 = (void*)&FUN_00d32c20;
    p->m_18 = (void*)&FUN_00d32c40;
    p->m_1c = (void*)&FUN_00d32ae0;
    p->m_20 = (void*)&CallIfNotFlagged;
    p->m_24 = (void*)&FUN_00d32b40;
    p->m_04 = (int)&FUN_00d32ba0;
    p->m_30 = 1;
}

struct FUN_00d32ae0_agent
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(const char*);
    virtual void f7();
};

void __cdecl FUN_00d97250(void*, void*, void*);

// If the flag at offset 0x0b of b is clear, calls f6 with "hkConvexListAgent3", FUN_00d97250 on b+0x10, then f7 on the agent.
// @fnv 0x00d32ae0
void __cdecl FUN_00d32ae0(int aiUnused, int b, int c)
{
    if (reinterpret_cast<unsigned char*>(b)[0x0b] & 0x20)
        return;

    FUN_00d32ae0_agent* agent = *reinterpret_cast<FUN_00d32ae0_agent**>(reinterpret_cast<char*>(&c) + 4);

    agent->f6("hkConvexListAgent3");
    FUN_00d97250(reinterpret_cast<char*>(b) + 0x10, reinterpret_cast<void*>(c), agent);
    agent->f7();
}

void __cdecl _FUN_00da35f0(void*, float, float, int);

// If the object's byte at offset 0xb lacks flag 0x20, forwards its fields at +0x10 plus three stack arguments to _FUN_00da35f0.
// @fnv 0x00d32b40
void __cdecl FUN_00d32b40(int aiUnused, int aiArg1, int aiArg2)
{
    struct StackArguments
    {
        void* object;
        float first;
        float second;
        int third;
    };

    StackArguments* pStackArgs = reinterpret_cast<StackArguments*>(&aiArg1);
    if (!(reinterpret_cast<unsigned char*>(pStackArgs->object)[0xb] & 0x20))
    {
        _FUN_00da35f0(reinterpret_cast<unsigned char*>(pStackArgs->object) + 0x10, pStackArgs->first,
                      pStackArgs->second, pStackArgs->third);
    }
}

void __cdecl DispatchInputRecord(int a, int b, void* c);

// Calls DispatchInputRecord with a, b and c, then sets bit 0x20 and clears bit 0x40 in byte 0xb of c.
// @fnv 0x00d32b70
void __cdecl SetFlagAndCall(int aiArg1, int aiArg2, int c)
{
    char* p = (char*)c;
    DispatchInputRecord(aiArg1, aiArg2, p);
    p[0xb] = (p[0xb] & 0xbf) | 0x20;
}

void __cdecl RemoveEntryById(void);

// @fnv 0x00d32be0
void __cdecl FUN_00d32be0(int, int apObject, int)
{
    if ((reinterpret_cast<unsigned char*>(apObject)[0x0b] & 0x20) != 0)
    {
        *reinterpret_cast<volatile int*>(&apObject) = apObject;
        RemoveEntryById();
    }
}

void __cdecl InsertSlotId(void);

// @fnv 0x00d32c00
void __cdecl FUN_00d32c00(int aiUnused, int apObject, int aiUnused2)
{
    if ((reinterpret_cast<unsigned char*>(apObject)[0x0b] & 0x20) != 0)
    {
        *(volatile int*)&apObject = apObject;
        InsertSlotId();
    }
}

void __cdecl FindEntryByKey(int, int, int);

// @fnv 0x00d32c20
void __cdecl FUN_00d32c20(int aiArg1, int apArg2, int aiArg3)
{
    if ((reinterpret_cast<unsigned char*>(apArg2)[0x0b] & 0x20) != 0)
        FindEntryByKey(aiArg1, apArg2, aiArg3);
}

struct PackTarget
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
    virtual void v24();
};

struct FUN_00d33210_cls
{
    int unk00;
    int unk04;
    int unk08;
    PackTarget* m_0c;
    void FUN_00d33210();
};

// @fnv 0x00d33210
void FUN_00d33210_cls::FUN_00d33210()
{
    m_0c->v24();
}

// FUN_00d33220 (0x00d33220, 10 bytes)
//
//	8b 49 0c        mov ecx, dword ptr [ecx+0xc]
//	8b 01           mov eax, dword ptr [ecx]
//	8b 40 10        mov eax, dword ptr [eax+0x10]
//	ff e0           jmp eax
//
// A __thiscall member of a wrapper class: it loads the polymorphic
// sub-object pointer at +0xc, then tail-jumps to the sub-object's
// virtual at vtable offset 0x10 (the fifth virtual), forwarding the
// incoming 4-byte stack argument in place (that is what puts the jump
// target in EAX instead of EDX).

struct Sub_d33220
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(int);
};

struct Own_d33220
{
    int unk00;
    int unk04;
    int unk08;
    Sub_d33220* unk0c;
    void FUN_00d33220(int);
};

// @fnv 0x00d33220
void Own_d33220::FUN_00d33220(int a)
{
    unk0c->v4(a);
}

struct FnvCpu_FUN_00d33230_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00d33230_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FnvCpu_FUN_00d33230_CpuInterface* target;
    void FUN_00d33230(int arg0);
};
// @fnv 0x00d33230
void FnvCpu_FUN_00d33230_CpuOwner::FUN_00d33230(int arg0)
{
    target->Invoke(arg0);
}

struct Target
{
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18(int a);
};

struct Self
{
    int unk00;
    int unk04;
    int unk08;
    Target* unk0c;
};

// @fnv 0x00d33240
void __fastcall FUN_00d33240(Self* self, int unused, int arg)
{
    self->unk0c->vfn18(arg);
}

struct FnvCpu_FUN_00d33250_CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void Invoke(int arg0);
};
struct FnvCpu_FUN_00d33250_CpuOwner
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    FnvCpu_FUN_00d33250_CpuInterface* target;
    void FUN_00d33250(int arg0);
};
// @fnv 0x00d33250
void FnvCpu_FUN_00d33250_CpuOwner::FUN_00d33250(int arg0)
{
    target->Invoke(arg0);
}

struct TargetInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual int slot10();
};

struct Arg3
{
    TargetInterface* target;
};

struct Arg1
{
    int unk00;
    int unk04;
    short unk08;
    char unk0a;
    unsigned char flags;
    int unk0c;
    int field_10;
};

struct EventData
{
    int m00;
    Arg3* m04;
    int m08;
    int m0c;
    int m10;
    int m14;
    int m18;
    int m1c;
};

void __cdecl FUN_00da48e0(void*, void*);

// @fnv 0x00d32c40
void __cdecl FUN_00d32c40(int aiUnused, Arg1* a1, int a2, Arg3* a3, int aiArg4, int aiArg5, int aiArg6)
{
    if (a1->flags & 0x20)
    {
        return;
    }
    int iSlotResult;
    iSlotResult = a3->target->slot10();
    EventData j;
    j.m00 = a2;
    j.m04 = a3;
    j.m10 = aiArg4;
    j.m14 = aiArg5;
    j.m18 = aiArg6;
    j.m0c = iSlotResult;
    FUN_00da48e0(&a1->field_10, &j);
}

struct hkpShapeD333
{
    void* m_ppVirtualMethodTable;
    int m_usMemSizeAndFlags;
    int m_ulUserData;
    int m_type;
};

class hkpShapeContainerD333
{
  public:
    virtual ~hkpShapeContainerD333() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual const hkpShapeD333* GetShapeForKey(unsigned int uiKey, void* pvBuffer) const throw();
};

struct hkpShapeCollectionD333 : public hkpShapeD333
{
    int m_10;
    hkpShapeContainerD333 m_container;
};

struct hkpCdBodyD333
{
    const hkpShapeD333* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const hkpCdBodyD333* m_parent;
};

struct hkpGskCacheD333
{
    unsigned short m_kVertices[4];
    unsigned char m_ucDimensionA;
    unsigned char m_ucDimensionB;
};

struct __declspec(align(16)) hkpShapeBufferD333
{
    unsigned int m_buffer[128];
};

class hkpChildProcessorD333
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int process(const hkpCdBodyD333& kBodyA, const hkpCdBodyD333& kBodyB, const void* pvInput,
                        const void* pvTransform, hkpGskCacheD333* pkCache, void* pvOutput) throw();
};

class hkpConvexListProcessorD333
{
  public:
    int m_00;
    int m_04;
    int m_08;
    hkpChildProcessorD333* m_processor;
    bool m_invalidCache;

    int ProcessConvexListChildren(const hkpCdBodyD333& kBodyA, const hkpCdBodyD333& kBodyB, const void* pvInput,
                                  const void* pvTransform, hkpGskCacheD333* pkCache, void* pvOutput) throw();
};

// Resolves convex-list child shapes for both bodies from the cache keys, flags an invalid cache on mismatch, and delegates to m_processor->process.
// @fnv 0x00d33390
int hkpConvexListProcessorD333::ProcessConvexListChildren(const hkpCdBodyD333& kBodyA, const hkpCdBodyD333& kBodyB,
                                                          const void* pvInput, const void* pvTransform,
                                                          hkpGskCacheD333* pkCache, void* pvOutput) throw()
{
    hkpShapeBufferD333 kBuffer;
    const hkpCdBodyD333* pkBodyA = &kBodyA;
    const hkpCdBodyD333* pkBodyB = &kBodyB;
    hkpCdBodyD333 kChildA;
    hkpCdBodyD333 kChildB;

    if (kBodyA.m_pCollisionShape->m_type == 0x16)
    {
        int iKey = pkCache->m_kVertices[0] >> 8;
        for (int i = 1; i < pkCache->m_ucDimensionA; i++)
        {
            if ((pkCache->m_kVertices[i] >> 8) != iKey)
            {
                m_invalidCache = true;
                return 0xffff;
            }
        }
        const hkpShapeD333* pkChild = static_cast<const hkpShapeCollectionD333*>(kBodyA.m_pCollisionShape)
                                          ->m_container.GetShapeForKey(iKey, &kBuffer);
        kChildA.m_uiCollisionShapeKey = iKey;
        kChildA.m_parent = &kBodyA;
        kChildA.m_pMotionState = kBodyA.m_pMotionState;
        kChildA.m_pCollisionShape = pkChild;
        pkBodyA = &kChildA;
    }
    if (kBodyB.m_pCollisionShape->m_type == 0x16)
    {
        int iKey = pkCache->m_kVertices[pkCache->m_ucDimensionA] >> 8;
        for (int i = pkCache->m_ucDimensionA + 1; i < pkCache->m_ucDimensionA + pkCache->m_ucDimensionB; i++)
        {
            if ((pkCache->m_kVertices[i] >> 8) != iKey)
            {
                m_invalidCache = true;
                return 0xffff;
            }
        }
        const hkpShapeD333* pkChild = static_cast<const hkpShapeCollectionD333*>(kBodyB.m_pCollisionShape)
                                          ->m_container.GetShapeForKey(iKey, &kBuffer);
        kChildB.m_parent = &kBodyB;
        kChildB.m_pMotionState = kBodyB.m_pMotionState;
        kChildB.m_pCollisionShape = pkChild;
        kChildB.m_uiCollisionShapeKey = iKey;
        pkBodyB = &kChildB;
    }
    return m_processor->process(*pkBodyA, *pkBodyB, pvInput, pvTransform, pkCache, pvOutput);
}

struct ValueBlock
{
    void FUN_00d33330(ValueBlock* destination);
};

struct Callback
{
    virtual void Reserved00();
    virtual void Reserved04();
    virtual void Reserved08();
    virtual void Reserved0c();
    virtual void Reserved10();
    virtual void Reserved14();
    virtual void Reserved18();
    virtual void Reserved1c();
    virtual void OnValueChange(unsigned int identifier, void* data);
};

void __cdecl FUN_00ec44d0(void* target, const void* input, unsigned int byteCount);

struct Container
{
    unsigned int tag;
    void FUN_00d33600(void* unusedA, void* unusedB, char* source, Callback* callback);
};

// Compares the source's time field with this object's, notifies the callback and copies the value block on change, then copies the tag and payload.
// @fnv 0x00d33600
void Container::FUN_00d33600(void* unusedA, void* unusedB, char* source, Callback* callback)
{
    float sourceTime = *reinterpret_cast<float*>(source + 0x3030);
    char* destination = reinterpret_cast<char*>(this);

    if (sourceTime != *reinterpret_cast<float*>(destination + 0x1030))
    {
        callback->OnValueChange(*reinterpret_cast<unsigned int*>(source + 4), source + 0x3050);
        reinterpret_cast<ValueBlock*>(source + 0x3010)
            ->FUN_00d33330(reinterpret_cast<ValueBlock*>(destination + 0x1010));
    }

    *reinterpret_cast<unsigned int*>(source) = tag;
    void* output = *reinterpret_cast<void**>(source + 0x3080);
    if (output != 0)
    {
        FUN_00ec44d0(output, destination + 4, 0x1008);
    }
}

struct hkpShapeD32
{
    int unk00;
    int unk04;
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0A;
    unsigned char m_flags;
    int unk0C;
    int m_data;
};

void __cdecl ForwardToTarget(void* agent, hkpShapeD32* shape, void* input, void* output, void* collector);
void __cdecl FUN_00da42b0(int* data, void* collector, void* input, void* output);

// If the hkpShapeD32 flag 0x20 is set, forward the call to ForwardToTarget; otherwise call FUN_00da42b0 with the shape data.
// @fnv 0x00d32ba0
void __cdecl FUN_00d32ba0(void* agent, hkpShapeD32* shape, void* input, void* output, void* collector)
{
    if (shape->m_flags & 0x20)
    {
        ForwardToTarget(agent, shape, input, output, collector);
        return;
    }
    FUN_00da42b0(&shape->m_data, collector, input, output);
}

void __cdecl FUN_00d41860();
// @fnv 0x00d32bd0
void __cdecl FUN_00d32bd0(int a, int b, int c)
{
    FUN_00d41860();
}

struct hkpAgent3FuncsD331
{
    hkpAgent3FuncsD331()
    {
        m_bIsPredictive = false;
        m_bAgentFlag1 = false;
        m_bAgentFlag2 = false;
        m_pAgentFunction7 = 0;
        m_pAgentFunction8 = 0;
        m_pUpdateFilterFunc = 0;
        m_pAgentFunction10 = 0;
        m_pAgentFunction11 = 0;
    }

    void* m_pCreateFunc;
    void* m_pAgent3DestroyFuncs;
    void* m_pAgentFunction3;
    void* m_pAgentFunction4;
    void* m_pAgentFunction5;
    void* m_createZeroContactFunc;
    void* m_pAgentFunction7;
    void* m_pAgentFunction8;
    void* m_pUpdateFilterFunc;
    void* m_pAgentFunction10;
    void* m_pAgentFunction11;
    void* m_setCollisionQualityFunc;
    bool m_bIsPredictive;
    bool m_bAgentFlag1;
    bool m_bAgentFlag2;
};

void __cdecl FUN_00d33140(hkpAgent3FuncsD331& kFuncs);

class hkpCollisionDispatcherD331
{
  public:
    void AddEntry(const hkpAgent3FuncsD331& kFuncs, int iTypeA, int iTypeB);
};

// Initializes a hkpAgent3FuncsD331 via FUN_00d33140 and adds two entries to pkDispatcher for type pairs 0x12/0x16 and 0x16/0x16.
// @fnv 0x00d331a0
void __cdecl RegisterAgent3Entries(hkpCollisionDispatcherD331* pkDispatcher)
{
    __declspec(align(16)) hkpAgent3FuncsD331 kFuncs;
    FUN_00d33140(kFuncs);
    pkDispatcher->AddEntry(kFuncs, 0x12, 0x16);
    pkDispatcher->AddEntry(kFuncs, 0x16, 0x16);
}

#include <xmmintrin.h>
// Builds on an earlier contributor's 2026-10-25 reconstruction of this routine.
extern float DAT_010CEB6C;
extern __m128 DAT_01268370;
void __cdecl FUN_00d41930(int, int, int, int);
// If bit 5 of the flag byte at c+11 is set, delegates to FUN_00d41930; otherwise writes DAT_01268370 to output and sets its fourth float to DAT_010CEB6C.
// @fnv 0x00d32ca0
void __cdecl FUN_00d32ca0(int a, int b, int c, int output)
{
    if ((*reinterpret_cast<const unsigned char*>(c + 11) & 0x20) != 0)
    {
        FUN_00d41930(a, b, c, output);
        return;
    }
    __m128* __restrict p = reinterpret_cast<__m128*>(output);
    float finalComponent = DAT_010CEB6C;
    *p = DAT_01268370;
    reinterpret_cast<float*>(p)[3] = finalComponent;
}

struct HK_ASSERT_OBJECT_SIZE_OK_FUNC_t
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    HK_ASSERT_OBJECT_SIZE_OK_FUNC_t& FUN_00d33260(const HK_ASSERT_OBJECT_SIZE_OK_FUNC_t& a);
};

struct __declspec(align(16)) HK_Stage_t
{
    int d00;
    int d04;
    int d08;
    int d0c;
    int d10;
    int d14;
    int d18;
    int d1c;
    int d20;
    int d24;
    int d28;
    int d2c;
    int d30;
    int d34;
    int d38;
    int d3c;
};

// Copies the first 20 bytes and the remaining 64 bytes of the source object into this object, returning a reference to this.
// @fnv 0x00d33260
HK_ASSERT_OBJECT_SIZE_OK_FUNC_t& HK_ASSERT_OBJECT_SIZE_OK_FUNC_t::FUN_00d33260(const HK_ASSERT_OBJECT_SIZE_OK_FUNC_t& a)
{
    m_00 = a.m_00;
    m_04 = a.m_04;
    m_08 = a.m_08;
    m_0c = a.m_0c;
    m_10 = a.m_10;
    HK_Stage_t stagedTail;
    stagedTail.d00 = a.m_20;
    stagedTail.d04 = a.m_24;
    stagedTail.d08 = a.m_28;
    stagedTail.d0c = a.m_2c;
    stagedTail.d10 = a.m_30;
    stagedTail.d14 = a.m_34;
    stagedTail.d18 = a.m_38;
    stagedTail.d1c = a.m_3c;
    stagedTail.d20 = a.m_40;
    stagedTail.d24 = a.m_44;
    stagedTail.d28 = a.m_48;
    stagedTail.d2c = a.m_4c;
    stagedTail.d30 = a.m_50;
    stagedTail.d34 = a.m_54;
    stagedTail.d38 = a.m_58;
    stagedTail.d3c = a.m_5c;
    __m128* d = (__m128*)&m_20;
    const __m128* s = (const __m128*)&stagedTail.d00;
    d[0] = s[0];
    d[1] = s[1];
    d[2] = s[2];
    d[3] = s[3];
    return *this;
}

#include <string.h>
struct __declspec(align(16)) FUN_00d33330_t
{
    __m128 first;
    __m128 second;
    int alpha, beta;
    int VirtualFunction28, reserved2c;
    int gamma, delta;
    volatile int epsilon, zeta;
    int coefficients[12];
    FUN_00d33330_t& FUN_00d33330(const FUN_00d33330_t& other);
};
// Copies first, second, alpha, beta, gamma, delta, epsilon, zeta and 48 bytes of coefficients from other, and returns *this.
// @fnv 0x00d33330
FUN_00d33330_t& FUN_00d33330_t::FUN_00d33330(const FUN_00d33330_t& other)
{
    first = other.first;
    second = other.second;
    alpha = other.alpha;
    beta = other.beta;
    gamma = other.gamma;
    delta = other.delta;
    epsilon = other.epsilon;
    zeta = other.zeta;
    memcpy(coefficients, other.coefficients, 48);
    return *this;
}

extern const float DAT_0104da48 = 3.402820018375656e+38F;
struct CollisionRecord
{
    __m128 position;
    __m128 normal;
    __m128 properties;
};
struct SmallState
{
    float a;
    float b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int h;
    int i;
    int j;
    int k;
    int l;
};
struct CollisionState
{
    SmallState* copyScalars(const CollisionState& s)
    {
        unk40 = s.unk40;
        unk44 = s.unk44;
        unk48 = s.unk48;
        unk4c = s.unk4c;
        return &extra;
    }
    __m128 vector0;
    __m128 vector1;
    float distance;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    SmallState extra;
};
struct LargeOutput
{
    int header;
    int unk04;
    int unk08;
    int unk0c;
    CollisionRecord contacts[256];
    CollisionState state;
    void* data;
};
class FUN_00d33670
{
  public:
    int header;
    unsigned char data[0x1008];
    int unk100c;
    CollisionState state;
    FUN_00d33670(const LargeOutput& src);
};
// Copies header, state vectors, distance, scalars, and data buffer from a LargeOutput into this collision object.
// @fnv 0x00d33670
FUN_00d33670::FUN_00d33670(const LargeOutput& src)
{
    float d = DAT_0104da48;
    header = src.header;
    state.distance = d;
    state.extra.a = 0.0f;
    state.extra.b = 0.0f;
    state.vector0 = src.state.vector0;
    state.vector1 = src.state.vector1;
    memcpy(&state.distance, &src.state.distance, 8);
    SmallState* pExtra = state.copyScalars(src.state);
    memcpy(pExtra, &src.state.extra, sizeof(state.extra));
    if (src.data)
        FUN_00ec44d0(data, src.data, sizeof(data));
}

#include <xmmintrin.h>
namespace fnv_00d32cd0 {
#include <windows.h>
#include <string.h>

extern "C" unsigned __int64 __rdtsc();
extern "C" void _ReadWriteBarrier();

struct __declspec(align(16)) FourFloatVector
{
    union
    {
        __m128 v;
        struct
        {
            float x, y, z, w;
        };
    };
};
struct Transform
{
    FourFloatVector rotation0, rotation1, rotation2, translation;
    void FUN_00cb22f0(Transform*, Transform*);
};
struct Shape
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c,
        unk40, unk44;
    int childCount;
    int unk4c;
    int children;
};
struct Body
{
    Shape* shape;
    int key;
    Transform* transform;
    Body* parent;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48;
    float radius;
};
struct CollisionInput
{
    int unk00, unk04;
    float tolerance;
};
struct Cache
{
    int first, second;
    unsigned int state;
};
struct Contact
{
    FourFloatVector position, normal;
};
struct Basis
{
    FourFloatVector x, y, z;
};
struct ContactIDs
{
    int id0, id1, id2, id3;
};
struct CacheState
{
    FourFloatVector first, second;
    union
    {
        float time;
        unsigned int timeBits;
    };
    int key;
    int unk28, unk2c;
    ContactIDs ids;
    Basis transform;
    __forceinline void assign(const CacheState& source)
    {
        first.v = source.first.v;
        second.v = source.second.v;
        timeBits = source.timeBits;
        key = source.key;
        ids = source.ids;
        transform = source.transform;
    }
};
struct Output
{
    int count;
    int owner;
    int unk08, unk0c;
    Contact contacts[384];
    CacheState cache;
    void* savedContacts;
};
struct Manager
{
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20(int, Basis*);
};
struct Context
{
    Body* bodyA;
    Body* bodyB;
    int unk08;
    CollisionInput* input;
    Manager* manager;
    int unk14, unk18, unk1c;
    Transform transform;
    int extra60, extra64, extra68, extra6c, extra70, extra74, extra78, extra7c;
};
struct StateRecord
{
    union
    {
        int packed;
        struct
        {
            short countdown;
            unsigned char count;
            char unk0f;
        };
    };
    Cache cache;
};
struct Agent
{
    int unk00, unk04;
    short unk08;
    char unk0a;
    unsigned char flags;
    StateRecord state;
};
struct FUN_00d33670
{
    int count;
    int owner;
    int unk08, unk0c;
    Contact contacts[128];
    CacheState cache;
    FUN_00d33670(Output*);
    void FUN_00d33600(Body*, Body*, Output*, Manager*);
};
struct ProcessInput
{
    Body* bodyA;
    Body* bodyB;
    int unk08;
    CollisionInput* input;
    Manager* manager;
    int unk14, unk18, unk1c;
    Transform transform;
    int extra60, extra64, extra68, extra6c, extra70, extra74, extra78, extra7c;
    void FUN_00d33260(Context*);
};
struct CollisionResult
{
    float unk00, unk04, unk08, distance;
};
struct ProbeInput
{
    Transform* relative;
    Transform* world;
    Shape* a;
    Shape* b;
    float tolerance;
};
struct Collector
{
    void* vtable;
    short unk04;
    short capacity;
    int mode;
    Manager* manager;
    bool hit;
};
struct MonitorEntry
{
    const char* volatile name;
    unsigned int time;
    int unk08;
    const char* volatile detail;
};
struct Monitor
{
    int unk00;
    MonitorEntry* current;
    int unk08;
    MonitorEntry* end;
};
extern DWORD DAT_0126835c;
extern void* DAT_010ceb44;
extern float DAT_010ceb6c;
int __cdecl FUN_00dabca0(ProbeInput*, Agent*, void*, FourFloatVector*);
void __cdecl FUN_00da42b0(Cache*, int, Manager*, int);
void* __cdecl FUN_00d41a30(ProcessInput*, int, Agent*, void*, Output*);
void __cdecl FUN_00d41860(int, Agent*, Manager*, int);
void __cdecl InitBlockPool(Cache*);
void __cdecl FUN_00da4aa0(Cache*, Context*, int*, int*, Output*);
void* __cdecl FUN_00c85750();

struct TLSArgument
{
    DWORD value;
};
// Runs a collision probe or stream on two bodies, updates the agent cache and contact output, and returns a 16-byte-aligned result pointer.
// @fnv 0x00d32cd0
void* __cdecl FUN_00d32cd0(Context* context, int stream, Agent* agent, CollisionResult* collisionOutput, Output* output)
{
    struct Scratch
    {
        volatile unsigned int stamp;
        union
        {
            Shape* shape;
            volatile unsigned int stamp;
        } shapeEnd;

        union
        {
            void* result;
            Monitor* monitor;
        } outcome;
    } scratch;

    {
        Monitor* monitor = (Monitor*)TlsGetValue(DAT_0126835c);
        MonitorEntry* entry = monitor->current;
        if (entry < monitor->end)
        {
            entry->name = "LtCvxLst";
            entry->detail = "StTim";
            _ReadWriteBarrier();
            scratch.stamp = (unsigned int)__rdtsc();
            _ReadWriteBarrier();
            entry->time = scratch.stamp;
            monitor->current = (MonitorEntry*)((char*)entry + 16);
        }
    }
    scratch.shapeEnd.shape = context->bodyB->shape;
    FUN_00d33670 temporary(output);

    FourFloatVector separating;
    union
    {
        Transform relative;
        ProcessInput process;
    } phase;
    union
    {
        ProbeInput probe;
        Collector collector;
    } arguments;
    if (agent->flags & 0x20)
        goto processStream;
    for (;;)
    {
        {
            scratch.outcome.monitor = (Monitor*)TlsGetValue(DAT_0126835c);
            MonitorEntry* entry = scratch.outcome.monitor->current;
            if (entry < scratch.outcome.monitor->end)
            {
                entry->name = "StStream";
                _ReadWriteBarrier();
                scratch.stamp = (unsigned int)__rdtsc();
                _ReadWriteBarrier();
                entry->time = scratch.stamp;
                scratch.outcome.monitor->current = (MonitorEntry*)((char*)entry + 12);
            }
            if (agent->state.countdown-- >= 0)
                goto fallback;
            agent->state.countdown = 25;
            {

                phase.relative.FUN_00cb22f0(context->bodyA->transform, context->bodyB->transform);

                arguments.probe.a = context->bodyA->shape;
                arguments.probe.b = context->bodyB->shape;
                arguments.probe.relative = &phase.relative;
                arguments.probe.world = context->bodyA->transform;
                arguments.probe.tolerance = context->input->tolerance;

                if (!FUN_00dabca0(&arguments.probe, agent, collisionOutput, &separating))
                    goto fallback;
            }
            FUN_00da42b0(&agent->state.cache, context->input->unk00, context->manager, output->owner);
            agent->flags |= 0x20;
            agent->state.packed = 0;
            temporary.FUN_00d33600(context->bodyA, context->bodyB, output, context->manager);
        }
    processStream: {

        arguments.collector.capacity = 1;
        arguments.collector.mode = 2;
        arguments.collector.vtable = &DAT_010ceb44;
        arguments.collector.manager = context->manager;
        arguments.collector.hit = false;

        phase.process.FUN_00d33260(context);
        phase.process.extra60 = context->extra60;
        phase.process.extra70 = context->extra70;
        phase.process.extra74 = context->extra74;
        phase.process.extra78 = context->extra78;
        phase.process.extra7c = context->extra7c;
        phase.process.manager = (Manager*)&arguments.collector;
        scratch.outcome.result = FUN_00d41a30(&phase.process, stream, agent, collisionOutput, output);
        phase.process.manager = arguments.collector.manager;
        if (!arguments.collector.hit)
        {
            if (!agent->state.count || (agent->flags & 0x40))
                goto finished;
            Body* body = context->bodyB;
            while (body->parent)
                body = body->parent;
            float radiusB = body->radius;
            body = context->bodyA;
            while (body->parent)
                body = body->parent;
            float radiusA = body->radius;
            float radius = radiusA < radiusB ? radiusA : radiusB;
            float twice = radius * 2.0f;
            if (!(collisionOutput->distance < -twice))
                goto finished;
        }
        Manager* manager = context->manager;
        if (output->cache.time != temporary.cache.time)
        {
            manager->f20(output->owner, &output->cache.transform);
            output->cache.assign(temporary.cache);
        }
        output->count = temporary.count;
        if (output->savedContacts)
            memmove(output->savedContacts, &temporary.owner, 0x1008);
        FUN_00d41860(stream, agent, context->manager, output->owner);
        agent->flags &= 0xdf;
        StateRecord* state = &agent->state;
        if (state)
        {
            state->cache.first = 0;
            state->cache.second = 0;
            state->cache.state = 0x80000000;
        }
        InitBlockPool(&agent->state.cache);
        agent->state.countdown = 25;
    }
    }
fallback:
    collisionOutput->distance = -1.701410009187828e+38f;
    {
        int count = scratch.shapeEnd.shape->childCount;
        int** arena = (int**)FUN_00c85750();
        int* keys = *arena;
        *arena = (int*)((char*)keys + ((count * 4 + 0x83) & ~0x7f));
        for (int i = 0; i < count; ++i)
            keys[i] = i;
        int* sub = &(*(Shape* volatile*)&scratch.shapeEnd.shape)->unk14;
        Cache* cache = &agent->state.cache;
        FUN_00da4aa0((keys[count] = -1, cache), context, sub, keys, output);
        *(int**)FUN_00c85750() = keys;
        scratch.outcome.result = cache + 1;
    }
finished:
    agent->flags |= 0x40;
    Monitor* monitor = (Monitor*)TlsGetValue(DAT_0126835c);
    MonitorEntry* entry;
    entry = monitor->current;
    if (entry < monitor->end)
    {
        entry->name = "lt";
        _ReadWriteBarrier();
        scratch.shapeEnd.stamp = (unsigned int)__rdtsc();
        _ReadWriteBarrier();
        entry->time = scratch.shapeEnd.stamp;
        monitor->current = (MonitorEntry*)((char*)entry + 12);
    }
    return (void*)(((unsigned int)scratch.outcome.result + 15) & ~15);
}
}  // namespace fnv_00d32cd0

class hkpLinearCastProcessorD334
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual int process(const hkpCdBodyD333* pkBodyA, const hkpCdBodyD333* pkBodyB, int iArg3, int iArg4, float fArg5,
                        int iArg6, hkpGskCacheD333* pkCache, int iArg8, int iArg9) throw();
};

class hkpConvexListLinearCastD334 : public hkpConvexListProcessorD333
{
  public:
    int FUN_00d334c0(const hkpCdBodyD333* a1, const hkpCdBodyD333* a2, int a3, int a4, float a5, int a6,
                     hkpGskCacheD333* a7, int a8, int a9);
};

// Resolves shape collection sub-shapes for both bodies if needed, then delegates to the linear cast processor's process method.
// @fnv 0x00d334c0
int hkpConvexListLinearCastD334::FUN_00d334c0(const hkpCdBodyD333* apBodyA, const hkpCdBodyD333* apBodyB, int a3,
                                              int a4, float a5, int a6, hkpGskCacheD333* apCache, int a8, int a9)
{
    hkpCdBodyD333 wrapper2;
    hkpShapeBufferD333 buffer;
    hkpCdBodyD333 wrapper1;

    const hkpCdBodyD333* bodyA = apBodyA;
    const hkpCdBodyD333* bodyB = apBodyB;

    if (apBodyA->m_pCollisionShape->m_type == 0x16)
    {
        int keyA = apCache->m_kVertices[0] >> 8;
        for (int i = 1; i < apCache->m_ucDimensionA; ++i)
        {
            if ((apCache->m_kVertices[i] >> 8) != keyA)
            {
                m_invalidCache = 1;
                return 1;
            }
        }
        const hkpShapeD333* shape = static_cast<const hkpShapeCollectionD333*>(apBodyA->m_pCollisionShape)
                                        ->m_container.GetShapeForKey(keyA, &buffer);
        wrapper1.m_uiCollisionShapeKey = keyA;
        wrapper1.m_parent = apBodyA;
        wrapper1.m_pMotionState = apBodyA->m_pMotionState;
        wrapper1.m_pCollisionShape = shape;
        bodyA = &wrapper1;
    }

    if (apBodyB->m_pCollisionShape->m_type == 0x16)
    {
        int keyB = apCache->m_kVertices[apCache->m_ucDimensionA] >> 8;
        for (int i = apCache->m_ucDimensionA + 1; i < apCache->m_ucDimensionB + apCache->m_ucDimensionA; ++i)
        {
            if ((apCache->m_kVertices[i] >> 8) != keyB)
            {
                m_invalidCache = 1;
                return 1;
            }
        }
        const hkpShapeD333* shape = static_cast<const hkpShapeCollectionD333*>(apBodyB->m_pCollisionShape)
                                        ->m_container.GetShapeForKey(keyB, &buffer);
        wrapper2.m_parent = apBodyB;
        wrapper2.m_pMotionState = apBodyB->m_pMotionState;
        wrapper2.m_pCollisionShape = shape;
        wrapper2.m_uiCollisionShapeKey = keyB;
        bodyB = &wrapper2;
    }

    return reinterpret_cast<hkpLinearCastProcessorD334*>(m_processor)
        ->process(bodyA, bodyB, a3, a4, a5, a6, apCache, a8, a9);
}
