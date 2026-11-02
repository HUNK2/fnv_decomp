
// src/havok/common/serialize/copier/hkdeepcopier_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/common/serialize/copier/hkdeepcopier.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/common/serialize/copier/hkdeepcopier.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/serialize/copier/hkdeepcopier.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

inline void* operator new(unsigned int, void* p) throw()
{
    return p;
}

struct hkMemAlloc
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void ReturnMemory(void* p, int numBytes);
};

struct hkMemRouter
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemAlloc* m_pStreamAllocator;
    hkMemAlloc& heap()
    {
        return *m_pStreamAllocator;
    }
};

void* FUN_00c85750();
void ResizeAudioStream(void* alloc, void* arr, int elemSize);
void* AllocateWithHeader(hkMemAlloc& alloc, int numBytes);
void FUN_00cb1260(void* dst, const void* src, int n);

__forceinline hkMemRouter* GetRouter()
{
    return (hkMemRouter*)FUN_00c85750();
}

template <class T> __forceinline void hkConstructWithCopy(T* p, int n, const T& t)
{
    for (int i = 0; i < n; i++)
        p[i] = t;
}

template <class T> struct hkArr
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    __forceinline hkArr() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    __forceinline ~hkArr()
    {
        _clearAndDeallocate(GetRouter()->heap());
    }
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    __forceinline int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    __forceinline T& operator[](int i)
    {
        return m_data[i];
    }
    __forceinline void _clearAndDeallocate(hkMemAlloc& alloc)
    {
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
    __forceinline void AddBack(const T& t)
    {
        hkMemAlloc& alloc = GetRouter()->heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        hkConstructWithCopy(m_data + m_iElementCount, 1, t);
        m_iElementCount++;
    }
    __forceinline void expandRecord(int offset, const void* obj, const char* name)
    {
        hkMemAlloc& alloc = GetRouter()->heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        ::new (m_data + m_iElementCount) T(offset, obj, name);
        m_iElementCount++;
    }
    __forceinline void pushBackConstruct(const T& t)
    {
        hkMemAlloc& alloc = GetRouter()->heap();
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(T));
        ::new (m_data + m_iElementCount) T(t);
        m_iElementCount++;
    }
};

struct hkBoolRet
{
    char m_cBooleanValue;
    hkBoolRet(bool b) : m_cBooleanValue(b)
    {}
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct ClassInfo
{
    const char* FUN_00d46d40() const;
    hkBoolRet GetLastNodeFlag() const;
};

struct VtableClassReg
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual const ClassInfo* GetClassFromVirtualInstance(const void* obj);
};

struct LoadedObjectReg
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void RegisterLoadedObject(void* obj, const char* typeName);
};

struct PtrMapBase
{
    void** m_kPrimitiveElement;
    int m_iCapacityFlags;
    int m_iPairCount;
    __forceinline PtrMapBase() : m_kPrimitiveElement(0), m_iCapacityFlags(0), m_iPairCount(-1)
    {}
    ~PtrMapBase();
    void EnsureCapacity(hkMemAlloc& alloc, int n);
    void FUN_00cb1870(hkMemAlloc& alloc, const void* key, int val);
    int FindSlot(const void* key);
    int LookupHashEntry(const void* key, int def);
    void ProcessArgument(hkMemAlloc& alloc);
    __forceinline bool isValid(int it) const
    {
        return it <= m_iPairCount;
    }
};

struct PtrMap
{
    PtrMapBase m_map;
    __forceinline PtrMap()
    {
        m_map.EnsureCapacity(GetRouter()->heap(), 0);
    }
    __forceinline ~PtrMap()
    {
        m_map.ProcessArgument(GetRouter()->heap());
    }
    __forceinline void insert(const void* key, int val)
    {
        m_map.FUN_00cb1870(GetRouter()->heap(), key, val);
    }
    __forceinline int FindValueForKey(const void* key, int def)
    {
        return m_map.LookupHashEntry(key, def);
    }
    __forceinline bool contains(const void* key)
    {
        return m_map.isValid(m_map.FindSlot(key));
    }
};

struct StructureLayoutRules
{
    unsigned char m_ucBytesInPointer;
    unsigned char m_bLittleEndian;
    unsigned char m_bReusePaddingOptimization;
    unsigned char m_bEmptyBaseClassOptimization;
};
extern const StructureLayoutRules g_hostLayoutRules_e4afe0;

struct StructLayout
{
    StructureLayoutRules m_kLayoutRules;
    StructLayout(const StructureLayoutRules& rules);
};

struct LocalFixup
{
    int m_iSourceOffset;
    int m_iTargetOffset;
};
struct TypedPointerRecord
{
    int m_iSourceOffset;
    void* m_pData;
    const ClassInfo* m_pClassInfo;
    int m_type;
};
struct FinishFixup
{
    int m_iSourceOffset;
    const char* m_pClassName;
};
struct ImportFixup
{
    int m_iSourceOffset;
    const char* m_pImportName;
};

struct RelocInfo
{
    hkArr<LocalFixup> m_pTrailingData;
    hkArr<TypedPointerRecord> m_pGlobal;
    hkArr<FinishFixup> m_kFinishFixups;
    hkArr<ImportFixup> m_kImports;
    void* m_kNodePool;
    __forceinline RelocInfo() : m_kNodePool(0)
    {}
    ~RelocInfo();
};

struct OArchive
{
    void* m_ppVirtualMethodTable;
    int m_memSizeAndRefCount;
    void* m_pStreamWriter;
    OArchive(hkArr<char>& buf);
    ~OArchive();
    void* GetStreamWriter()
    {
        return m_pStreamWriter;
    }
};

struct ObjCopier
{
    void* m_ppVirtualMethodTable;
    int m_memSizeAndRefCount;
    int m_iInputSize;
    int m_iOutputSize;
    int m_flags;
    bool m_bStreamResult;
    ObjCopier(const StructLayout& layoutIn, const StructLayout& layoutOut, int flags);
    ~ObjCopier();
    int FUN_00e04920(const void* dataIn, const ClassInfo& klassIn, void* dataOut, const ClassInfo& klassOut,
                     RelocInfo& reloc);
};

struct PendingCopy
{
    const void* m_object;
    const ClassInfo* m_pObjectTypeInfo;
};

struct CopyRecord
{
    int m_offset;
    const void* m_object;
    const char* m_pName;
    __forceinline CopyRecord(int offset, const void* obj, const char* name)
        : m_offset(offset), m_object(obj), m_pName(name)
    {}
};

// @fnv 0x00e4afe0
void* FUN_00e4afe0(const void* dataIn, const ClassInfo& klassIn, PtrMap* previousCopies,
                   VtableClassReg* vtableClassRegistry, LoadedObjectReg* loadedObjectRegistry, int flags)
{
    hkArr<char> buffer;
    OArchive dataOut(buffer);
    RelocInfo reloc;
    hkArr<PendingCopy> todo;
    {
        PendingCopy p;
        p.m_object = dataIn;
        p.m_pObjectTypeInfo = &klassIn;
        todo.AddBack(p);
    }
    PtrMap doneObjects;
    hkArr<CopyRecord> records;
    ObjCopier copier(g_hostLayoutRules_e4afe0, g_hostLayoutRules_e4afe0, flags);

    for (int todoIndex = 0; todoIndex < todo.GetLogicalSize(); ++todoIndex)
    {
        const void* obj = todo[todoIndex].m_object;
        const ClassInfo* pClassInfo = todo[todoIndex].m_pObjectTypeInfo;
        doneObjects.insert(obj, buffer.GetLogicalSize());
        int globalStart = reloc.m_pGlobal.GetLogicalSize();
        if (pClassInfo->GetLastNodeFlag())
            pClassInfo = vtableClassRegistry->GetClassFromVirtualInstance(obj);

        int offset = buffer.GetLogicalSize();
        const char* name = pClassInfo->FUN_00d46d40();
        records.pushBackConstruct(CopyRecord(offset, obj, name));

        copier.FUN_00e04920(obj, *pClassInfo, dataOut.GetStreamWriter(), *pClassInfo, reloc);

        for (int j = globalStart; j < reloc.m_pGlobal.GetLogicalSize(); ++j)
        {
            void* ptr = reloc.m_pGlobal[j].m_pData;
            if (!ptr)
                continue;
            const ClassInfo* ptrClass = reloc.m_pGlobal[j].m_pClassInfo;
            if (!ptrClass)
                continue;
            if (previousCopies)
            {
                int prev = previousCopies->FindValueForKey(ptr, 0);
                if (prev)
                {
                    reloc.m_pGlobal[j].m_pData = (void*)prev;
                    continue;
                }
            }
            if (!doneObjects.contains(ptr))
            {
                PendingCopy p;
                p.m_object = ptr;
                p.m_pObjectTypeInfo = ptrClass;
                todo.AddBack(p);
            }
        }
    }

    if (buffer.GetLogicalSize())
    {
        char* versioned = (char*)AllocateWithHeader(GetRouter()->heap(), buffer.GetLogicalSize());
        FUN_00cb1260(versioned, buffer.m_data, buffer.GetLogicalSize());

        for (int i = 0; i < reloc.m_pTrailingData.GetLogicalSize(); ++i)
            *(char**)(versioned + reloc.m_pTrailingData[i].m_iSourceOffset) =
                versioned + reloc.m_pTrailingData[i].m_iTargetOffset;

        for (int i = 0; i < reloc.m_pGlobal.GetLogicalSize(); ++i)
        {
            void* ptr = reloc.m_pGlobal.m_data[i].m_pData;
            int offset = doneObjects.FindValueForKey(ptr, -1);
            if (offset != -1)
                ptr = versioned + offset;
            *(void**)(versioned + reloc.m_pGlobal.m_data[i].m_iSourceOffset) = ptr;
        }

        if (previousCopies)
        {
            for (int i = 0; i < records.GetLogicalSize(); ++i)
                previousCopies->insert(records[i].m_object, (int)(versioned + records[i].m_offset));
        }

        if (loadedObjectRegistry)
        {
            for (int i = 0; i < records.GetLogicalSize(); ++i)
                loadedObjectRegistry->RegisterLoadedObject(versioned + records[i].m_offset, records[i].m_pName);
        }

        return versioned;
    }
    return 0;
}
