// gamebryo2.2/corelibs/nimain/niextradata.cpp: NiExtraData, NiAccumulator, MyOwner, ExtraDataObject and more (13 functions)

#include "niextradata_packet.h"
// @fnv 0x00aa0fe0
void NiAccumulator::ClearCamera()
{
    camera = 0;
}
// @fnv 0x00a7b3b0
void NiExtraData::LinkObject(NiStream& stream)
{
    if (stream.version < 0x0500000b)
        name.handle = stream.GetLoadedObject();
}
// Constructs a NiExtraData: sets the vtable, then assigns name from src with interlocked refcount updates on the string handle.
// @fnv 0x00a7b440
NiExtraData::NiExtraData(const NiFixedString& aName)
{
    const NiFixedString& src = aName;
    *(void**)this = kVtbl_NiExtraData;
    void* empty = EmptyFS.handle;
    name.handle = empty;
    void* srcHandle = src.handle;
    if (empty != srcHandle)
    {
        if (srcHandle != EmptyFS.handle)
            InterlockedIncrement((long*)((char*)srcHandle - 8));
        if (name.handle != EmptyFS.handle)
            InterlockedDecrement((long*)((char*)name.handle - 8));
        name.handle = srcHandle;
    }
}
// Loads NiExtraData from a stream: reads a count and byte buffer for old versions, otherwise reads the name, registering a NiBinaryExtraData object.
// @fnv 0x00a7b4a0
void NiExtraData::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    if (stream.version < 0x0500000b)
    {
        stream.ResetStreamState();
        unsigned int count;
        ReadCount(stream, count);
        if (count > 0 && IsExactKindOf(g_011c7820_arg1, this))
        {
            unsigned char* buffer = (unsigned char*)_NiMalloc(count);
            ReadBinaryValue(stream, buffer, count);
            NiBinaryExtraData* extra = new NiBinaryExtraData(count, buffer);
            if (extra)
                stream.RegisterObject(extra);
        }
    }
    else if (stream.version < 0x14010001)
        stream.ReadFixedString(name);
    else
        stream.ReadStringTableEntry(name);
}

struct NiObjectBase
{
    bool RegisterStreamables(NiStream*);
};
struct FakeStream
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual unsigned char f8(int*);
};
struct MyOwner : public NiObject
{
    int _08;
    bool NiExtraData_RegisterStreamables(NiStream&);
};
// @fnv 0x00a7b290
bool MyOwner::NiExtraData_RegisterStreamables(NiStream& kStream)
{
    if (!((NiObjectBase*)this)->NiObjectBase::RegisterStreamables(&kStream))
        return false;
    return ((FakeStream&)kStream).f8(&_08);
}

struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];
struct FUN_00a7b330_shell : public NiBinaryExtraData
{
    void FUN_00a7b330(NiBinaryExtraData*, CloningProcess*);
};

struct FUN_00a5d450_holder
{
    void __thiscall CreateVertexBufferSet(NiBinaryExtraData*, CloningProcess*);
};
// @fnv 0x00a7b330
void FUN_00a7b330_shell::FUN_00a7b330(NiBinaryExtraData* pkDest, CloningProcess* kCloning)
{
    ((FUN_00a5d450_holder*)this)->CreateVertexBufferSet(pkDest, kCloning);
    char* src = *(char**)((char*)this + 8);
    if (*(char**)((char*)pkDest + 8) != src)
    {
        if (src != *(char**)&EmptyFS)
            InterlockedIncrement((long*)(src - 8));
        char* dst = *(char**)((char*)pkDest + 8);
        if (dst != *(char**)&EmptyFS)
            InterlockedDecrement((long*)(dst - 8));
        *(char**)((char*)pkDest + 8) = src;
    }
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
struct _Call_a5d3a0
{
    _Call_a5d3a0();
};
inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}
// Allocates a 12-byte NiExtraData, constructs it, sets its vtable and copies a stored int into offset 8, returning the object or null.
// @fnv 0x00a7b380
NiExtraData* NiExtraData_CreateObject()
{
    NiExtraData* p = (NiExtraData*)BSFadeNode::operator new(12);
    if (p)
    {
        new (p) _Call_a5d3a0;
        *(void**)p = (void*)kVtbl_NiExtraData;
        *(int*)((char*)p + 8) = *(int*)&EmptyFS;
        return p;
    }
    return 0;
}

struct FUN_00a7b2c0_NiObject
{
    void LinkObject(NiStream&);
};

struct FUN_00a7b2c0_NiStream
{
    void SerializeString(const char*);
};

struct FUN_00a7b2c0_shell
{
    void* vtable;
    unsigned int pad;
    char m_kName[1];
    void NiExtraData_SaveBinary(NiStream& kStream);
};

// @fnv 0x00a7b2c0
void FUN_00a7b2c0_shell::NiExtraData_SaveBinary(NiStream& kStream)
{
    reinterpret_cast<FUN_00a7b2c0_NiObject*>(this)->LinkObject(kStream);
    reinterpret_cast<FUN_00a7b2c0_NiStream*>(&kStream)->SerializeString(m_kName);
}

extern void* _EmptyFS;

struct NiRefObject
{
    virtual ~NiRefObject();
};

struct FUN_00a7b300_shell : public NiRefObject
{
    void __thiscall FUN_00a7b300();
};

// Restores the NiExtraData vtable, releases the reference-counted object at offset 8 if not the empty sentinel, then calls the NiRefObject destructor.
// @fnv 0x00a7b300
void FUN_00a7b300_shell::FUN_00a7b300()
{
    *reinterpret_cast<void* volatile*>(this) = kVtbl_NiExtraData;

    void* pRef = *reinterpret_cast<void* const volatile*>(reinterpret_cast<unsigned char*>(this) + 8);

    if (pRef != _EmptyFS)
        InterlockedDecrement(reinterpret_cast<long*>(reinterpret_cast<unsigned char*>(pRef) - 8));

    NiRefObject::~NiRefObject();
}

extern int DAT_0109da1c;
extern void* DAT_0109b220;

struct ExtraDataObject
{
    void* m_vtbl;
    unsigned int refs;
    void* name;

    void InitializeBase();
    ExtraDataObject* FUN_00a7b2e0();
};

// @fnv 0x00a7b2e0
ExtraDataObject* ExtraDataObject::FUN_00a7b2e0()
{
    InitializeBase();
    m_vtbl = &DAT_0109da1c;
    name = DAT_0109b220;
    return this;
}

class NiObject_00a7b3d0
{
  public:
    void* vtable;
    unsigned int _04;
    unsigned int _08;

    unsigned char __thiscall IsSameAs(NiObject_00a7b3d0* object);
    unsigned char __thiscall NiExtraData_IsEqual(NiObject_00a7b3d0* object);
};

// Returns 0 if IsSameAs fails; otherwise returns whether _08 equals object->_08.
// @fnv 0x00a7b3d0
unsigned char __thiscall NiObject_00a7b3d0::NiExtraData_IsEqual(NiObject_00a7b3d0* object)
{
    if (!IsSameAs(object))
        return 0;

    return _08 == object->_08;
}

extern void* _EmptyFS;
extern void* kVtbl_NiExtraData[];
extern "C" void _ReadWriteBarrier(void);
void __cdecl FUN_00aa1460(void* ptr, unsigned int size);

struct Cls
{
    void* m_vptr;
    unsigned int m_refs;
    void* m_nameHandle;

    void FUN_00a5d3d0();

    Cls* DestroyExtraData(unsigned char acFlags);
};

// @fnv 0x00a7b400
Cls* Cls::DestroyExtraData(unsigned char acFlags)
{
    *(volatile void**)&m_vptr = kVtbl_NiExtraData;
    _ReadWriteBarrier();
    if (m_nameHandle != _EmptyFS)
    {
        InterlockedDecrement((long*)((char*)m_nameHandle - 8));
    }
    FUN_00a5d3d0();
    if (acFlags & 1)
    {
        FUN_00aa1460(this, 0xc);
    }
    return this;
}

struct StrArr
{
    void* vtable;
    char** data;
    unsigned short capacity, count, used, grow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
    void Add(char* value)
    {
        unsigned int index = count;
        if (index >= capacity)
            SetSize(index + grow);
        SetAt(index, value);
    }
};
extern const char* const g_01270908_arg1;
extern const char DAT_01097790[];
extern "C" char* FUN_00a7d330(const char*);
char* FUN_00a7d5e0(const char*, const char*);
struct ExtraDataStrings
{
    void* vtable;
    unsigned int refs;
    const char* name;
    const char* GetName() const
    {
        return name;
    }
    void NiExtraData_GetViewerStrings(StrArr* strings);
};
// @fnv 0x00a7b580
void ExtraDataStrings::NiExtraData_GetViewerStrings(StrArr* strings)
{
    strings->Add(FUN_00a7d330(g_01270908_arg1));
    strings->Add(FUN_00a7d5e0(DAT_01097790, GetName()));
}
