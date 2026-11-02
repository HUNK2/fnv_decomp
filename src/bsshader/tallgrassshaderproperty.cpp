// bsshader/tallgrassshaderproperty.cpp: TallGrassShaderProperty, Holder, PointerMap (9 functions)

#include "tallgrassshaderproperty_decls.h"
#pragma optimize("", off)
// @fnv 0x0057ce60
unsigned long TallGrassShaderProperty::GetCacheIdentifier()
{
    return DAT_011c9f6c;
}
#pragma optimize("", on)
// Iterates the grass map, destroys each grass entry, then clears the map and resets two globals.
// @fnv 0x00b62970
void TallGrassShaderProperty::ClearCacheData()
{
    struct Traversal
    {
        TallGrassCacheData* volatile value;
        void* pos;
        unsigned long key;
    } traversal;
    void* initial = GetCacheDataMap()->GetFirstPos();
    traversal.pos = initial;
    traversal.value = 0;
    if (GetCacheDataMap()->GetCount() > 0 && initial)
    {
        do
        {
            GetCacheDataMap()->GetNext(traversal.pos, traversal.key, const_cast<TallGrassCacheData*&>(traversal.value));
            DestroyGrass(traversal.value);
        } while (traversal.pos);
    }
    reinterpret_cast<GrassMap*>(GetCacheDataMap())->RemoveAll();
    DAT_011f9ef4 = 0;
    DAT_011f9ef8 = 0;
}

// Iterates the cached geometry entries, releasing unowned geometries and their data, then removes all entries from the map.
// @fnv 0x00b62a20
void TallGrassShaderProperty::ClearCaches()
{
    ClearCacheData();
    void* initial = GetGeometryCacheMap()->GetFirstPos();
    void* pos = initial;
    NiPointerCachedGeometry value;
    const char* key;
    if (GetGeometryCacheMap()->GetCount() > 0)
    {
        if (initial)
        {
            do
            {
                GetGeometryCacheMap()->GetNext(pos, key, value);
                GeometryCacheEntry* geometry = value;
                if (geometry && !geometry->owned)
                {
                    geometry->geometry.Reset();
                    TallGrassFree(geometry->data);
                    geometry->data = 0;
                    geometry->field14.Reset();
                    geometry->field1c.Reset();
                    geometry->field18.Reset();
                    geometry->field20.Reset();
                }
            } while (pos);
        }
        reinterpret_cast<GrassMap*>(GetGeometryCacheMap())->RemoveAll();
    }
}

struct BSStr
{
    bool Set(char const*, unsigned int);
};
struct NiStream
{
    void ReadStreamString(char*&);
};
struct Helper
{
    void FUN_00b70260(NiStream&);
};
void _NiFreeAlias(void*);
struct Holder
{
    char _pad[0x88];
    BSStr mStr;
    void ReadStringFromStream(NiStream&);
};
// Reads a string from the stream, stores it into mStr, then frees the temporary buffer.
// @fnv 0x00b60fc0
void Holder::ReadStringFromStream(NiStream& stream)
{
    ((Helper*)this)->FUN_00b70260(stream);
    char* pBuffer = 0;
    stream.ReadStreamString(pBuffer);
    mStr.Set(pBuffer, 0);
    _NiFreeAlias(pBuffer);
}

struct P03MM
{
    void* Allocate(unsigned int);
};
extern unsigned int DAT_011f9ef4;
extern __declspec(thread) int g_tlsMemContext;

struct AutoMemContext
{
    int iPrevContext;
    AutoMemContext(int aiContext)
    {
        iPrevContext = g_tlsMemContext;
        g_tlsMemContext = aiContext;
    }
    ~AutoMemContext()
    {
        g_tlsMemContext = iPrevContext;
    }
};

struct IntegerDataBlock
{
    int m_iWordAt00;
    unsigned long m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
};
struct GeometryCacheEntry;
template <class T> class NiPointer;
struct NiGPUProgram;
template <> class NiPointer<NiGPUProgram>
{
  public:
    NiGPUProgram* m_pObject;
    NiPointer<NiGPUProgram>& operator=(NiGPUProgram*);
};

struct TallGrassGroup_Node
{
    TallGrassGroup_Node* m_pkNext;
    TallGrassGroup_Node* m_pkPrev;
    struct FUN_00bd8f90* m_element;
};
struct FUN_00b58570_Class
{
    TallGrassGroup_Node* m_pkHead;
    TallGrassGroup_Node* m_pkTail;
    void* FUN_00b58570(void* element);
    struct FUN_00bd8f90* GetNext(void*& piter) const
    {
        struct FUN_00bd8f90* const& element = ((TallGrassGroup_Node*)piter)->m_element;
        piter = ((TallGrassGroup_Node*)piter)->m_pkNext;
        return element;
    }
};

struct FUN_00b617f0
{
    IntegerDataBlock m_kIntegerDataBlock;
    FUN_00b58570_Class m_kNode;
    int m_28;
    NiPointer<NiGPUProgram> m_spCachedGeometry;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    unsigned int m_3c;
    FUN_00b617f0();
    static void* operator new(unsigned int s)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(s);
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};

struct NiNodeStub
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void AttachChildInAvailableSlot(void* child, bool firstAvail);
};

struct FUN_00bd8f90
{
    void* m_pFirstObject;
    void* m_pSecondObject;
    void* m_pData;
    int m_iThirdValue;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
    unsigned int m_14;
    unsigned int m_18;
    unsigned int m_1c;
    unsigned int m_20;
    unsigned int m_24;
    unsigned int m_28;
    unsigned int m_2c;
    unsigned int m_30;
    unsigned int m_34;
    unsigned int m_38;
    int m_aiIntegerPair[2];
    int m_44;
    ~FUN_00bd8f90();
    void CopySettings(IntegerDataBlock* p);
    unsigned short GetRemaining() const
    {
        return m_usFirstValue - m_usSecondValue;
    }
    static void* operator new(unsigned int s)
    {
        return ((P03MM*)&g_memoryManager)->Allocate(s);
    }
    static void operator delete(void* p)
    {
        g_memoryManager.Deallocate(p);
    }
};
struct FUN_00bd8ae0 : FUN_00bd8f90
{
    FUN_00bd8ae0(GeometryCacheEntry* geom, int x, int y, int z);
};

struct NiTStringPointerMap_00e93020
{
    __declspec(noalias) bool GetAt(void* key, void*& val);
};
struct NiVBSet
{
    void Create(unsigned int key, void* val);
};
GeometryCacheEntry* __cdecl FUN_00b61980(IntegerDataBlock* p);
void* __cdecl _memmove(void*, const void*, unsigned int);

// Looks up a cached grass group for the cell, creating and attaching a new one to the node when none has remaining capacity, and returns its remaining count.
// @fnv 0x00b62bd0
unsigned short __cdecl GetOrCreateGrassGroup(IntegerDataBlock* apGrassParam, int aiCellX, int aiCellY,
                                             FUN_00bd8f90** apGrassGroup, NiNodeStub* apGrassNode)
{
    FUN_00b58570_Class* pCurrentElementNext;
    AutoMemContext tempMemContext(0x1c);
    void* piter;
    FUN_00b617f0* pGrassCache;
    GeometryCacheEntry* pcachedGeom;
    FUN_00bd8f90* pgrassgroup;
    *apGrassGroup = 0;
    pcachedGeom = FUN_00b61980(apGrassParam);
    if (!pcachedGeom)
        return 0;
    pGrassCache = 0;
    if (!((NiTStringPointerMap_00e93020*)TallGrassShaderProperty::GetCacheDataMap())
             ->GetAt((void*)apGrassParam->m_iWordAt04, (void*&)pGrassCache))
    {
        pGrassCache = new FUN_00b617f0();
        pGrassCache->m_spCachedGeometry = (NiGPUProgram*)pcachedGeom;
        _memmove(pGrassCache, apGrassParam, 0x20);
        ((NiVBSet*)TallGrassShaderProperty::GetCacheDataMap())->Create(apGrassParam->m_iWordAt04, pGrassCache);
    }
    pCurrentElementNext = &pGrassCache->m_kNode;
    piter = pCurrentElementNext->m_pkHead;
    while (!*apGrassGroup && piter)
    {
        pgrassgroup = pCurrentElementNext->GetNext(piter);
        if (pgrassgroup->m_usSecondValue != pgrassgroup->m_usFirstValue && aiCellX == pgrassgroup->m_aiIntegerPair[0] &&
            aiCellY == pgrassgroup->m_aiIntegerPair[1])
        {
            *apGrassGroup = pgrassgroup;
            break;
        }
    }
    if (!*apGrassGroup || !(*apGrassGroup)->GetRemaining())
    {
        delete *apGrassGroup;
        *apGrassGroup = new FUN_00bd8ae0(pcachedGeom, aiCellX, aiCellY, 0);
        ++DAT_011f9ef4;
        (*apGrassGroup)->CopySettings(apGrassParam);
        pCurrentElementNext->FUN_00b58570(apGrassGroup);
        apGrassNode->AttachChildInAvailableSlot((*apGrassGroup)->m_pSecondObject, true);
    }
    return (*apGrassGroup)->GetRemaining();
}

struct BSFadeNode
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
    BSFadeNode();
};
struct FUN_00b60f50 : BSFadeNode
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    int m_14;
    int m_18;
    int m_1c;
    int m_20;
    int m_24;
    int m_28;
    int m_2c;
    int m_30;
    int m_34;
    int m_38;
    int m_3c;
    int m_40;
    int m_44;
    int m_48;
    int m_4c;
    int m_50;
    int m_54;
    int m_58;
    int m_5c;
    int m_60;
    int m_64;
    int m_68;
    int m_6c;
    int m_70;
    int m_74;
    int m_78;
    int m_7c;
    int m_80;
    int m_84;
    int m_88;
    int m_8c;
    int m_90;
    int m_94;
    FUN_00b60f50();
};
// Allocates and constructs a new FUN_00b60f50 instance, returning the new object.
// @fnv 0x00b60f50
FUN_00b60f50* FUN_00b60f50_Create()
{
    return new FUN_00b60f50;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
struct MapObject
{
    virtual void slot0();
    virtual void DeleteThis();
    volatile long refs;
    void DecRef()
    {
        if (InterlockedDecrement(&refs) == 0)
            DeleteThis();
    }
};
struct MapPointer
{
    MapObject* pointer;
    MapPointer(const MapPointer& other) : pointer(other.pointer)
    {
        if (pointer)
            InterlockedIncrement(&pointer->refs);
    }
    ~MapPointer()
    {
        if (pointer)
            pointer->DecRef();
    }
    MapPointer& operator=(const MapPointer& other)
    {
        if (pointer != other.pointer)
        {
            if (pointer)
                pointer->DecRef();
            pointer = other.pointer;
            if (pointer)
                InterlockedIncrement(&pointer->refs);
        }
        return *this;
    }
};
struct MapEntry
{
    MapEntry* next;
    const char* key;
    MapPointer value;
};
struct MapPool
{
    unsigned int count;
    MapEntry* FUN_0043a010();
};
struct PointerMap
{
    virtual void slot0();
    virtual unsigned int Hash(const char*);
    virtual bool Equal(const char*, const char*);
    virtual void SetValue(MapEntry*, const char*, MapPointer);
    unsigned int hashSize;
    MapEntry** buckets;
    MapPool allocator;
    bool preserveKey;
    void FUN_00b61010(const char* key, MapPointer value);
};
// @fnv 0x00b61010
void PointerMap::FUN_00b61010(const char* key, MapPointer value)
{
    unsigned int hash = Hash(key);
    MapEntry* entry = buckets[hash];
    while (entry)
    {
        if (Equal(key, entry->key))
        {
            if (!preserveKey)
                entry->key = key;
            entry->value = value;
            return;
        }
        entry = entry->next;
    }
    entry = allocator.FUN_0043a010();
    SetValue(entry, key, value);
    entry->next = buckets[hash];
    buckets[hash] = entry;
    ++allocator.count;
}

struct GrassParamF
{
    int m_iWordAt00;
    unsigned long m_iWordAt04;
    int m_8;
    float m_iThirdValue;
    float m_10;
    int m_14;
    int m_18;
    int m_1c;
};

struct GrassGroupStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    NiVBSet kVBSet;
    void PushEntry(float* apInstance, void* apKey);
    void UpdateBounds();
};

int __cdecl PackFloatPairToInt(float* apPos);
void __cdecl FUN_00ecada6(int aiSeed);
int __cdecl FUN_00ecadb8();
NiTStringPointerMap_00e93020* __cdecl GetArrayHolder();

inline float FloorF(float f)
{
    float r = (float)(int)f;
    if (f - r >= 0.0)
        return r;
    return r - 1.0;
}

// Adds entries using supplied positions and scales, derives a fourth instance value from parameters and random values, then creates a vertex buffer set.
// @fnv 0x00b62de0
void __cdecl PopulateGrassInstances(void* apKey, int aiCellX, int aiCellY, NiNodeStub* apGrassNode,
                                    GrassParamF* apParam, float (*apPositions)[3], float* apScales,
                                    unsigned short auiCount)
{
    AutoMemContext kContext(0x1c);

    DAT_011f9ef8 += auiCount;

    int iIndex = 0;
    while (auiCount > 0)
    {
        GrassGroupStub* pGroup = 0;
        unsigned short iCount =
            GetOrCreateGrassGroup((IntegerDataBlock*)apParam, aiCellX, aiCellY, (FUN_00bd8f90**)&pGroup, apGrassNode);
        if (!pGroup)
            return;
        for (int j = 0; j < iCount; j++)
        {
            if (auiCount <= 0)
                break;
            FUN_00ecada6(PackFloatPairToInt(apPositions[iIndex]));
            float afInstance[4];
            afInstance[0] = apPositions[iIndex][0];
            afInstance[1] = apPositions[iIndex][1];
            afInstance[2] = apPositions[iIndex][2];
            float fRand = FUN_00ecadb8() / 65534.0 - 1.0;
            afInstance[3] = (1.0 - apParam->m_10 + apParam->m_10 * 0.5 * fRand) * apScales[iIndex];
            if (afInstance[3] >= 1.0)
                afInstance[3] = 0.99f;
            else if (afInstance[3] < 0.0)
                afInstance[3] = 0.0;
            float fRand2 = FUN_00ecadb8() / 32767.0 * 2.0 - 1.0;
            float fValue = apParam->m_iThirdValue * fRand2 * 100.0;
            afInstance[3] = FloorF(fValue) + afInstance[3];
            pGroup->PushEntry(afInstance, apKey);
            auiCount--;
            iIndex++;
        }
        pGroup->UpdateBounds();
    }

    apGrassNode->v47();

    GrassGroupStub* pGroup = 0;
    GetArrayHolder()->GetAt((void*)apParam->m_iWordAt04, (void*&)pGroup);
    pGroup->kVBSet.Create((unsigned int)apKey, apKey);
}

namespace fnv_00b61170 {
void* __cdecl FUN_00aa1070(unsigned int size);
void __cdecl FUN_00ec61c0(void* p, int fill, unsigned int size);
int __cdecl FUN_00ec658f(void(__cdecl* fn)());

struct ArrayHolderBase
{
    virtual void Unk_00();
    int m_04;
    void* m_08;
    unsigned int m_0C;
    ArrayHolderBase()
    {
        m_04 = 0x25;
        m_0C = 0;
        m_08 = FUN_00aa1070(m_04 * 4);
        FUN_00ec61c0(m_08, 0, m_04 * 4);
    }
};

struct ArrayHolder : ArrayHolderBase
{
    virtual ~ArrayHolder()
    {
        m_0C = 0;
    }
};

// Returns a pointer to a static ArrayHolder instance.
// @fnv 0x00b61170
ArrayHolder* __cdecl GetArrayHolder()
{
    static ArrayHolder obj;
    return &obj;
}
}  // namespace fnv_00b61170
