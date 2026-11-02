// src/havok/animation/animation/animation/util/hkatrackanalysis_gs_ehsc_nogs_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHs-c- /Gy (unit src/havok/animation/animation/animation/util/hkatrackanalysis.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/animation/animation/animation/util/hkatrackanalysis.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/animation/animation/animation/util/hkatrackanalysis.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct TrackAnalysis
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    int count;
    int sum;
    int max;
};
void AnalyzeTrackBits(const unsigned short* values, unsigned int count, TrackAnalysis* result);
void AnalyzeTrackBits(const unsigned short* values, unsigned int count, TrackAnalysis* result);
void AnalyzeTrackWithZeroCount(const unsigned short* aFirstValues, const unsigned short* values,
                               unsigned int firstCount, unsigned int count, TrackAnalysis* result);
struct TraceSink
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void unused2();
    virtual void write(int, int, const char*, const char*, int);
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void begin(unsigned int, const char*);
    virtual void end();
};
extern TraceSink* DAT_01268360;
extern const char str_010ec758[];
extern const char str_010ec724[];
extern const char str_010ec74c[];
extern const char str_010ec70c[];
extern const char str_010ec6f4[];
extern const char str_010ec6e0[];
extern const char str_010ec6cc[];
extern const char str_010ec6b4[];
extern const char str_010ec69c[];
extern const char str_010ec688[];
extern const char str_010ec670[];
extern const char str_010ec658[];
extern const char str_010ec644[];
extern const char str_010ec6f40[];
extern const char str_010ec624[];
struct TextBuilder
{
    int state;
    int length;
    int bufferCapacity;
    void FUN_00cb1600(char*, unsigned int);
    TextBuilder* FUN_00cc01c0(const char*, int);
    TextBuilder* FUN_00cc01c0(const char*, float);
    void FUN_00cc02d0();
    void WriteFloat();
    void FUN_00cc00e0();
};
struct TrackStatistics
{
    int field0;
    int field1;
    int field2;
    int field3;
    int field4;
    int field5;
    int field6;
    int field7;
    int field8;
    int field9;
    int field10;
    int total0;
    int total1;
    float rate;
    void LogStatistics();
};
void* FUN_00c85750();
struct hkMemoryAllocator_e50650;
void FUN_00c908c0(hkMemoryAllocator_e50650& kAllocator, void* pkArray, int iNewCapacity, int iElementSize);
struct hkMemoryRouter_e50650
{
    char m_acPad00[0x10];
    hkMemoryAllocator_e50650* m_pkHeap;
    hkMemoryAllocator_e50650& heap()
    {
        return *m_pkHeap;
    }
};
struct hkContainerHeapAllocator_e50650
{
    hkMemoryAllocator_e50650& get(const void*)
    {
        return ((hkMemoryRouter_e50650*)FUN_00c85750())->heap();
    }
};
template <class T> struct hkArray_e50650
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArray_e50650() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    void reserve(hkMemoryAllocator_e50650& kAllocator, int n)
    {
        const int iCapacity = getCapacity();
        if (iCapacity < n)
        {
            int iCap = 2 * iCapacity;
            int iNewSize = (n < iCap) ? iCap : n;
            FUN_00c908c0(kAllocator, this, iNewSize, sizeof(T));
        }
    }
    void _setSize(hkMemoryAllocator_e50650& kAllocator, int n)
    {
        reserve(kAllocator, n);
        m_iElementCount = n;
    }
    void SetSizeAndGrow(int n)
    {
        _setSize(hkContainerHeapAllocator_e50650().get(this), n);
    }
};
struct TrackHeader_e50650
{
    int m_iUnk00;
    int m_iArrayLength;
    int m_iUnk08;
};
struct TrackSource_e50650
{
    TrackHeader_e50650 m_kHeader;
    float m_fCoefficientA;
    float m_fB;
    float m_fC;
    float m_fD;
    unsigned char m_ucE;
};
struct TrackBuffers_e50650
{
    TrackHeader_e50650 m_kHeader;
    hkArray_e50650<float> m_kA;
    hkArray_e50650<float> m_kB;
    hkArray_e50650<float> m_kC;
    hkArray_e50650<float> m_kCubicCoefficient;
    hkArray_e50650<unsigned char> m_kE;

    void FUN_00e50ca0();
};
struct hkBool_e50650
{
    char m_cBooleanValue;
    hkBool_e50650(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};
void FUN_00e4f910(TrackBuffers_e50650* pkBuffers, void* pkArg, void* pkArgCur, hkBool_e50650 bFlag);
void ExpandTrackSource(const TrackSource_e50650* pkSource, void* pkArg, void* pkArgCur);
struct StatsB0
{
    unsigned int m_iWordAt00, m_iWordAt04, m_8, m_iThirdValue, m_10, m_14, m_18, m_1c, m_20, m_24, m_28, m_2c, m_30;
    float m_34;
};
__declspec(noinline) void __cdecl Analyze(const unsigned short* p, unsigned int count, StatsB0* s)
{
    for (unsigned int i = 0; i < count; i++)
        s->m_1c += p[i] & 3;
}
__declspec(noinline) void __cdecl CountTail(const unsigned short* p, void* a1, unsigned int count, unsigned int a3,
                                            StatsB0* s)
{
    Analyze(p, count, s);
    Analyze((const unsigned short*)a1, a3, s);
}
void __cdecl FUN_00e4ebb0(const unsigned short* p, void* a1, unsigned int count, unsigned int a3, StatsB0* s);
#include <xmmintrin.h>
#include <math.h>
struct PerTransformIn
{
    const void* boneData;
    unsigned int numberOfTransformTracks;
    unsigned int numberOfPoses;
};
struct PerFloatIn
{
    const float* floatData;
    unsigned int numberOfFloatTracks;
    unsigned int numberOfPoses;
    hkArray_e50650<float> absoluteTolerance;
};
struct hkMemoryAllocator_e50650
{
    virtual void AllocateMemoryBlock(int);
    virtual void ReleaseBlock(void*, int);
    virtual void* AllocateBufferWithSize(int&);
    virtual void* BufRealloc(void*, int, int&);
    virtual void ReturnMemory(void*, int);
};
struct E50920Router
{
    char* stackTop;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator_e50650* heap;
};
static __forceinline void ClearStatistics(TrackStatistics& s)
{
    s.field0 = 0;
    s.field1 = 0;
    s.field2 = 0;
    s.field3 = 0;
    s.field4 = 0;
    s.field5 = 0;
    s.field6 = 0;
    s.field7 = 0;
    s.field8 = 0;
    s.field9 = 0;
    s.field10 = 0;
    s.total0 = 0;
    s.total1 = 0;
    s.rate = 0.0f;
}
struct PassBool
{
    unsigned char value;
    PassBool(bool b) : value(b)
    {}
    PassBool(const PassBool& other) : value(other.value)
    {}
};
typedef void(__cdecl* QsAnalyzeFn)(TrackBuffers_e50650*, void*, void*, PassBool);
void __cdecl FUN_00e4ead0(const unsigned short* mask, unsigned int count, TrackStatistics* result);
void __cdecl FUN_00e4ebb0(const unsigned short* maskT, const unsigned short* maskF, unsigned int numT,
                          unsigned int numF, TrackStatistics* result);
struct FloatLocalArray
{
    hkArray_e50650<float> values;
    float* localMemory;

    __forceinline void allocate(int n)
    {
        E50920Router* router = (E50920Router*)FUN_00c85750();
        char* block = router->stackTop;
        router->stackTop = block + ((n * 4 + 127) & ~127);
        values.m_iCapacityState = n | 0x80000000;
        values.m_data = (float*)block;
        localMemory = (float*)block;
    }

    __forceinline void freeStorage(hkMemoryAllocator_e50650& alloc)
    {
        int cap = values.m_iCapacityState;
        values.m_iElementCount = 0;
        if ((cap & 0x80000000) == 0)
        {
            alloc.ReturnMemory(values.m_data, (cap & 0x3fffffff) * 4);
        }
        values.m_data = 0;
        values.m_iCapacityState = 0x80000000;
    }

    __forceinline void release()
    {
        float* saved = localMemory;
        if (saved == values.m_data)
        {
            values.m_iElementCount = 0;
        }
        ((E50920Router*)FUN_00c85750())->stackTop = (char*)saved;
        freeStorage(hkContainerHeapAllocator_e50650().get(&values));
    }
};
void __cdecl FUN_00e50920(const PerTransformIn& input, const PerFloatIn& finput, unsigned short* staticMask,
                          float* staticDOFs, hkBool_e50650 displayStatsReport);
