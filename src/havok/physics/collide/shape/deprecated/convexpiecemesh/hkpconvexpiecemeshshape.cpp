
// src/havok/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/deprecated/convexpiecemesh/hkpconvexpiecemeshshape.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpConvexPieceMeshShape.h"

struct HkpStandIn;

struct HkpAllocator
{
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void release(HkpStandIn* object, unsigned short size) = 0;
};

struct HkpRouter
{
    void* reserved;
    unsigned char padding[12];
    HkpAllocator* allocator;
};

struct HkpStandIn
{
    virtual void v0() = 0;

    void FUN_00e490d0();
    HkpStandIn* FUN_00e01010(int flags);

    unsigned short value;
};

HkpRouter* _D1A0E0GetMemoryRouter();

// Calls FUN_00e490d0, then if flags has bit 0 set, releases this through the memory router's allocator with this->value as size, and returns this.
// @fnv 0x00e01010
HkpStandIn* HkpStandIn::FUN_00e01010(int flags)
{
    this->FUN_00e490d0();

    if (flags & 1)
    {
        HkpRouter* router = _D1A0E0GetMemoryRouter();
        HkpAllocator* allocator = router->allocator;
        allocator->release(this, this->value);
    }

    return this;
}

struct FUN_00e49100_t
{
    int GetNextKey(int key);
};

// @fnv 0x00e49100
int FUN_00e49100_t::GetNextKey(int key)
{
    void* shape = *(void**)((char*)this + 8);
    int iMaxKey = *(int*)((char*)shape + 0x24) + *(int*)((char*)shape + 0x18);
    int iNextKey = key + 1;
    if (iNextKey >= iMaxKey)
        iNextKey = -1;
    return iNextKey;
}

struct FUN_00e49290_Target
{
    // Virtual stub that returns 0 for the given int argument.
// @fnv 0x00e49290
    virtual int FUN_00e49290_f0(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f1(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f2(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f3(int)
    {
        return 0;
    }
    virtual int FUN_00e49290_f4(int)
    {
        return 0;
    }
};

struct FUN_00e49290_Owner
{
    unsigned char pad[0x10];
    FUN_00e49290_Target target;
};

struct FUN_00e49290_Data
{
    unsigned char pad0[8];
    int* p8;
    unsigned char pad1[8];
    int* p14;
    unsigned int count;
    unsigned char pad2[4];
    int* p20;
};

struct FUN_00e49290_Class
{
    unsigned char pad[8];
    FUN_00e49290_Data* data;
    FUN_00e49290_Owner* owner;

    int FUN_00e49290(unsigned int index);
};

int FUN_00e49290_Class::FUN_00e49290(unsigned int index)
{
    int result;

    if (index < this->data->count)
    {
        int i = this->data->p14[index];
        result = this->data->p8[i + 1];
    }
    else
    {
        result = this->data->p20[index - this->data->count];
    }

    return this->owner->target.FUN_00e49290_f4(result);
}

// @fnv 0x00e49030
int FUN_00e49030()
{
    return 0;
}

struct Ref
{
    void FUN_00c905b0() throw();
};
struct P
{
    virtual ~P()
    {}
    int a, b, c;
};
struct S
{
    virtual ~S()
    {}
    int d;
};
struct Ptr
{
    Ref* p;
    ~Ptr()
    {
        p->FUN_00c905b0();
    }
};
struct D : P, S
{
    Ptr m18;
    Ptr m1c;
    __forceinline ~D()
    {}
    void FUN_00e490d0();
};
// Destroys the object by invoking its destructor.
// @fnv 0x00e490d0
void D::FUN_00e490d0()
{
    this->D::~D();
}

class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_01269198;

int __cdecl FUN_00d06f80(const void* pvChunk, int iNumBytes) throw();

template <class T> class hkArrayE494
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
};

class hkStatisticsCollectorE494
{
  public:
    virtual ~hkStatisticsCollectorE494() throw();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual void addChildObject(const char* pcName, const void* pvObject, const void* pvClass) throw();
    virtual void V4() throw();
    virtual void AddMemoryChunk(int iType, const char* pcName, const void* pvChunk, int iUsedSize,
                                int iAllocatedSize) throw();

    int m_04;
    int m_08;
    int m_0c;
    hkBool m_countDontDeallocate;

    template <class T> void addArray(const char* pcName, const hkArrayE494<T>& kArray)
    {
        if ((kArray.m_iCapacityState & 0x80000000) == 0 || m_countDontDeallocate)
        {
            const T* pData = kArray.m_data;
            int iAllocated = FUN_00d06f80(pData, kArray.getCapacity() * sizeof(T));
            AddMemoryChunk(3, pcName, kArray.m_data, kArray.GetLogicalSize() * sizeof(T), iAllocated);
        }
    }
};

class hkxStreamE494;
class hkDisplayMeshE494;

struct hkMeshSectionE494
{
    int unk00;
    int unk04;
    hkArrayE494<hkxStreamE494*> m_indexStreams;
    hkArrayE494<hkxStreamE494*> m_vertexStreams;
    hkArrayE494<hkxStreamE494*> m_materialStreams;
};

class hkReferencedObjectE494
{
  public:
    virtual ~hkReferencedObjectE494() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;

    void FUN_00d213e0(hkStatisticsCollectorE494* pkCollector, const GlobalObjectO2_00d472a0* pkClass) const throw();
};

class hkDisplayGeometryE494 : public hkReferencedObjectE494
{
  public:
    hkMeshSectionE494* m_kCriticalSection;
    hkDisplayMeshE494* m_pDisplayMesh;

    void AddToStatisticsCollector(hkStatisticsCollectorE494* pkCollector, const GlobalObjectO2_00d472a0* pkClass) const
        throw();
};

// Adds the vertex, material and index stream arrays and the display mesh to pkCollector, then forwards to the base statistics routine.
// @fnv 0x00e49410
void hkDisplayGeometryE494::AddToStatisticsCollector(hkStatisticsCollectorE494* pkCollector,
                                                     const GlobalObjectO2_00d472a0* pkClass) const throw()
{
    pkCollector->addArray("Stream", m_kCriticalSection->m_vertexStreams);
    pkCollector->addArray("Stream", m_kCriticalSection->m_materialStreams);
    pkCollector->addArray("Stream", m_kCriticalSection->m_indexStreams);
    pkCollector->addChildObject("DisplayMesh", m_pDisplayMesh, 0);
    FUN_00d213e0(pkCollector, &g_01269198);
}

// Stores whether bit bitIndex % 31 of word bitIndex / 31, at bits[bits[0] + 1 + word], is set into *found, and returns found.
// @fnv 0x00e49040
unsigned char* __stdcall FUN_00e49040(unsigned char* pbResult, const int* bits, unsigned int bitIndex)
{
    unsigned int wordIndex = bitIndex / 31;
    unsigned int bitWithinWord = bitIndex % 31;
    unsigned int mask = 1u << bitWithinWord;
    *pbResult = (bits[bits[0] + wordIndex + 1] & mask) != 0;
    return pbResult;
}

// sub ecx,0x10; jmp target  ==  MSVC adjustor thunk for a virtual declared by both bases.
struct PrimaryBase
{
    virtual void FUN_00e01040();
    int unk04;
    int unk08;
    int unk0C;
};

struct SecondaryBase
{
    virtual void FUN_00e01040();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00e01040
    virtual void FUN_00e01040();
};

Derived::Derived()
{}
