
// src/gamebryo2.2/corelibs/nimain/niditherproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/niditherproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern void* g_011f5f48;

// @fnv 0x00a9a5e0
void* __cdecl FUN_00a9a5e0()
{
    return &g_011f5f48;
}

// @fnv 0x00dc9bc0
int __cdecl FUN_00dc9bc0()
{
    return 8;
}

struct NiProperty
{
    void FUN_00a9a640_ctor();
};

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

extern void* DAT_010a0f6c;

// @fnv 0x00a9a640
void* __cdecl FUN_00a9a640()
{
    void* p = BSFadeNode::operator new(0x1c);
    if (p)
    {
        NiProperty* property = static_cast<NiProperty*>(p);
        property->FUN_00a9a640_ctor();
        *(short*)((char*)p + 0x18) = 0;
        *(void**)((char*)p + 0) = &DAT_010a0f6c;
        return p;
    }
    return 0;
}

struct CloningProcess;
struct NiCullingProperty : NiProperty
{
    void* vtable;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    unsigned short unk18;
    void FUN_00a5d7a0(NiCullingProperty*, CloningProcess&);
    NiCullingProperty* FUN_00a9a5f0(CloningProcess&);
};
// Allocates and constructs a copy of this NiCullingProperty, runs FUN_00a5d7a0 on it, copies unk18, and returns the copy.
// @fnv 0x00a9a5f0
NiCullingProperty* NiCullingProperty::FUN_00a9a5f0(CloningProcess& process)
{
    NiCullingProperty* copy = (NiCullingProperty*)BSFadeNode::operator new(0x1c);
    if (copy)
    {
        copy->FUN_00a9a640_ctor();
        copy->vtable = &DAT_010a0f6c;
        copy->unk18 = 0;
    }
    else
    {
        copy = 0;
    }
    FUN_00a5d7a0(copy, process);
    copy->unk18 = unk18;
    return copy;
}

char* __cdecl FUN_00a7d330(char const*);
char* __cdecl FUN_00a7d370(char const*, bool);
template <class T> struct NiTMallocInterface
{
};
template <class T, class I> struct NiTPrimitiveArray
{
    void* unk00;
    int unk04;
    unsigned short capacity;
    unsigned short size;
    unsigned short unk0c;
    unsigned short growth;
    void SetSize(unsigned int);
    void SetAt(unsigned int, T&);
};
struct StrArr : NiTPrimitiveArray<char*, NiTMallocInterface<char*> >
{
};
struct FUN_00a62a40_this
{
    void AppendString(StrArr*);
};
struct Owner : FUN_00a62a40_this
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned char m_bDither;
    void AppendDitherSettings(StrArr*);
};
union Temporary
{
    char* text;
    bool flag;
};
// Appends the g_011f5f48 string and a formatted "m_bDither" flag value to the array, growing it as needed.
// @fnv 0x00a9a670
void Owner::AppendDitherSettings(StrArr* array)
{
    AppendString(array);
    Temporary value;
    value.text = FUN_00a7d330((char const*)g_011f5f48);
    unsigned int index = array->size;
    if (index >= array->capacity)
        array->SetSize(index + array->growth);
    array->SetAt(index, value.text);
    value.flag = (m_bDither & 1) != 0;
    value.text = FUN_00a7d370("m_bDither", value.flag);
    index = array->size;
    if (index >= array->capacity)
        array->SetSize(index + array->growth);
    array->SetAt(index, value.text);
}
