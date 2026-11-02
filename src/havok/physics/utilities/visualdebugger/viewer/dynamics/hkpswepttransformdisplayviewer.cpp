
// src/havok/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/dynamics/hkpswepttransformdisplayviewer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkpSweptTransformDisplayViewer
{
    int FindEntryIndex(int);
    void RemoveWorldData(int);
    void FUN_00d64950(int a);
};

// Calls FindEntryIndex on the viewer at this-0x20 with a; if the returned index is non-negative, calls RemoveWorldData with it.
// @fnv 0x00d64950
void hkpSweptTransformDisplayViewer::FUN_00d64950(int a)
{
    hkpSweptTransformDisplayViewer* p = (hkpSweptTransformDisplayViewer*)((char*)this - 0x20);
    int r = p->FindEntryIndex(a);
    if (r >= 0)
        p->RemoveWorldData(r);
}

extern "C" void FUN_00d64650();
// @fnv 0x00d647f0
void __fastcall FUN_00d647f0(void* self)
{
    ((void(__thiscall*)(void*))FUN_00d64650)((char*)self - 0x20);
}

extern "C" int g_ptr_0x1268fd0;

// @fnv 0x00d64970
int __cdecl FUN_00d64970()
{
    return g_ptr_0x1268fd0;
}

struct D63FF0Entry
{
    void* m_key;
};

struct D63FF0Container
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
    D63FF0Entry** m_entries;
    int m_iNumberOfEntries;

    int FindEntryIndex(void* key) const;
};

// Scans m_entries for an entry whose m_key equals key and returns its index, or -1 if none matches.
// @fnv 0x00d63ff0
int D63FF0Container::FindEntryIndex(void* key) const
{
    for (int i = 0; i < m_iNumberOfEntries; i++)
    {
        if (m_entries[i]->m_key == key)
            return i;
    }
    return -1;
}

struct SweptList
{
    int unk00;
    void** m_04;
    int m_08;
};

struct SweptArg
{
    int unk00;
    int unk04;
    int m_08;
    int unk0C;
    unsigned char m_10;
    unsigned char m_11;
    unsigned char m_12;
    unsigned char m_13;
};

struct SweptVObj
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual int v5(void* p, int g, int z);
};

class SweptTransformItem
{
  public:
    int unk00;
    int unk04;
    SweptList** m_08;

    void FUN_00d64120(SweptArg* a1);
};

extern "C" int g_ptr_0x1268fd0;

// @fnv 0x00d64120
void SweptTransformItem::FUN_00d64120(SweptArg* a1)
{
    if (*(int*)&a1->m_10 == 0)
    {
        return;
    }
    hkpSweptTransformDisplayViewer* viewer = (hkpSweptTransformDisplayViewer*)((char*)this - 0x28);
    int iIndex = viewer->FindEntryIndex(a1->m_08);
    if (iIndex < 0)
    {
        return;
    }
    SweptList* list = this->m_08[iIndex];
    void* key = (void*)&a1->m_11;
    SweptVObj* pVObj = *(SweptVObj**)((char*)this - 0x10);
    pVObj->v5(key, g_ptr_0x1268fd0, 0);

    int i = 0;
    int iCount = list->m_08;
    if (iCount > 0)
    {
        void** p = list->m_04;
        do
        {
            if (*p == key)
            {
                if (i >= 0)
                {
                    (*(volatile int*)&list->m_08)--;
                    int last = list->m_08;
                    if (last != i)
                    {
                        list->m_04[i] = list->m_04[last];
                    }
                }
                break;
            }
            ++i;
            ++p;
        } while (i < iCount);
    }

    key = (void*)&a1->m_12;
    int g2 = g_ptr_0x1268fd0;
    pVObj = *(SweptVObj**)((char*)this - 0x10);
    pVObj->v5(key, g2, 0);

    i = 0;
    iCount = list->m_08;
    if (iCount > 0)
    {
        void** p = list->m_04;
        do
        {
            if (*p == key)
            {
                if (i >= 0)
                {
                    (*(volatile int*)&list->m_08)--;
                    int last = list->m_08;
                    if (last != i)
                    {
                        list->m_04[i] = list->m_04[last];
                    }
                }
                break;
            }
            ++i;
            ++p;
        } while (i < iCount);
    }
}

struct FUN_00d647b0_Pool
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
    int* m_items;
    int m_uiItemCount;
};

struct FUN_00d647b0_Listener
{
    int unk00;
};

typedef void(__thiscall* FUN_00d647b0_Handler)(FUN_00d647b0_Listener* self, int item);

struct FUN_00d647b0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    FUN_00d647b0_Pool* m_kNodePool;

    void NotifyItems();
};

// @fnv 0x00d647b0
void FUN_00d647b0_cls::NotifyItems()
{
    if (m_kNodePool != 0)
    {
        int i = 0;
        if (m_kNodePool->m_uiItemCount > i)
        {
            FUN_00d647b0_Listener* listener = (FUN_00d647b0_Listener*)((char*)this - 8);
            do
            {
                ((FUN_00d647b0_Handler)FUN_00d64650)(listener, m_kNodePool->m_items[i]);
                i++;
            } while (i < m_kNodePool->m_uiItemCount);
        }
    }
}

struct SweptHeap
{
    virtual ~SweptHeap();
    virtual void* AllocateMemoryBlock(int n);
    virtual void ReleaseBlock(void* p, int n);
    virtual void* AllocateBufferWithSize(int& n);
    virtual void ReturnMemory(void* p, int n);
};

struct SweptRouter
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    SweptHeap* m_pStreamAllocator;
    SweptHeap& heap()
    {
        return *m_pStreamAllocator;
    }
};

__declspec(nothrow) SweptRouter& __cdecl FUN_00c85750();

template <int SIZE> __forceinline void SweptMemCpyOne(void* dst, const void* src)
{
    for (int i = 0; i < SIZE / 4; i++)
        ((unsigned int*)dst)[i] = ((const unsigned int*)src)[i];
}

template <typename T> struct SweptArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline ~SweptArray() throw()
    {
        _clearAndDeallocate(FUN_00c85750().heap());
    }

    __forceinline void clear() throw()
    {
        m_iElementCount = 0;
    }
    __forceinline void _clearAndDeallocate(SweptHeap& alloc) throw()
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
            SweptMemCpyOne<sizeof(T)>(m_data + index, m_data + m_iElementCount);
    }
};

struct SweptEntityListener
{
    virtual void EntityAddedCallback(void* entity);
};
struct SweptPostSimListener
{
    virtual void postSimulationCallback(void* world);
};

struct SweptWorld
{
    void AddEntityListener(SweptEntityListener* listener);
    void AddPostSimulationListener(SweptPostSimListener* listener);
};

struct SweptWorldData
{
    SweptWorld* m_pOwningWorld;
    SweptArray<unsigned long> m_kEntityIDs;

    static void operator delete(void* p, unsigned int nbytes)
    {
        FUN_00c85750().heap().ReleaseBlock(p, nbytes);
    }
};

struct SweptViewerBase
{
    virtual ~SweptViewerBase();
    int m_04, m_08, m_0c, m_10, m_14, m_18, m_1c, m_20, m_24;
};

struct SweptViewer : SweptViewerBase, SweptEntityListener, SweptPostSimListener
{
    SweptArray<SweptWorldData*> m_kWorldDataList;

    void ClearSweptEntry(int index);
    void RemoveWorldData(int index);
};

// Unregisters this viewer from the world at index, calls ClearSweptEntry, deletes the world data and removes it from the array.
// @fnv 0x00d64800
void SweptViewer::RemoveWorldData(int index)
{
    m_kWorldDataList[index]->m_pOwningWorld->AddEntityListener(this);
    m_kWorldDataList[index]->m_pOwningWorld->AddPostSimulationListener(this);
    ClearSweptEntry(index);
    delete m_kWorldDataList[index];
    m_kWorldDataList.removeAt(index);
}

namespace fnv_00d648c0 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void*, unsigned int) throw();
};
struct AudioHolder
{
    int unk00, unk04, unk08, unk0c;
    AudioAllocator* m_pAllocator;
};
struct BSAudio;
BSAudio* __cdecl FUN_00c85750();
extern int DAT_010d1918, DAT_010d18f8, DAT_010d18e8, DAT_010d18cc, DAT_010d18bc, DAT_010ccf7c;
struct AudioArray
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapBits;
    void Reset()
    {
        m_pData = 0;
        m_uCapBits = 0x80000000u;
    }
};
struct SweptViewer
{
    int m_vptr00, unk04, m_vptr08, unk0c, unk10, unk14, unk18, unk1c, m_vptr20, m_vptr24, m_vptr28, m_vptr2c;
    AudioArray m_ppData;
    void RemoveWorldData(int);
    void FUN_00ddcc60_tail();
    void Destroy();
};
// @fnv 0x00d648c0
void SweptViewer::Destroy()
{
    m_vptr00 = (int)&DAT_010d1918;
    m_vptr08 = (int)&DAT_010d18f8;
    m_vptr20 = (int)&DAT_010d18e8;
    m_vptr28 = (int)&DAT_010d18cc;
    m_vptr2c = (int)&DAT_010d18bc;
    int i = m_ppData.m_iArrayLength - 1;
    if (i >= 0)
    {
        do
        {
            RemoveWorldData(i);
            --i;
        } while (i >= 0);
    }
    AudioHolder* h = (AudioHolder*)FUN_00c85750();
    AudioAllocator* a = h->m_pAllocator;
    m_ppData.m_iArrayLength = 0;
    unsigned int uiCapBits = m_ppData.m_uCapBits;
    if ((uiCapBits & 0x80000000u) == 0)
        a->FreeArray(m_ppData.m_pData, (uiCapBits & 0x3fffffffu) * 4);
    m_ppData.Reset();
    m_vptr2c = (int)&DAT_010ccf7c;
    m_vptr28 = (int)"pFU";
    return FUN_00ddcc60_tail();
}
}  // namespace fnv_00d648c0

#include <xmmintrin.h>
struct __declspec(align(16)) D64020Vector4
{
    float m_f[4];
};

struct __declspec(align(16)) D64020Rotation
{
    D64020Vector4 m_kColumn0;
    D64020Vector4 m_kColumn1;
    D64020Vector4 m_kColumn2;

    void set(const D64020Vector4& quat);
};

struct __declspec(align(16)) D64020Transform
{
    D64020Rotation m_rotation;
    D64020Vector4 m_vTranslation;
};

inline __m128 D64020RotateDir(const D64020Rotation& m, const D64020Vector4& v)
{
    const __m128 b = *(const __m128*)v.m_f;
    const __m128 b0 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(0, 0, 0, 0));
    const __m128 r0 = _mm_mul_ps(*(const __m128*)m.m_kColumn0.m_f, b0);
    const __m128 b1 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(1, 1, 1, 1));
    const __m128 r1 = _mm_mul_ps(*(const __m128*)m.m_kColumn1.m_f, b1);
    const __m128 b2 = _mm_shuffle_ps(b, b, _MM_SHUFFLE(2, 2, 2, 2));
    const __m128 r2 = _mm_mul_ps(*(const __m128*)m.m_kColumn2.m_f, b2);
    return _mm_add_ps(_mm_add_ps(r0, r1), r2);
}

extern int g_D64020Color;

struct D64020DisplayHandler
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void unk0C();
    virtual void displayFrame(const D64020Transform& transform, unsigned long id, int tag);
};

struct D64020Constraint
{
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    D64020Vector4 m_kPivotA;
    D64020Vector4 m_kPivotB;
    D64020Vector4 m_kRotationA;
    D64020Vector4 m_kRotationB;
    D64020Vector4 m_localPivot;
};

class D64020Primary
{
  public:
    virtual void unk00();

    D64020DisplayHandler* m_pDisplayHandler;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
};

class D64020Secondary
{
  public:
    virtual void DisplayConstraintPivots(D64020Constraint* constraint);
};

class D64020Viewer : public D64020Primary, public D64020Secondary
{
  public:
    virtual void DisplayConstraintPivots(D64020Constraint* constraint);
};

// Builds two D64020Transforms from the constraint's rotation and pivot pairs and submits them to the display handler for rendering.
// @fnv 0x00d64020
void D64020Viewer::DisplayConstraintPivots(D64020Constraint* constraint)
{
    D64020Transform frame;

    frame.m_rotation.set(constraint->m_kRotationA);
    *(__m128*)frame.m_vTranslation.m_f = _mm_sub_ps(*(const __m128*)constraint->m_kPivotA.m_f,
                                                    D64020RotateDir(frame.m_rotation, constraint->m_localPivot));
    m_pDisplayHandler->displayFrame(frame, (unsigned long)constraint + 0x11, g_D64020Color);

    frame.m_rotation.set(constraint->m_kRotationB);
    *(__m128*)frame.m_vTranslation.m_f = _mm_sub_ps(*(const __m128*)constraint->m_kPivotB.m_f,
                                                    D64020RotateDir(frame.m_rotation, constraint->m_localPivot));
    m_pDisplayHandler->displayFrame(frame, (unsigned long)constraint + 0x12, g_D64020Color);
}

// sub ecx,8; jmp FUN_00d649c0 == MSVC adjustor thunk for the secondary base's override.
struct PrimaryBase
{
    virtual void FUN_00d64980();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00d64980();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00d64980
    virtual void FUN_00d64980();
};

Derived::Derived()
{}

// FUN_00d64990 : MSVC this-adjusting thunk  (sub ecx, 0x28 ; jmp <impl>)
//
// Two bases declare the same virtual, so the derived class overrides one
// function for both of them and the compiler emits one adjustor thunk per
// secondary base.  The first base is padded to 40 bytes so the second
// base lands at +0x28.  The override is DECLARED ONLY, so this thunk
// is the single defined function symbol carrying the name FUN_00d64990; a defined
// key function makes the vftable that references the thunk be emitted here.
struct A1_00d64990
{
    A1_00d64990();
    virtual void FUN_00d64990();
    char pad[0x24];
};

struct A2_00d64990
{
    A2_00d64990();
// @fnv 0x00d64990
    virtual void FUN_00d64990();
};

struct Own_00d64990 : A1_00d64990, A2_00d64990
{
    Own_00d64990();
    virtual void key_fn();  // key function - defined, so the vftable is emitted
    void FUN_00d64990();    // the shared override - declared only
};

Own_00d64990::Own_00d64990()
{}
void Own_00d64990::key_fn()
{}

Own_00d64990* make_00d64990()
{
    static Own_00d64990 o;
    return &o;
}

struct D649A0Primary
{
    virtual void vfunc00();
    virtual void FUN_00d649a0();

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
};

struct D649A0Secondary
{
    virtual void FUN_00d649a0();
};

struct D649A0Object : D649A0Primary, D649A0Secondary
{
    D649A0Object();

// @fnv 0x00d649a0
    virtual void FUN_00d649a0();
};

D649A0Object::D649A0Object()
{}

// FUN_00d649b0 : MSVC this-adjusting thunk  (sub ecx, 0x20 ; jmp <impl>)
//
// Two bases declare the same virtual, so the derived class overrides one
// function for both of them and the compiler emits one adjustor thunk per
// secondary base.  The first base is padded to 32 bytes so the second
// base lands at +0x20.  The override is DECLARED ONLY, so this thunk
// is the single defined function symbol carrying the name FUN_00d649b0; a defined
// key function makes the vftable that references the thunk be emitted here.
struct A1_00d649b0
{
    A1_00d649b0();
    virtual void FUN_00d649b0();
    char pad[0x1c];
};

struct A2_00d649b0
{
    A2_00d649b0();
// @fnv 0x00d649b0
    virtual void FUN_00d649b0();
};

struct Own_00d649b0 : A1_00d649b0, A2_00d649b0
{
    Own_00d649b0();
    virtual void key_fn();  // key function - defined, so the vftable is emitted
    void FUN_00d649b0();    // the shared override - declared only
};

Own_00d649b0::Own_00d649b0()
{}
void Own_00d649b0::key_fn()
{}

Own_00d649b0* make_00d649b0()
{
    static Own_00d649b0 o;
    return &o;
}

struct S_00d649c0_Heap
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void ReleaseBlock(void* p, int numBytes);
};

struct S_00d649c0_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S_00d649c0_Heap* m_pStreamAllocator;
    __forceinline S_00d649c0_Heap& heap()
    {
        return *m_pStreamAllocator;
    }
};

struct FUN_00d649c0
{
    virtual ~FUN_00d649c0() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    FUN_00d649c0();
    static void operator delete(void* p, unsigned int)
    {
        FUN_00d649c0* b = static_cast<FUN_00d649c0*>(p);
        FUN_00c85750().heap().ReleaseBlock(p, b->m_usMemSizeAndFlags);
    }
};

// @fnv 0x00d649c0
FUN_00d649c0::FUN_00d649c0()
{}
