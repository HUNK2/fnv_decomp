
// NavMeshInfoMap: bounding-box verification and loaded-info initialization.
// NavMeshBounds, BSSimpleArray 16, NiTPointerMap 16) with layout asserts.

#include <stddef.h>
#include <malloc.h>
class TESFile;
class TESObjectREFR;
class NavMesh;
enum MEM_CONTEXT
{
    MEM_CONTEXT_NAVMESH = 46
};
enum ENUM_FORM_ID
{
    ENUM_FORM_ID_NAVMESHINFOMAP = 56
};
template <int N> struct EndianSizeTag
{
    char value;
};
void BSEndian(unsigned int*, EndianSizeTag<4>);
void BSEndian(int*, EndianSizeTag<4>);
void* operator new(unsigned int);
void operator delete(void*);
class MemoryManager
{
  public:
    static void* Allocate(unsigned int);
};
void FNV_DeleteBuffer(void*);
class AutoMemContext
{
  public:
    MEM_CONTEXT m_eMemoryContext;
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};

#define NULL 0

#pragma pack(push, 4)

class NavMeshBounds
{
  public:
    unsigned char data[56];
};

class NavMeshInfo;
template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;             // +0x0
    T* pBuffer;                  // +0x4
    unsigned int iSize;          // +0x8
    unsigned int SimpleArrayStorage;  // +0xC
    BSSimpleArray();
    ~BSSimpleArray();
    T& operator[](unsigned int index);
    unsigned int Add(T& item);
    unsigned int GetSize();
    T& GetAt(int iIndex);
    template <unsigned int Other> void CopyTo(BSSimpleArray<T, Other>*);
    template <class U> unsigned int Find(U&, unsigned int, bool(__cdecl*)(U&, U&));
};
typedef char BSSimpleArrayCheck[sizeof(BSSimpleArray<NavMeshInfo*, 1024>) == 16 ? 1 : -1];

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    static const NiPoint3 ZERO;
};
class NavMeshInfo
{
  public:
    unsigned int m_uiNavMeshID;                   // +0x0
    unsigned int m_uiParentSpaceID;               // +0x4
    unsigned int uiFlags;                         // +0x8
    int m_uiPathingFlags;                         // +0xC
    NiPoint3 m_kNavMeshPosition;                  // +0x10
    void* m_pParentSpace;                         // +0x1C
    float m_fStoredValue;                         // +0x20
    BSSimpleArray<NavMeshInfo*, 1024> adjacent;   // +0x24
    BSSimpleArray<NavMeshInfo*, 1024> preferred;  // +0x34
    BSSimpleArray<TESObjectREFR*, 1024> doors;    // +0x44
    void* m_pLocationNavMesh;                     // +0x54
    NavMeshBounds* pBounds;                       // +0x58
    NavMeshBounds* GetBounds();
    NavMeshInfo();
    ~NavMeshInfo();
    void LoadNavMeshInfo(char*, TESFile*, int);
    void LoadSerializedData(char*, TESFile*, int);
    bool AcquireNavMesh(class NavMeshPtr&);
    void CopyTo(NavMeshInfo*);
    void SetNavMesh(NavMesh*);
    class TESObjectCELL* GetInteriorCell();
    unsigned int GetNavMeshID();
    void ReleaseNavMesh();
};
typedef char NavMeshInfoCheckSize[sizeof(NavMeshInfo) == 92 ? 1 : -1];
typedef char NavMeshInfoCheckBounds[offsetof(NavMeshInfo, pBounds) == 0x58 ? 1 : -1];

template <class K, class V> class NiTMapItem
{
  public:
    NiTMapItem<K, V>* m_pkNext;
    K m_key;
    V m_val;
};

template <class K, class V> class NiTPointerMap
{
  public:
    void** m_ppVirtualMethodTable;                    // +0x0
    unsigned int m_uiHashSize;          // +0x4
    NiTMapItem<K, V>** m_ppkHashTable;  // +0x8
    struct MapEntryCount
    {
        unsigned int m_uiCount;
    } m_kItemCount;  // +0xC
    NiTPointerMap(unsigned int uiHashSize);
    ~NiTPointerMap();
    bool RemoveAt(unsigned int key);
    bool GetAt(unsigned int key, V& val) const;
    template <class U> bool GetAt(unsigned int key, U& val) const;
    void SetAt(unsigned int key, void* val);
    void* GetFirstPos();
    void GetNext(void*& pPos, unsigned int& uiKey, void*& val);
};
typedef char NiTMapCheck[sizeof(NiTPointerMap<unsigned int, void*>) == 16 ? 1 : -1];

typedef BSSimpleArray<NavMeshInfo*, 1024> NavMeshInfoArray;

typedef NiTPointerMap<unsigned int, void*> CellKeyMap;

struct OuterPair
{
    void* pInnerMapRaw;
    unsigned int uiOuterKey;
};

struct InnerCounts
{
    unsigned int uiIndex;
    unsigned int uiValid;
};

class TESForm
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual ~TESForm();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void readOBNDSubRecord(TESFile*);
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual bool SetEditorID_AtRuntime(const char*);
    unsigned char data[20];
    TESForm();
    unsigned int GetFormID();
    void LoadRecordHeader(TESFile*);
    void SetFormType(ENUM_FORM_ID);
    static void RemapFormIDForFile(unsigned int&, TESFile*);
    static TESForm* GetFormByID(unsigned int id);
};
typedef char TESFormCheck[sizeof(TESForm) == 24 ? 1 : -1];

class NavMeshInfoMap : public TESForm
{
  public:
    bool m_bNavMeshInfoArraysValid;  // +0x18
    unsigned char pad19[3];
    NiTPointerMap<unsigned int, NavMeshInfo*> m_kNavMeshInfosByFormID;  // +0x1C
    NiTPointerMap<unsigned int, NiTPointerMap<unsigned int, NavMeshInfoArray*>*>
        m_kNavMeshInfoArraysByWorldspace;  // +0x2C
    bool m_bKeepNavMeshLoaded;             // +0x3C
    unsigned char pad3D[3];
    NavMeshInfoMap();
    bool Load(TESFile*);
    NavMeshInfo* FUN_00693d70(unsigned int);
    bool ValidateNavMeshInfoArrays();
    void InitItem();
    void InsertNavMeshInfo(NavMeshInfo* info);
};
typedef char NavMeshInfoMapCheck[sizeof(NavMeshInfoMap) == 64 ? 1 : -1];
typedef char NavMeshInfoMapCheckCell[offsetof(NavMeshInfoMap, m_kNavMeshInfoArraysByWorldspace) == 0x2C ? 1 : -1];

#pragma pack(pop)

class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool GetChunkData(void*, unsigned int);
    bool IsEndianConversionRequired();
    bool NextChunk();
};
class TESObjectREFR : public TESForm
{
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
};
class NavMeshPtr : public NiPointer<NavMesh>
{
  public:
    NavMeshPtr();
    ~NavMeshPtr();
    NavMesh* GetPtr();
};
typedef BSSimpleArray<TESObjectREFR*, 1024> NavMeshDoorArray;

class TESWorldSpace : public TESForm
{
  public:
    bool GetSmallWorld();
};
unsigned int FUN_006b7b30(NavMeshInfo*);
bool FUN_009a3830(NavMeshInfo*&, NavMeshInfo*&);

// Keep the accepted InitItem spelling while recovering the vector member.
#define approxZ m_kNavMeshPosition.z
