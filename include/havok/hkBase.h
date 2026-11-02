// include/havok/hkBase.h - Havok 7.1 value types used by the generated class headers (gen_havok_headers.py, 2026-10-17).
#ifndef FNV_HAVOK_HKBASE_H
#define FNV_HAVOK_HKBASE_H
typedef float hkReal;
typedef signed char hkInt8;
typedef unsigned char hkUint8;
typedef short hkInt16;
typedef unsigned short hkUint16;
typedef int hkInt32;
typedef unsigned int hkUint32;
typedef __int64 hkInt64;
typedef unsigned __int64 hkUint64;
typedef unsigned long hkUlong;
typedef char hkBool;
typedef short hkHalf;
typedef char* hkStringPtr;
class hkClass;
class hkClassEnum;
#pragma pack(push, 1)
struct hkVector4
{
    hkReal x, y, z, w;
};  // 16 bytes (SIMD-aligned in the PC build)
struct hkQuaternion
{
    hkVector4 m_vec;
};  // 16
struct hkMatrix3
{
    hkVector4 m_kColumn0, m_kColumn1, m_kColumn2;
};  // 48
struct hkRotation : hkMatrix3
{
};  // 48
struct hkTransform
{
    hkRotation m_rotation;
    hkVector4 m_vTranslation;
};  // 64
struct hkQsTransform
{
    hkVector4 m_vTranslation;
    hkQuaternion m_rotation;
    hkVector4 m_vScale;
};  // 48
struct hkMatrix4
{
    hkVector4 m_kColumn0, m_kColumn1, m_kColumn2, m_kColumn3;
};  // 64
template <class T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};  // 12
template <class T> struct hkSimpleArray
{
    T* m_data;
    int m_iElementCount;
};  // 8
struct hkVariant
{
    void* m_object;
    const hkClass* m_class;
};  // 8
struct hkHomogeneousArray
{
    const hkClass* m_class;
    void* m_data;
    int m_iElementCount;
};  // 12
#pragma pack(pop)
class hkBaseObject
{
  public:
    virtual ~hkBaseObject();
};  // 4 (vtable)
#endif
