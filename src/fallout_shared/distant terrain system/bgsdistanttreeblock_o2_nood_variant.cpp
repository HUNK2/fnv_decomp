
// src/fallout_shared/distant terrain system/bgsdistanttreeblock_o2_nood_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHsc /Gy (unit src/fallout_shared/distant terrain system/bgsdistanttreeblock.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/fallout_shared/distant terrain system/bgsdistanttreeblock.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/distant terrain system/bgsdistanttreeblock.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct NP
{
    NP& operator=(void*);
};
extern NP DAT_012007c4;
void FUN_006f7a60(void* p);
struct BGSDistantTreeBlockLoadTask
{
    void* Destroy(unsigned int flags);
    void FUN_006f94a0();
};
void* __cdecl _Deallocate(void*);
struct GO
{
    void* p;
    GO(int);
    ~GO();
};
struct Helper8
{
    void FUN_006f9740();
};
struct FUN_006f8650
{
    int unk0;
    GO unk4;
    Helper8 unk8;
    FUN_006f8650();
};
struct FUN_006b3140_shell
{
    void AddElement(void*);
    void* FUN_006b3140();
};
extern FUN_006b3140_shell g_011d85d0;
void BuildNavMeshGeometry(void*);
void FUN_006f86b0(void* a1);
struct FUN_006f8800_shell
{
    void FUN_006f8830();
    void* FUN_006f8800(unsigned int flags);
};
struct Flt
{
    operator unsigned int();
};
struct MiddleHighProcess
{
    void FUN_00929260(unsigned char);
};
struct QIdlePtr
{
    QIdlePtr& operator=(void*);
};
struct FUN_006f88e0_shell
{
    void FUN_006f88e0();
};
struct BGSDistantTreeBlockLoadTask;
struct BGSDistantTreeBlockLoadTask_shell : BGSDistantTreeBlockLoadTask
{
    void FUN_006f94c0();
};
struct Block88
{
    void FUN_006f88e0();
};
struct Holder96
{
    char _0[0x30];
    Block88* p30;
    char _34[0x10];
    unsigned char b44;
    unsigned char b45;
    void FUN_006f9610();
};
struct InstanceData
{
    int f[8];
};
struct FakeArray
{
    int _0;
    InstanceData* _4;
    unsigned int __thiscall GetNextIndex();
    void __thiscall ConstructElements(void*, int);
    unsigned int __thiscall AppendInstance(InstanceData*);
};
struct NavMeshSearchLOSArray
{
    void FUN_006a8500();
    void FUN_006ac070(void*, unsigned int);
};
struct ShaderProp
{
    void __thiscall FUN_006fa090(void* a, void* b);
};
struct FUN_006f9c70_shell
{
    void FUN_006f9c70(bool freeStorage);
};
int __cdecl _sprintf_s(char*, unsigned int, const char*, ...);
struct Fake076
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual void v70();
    virtual void v71();
    virtual void v72();
    virtual void v73();
    virtual void v74();
    virtual void v75();
    virtual const char* GetStr();
};
int __cdecl FormatTreeLodDtlPath(char* a1, Fake076* a2, int a3, short a4, short a5);
struct Arr
{
    unsigned int* GetAt(int, int);
};
struct ArrSI : public Arr
{
    unsigned int GetFlags();
};
struct BGSDistantTreeBlock
{
    char _pad[52];
    ArrSI mArray;
    void MarkTreeInstance(unsigned int);
    void FUN_006f7780();
    void ProcessAllTrees();
};
struct IOTask
{
    bool FUN_0043caa0();
    void NotifyParents();
};
class SoundPlaybackHandle;
template <typename A, typename B> struct NiTPointerMap
{
    bool IsEmpty();
};
struct IOManager
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
    virtual void v18(void*);
};
extern IOManager* DAT_01202d98;
struct FUN_006f94e0_shell
{
    char _pad[52];
    bool m_bValueAtOffset34;
    void FUN_006f94e0();
};
struct DummyPointerMap
{
    bool GetAt(unsigned int, unsigned int&);
};
struct BSSimpleArrayStandIn
{
    unsigned int Add(void*&);
};
struct InstanceDataB
{
    unsigned char b1c;
};
struct ArrB
{
    unsigned int* GetAt(int);
};
struct BGSDistantTreeBlock_shell : BGSDistantTreeBlock
{
    void MarkTreeInstance(unsigned int aID, bool abQueue);
};
struct FUN_006b3120_helper
{
    unsigned char* __thiscall GetElementAt(int);
};
extern NP g_011d85bc;
extern NP g_011d85c4;
extern NP g_011d85e0;
extern unsigned char DAT_011d85a0;
void FUN_006f83f0();
struct NiBinaryStream
{
    unsigned int Read(void* buffer, unsigned int size);
};
struct NiFile : public NiBinaryStream
{
};
struct NiBound
{
    unsigned int x0;
    unsigned int x1;
    unsigned int x2;
    unsigned int x3;
    unsigned int x4;
    unsigned int x5;
    unsigned int x6;
    unsigned int x7;

    NiBound();
};
struct AutoMemHelper
{
    int value;

    AutoMemHelper(int context, bool flag, const char* file, int line);
    ~AutoMemHelper();
};
extern const char str_0106dd30[];
struct FUN_006f8b40_shell
{
    void ClearEntries();
    void AddTreeInstance(unsigned int type, void* instance);
    void ReadGroups(NiFile* apInputFile);
};
struct FUN_00bb7290_shell
{
    void SetEntry(unsigned int, float, float, float, float, float);
};
struct FUN_006b3120_shell
{
    void* GetElementAt(int);
};
struct FUN_006f90a0_instance
{
    float f0;
    float f1;
    float f2;
    float f3;
    float f4;
    char _pad[8];
    unsigned char flag;
};
struct FUN_006f90a0_owner
{
    char _pad[0x1c];
    unsigned char flag;
};
struct FUN_006f90a0_params
{
    FUN_00bb7290_shell* renderer;
    FUN_006f90a0_owner* owner;
};
struct FUN_006f90a0_shell
{
    void UpdateInstances(FUN_006f90a0_params params);
};
unsigned int __cdecl FUN_0042f5a0(unsigned int, unsigned int);
unsigned int __cdecl FUN_00bb6030(void);
struct NiPoint3
{
    float x;
    float y;
    float z;
    NiPoint3();
    void NiPoint3_Unitize();
};
struct NiPoint2
{
    float x;
    float y;
    NiPoint2();
};
struct NiMemObject
{
    static void* operator new(unsigned int);
};
struct Obj44 : NiMemObject
{
    char _pad[44];
    Obj44(unsigned short);
    void FUN_00a72ca0(int);
    void FUN_00a730e0(int);
    void FUN_00a72bb0(int, void*, int, int);
    void FUN_00a726a0(int, int, int, int, unsigned short, int, int);
};
struct Obj88 : NiMemObject
{
    char _pad[88];
    Obj88(unsigned short, NiPoint3*, NiPoint3*, int, NiPoint2*, int, int, unsigned short, unsigned short*);
};
class PathingSolution
{
};
template <typename T> struct PathingRef
{
    void Reset(void*);
};
struct NavMeshPtr
{
    int v;
    NavMeshPtr& operator=(const NavMeshPtr&);
};
class NiGPUProgram;
struct NiGPUProgramOwner
{
    void SetProgram(NiGPUProgram*);
};
int __fastcall FUN_00559450(int*);
struct InParam
{
    int unk0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    NavMeshPtr m1c;
};
extern const float DAT_01012054;
float __cdecl FUN_004579e0(float);
void BuildNavMeshGeometry(void* param);
void FNV_Warning(const char* fmt, ...);
struct TreeInstance
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    unsigned int uiID;
    int iBlockIndex;
    unsigned char bFlag;
};
struct TreeInstanceArray
{
    int unk00;
    TreeInstance* pData;
    unsigned int uiSize;
    unsigned int uiCapacity;
    unsigned int GetSize();
    void SetCapacity(unsigned int);
    unsigned int AddInstance(TreeInstance* apInstance);
    TreeInstance* GetInstance(int);
};
struct TreeTypeArray
{
    unsigned int GetSize();
    void* GetType(unsigned int);
};
extern TreeTypeArray g_TreeTypes;
struct TreeBlock
{
    void* pType;
    int unk04;
    TreeInstanceArray kInstances;
    int iIndex;
    unsigned char bFull;
    TreeBlock();
};
struct TreeBlockArray
{
    unsigned int Add(TreeBlock*& arpBlock);
    unsigned int GetSize();
};
struct TreeBlockMap
{
    bool GetAt(unsigned int auiKey, TreeBlock*& arpVal);
    void SetAt(unsigned int auiKey, TreeBlock* apVal);
};
struct TreeInstanceMap
{
    void SetAt(unsigned int auiKey, TreeInstance* apVal);
};
struct TreeLODManager
{
    int unk00;
    TreeBlockArray kBlocks;
    int unk08;
    int unk0C;
    int unk10;
    TreeInstanceMap kInstanceMap;
    int unk18;
    int unk1C;
    int unk20;
    TreeBlockMap kBlockMap;
    void AddTreeInstance(unsigned int auiType, TreeInstance* apInstance);
};
struct NiAVObjectS;
template <class T> struct NiPtrS
{
    T* m_pObject;
    operator T*() const;
    NiPtrS& operator=(T* p);
};
struct NiNodeS
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void InsertChild(NiAVObjectS* apChild);
};
struct RootHolderS
{
    NiNodeS* GetRootNode();
};
struct SimpleArrS
{
    int unk0;
    int unk4;
    int unk8;
    void Clear(bool abFree);
};
struct TreeBlockEntryS
{
    int unk0;
    NiPtrS<NiAVObjectS> m_pController;
    SimpleArrS kInstances;
    ~TreeBlockEntryS();
};
struct EntryArrS
{
    TreeBlockEntryS*& GetAt(unsigned int auiIndex);
    unsigned int GetSize();
    void Clear(bool abFree);
};
struct TreeOwnerS
{
    int unk0;
    EntryArrS kEntries;
    NiPtrS<RootHolderS>& GetHolder();
    void ClearEntries();
};
struct TreeScopeGuard
{
    void* p;
    TreeScopeGuard(int line, int flags, const char* file, int size);
    ~TreeScopeGuard();
};
struct TreeRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    TreeRecord();
    ~TreeRecord();
};
struct TreeTemp
{
    int v;
    TreeTemp(int v);
};
struct TreeHost
{
    void ReadBytes(void* buf, unsigned int n);
};
void ReadTreeRecords(TreeHost* host);
struct C6F9060Member
{
    int unk00;

    C6F9060Member(int value);
};
struct FUN_006f9060
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    C6F9060Member m_kMember;

    FUN_006f9060();
};
struct Callee
{
    void FUN_0045cec0();
};
struct FUN_006f9080_owner : BGSDistantTreeBlockLoadTask
{
    char unk1b[0x1c];
    Callee callee;

    void FUN_006f9080();
};
void Callee::FUN_0045cec0()
{}
struct Fake076;
int __cdecl FormatTreeLodDtlPath(char* a1, Fake076* a2, int a3, short a4, short a5);
struct QBase
{
    QBase(int aPriority);
    virtual ~QBase();
    void SetTaskName(const char* apName);
    void SetTaskFlag(int aValue);

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
};
struct BGSDistantTreeBlock;
struct FUN_006f9360 : QBase
{
    BGSDistantTreeBlock* pBlock;
    bool m_bValueAtOffset34;
    int m_iGridPositionX;
    int m_iGridCoordinateY;
    int iLODLevel;
    bool m_bHeaderParsed;
    bool bFadeQueuedCur;

    FUN_006f9360(BGSDistantTreeBlock* apBlock, Fake076* apWorld, int aiCellX, int aiCellY, int aiLODLevel,
                 int aiUnused);
    virtual ~FUN_006f9360();
};
class C6F94A0Base
{
  public:
    virtual ~C6F94A0Base();
};
class FUN_006f94a0 : public C6F94A0Base
{
  public:
    virtual ~FUN_006f94a0();
};
class B6F9570File
{
  public:
    virtual ~B6F9570File();
};
class B6F9570FileFinder
{
  public:
    static B6F9570File* GetFile(const char* pcName, int eMode, unsigned int uiBufferSize, unsigned int uiFlags);
};
class B6F9570TreeBlock
{
  public:
    void ReadGroups(B6F9570File* pkFile);
    void ProcessAllTrees();
};
class B6F9570TreeLoader
{
  public:
    const char* GetFilename();
    void LoadTreeFile();

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
    B6F9570TreeBlock* m_pkTreeBlock;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    bool m_bCancelled;
    bool m_bLoadComplete;
};
struct Lod77Foo1
{
    static void* operator new(unsigned int);
    Lod77Foo1();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};
struct Lod77Foo2
{
    static void* operator new(unsigned int);
    Lod77Foo2();
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
};
struct Lod77Elem
{
    void Step0();
    void Step1();
    void Step2();
    void Step3();
    void Step4();
};
struct Lod77Container
{
    void Add(void* p);
    Lod77Elem* Get(int i);
    void* Get0();
};
struct LodFile
{
    virtual ~LodFile();
};
struct Lod77Mgr
{
    void Load(char* path, Lod77Container* c, int a, int b);
};
extern Lod77Container DAT_011d85bc;
extern Lod77Container DAT_011d85c4;
extern Lod77Container DAT_011d85e0;
extern Lod77Mgr* DAT_011dea10;
int __cdecl FUN_00ec8a19(const char* a, const char* b, int c);
void* __cdecl FUN_00afdf00(char* path, int mode, unsigned int size);
void __cdecl FUN_005b5e40(const char* msg);
void __cdecl LoadTreeLodResources(Fake076* self);
struct NiPoint3Ex
{
    float x, y, z;
    NiPoint3Ex(float, float, float);
    NiPoint3Ex operator-(const NiPoint3Ex&) const;
    NiPoint3Ex operator+(const NiPoint3Ex&) const;
    NiPoint3Ex FUN_0053d280(float) const;
    float Length() const;
};
struct FUN_006240d0
{
    float x, y, z, radius;
    FUN_006240d0();
    void NiBound_SetCenterAndRadius(const NiPoint3Ex&, float);
    float FUN_0084d030();
};
struct TreeGeometry
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual FUN_006240d0* GetBound();
};
struct TreeGeometryPtr
{
    TreeGeometry* object;
    TreeGeometry* FUN_00559450();
};
struct TreePositions
{
    unsigned int FUN_0044ddc0();
    NiPoint3Ex* GetElementAt(unsigned int);
};
struct BoundTreeBlock
{
    int unk00;
    TreeGeometryPtr geometry;
    TreePositions instances;
};
float __cdecl FUN_0040ebd0(float, float);
float __cdecl FUN_00404010(float, float);
struct TreeBoundsOwner
{
    FUN_006240d0 ComputeTreeBounds(BoundTreeBlock* block);
};
struct UpdateDataX
{
    float time;
    bool a, b;
    int unk08;
    UpdateDataX(float, bool, bool);
};
struct BoundsX
{
    float x, y, z, r;
};
struct NodeX : NiMemObject
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
    virtual void Attach(NodeX*, bool);
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void SetObjectBound(BoundsX);
    void SetSize(unsigned int);
    void AttachProperty(void*);
    void Finish();
    void Update(UpdateDataX&);
};
struct NewNodeX : NodeX
{
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    NewNodeX(void*);
};
struct PropertyX : NiMemObject
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    PropertyX();
};
struct TypeX
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    NiPtrS<void> name;
};
struct EntryX
{
    TypeX* type;
    NiPtrS<NodeX> node;
    SimpleArrS instances;
};
struct ArrayX
{
    EntryX*& GetAt(unsigned int);
    unsigned int GetSize();
    int unk00, unk04, unk08, unk0c;
};
struct HolderX
{
    NodeX* GetRootNode();
    NodeX* GetMenuRoot();
};
struct OwnerX
{
    int unk00;
    ArrayX entries;
    int unk14, unk18, unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40, unk44;
    bool loaded, built;
    NiPtrS<HolderX>& GetHolder();
    void Configure(PropertyX*, EntryX*);
    BoundsX GetBound(EntryX*);
    void Refresh();
    void FUN_006f8c40();
};
void __cdecl SetupNode(NodeX*, int, int);

struct S_00bb6050
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
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;

    int __thiscall FUN_00bb6050(int arg0, int arg1);
};

// @fnv 0x00bb6050
int __thiscall S_00bb6050::FUN_00bb6050(int arg0, int arg1)
{
    return this->unk80;
}
