
// src/havok/physics/dynamics/phantom/hkpphantom.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/phantom/hkpphantom.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkpPhantom.h"

class hkListenerD07B;

template <class T>
class hkArrayD07B {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const { return m_iElementCount; }
    T& operator[](int i) { return m_data[i]; }
};

class FUN_00d07bd0_cls;

class hkListenerD07B {
public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3(FUN_00d07bd0_cls* pkObject);
};

class FUN_00d07bd0_cls {
public:
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    hkArrayD07B<hkListenerD07B*> m_kListeners;

    void FUN_00d07af0();
    void NotifyListeners();
};

// Iterates the listener array backwards, calling V3(this) on each non-null listener, then calls FUN_00d07af0.
// @fnv 0x00d07bd0
void FUN_00d07bd0_cls::NotifyListeners()
{
    for (int i = m_kListeners.GetLogicalSize() - 1; i >= 0; i--) {
        if (m_kListeners[i] != 0)
            m_kListeners[i]->V3(this);
    }
    FUN_00d07af0();
}

struct PhantomListeners : hkpPhantom {
    void __thiscall RemoveListener(void* listener);
};
// @fnv 0x00d07c10
void PhantomListeners::RemoveListener(void* listener) {
    int foundIndex;
    int index = 0;
    int count = m_kPhantomListeners.m_iElementCount;
    if (count > 0) {
        void** ppCurrent = m_kPhantomListeners.m_data;
        do {
            if (*ppCurrent == listener) {
                foundIndex = index;
                goto found;
            }
            ++index;
            ++ppCurrent;
        } while (index < count);
    }
    foundIndex = -1;
found:
    --(volatile int&)m_kPhantomListeners.m_iElementCount;
    int bytes = ((volatile int&)m_kPhantomListeners.m_iElementCount - foundIndex) * 4;
    void** destination = m_kPhantomListeners.m_data + foundIndex;
    void** source = destination + 1;
    for (int offset = 0; offset < bytes; offset += 4) {
        *(void**)((char*)destination + offset) = *(void**)((char*)source + offset);
    }
}

class PhArchive {
public:
    char unk04[0xc];
    char m_flag;
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void Write(int type, const char* name, void* ptr, int size, int extra);
};
struct PhTag;
extern PhTag DAT_01268808;
int FUN_00d06f80(void* p, int n);
class FUN_00d07cf0_cls : public hkpPhantom {
public:
    void WriteToStream(PhArchive* a, PhTag* t);
    void WritePhantomLists(PhArchive* a, int unused);
};
// Writes the overlap and phantom lists to the archive via Write, after calling WriteToStream with DAT_01268808.
// @fnv 0x00d07cf0
void FUN_00d07cf0_cls::WritePhantomLists(PhArchive* pArchive, int unused)
{
    WriteToStream(pArchive, &DAT_01268808);
    if (!(m_kPhantomOverlapListeners.m_iCapacityState & 0x80000000) || pArchive->m_flag) {
        void* base = m_kPhantomOverlapListeners.m_data;
        int e = FUN_00d06f80(base, (m_kPhantomOverlapListeners.m_iCapacityState & 0x3fffffff) * 4);
        pArchive->Write(3, "OvrlapLisPtr", m_kPhantomOverlapListeners.m_data, m_kPhantomOverlapListeners.m_iElementCount * 4, e);
    }
    if (!(m_kPhantomListeners.m_iCapacityState & 0x80000000) || pArchive->m_flag) {
        void* base = m_kPhantomListeners.m_data;
        int e = FUN_00d06f80(base, (m_kPhantomListeners.m_iCapacityState & 0x3fffffff) * 4);
        pArchive->Write(3, "PhantmLisPtr", m_kPhantomListeners.m_data, m_kPhantomListeners.m_iElementCount * 4, e);
    }
}

class hkMemoryAllocatorD07E {
public:
    virtual ~hkMemoryAllocatorD07E() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T>
    void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterD07E {
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorD07E* m_pStreamAllocator;
    hkMemoryAllocatorD07E& heap() { return *m_pStreamAllocator; }
};
extern "C" hkMemoryRouterD07E& __cdecl FUN_00c85750();

template <class T>
__forceinline void destructD07E(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T>
class hkArrayD07E {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    ~hkArrayD07E() throw()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructD07E(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorD07E& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};


class hkpPhantomOverlapListenerD07E;
class hkpPhantomListenerD07E;

class hkpPhantomD07E {
public:
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    hkArrayD07E<hkpPhantomOverlapListenerD07E*> m_kPhantomOverlapListeners;
    hkArrayD07E<hkpPhantomListenerD07E*> m_kPhantomListeners;

    void FreeListenerArrays() throw();
};

// Frees the overlap-listener and phantom-listener arrays when they are empty, releasing their buffers through the memory router's heap.
// @fnv 0x00d07e20
void hkpPhantomD07E::FreeListenerArrays() throw()
{
    if (m_kPhantomOverlapListeners.m_iElementCount == 0)
        m_kPhantomOverlapListeners.ClearAndRelease(FUN_00c85750().heap());
    if (m_kPhantomListeners.m_iElementCount == 0)
        m_kPhantomListeners.ClearAndRelease(FUN_00c85750().heap());
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

struct __declspec(intrin_type) __declspec(align(16)) __m128 {
    float x, y, z, w;
};

extern "C" __m128 _mm_add_ps(__m128, __m128);
extern "C" __m128 _mm_mul_ps(__m128, __m128);
extern "C" __m128 _mm_min_ps(__m128, __m128);
extern "C" __m128 _mm_max_ps(__m128, __m128);

extern float DAT_011b6d70;
extern float DAT_01267e30;

struct __declspec(align(16)) hkQuadD07950 {
    hkReal x, y, z, w;
};

struct hkAabbD07950 {
    hkVector4 m_kMinimumCorner;
    hkVector4 m_kMaximumCorner;
};

struct BroadPhaseD07950 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    hkVector4 m_kVectorAt40;
    hkVector4 m_kVectorAt50;
    hkVector4 m_vScale;
};

struct WorldD07950 {
    int unk00; int unk04; int unk08; int unk0C; int unk10; int unk14; int unk18; int unk1C;
    int unk20; int unk24; int unk28; int unk2C; int unk30; int unk34; int unk38; int unk3C;
    int unk40; int unk44; int unk48; int unk4C; int unk50; int unk54; int unk58; int unk5C;
    int unk60; int unk64; int unk68; int unk6C; int unk70; int unk74;
    BroadPhaseD07950* m_pJobSemaphore;
};

__forceinline int hkToIntFastD07950(hkReal r)
{
    return fnv_FloatToInt(r);
}

__forceinline hkReal compAtD07950(const hkQuadD07950& v, int i)
{
    const hkReal* p = &v.x;
    return p[i];
}

__forceinline void zeroExpD07950(hkpCollidableBoundingVolumeData& b)
{
    b.m_ucExpansionShift = 0;
    b.m_ucExpansionMin[0] = 0;
    b.m_ucExpansionMin[1] = 0;
    b.m_ucExpansionMin[2] = 0;
    b.m_ucExpansionMax[0] = 0;
    b.m_ucExpansionMax[1] = 0;
    b.m_ucExpansionMax[2] = 0;
}

class FUN_00d07950_cls : public hkpPhantom {
public:
    void FUN_00d07950(const hkAabbD07950& aabb);
};

// @fnv 0x00d07950
void FUN_00d07950_cls::FUN_00d07950(const hkAabbD07950& aabb)
{
    BroadPhaseD07950* pBroadPhase = ((WorldD07950*)m_pOwningWorld)->m_pJobSemaphore;
    const __m128 vClampMax = *(const __m128*)&DAT_011b6d70;

    __m128 vMin = _mm_add_ps(*(const __m128*)&pBroadPhase->m_kVectorAt40, *(const __m128*)&aabb.m_kMinimumCorner);
    vMin = _mm_mul_ps(vMin, *(const __m128*)&pBroadPhase->m_vScale);
    vMin = _mm_min_ps(vMin, vClampMax);
    vMin = _mm_max_ps(vMin, *(const __m128*)&DAT_01267e30);
    hkQuadD07950 kMinBoundsCur;
    *(__m128*)&kMinBoundsCur = vMin;
    hkUint32* outMin = m_kCollidable.m_kBoundingVolumeData.m_kMinimumCorner;
    outMin[0] = hkToIntFastD07950(compAtD07950(kMinBoundsCur, 0));
    outMin[1] = hkToIntFastD07950(compAtD07950(kMinBoundsCur, 1));
    outMin[2] = hkToIntFastD07950(compAtD07950(kMinBoundsCur, 2));
    outMin[3] = hkToIntFastD07950(compAtD07950(kMinBoundsCur, 3));

    __m128 vMax = _mm_add_ps(*(const __m128*)&pBroadPhase->m_kVectorAt50, *(const __m128*)&aabb.m_kMaximumCorner);
    vMax = _mm_mul_ps(vMax, *(const __m128*)&pBroadPhase->m_vScale);
    vMax = _mm_min_ps(vMax, vClampMax);
    vMax = _mm_max_ps(vMax, *(const __m128*)&DAT_01267e30);
    hkQuadD07950 kMaxPoint;
    *(__m128*)&kMaxPoint = vMax;
    hkUint32* outMax = m_kCollidable.m_kBoundingVolumeData.m_kMaximumCorner;
    outMax[0] = hkToIntFastD07950(compAtD07950(kMaxPoint, 0));
    outMax[1] = hkToIntFastD07950(compAtD07950(kMaxPoint, 1));
    outMax[2] = hkToIntFastD07950(compAtD07950(kMaxPoint, 2));
    outMax[3] = hkToIntFastD07950(compAtD07950(kMaxPoint, 3));

    zeroExpD07950(m_kCollidable.m_kBoundingVolumeData);
}

inline void MemCopyD07A90(void* pvDst, const void* pvSrc, int nbytes)
{
    char* pcDst = static_cast<char*>(pvDst);
    const char* pcSrc = static_cast<const char*>(pvSrc);
    for (int i = 0; i < nbytes; i += 4)
        *reinterpret_cast<unsigned int*>(pcDst + i) = *reinterpret_cast<const unsigned int*>(pcSrc + i);
}
template <class T> struct ArrayD07A90 {
    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        MemCopyD07A90(m_data + index, m_data + index + 1, (m_iElementCount - index) * sizeof(T));
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct ListenerD07A90;
struct PhantomD07A90 {
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    ArrayD07A90<ListenerD07A90*> m_kPhantomOverlapListeners;
    void FUN_00d07a90();
};

// Iterates m_kPhantomOverlapListeners in reverse and removes any null entries via removeAtAndCopy.
// @fnv 0x00d07a90
void PhantomD07A90::FUN_00d07a90()
{
    for (int i = m_kPhantomOverlapListeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (m_kPhantomOverlapListeners.m_data[i] == 0)
            m_kPhantomOverlapListeners.removeAtAndCopy(i);
    }
}

inline void MemCopyD07AF0(void* pvDst, const void* pvSrc, int nbytes)
{
    char* pcDst = static_cast<char*>(pvDst);
    const char* pcSrc = static_cast<const char*>(pvSrc);
    for (int i = 0; i < nbytes; i += 4)
        *reinterpret_cast<unsigned int*>(pcDst + i) = *reinterpret_cast<const unsigned int*>(pcSrc + i);
}
template <class T> struct ArrayD07AF0 {
    void removeAtAndCopy(int index)
    {
        m_iElementCount--;
        MemCopyD07AF0(m_data + index, m_data + index + 1, (m_iElementCount - index) * sizeof(T));
    }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
struct ListenerD07AF0;
struct PhantomD07AF0 {
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    ArrayD07AF0<ListenerD07AF0*> m_kPhantomListeners;
    void FUN_00d07af0();
};

// Iterates m_kPhantomListeners in reverse and removes any null entries via removeAtAndCopy.
// @fnv 0x00d07af0
void PhantomD07AF0::FUN_00d07af0()
{
    for (int i = m_kPhantomListeners.m_iElementCount - 1; i >= 0; i--)
    {
        if (m_kPhantomListeners.m_data[i] == 0)
            m_kPhantomListeners.removeAtAndCopy(i);
    }
}

struct LS_cls;
struct hkArr {
    void** m_data;
    int m_iElementCount;
    int m_pRayCursor;
    void** operator[](int i) { return m_data + i; }
};
struct Fun_cls {
    void* m_unk[38];
    hkArr m_lsn;
    void __thiscall FUN_00d07b50();
    void __thiscall FUN_00d07af0();
};
struct LS_cls {
    virtual void vf0a();
    virtual void vf0b();
    virtual void phantomRemoved(Fun_cls* phantom);
};

// Iterates the m_lsn array in reverse, calling phantomRemoved on each non-null entry, then calls FUN_00d07af0.
// @fnv 0x00d07b50
void Fun_cls::FUN_00d07b50()
{
    for (int i = m_lsn.m_iElementCount - 1; i >= 0; --i) {
        if (*m_lsn[i])
            ((LS_cls*)*m_lsn[i])->phantomRemoved(this);
    }
    FUN_00d07af0();
}

struct PhantomLsn {
    virtual void V0();
    virtual void V1(void* owner);
};

template <class T> struct ArrRef {
    T* m_data;
    int m_iElementCount;
    T& operator[](int i) { return m_data[i]; }
    int GetLogicalSize() const { return m_iElementCount; }
};

struct PhantomCls {
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
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    ArrRef<PhantomLsn*> m_kListeners;

    void FUN_00d07af0();
    void FUN_00d07b90();
};

// Iterates m_kListeners in reverse, calling V1 on each non-null entry with this, then calls FUN_00d07af0.
// @fnv 0x00d07b90
void PhantomCls::FUN_00d07b90()
{
    for (int i = m_kListeners.GetLogicalSize(); --i >= 0; ) {
        if (m_kListeners[i]) {
            m_kListeners[i]->V1(this);
        }
    }
    FUN_00d07af0();
}

inline int FindListener(const hkArray<void*>& listeners, void* listener)
{
    for (int index = 0; index < listeners.m_iElementCount; ++index) {
        if (listeners.m_data[index] == listener) return index;
    }
    return -1;
}

inline void CopyPointerRange(void** destination, void** source, int byteCount)
{
    for (int offset = 0; offset < byteCount; offset += 4) {
        *(void**)((char*)destination + offset) =
            *(void**)((char*)source + offset);
    }
}

struct PhRemoveListener : hkpPhantom {
    void FUN_00d07c80(void* listener);
};

// Removes the given listener from m_kPhantomOverlapListeners by shifting subsequent entries down and decrementing the count.
// @fnv 0x00d07c80
void PhRemoveListener::FUN_00d07c80(void* listener)
{
    int index = FindListener(m_kPhantomOverlapListeners, listener);
    --m_kPhantomOverlapListeners.m_iElementCount;
    CopyPointerRange(m_kPhantomOverlapListeners.m_data + index,
                     m_kPhantomOverlapListeners.m_data + index + 1,
                     (m_kPhantomOverlapListeners.m_iElementCount - index) * sizeof(void*));
}

template <int SIZE>
__forceinline void memCpyOneAlignedXd07da0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXd07da0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXd07da0 {
    extern "C" hkMemoryRouterXd07da0& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T>
class hkArrayXd07da0 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXd07da0& router = hkRouterXd07da0::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXd07da0<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class hkOwnerXd07da0 {
public:
    int unk00[38];
    hkArrayXd07da0<void*> m_kNode;

    void AddItem(void* item);
};

// @fnv 0x00d07da0
void hkOwnerXd07da0::AddItem(void* item)
{
    m_kNode.AddBack(item);
}

template <int SIZE>
__forceinline void memCpyOneAlignedXd07de0(void* dst, const void* src)
{
    const unsigned int* s = (const unsigned int*)src;
    unsigned int* d = (unsigned int*)dst;
    int i = 0;
    do {
        d[i] = s[i];
    } while (++i < SIZE / 4);
}

struct hkMemoryRouterXd07de0 {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    void* m_pStreamAllocator;
};

namespace hkRouterXd07de0 {
    extern "C" hkMemoryRouterXd07de0& __cdecl FUN_00c85750() throw();
}
void __cdecl ResizeAudioStream(void* m_pPoolBase, void* pArray, int iSizeElem);

template <class T>
class hkArrayXd07de0 {
public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }
    __forceinline void AddBack(const T& e)
    {
        hkMemoryRouterXd07de0& router = hkRouterXd07de0::FUN_00c85750();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(router.m_pStreamAllocator, this, sizeof(T));
        memCpyOneAlignedXd07de0<sizeof(T)>(m_data + m_iElementCount, &e);
        m_iElementCount++;
    }
};

class hkOwnerXd07de0 {
public:
    int unk00[35];
    hkArrayXd07de0<void*> m_kNode;

    void FUN_00d07de0(void* item);
};

// Adds the given item to the owner's internal array of pointers.
// @fnv 0x00d07de0
void hkOwnerXd07de0::FUN_00d07de0(void* item)
{
    m_kNode.AddBack(item);
}

class hkMemoryAllocatorD07 {
public:
    virtual void v00();
    virtual void* AllocateMemoryBlock(int iNumBytes);
    virtual void ReleaseBlock(void* p, int iNumBytes);
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut);
    virtual void ReturnMemory(void* p, int iNumBytes);
};
struct hkMemoryRouterD07 {
    void* m_aiEntries;
    void* m_stackStart;
    void* m_stackEnd;
    hkMemoryAllocatorD07* m_pTemp;
    hkMemoryAllocatorD07* m_pStreamAllocator;
    hkMemoryAllocatorD07& heap() { return *m_pStreamAllocator; }
};
hkMemoryRouterD07& __cdecl GetMemoryRouterD07() throw();

template <typename T> struct hkArrayD07 {
    hkArrayD07() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000) {}
    __forceinline ~hkArrayD07() throw()
    {
        hkMemoryAllocatorD07& kAlloc = GetMemoryRouterD07().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    int GetLogicalSize() const { return m_iElementCount; }
    T* begin() { return m_data; }
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
template <typename T> __forceinline T* hkAllocateStackD07(int n)
{
    hkMemoryRouterD07& kRouter = GetMemoryRouterD07();
    char* pcCur = (char*)kRouter.m_aiEntries;
    kRouter.m_aiEntries = pcCur + ((n * sizeof(T) + 0x7f) & ~0x7f);
    return (T*)pcCur;
}
template <typename T> __forceinline void hkDeallocateStackD07(T* p)
{
    GetMemoryRouterD07().m_aiEntries = p;
}
template <typename T> struct hkLocalArrayD07 : public hkArrayD07<T> {
    __forceinline hkLocalArrayD07(int n) throw()
    {
        T* pLocal = hkAllocateStackD07<T>(n);
        this->m_data = pLocal;
        this->m_iCapacityState = n | 0x80000000;
        m_pStackAllocation = pLocal;
    }
    __forceinline ~hkLocalArrayD07() throw()
    {
        if (m_pStackAllocation == this->m_data)
            this->m_iElementCount = 0;
        hkDeallocateStackD07(m_pStackAllocation);
    }
    T* m_pStackAllocation;
};

struct hkAabbD07;
class hkpBroadPhaseHandleD07;
class hkpPhantomD07;
struct hkpBroadPhaseHandlePairD07 {
    hkpBroadPhaseHandleD07* m_kPointA;
    hkpBroadPhaseHandleD07* m_kPointB;
};

class hkpBroadPhaseD07 {
public:
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
    virtual void UpdateAabbs(hkpBroadPhaseHandleD07* pkObjects[], const hkAabbD07* pkAabbs, int iNumObjects,
                             hkArrayD07<hkpBroadPhaseHandlePairD07>& kAddedPairs, hkArrayD07<hkpBroadPhaseHandlePairD07>& kRemovedPairs) throw();
    void lock() throw() { if (m_pWorldLock) lockImplementation(); }
    void unlock() throw() { if (m_pWorldLock) unlockImplementation(); }
    void lockImplementation() throw();
    void unlockImplementation() throw();
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    void* m_pWorldLock;
};

class hkpCollidableCollidableFilterD07 {
public:
    virtual void v00();
};
class hkpCollisionFilterD07 {
public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkpCollidableCollidableFilterD07 m_kCollidableFilter;
};

class hkpTypedBroadPhaseDispatcherD07 {
public:
    static void __cdecl SortPairs(hkArrayD07<hkpBroadPhaseHandlePairD07>& kNewPairs, hkArrayD07<hkpBroadPhaseHandlePairD07>& kDelPairs) throw();
    void DispatchCollisionPairs(hkpBroadPhaseHandlePairD07* pkPairs, int iNumPairs) throw();
    void DispatchNewPairs(hkpBroadPhaseHandlePairD07* pkPairs, int iNumPairs, const hkpCollidableCollidableFilterD07* pkFilter) throw();
};

class hkpKdTreeManagerD07 {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void setDirty(int aiDirtyFlags) throw();
};

struct hkWorldOperationD07 {
    enum Type { UPDATE_PHANTOM_BP = 0x11 };
    struct TypeTag {
        TypeTag(Type eType) : m_type(static_cast<unsigned char>(eType)) {}
        unsigned char m_type;
    };
    struct PhantomBroadphaseUpdate : public TypeTag {
        PhantomBroadphaseUpdate() : TypeTag(UPDATE_PHANTOM_BP) {}
        hkpPhantomD07* m_pPhantom;
        const hkAabbD07* m_kBounds;
    };
};

class hkpWorldD07 {
public:
    bool areCriticalOperationsLockedForPhantoms() const { return m_iCriticalOperationsLockCountForPhantoms + m_iCriticalOperationsLockCount != 0; }
    void lockCriticalOperations() { m_iCriticalOperationsLockCount++; }
    void unlockCriticalOperations() { m_iCriticalOperationsLockCount--; }
    __forceinline void attemptToExecutePendingOperations()
    {
        if (m_iCriticalOperationsLockCount == 0 && !m_bBlockExecutingPendingOperations) {
            if (m_iPendingOperationCount)
                ExecutePendingOperations();
            if (m_iPendingOperationQueueCount == 1 && m_iQueuedOperationCount)
                ExecutePendingOperationQueues();
        }
    }
    __forceinline void unlockAndAttemptToExecutePendingOperations()
    {
        unlockCriticalOperations();
        attemptToExecutePendingOperations();
    }
    const hkpCollidableCollidableFilterD07* getCollisionFilter() const
    {
        return m_pCollisionFilter ? &m_pCollisionFilter->m_kCollidableFilter : 0;
    }
    void AddWorldOperation(const hkWorldOperationD07::TypeTag& kOperation) throw();
    void ExecutePendingOperations() throw();
    void ExecutePendingOperationQueues() throw();

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
    hkpBroadPhaseD07* m_pJobSemaphore;
    hkpKdTreeManagerD07* m_pKdTreeManager;
    unsigned int unk60;
    hkpTypedBroadPhaseDispatcherD07* m_pBroadPhaseDispatcher;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    hkpCollisionFilterD07* m_pCollisionFilter;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    int m_iPendingOperationCount;
    int m_iQueuedOperationCount;
    int m_iCriticalOperationsLockCount;
    int m_iCriticalOperationsLockCountForPhantoms;
    bool m_bBlockExecutingPendingOperations;
    bool m_bBlockExecutingPendingOperationQueues;
    void* m_pPendingOperationQueues;
    int m_iPendingOperationQueueCount;
    unsigned int unka8;
    unsigned int unkac;
    unsigned int unkb0;
    unsigned int unkb4;
    unsigned int unkb8;
    unsigned int unkbc;
    unsigned int unkc0;
    unsigned int unkc4;
    unsigned int unkc8;
    unsigned int unkcc;
    unsigned int unkd0;
    unsigned int unkd4;
    unsigned int unkd8;
    unsigned int unkdc;
    unsigned int unke0;
    unsigned int unke4;
    unsigned int unke8;
    unsigned int unkec;
    unsigned int unkf0;
    unsigned int unkf4;
    unsigned int unkf8;
    unsigned int unkfc;
    unsigned int unk100;
    unsigned int unk104;
    unsigned int unk108;
    unsigned int unk10c;
    unsigned int unk110;
    unsigned int unk114;
    unsigned int unk118;
    unsigned int unk11c;
    unsigned int unk120;
    unsigned int unk124;
    unsigned int unk128;
    unsigned int unk12c;
    unsigned int unk130;
    unsigned int unk134;
    unsigned int unk138;
    unsigned int unk13c;
    unsigned int unk140;
    unsigned int unk144;
    unsigned int unk148;
    unsigned int unk14c;
    unsigned int unk150;
    unsigned int unk154;
    unsigned int unk158;
    unsigned int unk15c;
    unsigned int unk160;
    unsigned int unk164;
    unsigned int unk168;
    unsigned int unk16c;
    unsigned int unk170;
    unsigned int unk174;
    unsigned int unk178;
    unsigned int unk17c;
    unsigned int unk180;
    unsigned int unk184;
    unsigned int unk188;
    unsigned int unk18c;
    unsigned int unk190;
    unsigned int unk194;
    unsigned int unk198;
    unsigned int unk19c;
    unsigned int unk1a0;
    unsigned int unk1a4;
    unsigned int unk1a8;
    unsigned int unk1ac;
    unsigned int unk1b0;
    unsigned int unk1b4;
    unsigned int unk1b8;
    unsigned int unk1bc;
    unsigned int unk1c0;
    unsigned int unk1c4;
    unsigned int unk1c8;
    unsigned int unk1cc;
    unsigned int unk1d0;
    unsigned int unk1d4;
    unsigned int unk1d8;
    unsigned int unk1dc;
    unsigned int unk1e0;
    unsigned int unk1e4;
    unsigned int unk1e8;
    unsigned int unk1ec;
    unsigned int unk1f0;
    unsigned int unk1f4;
    unsigned int unk1f8;
    unsigned int unk1fc;
    unsigned int unk200;
    unsigned int unk204;
    unsigned int unk208;
    unsigned int unk20c;
    unsigned int unk210;
    unsigned int unk214;
    unsigned int unk218;
    unsigned int unk21c;
    unsigned int unk220;
    unsigned int unk224;
    unsigned int unk228;
    unsigned int unk22c;
    unsigned int unk230;
    unsigned int unk234;
    unsigned int unk238;
    unsigned int unk23c;
    unsigned int unk240;
    unsigned int unk244;
    unsigned int unk248;
    unsigned int unk24c;
    unsigned int unk250;
    unsigned int unk254;
    unsigned int unk258;
    unsigned int unk25c;
    unsigned int unk260;
    unsigned int unk264;
    unsigned int unk268;
    unsigned int unk26c;
    unsigned int unk270;
    unsigned int unk274;
    unsigned int unk278;
    unsigned int unk27c;
    unsigned int unk280;
    unsigned int unk284;
    unsigned int unk288;
    unsigned int unk28c;
    unsigned int unk290;
    unsigned int unk294;
    unsigned int unk298;
    unsigned int unk29c;
    unsigned int unk2a0;
    unsigned int unk2a4;
    unsigned int unk2a8;
    unsigned int unk2ac;
    unsigned int unk2b0;
    unsigned int unk2b4;
    unsigned int unk2b8;
    unsigned int unk2bc;
    unsigned int unk2c0;
    unsigned int unk2c4;
    unsigned int unk2c8;
    unsigned int unk2cc;
    unsigned int unk2d0;
    unsigned int unk2d4;
    unsigned int unk2d8;
    unsigned int unk2dc;
    unsigned int unk2e0;
    unsigned int unk2e4;
    unsigned int unk2e8;
    unsigned int unk2ec;
    unsigned int unk2f0;
    unsigned int unk2f4;
    unsigned int unk2f8;
    unsigned int unk2fc;
    unsigned int unk300;
    unsigned int unk304;
    unsigned int unk308;
    unsigned int unk30c;
    unsigned int unk310;
    unsigned int unk314;
    unsigned int unk318;
    unsigned int unk31c;
    unsigned int unk320;
    unsigned int unk324;
    unsigned int unk328;
    unsigned int unk32c;
    unsigned int unk330;
    unsigned int unk334;
    unsigned int unk338;
    int m_iBroadPhaseNumObjects;
};

class hkpPhantomD07 {
public:
    virtual void v00();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkpWorldD07* m_pOwningWorld;
    unsigned int m_ulUserData;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    hkpBroadPhaseHandleD07* getBroadPhaseHandle() { return reinterpret_cast<hkpBroadPhaseHandleD07*>(&m_kBroadPhaseHandle); }
    unsigned int m_kBroadPhaseHandle;
};

class hkpAabbPhantomD07 : public hkpPhantomD07 {
public:
    void FUN_00d07ec0(const hkAabbD07& kNewAabb) throw();
    void updateOverlaps() throw();
    void setAabbData(const hkAabbD07& kNewAabb) throw();
};

// Updates the phantom's AABB in the broad phase, dispatches collision pair changes, and marks the KD-tree dirty if the world owns one.
// @fnv 0x00d07ec0
void hkpAabbPhantomD07::FUN_00d07ec0(const hkAabbD07& kNewAabb) throw()
{
    if (m_pOwningWorld) {
        if (m_pOwningWorld->areCriticalOperationsLockedForPhantoms()) {
            hkWorldOperationD07::PhantomBroadphaseUpdate kOp;
            kOp.m_pPhantom = this;
            kOp.m_kBounds = &kNewAabb;
            m_pOwningWorld->AddWorldOperation(kOp);
            return;
        }

        m_pOwningWorld->lockCriticalOperations();

        hkLocalArrayD07<hkpBroadPhaseHandlePairD07> kNewPairs(m_pOwningWorld->m_iBroadPhaseNumObjects);
        hkLocalArrayD07<hkpBroadPhaseHandlePairD07> kDelPairs(m_pOwningWorld->m_iBroadPhaseNumObjects);

        hkpBroadPhaseHandleD07* pkThisObj = getBroadPhaseHandle();
        m_pOwningWorld->m_pJobSemaphore->lock();
        m_pOwningWorld->m_pJobSemaphore->UpdateAabbs(&pkThisObj, &kNewAabb, 1, kNewPairs, kDelPairs);

        if (kNewPairs.GetLogicalSize() != 0 || kDelPairs.GetLogicalSize() != 0) {
            hkpTypedBroadPhaseDispatcherD07::SortPairs(kNewPairs, kDelPairs);
            m_pOwningWorld->m_pBroadPhaseDispatcher->DispatchCollisionPairs(kDelPairs.begin(), kDelPairs.GetLogicalSize());
            m_pOwningWorld->m_pBroadPhaseDispatcher->DispatchNewPairs(kNewPairs.begin(), kNewPairs.GetLogicalSize(), m_pOwningWorld->getCollisionFilter());
            updateOverlaps();
        }
        m_pOwningWorld->m_pJobSemaphore->unlock();

        setAabbData(kNewAabb);

        if (m_pOwningWorld->m_pKdTreeManager)
            m_pOwningWorld->m_pKdTreeManager->setDirty(0);

        m_pOwningWorld->unlockAndAttemptToExecutePendingOperations();
    }
}

struct S00d08130_Arr {
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline void ClearAndRelease(hkMemoryAllocatorD07E& kAlloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<void*>(m_data, m_iCapacityState & 0x3fffffff);
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class FUN_00d08130 {
public:
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
    int unk80;
    int unk84;
    int unk88;
    S00d08130_Arr m_kPhantomOverlapListeners;
    S00d08130_Arr m_kPhantomListeners;

    void NotifyElements();
    void FUN_00c9d3b0();
    virtual ~FUN_00d08130();
};

// Destructor: calls NotifyElements, releases m_kPhantomListeners and m_kPhantomOverlapListeners, then calls FUN_00c9d3b0.
// @fnv 0x00d08130
FUN_00d08130::~FUN_00d08130()
{
    NotifyElements();
    m_kPhantomListeners.ClearAndRelease(FUN_00c85750().heap());
    m_kPhantomOverlapListeners.ClearAndRelease(FUN_00c85750().heap());
    FUN_00c9d3b0();
}
