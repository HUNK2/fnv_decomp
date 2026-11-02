
// src/havok/common/visualize/process/hkinspectprocess_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/havok/common/visualize/process/hkinspectprocess.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

void __stdcall GetPunctuationChars(char** pOut, int* pLen);
struct hkInspectProcess;
struct hkProcess;
extern hkProcess* DAT_01269cd0;
extern hkInspectProcess* DAT_01269cd4;
void __cdecl FUN_00ddb710(hkProcess*);
struct hkProcessFactory
{
    hkInspectProcess* __thiscall RegisterProcess(const char*, void(__cdecl*)(hkProcess*));
};
extern hkProcessFactory* FUN_00dd9380;
void __cdecl RegisterObjectInspectionProcess();
struct hkInspectProcessStandIn
{
    void __thiscall WriteObjectHeader(void* object, int type, int flags);
    void __thiscall RemovePair(void* object);
};
void __cdecl FUN_00ddb5d0(void* object, int type, char addObject, int flags, hkInspectProcess* inspectProcess);
void __cdecl CreateImpl(hkProcess*);
struct hkInspectProcess;
extern hkInspectProcess* DAT_01269cd8;
hkInspectProcess* __cdecl CreateStatisticsProcess();
struct hkInspectProcess;
extern hkInspectProcess* DAT_01269cd4;
hkInspectProcess* FUN_00ddbeb0();
class hkRefObjDDB6
{
  public:
    virtual ~hkRefObjDDB6() throw();
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    hkRefObjDDB6() throw()
    {
        m_sReferenceCount = 1;
    }
};
class hkListenerDDB6
{
  public:
    virtual void onEvent() = 0;
    bool m_enabled;
    hkListenerDDB6() throw() : m_enabled(true)
    {}
};
class hkSourceDDB6
{
  public:
    int unk00;
    void* m_target;

    void FUN_00c90510() throw();
    void FUN_00cd13c0(void(__cdecl* callback)(void*), void* userData) throw();
};
struct hkSourceListDDB6
{
    hkSourceDDB6** m_data;
    int m_iElementCount;
};
template <typename T> struct hkArrayDDB6
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArrayDDB6() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
};
void __cdecl FUN_00ddb5d0(void* userData);
class FUN_00ddb600 : public hkRefObjDDB6, public hkListenerDDB6
{
  public:
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkArrayDDB6<void*> m_items;
    hkSourceDDB6* m_pObservedSource;

    FUN_00ddb600(const hkSourceListDDB6& sources) throw();
    virtual ~FUN_00ddb600() throw();
    virtual void onEvent();
};
struct FnvCpu_FUN_00ddb710_CpuBlock;
struct FnvCpu_FUN_00ddb710_CpuAllocator
{
    virtual void slot00();
    virtual void* Invoke(unsigned int size);
};
struct FnvCpu_FUN_00ddb710_CpuHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    FnvCpu_FUN_00ddb710_CpuAllocator* allocator;
};
void* __cdecl FUN_00c85750();
struct FnvCpu_FUN_00ddb710_CpuBlock
{
    unsigned int unk00;
    unsigned short size;
    FnvCpu_FUN_00ddb710_CpuBlock* FUN_00ddb600(unsigned int value);
};
void* __cdecl FUN_00ddb710(unsigned int value);
struct MemoryManager
{
    virtual void unk0();
    virtual void unk4();
    virtual void deallocate(void* p, unsigned int size);
};
struct ThreadMemory
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    MemoryManager* memoryManager;
};
void* __cdecl FUN_00c85750();
struct TestClass
{
    void* vtable;
    unsigned short m_usAllocationSize;
    unsigned short m_iObjectReferenceCount;

    void FUN_00ddb670();
    void* FUN_00ddbed0(char flags);
};
class hkClass;
class hkStatisticsCollector;
class hkBool
{
    char value;

  public:
    operator bool() const
    {
        return value != 0;
    }
};
class hkClass
{
  public:
    hkBool GetLastNodeFlag() const;
};
class hkReferencedObject
{
  public:
    virtual ~hkReferencedObject();
    virtual const hkClass* GetClassType() const;
    virtual void CalcContentStatistics(hkStatisticsCollector*, const hkClass*) const;
    unsigned short memSizeAndFlags;
    short referenceCount;
};
class hkVtableClassRegistry : public hkReferencedObject
{
  public:
    virtual void RegisterVtable(const void*, const hkClass*);
    virtual const hkClass* GetClassFromVirtualInstance(const void*) const;
};
class ProcessContext
{
  public:
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    int unk40, unk44, unk48;
    hkVtableClassRegistry* registry;
};
class hkOArchive
{
  public:
    void FUN_00d60960(unsigned int);
    void FUN_00d605d0(unsigned char);
    void FUN_00d609a0(unsigned __int64);
};
struct hkInspectProcess
{
    int unk00, unk04, unk08, unk0c, unk10;
    hkOArchive* archive;
    int unk18, unk1c, unk20, unk24, unk28;
    ProcessContext* context;
    int WriteObjectHeader(void*, const hkClass*, unsigned int);
};
struct LayoutRulesDDB3
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};
extern const LayoutRulesDDB3 DAT_011b7b88;
class GlobalObjectO2_00d472a0;
extern GlobalObjectO2_00d472a0 g_0126cae8;
class FUN_00d605d0_Class
{
  public:
    void FUN_00d60960(int iCommand);
    void FUN_00d605d0(unsigned int uiValue);
    void FUN_00d609a0(const GlobalObjectO2_00d472a0* pkClass, int iFlags);
};
struct TrackedObjectDDB3
{
    void* m_pvObject;
    int m_iType;
    int m_iFlags;
};
template <class T> struct hkArrayDDB3
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
};
struct TrackedListDDB3
{
    int unk00[10];
    hkArrayDDB3<TrackedObjectDDB3> m_kTrackedObjects;
};
class ProcessBaseDDB3
{
  public:
    virtual void vfn_00();
    int unk04;
};
class ListenerDDB3
{
  public:
    virtual void WriteTrackedObjects();
};
class InspectProcessDDB3 : public ProcessBaseDDB3, public ListenerDDB3
{
  public:
    int unk0C;
    int unk10;
    FUN_00d605d0_Class* m_pDataStream;
    int unk18, unk1C, unk20, unk24, unk28;
    TrackedListDDB3* m_pkTracked;

    void WriteObjectHeader(void* pvObject, int iType, int iFlags);
    virtual void WriteTrackedObjects();
};

struct Heap_ddba
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void ReturnMemory(void* p, int nbytes) throw();
};
struct Router_ddba
{
    int unk00, unk04, unk08, unk0C;
    Heap_ddba* m_pStreamAllocator;
    Heap_ddba& heap()
    {
        return *m_pStreamAllocator;
    }
    static Router_ddba& __cdecl FUN_00c85750() throw();
};
void __cdecl FUN_00c908c0(Heap_ddba* heap, void* array, int numElements, int sizeOfElement) throw();

struct hkBool_ddba
{
    char m_cBooleanValue;
    hkBool_ddba(bool b) throw() : m_cBooleanValue(b)
    {}
};

template <class T> struct hkArray_ddba
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    hkArray_ddba() throw() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArray_ddba() throw()
    {
        Heap_ddba& heap = Router_ddba::FUN_00c85750().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            heap.ReturnMemory(m_data, (m_iCapacityState & 0x3fffffff) * sizeof(T));
    }
    __forceinline void SetSizeAndGrow(int n) throw()
    {
        Heap_ddba& heap = Router_ddba::FUN_00c85750().heap();
        int cap = m_iCapacityState & 0x3fffffff;
        if (cap < n)
        {
            int cap2 = 2 * cap;
            FUN_00c908c0(&heap, this, n < cap2 ? cap2 : n, sizeof(T));
        }
        m_iElementCount = n;
    }
};

struct Pair_ddba
{
    void* m_kPointA;
    void* m_kPointB;
};

struct Hit_ddba
{
    int a, b;
};

struct Query_ddba
{
    void FUN_00ddb770(void* a, void* b, hkBool_ddba flag, hkArray_ddba<Hit_ddba>& hits) throw();
};

struct Shape_ddba
{
    int unk00, unk04, unk08, unk0C, unk10, unk14;
    Pair_ddba* m_pairs;
    int m_numPairs;
    int getNumPairs() const
    {
        return m_numPairs;
    }
    void FUN_00ddba20(int unused);
};

// @fnv 0x00ddba20
void Shape_ddba::FUN_00ddba20(int unused)
{
    hkArray_ddba<Hit_ddba> hits;
    for (int i = 0; i < getNumPairs(); i++)
    {
        hits.SetSizeAndGrow(0);
        ((Query_ddba*)((char*)this - 8))->FUN_00ddb770(m_pairs[i].m_kPointA, m_pairs[i].m_kPointB, false, hits);
    }
}
