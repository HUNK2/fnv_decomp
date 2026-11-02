
// src/havok/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/vehicle/hkpvehicleviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct D625A0Allocator;

void __cdecl FUN_00c908c0(D625A0Allocator* alloc, void* array, int numElements, int sizeElem);
void __cdecl D625A0MemMove(void* dst, const void* src, unsigned int nbytes);

struct D625A0CharArray
{
    char* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    void ReplaceRange(D625A0Allocator& alloc, int index, int numdel, const char* p, int numtoinsert);
};

// @fnv 0x00d625a0
void D625A0CharArray::ReplaceRange(D625A0Allocator& alloc, int index, int aiNumDelete, const char* apSource,
                                   int aiNumInsert)
{
    int iNewLength = m_iElementCount - aiNumDelete + aiNumInsert;
    int numtomove = m_iElementCount - index - aiNumDelete;
    const int iCapacity = getCapacity();
    if (iCapacity < iNewLength)
    {
        int iDoubledCapacity = 2 * iCapacity;
        int iNewCapacity = (iNewLength < iDoubledCapacity) ? iDoubledCapacity : iNewLength;
        FUN_00c908c0(&alloc, this, iNewCapacity, sizeof(char));
    }
    D625A0MemMove(m_data + index + aiNumInsert, m_data + index + aiNumDelete, numtomove * sizeof(char));
    char* dst = m_data + index;
    for (int i = 0; i < aiNumInsert; ++i)
        dst[i] = apSource[i];
    m_iElementCount = iNewLength;
}

extern char d_010d17d0;
// @fnv 0x00d634d0
char* FUN_00d634d0()
{
    return &d_010d17d0;
}

struct ItemSink;

typedef void(__thiscall* ProcessFn)(ItemSink* apThis, void* apItem);

struct ItemSinkVtbl
{
    void* fn00;
    ProcessFn Process;
};

struct ItemSink
{
    ItemSinkVtbl* m_pVtbl;
};

struct ItemHolder
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
    void** m_ppItems;
    int m_iArrayLength;
};

struct FUN_00d634e0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    ItemSink m_kSink;
    ItemHolder* m_pHolder;

    void ProcessItems();
};

// Iterates m_pHolder's items and passes each to the sink's Process callback when m_pHolder is non-null.
// @fnv 0x00d634e0
void FUN_00d634e0_cls::ProcessItems()
{
    if (m_pHolder != 0)
    {
        for (int i = 0; i < m_pHolder->m_iArrayLength; i++)
            m_kSink.m_pVtbl->Process(&m_kSink, m_pHolder->m_ppItems[i]);
    }
}

struct HeadPart
{
    virtual void h00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
};

struct OurPart
{
    virtual void o00();

    int m_i04;

    void RegisterAndNotify(struct Registry* apRegistry);
};

struct NotifyTarget
{
    virtual void v00();
    virtual void Notify(void* apItem);
};

struct SecondTarget
{
    virtual void w00();
};

struct Container : HeadPart, OurPart, NotifyTarget, SecondTarget
{
};

struct ItemList
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void** m_ppItems;
    int m_iArrayLength;

    void FUN_00c905b0();
};

struct Registry
{
    void FUN_00c937a0(NotifyTarget* apTarget);
    void FUN_00c93920(SecondTarget* apTarget);
    ItemList* FUN_00c929e0();
};

// @fnv 0x00d63520
void OurPart::RegisterAndNotify(Registry* apRegistry)
{
    apRegistry->FUN_00c937a0((Container*)((char*)this - 0x20));
    apRegistry->FUN_00c93920((Container*)((char*)this - 0x20));

    ItemList* pItemList = apRegistry->FUN_00c929e0();
    for (int i = 0; i < pItemList->m_iArrayLength; i++)
        ((NotifyTarget*)((char*)this + 8))->Notify(pItemList->m_ppItems[i]);

    pItemList->FUN_00c905b0();
}

struct Factory
{
    void* FUN_00dd9380(const char*, void*);
};
extern void* DAT_01268fcc;
extern Factory* DAT_01269cd0;
extern const char DAT_010d17c4;
extern void AllocAndInitObject();
// @fnv 0x00d63da0
void __cdecl FUN_00d63da0()
{
    DAT_01268fcc = DAT_01269cd0->FUN_00dd9380(&DAT_010d17c4, (void*)AllocAndInitObject);
}

extern int g_D63DC0Value;

// @fnv 0x00d63dc0
int __cdecl FUN_00d63dc0()
{
    return g_D63DC0Value;
}

// PassMembersToTarget - forwarding stub for a "container of" style object.
//
// `this` points at a sub-object that lives 0x20 bytes into a bigger object;
// the code recovers the owner pointer (this - 0x20) and passes it on to the
// two Target methods, which are called with the owner as their `this`.
struct Target
{
    void FUN_00c91700(void* apArg);
    void ClearValue(void* apArg);
};

struct FUN_00d63480_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;

    void PassMembersToTarget(Target* apTarget);
};

// Passes pointers to this object's members at offsets 8 and 0xc to the target's two callbacks, or null if the owner pointer is null.
// @fnv 0x00d63480
void FUN_00d63480_cls::PassMembersToTarget(Target* apTarget)
{
    char* pOwner = (char*)this - 0x20;
    apTarget->FUN_00c91700(pOwner ? (void*)((char*)this + 8) : (void*)0);
    apTarget->ClearValue(pOwner ? (void*)((char*)this + 0xc) : (void*)0);
}

// FUN_00d63c50 - the constructor of the Havok vehicle viewer
// (hkpVehicleViewer).
//
// The base class constructor (hkpWorldViewerBase) is called first with the
// argument that was passed in; afterwards the vtable pointer of the two
// listener bases and the vtable pointers of the viewer's own five base
// sub-objects are stored, and the last three members are initialised.
struct ViewerArg
{
    int unk00;
    int unk04;
};

// hkpWorldViewerBase - its constructor is not defined here, so the call stays
// an external reference and the checker binds it from the original's bytes.
struct WorldViewerBase
{
    WorldViewerBase(ViewerArg* arg);
    int* m_vtbl00;  // +0x00
    int unk04;      // +0x04
    int* m_vtbl08;  // +0x08
    int unk0c;      // +0x0c
    int unk10;      // +0x10
    int unk14;      // +0x14
    int unk18;      // +0x18
    int unk1c;      // +0x1c
    int* m_vtbl20;  // +0x20
    int unk24;      // +0x24
};

struct FUN_00d63c50 : public WorldViewerBase
{
    FUN_00d63c50(ViewerArg* arg);
    int* volatile m_vtbl28;  // +0x28
    int* volatile m_vtbl2c;  // +0x2c
    volatile int m_30;       // +0x30
    volatile int m_34;       // +0x34
    volatile int m_38;       // +0x38
};

// the vftables of the class and of its bases
extern int DAT_010cb1d4;
extern int DAT_010ccf7c;
extern int DAT_010d1854;
extern int DAT_010d1834;
extern int DAT_010d1824;
extern int DAT_010d1814;
extern int DAT_010d1804;

// @fnv 0x00d63c50
FUN_00d63c50::FUN_00d63c50(ViewerArg* arg) : WorldViewerBase(arg)
{
    m_vtbl28 = &DAT_010cb1d4;
    m_vtbl2c = &DAT_010ccf7c;
    m_vtbl00 = &DAT_010d1854;
    m_vtbl08 = &DAT_010d1834;
    m_vtbl20 = &DAT_010d1824;
    m_vtbl28 = &DAT_010d1814;
    m_vtbl2c = &DAT_010d1804;
    m_30 = 0;
    m_34 = 0;
    m_38 = 0x80000000;
}

struct S_Heap
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void ReturnMemory(void* p, int n) throw();
};
struct S_Holder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    S_Heap* m10;
    S_Heap& heap()
    {
        return *m10;
    }
};
void* __cdecl FUN_00c85750() throw();
struct S_P
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
    void** m6c;
    int m70;
};
struct S_B0
{
    virtual void b0v0();
    int unk04;
};
struct S_B8
{
    virtual void b8v0();
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
};
struct S_B20
{
    virtual void b20v0();
    void PassMembersToTarget(void* child);
};
struct FUN_00ddcc60 : S_B0, S_B8, S_B20
{
    S_P* m24;
    virtual ~FUN_00ddcc60() throw();
};
struct S_D
{
    virtual ~S_D() throw()
    {}
};
struct S_E
{
    virtual ~S_E() throw()
    {}
};
struct S_Arr
{
    void** m_data;
    int m_iElementCount;
    int m_cap;
    __forceinline void clear() throw()
    {
        S_Heap& heap = ((S_Holder*)FUN_00c85750())->heap();
        m_iElementCount = 0;
        if ((m_cap & 0x80000000) == 0)
            heap.ReturnMemory(m_data, (m_cap & 0x3fffffff) * (int)sizeof(void*));
        m_data = 0;
        m_cap = 0x80000000;
    }
};
struct FUN_00d63cb0 : FUN_00ddcc60, S_D, S_E
{
    S_Arr m30;
    virtual ~FUN_00d63cb0() throw();
};
// Destroys the object: calls PassMembersToTarget on each of m24->m6c up to m24->m70, then clears m30.
// @fnv 0x00d63cb0
FUN_00d63cb0::~FUN_00d63cb0() throw()
{
    if (m24)
    {
        for (int i = 0; i < m24->m70; i++)
            ((S_B20*)this)->PassMembersToTarget(m24->m6c[i]);
    }
    m30.clear();
}

namespace fnv_00d63d60 {
struct AllocIface
{
    virtual void* unk00();
    virtual void* Alloc(unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AllocIface* m_pAllocator;
};

AllocHolder* __cdecl FUN_00c85750() throw();

struct FUN_00d63d60_obj
{
    int unk00;
    unsigned short m_wSize;
    unsigned short m_u06;

    void* FUN_00d63c50(int a1);
};

// Allocates a 0x3c-byte object via the global allocator, sets its size, calls FUN_00d63c50(a1), and returns the result offset by 8 or null.
// @fnv 0x00d63d60
void* AllocAndInitObject(int a1)
{
    AllocHolder* pAllocHolder = reinterpret_cast<AllocHolder*>(FUN_00c85750());
    FUN_00d63d60_obj* obj = reinterpret_cast<FUN_00d63d60_obj*>(pAllocHolder->m_pAllocator->Alloc(0x3c));
    obj->m_wSize = 0x3c;
    void* pResult = obj->FUN_00d63c50(a1);
    if (pResult != 0)
    {
        return (char*)pResult + 8;
    }
    return 0;
}
}  // namespace fnv_00d63d60

namespace fnv_00d63e10 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize) throw();
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750() throw();

struct FUN_00d63e10_cls
{
    int unk00;
    unsigned short m_uSize;
    unsigned short m_u06;

    void FUN_00d63cb0();

    FUN_00d63e10_cls* Destroy(unsigned char acFlags);
    static void operator delete(void* apMemory) throw();
};

// @fnv 0x00d63e10
FUN_00d63e10_cls* FUN_00d63e10_cls::Destroy(unsigned char acFlags)
{
    FUN_00d63cb0();
    if (acFlags & 1)
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(this, m_uSize);
    }
    return this;
}
}  // namespace fnv_00d63e10

class hkMemoryAllocatorD635;

struct hkMemoryRouterD635
{
    int unk00, unk04, unk08, unk0C;
    hkMemoryAllocatorD635* m_pStreamAllocator;
    hkMemoryAllocatorD635& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkD635 {
extern "C" hkMemoryRouterD635& __cdecl FUN_00c85750() throw();
}

void __cdecl ResizeAudioStream(void* pvAlloc, void* apvArray, int iSizeElem) throw();

struct hkBoolD635
{
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkClassD635
{
  public:
    hkBoolD635 FUN_00d46d80(const hkClassD635& k) const throw();
};

class hkReferencedObjectD635
{
  public:
    void FUN_00c90510() throw();
};

class hkClassNameRegistryD635
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual const hkClassD635* GetClassByName(const char* className) const;
};

class hkVtableClassRegistryD635
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual const hkClassD635* GetClassFromVirtualInstance(const void* obj) const;
};

class hkBuiltinTypeRegistryD635
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual hkClassNameRegistryD635* GetClassNameRegistry();
    virtual hkVtableClassRegistryD635* GetVtableClassRegistry();
};

namespace hkD635 {
extern hkBuiltinTypeRegistryD635* DAT_01268b08;
}

template <class T> class hkArrayD635
{
  public:
    __forceinline void AddBack(const T& t)
    {
        _pushBack(hkD635::FUN_00c85750(), t);
    }
    __forceinline void _pushBack(hkMemoryRouterD635& router, const T& t)
    {
        if (m_iElementCount == (m_iCapacityState & 0x3fffffff))
            ResizeAudioStream(&router.heap(), this, sizeof(T));
        constructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    static __forceinline void constructWithCopy(T* p, int n, const T& tcopy)
    {
        for (int i = 0; i < n; ++i)
            p[i] = tcopy;
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

class VehicleViewerD635
{
  public:
    void AddVehicle(hkReferencedObjectD635* pkObj);

    int unk00, unk04;
    hkArrayD635<hkReferencedObjectD635*> m_ppVehicles;
};

// Looks up a class by name and pkObj's class by vtable; if both exist and FUN_00d46d80 is true, calls FUN_00c90510 on pkObj and appends it to m_ppVehicles.
// @fnv 0x00d635e0
void VehicleViewerD635::AddVehicle(hkReferencedObjectD635* pkObj)
{
    hkBuiltinTypeRegistryD635* pkReg = hkD635::DAT_01268b08;
    const hkClassD635* pkVehicleClass = pkReg->GetClassNameRegistry()->GetClassByName(&d_010d17d0);
    const hkClassD635* pkObjClass = pkReg->GetVtableClassRegistry()->GetClassFromVirtualInstance(pkObj);
    if (pkVehicleClass && pkObjClass && pkVehicleClass->FUN_00d46d80(*pkObjClass))
    {
        pkObj->FUN_00c90510();
        m_ppVehicles.AddBack(pkObj);
    }
}

// VC9 adjustor thunk: dual-slot override + static global forces
// [thunk]: TO::FUN_00d63dd0`adjustor{32}' = sub ecx,0x20; jmp TO::FUN_00d63dd0
struct Prim
{
    virtual void FUN_00d63dd0();
    int p04;
    int p08;
    int p0c;
    int p10;
    int p14;
    int p18;
    int p1c;
};

struct B1
{
    virtual void FUN_00d63dd0();
};

struct TO : Prim, B1
{
// @fnv 0x00d63dd0
    virtual void FUN_00d63dd0();
};

static TO g_thunk;

// sub ecx,8; jmp Destroy
// MSVC adjustor thunk: a class derives from two bases that both declare the same
// virtual, so the secondary base's vtable entry is an adjustor thunk that moves
// `this` back by the size of the primary base (8 = vptr + one int field).
struct PrimaryBase
{
    virtual void FUN_00d63de0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d63de0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d63de0
    virtual void FUN_00d63de0();
};

Derived::Derived()
{}

struct Parent;
struct FirstBase
{
    virtual Parent* FUN_00d63df0(unsigned int flags) = 0;
    unsigned int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
};
struct Receiver
{
    virtual Parent* FUN_00d63df0(unsigned int flags) = 0;
};
struct Parent : FirstBase, Receiver
{
    Parent();
// @fnv 0x00d63df0
    virtual Parent* FUN_00d63df0(unsigned int flags);
};
Parent::Parent()
{}

// FUN_00d63e00 : MSVC this-adjusting thunk  (sub ecx, 0x2c ; jmp <impl>)
struct A1_00d63e00
{
    A1_00d63e00();
    virtual void FUN_00d63e00();
    char pad[0x28];
};
struct A2_00d63e00
{
    A2_00d63e00();
    virtual void FUN_00d63e00();
};
struct Own_00d63e00 : A1_00d63e00, A2_00d63e00
{
    Own_00d63e00();
    virtual void key_fn();
// @fnv 0x00d63e00
    void FUN_00d63e00();
};
Own_00d63e00::Own_00d63e00()
{}
void Own_00d63e00::key_fn()
{}
Own_00d63e00* make_00d63e00()
{
    static Own_00d63e00 o;
    return &o;
}

struct D63590Array
{
    unsigned int* m_data;
    int m_iElementCount;

    int indexOf(unsigned int value) const
    {
        for (int i = 0; i < m_iElementCount; ++i)
        {
            if (m_data[i] == value)
                return i;
        }
        return -1;
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            m_data[index] = m_data[m_iElementCount];
    }
};

class D63590List
{
  public:
    int unk00;
    int unk04;
    D63590Array m_items;

    void FUN_00d63590(unsigned int value);
};

// Finds value in m_items, removes it at that index, and calls FUN_00c905b0 on the ItemList.
// @fnv 0x00d63590
void D63590List::FUN_00d63590(unsigned int value)
{
    int index = m_items.indexOf(value);
    if (index != -1)
    {
        m_items.removeAt(index);
        ((ItemList*)value)->FUN_00c905b0();
    }
}
