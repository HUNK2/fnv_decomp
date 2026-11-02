// Private PC declarations for the covered NiDynamicEffect revision member.
// NiMemObject, NiRefObject, NiObject, NiFixedString and NiObjectNET retain the
// corresponding supplied canonical class declarations and data layouts.
// NiRefObject inline bodies below are byte-identical supplied dependencies.
// PC-only NiAVObject/DList/transform layouts: JIP-LN-NVSE internal/netimmerse.h
// and internal/Ni_types.h. IncRevisionID name/address: JohnnyGuitar NiDynamicEffect.cpp.
#ifndef FNV_NITARRAY_PC_EFFECT_H
#define FNV_NITARRAY_PC_EFFECT_H

#include <stddef.h>
#define FNV_NITARRAY_LAYOUT_CHECK(name, expression) typedef char name[(expression) ? 1 : -1]
#ifndef FNV_FORCEINLINE
#define FNV_FORCEINLINE __forceinline
#endif
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* value);
class NiMemObject
{
  public:
};
class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;  // +0x4
    virtual ~NiRefObject();
    virtual void DeleteThis();
    FNV_FORCEINLINE void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    FNV_FORCEINLINE void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};
class NiObject : public NiRefObject
{
  public:
};
class NiFixedString
{
  public:
    char* m_kHandle;  // +0x0
};
class NiTimeController;
class NiExtraData;
class NiObjectNET : public NiObject
{
  public:
    NiFixedString m_kName;                       // +0x8
    NiPointer<NiTimeController> m_pControllers;  // +0xC
    NiExtraData** m_ppExtraData;                 // +0x10
    unsigned short m_usExtraDataCount;           // +0x14
    unsigned short m_usMaxSize;                  // +0x16
};
struct NiVector3
{
    float x, y, z;
};
struct NiMatrix33
{
    float cr[3][3];
};
struct NiTransform
{
    NiMatrix33 rotate;
    NiVector3 translate;
    float scale;
};
template <class Item> class DList
{
  public:
    struct Node
    {
        Node* next;
        Node* prev;
        Item* data;
    };

  private:
    Node* first;
    Node* last;
    unsigned long count;
};
class NiNode;
class bhkNiCollisionObject;
class NiBound;
class NiProperty;
class NiAVObject : public NiObjectNET
{
  public:
    NiNode* m_parent;
    bhkNiCollisionObject* m_collisionObject;
    NiBound* m_kWorldBound;
    DList<NiProperty> m_propertyList;
    unsigned long m_flags;
    NiTransform m_transformLocal;
    NiTransform m_transformWorld;
};
class NiDynamicEffect : public NiAVObject
{
  public:
    bool switchState;
    unsigned char effectType;
    long iIndex;
    unsigned long pushCount;
    unsigned long revID;
    DList<NiNode> shadowGenerator;
    DList<NiNode> unaffectedNodes;
    void IncRevisionID();
};
FNV_NITARRAY_LAYOUT_CHECK(nitarray_mem_size, sizeof(NiMemObject) == 1);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_ref_size, sizeof(NiRefObject) == 8);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_ref_count_offset, offsetof(NiRefObject, m_uiRefCount) == 4);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_object_size, sizeof(NiObject) == 8);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_fixed_string_size, sizeof(NiFixedString) == 4);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_fixed_string_offset, offsetof(NiFixedString, m_kHandle) == 0);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_objectnet_name_offset, offsetof(NiObjectNET, m_kName) == 8);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_objectnet_controllers_offset, offsetof(NiObjectNET, m_pControllers) == 0xc);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_objectnet_extra_offset, offsetof(NiObjectNET, m_ppExtraData) == 0x10);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_objectnet_extra_size_offset, offsetof(NiObjectNET, m_usExtraDataCount) == 0x14);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_objectnet_max_size_offset, offsetof(NiObjectNET, m_usMaxSize) == 0x16);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_objectnet_size, sizeof(NiObjectNET) == 0x18);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_transform_size, sizeof(NiTransform) == 0x34);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_avobject_size, sizeof(NiAVObject) == 0x9c);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_avobject_local_offset, offsetof(NiAVObject, m_transformLocal) == 0x34);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_avobject_world_offset, offsetof(NiAVObject, m_transformWorld) == 0x68);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_effect_size, sizeof(NiDynamicEffect) == 0xc4);
FNV_NITARRAY_LAYOUT_CHECK(nitarray_revision_offset, offsetof(NiDynamicEffect, revID) == 0xa8);
#endif
