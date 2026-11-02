
// src/havok/physics/utilities/weapons/hkpmountedballgun_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-11-01 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/physics/utilities/weapons/hkpmountedballgun.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/weapons/hkpmountedballgun.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/weapons/hkpmountedballgun.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
#include "havok/hkpMountedBallGun.h"
#include <xmmintrin.h>
extern unsigned int DAT_010ec004;
extern float DAT_01011d78;
extern float DAT_01016410;
struct FUN_00e46f90_Obj
{
    void FUN_00e46f90(int a);
};
struct HKStr
{
    void* m_p;
    void operator=(const char* s);
};
union HKVec
{
    __m128 v;
    struct
    {
        float x, y, z, w;
    };
};
struct MBG
{
    void* vfptr;
    unsigned short unk04;
    short unk06;
    unsigned char m_type;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    HKStr m_name;
    unsigned char m_uiKeyboardKey;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    void** m_listenerData;
    int m_listenerCount;
    int m_listenerCap;
    float m_fBulletRadius;
    float m_fBulletVelocity;
    float m_fBulletMass;
    float m_fBulletSpread;
    int m_iBulletBatchCount;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    HKVec m_kBulletDirection;
    void* m_pBulletQueue;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    HKVec m_vContactPosition;
};
struct FUN_00e45150_class
{
    MBG* Initialize(int a);
};
struct hkMemoryAllocatorQ
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
};
struct hkMemoryRouterQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocatorQ* m_pStreamAllocator;
    hkMemoryAllocatorQ& heap()
    {
        return *m_pStreamAllocator;
    }
};
void* __cdecl FUN_00c85750();
void __cdecl FUN_00cb1260(void* dst, const void* src, int numBytes);
inline hkMemoryRouterQ& getRouter()
{
    return *(hkMemoryRouterQ*)FUN_00c85750();
}
template <typename T> inline T* hkAllocateChunkQ(int n)
{
    return (T*)getRouter().heap().AllocateMemoryBlock(n * sizeof(T));
}
template <typename T> inline void hkDeallocateChunkQ(T* p, int n)
{
    getRouter().heap().ReleaseBlock(p, n * sizeof(T));
}
struct hkpRigidBody;
template <typename T> struct hkQueueQ
{
    T* m_data;
    int m_pRayCursor;
    int m_pFirstNode;
    int m_pTail;
    int m_iNodeCount;

    int getCapacity() const
    {
        return m_pRayCursor;
    }
    void releaseMemory()
    {
        if (m_pRayCursor)
            hkDeallocateChunkQ<T>(m_data, m_pRayCursor);
    }
    void FUN_00e45460(int n);
};
template struct hkQueueQ<hkpRigidBody*>;
