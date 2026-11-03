
// src/gamebryo2.2/corelibs/nimain/nitarray_h_unit_o2_variant.cpp - flag-variant unit created 2026-10-17 by flag_variants.py for src/gamebryo2.2/corelibs/nimain/nitarray_h_unit.cpp functions whose prologue its flags cannot
// produce (frameless code in an /Od unit). Declarations copied from that unit's skeleton; move the functions to their real unit once identified.

// Header unit for gamebryo2.2/corelibs/nimain/nitarray.inl.
// No @fnv markers here; the covered template members are defined and
// marked in the header. This translation unit only forces the covered
// COMDATs to be emitted so their bytes can be compared.
#include "nitarray.inl"

struct StrArr
{
    unsigned char m_auiShapeKeys[8];
    unsigned short m_iElementCount;
    unsigned short m_uiItemCount;
    unsigned short m_pAuxiliaryObject;
    unsigned short m_growth;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct FUN_00cc6540_Class
{
    unsigned char m_auiShapeKeys[4];
    void* m_pUserData;

    void hkConstraintCinfo_GetViewerStrings(StrArr* array);
    void FUN_00cc6540(StrArr* array);
};

char* __cdecl FUN_00a7d550(char const* name, float value);

// @fnv 0x00cc6540
void FUN_00cc6540_Class::FUN_00cc6540(StrArr* array)
{
    hkConstraintCinfo_GetViewerStrings(array);

    unsigned char* data = static_cast<unsigned char*>(m_pUserData);
    if (data)
    {
        char* value = FUN_00a7d550("ConeMinAngle", *reinterpret_cast<float*>(data + 0xa0));
        unsigned int index = array->m_uiItemCount;
        unsigned int size = array->m_iElementCount;
        if (index >= size)
            array->SetSize(index + array->m_growth);
        array->SetAt(index, value);

        value = FUN_00a7d550("PlaneMinAngle", *reinterpret_cast<float*>(data + 0xb0));
        index = array->m_uiItemCount;
        size = array->m_iElementCount;
        if (index >= size)
            array->SetSize(index + array->m_growth);
        array->SetAt(index, value);

        value = FUN_00a7d550("PlaneMaxAngle", *reinterpret_cast<float*>(data + 0xb4));
        index = array->m_uiItemCount;
        size = array->m_iElementCount;
        if (index >= size)
            array->SetSize(index + array->m_growth);
        array->SetAt(index, value);

        value = FUN_00a7d550("TwistMinAngle", *reinterpret_cast<float*>(data + 0x88));
        index = array->m_uiItemCount;
        size = array->m_iElementCount;
        if (index >= size)
            array->SetSize(index + array->m_growth);
        array->SetAt(index, value);

        value = FUN_00a7d550("TwistMaxAngle", *reinterpret_cast<float*>(data + 0x8c));
        index = array->m_uiItemCount;
        size = array->m_iElementCount;
        if (index >= size)
            array->SetSize(index + array->m_growth);
        array->SetAt(index, value);
    }
}

namespace fnv_00cf46e0 {
struct StrArr
{
    unsigned char _pad[8];
    unsigned short m_008;
    unsigned short m_00a;
    unsigned short m_00c;
    unsigned short m_00e;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
};

struct GlobalObjectO2_00a7b610
{
    unsigned char _pad[0x2b4];
    unsigned int m_02b4;
};

extern __declspec(thread) GlobalObjectO2_00a7b610 g_tls_object;
extern GlobalObjectO2_00a7b610* g_01268740;

char* __cdecl _FUN_00a7d330(GlobalObjectO2_00a7b610* object);

struct TLSGuard
{
    unsigned int saved;

    TLSGuard() : saved(g_tls_object.m_02b4)
    {
        g_tls_object.m_02b4 = 0x10;
    }

    ~TLSGuard()
    {
        g_tls_object.m_02b4 = saved;
    }
};

// @fnv 0x00cf46e0
void __stdcall FUN_00cf46e0(StrArr* array)
{
    TLSGuard guard;
    char* value = _FUN_00a7d330(g_01268740);
    unsigned int index = array->m_00a;

    if (index >= array->m_008)
        array->SetSize(static_cast<unsigned int>(index + array->m_00e));

    array->SetAt(index, value);
}
}  // namespace fnv_00cf46e0

struct CharPtrArr
{
    int unk00;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short unk0C;
    unsigned short m_usGrowBy;

    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
    int FUN_00a5b4b0(char*& value);
};

// @fnv 0x00a5b4b0
int CharPtrArr::FUN_00a5b4b0(char*& value)
{
    if (value == 0)
        return -1;
    unsigned short i = 0;
    for (; i < m_usSize; i++)
    {
        if (m_pBase[i] == 0)
        {
            m_pBase[i] = value;
            unk0C++;
            return i;
        }
    }
    unsigned int count = m_usSize;
    if (count >= m_usMaxSize)
        SetSize(m_usGrowBy + count);
    SetAt(count, value);
    return count;
}

extern __declspec(thread) int g_iC8AD40AllocTag;

struct BC8AD40AllocTagScope
{
    int m_iSaved;

    BC8AD40AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iC8AD40AllocTag;
        g_iC8AD40AllocTag = aiAllocationTag;
    }
    ~BC8AD40AllocTagScope()
    {
        g_iC8AD40AllocTag = m_iSaved;
    }
};

class BC8AD40StringArray
{
  public:
    virtual ~BC8AD40StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern const char* g_pcC8AD40Name;

char* __cdecl FUN_00a7d330(const char* pcString);

class FUN_00c8ad40_cls
{
  public:
    void C8AD40BaseGetViewerStrings(BC8AD40StringArray* pkArray);
    void bhkBinaryAction_GetViewerStrings(BC8AD40StringArray* pkArray);
};

// @fnv 0x00c8ad40
void FUN_00c8ad40_cls::bhkBinaryAction_GetViewerStrings(BC8AD40StringArray* pkArray)
{
    BC8AD40AllocTagScope kScope(0x10);
    C8AD40BaseGetViewerStrings(pkArray);
    char* pcName = FUN_00a7d330(g_pcC8AD40Name);
    pkArray->Add(pcName);
}

namespace fnv_00cc31c0 {
extern __declspec(thread) int g_iCC31C0MemContext;

class CC31C0MemContext
{
  public:
    CC31C0MemContext(int aiMemoryContext)
    {
        m_iPrevious = g_iCC31C0MemContext;
        g_iCC31C0MemContext = aiMemoryContext;
    }
    ~CC31C0MemContext()
    {
        g_iCC31C0MemContext = m_iPrevious;
    }

    int m_iPrevious;
};

extern const char* g_pcCC31C0ClassName;
extern "C" char* __cdecl FUN_00a7d330(const char* pcName);

class CC31C0StrArray
{
  public:
    void SetSize(unsigned int uiSize);
    void SetAt(unsigned int uiIndex, const char* const& pcValue);

    unsigned int Add(const char* const& pcValue)
    {
        unsigned int uiIndex = m_usSize;
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcValue);
        return uiIndex;
    }

    void* m_ppVirtualMethodTable;
    const char** m_ppcBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

class CC31C0Object
{
  public:
    void GetViewerStringsBase(CC31C0StrArray* pkStrings);
    void bhkSpringAction_GetViewerStrings(CC31C0StrArray* pkStrings);
};

// @fnv 0x00cc31c0
void CC31C0Object::bhkSpringAction_GetViewerStrings(CC31C0StrArray* pkStrings)
{
    CC31C0MemContext kContext(0x10);
    GetViewerStringsBase(pkStrings);
    pkStrings->Add(FUN_00a7d330(g_pcCC31C0ClassName));
}
}  // namespace fnv_00cc31c0

struct ViewerObject
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void* GetType();
};
const char* __cdecl TypeName(void*);
char* __cdecl MakeViewerString(const char*, const char*);
char* __cdecl FUN_00a7d4d0(const char*, int);
int __cdecl FormatViewer(char*, unsigned int, const char*, ...);
struct ViewerConstraint
{
    int unk00;
    ViewerObject* object;
    int priority;
    void* entityA;
    void* entityB;
    void hkConstraintCinfo_GetViewerStrings(BC8AD40StringArray* array);
};
// @fnv 0x00c8a560
void ViewerConstraint::hkConstraintCinfo_GetViewerStrings(BC8AD40StringArray* array)
{
    BC8AD40AllocTagScope scope(16);
    char* text;
    char buffer[32];
    if (object)
    {
        text = MakeViewerString("Type", TypeName(object->GetType()));
        array->Add(text);
    }
    FormatViewer(buffer, 32, "0x%8X", entityA);
    text = MakeViewerString("hkpEntityA", buffer);
    array->Add(text);
    FormatViewer(buffer, 32, "0x%8X", entityB);
    text = MakeViewerString("hkpEntityB", buffer);
    array->Add(text);
    text = FUN_00a7d4d0("ePriority", priority);
    array->Add(text);
}

// Appends this class name to the viewer strings after the base entries, under the Havok allocation tag.

extern __declspec(thread) int g_iCC4740AllocTag;

struct BCC4740AllocTagScope
{
    int m_iSaved;

    BCC4740AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCC4740AllocTag;
        g_iCC4740AllocTag = aiAllocationTag;
    }
    ~BCC4740AllocTagScope()
    {
        g_iCC4740AllocTag = m_iSaved;
    }
};

class BCC4740StringArray
{
  public:
    virtual ~BCC4740StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern const char* g_pcCC4740Name;

char* __cdecl FUN_00a7d330(const char* pcString);

class CC4740Base
{
  public:
    void GetViewerStrings(BCC4740StringArray* pkArray);
};

class CC4740Derived : public CC4740Base
{
  public:
    void bhkAngularDashpotAction_GetViewerStrings(BCC4740StringArray* pkArray);
};

// @fnv 0x00cc4740
void CC4740Derived::bhkAngularDashpotAction_GetViewerStrings(BCC4740StringArray* pkArray)
{
    BCC4740AllocTagScope kScope(0x10);
    CC4740Base::GetViewerStrings(pkArray);
    char* pcName = FUN_00a7d330(g_pcCC4740Name);
    pkArray->Add(pcName);
}

extern __declspec(thread) int g_iCC4740AllocTag;
struct CF4520AllocTagScope
{
    int saved;
    CF4520AllocTagScope(int tag)
    {
        saved = g_iCC4740AllocTag;
        g_iCC4740AllocTag = tag;
    }
    ~CF4520AllocTagScope()
    {
        g_iCC4740AllocTag = saved;
    }
};
extern const char* DAT_01268738;
char* __cdecl FUN_00a7d330(const char* name);
struct CF4520Array
{
    void* vtable;
    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void FUN_0096ad30(unsigned int size);
    void FUN_0096ae90(unsigned int index, char* const& item);
    unsigned int Add(char* const& item)
    {
        unsigned int index = m_usSize;
        if (index >= m_usMaxSize)
            FUN_0096ad30(index + m_usGrowBy);
        FUN_0096ae90(index, item);
        return index;
    }
};
// @fnv 0x00cf4520
void __stdcall FUN_00cf4520(CF4520Array* array)
{
    CF4520AllocTagScope tag(16);
    char* element = FUN_00a7d330(DAT_01268738);
    array->Add(element);
}

extern __declspec(thread) int g_iCCCFD0AllocTag;
struct BCCCFD0AllocTagScope
{
    int m_iSaved;

    BCCCFD0AllocTagScope(int aiAllocationTag)
    {
        m_iSaved = g_iCCCFD0AllocTag;
        g_iCCCFD0AllocTag = aiAllocationTag;
    }
    ~BCCCFD0AllocTagScope()
    {
        g_iCCCFD0AllocTag = m_iSaved;
    }
};

class BCCCFD0StringArray
{
  public:
    virtual ~BCCCFD0StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern const char* g_pcCCCFD0Name;

class CCCFD0Base
{
  public:
    void GetViewerStrings(BCCCFD0StringArray* pkStrings);
};

class CCCFD0Derived : public CCCFD0Base
{
  public:
    void bhkExtendedMeshShape_GetViewerStrings(BCCCFD0StringArray* pkStrings);
};

// @fnv 0x00cccfd0
void CCCFD0Derived::bhkExtendedMeshShape_GetViewerStrings(BCCCFD0StringArray* pkStrings)
{
    BCCCFD0AllocTagScope kScope(0x10);
    CCCFD0Base::GetViewerStrings(pkStrings);
    pkStrings->Add(FUN_00a7d330(g_pcCCCFD0Name));
}

extern "C" void _ReadWriteBarrier();
struct CAA010Inner
{
    virtual void OpA();
    virtual void OpB();
    virtual void OpC();
    virtual void OpD();
    virtual void OpE();
    virtual void OpF();
    virtual void OpG();
    virtual void OpH();
    virtual void* GetHandle();
};

struct CAA010Shell
{
    virtual void Activate(int flag);
    virtual void OpB();
    virtual void OpC();
    virtual void OpD();
    virtual void OpE();
    virtual void PassArray(struct CAA010Arr* array);
    void SetChildObject(CAA010Inner* inner);
};

struct CAA010Data
{
    int unk00;
    int unk04;
    int unk08;
    CAA010Inner* m_obj;
    int unk10;
    int unk14;
    int unk18;
    float m_f;
};

extern __declspec(thread) int g_caa010TlsTag;

struct CAA010TagScope
{
    int m_iSaved;
    CAA010TagScope(int aiAllocationTag)
    {
        m_iSaved = g_caa010TlsTag;
        g_caa010TlsTag = aiAllocationTag;
    }
    ~CAA010TagScope()
    {
        g_caa010TlsTag = m_iSaved;
    }
};

struct CAA010Arr
{
    int unk00;
    int unk04;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int size);
    void SetAt(unsigned int index, char*& value);
    unsigned int SetAtGrow(unsigned int index, char* const& value)
    {
        if (index >= m_usMaxSize)
            SetSize(index + m_usGrowBy);
        SetAt(index, (char*&)value);
        return index;
    }
};

CAA010Shell* __cdecl CreateSaver(void* p);

struct CAA010This
{
    int unk00;
    void* m_pUserData;
    void hkConstraintCinfo_GetViewerStrings(CAA010Arr* array);
    CAA010Inner* GetObj()
    {
        return m_pUserData ? ((CAA010Data*)m_pUserData)->m_obj : 0;
    }
    void FUN_00caa010(CAA010Arr* array);
};

// @fnv 0x00caa010
void CAA010This::FUN_00caa010(CAA010Arr* array)
{
    CAA010TagScope scope(16);
    hkConstraintCinfo_GetViewerStrings(array);
    array->SetAtGrow(array->m_usSize, FUN_00a7d550("Strength", m_pUserData ? ((CAA010Data*)m_pUserData)->m_f : 0.0f));
    CAA010Inner* inner = GetObj();
    _ReadWriteBarrier();
    if (inner)
    {
        CAA010Shell* shell = CreateSaver(inner->GetHandle());
        if (shell)
        {
            shell->SetChildObject(inner);
            shell->PassArray(array);
            shell->Activate(1);
            return;
        }
        return;
    }
}

extern const char* DAT_01268730;
// @fnv 0x00cf4300
void __stdcall FUN_00cf4300(CF4520Array* pkArray)

{

    CF4520AllocTagScope scope(16);

    char* pcElement = FUN_00a7d330(DAT_01268730);

    pkArray->Add(pcElement);
}
