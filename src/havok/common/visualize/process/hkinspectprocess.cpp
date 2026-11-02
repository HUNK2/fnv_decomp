
// src/havok/common/visualize/process/hkinspectprocess.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/process/hkinspectprocess.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00ddb2f0
void __stdcall GetPunctuationChars(char** apOutString, int* apiLength)
{
    *apOutString = "!\"#$%";
    *apiLength = 5;
}

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
// @fnv 0x00ddb750
void __cdecl RegisterObjectInspectionProcess()
{
    DAT_01269cd4 = FUN_00dd9380->RegisterProcess("ObjectInspection", FUN_00ddb710);
}

struct hkInspectProcessStandIn
{
    void __thiscall WriteObjectHeader(void* object, int type, int flags);
    void __thiscall RemovePair(void* object);
};

// If addObject is set, calls WriteObjectHeader with object, type and flags; otherwise calls RemovePair with object.
// @fnv 0x00ddb5d0
void __cdecl FUN_00ddb5d0(void* object, int type, char addObject, int flags, hkInspectProcess* inspectProcess)
{
    if (addObject)
    {
        reinterpret_cast<hkInspectProcessStandIn*>(inspectProcess)->WriteObjectHeader(object, type, flags);
    }
    else
    {
        reinterpret_cast<hkInspectProcessStandIn*>(inspectProcess)->RemovePair(object);
    }
}

void __cdecl CreateImpl(hkProcess*);
struct hkInspectProcess;
extern hkInspectProcess* DAT_01269cd8;

// @fnv 0x00ddc1a0
hkInspectProcess* __cdecl CreateStatisticsProcess()
{
    return DAT_01269cd8 = ((hkProcessFactory*)DAT_01269cd0)->RegisterProcess("Statistics", CreateImpl);
}

struct hkInspectProcess;
extern hkInspectProcess* DAT_01269cd4;

// @fnv 0x00ddbeb0
hkInspectProcess* FUN_00ddbeb0()
{
    return DAT_01269cd4;
}

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

// @fnv 0x00ddb600
FUN_00ddb600::FUN_00ddb600(const hkSourceListDDB6& sources) throw()
{
    m_pObservedSource = sources.m_iElementCount > 0 ? (hkSourceDDB6*)sources.m_data[0]->m_target : 0;
    if (m_pObservedSource)
    {
        m_pObservedSource->FUN_00c90510();
        m_pObservedSource->FUN_00cd13c0(FUN_00ddb5d0, this);
    }
}

namespace fnv_00ddb670 {
class hkMemoryAllocatorDDB6
{
  public:
    virtual ~hkMemoryAllocatorDDB6() throw();
    virtual void* AllocateMemoryBlock(int iNumBytes) throw();
    virtual void ReleaseBlock(void* p, int iNumBytes) throw();
    virtual void* AllocateBufferWithSize(int& iReqNumBytesInOut) throw();
    virtual void ReturnMemory(void* p, int iNumBytes) throw();

    template <typename T> void _bufFree(void* p, int aiNumElements)
    {
        ReturnMemory(p, aiNumElements * sizeof(T));
    }
};

struct hkMemoryRouterDDB6
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
    hkMemoryAllocatorDDB6* m_pStreamAllocator;
    hkMemoryAllocatorDDB6& heap()
    {
        return *m_pStreamAllocator;
    }
};
extern "C" hkMemoryRouterDDB6& __cdecl FUN_00c85750();

template <class T> __forceinline void destructDDB6(T* t, int n)
{
    for (int i = 0; i < n; i++)
        t[i].~T();
}

template <class T> class hkArrayDDB6
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }

    ~hkArrayDDB6() throw()
    {
        ClearAndRelease(FUN_00c85750().heap());
    }
    __forceinline void clear()
    {
        destructDDB6(m_data, m_iElementCount);
        m_iElementCount = 0;
    }
    __forceinline void ClearAndRelease(hkMemoryAllocatorDDB6& kAlloc)
    {
        clear();
        if ((m_iCapacityState & 0x80000000) == 0)
            kAlloc._bufFree<T>(m_data, getCapacity());
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

class hkReferencedObject
{
  public:
    virtual ~hkReferencedObject() throw()
    {}
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;

    void removeReference() throw();
};

class hkProcessDDB6
{
  public:
    virtual ~hkProcessDDB6() throw()
    {}
};

struct hkProcessObjectDDB6
{
    void* m_object;
    int unk04;
    int unk08;
};

class hkProcessContextDDB6 : public hkReferencedObject
{
  public:
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    hkProcessObjectDDB6* m_kTrackedObjects;
    int m_numObjects;

    void FUN_00cd1140(void(__cdecl* pfnCallback)(void*, int, char, int, hkInspectProcess*)) throw();
};

struct hkInspectEntryDDB6
{
    int unk00;
    int unk04;
};

class FUN_00ddb670 : public hkReferencedObject, public hkProcessDDB6
{
  public:
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    hkArrayDDB6<hkInspectEntryDDB6> m_entries;
    hkProcessContextDDB6* m_iValueAtOffset0C;

    void RemovePair(void* pvObject) throw();
    virtual ~FUN_00ddb670() throw();
};

// @fnv 0x00ddb670
FUN_00ddb670::~FUN_00ddb670() throw()
{
    hkProcessContextDDB6* pkContext = m_iValueAtOffset0C;
    if (pkContext)
    {
        for (int i = 0; i < pkContext->m_numObjects; i++)
            RemovePair(pkContext->m_kTrackedObjects[i].m_object);
        m_iValueAtOffset0C->FUN_00cd1140(FUN_00ddb5d0);
        m_iValueAtOffset0C->removeReference();
    }
}
}  // namespace fnv_00ddb670

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
// @fnv 0x00ddb710
void* __cdecl FUN_00ddb710(unsigned int value)
{
    FnvCpu_FUN_00ddb710_CpuHolder* pCpuHolder = static_cast<FnvCpu_FUN_00ddb710_CpuHolder*>(FUN_00c85750());
    FnvCpu_FUN_00ddb710_CpuBlock* pCpuBlock =
        static_cast<FnvCpu_FUN_00ddb710_CpuBlock*>(pCpuHolder->allocator->Invoke(48));
    pCpuBlock->size = 48;
    pCpuBlock = pCpuBlock->FUN_00ddb600(value);
    if (pCpuBlock)
        return reinterpret_cast<char*>(pCpuBlock) + 8;
    return 0;
}

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

// @fnv 0x00ddbed0
void* TestClass::FUN_00ddbed0(char flags)
{
    FUN_00ddb670();
    if (flags & 1)
    {
        ThreadMemory* mem = (ThreadMemory*)FUN_00c85750();
        mem->memoryManager->deallocate(this, m_usAllocationSize);
    }
    return this;
}

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
// Writes a 25-byte object header to the archive, resolving the actual class via the vtable registry when available.
// @fnv 0x00ddb310
int hkInspectProcess::WriteObjectHeader(void* object, const hkClass* pClassInfo, unsigned int flags)
{
    archive->FUN_00d60960(25);
    const hkClass* pActualClass = pClassInfo;
    if (context->registry && pClassInfo->GetLastNodeFlag())
    {
        pActualClass = context->registry->GetClassFromVirtualInstance(object);
        if (!pActualClass)
            pActualClass = pClassInfo;
    }
    archive->FUN_00d605d0(33);
    archive->FUN_00d609a0(reinterpret_cast<unsigned int>(object));
    archive->FUN_00d609a0(reinterpret_cast<unsigned int>(pActualClass));
    archive->FUN_00d609a0(flags);
    return 25;
}

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

// Writes layout rules and each tracked object entry to m_pDataStream via FUN_00d60960, FUN_00d605d0, FUN_00d609a0, and WriteObjectHeader.
// @fnv 0x00ddb3a0
void InspectProcessDDB3::WriteTrackedObjects()
{
    if (!m_pkTracked)
        return;
    m_pDataStream->FUN_00d60960(0xd);
    m_pDataStream->FUN_00d605d0(0x20);
    m_pDataStream->FUN_00d609a0(&g_0126cae8, 0);
    m_pDataStream->FUN_00d605d0(DAT_011b7b88.m_ucBytesInPointer);
    m_pDataStream->FUN_00d605d0(DAT_011b7b88.m_bLittleEndian);
    m_pDataStream->FUN_00d605d0(DAT_011b7b88.m_bReusePaddingOptimization);
    m_pDataStream->FUN_00d605d0(DAT_011b7b88.m_bEmptyBaseClassOptimization);
    hkArrayDDB3<TrackedObjectDDB3>& kObjects = m_pkTracked->m_kTrackedObjects;
    for (int i = 0; i < kObjects.GetLogicalSize(); i++)
    {
        TrackedObjectDDB3& kEntry = kObjects[i];
        WriteObjectHeader(kEntry.m_pvObject, kEntry.m_iType, kEntry.m_iFlags);
    }
}

namespace fnv_00ddb550 {
class FUN_00d605d0_Class
{
  public:
    void FUN_00d60960(int iFlags);
    void FUN_00d605d0(unsigned int uiFlags);
    void FUN_00d609a0(int iKey, int iValue);
};

struct hkPairDDB5
{
    int m_key;
    int m_uiFilterValue;
};

template <typename T> struct hkArrayDDB5
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    void removeAt(int index)
    {
        m_iElementCount--;
        if (m_iElementCount != index)
        {
            unsigned int* src = reinterpret_cast<unsigned int*>(m_data + m_iElementCount);
            unsigned int* dst = reinterpret_cast<unsigned int*>(m_data + index);
            int k = 0;
            do
            {
                dst[k] = src[k];
            } while (++k < (int)(sizeof(T) / 4));
        }
    }
};

class FUN_00ddb550_cls
{
  public:
    int unk00, unk04, unk08, unk0C, unk10;
    FUN_00d605d0_Class* m_pStreamWriter;
    int unk18, unk1C;
    hkArrayDDB5<hkPairDDB5> m_pairs;

    int RemovePair(int iKey);
};

// Writes a header and key to m_pStreamWriter, removes the matching entry from m_pairs, and returns 9.
// @fnv 0x00ddb550
int FUN_00ddb550_cls::RemovePair(int iKey)
{
    m_pStreamWriter->FUN_00d60960(9);
    m_pStreamWriter->FUN_00d605d0(0x22);
    m_pStreamWriter->FUN_00d609a0(iKey, 0);
    for (int i = 0; i < m_pairs.m_iElementCount; i++)
    {
        if (m_pairs.m_data[i].m_key == iKey)
        {
            m_pairs.removeAt(i);
            break;
        }
    }
    return 9;
}
}  // namespace fnv_00ddb550

struct hkMemoryAllocatorQ
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void ReturnMemory(void* p, int numBytes) throw();
};

struct hkMemoryRouterQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkMemoryAllocatorQ* m_pStreamAllocator;
    hkMemoryAllocatorQ& heap()
    {
        return *m_pStreamAllocator;
    }
};

void __cdecl ResizeAudioStream(hkMemoryAllocatorQ* alloc, void* array, int sizeElem) throw();

template <typename T> struct hkArrQ
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArrQ() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArrQ()
    {
        ClearAndRelease();
    }

    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }

    void _clearAndDeallocate(hkMemoryAllocatorQ& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    void ClearAndRelease()
    {
        _clearAndDeallocate(static_cast<hkMemoryRouterQ*>(FUN_00c85750())->heap());
    }

    void _pushBack(hkMemoryAllocatorQ& alloc, const T& t)
    {
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(&alloc, this, sizeof(T));
        }
        T* p = m_data + m_iElementCount;
        m_iElementCount++;
        *p = t;
    }
    void AddBack(const T& t)
    {
        _pushBack(static_cast<hkMemoryRouterQ*>(FUN_00c85750())->heap(), t);
    }
};

class hkBoolQ
{
  public:
    char m_cBooleanValue;
    hkBoolQ(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct hkClassQ
{
    hkBoolQ hasVtable() const throw();
};

struct hkVtableClassRegistryQ
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual const hkClassQ* GetClassFromVirtualInstance(const void* obj) const throw();
};

struct hkInspectContextQ
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
    hkVtableClassRegistryQ* m_vtableRegistry;
};

struct hkLayoutRulesQ
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};

extern hkLayoutRulesQ DAT_010d6ae8;

struct hkStructureLayoutQ
{
    hkLayoutRulesQ m_kLayoutRules;
    hkStructureLayoutQ(const hkLayoutRulesQ& rules) throw();
};

struct hkArrayStreamWriterQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkArrayStreamWriterQ(hkArrQ<char>* arr, int ownerShip) throw();
    ~hkArrayStreamWriterQ() throw();
};

struct hkObjectPatchQ
{
    int unk00;
    int unk04;
    const void* m_object;
    int unk0C;
    const hkClassQ* m_class;
    int unk14;
};

struct hkWrittenObjectQ
{
    const void* m_object;
    const hkClassQ* m_class;
};

struct hkDisplayOStreamQ
{
    void FUN_00d60960(int size) throw();
    void FUN_00d605d0(unsigned int cmd) throw();
    void FUN_00d607b0(const char* data, int size) throw();
};

int __cdecl FUN_00e0bd40(hkArrayStreamWriterQ* writer, hkStructureLayoutQ* layout, const void* object, int flags,
                         const void* original, const hkClassQ* pClassInfo, hkArrQ<hkObjectPatchQ>* patches) throw();

struct hkInspectProcessQ
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    hkDisplayOStreamQ* m_pDisplayStream;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    hkInspectContextQ* m_iValueAtOffset0C;

    // Calls FUN_00ddb770 with the given object, class, true, and written array.
// @fnv 0x00ddb770
    __forceinline int sendRecursiveQ(const void* apObject, const hkClassQ* apClass,
                                     hkArrQ<hkWrittenObjectQ>* apWrittenObjects) throw()
    {
        return FUN_00ddb770(apObject, apClass, true, apWrittenObjects);
    }
    int FUN_00ddb770(const void* object, const hkClassQ* pClassInfo, hkBoolQ recurse,
                     hkArrQ<hkWrittenObjectQ>* written) throw();
};

int hkInspectProcessQ::FUN_00ddb770(const void* object, const hkClassQ* pClassInfo, hkBoolQ recurse,
                                    hkArrQ<hkWrittenObjectQ>* written) throw()
{
    hkStructureLayoutQ layout(DAT_010d6ae8);
    hkArrQ<hkObjectPatchQ> patches;

    const hkClassQ* realClass = pClassInfo;
    if (m_iValueAtOffset0C->m_vtableRegistry && pClassInfo->hasVtable())
    {
        realClass = m_iValueAtOffset0C->m_vtableRegistry->GetClassFromVirtualInstance(object);
        if (!realClass)
        {
            realClass = pClassInfo;
        }
    }

    if (recurse)
    {
        int i;
        for (i = 0; i < written->GetLogicalSize(); i++)
        {
            if ((*written)[i].m_object == object)
            {
                break;
            }
        }
        if (i < written->GetLogicalSize())
        {
            return 0;
        }
        hkWrittenObjectQ w;
        w.m_object = object;
        w.m_class = realClass;
        written->AddBack(w);
    }

    hkArrQ<char> buffer;
    hkArrayStreamWriterQ writer(&buffer, 1);
    int size = FUN_00e0bd40(&writer, &layout, object, 0, object, realClass, &patches);
    if (size != buffer.GetLogicalSize() || size < 1)
    {
        return -1;
    }

    int total = size + 1;
    m_pDisplayStream->FUN_00d60960(total);
    m_pDisplayStream->FUN_00d605d0(0x24);
    m_pDisplayStream->FUN_00d607b0(buffer.m_data, buffer.GetLogicalSize());
    if (recurse)
    {
        for (int i = 0; i < patches.GetLogicalSize(); i++)
        {
            const void* obj = patches[i].m_object;
            const hkClassQ* cls = patches[i].m_class;
            total += sendRecursiveQ(obj, cls, written);
        }
    }
    return total;
}

// sub ecx,8; jmp FUN_00ddbed0 == MSVC adjustor thunk for a secondary base vtable slot.
struct PrimaryBase
{
    virtual void FUN_00ddbec0();
    int unk04;
};

struct SecondaryBase
{
    virtual void FUN_00ddbec0();
};

struct Derived : PrimaryBase, SecondaryBase
{
    Derived();
// @fnv 0x00ddbec0
    virtual void FUN_00ddbec0();
};

Derived::Derived()
{}

namespace fnv_00ddb450 {
struct hkClass;
struct hkClassMember
{
    const char* unk00;
    const hkClass* unk04;
    const void* unk08;
    unsigned char unk0C;
    unsigned char unk0D;
    short unk0E;
    unsigned short unk10;
    unsigned short unk12;
    int __thiscall GetTagValue() const;
    const hkClass* __thiscall FUN_00d86910() const;
};
struct hkClass
{
    const hkClassMember& __thiscall FUN_00d46f20(int i) const;
};
struct hkPathArray
{
    unsigned short* unk00;
};
static __forceinline int nextIndex(const hkPathArray* path, int i)
{
    return path->unk00[i + 1];
}
// Walks a hkPathArray through hkClassMember types to compute and return the pointer to a nested member within data.
// @fnv 0x00ddb450
static __declspec(noinline) void* __cdecl FUN_00ddb450(const hkClassMember* member, char* data, const hkPathArray* path,
                                                       int type, int aiIndex)
{
    char* p = data;
    for (;;)
    {
        switch (type)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 24:
        case 30:
        case 31:
        case 32:
            return p;
        case 14:
        case 15:
        case 16:
        case 17:
        case 18: {
            char* next = p + path->unk00[aiIndex + 1] * 16;
            type = 12;
            ++aiIndex;
            p = next;
        }
            continue;
        case 22:
        case 26: {
            int iIndex = path->unk00[aiIndex + 1];
            {
                char* next = *(char**)p + member->GetTagValue() * iIndex;
                type = member->unk0D;
                ++aiIndex;
                p = next;
            }
            continue;
        }
        case 25: {
            if (!member)
                return 0;
            if (!member->unk04)
                return 0;
            const hkClass* k = member->FUN_00d86910();
            if (!k)
                return 0;
            member = &k->FUN_00d46f20(nextIndex(path, aiIndex));
            {
                char* next = p + member->unk12;
                type = member->unk0C;
                ++aiIndex;
                p = next;
            }
            continue;
        }
        case 20:
            return 0;
        default:
            return 0;
        }
    }
}

void* S00ddb450_Call(int type, char* data, const hkPathArray* path, int i, const hkClassMember* member)
{
    return FUN_00ddb450(member, data, path, type, i);
}
}  // namespace fnv_00ddb450
