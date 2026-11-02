
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpmidphaseviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpmidphaseviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct FullObject;
struct Receiver;

struct HeadPart
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct FirstBase
{
    int unk00;
    int unk04;
    void FUN_00d6a250(Receiver* apReceiver);
};

struct SecondBase
{
    int unk00;
};

struct FullObject : HeadPart, FirstBase, SecondBase
{
};

typedef char _check_offsets[sizeof(FullObject) == 0x2c ? 1 : -1];

struct Receiver
{
    void ClearValue(SecondBase* apObject);
};

// Passes the enclosing FullObject (this minus 0x20) to the receiver's ClearValue.
// @fnv 0x00d6a250
void FirstBase::FUN_00d6a250(Receiver* apReceiver)
{
    apReceiver->ClearValue((FullObject*)((char*)this - 0x20));
}

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
    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
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
    __forceinline ~hkArray() throw()
    {
        _clearAndDeallocate(FUN_00c85750()->heap());
    }
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
    virtual ~S_00d6a750_Listener() throw()
    {}
};
struct FUN_00d6a750 : S_00d6a750_Base0, S_00d6a750_Base1, S_00d6a750_Base2, S_00d6a750_Listener
{
    hkArray<S_00d6a750_Element> m_elements;
    ~FUN_00d6a750();
};
// @fnv 0x00d6a750
FUN_00d6a750::~FUN_00d6a750()
{
    if (m_pSharedOwner)
    {
        for (int i = 0; i < m_pSharedOwner->m_iNumSources; i++)
            m_pSharedOwner->m_ppSources[i]->ClearValue(this);
    }
}

namespace fnv_00d6a810 {
struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct AudioMgr
{
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

struct RefObj
{
    void* vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

struct Obj : RefObj
{
    int pad[12];
    Obj* FUN_00d6a280(int);
};

inline void* hkAlloc(int n)
{
    RefObj* p = (RefObj*)audio()->heap().AllocateMemoryBlock(n);
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}

// @fnv 0x00d6a810
void* __cdecl FUN_00d6a810(int a)
{
    Obj* o = ((Obj*)hkAlloc(sizeof(Obj)))->FUN_00d6a280(a);
    return o ? (char*)o + 8 : 0;
}
}  // namespace fnv_00d6a810

struct Registry_00dd9380
{
    void* Register(const char* name, void (*fn)());
};

extern Registry_00dd9380* DAT_01269cd0;
extern char DAT_010d22e0[];
extern void* DAT_01269024;
void FUN_00d6a810();

// @fnv 0x00d6a850
void FUN_00d6a850()
{
    DAT_01269024 = DAT_01269cd0->Register(DAT_010d22e0, FUN_00d6a810);
}

struct Target
{
    int Handle(void* apValue);
};

struct FUN_00d6a220_cls
{
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

// @fnv 0x00d6a220
int FUN_00d6a220_cls::HandleWithSelfOffset(Target* apTarget)
{
    return apTarget->Handle(((char*)this - 0x20) != 0 ? (char*)this + 8 : 0);
}

struct S_d6a280_Elem;

struct S_d6a280_Owner
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
    S_d6a280_Elem** m_items;
    int m_uiItemCount;
};

struct S_d6a280_P0
{
    virtual void a0();
    int unk04;
};

struct S_d6a280_P8
{
    virtual void a8();
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct S_d6a280_P20
{
    virtual void a20();
    S_d6a280_Owner* m_24;
};

struct FUN_00ddccb0 : S_d6a280_P0, S_d6a280_P8, S_d6a280_P20
{
    FUN_00ddccb0(int a);
};

struct S_d6a280_Arr
{
    void* m_data;
    int m_iElementCount;
    unsigned int m_cap;
    __forceinline S_d6a280_Arr() : m_data(0), m_iElementCount(0), m_cap(0x80000000u)
    {}
};

struct S_d6a280_Mx
{
    virtual void m0();
    __forceinline S_d6a280_Mx()
    {}
};

struct S_d6a280_Elem
{
    void FUN_00c93920(S_d6a280_Mx* m);
};

struct FUN_00d6a280 : FUN_00ddccb0, S_d6a280_Mx
{
    S_d6a280_Arr m_aiIndexedValues;
    virtual void m0();
    virtual void a0();
    virtual void a8();
    virtual void a20();
    FUN_00d6a280(int a);
};

// Constructs the base with a, then calls FUN_00c93920 on each item of m_24's m_items array, passing this.
// @fnv 0x00d6a280
FUN_00d6a280::FUN_00d6a280(int a) : FUN_00ddccb0(a)
{
    if (m_24 != 0)
    {
        for (int i = 0; i < m_24->m_uiItemCount; i++)
            m_24->m_items[i]->FUN_00c93920((S_d6a280_Mx*)this);
    }
}

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
{}

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

struct AdjustorPrimaryBase
{
    int m_00;  // +0x04
    AdjustorPrimaryBase();
    virtual void FUN_00d6a890(int flag);
};

struct AdjustorSecondaryBase
{
    AdjustorSecondaryBase();
    virtual void FUN_00d6a890(int flag);
};

struct AdjustorDerived : public AdjustorPrimaryBase, public AdjustorSecondaryBase
{
    AdjustorDerived();
// @fnv 0x00d6a890
    virtual void FUN_00d6a890(int flag);
};

AdjustorPrimaryBase::AdjustorPrimaryBase() : m_00(0)
{}
AdjustorSecondaryBase::AdjustorSecondaryBase()
{}
AdjustorDerived::AdjustorDerived()
{}

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
struct hkpShape
{
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
struct hkpMidphaseViewerBase
{
    hkpMidphaseViewerBase();
// @fnv 0x00d6a8a0
    virtual void FUN_00d6a8a0();
};

struct hkpMidphaseViewer : public hkpShape, public hkpMidphaseViewerBase
{
    hkpMidphaseViewer();
    virtual void FUN_00d6a8a0();  // declared, never defined
};

hkpMidphaseViewer::hkpMidphaseViewer() : hkpShape(), hkpMidphaseViewerBase()
{}

namespace fnv_00d6a870 {
extern int DAT_01269024;

// @fnv 0x00d6a870
int __cdecl FUN_00d6a870()
{
    return DAT_01269024;
}
}  // namespace fnv_00d6a870

namespace fnv_00d6a8b0 {
// FUN_00d6a8b0 - hkpMidphaseViewer: tears the viewer down and, when the
// deleting flag is set, unregisters it from the physics world.
struct hkpWorldViewerRegistry
{
    virtual void v0();
    virtual void v1();
    virtual void removeViewer(void* viewer, unsigned short viewerId);
};

struct hkpPhysicsWorld
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    hkpWorldViewerRegistry* unk10;
};

extern hkpPhysicsWorld* FUN_00c85750();

struct hkpMidphaseViewer
{
    void* unk00;
    unsigned short unk04;
    void FUN_00d6a750();
    void* FUN_00d6a8b0(int flags);
};

// Calls FUN_00d6a750, then if flags & 1 removes this viewer from the physics world registry, and returns this.
// @fnv 0x00d6a8b0
void* hkpMidphaseViewer::FUN_00d6a8b0(int flags)
{
    FUN_00d6a750();
    if (flags & 1)
    {
        hkpPhysicsWorld* world = FUN_00c85750();
        world->unk10->removeViewer(this, unk04);
    }
    return this;
}
}  // namespace fnv_00d6a8b0
