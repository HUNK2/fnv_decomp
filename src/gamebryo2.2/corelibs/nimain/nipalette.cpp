
// src/gamebryo2.2/corelibs/nimain/nipalette.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nipalette.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_011f5c08;

// @fnv 0x00a8b070
void* __cdecl FUN_00a8b070()
{
    return &g_011f5c08;
}

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
struct FUN_00a8b010_Node
{
    char _pad[0x1c];
    FUN_00a8b010_Node* _prev;
    FUN_00a8b010_Node* _next;
    void Unlink();
};
extern FUN_00a8b010_Node* DAT_011f5c00;
extern FUN_00a8b010_Node* DAT_011f5c04;
extern int DAT_011f5c80;
// Under a critical section, removes this node from the doubly linked list, updating the head, tail and neighbouring links.
// @fnv 0x00a8b010
void FUN_00a8b010_Node::Unlink()
{
    EnterCriticalSection(&DAT_011f5c80);
    if (DAT_011f5c00 == this)
        DAT_011f5c00 = this->_next;
    if (DAT_011f5c04 == this)
        DAT_011f5c04 = this->_prev;
    if (this->_prev)
        this->_prev->_next = this->_next;
    if (this->_next)
        this->_next->_prev = this->_prev;
    LeaveCriticalSection(&DAT_011f5c80);
}

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};
extern int DAT_0109f3fc;
void __fastcall _Call_a5d3a0(void*);
void __fastcall FUN_00a8afc0(void*);
struct MyObj
{
    void* v0;
    int f04;
    unsigned char f08;
    char pad09[3];
    void* f0C;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
};
// @fnv 0x00a8b220
void* FUN_00a8b220()
{
    MyObj* p = (MyObj*)BSFadeNode::operator new(0x24);
    if (p)
    {
        _Call_a5d3a0(p);
        p->v0 = (void*)&DAT_0109f3fc;
        p->f08 = 0;
        p->f0C = 0;
        p->f14 = 0;
        p->f10 = 1;
        p->f18 = 0;
        FUN_00a8afc0(p);
        return p;
    }
    return 0;
}

struct RendererData
{
    virtual ~RendererData();
};
struct NiRefObject
{
    ~NiRefObject();
};
struct MM
{
    void _DeallocateAlias(void*);
};
extern MM g_memoryManager;
struct S_00a8b010
{
    void Unlink();
};
extern int DAT_0109f3fc;
void _delete(void*, unsigned int);
struct NiPalette
{
    void* vtable;
    char pad[16];
    void* m_pColorEntries;
    RendererData* m_pTextureRendererData;
    void* DestroyPalette(unsigned int);
};
// @fnv 0x00a8b270
void* NiPalette::DestroyPalette(unsigned int auiFlags)
{
    *(void**)this = (void*)&DAT_0109f3fc;
    g_memoryManager._DeallocateAlias(m_pColorEntries);
    delete m_pTextureRendererData;
    ((S_00a8b010*)this)->Unlink();
    ((NiRefObject*)this)->~NiRefObject();
    if (auiFlags & 1)
        _delete(this, 0x24);
    return this;
}

template <class T> struct NiTMallocInterface
{
};
template <class T, class A> struct NiTPrimitiveArray
{
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
void __stdcall AppendCameraPathEntries(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >*);
char* __cdecl _FUN_00a7d330(void*);
// @fnv 0x00a8b460
void __stdcall FUN_00a8b460(NiTPrimitiveArray<char*, NiTMallocInterface<char*> >* pkStrings)
{
    AppendCameraPathEntries(pkStrings);
    char* pszString = _FUN_00a7d330(g_011f5c08);
    unsigned int uiSize = *(unsigned short*)((char*)pkStrings + 10);
    unsigned int uiCapacity = *(unsigned short*)((char*)pkStrings + 8);
    if (uiSize >= uiCapacity)
    {
        unsigned int uiGrow = *(unsigned short*)((char*)pkStrings + 14);
        pkStrings->SetSize(uiGrow + uiSize);
    }
    pkStrings->SetAt(uiSize, pszString);
}

struct FUN_00a8af40_cls
{
    char unk00[8];
    unsigned char f08;
    char unk09[3];
    unsigned int f0C;
    char unk10[4];
    unsigned char* f14;

    char Probe(void* p);
    unsigned char Equals(FUN_00a8af40_cls* o);
};

// @fnv 0x00a8af40
unsigned char FUN_00a8af40_cls::Equals(FUN_00a8af40_cls* apOther)
{
    if (this->Probe(apOther) == 0)
    {
        return 0;
    }
    if (this->f08 != apOther->f08)
    {
        return 0;
    }
    if (this->f0C != apOther->f0C)
    {
        return 0;
    }
    unsigned int uiByteCount = this->f0C;
    uiByteCount += uiByteCount;
    uiByteCount += uiByteCount;
    unsigned int n = uiByteCount != 0;
    unsigned char* pOtherData = apOther->f14;
    unsigned char* pThisData = this->f14;
    while (n >= 4)
    {
        if (*(unsigned int*)pThisData != *(unsigned int*)pOtherData)
        {
            return 0;
        }
        n -= 4;
        pOtherData += 4;
        pThisData += 4;
    }
    if (n != 0)
    {
        if (pOtherData[0] != pThisData[0])
            return 0;
        if (n > 1)
        {
            if (pOtherData[1] != pThisData[1])
                return 0;
            if (n > 2)
            {
                if (pOtherData[2] != pThisData[2])
                    return 0;
            }
        }
    }
    return 1;
}

// FUN_00a8b110: thiscall, 3 stack args (ret 0xc). Stores the byte and
// dword args, allocates a 4-byte element array of count arg2 through the
// global allocator, copies arg3 into it, then notifies the global listener.

struct A8b110Allocator
{
    void* FUN_00aa3e40(unsigned int size);  // allocates size bytes, callee pops
};
extern A8b110Allocator DAT_011f6238;

struct A8b110Elem
{
    static void* operator new[](unsigned int bytes)
    {
        return DAT_011f6238.FUN_00aa3e40(bytes);
    }
    int m_uiFilterValue;
};

struct A8b110Listener
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
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void v0F();
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
    virtual void v1A();
    virtual void v1B();
    virtual void v1C();
    virtual void v1D();
    virtual void v1E();
    virtual void v1F();
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
    virtual void v2A();
    virtual void v2B();
    virtual void v2C();
    virtual void v2D();
    virtual void v2E();
    virtual void v2F();
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
    virtual void v3A();
    virtual void v3B();
    virtual void v3C();
    virtual void v3D();
    virtual void v3E();
    virtual void v3F();
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
    virtual void v4A();
    virtual void v4B();
    virtual void v4C();
    virtual void v4D();
    virtual void v4E();
    virtual void v4F();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(void* p);
};
extern A8b110Listener* DAT_011f4748;
void __cdecl FUN_00ec44d0(void* dst, void* src, unsigned int size);

struct A8b110Owner
{
    void* vtable;
    int unk04;
    unsigned char m_08;
    unsigned int m_0C;
    int m_10;
    A8b110Elem* m_14;
    int m_18;

    void* FUN_00a8b110(unsigned char a1, unsigned int a2, void* a3);
};

// Initializes the owner: stores the byte and count, allocates an element array, copies count*4 bytes from a3, and notifies DAT_011f4748.
// @fnv 0x00a8b110
void* A8b110Owner::FUN_00a8b110(unsigned char a1, unsigned int a2, void* pSrc)
{
    _Call_a5d3a0(this);
    m_08 = a1;
    m_0C = a2;
    vtable = (void*)&DAT_0109f3fc;
    m_10 = 1;
    m_14 = new A8b110Elem[a2];
    FUN_00ec44d0(m_14, pSrc, m_0C * 4);
    m_18 = 0;
    if (DAT_011f4748)
    {
        DAT_011f4748->v54(this);
    }
    FUN_00a8afc0(this);
    return this;
}

namespace fnv_00a8b2c0 {
struct BinaryReader
{
    void* unk00;
    unsigned int bytesRead;
    unsigned int(__cdecl* read)(BinaryReader*, void*, unsigned int, unsigned int*, unsigned int);
    void readBlock(void* output, unsigned int bytes, unsigned int unitValue)
    {
        unsigned int unit = unitValue;
        bytesRead += read(this, output, bytes, &unit, 1);
    }
};
struct DataSource
{
    BinaryReader* reader() const
    {
        return *reinterpret_cast<BinaryReader* const*>(reinterpret_cast<const char*>(this) + 0x24c);
    }
};
void __stdcall ReadGroup(DataSource*);
struct MMExtra
{
    void* _Allocate(unsigned int);
};
struct ReadState
{
    unsigned int elementCount;
};
struct MemoryBlock
{
    unsigned int value;
    MemoryBlock()
    {}
    static void* operator new[](unsigned int size)
    {
        return reinterpret_cast<MMExtra&>(g_memoryManager)._Allocate(size);
    }
};
struct Observer
{
    void** vtable;
};
extern Observer* DAT_011f4748;
struct DataArray
{
    unsigned int unk00;
    unsigned int unk04;
    bool enabled;
    unsigned int count;
    unsigned int unk10;
    MemoryBlock* values;
    void ReadFromSource(DataSource* source);
};
// Reads an enabled flag and element count from the source's reader, reallocates values if the count changed, reads the values, then notifies the observer.
// @fnv 0x00a8b2c0
void DataArray::ReadFromSource(DataSource* source)
{
    ReadGroup(source);
    ReadState readState;

    unsigned char enabledByte;
    BinaryReader* reader = source->reader();
    reader->readBlock(&enabledByte, 1, 1);
    enabled = enabledByte != 0;

    reader = source->reader();
    reader->readBlock(&readState.elementCount, 4, 4);
    if (readState.elementCount != count)
    {
        g_memoryManager._DeallocateAlias(values);
        count = readState.elementCount;
        values = new MemoryBlock[readState.elementCount];
    }

    reader = source->reader();
    reader->readBlock(values, count * sizeof(MemoryBlock), 1);
    Observer* observer = DAT_011f4748;
    if (observer)
    {
        typedef void(__thiscall * OnRead)(Observer*, DataArray*);
        (reinterpret_cast<OnRead>(observer->vtable[0x150 / 4]))(observer, this);
    }
}
}  // namespace fnv_00a8b2c0

// NiObject-derived data SaveBinary: base data, a flag byte, the element count, then the raw element bytes.

class A8B3C0BinaryStream
{
  public:
    void* m_ppVirtualMethodTable;
    unsigned int m_uiStreamFlags;
    unsigned int(__cdecl* m_pfnRead)(A8B3C0BinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int(__cdecl* m_pfnWrite)(A8B3C0BinaryStream*, const void*, unsigned int, unsigned int*, unsigned int);

    unsigned int BinaryWrite(const void* p, unsigned int n, unsigned int* sizes, unsigned int count)
    {
        unsigned int written = m_pfnWrite(this, p, n, sizes, count);
        m_uiStreamFlags += written;
        return written;
    }
    unsigned int Write(const void* p, unsigned int n, unsigned int uiComponentSize)
    {
        unsigned int size = uiComponentSize;
        return BinaryWrite(p, n, &size, 1);
    }
};

class A8B3C0Stream
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    int unk034;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
    int unk0B0;
    int unk0B4;
    int unk0B8;
    int unk0BC;
    int unk0C0;
    int unk0C4;
    int unk0C8;
    int unk0CC;
    int unk0D0;
    int unk0D4;
    int unk0D8;
    int unk0DC;
    int unk0E0;
    int unk0E4;
    int unk0E8;
    int unk0EC;
    int unk0F0;
    int unk0F4;
    int unk0F8;
    int unk0FC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    A8B3C0BinaryStream* m_pBackingStream;
};

template <class T>
inline void A8B3C0BinaryStreamSave(A8B3C0BinaryStream& kOstr, const T* pValue, unsigned int uiNumEls = 1)
{
    unsigned int uiSize = sizeof(T);
    kOstr.BinaryWrite(pValue, uiNumEls * uiSize, &uiSize, 1);
}

template <class T> inline void A8B3C0SaveBinary(A8B3C0Stream& kStream, const T& value)
{
    A8B3C0BinaryStreamSave(*kStream.m_pBackingStream, &value);
}

template <class T> inline void A8B3C0SaveBinary(A8B3C0Stream& kStream, const T* pValues, unsigned int ItemUpdateArray)
{
    A8B3C0BinaryStreamSave(*kStream.m_pBackingStream, pValues, ItemUpdateArray);
}

class A8B3C0Base
{
  public:
    void* m_pVtbl;
    int unk04;
    void SaveBinary(A8B3C0Stream& kStream);
};

class A8B3C0Data : public A8B3C0Base
{
  public:
    bool m_bFlag;
    unsigned int m_uiCount;
    int unk10;
    unsigned char* m_pCompressedData;

    void FUN_00a8b3c0(A8B3C0Stream& kStream);
};

// @fnv 0x00a8b3c0
void A8B3C0Data::FUN_00a8b3c0(A8B3C0Stream& kStream)
{
    A8B3C0Base::SaveBinary(kStream);
    A8B3C0SaveBinary<unsigned char>(kStream, m_bFlag);
    A8B3C0SaveBinary(kStream, m_uiCount);
    A8B3C0SaveBinary(kStream, m_pCompressedData, m_uiCount * 4);
}

struct PaletteElement : A8b110Elem
{
    PaletteElement()
    {}
};
struct A8b080Owner : A8b110Owner
{
    void* FUN_00a8b080(const A8b080Owner& src);
};

// Copies m_08, m_0C and a deep copy of the m_14 element array from src, then calls FUN_00a8afc0.
// @fnv 0x00a8b080
void* A8b080Owner::FUN_00a8b080(const A8b080Owner& src)
{
    _Call_a5d3a0(this);
    this->vtable = &DAT_0109f3fc;
    this->m_08 = src.m_08;
    this->m_0C = src.m_0C;
    this->m_10 = 1;
    this->m_14 = new PaletteElement[this->m_0C];
    FUN_00ec44d0(this->m_14, src.m_14, src.m_0C * 4);
    this->m_18 = 0;
    if (DAT_011f4748)
        DAT_011f4748->v54(this);
    FUN_00a8afc0(this);
    return this;
}

#include <string.h>
struct MMAllocInterface
{
    void* FUN_00aa3e40(unsigned int);
};
struct ArrayElement
{
    unsigned int value;
    static void* operator new[](unsigned int bytes)
    {
        return ((MMAllocInterface*)&g_memoryManager)->FUN_00aa3e40(bytes);
    }
};
// Copies the f08 scalar and the f14/f0C integer array from rhs, reallocating the array only when the element count differs.
// @fnv 0x00a8b190
MyObj* __fastcall FUN_00a8b190(MyObj* self, void*, const MyObj* rhs)
{
    if (self != rhs)
    {
        if (self->f18)
        {
            delete reinterpret_cast<RendererData*>(self->f18);
            self->f18 = 0;
        }
        self->f08 = rhs->f08;
        self->f10 = 1;
        if (self->f0C != rhs->f0C)
        {
            g_memoryManager._DeallocateAlias((void*)self->f14);
            unsigned int count = (unsigned int)rhs->f0C;
            self->f0C = (void*)count;
            self->f14 = (int)(new ArrayElement[count]);
        }
        memcpy((void*)self->f14, (void*)rhs->f14, (unsigned int)rhs->f0C * sizeof(int));
    }
    return self;
}

// Appends the given node to the end of a doubly-linked list guarded by a critical section, updating the head and tail pointers.
// @fnv 0x00a8afc0
void __fastcall FUN_00a8afc0(void* apNode)
{
    FUN_00a8b010_Node* node = static_cast<FUN_00a8b010_Node*>(apNode);
    EnterCriticalSection(&DAT_011f5c80);
    if (DAT_011f5c00 == 0)
        DAT_011f5c00 = node;
    if (DAT_011f5c04 != 0)
    {
        DAT_011f5c04->_next = node;
        node->_prev = DAT_011f5c04;
    }
    else
    {
        node->_prev = 0;
    }
    DAT_011f5c04 = node;
    node->_next = 0;
    LeaveCriticalSection(&DAT_011f5c80);
}
