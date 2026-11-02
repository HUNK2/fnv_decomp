// include/havok/hkClassMember.h - generated from the Havok 7.1 reflection data in the PC exe (gen_havok_headers.py, 2026-10-17).
// Reflected members at their exact offsets; unreflected bytes are padding. Size 0x18.
#ifndef FNV_HAVOK_HKCLASSMEMBER_H
#define FNV_HAVOK_HKCLASSMEMBER_H

#include "hkBase.h"
class hkClass;
class hkClassEnum;
class hkCustomAttributes;
#pragma pack(push, 1)
class hkClassMember
{
  public:
    enum Type
    {
        TYPE_VOID = 0,
        TYPE_BOOL = 1,
        TYPE_CHAR = 2,
        TYPE_INT8 = 3,
        TYPE_UINT8 = 4,
        TYPE_INT16 = 5,
        TYPE_UINT16 = 6,
        TYPE_INT32 = 7,
        TYPE_UINT32 = 8,
        TYPE_INT64 = 9,
        TYPE_UINT64 = 10,
        TYPE_REAL = 11,
        TYPE_VECTOR4 = 12,
        TYPE_QUATERNION = 13,
        TYPE_MATRIX3 = 14,
        TYPE_ROTATION = 15,
        TYPE_QSTRANSFORM = 16,
        TYPE_MATRIX4 = 17,
        TYPE_TRANSFORM = 18,
        TYPE_ZERO = 19,
        TYPE_POINTER = 20,
        TYPE_FUNCTIONPOINTER = 21,
        TYPE_ARRAY = 22,
        TYPE_INPLACEARRAY = 23,
        TYPE_ENUM = 24,
        TYPE_STRUCT = 25,
        TYPE_SIMPLEARRAY = 26,
        TYPE_HOMOGENEOUSARRAY = 27,
        TYPE_VARIANT = 28,
        TYPE_CSTRING = 29,
        TYPE_ULONG = 30,
        TYPE_FLAGS = 31,
        TYPE_HALF = 32,
        TYPE_STRINGPTR = 33,
        TYPE_MAX = 34
    };
    enum FlagValues
    {
        FLAGS_NONE = 0,
        ALIGN_8 = 128,
        ALIGN_16 = 256,
        NOT_OWNED = 512,
        SERIALIZE_IGNORED = 1024
    };
    enum DeprecatedFlagValues
    {
        DEPRECATED_SIZE_8 = 8,
        DEPRECATED_ENUM_8 = 8,
        DEPRECATED_SIZE_16 = 16,
        DEPRECATED_ENUM_16 = 16,
        DEPRECATED_SIZE_32 = 32,
        DEPRECATED_ENUM_32 = 32
    };
    char* m_name;                             // +0x0
    hkClass* m_class;                         // +0x4
    hkClassEnum* m_pClassEnum;                // +0x8
    hkUint8 m_type;                           // +0xC (Type)
    hkUint8 m_eSubtype;                       // +0xD (Type)
    hkInt16 m_iArraySize;                     // +0xE
    hkUint16 m_flags;                         // +0x10 (FlagValues)
    hkUint16 m_offset;                        // +0x12
    hkCustomAttributes* m_pCustomAttributes;  // +0x14
};
#pragma pack(pop)
typedef char fnv_hk_size_hkClassMember[(sizeof(hkClassMember) == 0x18) ? 1 : -1];
#endif
