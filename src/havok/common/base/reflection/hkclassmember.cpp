
// src/havok/common/base/reflection/hkclassmember.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/reflection/hkclassmember.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include "havok/hkClassMember.h"

struct hkCustomAttributes
{
    const hkVariant* getAttribute(const char* name) const;
};

struct hkClassMember_FUN_00d86960
{
    char _pad[0x14];
    const hkCustomAttributes* m_pCustomAttributes;
    const hkVariant* FUN_00d86960(const char* name) const;
};

// @fnv 0x00d86960
const hkVariant* hkClassMember_FUN_00d86960::FUN_00d86960(const char* name) const
{
    if (m_pCustomAttributes)
        return m_pCustomAttributes->getAttribute(name);
    return 0;
}

extern char DAT_011b6ab0;

// @fnv 0x00d868a0
char* __cdecl FUN_00d868a0(int index)
{
    return &DAT_011b6ab0 + index * 12;
}

int __cdecl FUN_00d86980();

// Stores v into p as a char, short or int depending on the size returned by FUN_00d86980.
// @fnv 0x00d86bc0
void __stdcall FUN_00d86bc0(int apTarget, int aiValue)
{
    switch (FUN_00d86980())
    {
    case 1:
        *(char*)apTarget = (char)aiValue;
        break;
    case 2:
        *(short*)apTarget = (short)aiValue;
        break;
    case 4:
        *(int*)apTarget = aiValue;
        break;
    default:
        break;
    }
}

// @fnv 0x00d868b0
static bool FUN_00d868b0(hkClassMember::Type aeType)
{
    return aeType >= 0 && (aeType < hkClassMember::TYPE_POINTER || aeType == hkClassMember::TYPE_VARIANT ||
                           aeType == hkClassMember::TYPE_ULONG || aeType == hkClassMember::TYPE_CSTRING ||
                           aeType == hkClassMember::TYPE_HALF || aeType == hkClassMember::TYPE_STRINGPTR);
}

void dummy(hkClassMember::Type x)
{
    FUN_00d868b0(x);
}

struct TestClass : public hkClassMember
{
    const hkClass* FUN_00d86910() const;
};

// @fnv 0x00d86910
const hkClass* TestClass::FUN_00d86910() const
{
    return this->m_class;
}

struct Struct_d86920
{
    int unk00;
    int unk04;
    int FUN_00d86920();
};

// @fnv 0x00d86920
int Struct_d86920::FUN_00d86920()
{
    return unk04;
}

class FUN_00d86930_StandIn
{
  public:
    void* unk00;
    void* unk04;
    hkClassEnum* unk08;

    hkClassEnum* FUN_00d86930();
};

// @fnv 0x00d86930
hkClassEnum* FUN_00d86930_StandIn::FUN_00d86930()
{
    return unk08;
}

struct FUN_00dba990_Obj
{
    int FUN_00dba990();
};

struct FUN_00d86bc0_Obj
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0C;
    void FUN_00d86bc0(int a, int b);
};

// @fnv 0x00dc1bf0
unsigned int __stdcall FUN_00dc1bf0(int aiArg, int pMember, int pSource, int aiUnused)
{
    FUN_00d86bc0_Obj* member = (FUN_00d86bc0_Obj*)pMember;
    unsigned int type = member->unk0C;

    switch (type)
    {
    case 0x18:
        if (member->unk08 != 0)
        {
            int result = ((FUN_00dba990_Obj*)pSource)->FUN_00dba990();
            member->FUN_00d86bc0(aiArg, result);
        }
        return 0;
    case 0x1f:
        if (member->unk08 != 0)
        {
            member->FUN_00d86bc0(aiArg, ((FUN_00dba990_Obj*)pSource)->FUN_00dba990());
        }
        return 0;
    }
    return 1;
}

struct NativeTypePropertyD86A
{
    int m_type;
    const char* m_name;
    short m_iElementCount;
    short m_usFlags;
};

class hkClassD86A;

class hkClassMemberD86A
{
  public:
    enum Type
    {
        TYPE_ENUM = 0x18,
        TYPE_STRUCT = 0x19,
        TYPE_FLAGS = 0x1f
    };
    enum Flags
    {
        ALIGN_8 = 0x80,
        ALIGN_16 = 0x100
    };

    const char* m_name;
    const hkClassD86A* m_class;
    const void* m_pClassEnum;
    unsigned char m_type;
    unsigned char m_eSubtype;
    short m_iArraySize;
    unsigned short m_flags;
    unsigned short m_offset;

    int GetAlignment() const;
};

class hkClassD86A
{
  public:
    int FUN_00d46f00() const;
    const hkClassMemberD86A& FUN_00d46f20(int i) const;
};

// Returns the memory alignment of this class member, derived from its type, struct member alignments, or explicit ALIGN_8/ALIGN_16 flags.
// @fnv 0x00d86a90
int hkClassMemberD86A::GetAlignment() const
{
    int type = m_type;
    if (type == TYPE_ENUM || type == TYPE_FLAGS)
        type = m_eSubtype;

    int align;
    if (type == TYPE_STRUCT)
    {
        int structAlign = 1;
        for (int i = 0; i < m_class->FUN_00d46f00(); i++)
        {
            if (m_class->FUN_00d46f20(i).GetAlignment() > structAlign)
                structAlign = m_class->FUN_00d46f20(i).GetAlignment();
        }
        align = structAlign;
    }
    else
    {
        align = ((const NativeTypePropertyD86A*)&DAT_011b6ab0)[type].m_usFlags;
    }

    if (m_flags & (ALIGN_8 | ALIGN_16))
    {
        int required = (bool)((m_flags >> 8) & 1) ? 16 : 8;
        if (required > align)
            align = required;
    }
    return align;
}

struct TypeDescription
{
    const char* name;
    const char* displayName;
    int size;
};
extern TypeDescription DAT_011b6ab4[];
extern const char str_010d3a74[];
struct TypeNameOutput
{
    void FUN_00d61c10(const char*);
};
extern void __cdecl FUN_00d61d00(TypeNameOutput*, const char*, const char*, const char*);
// Writes the selected type name to output, calling FUN_00d61d00 with that name and detail when detail is non-null.
// @fnv 0x00d868e0
static __declspec(noinline) void FUN_00d868e0(TypeNameOutput* output, const char* detail, int type)
{
    if (!detail)
        output->FUN_00d61c10(DAT_011b6ab4[type].name);
    else
        FUN_00d61d00(output, str_010d3a74, DAT_011b6ab4[type].name, detail);
}
void formatTypeName(TypeNameOutput* output, const char* detail, int type)
{
    FUN_00d868e0(output, detail, type);
}

class OwnerD869
{
  public:
    int FUN_00d86940() const;
    int unk00;
    int unk04;
    int unk08;
    short unk0c;
    short m_sValue;
};

// @fnv 0x00d86940
int OwnerD869::FUN_00d86940() const
{
    return m_sValue;
}

struct TypeProps_d869
{
    int m_type;
    const char* m_name;
    short m_iElementCount;
    short m_usFlags;
};

class hkClass_d869
{
  public:
    int GetObjectAlignment() const;
};

struct ClassMember_d869 : public hkClassMember
{
    int GetMemberOffset() const;
    const hkClass_d869& GetReferencedClass() const;
    int FUN_00d86980() const;
};

__declspec(noinline) int ClassMember_d869::GetMemberOffset() const
{
    return m_iArraySize;
}
__declspec(noinline) const hkClass_d869& ClassMember_d869::GetReferencedClass() const
{
    return *(const hkClass_d869*)m_class;
}

static inline const TypeProps_d869* typeProps_d869()
{
    return (const TypeProps_d869*)&DAT_011b6ab0;
}

// For handled types, multiplies the selected type-property value or referenced class alignment by the member count; otherwise returns -1.
// @fnv 0x00d86980
int ClassMember_d869::FUN_00d86980() const
{
    int size = -1;
    switch (m_type)
    {
    case TYPE_BOOL:
    case TYPE_CHAR:
    case TYPE_INT8:
    case TYPE_UINT8:
    case TYPE_INT16:
    case TYPE_UINT16:
    case TYPE_INT32:
    case TYPE_UINT32:
    case TYPE_INT64:
    case TYPE_UINT64:
    case TYPE_REAL:
    case TYPE_VECTOR4:
    case TYPE_QUATERNION:
    case TYPE_MATRIX3:
    case TYPE_ROTATION:
    case TYPE_QSTRANSFORM:
    case TYPE_MATRIX4:
    case TYPE_TRANSFORM:
    case TYPE_POINTER:
    case TYPE_FUNCTIONPOINTER:
    case TYPE_ARRAY:
    case TYPE_SIMPLEARRAY:
    case TYPE_HOMOGENEOUSARRAY:
    case TYPE_VARIANT:
    case TYPE_CSTRING:
    case TYPE_ULONG:
    case TYPE_HALF:
    case TYPE_STRINGPTR: {
        int nelem = GetMemberOffset() ? GetMemberOffset() : 1;
        size = nelem * typeProps_d869()[m_type].m_iElementCount;
    }
    break;
    case TYPE_ENUM:
    case TYPE_FLAGS: {
        int nelem = GetMemberOffset() ? GetMemberOffset() : 1;
        size = nelem * typeProps_d869()[m_eSubtype].m_iElementCount;
    }
    break;
    case TYPE_STRUCT: {
        int nelem = GetMemberOffset() ? GetMemberOffset() : 1;
        size = nelem * GetReferencedClass().GetObjectAlignment();
    }
    break;
    case TYPE_ZERO:
    case TYPE_INPLACEARRAY:
        break;
    }
    return size;
}
