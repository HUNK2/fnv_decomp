
// src/havok/common/visualize/hkserverprocesshandler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkserverprocesshandler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern int DAT_010d1508;
void __cdecl Deallocate(void*);
struct FUN_00d60bb0
{
    int* m_p;
    FUN_00d60bb0(unsigned char);
};
// @fnv 0x00d60bb0
FUN_00d60bb0::FUN_00d60bb0(unsigned char p)
{
    m_p = &DAT_010d1508;
    if (p & 1)
        Deallocate(this);
}

extern "C" void* DAT_011b5d38;

// @fnv 0x00d60bf0
void __stdcall FUN_00d60bf0(void** ppOut, void** b)
{
    *ppOut = &DAT_011b5d38;
    *(int*)b = 2;
}

struct FUN_00d605d0_s
{
    void WriteUint8(unsigned char);
};
struct FUN_00d60920_s
{
    void AssignInteger(int);
};
struct FUN_00d60940_s
{
    void WriteInt32(int);
};
struct FUN_00d607b0_s
{
    void writeVec(int, int);
};
struct FUN_00d60ca0_s
{
    int FUN_00d60ca0(int a, int b);
};
int __cdecl FUN_00cb10d0(int);
// @fnv 0x00d60ca0
int FUN_00d60ca0_s::FUN_00d60ca0(int a, int b)
{
    int iClamped = FUN_00cb10d0(a);
    if (iClamped > 0xffff)
        iClamped = 0xffff;
    ((FUN_00d60940_s*)*(void**)((char*)this + 0x10))->WriteInt32(iClamped + 7);
    ((FUN_00d605d0_s*)*(void**)((char*)this + 0x10))->WriteUint8(0xc0);
    ((FUN_00d60940_s*)*(void**)((char*)this + 0x10))->WriteInt32(b);
    ((FUN_00d60920_s*)*(void**)((char*)this + 0x10))->AssignInteger(iClamped);
    ((FUN_00d607b0_s*)*(void**)((char*)this + 0x10))->writeVec(a, iClamped);
    return 0;
}

struct FUN_00d60940_Class
{
    void WriteInt(unsigned int);
};
struct FUN_00d605d0_Class
{
    void FUN_00d605d0(unsigned int);
};
struct FUN_00d60d10_Class
{
    int* m_p;
    int FUN_00d60d10(unsigned int a);
};
// @fnv 0x00d60d10
int FUN_00d60d10_Class::FUN_00d60d10(unsigned int a)
{
    ((FUN_00d60940_Class*)(*(int**)((char*)this + 0x10)))->WriteInt(5);
    ((FUN_00d605d0_Class*)(*(int**)((char*)this + 0x10)))->FUN_00d605d0(0xc1);
    ((FUN_00d60940_Class*)(*(int**)((char*)this + 0x10)))->WriteInt(a);
    return 0;
}

struct FUN_00ddac60_Obj
{
    unsigned char* __thiscall GetStreamResult(void*);
};

struct FUN_00ddacd0_shell : FUN_00ddac60_Obj
{
    void __thiscall FUN_00dd8fe0(void*, int, int);
};

struct FUN_00d60c10_VirtualBase
{
    virtual void FUN_00d60c10_v0();
    virtual void FUN_00d60c10_v1();
    virtual void FUN_00d60c10_v2();
    virtual void FUN_00d60c10_v3();
    virtual void FUN_00d60c10_v4();
    virtual void FUN_00d60c10_v5(int);
    virtual void FUN_00d60c10_v6(int);
};

struct FUN_00d60c10_s
{
    int m_unused1;
    int m_unused2;
    FUN_00ddacd0_shell* m_pArchive;

    void HandleCommand(unsigned char);
};

// @fnv 0x00d60c10
void FUN_00d60c10_s::HandleCommand(unsigned char ucCommand)
{
    switch (ucCommand)
    {
    case 0xc3: {
        int iValue;

        m_pArchive->FUN_00dd8fe0(&iValue, 4, 1);
        if (*m_pArchive->GetStreamResult(&ucCommand))
            ((FUN_00d60c10_VirtualBase*)((char*)this - 4))->FUN_00d60c10_v6(iValue);
        break;
    }

    case 0xc2: {
        unsigned char ucStatus;
        int iValue;

        m_pArchive->FUN_00dd8fe0(&iValue, 4, 1);
        if (*m_pArchive->GetStreamResult(&ucStatus))
            ((FUN_00d60c10_VirtualBase*)((char*)this - 4))->FUN_00d60c10_v5(iValue);
        break;
    }
    }
}

struct FUN_00d60d40_Element
{
    virtual void FUN_00d60d40_Dummy();
    virtual int FUN_00d60d40_GetValue();
};

// Empty virtual function body; does nothing.
// @fnv 0x00d60d40
inline void FUN_00d60d40_Element::FUN_00d60d40_Dummy()
{}

inline int FUN_00d60d40_Element::FUN_00d60d40_GetValue()
{
    return 0;
}

struct FUN_00d60d40_Class
{
    unsigned char m_auiShapeKeys[0x38];
    FUN_00d60d40_Element** m_p;
    int m_uiItemCount;

    int FUN_00d60d40(int value);
};

int FUN_00d60d40_Class::FUN_00d60d40(int value)
{
    int count = m_uiItemCount;
    int index = 0;
    while (index < count)
    {
        if (m_p[index]->FUN_00d60d40_GetValue() == value)
            return index;
        ++index;
    }
    return -1;
}

extern int DAT_01269cd0;
struct FUN_00dd9270_Class
{
    void FindEntry();
};
// @fnv 0x00d61240
void __cdecl FUN_00d61240()
{
    ((FUN_00dd9270_Class*)DAT_01269cd0)->FindEntry();
}

struct FUN_00d61260_Class
{
    void* m_p;
    unsigned short m_iElementCount;

    void FUN_00d610e0();
    void* FUN_00d61260(int flags);
};

struct FUN_00d61260_MemoryManager
{
    virtual void FUN_00d61260_0();
    virtual void FUN_00d61260_1();
    virtual void Deallocate(void* p, unsigned short size);
};

struct FUN_00d61260_Router
{
    void* m_p[4];
    FUN_00d61260_MemoryManager* m_pMemoryManager;
};

FUN_00d61260_Router* __cdecl _D1A0E0GetMemoryRouter();

// @fnv 0x00d61260
void* FUN_00d61260_Class::FUN_00d61260(int flags)
{
    FUN_00d610e0();

    if (flags & 1)
    {
        FUN_00d61260_Router* router = _D1A0E0GetMemoryRouter();
        router->m_pMemoryManager->Deallocate(this, m_iElementCount);
    }

    return this;
}

extern int DAT_01268fb8;

// @fnv 0x00d61210
int __cdecl FUN_00d61210()
{
    return DAT_01268fb8;
}

class hkBaseD60B
{
  public:
    virtual ~hkBaseD60B() throw()
    {}
};

class hkObjD60B : public hkBaseD60B
{
  public:
    hkObjD60B* FUN_00d60bd0(unsigned int uiFlags) throw();
};

// @fnv 0x00d60bd0
hkObjD60B* hkObjD60B::FUN_00d60bd0(unsigned int uiFlags) throw()
{
    this->hkBaseD60B::~hkBaseD60B();
    if (uiFlags & 1)
        Deallocate(this);
    return this;
}

struct hkEntryD60D
{
    unsigned int m_name;
    int unk04;
    int unk08;
};

struct hkEntryArrayD60D
{
    hkEntryD60D* m_data;
    int m_iElementCount;
};

struct hkRegistryD60D
{
    int unk00;
    int unk04;
    int unk08;
    hkEntryArrayD60D m_entries;
};

struct hkVisitorD60D
{
    virtual void v00();
    virtual void v04(const char* name, int index);
};

struct hkObjD60D
{
    int unk00;
    int unk04;
    hkVisitorD60D m_visitor;

    int VisitEntryNames();
};

// Iterates the registry entry array and calls the visitor's v04 with each entry's name pointer and index, then returns 0.
// @fnv 0x00d60d80
int hkObjD60D::VisitEntryNames()
{
    hkEntryArrayD60D& entries = reinterpret_cast<hkRegistryD60D*>(DAT_01269cd0)->m_entries;
    for (int i = 0; i < entries.m_iElementCount; i++)
        m_visitor.v04((const char*)(entries.m_data[i].m_name & ~1u), i);
    return 0;
}

struct FUN_00d60dd0_Elem
{
    virtual void FUN_00d60dd0_v0();
    virtual void FUN_00d60dd0_v1();
    virtual void FUN_00d60dd0_v2();
    virtual void FUN_00d60dd0_v3();
    virtual void FUN_00d60dd0_v4();
    virtual void FUN_00d60dd0_v5();
    virtual void FUN_00d60dd0_v6(float f);
};

struct FUN_00dd9660_Class
{
    void ReadCommands(float* p, void* obj);
};

struct FUN_00d60dd0_Class
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    void* unk10;
    void* unk14;
    FUN_00dd9660_Class unk18;
    void* unk1c;
    void* unk20;
    void* unk24;
    void* unk28;
    FUN_00d60dd0_Elem** unk2c;
    int unk30;

    void ApplyToElements(float f);
};

// Calls FUN_00d60dd0_v6(f) on each element in unk2c in reverse order, then passes f and unk08 to unk18.ReadCommands if unk08 is set.
// @fnv 0x00d60dd0
void FUN_00d60dd0_Class::ApplyToElements(float afValue)
{
    for (int i = unk30 - 1; i >= 0; i--)
    {
        unk2c[i]->FUN_00d60dd0_v6(afValue);
    }
    if (unk08)
    {
        unk18.ReadCommands(&afValue, unk08);
    }
}

extern int DAT_0102e388;

class hkMemoryAllocatorD610
{
  public:
    virtual void V0() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void V3() throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD610
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD610* m_pStreamAllocator;
    hkMemoryAllocatorD610& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterD610& __cdecl FUN_00c85750();

template <class T> class hkArrayD610
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    ~hkArrayD610() throw()
    {
        hkMemoryAllocatorD610& kHeap = FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kHeap.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkMapBaseD610
{
  public:
    void* m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;

    ~hkMapBaseD610() throw()
    {
        FUN_00a29680();
    }
    void ProcessArgument(hkMemoryAllocatorD610& kAlloc) throw();
    void FUN_00a29680() throw();
};

class hkPointerMapD610
{
  public:
    hkMapBaseD610 m_map;

    ~hkPointerMapD610() throw()
    {
        m_map.ProcessArgument(FUN_00c85750().heap());
    }
};

class hkReferencedObjectD610
{
  public:
    virtual ~hkReferencedObjectD610() throw()
    {
        *reinterpret_cast<int**>(this) = &DAT_0102e388;
    }
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkInterfaceAD610
{
  public:
    virtual ~hkInterfaceAD610() throw()
    {}
};

class hkInterfaceBD610
{
  public:
    virtual ~hkInterfaceBD610() throw()
    {}
    int unk04;
};

class hkOwnedD610
{
  public:
    virtual ~hkOwnedD610() throw();
};

class FUN_00d610e0 : public hkReferencedObjectD610, public hkInterfaceAD610, public hkInterfaceBD610
{
  public:
    virtual ~FUN_00d610e0() throw();

    hkOwnedD610* m_14;
    hkOwnedD610* m_18;
    hkOwnedD610* m_1c;
    int unk20;
    hkReferencedObjectD610 m_24;
    hkPointerMapD610 m_2c;
    hkArrayD610<hkOwnedD610*> m_38;
    hkArrayD610<int> m_44;
};

// Destructor: deletes every element of m_38, then deletes m_14, m_18 and m_1c; member destructors run afterwards.
// @fnv 0x00d610e0
FUN_00d610e0::~FUN_00d610e0() throw()
{
    for (int i = 0; i < m_38.m_iElementCount; i++)
        delete m_38.m_data[i];
    delete m_14;
    delete m_18;
    delete m_1c;
}

struct hkBoolD611
{
    char m_cBooleanValue;
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

class hkInnerD611
{
  public:
    hkBoolD611 ForwardValueToObject() const throw();
};

class hkObjD611
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkInnerD611* m_inner;

    int FUN_00d611e0() const throw();
};

// Returns 1 if m_inner is non-null and its ForwardValueToObject() returns true, otherwise 0.
// @fnv 0x00d611e0
int hkObjD611::FUN_00d611e0() const throw()
{
    if (m_inner && m_inner->ForwardValueToObject())
        return 1;
    return 0;
}

struct FUN_00dd9240_Class
{
    void FUN_00dd9240();
};
// @fnv 0x00d61250
void __cdecl FUN_00d61250()
{
    ((FUN_00dd9240_Class*)DAT_01269cd0)->FUN_00dd9240();
}

namespace fnv_00dd9cc0 {
class hkMemoryAllocatorDD9C
{
  public:
    virtual ~hkMemoryAllocatorDD9C() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterDD9C
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDD9C* m_pStreamAllocator;
    hkMemoryAllocatorDD9C& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDD9C& __cdecl FUN_00c85750();

class FUN_00cf6da0
{
  public:
    FUN_00cf6da0(int iCapacity) throw();

    static void* operator new(unsigned int uiSize) throw()
    {
        return FUN_00c85750().heap().AllocateMemoryBlock(uiSize);
    }
    static void operator delete(void* p) throw();

    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class hkReferencedObjectDD9C
{
  public:
    hkReferencedObjectDD9C()
    {
        m_sReferenceCount = 1;
    }
    virtual ~hkReferencedObjectDD9C() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
};

class hkListenerBaseDD9C
{
  public:
    virtual ~hkListenerBaseDD9C() throw();
};

class FUN_00dd9cc0 : public hkReferencedObjectDD9C, public hkListenerBaseDD9C
{
  public:
    void* m_pOwnerObject;
    FUN_00cf6da0* m_kNodePool;

    FUN_00dd9cc0(void* pvOwner) throw();
    virtual ~FUN_00dd9cc0() throw();
};

// Stores pvOwner and allocates a FUN_00cf6da0 with capacity 1000 into the second member.
// @fnv 0x00dd9cc0
FUN_00dd9cc0::FUN_00dd9cc0(void* pvOwner) throw()
{
    m_pOwnerObject = pvOwner;
    m_kNodePool = new FUN_00cf6da0(1000);
}
}  // namespace fnv_00dd9cc0

template <int SIZE> __forceinline void memCpyOneAlignedD60E(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do
    {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterD60E
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterD60E {
extern "C" hkMemoryRouterD60E& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T> class hkArrayD60E
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterD60E& router = hkRouterD60E::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedD60E<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class ListenerD60E
{
  public:
    virtual int FUN_00d60e80(int aiSoundId);
};

class EntryD60E
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    int unk04;
    int m_unk08;
    int m_unk0C;
    int m_unk10;
    ListenerD60E* m_pkListener;
};

class EntryFactoryD60E
{
  public:
    EntryD60E* InvokeRecord(int aiSoundId, void* pvParam);
};

class EntryListD60E
{
  public:
    void ProcessInputData(EntryD60E* pkEntry);
};

class OwnerBaseD60E
{
  public:
    virtual void vfn_00();
    int unk04;
};

class OwnerD60E : public OwnerBaseD60E, public ListenerD60E
{
  public:
    int unk0C;
    int unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int unk20;
    EntryListD60E m_kEntryList;
    int unk28, unk2C, unk30, unk34;
    hkArrayD60E<EntryD60E*> m_kEntries;
    int m_unk44;

    int FUN_00d60d40(int aiSoundId);
    virtual int FUN_00d60e80(int aiSoundId);
};

// Creates an EntryD60E for aiSoundId via DAT_01269cd0, configures it with owner state, adds it to m_kEntries, and processes it through m_kEntryList.
// @fnv 0x00d60e80
int OwnerD60E::FUN_00d60e80(int aiSoundId)
{
    if (FUN_00d60d40(aiSoundId) >= 0)
        return 0;
    EntryD60E* pkEntry = ((EntryFactoryD60E*)DAT_01269cd0)->InvokeRecord(aiSoundId, &m_unk44);
    if (pkEntry)
    {
        EntryD60E* const receiver = pkEntry;
        receiver->m_unk08 = m_unk14;
        receiver->m_unk0C = m_unk18;
        receiver->m_pkListener = this;
        receiver->m_unk10 = m_unk1C;
        receiver->vfn_14();
        m_kEntries.AddBack(pkEntry);
        m_kEntryList.ProcessInputData(pkEntry);
        return 0;
    }
    return 1;
}

inline void memCpy4_d60e(void* dst, const void* src, int nbytes)
{
    for (int i = 0; i < nbytes; i += 4)
        *(unsigned int*)((char*)dst + i) = *(const unsigned int*)((const char*)src + i);
}

template <class T> struct hkArray_d60e
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    T& operator[](int i)
    {
        return m_data[i];
    }
    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            memCpy4_d60e(m_data + index, m_data + m_iElementCount, sizeof(T));
    }
};

struct Item_d60e
{
    virtual ~Item_d60e();
};

struct Owner_d60e
{
    int FUN_00d60d40(void* key);
};

struct Listeners_d60e
{
    void FUN_00dd95b0(Item_d60e* item);
};

struct Part_d60e
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18;
    Listeners_d60e m_kListeners;
    int unk20, unk24, unk28, unk2C;
    hkArray_d60e<Item_d60e*> m_items;
    int FUN_00d60e20(void* key);
};

// Looks up an item by key in the owner, removes it from m_items, notifies m_kListeners, and deletes the item.
// @fnv 0x00d60e20
int Part_d60e::FUN_00d60e20(void* key)
{
    int index = ((Owner_d60e*)((char*)this - 8))->FUN_00d60d40(key);
    if (index >= 0)
    {
        Item_d60e* item = m_items[index];
        m_items.removeAt(index);
        m_kListeners.FUN_00dd95b0(item);
        delete item;
    }
    return 0;
}

// Adjustor thunk: sub ecx,0x0c; jmp FUN_00d61260
// The secondary base sits at offset 0x0c inside the derived object, so the
// thunk moves `this` back to the start of the primary base before tail-calling
// the shared virtual implementation.
struct ThunkPrimaryBase
{
    virtual void FUN_00d61220();
    int unk04;
    int unk08;
};

struct ThunkSecondaryBase
{
    virtual void FUN_00d61220();
};

struct ThunkDerived : ThunkPrimaryBase, ThunkSecondaryBase
{
    ThunkDerived();
// @fnv 0x00d61220
    virtual void FUN_00d61220();
};

ThunkDerived::ThunkDerived()
{}

// sub ecx,8; jmp target  ==  MSVC adjustor thunk: Derived overrides a virtual that both of its bases
// declare, so the second base's vtable gets a thunk that moves `this` back by the first base's size (8).
struct PrimaryBase
{
    virtual void FUN_00d61230();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d61230();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d61230
    virtual void FUN_00d61230();
};

Derived::Derived()
{}

namespace fnv_00d60f30 {
struct MemManager
{
    virtual void v0();
    virtual void* Alloc(unsigned int size);
    virtual void v2();
    virtual void* AllocBytes(int* size);
    virtual void Free(void* p, int size);
};
struct BSAudio
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    MemManager* m_mm;
    MemManager& heap()
    {
        return *m_mm;
    }
};
BSAudio& __cdecl FUN_00c85750();

struct __declspec(novtable) RefObject
{
    virtual void RefObject_v0();
    unsigned short m_iElementCount;
    unsigned short m_refs;
    RefObject() : m_refs(1)
    {}
    static void* operator new(unsigned int size)
    {
        RefObject* p = (RefObject*)FUN_00c85750().heap().Alloc(size);
        p->m_iElementCount = (unsigned short)size;
        return p;
    }
};

struct PtrArray
{
    enum
    {
        CAPACITY_MASK = int(0x3FFFFFFF),
        DONT_DEALLOCATE_FLAG = int(0x80000000)
    };
    int* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    PtrArray() : m_data(0), m_iElementCount(0), m_iCapacityState(DONT_DEALLOCATE_FLAG)
    {}
    int getCapacity() const
    {
        return m_iCapacityState & CAPACITY_MASK;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline void copyFromArray(MemManager& alloc, const PtrArray& a)
    {
        if (getCapacity() < a.GetLogicalSize())
        {
            if ((m_iCapacityState & DONT_DEALLOCATE_FLAG) == 0)
                alloc.Free(m_data, getCapacity() * int(sizeof(int)));
            int numBytes = a.GetLogicalSize() * int(sizeof(int));
            m_data = (int*)alloc.AllocBytes(&numBytes);
            m_iCapacityState = numBytes / int(sizeof(int));
        }
        int n = a.GetLogicalSize();
        m_iElementCount = n;
        int* d = m_data;
        int* s = a.m_data;
        for (int i = 0; i < n; i++)
            d[i] = s[i];
    }
    __forceinline PtrArray& operator=(const PtrArray& a)
    {
        copyFromArray(FUN_00c85750().heap(), a);
        return *this;
    }
};
struct HandleSet
{
    int unk00;
    int unk04;
    int unk08;
    HandleSet(int count = 0) : unk00(0), unk04(0), unk08(-1)
    {
        EnsureCapacity(&FUN_00c85750().heap(), count);
    }
    void EnsureCapacity(MemManager* mm, int count) throw();
};

struct OwnerObject : RefObject
{
    HandleSet m_handles;
    OwnerObject()
    {}
    virtual void OwnerObject_v1();
    void ProcessInputData(struct ListenerC* listener) throw();
};

struct ListenerB
{
    virtual void ListenerB_v0();
};
struct ListenerC
{
    virtual void ListenerC_v0();
    unsigned char m_flag;
    ListenerC() : m_flag(0)
    {}
};

struct OwnerHolder : OwnerObject
{

    void ProcessInputData(ListenerC* listener) throw();
};

struct FUN_00ddabe0 : RefObject
{
    int unk08;
    int unk0c;
    FUN_00ddabe0(void* src) throw();
};
struct FUN_00dda6e0 : RefObject
{
    int unk08;
    int unk0c;
    FUN_00dda6e0(void* src) throw();
};
struct ChildBase
{
    virtual void ChildBase_v0();
};
struct FUN_00dd9cc0 : RefObject, ChildBase
{
    int unk0c;
    int unk10;
    FUN_00dd9cc0(FUN_00dda6e0* src) throw();
};

struct FUN_00d60f30 : RefObject, ListenerB, ListenerC
{
    FUN_00ddabe0* m_pHeadNode;
    FUN_00dda6e0* m_iSecondInteger;
    ChildBase* m_pChildAtom;
    ListenerB* m_kListener;
    OwnerObject m_pOwnerObject;
    PtrArray m_arr38;
    PtrArray m_arr44;

    FUN_00d60f30(const PtrArray& arr, void* first, void* second);
    virtual void Thing_v1();
    virtual void ListenerB_v0();
    virtual void ListenerC_v0();
};

// Calls m_pOwnerObject.FUN_00dd9600(this), copies arr to m_arr44, conditionally constructs two objects, then constructs a child and assigns m_kListener.
// @fnv 0x00d60f30
FUN_00d60f30::FUN_00d60f30(const PtrArray& apArray, void* first, void* second)
{
    m_pOwnerObject.ProcessInputData(this);
    m_arr44 = apArray;
    m_pHeadNode = first ? new FUN_00ddabe0(first) : 0;
    m_iSecondInteger = second ? new FUN_00dda6e0(second) : 0;
    m_pChildAtom = new FUN_00dd9cc0(m_iSecondInteger);
    m_kListener = this;
}
}  // namespace fnv_00d60f30
