
// src/havok/physics/dynamics/collide/contactlistener/util/hkpcollisioncallbackutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/collide/contactlistener/util/hkpcollisioncallbackutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FUN_00d0b1e0
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0c;
    int unk10;
    struct Base
    {
        void FUN_00d0b0d0();
    };
    FUN_00d0b1e0(int flags);
};
extern int DAT_0102e388;
extern int DAT_010cb1e4;
extern int DAT_010cb1c4;
extern "C" void* __cdecl FUN_00c85750();
struct CallbackInterface
{
    virtual void f0();
    virtual void f1();
    virtual void callback(void*, unsigned short);
};
struct Manager
{
    int unk00[4];
    CallbackInterface* interface10;
};
// Initializes the object's base subobject and pointers, then if flags bit 0 is set calls callback on the manager's interface with this and unk04.
// @fnv 0x00d0b1e0
FUN_00d0b1e0::FUN_00d0b1e0(int flags)
{
    ((Base*)((char*)this + 0x14))->FUN_00d0b0d0();
    unk0c = &DAT_010cb1c4;
    unk08 = &DAT_010cb1e4;
    unk00 = &DAT_0102e388;
    if (flags & 1)
    {
        Manager* manager = (Manager*)FUN_00c85750();
        manager->interface10->callback(this, unk04);
    }
}

struct CallbackTarget
{
    void FUN_00c91750(void* apValue);
    void FUN_00c91a70(void* apValue);
};

struct OuterRefHolder
{
    int unk00;
    int unk04;
    int unk08;

    void FUN_00c905b0();
};

struct SubEntry
{
    int unk00;

    void FUN_00d9e280(CallbackTarget* apTarget);
};

struct FUN_00d0ae30_cls
{
    int unk00;
    int unk04;
    SubEntry m_08;

    void FUN_00d0ae30(CallbackTarget* apTarget);
};

// @fnv 0x00d0ae30
void FUN_00d0ae30_cls::FUN_00d0ae30(CallbackTarget* apTarget)
{
    m_08.FUN_00d9e280(apTarget);
    apTarget->FUN_00c91750(((char*)this - 0xc) != 0 ? (char*)this - 4 : 0);
    apTarget->FUN_00c91a70(((char*)this - 0xc) != 0 ? (char*)this : 0);
    ((OuterRefHolder*)((char*)this - 0xc))->FUN_00c905b0();
}

extern int DAT_010cb1e4;
extern int DAT_010cb1c4;
extern int DAT_010cd33c;
extern int DAT_010cd31c;
extern int DAT_010cd30c;

struct FUN_00d0b180_sub
{
    void FUN_00d9e860();
};

struct FUN_00d0b180_cls
{
    void* unk00;
    unsigned short unk04;
    unsigned short unk06;
    void* unk08;
    void* unk0c;
    int unk10;
    FUN_00d0b180_sub unk14;
    FUN_00d0b180_cls* Initialize();
};

// Sets the object's fields to point at the given globals, sets unk06 and unk10 to 1, calls FUN_00d9e860 on unk14, and returns this.
// @fnv 0x00d0b180
FUN_00d0b180_cls* FUN_00d0b180_cls::Initialize()
{
    *(volatile unsigned short*)&unk06 = 1;
    *(void* volatile*)&unk08 = &DAT_010cb1e4;
    *(void* volatile*)&unk0c = &DAT_010cb1c4;
    FUN_00d0b180_sub* sub = &unk14;
    unk00 = &DAT_010cd33c;
    unk08 = &DAT_010cd31c;
    unk0c = &DAT_010cd30c;
    unk10 = 1;
    sub->FUN_00d9e860();
    return this;
}

#include <windows.h>
extern "C" void _ReadWriteBarrier(void);

extern DWORD DAT_0126835c;

unsigned __int64 __cdecl __rdtsc(void);

struct ProfRec
{
    const char* m_pName;
    DWORD m_iTick;
    DWORD unk08;
};

struct ProfBuf
{
    DWORD unk00;
    ProfRec* m_pCur;
    DWORD unk08;
    ProfRec* m_pRecordEnd;
};

typedef LPVOID(WINAPI* PFN_TlsGetValue)(DWORD dwTlsIndex);

struct Collider
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int v20();
    void* unk04;
    void* unk08;
    void* GetBase();
};

struct Node
{
    void* unk00;
    void* unk04;
    void* unk08;
};

struct Params
{
    void* unk00;
    void* unk04;
    void* unk08;
    Collider* unk0c;
    void* unk10;
    Node* unk14;
    void* unk18;
};

struct Data
{
    int kind;
    Node* a;
    void* b;
    void* c;
};

extern "C" void __cdecl DispatchCollisionEvents(void* obj, Data* data);
extern "C" void __cdecl FUN_00cfffb0(void* obj, Data* data);

// Records a profiler tick, then if pObj->v20() is 11 calls DispatchCollisionEvents once and FUN_00cfffb0 twice with a Data record, and records an end tick.
// @fnv 0x00d0ae80
void __stdcall FUN_00d0ae80(Params* p)
{
    PFN_TlsGetValue pfnTls = TlsGetValue;
    Data data;
    volatile DWORD tickEnter;
    {
        ProfBuf* pBuf = (ProfBuf*)pfnTls(DAT_0126835c);
        if (pBuf->m_pCur < pBuf->m_pRecordEnd)
        {
            ProfRec* pRec = pBuf->m_pCur;
            pRec->m_pName = "TtCollLtUtil";
            _ReadWriteBarrier();
            tickEnter = (DWORD)__rdtsc();
            pRec->m_iTick = tickEnter;
            pBuf->m_pCur = pRec + 1;
        }
    }

    Collider* pCollider = p->unk0c;
    if (pCollider->v20() == 11)
    {
        data.c = pCollider->GetBase();
        Node* a = p->unk14;
        void* b = p->unk18;
        data.kind = 2;
        data.a = a;
        data.b = b;
        DispatchCollisionEvents(a->unk08, &data);
        data.kind = 0;
        FUN_00cfffb0(a, &data);
        data.kind = 1;
        FUN_00cfffb0(b, &data);
    }

    volatile DWORD tickExit;
    {
        ProfBuf* pBuf = (ProfBuf*)pfnTls(DAT_0126835c);
        if (pBuf->m_pCur < pBuf->m_pRecordEnd)
        {
            ProfRec* pRec = pBuf->m_pCur;
            pRec->m_pName = "Et";
            _ReadWriteBarrier();
            tickExit = (DWORD)__rdtsc();
            pRec->m_iTick = tickExit;
            pBuf->m_pCur = pRec + 1;
        }
    }
}

extern DWORD hkMonitorStreamTls;

struct S_00d0af60_TimerCommand
{
    const char* m_pCommandName;
    unsigned int m_uiStartTicks;
    unsigned int m_uiEndTicks;
};

struct S_00d0af60_MonitorStream
{
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pRayCursor;
    char* m_pCurrentCommand;
};

static inline void S_00d0af60_Timer(const char* name)
{
    S_00d0af60_MonitorStream* s = (S_00d0af60_MonitorStream*)TlsGetValue(hkMonitorStreamTls);
    if (s->m_kRayEnd < s->m_pCurrentCommand)
    {
        S_00d0af60_TimerCommand* h = (S_00d0af60_TimerCommand*)s->m_kRayEnd;
        h->m_pCommandName = name;
        _ReadWriteBarrier();
        volatile unsigned int t = (unsigned int)__rdtsc();
        h->m_uiStartTicks = t;
        s->m_kRayEnd = (char*)(h + 1);
    }
}

struct S_00d0af60_Shape
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual int getType();
    void* FUN_00d92820();
};

struct S_00d0af60_Entity
{
    int unk0;
    int unk4;
    void* unk8;
};

struct S_00d0af60_Event
{
    int m_type;
    S_00d0af60_Entity* m_kPointA;
    S_00d0af60_Entity* m_kPointB;
    void* m_obj;
};

struct S_00d0af60_Input
{
    int unk0;
    int unk4;
    int unk8;
    S_00d0af60_Shape* unkC;
    int unk10;
    S_00d0af60_Entity* unk14;
    S_00d0af60_Entity* unk18;
};

void FUN_00d00de0(void*, S_00d0af60_Event*);
void FUN_00d00060(S_00d0af60_Entity*, S_00d0af60_Event*);

// Between two profiler timers, if the shape's type is 11, builds an event and calls FUN_00d00de0 with a->unk8, then FUN_00d00060 for each entity.
// @fnv 0x00d0af60
void __stdcall FUN_00d0af60(S_00d0af60_Input* in)
{
    S_00d0af60_Timer("TtCollLfUtil");
    S_00d0af60_Shape* shape = in->unkC;
    if (shape->getType() == 11)
    {
        S_00d0af60_Event ev;
        void* obj = shape->FUN_00d92820();
        S_00d0af60_Entity* a = in->unk14;
        S_00d0af60_Entity* b = in->unk18;
        ev.m_obj = obj;
        ev.m_type = 2;
        ev.m_kPointA = a;
        ev.m_kPointB = b;
        FUN_00d00de0(a->unk8, &ev);
        ev.m_type = 0;
        FUN_00d00060(a, &ev);
        ev.m_type = 1;
        FUN_00d00060(b, &ev);
    }
    S_00d0af60_Timer("Et");
}

// sub ecx,8; jmp target: MSVC adjustor thunk for the SecondaryBase slot of a
// class deriving from two bases; PrimaryBase is 8 bytes (vptr + one int).
struct AdjPrimaryBase
{
    virtual void FUN_00d0b1c0();
    int unk04;
};

struct AdjSecondaryBase
{
    virtual void FUN_00d0b1c0();
};

struct AdjDerived : AdjPrimaryBase, AdjSecondaryBase
{
    AdjDerived();
// @fnv 0x00d0b1c0
    virtual void FUN_00d0b1c0();
};

AdjDerived::AdjDerived()
{}

// sub ecx,0xc; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (0xc).
struct PrimaryBase
{
    virtual void FUN_00d0b1d0();
    int unk04;
    int unk08;
};

struct SecondaryBase
{
    virtual void FUN_00d0b1d0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d0b1d0
    virtual void FUN_00d0b1d0();
};

Derived::Derived()
{}

namespace fnv_00d0b040 {
struct hkMemory
{
    virtual void unk00();
    virtual void* allocateChunk(int size);
};

struct hkThreadMemory
{
    char pad00[0x10];
    hkMemory* m_pMemoryAllocator;
};

extern "C" hkThreadMemory* __cdecl FUN_00c85750();

struct SubObj
{
    void __thiscall PassObjectToTarget(void* obj);
};

struct hkpCollisionCallbackUtil
{
    char pad00[4];
    unsigned short m_usMemSizeAndFlags;
    char pad06[2];
    void* field_08;
    void* field_0C;
    int m_sReferenceCount;
    SubObj field_14;

    hkpCollisionCallbackUtil* __thiscall Initialize();
};

struct TargetClass
{
    char pad00[0x1c0];
    hkpCollisionCallbackUtil* m_pCallbackData;

    void __thiscall FUN_00c93a60(void* p);
    void __thiscall FUN_00c937e0(void* p);
};

// Increments the reference count of m_pCallbackData if present, otherwise allocates a 0x4c chunk, initializes it, and wires it into the object.
// @fnv 0x00d0b040
void __cdecl FUN_00d0b040(TargetClass* obj)
{
    hkpCollisionCallbackUtil* util = obj->m_pCallbackData;
    if (util)
    {
        util->m_sReferenceCount++;
        return;
    }

    hkThreadMemory* threadMem = FUN_00c85750();
    hkpCollisionCallbackUtil* mem = (hkpCollisionCallbackUtil*)threadMem->m_pMemoryAllocator->allocateChunk(0x4c);
    mem->m_usMemSizeAndFlags = 0x4c;
    util = mem->Initialize();
    obj->m_pCallbackData = util;

    obj->FUN_00c93a60(util ? &util->field_0C : 0);
    obj->FUN_00c937e0(util ? &util->field_08 : 0);
    util->field_14.PassObjectToTarget(obj);
}
}  // namespace fnv_00d0b040
