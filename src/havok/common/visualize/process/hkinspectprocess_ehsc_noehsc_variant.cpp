// src/havok/common/visualize/process/hkinspectprocess_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/visualize/process/hkinspectprocess.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


void __stdcall GetPunctuationChars(char** apOutString, int* apiLength);
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

// @fnv 0x00ddb770
    __forceinline int sendRecursiveQ(const void* obj, const hkClassQ* cls, hkArrQ<hkWrittenObjectQ>* written) throw()
    {
        return FUN_00ddb770(obj, cls, true, written);
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

typedef unsigned __int64 Wide;
struct InputArchive
{
    void FUN_00dd8fe0(void* data, int width, int count);
    int FUN_00dd90d0(void* data, int bytes);
    __forceinline Wide readWide()
    {
        Wide value;
        FUN_00dd8fe0(&value, 8, 1);
        return value;
    }
    __forceinline unsigned short readWord()
    {
        unsigned short value;
        FUN_00dd8fe0(&value, 2, 1);
        return value;
    }
    __forceinline unsigned int ReadTag()
    {
        unsigned int value;
        FUN_00dd8fe0(&value, 4, 1);
        return value;
    }
    __forceinline unsigned char readByte()
    {
        unsigned char value;
        FUN_00dd8fe0(&value, 1, 1);
        return value;
    }
};
struct HeapAllocator
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void* allocate(int& bytes);
    virtual void release(void* data, int bytes);
    template <class T> __forceinline T* allocateItems(int& count)
    {
        int bytes = count * int(sizeof(T));
        void* data = allocate(bytes);
        count = bytes / int(sizeof(T));
        return static_cast<T*>(data);
    }
};
struct HeapRouter
{
    int unk00, unk04, unk08, unk0c;
    HeapAllocator* allocator;
    __forceinline HeapAllocator& heap()
    {
        return *allocator;
    }
};
static __forceinline HeapAllocator& getHeap()
{
    return static_cast<HeapRouter*>(FUN_00c85750())->heap();
}
void __cdecl FUN_00c908c0(HeapAllocator&, void*, int, int);
void __cdecl ResizeAudioStream(HeapAllocator&, void*, int);
template <class T> struct ListBase
{
    T* data;
    int size;
    int capacity;
    __forceinline ListBase() : data(0), size(0), capacity(0x80000000)
    {}
    __forceinline int GetLogicalSize() const
    {
        return size;
    }
    __forceinline int getCapacity() const
    {
        return capacity & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return data[i];
    }
    __forceinline const T& operator[](int i) const
    {
        return data[i];
    }
    __forceinline T* begin()
    {
        return data;
    }
    __forceinline void owned(T* p, int n, int cap)
    {
        data = p;
        size = n;
        capacity = cap;
    }
    __forceinline void reserve(HeapAllocator& heap, int n)
    {
        if (getCapacity() < n)
        {
            int twice = 2 * getCapacity();
            FUN_00c908c0(heap, this, n < twice ? twice : n, sizeof(T));
        }
    }
    __forceinline void resize(HeapAllocator& heap, int n)
    {
        reserve(heap, n);
        size = n;
    }
    __forceinline void free(HeapAllocator& heap)
    {
        size = 0;
        if (!(capacity & 0x80000000))
            heap.release(data, getCapacity() * int(sizeof(T)));
        data = 0;
        capacity = 0x80000000;
    }
    __forceinline T& expand(HeapAllocator& heap)
    {
        if (size == getCapacity())
            ResizeAudioStream(heap, this, sizeof(T));
        return data[size++];
    }
    __forceinline void remove(int index)
    {
        --size;
        if (size != index)
        {
            const int* source = reinterpret_cast<const int*>(data + size);
            int* destination = reinterpret_cast<int*>(data + index);
            unsigned int i = 0;
            do
            {
                destination[i] = source[i];
            } while (++i < sizeof(T) / 4);
        }
    }
};
template <class T> struct List : ListBase<T>
{
    __forceinline List()
    {}
    __forceinline explicit List(int n)
    {
        HeapAllocator& heap = getHeap();
        T* p = n ? heap.allocateItems<T>(n) : 0;
        int cap = n ? n : 0x80000000;
        owned(p, n, cap);
    }
    __forceinline ~List()
    {
        free(getHeap());
    }
    __forceinline void SetSizeAndGrow(int n)
    {
        resize(getHeap(), n);
    }
    __forceinline T& AllocatePair()
    {
        return expand(getHeap());
    }
};
struct MemberInfo;
struct TypeInfo
{
    MemberInfo& FUN_00d46f60(int index);
    const MemberInfo& FUN_00d46f20(int index) const;
};
struct MemberInfo
{
    const char* name;
    const TypeInfo* type;
    const void* enumeration;
    unsigned char kind, subtype;
    unsigned short count;
    unsigned short flags, offset;
    int GetTagValue() const;
    const TypeInfo& FUN_00d86910() const;
    __forceinline int getOffset() const
    {
        return offset;
    }
    __forceinline int getKind() const
    {
        return kind;
    }
    __forceinline int getSubtype() const
    {
        return subtype;
    }
};
static __declspec(noinline) void* FUN_00ddb450(void* address, const List<unsigned short>& path, int depth, int kind,
                                               int subtype, const MemberInfo* field)
{
    switch (kind)
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
        return address;
    case 14:
    case 15:
    case 17:
    case 18: {
        int childIndex = path[depth + 1];
        void* child = static_cast<char*>(address) + childIndex * 16;
        return FUN_00ddb450(child, path, depth + 1, 12, 0, field);
    }
    case 20:
        return 0;
    case 22:
    case 26: {
        int childIndex = path[depth + 1];
        List<char>* array = static_cast<List<char>*>(address);
        void* child = array->begin() + childIndex * field->GetTagValue();
        return FUN_00ddb450(child, path, depth + 1, field->subtype, 0, field);
    }
    case 25: {
        const TypeInfo* type = field && field->type ? &field->FUN_00d86910() : 0;
        if (type)
        {
            int childIndex = path[depth + 1];
            const MemberInfo& child = type->FUN_00d46f20(childIndex);
            return FUN_00ddb450(static_cast<char*>(address) + child.offset, path, depth + 1, child.kind, child.subtype,
                                &child);
        }
        break;
    }
    }
    return 0;
}
void __cdecl FUN_00cb1260(void* destination, const void* source, int bytes);
struct InspectInputBase
{
    virtual void FUN_00ddbae0(unsigned char);
    int unk04;
    InputArchive* input;
    void* output;
    void* display;
    void* handler;
};
struct InspectConsumer : hkReferencedObject, InspectInputBase
{
    List<hkWrittenObjectQ> tracked;
    void* context;
    virtual void FUN_00ddbae0(unsigned char command);
};
// @fnv 0x00ddbae0
void InspectConsumer::FUN_00ddbae0(unsigned char command)
{
    switch (command)
    {
    case 0x25: {
        Wide objectID = input->readWide();
        Wide classID = input->readWide();
        unsigned short length = input->readWord();
        List<unsigned short> path(length);
        path.SetSizeAndGrow(length);
        for (int i = 0; i < length; ++i)
            path[i] = input->readWord();
        unsigned int bytes = input->ReadTag();
        List<unsigned char> payload(bytes);
        payload.SetSizeAndGrow(bytes);
        input->FUN_00dd90d0(payload.begin(), bytes);
        if (objectID > 0 && classID > 0 && path.GetLogicalSize() > 0 && bytes > 0)
        {
            void* object = reinterpret_cast<void*>(unsigned int(objectID));
            TypeInfo* type = reinterpret_cast<TypeInfo*>(unsigned int(classID));
            const MemberInfo& field = type->FUN_00d46f60(path[0]);
            void* destination = FUN_00ddb450(static_cast<char*>(object) + field.getOffset(), path, 0, field.getKind(),
                                             field.getSubtype(), &field);
            if (destination)
                FUN_00cb1260(destination, payload.begin(), bytes);
        }
        break;
    }
    case 0x23: {
        Wide objectID = input->readWide();
        Wide classID = input->readWide();
        unsigned char flags = input->readByte();
        if (objectID > 0 && classID > 0)
        {
            void* object = reinterpret_cast<void*>(unsigned int(objectID));
            hkClassQ* type = reinterpret_cast<hkClassQ*>(unsigned int(classID));
            List<hkWrittenObjectQ> visited;
            bool recurse = static_cast<const void*>(type) == &g_0126cae8 || (flags & 2);
            reinterpret_cast<hkInspectProcessQ*>(this)->FUN_00ddb770(
                object, type, recurse, reinterpret_cast<hkArrQ<hkWrittenObjectQ>*>(&visited));
            int count = tracked.GetLogicalSize();
            int i = 0;
            for (; i < count; ++i)
                if (tracked[i].m_object == object)
                    break;
            bool present = i != count;
            if (flags & 1)
            {
                if (!present)
                {
                    hkWrittenObjectQ& entry = tracked.AllocatePair();
                    entry.m_class = type;
                    entry.m_object = object;
                }
            }
            else if (present)
                tracked.remove(i);
        }
        break;
    }
    }
}
