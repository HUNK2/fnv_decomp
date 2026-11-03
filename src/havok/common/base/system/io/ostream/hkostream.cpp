
// src/havok/common/base/system/io/ostream/hkostream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/system/io/ostream/hkostream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkOstream.h"

extern int DAT_01268108;
extern "C" __declspec(dllimport) void __stdcall free(void*);

// @fnv 0x00c85750
void __cdecl FUN_00c85750()
{
    free((void*)DAT_01268108);
}

extern char _DAT_010c9314;
extern char _DAT_0102e388;
struct Old
{
    void ReleaseReference();
};
struct FUN_00cc00e0
{
    void* vtbl;
    int m_ref;
    Old* m_pStreamWriter;
    ~FUN_00cc00e0();
};
// @fnv 0x00cc00e0
FUN_00cc00e0::~FUN_00cc00e0()
{
    vtbl = (void*)&_DAT_010c9314;
    if (m_pStreamWriter)
        m_pStreamWriter->ReleaseReference();
    vtbl = (void*)&_DAT_0102e388;
}

struct hkReferencedObjectStandIn
{
    void RetainReference();
    void removeReference();
};
struct DDCC60WorldStandIn
{
    int m_uiStandInValue;
    int m_iValueAfterStandIn;
    hkReferencedObjectStandIn* m_ref;
    void FUN_00cc0480(hkReferencedObjectStandIn* pNew);
};
// @fnv 0x00cc0480
void DDCC60WorldStandIn::FUN_00cc0480(hkReferencedObjectStandIn* pNew)
{
    pNew->RetainReference();
    m_ref->removeReference();
    m_ref = pNew;
}

struct FUN_00cc0680
{
    int tell();
};

// @fnv 0x00cc0680
int FUN_00cc0680::tell()
{
    char* p = *(char**)(this + 8);
    int n = *(int*)(p + 0xc) - 1;
    return *(int*)(p + 4) + *(int*)(p + 0) * n;
}

struct FUN_00cc07f0_Router
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Free(void*, unsigned short);
};

struct FUN_00cc07f0_MemoryRouter
{
    unsigned char padding[0x10];
    FUN_00cc07f0_Router* pRouter;
};

extern FUN_00cc07f0_MemoryRouter* _D1A0E0GetMemoryRouter();

struct FUN_00cc07f0_StandIn
{
    // Virtual destructor for the stand-in type; does nothing.
// @fnv 0x00cc07f0
    virtual ~FUN_00cc07f0_StandIn()
    {}
    void FUN_00cc0780();
    unsigned short m_nSize;

    FUN_00cc07f0_StandIn* FUN_00cc07f0(unsigned int deletingFlag);
};

FUN_00cc07f0_StandIn* FUN_00cc07f0_StandIn::FUN_00cc07f0(unsigned int deletingFlag)
{
    FUN_00cc0780();

    if (deletingFlag & 1)
    {
        FUN_00cc07f0_MemoryRouter* memoryRouter = _D1A0E0GetMemoryRouter();
        unsigned short size = m_nSize;
        memoryRouter->pRouter->Free(this, size);
    }

    return this;
}

struct CpuInterface
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void Invoke();
};
struct CpuObject
{
    unsigned int unk00;
    unsigned int unk04;
    CpuInterface* target;
    void FUN_00cc0460();
};
// @fnv 0x00cc0460
void CpuObject::FUN_00cc0460()
{
    target->Invoke();
}

// FUN_00cc0470 : the stub family - load a sub-object out of `this` and tail-jump to
// one of its virtuals (vtable offset 0x10).
struct Sub_00cc0470
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10(void* a);
};

struct Own_00cc0470
{
    int u00;
    int u04;
    Sub_00cc0470* m_sub;
    void __thiscall FUN_00cc0470(void* a);
};

// @fnv 0x00cc0470
void __thiscall Own_00cc0470::FUN_00cc0470(void* a)
{
    m_sub->v10(a);
}

extern int g_unk01268560;

// @fnv 0x00cc04c0
int* __cdecl hkOstream_getClassType()
{
    return &g_unk01268560;
}

extern int DAT_01268ad8;

// @fnv 0x00cc0770
int __cdecl hkArrayStreamWriter_getClassType()
{
    return reinterpret_cast<int>(&DAT_01268ad8);
}

// @fnv 0x00e3b490
void __stdcall FUN_00e3b490(bool* p)
{
    *p = true;
}

struct FUN_00cc04a0_Slots
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0C(const char* name, void* value, int flags);
};
struct FUN_00cc04a0_Cls
{
    int unk00;
    int unk04;
    void* unk08;
    void RegisterWriter(FUN_00cc04a0_Slots* target, int unused);
};
// @fnv 0x00cc04a0
void FUN_00cc04a0_Cls::RegisterWriter(FUN_00cc04a0_Slots* apSlots, int unused)
{
    apSlots->slot0C("writer", unk08, 0);
}

class hkMemoryAllocatorCC06
{
  public:
    virtual ~hkMemoryAllocatorCC06() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCC06
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorCC06* m_pStreamAllocator;

    hkMemoryAllocatorCC06& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterCC06 {
extern "C" hkMemoryRouterCC06& __cdecl FUN_00c85750() throw();
}

class hkRefObjCC06
{
  public:
    virtual ~hkRefObjCC06() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjCC06()
    {
        m_sReferenceCount = 1;
    }

    static void* operator new(unsigned int nbytes) throw()
    {
        hkRefObjCC06* b = static_cast<hkRefObjCC06*>(hkRouterCC06::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class FUN_00cc06f0 : public hkRefObjCC06
{
  public:
    int unk08;
    int unk0C;
    int unk10;

    FUN_00cc06f0(void* owner, int flag) throw();
};

class FUN_00cc0630 : public hkRefObjCC06
{
  public:
    FUN_00cc06f0* m_pChildAtom;

    FUN_00cc0630(void* owner);
    virtual ~FUN_00cc0630();
};

// @fnv 0x00cc0630
FUN_00cc0630::FUN_00cc0630(void* owner)
{
    m_pChildAtom = new FUN_00cc06f0(owner, 1);
}

namespace fnv_00cc0690 {
class hkMemoryAllocatorCC06
{
  public:
    virtual ~hkMemoryAllocatorCC06() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCC06
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCC06* m_pStreamAllocator;
    hkMemoryAllocatorCC06& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterCC06 {
extern "C" hkMemoryRouterCC06& __cdecl FUN_00c85750();
}

class FUN_00d46be0_class
{
  public:
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;

    void FUN_00d46be0() throw();
    ~FUN_00d46be0_class() throw()
    {
        FUN_00d46be0();
    }
    static void operator delete(void* p) throw()
    {
        hkRouterCC06::FUN_00c85750().heap().ReleaseBlock(p, sizeof(FUN_00d46be0_class));
    }
};

struct FUN_00d1df70
{
    void FUN_00c90510() throw();
    void removeReference() throw();
};

class hkReferencedObjectCC06
{
  public:
    virtual ~hkReferencedObjectCC06() throw()
    {}
    hkUint16 m_usMemSizeAndFlags;
    hkInt16 m_sReferenceCount;

    static void operator delete(void* p) throw()
    {
        hkRouterCC06::FUN_00c85750().heap().ReleaseBlock(p,
                                                         static_cast<hkReferencedObjectCC06*>(p)->m_usMemSizeAndFlags);
    }
};

class hkStreamCC06 : public hkReferencedObjectCC06
{
  public:
    FUN_00d46be0_class* m_stream;
    void* m_external;

    virtual ~hkStreamCC06() throw()
    {
        if (m_external == 0)
            delete m_stream;
    }
    hkStreamCC06* DestroyStream(unsigned int uiFlags) throw();
};

// Destroys the stream object and, when bit 0 of uiFlags is set, frees its memory via operator delete; returns this.
// @fnv 0x00cc0690
hkStreamCC06* hkStreamCC06::DestroyStream(unsigned int uiFlags) throw()
{
    this->hkStreamCC06::~hkStreamCC06();
    if (uiFlags & 1)
        hkStreamCC06::operator delete(this);
    return this;
}
}  // namespace fnv_00cc0690

namespace fnv_00cc06f0 {
class hkMemoryAllocatorCC06;

struct hkMemoryRouterCC06
{
    int unk00;
    int unk04;
    int unk08;
    hkMemoryAllocatorCC06* m_pTemp;
    hkMemoryAllocatorCC06* m_pStreamAllocator;
    hkMemoryAllocatorCC06& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterCC06 {
extern "C" hkMemoryRouterCC06& __cdecl FUN_00c85750() throw();
}
void __cdecl FUN_00c908c0(hkMemoryAllocatorCC06& kAlloc, void* apvArray, int aiNumElements, int iSizeElem) throw();

template <class T> class hkArrayCC06
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline void reserve(hkMemoryAllocatorCC06& kAlloc, int n)
    {
        const int iCap = getCapacity();
        if (iCap < n)
        {
            int iCap2 = 2 * iCap;
            int iNewCap = (n < iCap2) ? iCap2 : n;
            FUN_00c908c0(kAlloc, this, iNewCap, sizeof(T));
        }
    }
    __forceinline void reserve(int n)
    {
        reserve(hkRouterCC06::FUN_00c85750().heap(), n);
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        reserve(hkRouterCC06::FUN_00c85750().heap(), n);
        m_iElementCount = n;
    }
};

class hkRefObjCC06
{
  public:
    virtual ~hkRefObjCC06() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjCC06() throw()
    {
        m_sReferenceCount = 1;
    }
};

class FUN_00cc06f0 : public hkRefObjCC06
{
  public:
    hkArrayCC06<char>* m_buffer;
    int m_kRayStart;
    int m_flags;

    FUN_00cc06f0(hkArrayCC06<char>* buffer, int flags) throw();
    virtual ~FUN_00cc06f0() throw();
};

// Stores the buffer and its size, reserves one extra char, and appends a terminating null byte.
// @fnv 0x00cc06f0
FUN_00cc06f0::FUN_00cc06f0(hkArrayCC06<char>* buffer, int flags) throw()
    : m_buffer(buffer), m_kRayStart(buffer->m_iElementCount), m_flags(flags)
{
    buffer->reserve(buffer->m_iElementCount + 1);
    m_buffer->m_data[m_buffer->m_iElementCount] = 0;
}
}  // namespace fnv_00cc06f0

class hkMemoryAllocatorCC07
{
  public:
    virtual ~hkMemoryAllocatorCC07() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iNumBytes) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterCC07
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorCC07* m_pStreamAllocator;
    hkMemoryAllocatorCC07& heap()
    {
        return *m_pStreamAllocator;
    }
};
namespace hkRouterCC07 {
extern "C" hkMemoryRouterCC07& __cdecl FUN_00c85750() throw();
}

template <class T> class hkArrayCC07
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    static void operator delete(void* p, unsigned int nbytes)
    {
        hkRouterCC07::FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }
    ~hkArrayCC07() throw()
    {
        hkMemoryAllocatorCC07& kAlloc = hkRouterCC07::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkBaseObjectCC07
{
  public:
    virtual ~hkBaseObjectCC07() throw()
    {}
};

class FUN_00cc0780 : public hkBaseObjectCC07
{
  public:
    int unk04;
    hkArrayCC07<unsigned char>* m_buffer;
    int unk0C;
    int m_external;

    virtual ~FUN_00cc0780() throw();
};

// Destructor that deletes m_buffer unless m_external is set.
// @fnv 0x00cc0780
FUN_00cc0780::~FUN_00cc0780() throw()
{
    if (!m_external)
        delete m_buffer;
}

struct GlobalObject_0045cfe0
{
    ~GlobalObject_0045cfe0();
    int unk00;
};

class FUN_00cbf430 : public GlobalObject_0045cfe0
{
  public:
    ~FUN_00cbf430();
    void FUN_00cbf2f0();
};

// @fnv 0x00cbf430
FUN_00cbf430::~FUN_00cbf430()
{
    FUN_00cbf2f0();
}

class hkMemoryAllocatorD60B
{
  public:
    virtual ~hkMemoryAllocatorD60B() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
};

struct hkMemoryRouterD60B
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorD60B* m_pStreamAllocator;

    hkMemoryAllocatorD60B& heap()
    {
        return *m_pStreamAllocator;
    }
};

namespace hkRouterD60B {
extern "C" hkMemoryRouterD60B& __cdecl FUN_00c85750() throw();
}

class hkRefObjD60B
{
  public:
    virtual ~hkRefObjD60B() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    hkRefObjD60B()
    {
        m_sReferenceCount = 1;
    }

    static void* operator new(unsigned int nbytes)
    {
        hkRefObjD60B* b = static_cast<hkRefObjD60B*>(hkRouterD60B::FUN_00c85750().heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = (unsigned short)nbytes;
        return b;
    }
    static void operator delete(void* p);
};

class FUN_00d60b40 : public hkRefObjD60B
{
  public:
    FUN_00cc06f0* m_pChildAtom;
    char m_flag;

    FUN_00d60b40(void* owner, char flag) throw();
    virtual ~FUN_00d60b40();
};

// Sets m_flag and assigns m_pChildAtom to a new FUN_00cc06f0 constructed with owner and 1.
// @fnv 0x00d60b40
FUN_00d60b40::FUN_00d60b40(void* owner, char flag) throw()
{
    m_flag = flag;
    m_pChildAtom = new FUN_00cc06f0(owner, 1);
}

struct NiBinaryStream;
typedef unsigned int(__cdecl* NiBinaryReadFn)(NiBinaryStream* stream, void* buffer, unsigned int bytes,
                                              unsigned int* componentSizes, unsigned int numComponents);

struct NiBinaryStream
{
    void* vtbl;
    unsigned int m_uiStreamFlags;
    NiBinaryReadFn m_pfnRead;
};

struct NiStream
{
    void* vtbl;
    unsigned int m_uiFormatVersion;
    char m_author[0xd8];
    char m_fileName[0x105];
    char m_bLittleEndian;
    short unk1e6;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    NiBinaryStream* m_binaryStream;
};

struct HavokError
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual int Warning(int type, int id, const char* desc, const char* file, int line);
};
extern HavokError* DAT_01268360;

struct BoolType
{
    char m_cBooleanValue;
    BoolType(bool b) : m_cBooleanValue(b)
    {}
    BoolType(const BoolType& o) : m_cBooleanValue(o.m_cBooleanValue)
    {}
};

namespace MoppLoadStream {
struct FUN_00cc00e0
{
    void* vtbl;
    int m_ref;
    Old* m_pStreamWriter;
    __declspec(noinline) ~FUN_00cc00e0();
};
}

struct OStream : public MoppLoadStream::FUN_00cc00e0
{
    OStream(void* mem, int GetAllocationSize, BoolType isArray);
    OStream& operator<<(const char* s);
};

struct MoppCodeHeader
{
    int unk00;
    int unk04;
    int unk08;
    unsigned long m_data;
};

struct bhkMoppBvTreeShape
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0a();
    virtual void v0b();
    virtual void v0c();
    virtual void v0d();
    virtual void v0e();
    virtual void v0f();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v1a();
    virtual void v1b();
    virtual void v1c();
    virtual void v1d();
    virtual void v1e();
    virtual void v1f();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual unsigned int slotA8();
    virtual void v2b();
    virtual void v2c();
    virtual MoppCodeHeader* slotB4(char* pAllocated);

    void bhkSerializable_LoadCInfo(NiStream& stream);

    unsigned int bhkMoppBvTreeShape_LoadCInfo(NiStream& stream);
};

extern "C" unsigned long __cdecl _byteswap_ulong(unsigned long);

// Gets a size and buffer, reads binary data and warns for versions below 6, otherwise calls bhkSerializable_LoadCInfo and may byte-swap m_data.
// @fnv 0x00cc9f60
unsigned int bhkMoppBvTreeShape::bhkMoppBvTreeShape_LoadCInfo(NiStream& stream)
{
    unsigned int size = slotA8();
    char allocated;
    MoppCodeHeader* buffer = slotB4(&allocated);

    if (stream.m_uiFormatVersion < 6)
    {
        NiBinaryStream* pBinaryStream = stream.m_binaryStream;
        pBinaryStream->m_uiStreamFlags += pBinaryStream->m_pfnRead(pBinaryStream, buffer, size -= 4, 0, 0);

        const char* pcFileName = stream.m_fileName;
        const char* pcAuthor = stream.m_author;
        if (!*pcAuthor)
        {
            pcAuthor = "Please";
        }

        char szWarning[512];
        OStream s(szWarning, sizeof(szWarning), true);
        s << "File " << pcFileName << " contains an old bhkMoppBvTreeShape! " << pcAuthor << " re-export\n";
        DAT_01268360->Warning(1, 0x234f2250, szWarning,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\BSHavok\\bhkMoppBvTreeShape.cpp", 187);
    }
    else
    {
        bhkSerializable_LoadCInfo(stream);
        if (stream.m_bLittleEndian != 1)
        {
            buffer->m_data = _byteswap_ulong(buffer->m_data);
        }
    }

    return size;
}
