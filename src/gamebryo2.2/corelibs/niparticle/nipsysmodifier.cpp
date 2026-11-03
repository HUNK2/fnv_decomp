// gamebryo2.2/corelibs/niparticle/nipsysmodifier.cpp: NiPSysModifier, MyIsEqual, ParticleModifierBinary, ParticleModifier (8 functions)

#include "nipsysmodifier_decls.h"

// @fnv 0x00C318B0
void NiPSysModifier::LoadBinary(NiStream& kStream)
{
    NiObject::LoadBinary(kStream);
    if (kStream.m_uiNifVersion < 0x14010001)
        kStream.ReadFixedString(m_kName);
    else
        kStream.ReadStringTableEntry(m_kName);

    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &m_uiUpdateOrder);
    kStream.ResetStreamState();
    unsigned char ucActive;
    NiBinaryStreamLoad(*kStream.m_pUnderlyingStream, &ucActive);
    m_bModifierActive = ucActive != 0;
}

// @fnv 0x00C31780
void NiPSysModifier::CopyMemberData(NiPSysModifier* pkDest, CloningProcess& kCloning)
{
    NiObject::CreateVertexBufferSet(pkDest, kCloning);
    char* pcName = m_kName.m_kHandle;
    if (pkDest->m_kName.m_kHandle != pcName)
    {
        if (pcName != EmptyFS.m_kHandle)
            InterlockedIncrement(reinterpret_cast<volatile long*>(pcName - 8));
        char* pcOldName = pkDest->m_kName.m_kHandle;
        if (pcOldName != EmptyFS.m_kHandle)
            InterlockedDecrement(reinterpret_cast<volatile long*>(pcOldName - 8));
        pkDest->m_kName.m_kHandle = pcName;
    }
    pkDest->m_uiUpdateOrder = m_uiUpdateOrder;
    pkDest->m_bModifierActive = m_bModifierActive;
}

// @fnv 0x00C317E0
void NiPSysModifier::ProcessClone(CloningProcess& kCloning)
{
    NiObject::ProcessClone(kCloning);
    NiObject* pkClone = 0;
    NiPSysCloneMapGetAt(kCloning.m_pCloneMap, this, pkClone);
    NiPSysModifier* pkDest = static_cast<NiPSysModifier*>(pkClone);
    NiPSysCloneMapGetAt(kCloning.m_pCloneMap, reinterpret_cast<NiObject*>(m_pkTarget), pkClone);
    pkDest->m_pkTarget = reinterpret_cast<NiParticleSystem*>(pkClone);
}

// @fnv 0x00C31650
void NiPSysModifier::LinkObject(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    kStream.GetLoadedObject();
}

struct NiPSysModifier_shell
{
    void NiPSysModifier_SetSystemPointer(NiParticleSystem* pkTarget);
};

// @fnv 0x00c31640
void NiPSysModifier_shell::NiPSysModifier_SetSystemPointer(NiParticleSystem* pkTarget)
{
    *reinterpret_cast<unsigned int*>(reinterpret_cast<unsigned int*>(this) + 4) =
        reinterpret_cast<unsigned int>(pkTarget);
}

extern const char* const g_01202528_arg1;

// @fnv 0x00c31710
const char* const* __cdecl NiPSysModifier_GetRTTI()
{
    return &g_01202528_arg1;
}

bool __stdcall IsSameAs(NiObject* pkObject);
struct MyIsEqual
{
    bool NiPSysModifier_IsEqual(NiObject* pkObject);
};
// Compares this object with a NiPSysModifier: checks IsSameAs, then fields at offsets 8, 0xc and 0x14 for equality.
// @fnv 0x00c31830
bool MyIsEqual::NiPSysModifier_IsEqual(NiObject* pkObject)
{
    NiPSysModifier* pkDest = (NiPSysModifier*)pkObject;
    if (IsSameAs(pkObject) && *(void**)((char*)this + 8) == *(void**)((char*)pkDest + 8) &&
        *(unsigned int*)((char*)this + 0xc) == *(unsigned int*)((char*)pkDest + 0xc) &&
        *(unsigned char*)((char*)this + 0x14) == *(unsigned char*)((char*)pkDest + 0x14))
        return true;
    return false;
}

struct NiObjectBase
{
    bool RegisterStreamables(NiStream&);
};
struct StreamHack
{
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8(void*);
};
struct X
{
    bool FUN_00c31670(NiStream&);
};
// Registers streamables via NiObjectBase::RegisterStreamables and, on success, calls vf8 on the stream with this+8.
// @fnv 0x00c31670
bool X::FUN_00c31670(NiStream& kStream)
{
    if (!((NiObjectBase*)this)->RegisterStreamables(kStream))
        return false;
    ((StreamHack*)&kStream)->vf8((char*)this + 8);
    return true;
}

struct OutputBinaryStream : NiBinaryStream
{
    __forceinline void WriteComponents(const void* data, unsigned int bytes, unsigned int* componentSizes,
                                       unsigned int componentCount)
    {
        unsigned int written = m_pfnWrite(this, data, bytes, componentSizes, componentCount);
        m_uiStreamFlags += written;
    }
};
struct OutputStream : NiStream
{
    OutputBinaryStream* m_pBackingStream;
    void WriteObjectLink(NiFixedString&);
};
struct LinkOutput
{
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0c();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1c();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2c();
    virtual void SaveObject(NiParticleSystem*);
};
struct BinaryObjectBase
{
    void* vtable;
    unsigned int referenceCount;
    void FUN_00a89af0(OutputStream&);
};
struct ParticleModifierBinary : BinaryObjectBase
{
    NiFixedString name;
    unsigned int order;
    NiParticleSystem* target;
    bool active;
    void NiPSysModifier_SaveBinary(OutputStream&);
};
template <class T> __forceinline void PrimitiveWrite(OutputBinaryStream* stream, const T& value)
{
    unsigned int size = sizeof(T);
    stream->WriteComponents(&value, sizeof(T), &size, 1);
}
__forceinline void BooleanWrite(OutputBinaryStream* stream, bool value)
{
    unsigned int size = 1;
    stream->WriteComponents(&value, 1, &size, 1);
}
// @fnv 0x00c31950
void ParticleModifierBinary::NiPSysModifier_SaveBinary(OutputStream& stream)
{
    FUN_00a89af0(stream);
    stream.WriteObjectLink(name);
    PrimitiveWrite(stream.m_pBackingStream, order);
    reinterpret_cast<LinkOutput*>(&stream)->SaveObject(target);
    BooleanWrite(stream.m_pBackingStream, active);
}

extern "C" char* DAT_0109b220;
extern "C" int DAT_010c09cc;
extern "C" void(__stdcall* DAT_00fdf1c0)(char*);
extern "C" void(__stdcall* DAT_00fdf1c4)(char*);
struct ParticleModifier
{
    void* vtable;
    unsigned int referenceCount;
    char* name;
    unsigned int order;
    void* target;
    bool active;
    void __thiscall FUN_00a5d3a0();
    ParticleModifier* __thiscall FUN_00c316a0(char* volatile* newName, unsigned int newOrder);
};
// @fnv 0x00c316a0
ParticleModifier* __thiscall ParticleModifier::FUN_00c316a0(char* volatile* newName, unsigned int newOrder)
{
    FUN_00a5d3a0();
    vtable = &DAT_010c09cc;
    name = DAT_0109b220;
    order = newOrder;
    target = 0;
    active = true;
    char* pNewName = *newName;
    if (name != pNewName)
    {
        if (pNewName != DAT_0109b220)
            DAT_00fdf1c0(pNewName - 8);
        if (name != DAT_0109b220)
            DAT_00fdf1c4(name - 8);
        name = pNewName;
    }
    return this;
}

struct StrArr
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char*& pElement);
    __forceinline void Add(char* pElement)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pElement);
    }
};
void __stdcall AppendCameraPathEntries(StrArr* apViewerStrings);
char* __cdecl FUN_00a7d330(const char* pcText);
char* __cdecl FUN_00a7d5e0(const char* pcPrefix, const char* pcValue);
char* __cdecl FUN_00a7d510(const char* pcPrefix, unsigned int uiValue);
char* __cdecl FUN_00a7d370(const char* pcPrefix, bool bValue);
extern const char g_011d4e34_arg1[];

struct FUN_00c319e0_cls : ParticleModifierBinary
{
    void NiPSysModifier_GetViewerStrings(StrArr* apViewerStrings);
};

// Appends the modifier's name, order and active flag as formatted strings to the given string array.
// @fnv 0x00c319e0
void FUN_00c319e0_cls::NiPSysModifier_GetViewerStrings(StrArr* apViewerStrings)
{
    AppendCameraPathEntries(apViewerStrings);
    apViewerStrings->Add(FUN_00a7d330(g_01202528_arg1));
    const char* pcName = name.m_kHandle;
    apViewerStrings->Add(FUN_00a7d5e0(g_011d4e34_arg1, pcName));
    apViewerStrings->Add(FUN_00a7d510("Order", order));
    apViewerStrings->Add(FUN_00a7d370("Active", active));
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void __cdecl FUN_00aa1460(void* pvMem, unsigned int uiSize);

namespace c318 {
extern char* DAT_0109b220;
}

class NiFixedStringC318
{
  public:
    ~NiFixedStringC318()
    {
        if (m_kHandle != c318::DAT_0109b220)
            InterlockedDecrement((long volatile*)(m_kHandle - 8));
    }
    char* m_kHandle;
};

class FUN_00a5d3d0
{
  public:
    virtual ~FUN_00a5d3d0();
    long m_uiRefCount;
};

class NamedC318 : public FUN_00a5d3d0
{
  public:
    virtual ~NamedC318()
    {}

    static void operator delete(void* pvMem, unsigned int uiSize)
    {
        FUN_00aa1460(pvMem, uiSize);
    }

    NiFixedStringC318 m_kName;
    int unk0C[3];

    NamedC318* FUN_00c31870(unsigned int uiFlags);
};

// Releases the NamedC318 object, calling its destructor and freeing memory when uiFlags has bit 0 set, then returns this.
// @fnv 0x00c31870
NamedC318* NamedC318::FUN_00c31870(unsigned int uiFlags)
{
    this->NamedC318::~NamedC318();
    if (uiFlags & 1)
        NamedC318::operator delete(this, sizeof(NamedC318));
    return this;
}
