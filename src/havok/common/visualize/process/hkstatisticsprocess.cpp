
// src/havok/common/visualize/process/hkstatisticsprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/process/hkstatisticsprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void FreeArray(void* apMemory, unsigned int auiCapacity) throw();
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

struct ArrayMember
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~ArrayMember() throw()
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->FreeArray(m_pData, uCapacity & 0x3fffffff);
        m_pData = 0;
        m_uCapacity = 0x80000000;
    }
};

struct PtrArrayMember
{
    void** m_ppData;
    int m_iArrayLength;
    unsigned int m_uCapacity;

    ~PtrArrayMember() throw()
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->FreeArray(m_ppData, (uCapacity & 0x3fffffff) * 4);
        m_ppData = 0;
        m_uCapacity = 0x80000000;
    }
};

struct FirstBase
{
    virtual void a00();
    int m_i04;

    virtual ~FirstBase() throw()
    {}
};

struct SecondBase
{
    virtual void b00();

    virtual ~SecondBase() throw()
    {}
};

struct FUN_00ddc0b0 : FirstBase, SecondBase
{
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    PtrArrayMember m_kFirst;
    ArrayMember m_kSecond;
    ArrayMember m_kThird;

    virtual ~FUN_00ddc0b0() throw();
};

// Destructor of a container holding three array members, which are freed by their own destructors.
// @fnv 0x00ddc0b0
FUN_00ddc0b0::~FUN_00ddc0b0() throw()
{}

extern int DAT_01269cd8;

// @fnv 0x00ddc820
int FUN_00ddc820()
{
    return DAT_01269cd8;
}

#include <windows.h>
extern DWORD DAT_0126835c;
struct TlsBuf
{
    int* m_pCurrent;
    int* m_pRecordEnd;
};
struct Allocator
{
    virtual void a0();
    virtual void a1();
    virtual void a2(void* p, int bytes);
    virtual void* Alloc(int* pBytes);
    virtual void Free(void* p, int bytes);
};
struct Singleton
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    Allocator* m_10;
};
__forceinline Singleton* GetSingleton()
{
    return reinterpret_cast<Singleton*>(FUN_00c85750());
}
void __cdecl ResizeAudioStream(Allocator* ctx, void* pVec, int elem);
void __cdecl FUN_00c908c0(Allocator* ctx, void* pVec, int sz, int elem);
struct IntVec
{
    int* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};
struct SrcArr
{
    int* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};
struct Entry
{
    int m_00;
    int m_04;
    SrcArr m_08;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    SrcArr m_2c;
};
struct Pair
{
    int m_00;
    int m_04;
};
struct ObjA
{
    Pair* m_pData;
    int m_04;
    int m_iArrayLength;
    void EnsureCapacity(Allocator* ctx, int zero);
    void ProcessArgument(Allocator* ctx);
    void FUN_00a29680();
    __forceinline int first() const
    {
        int i;
        for (i = 0; i <= m_iArrayLength; ++i)
            if (m_pData[i].m_00 != -1)
                break;
        return i;
    }
    __forceinline int next(int previous) const
    {
        int i;
        for (i = previous + 1; i <= m_iArrayLength; ++i)
            if (m_pData[i].m_00 != -1)
                break;
        return i;
    }
    __forceinline bool valid(int i) const
    {
        return i <= m_iArrayLength;
    }
};
void __cdecl ProcessRecords(int a, int b, ObjA* o);
struct Sub8
{
    int m_00;
    int m_04;
    void FUN_00cb0c10(int a);
};
struct Elem16
{
    long long m_00;
    Sub8 m_08;
    void FUN_00e0bf20();
};
struct Vec3
{
    Elem16* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
    void FUN_00e0f6e0();
    void FUN_00ddc870();
    __forceinline Elem16& expand(Allocator& allocator)
    {
        if (m_iArrayLength == (m_iCapacity & 0x3fffffff))
            ResizeAudioStream(&allocator, this, 0x10);
        Elem16* item = m_pData + m_iArrayLength;
        if (item != 0)
            item->FUN_00e0bf20();
        return m_pData[m_iArrayLength++];
    }
};
extern char DAT_010c9368;
extern char DAT_0102e388;
extern char DAT_010d6ae8;
extern char DAT_0126c830;
struct CharVec
{
    char* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};
__forceinline void ReserveChars(Allocator& allocator, CharVec* array, int count)
{
    int cap = array->m_iCapacity & 0x3fffffff;
    if (cap < count)
    {
        int grown = cap + cap;
        FUN_00c908c0(&allocator, array, count < grown ? grown : count, 1);
    }
}
struct Elem12
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    int m_10;
    int m_14;
};
struct Vec4
{
    Elem12* m_pData;
    int m_iArrayLength;
    int m_iCapacity;
};
struct MiniStr
{
    char* m_00;
    void FUN_00dc1680(void* p);
};
struct SObj
{
    void* m_00;
    short m_04;
    short m_06;
    CharVec* m_08;
    int m_0c;
    int m_10;
};
void __cdecl FUN_00e0bd40(SObj* s, MiniStr* ms, int a, int b, Vec3* v3, void* g, Vec4* v4);
struct Stream
{
    void FUN_00d60960(int total);
    void FUN_00d605d0(int a);
    void WriteInt(int a);
    void FUN_00d607b0(int a, int b);
};
struct ThisCls
{
    int m_00;
    int m_04;
    int m_08;
    Stream* m_0c;
    int m_10;
    int m_14;
    Entry** m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    CharVec m_30;
    Stream* m_0c_ptr()
    {
        return (Stream*)m_0c;
    }
    void WriteToStream(int arg);
};
// When sum is positive, writes m_24 data, m_30 text, and ranges derived from m_18 to m_0c, then frees local buffers.
// @fnv 0x00ddc1c0
void ThisCls::WriteToStream(int aiUnused)
{
    if (m_0c == 0)
        return;
    Vec4 vec4;
    IntVec vecStarts;
    IntVec vecEnds;
    vec4.m_iCapacity = (int)0x80000000;
    vecStarts.m_iCapacity = (int)0x80000000;
    vecEnds.m_iCapacity = (int)0x80000000;
    vec4.m_pData = 0;
    vec4.m_iArrayLength = 0;
    vecStarts.m_pData = 0;
    vecStarts.m_iArrayLength = 0;
    vecEnds.m_pData = 0;
    vecEnds.m_iArrayLength = 0;
    int count = m_1c;
    {
        for (int i = 0; i < count; i++)
        {
            if (m_18[i]->m_08.m_iArrayLength > 0)
            {
                SrcArr* pSrcStarts = &m_18[i]->m_08;
                Singleton* s = GetSingleton();
                Allocator* alloc = s->m_10;
                if ((vecStarts.m_iCapacity & 0x3fffffff) < pSrcStarts->m_iArrayLength)
                {
                    if ((vecStarts.m_iCapacity & 0x80000000u) == 0)
                        alloc->Free(vecStarts.m_pData, (vecStarts.m_iCapacity & 0x3fffffff) * 4);
                    int bytes = pSrcStarts->m_iArrayLength * 4;
                    vecStarts.m_pData = (int*)alloc->Alloc(&bytes);
                    vecStarts.m_iCapacity = bytes / 4;
                }
                {
                    int iCopyCount = pSrcStarts->m_iArrayLength;
                    vecStarts.m_iArrayLength = iCopyCount;
                    int* pSrcData = pSrcStarts->m_pData;
                    int* pDstData = vecStarts.m_pData;
                    for (int k = 0; k < iCopyCount; k++)
                        pDstData[k] = pSrcData[k];
                }
                SrcArr* pSrcEnds = &m_18[i]->m_2c;
                Singleton* pSingleton2 = GetSingleton();
                Allocator* pAllocator2 = pSingleton2->m_10;
                if ((vecEnds.m_iCapacity & 0x3fffffff) < pSrcEnds->m_iArrayLength)
                {
                    if ((vecEnds.m_iCapacity & 0x80000000u) == 0)
                        pAllocator2->Free(vecEnds.m_pData, (vecEnds.m_iCapacity & 0x3fffffff) * 4);
                    int bytes2 = pSrcEnds->m_iArrayLength * 4;
                    vecEnds.m_pData = (int*)pAllocator2->Alloc(&bytes2);
                    vecEnds.m_iCapacity = bytes2 / 4;
                }
                {
                    int iCopyCount2 = pSrcEnds->m_iArrayLength;
                    vecEnds.m_iArrayLength = iCopyCount2;
                    int* pSrcData2 = pSrcEnds->m_pData;
                    int* pDstData2 = vecEnds.m_pData;
                    for (int k = 0; k < iCopyCount2; k++)
                        pDstData2[k] = pSrcData2[k];
                }
                break;
            }
        }
    }
    if (vecStarts.m_iArrayLength == 0)
    {
        TlsBuf* pTlsBuf = (TlsBuf*)TlsGetValue(DAT_0126835c);
        int cur = (int)pTlsBuf->m_pCurrent;
        int end = (int)pTlsBuf->m_pRecordEnd;
        Singleton* s = GetSingleton();
        if (vecStarts.m_iArrayLength == (vecStarts.m_iCapacity & 0x3fffffff))
            ResizeAudioStream(s->m_10, &vecStarts, 4);
        vecStarts.m_pData[vecStarts.m_iArrayLength] = cur;
        vecStarts.m_iArrayLength++;
        Singleton* pSingleton2 = GetSingleton();
        if (vecEnds.m_iArrayLength == (vecEnds.m_iCapacity & 0x3fffffff))
            ResizeAudioStream(pSingleton2->m_10, &vecEnds, 4);
        vecEnds.m_pData[vecEnds.m_iArrayLength] = end;
        vecEnds.m_iArrayLength++;
    }
    CharVec* pOutText = &m_30;
    {
        ReserveChars(*GetSingleton()->m_10, pOutText, 0);
        pOutText->m_iArrayLength = 0;
    }
    int iTotalRangeLen = 0;
    ObjA objRecords;
    objRecords.m_pData = 0;
    objRecords.m_04 = 0;
    objRecords.m_iArrayLength = -1;
    Singleton* pSingleton4 = GetSingleton();
    objRecords.EnsureCapacity(pSingleton4->m_10, 0);
    Vec3 vecProcessed;
    vecProcessed.FUN_00e0f6e0();
    for (int i = 0; i < vecStarts.m_iArrayLength; i++)
    {
        ProcessRecords(vecStarts.m_pData[i], vecEnds.m_pData[i], &objRecords);
        iTotalRangeLen += vecEnds.m_pData[i] - vecStarts.m_pData[i];
    }
    {
        int iRecordIdx = objRecords.first();
        while (objRecords.valid(iRecordIdx))
        {
            Elem16* pElem = &vecProcessed.expand(*GetSingleton()->m_10);
            pElem->m_00 = (long long)objRecords.m_pData[iRecordIdx].m_00;
            pElem->m_08.FUN_00cb0c10(objRecords.m_pData[iRecordIdx].m_04);
            iRecordIdx = objRecords.next(iRecordIdx);
        }
    }
    int iTextLen = pOutText->m_iArrayLength;
    SObj objStr;
    objStr.m_06 = 1;
    objStr.m_00 = &DAT_010c9368;
    objStr.m_08 = pOutText;
    objStr.m_0c = iTextLen;
    objStr.m_10 = 1;
    int need = objStr.m_08->m_iArrayLength + 1;
    ReserveChars(*GetSingleton()->m_10, pOutText, need);
    objStr.m_08->m_pData[objStr.m_08->m_iArrayLength] = 0;
    MiniStr ms;
    ms.FUN_00dc1680(&DAT_010d6ae8);
    FUN_00e0bd40(&objStr, &ms, 1, 0, &vecProcessed, &DAT_0126c830, &vec4);
    objStr.m_00 = &DAT_010c9368;
    if (objStr.m_10 == 0)
    {
        CharVec* pCharVec = objStr.m_08;
        if (pCharVec != 0)
        {
            Singleton* pSingleton7 = GetSingleton();
            Allocator* pAllocator7 = pSingleton7->m_10;
            int cap = pCharVec->m_iCapacity;
            pCharVec->m_iArrayLength = 0;
            if ((cap & 0x80000000u) == 0)
                pAllocator7->Free(pCharVec->m_pData, cap & 0x3fffffff);
            pCharVec->m_pData = 0;
            pCharVec->m_iCapacity = (int)0x80000000;
            Singleton* pSingleton7b = GetSingleton();
            pSingleton7b->m_10->a2(pCharVec, 12);
        }
    }
    objStr.m_00 = &DAT_0102e388;
    vecProcessed.FUN_00ddc870();
    {
        Singleton* pSingleton8 = GetSingleton();
        objRecords.ProcessArgument(pSingleton8->m_10);
    }
    objRecords.FUN_00a29680();
    if (iTotalRangeLen < 1)
    {
        Singleton* pSingleton9 = GetSingleton();
        Allocator* pAllocator9 = pSingleton9->m_10;
        int cap2 = vecEnds.m_iCapacity;
        vecEnds.m_iArrayLength = 0;
        if ((cap2 & (int)0x80000000) == 0)
            pAllocator9->Free(vecEnds.m_pData, (cap2 & 0x3fffffff) * 4);
        vecEnds.m_pData = 0;
        vecEnds.m_iCapacity = (int)0x80000000;
        Singleton* pSingleton10 = GetSingleton();
        Allocator* pAllocator10 = pSingleton10->m_10;
        int cap1 = vecStarts.m_iCapacity;
        vecStarts.m_iArrayLength = 0;
        if ((cap1 & (int)0x80000000) == 0)
            pAllocator10->Free(vecStarts.m_pData, (cap1 & 0x3fffffff) * 4);
        vecStarts.m_pData = 0;
        vecStarts.m_iCapacity = (int)0x80000000;
        {
            Singleton* pSingleton11 = GetSingleton();
            Allocator* pAllocator11 = pSingleton11->m_10;
            int cap4 = vec4.m_iCapacity;
            vec4.m_iArrayLength = 0;
            if ((cap4 & (int)0x80000000) == 0)
                pAllocator11->Free(vec4.m_pData, (cap4 & 0x3fffffff) * sizeof(Elem12));
        }
        return;
    }
    else
    {
        int numRanges = vecStarts.m_iArrayLength;
        int iDataLen = m_28;
        int iTextLen2 = m_30.m_iArrayLength;
        m_0c->FUN_00d60960(iTextLen2 + numRanges * 4 + iDataLen + iTotalRangeLen + 0xd);
        m_0c->FUN_00d605d0(10);
        m_0c->WriteInt(iDataLen);
        if (iDataLen > 0)
            m_0c->FUN_00d607b0(m_24, iDataLen);
        m_0c->WriteInt(iTextLen2);
        if (iTextLen2 > 0)
            m_0c->FUN_00d607b0((int)pOutText->m_pData, iTextLen2);
        m_0c->WriteInt(numRanges);
        for (int i = 0; i < numRanges; i++)
        {
            int diff = vecEnds.m_pData[i] - vecStarts.m_pData[i];
            m_0c->WriteInt(diff);
            if (diff > 0)
                m_0c->FUN_00d607b0(vecStarts.m_pData[i], diff);
        }
        Singleton* pSingleton9 = GetSingleton();
        Allocator* pAllocator9 = pSingleton9->m_10;
        int cap2 = vecEnds.m_iCapacity;
        vecEnds.m_iArrayLength = 0;
        if ((cap2 & (int)0x80000000) == 0)
            pAllocator9->Free(vecEnds.m_pData, (cap2 & 0x3fffffff) * 4);
        vecEnds.m_pData = 0;
        vecEnds.m_iCapacity = (int)0x80000000;
        Singleton* pSingleton10 = GetSingleton();
        Allocator* pAllocator10 = pSingleton10->m_10;
        int cap1 = vecStarts.m_iCapacity;
        vecStarts.m_iArrayLength = 0;
        if ((cap1 & (int)0x80000000) == 0)
            pAllocator10->Free(vecStarts.m_pData, (cap1 & 0x3fffffff) * 4);
        vecStarts.m_pData = 0;
        vecStarts.m_iCapacity = (int)0x80000000;
    }
    {
        Singleton* pSingleton11 = GetSingleton();
        Allocator* pAllocator11 = pSingleton11->m_10;
        int cap4 = vec4.m_iCapacity;
        vec4.m_iArrayLength = 0;
        if ((cap4 & (int)0x80000000) == 0)
            pAllocator11->Free(vec4.m_pData, (cap4 & 0x3fffffff) * sizeof(Elem12));
    }
    (void)aiUnused;
    (void)iTotalRangeLen;
    (void)vecProcessed;
}

// sub ecx,8; jmp FUN_00ddc840 == MSVC adjustor thunk for the secondary base's slot.
struct PrimaryBase
{
    virtual void FUN_00ddc830();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00ddc830();
};

struct AdjustDerived : PrimaryBase, SecondaryBase
{
    AdjustDerived();
// @fnv 0x00ddc830
    virtual void FUN_00ddc830();
};

AdjustDerived::AdjustDerived()
{}

namespace fnv_00ddc840 {
struct AudioAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void Free(void* apMemory, unsigned int auiSize);
};

struct AudioHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    AudioAllocator* m_pAllocator;
};

AudioHolder* __cdecl FUN_00c85750();

struct FUN_00ddc840
{
    unsigned short m_u04;
    unsigned short m_u06;
    FUN_00ddc840();
    virtual ~FUN_00ddc840();
    static void operator delete(void* apMemory)
    {
        AudioHolder* pHolder = FUN_00c85750();
        unsigned int uiSize = ((FUN_00ddc840*)apMemory)->m_u04;
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        pAllocator->Free(apMemory, uiSize);
    }
};

// Initialises m_u04 and m_u06 to zero.
// @fnv 0x00ddc840
FUN_00ddc840::FUN_00ddc840()
{
    m_u04 = 0;
    m_u06 = 0;
}
}  // namespace fnv_00ddc840

struct Sbf00_Sub
{
    void* unk00;
    int unk04;
    int unk08;
    int unk0c;
    void InitHeading();
};
struct Sbf00_Ctx
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    Sbf00_Sub m_kSub;
    float m_f24;
    float m_f28;
    int unk2c;
    int unk30;
    int unk34;
    void FUN_00cc06f0(ArrayMember* apArr, int a2);
    void FUN_00cc0780();
};
struct Sbf00_Name
{
    int unk00;
    int unk04;
    void FUN_00dc1680(void* apStr);
};
struct Sbf00_Arr24
{
    void* m_pData;
    int m_iArrayLength;
    unsigned int m_uCapacity;
    void Free()
    {
        AudioHolder* pHolder = FUN_00c85750();
        AudioAllocator* pAllocator = pHolder->m_pAllocator;
        unsigned int uCapacity = m_uCapacity;
        m_iArrayLength = 0;
        if ((uCapacity & 0x80000000) == 0)
            pAllocator->FreeArray(m_pData, (uCapacity & 0x3fffffff) * 24);
    }
};
struct Sbf00_B2
{
    void* m_pVtbl;
    unsigned char m_bFlag;
};
struct Sbf00_Alloc
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void* AllocArray(int* apBytes);
    virtual void FreeArray(void* apMemory, unsigned int auiCapacity);
};
extern int DAT_010d1508;
extern int DAT_010d7e48;
extern int DAT_010d7e28;
extern int DAT_0126c860;
extern double DAT_01017b70;
unsigned __int64 __cdecl FUN_00d60580();
void __cdecl FUN_00e0bd40(Sbf00_Ctx* a1, Sbf00_Name* a2, int a3, int a4, Sbf00_Sub* a5, void* a6, Sbf00_Arr24* a7);
struct SbfRef
{
    void* m_pVtbl;
    unsigned short unk04;
    unsigned short m_uRefCount;
    SbfRef() : m_uRefCount(1)
    {}
};
struct SbfProc
{
    void* m_pVtbl;
    unsigned char m_bFlag;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    SbfProc() : m_pVtbl(&DAT_010d1508), m_bFlag(1)
    {}
};
struct SbfBases : SbfRef, SbfProc
{
    SbfBases()
    {
        SbfRef::m_pVtbl = &DAT_010d7e48;
        SbfProc::m_pVtbl = &DAT_010d7e28;
    }
};
struct SbfPtrs
{
    void** m_ppData;
    int m_iArrayLength;
    unsigned m_uCapacity;
    SbfPtrs() : m_ppData(0), m_iArrayLength(0), m_uCapacity(0x80000000)
    {}
};
struct SbfBytes
{
    void* m_pData;
    int m_iArrayLength;
    unsigned m_uCapacity;
    SbfBytes() : m_pData(0), m_iArrayLength(0), m_uCapacity(0x80000000)
    {}
};
struct FUN_00ddbf00 : SbfBases
{
    SbfPtrs m_kFirst;
    SbfBytes m_kSecond;
    SbfBytes m_kThird;
    FUN_00ddbf00(PtrArrayMember* pSource);
};
// Copies pointer elements from pSource into m_kFirst, growing its backing array when the source count exceeds capacity.
// @fnv 0x00ddbf00
FUN_00ddbf00::FUN_00ddbf00(PtrArrayMember* pSource)
{
    FUN_00ddbf00* pThis = this;
    ArrayMember* pSecond = (ArrayMember*)&m_kSecond;
    Sbf00_Ctx kCtx;
    kCtx.m_kSub.InitHeading();
    kCtx.m_kSub.unk00 = 0;
    kCtx.m_kSub.unk0c = 0;
    kCtx.m_kSub.unk04 = 0;
    kCtx.m_kSub.unk08 = 1;
    {
        kCtx.m_f24 = (float)(DAT_01017b70 / (double)FUN_00d60580());
    }
    kCtx.m_f28 = 1.0f;
    Sbf00_Arr24 kArr;
    kArr.m_pData = 0;
    kArr.m_iArrayLength = 0;
    kArr.m_uCapacity = 0x80000000;
    kCtx.FUN_00cc06f0(pSecond, 1);
    {
        Sbf00_Name kName;
        kName.FUN_00dc1680(&DAT_010d6ae8);
        FUN_00e0bd40(&kCtx, &kName, 1, 0, &kCtx.m_kSub, &DAT_0126c860, &kArr);
    }
    kCtx.FUN_00cc0780();
    kArr.Free();
    Sbf00_Alloc* pAlloc = (Sbf00_Alloc*)FUN_00c85750()->m_pAllocator;
    unsigned int uCap = pThis->m_kFirst.m_uCapacity;
    int iCap = uCap & 0x3fffffff;
    if (iCap < pSource->m_iArrayLength)
    {
        if ((uCap & 0x80000000) == 0)
            pAlloc->FreeArray(pThis->m_kFirst.m_ppData, iCap * 4);
        int iBytes = pSource->m_iArrayLength * 4;
        pThis->m_kFirst.m_ppData = (void**)pAlloc->AllocArray(&iBytes);
        pThis->m_kFirst.m_uCapacity = iBytes / 4;
    }
    int n = pSource->m_iArrayLength;
    void** pDst = pThis->m_kFirst.m_ppData;
    pThis->m_kFirst.m_iArrayLength = n;
    void** pSrc = pSource->m_ppData;
    for (int i = 0; i < n; i++)
        pDst[i] = pSrc[i];
}

namespace fnv_00ddc870 {
struct FixedAllocator
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void FreeArray(void* p, unsigned int size);
};

struct AllocHolder
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    FixedAllocator* m_pAllocator;
};

AllocHolder* FUN_00c85750();

struct ElemSub
{
    int unk00;
    int unk04;
    void Release();
};

struct Elem
{
    int unk00;
    int unk04;
    ElemSub m_08;
};

struct FUN_00ddc870_cls
{
    Elem* m_pItems;
    int m_iArrayLength;
    unsigned int m_uCapBits;

    void FUN_00ddc870();
};

// @fnv 0x00ddc870
void FUN_00ddc870_cls::FUN_00ddc870()
{
    AllocHolder* holder = FUN_00c85750();
    FixedAllocator* alloc = holder->m_pAllocator;
    int iCount = m_iArrayLength;
    Elem* pItems = *(Elem* volatile*)&m_pItems;
    if (iCount > 0)
    {
        ElemSub* s = &pItems->m_08;
        int n = iCount;
        do
        {
            s->Release();
            s = (ElemSub*)((char*)s + 16);
        } while (--n != 0);
    }

    m_iArrayLength = 0;
    unsigned int cap = m_uCapBits;
    if ((cap & 0x80000000u) == 0)
    {
        alloc->FreeArray(m_pItems, (cap & 0x3fffffffu) * 16);
    }
    m_uCapBits = 0x80000000u;
    m_pItems = 0;
}
}  // namespace fnv_00ddc870
