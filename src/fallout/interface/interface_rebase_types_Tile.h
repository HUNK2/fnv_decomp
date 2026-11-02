// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_INTERFACE_REBASE_FNV_INTERFACE_TABLINE_TILE_H
#define FNV_INTERFACE_REBASE_FNV_INTERFACE_TABLINE_TILE_H
#include "interface_rebase_layout_support.h"
#include "interface_rebase_layout_support.h"
class NiTAbstractPoolAllocator_unsigned_int_;
class NiTListBase_NiTPointerAllocator_unsigned_int__Tile___;
class NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator;
class NiTListItem_Tile___;
class NiTPointerAllocator_unsigned_int_;
class NiTPointerList_Tile___;
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___;
class Tile__Value;
class NiTAbstractPoolAllocator_unsigned_int_
{
  public:
};
FNV_STATIC_ASSERT(sizeof(NiTAbstractPoolAllocator_unsigned_int_) == 1);
class NiTPointerAllocator_unsigned_int_ : public NiTAbstractPoolAllocator_unsigned_int_
{
  public:
    // void* __cdecl NiTPointerAllocator<unsigned int>::*()
    // void __cdecl NiTPointerAllocator<unsigned int>::*(void*)
};
FNV_STATIC_ASSERT(sizeof(NiTPointerAllocator_unsigned_int_) == 1);
class NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator
    : public NiTPointerAllocator_unsigned_int_
{
  public:
    // base NiTPointerAllocator<unsigned int> at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator, m_uiCount) == 0);
class NiTListBase_NiTPointerAllocator_unsigned_int__Tile___
{
  public:
    NiTListItem_Tile___* m_pkHead;                                                           // +0x0, 4 bytes
    NiTListItem_Tile___* m_pkTail;                                                           // +0x4, 4 bytes
    NiTListBase_NiTPointerAllocator_unsigned_int__Tile_____AntiBloatAllocator m_kItemCount;  // +0x8, 4 bytes
    // unsigned int __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // bool __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*, void*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*, void*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(NiTListItem<Tile *>*)
    // void __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(NiTListItem<Tile *>*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*, NiTListItem<Tile *>*)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*, NiTListItem<Tile *>*)
    // NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>& __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(const NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>&)
    // void* __cdecl NiTListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile___) == 12);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile___, m_pkHead) == 0);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile___, m_pkTail) == 4);
FNV_STATIC_ASSERT(offsetof(NiTListBase_NiTPointerAllocator_unsigned_int__Tile___, m_kItemCount) == 8);
class NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___
    : public NiTListBase_NiTPointerAllocator_unsigned_int__Tile___
{
  public:
    // base NiTListBase<NiTPointerAllocator<unsigned int>,Tile *> at +0x0, size 12
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(Tile*&)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(Tile*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*, Tile*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*, Tile*&)
    // Tile*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // Tile*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // Tile*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*)
    // Tile*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*&)
    // Tile*& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*&)
    // Tile* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // Tile* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // Tile* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(Tile*&)
    // Tile* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(void*&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(Tile*&, void*)
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(int __cdecl (void*, void*)*)
    // NiTListItem<Tile *>* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*()
    // void __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(NiTListItem<Tile *>*)
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>
    // NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>& __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(const NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>&)
    // void* __cdecl NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *>::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___) == 12);
class NiTPointerList_Tile___ : public NiTPointerListBase_NiTPointerAllocator_unsigned_int__Tile___
{
  public:
    // base NiTPointerListBase<NiTPointerAllocator<unsigned int>,Tile *> at +0x0, size 12
    // NiTPointerList<Tile *>
    // void __cdecl NiTPointerList<Tile *>::*()
    // NiTPointerList<Tile *>& __cdecl NiTPointerList<Tile *>::*(const NiTPointerList<Tile *>&)
    // void* __cdecl NiTPointerList<Tile *>::*(unsigned int)
};
FNV_STATIC_ASSERT(sizeof(NiTPointerList_Tile___) == 12);
class Tile
{
  public:
    static Menu* FindMenuById(unsigned int);
    Menu* GetMenu() const;
    void SetString(int trait, const char* text, bool clearActions);
    void SetName(const char* name);
    void SetInt(int trait, int value);
    float GetFloat(int trait) const;
    Tile* GetNamedChild(const char* name) const;
    static int GetTraitID(const char* name);
    static void UpdateAll(bool force);

    void** m_ppVirtualMethodTable;                           // +0x0, 4 bytes
    NiTPointerList_Tile___ m_kChildTileList;   // +0x4, 12 bytes
    BSSimpleArray<Tile__Value*, 8> m_kValues;  // +0x10, 16 bytes
    BSStringT<char> StringProvider;            // +0x20, 8 bytes
    Tile* pParent;                             // +0x28, 4 bytes
    NiPointer<NiNode> m_pRenderedNodeEntry;                 // +0x2C, 4 bytes
    unsigned int uiFlags;                      // +0x30, 4 bytes
    bool m_bFlagAfterUiFlags;                  // +0x34, 1 bytes
    bool m_bSpeechChallengeFailure;            // +0x35, 1 bytes
    unsigned char layoutPadding36[2];
    // void __cdecl Tile::*()
    // void __cdecl Tile::*(int, float, float, float, Tile::TILE_FADE_CONTROL_TYPE)
    // void __cdecl Tile::*(int)
    // float __cdecl Tile::*(int)
    // bool __cdecl Tile::*(int)
    // bool __cdecl Tile::*(int)
    // Tile::TILE_FADE_CONTROL_TYPE __cdecl Tile::*(int)
    // void __cdecl Tile::*(NiAVObject*, float)
    // Tile::Value* __cdecl Tile::*(int, int)
    // int __cdecl Tile::*(const void*, const void*)
    // void __cdecl Tile::*(Tile::Value*, Tile::Value*)
    // void __cdecl Tile::*(Tile::Value*)
    // Tile
    // void __cdecl Tile::*()
    // void __cdecl Tile::*(int)
    // void __cdecl Tile::*(int)
    // void __cdecl Tile::*(int)
    // int __cdecl Tile::*()
    // int __cdecl Tile::*(int)
    // void __cdecl Tile::*(bool)
    // void __cdecl Tile::*(bool)
    // void __cdecl Tile::*(bool)
    // void __cdecl Tile::*(bool)
    // void __cdecl Tile::*(bool)
    // void __cdecl Tile::*()
    // void __cdecl Tile::*()
    // bool __cdecl Tile::*()
    // bool __cdecl Tile::*()
    // bool __cdecl Tile::*()
    // bool __cdecl Tile::*()
    // bool __cdecl Tile::*()
    // bool __cdecl Tile::*()
    // bool __cdecl Tile::*()
    // void __cdecl Tile::*()
    // void __cdecl Tile::*(float, float, float, float)
    // const char* __cdecl Tile::*()
    // SetName
    // void __cdecl Tile::*(Tile*, Tile*)
    // Tile* __cdecl Tile::*()
    // void __cdecl Tile::*(NiNode*)
    // NiNode* __cdecl Tile::*()
    // NiNode* __cdecl Tile::*()
    // void __cdecl Tile::*()
    // Tile::Value* __cdecl Tile::*(int)
    // Tile::Value* __cdecl Tile::*(int)
    // Tile::Value* __cdecl Tile::*(int)
    // float __cdecl Tile::*(int)
    // const char* __cdecl Tile::*(int)
    // bool __cdecl Tile::*(int)
    // void __cdecl Tile::*(int, float)
    // Set
    // bool __cdecl Tile::*()
    // float __cdecl Tile::*()
    // float __cdecl Tile::*()
    // float __cdecl Tile::*()
    // void __cdecl Tile::*(int)
    // void __cdecl Tile::*(bool, bool)
    // void __cdecl Tile::*(bool, bool)
    // void __cdecl Tile::*(int)
    // void __cdecl Tile::*(Tile::Value*)
    // Tile* __cdecl Tile::*(const char*)
    // Tile* __cdecl Tile::*(int, float, const char*)
    // Menu* __cdecl Tile::*()
    // Tile* __cdecl Tile::*()
    // Tile* __cdecl Tile::*(const char*)
    // Tile* __cdecl Tile::*(int)
    // Tile* __cdecl Tile::*(int, int&)
    // void __cdecl Tile::*()
    // bool __cdecl Tile::*()
    // bool __cdecl Tile::*()
    // void __cdecl Tile::*()
    // void __cdecl Tile::*(bool)
    // bool __cdecl Tile::*(bool)
    // void __cdecl Tile::*(int)
    // bool __cdecl Tile::*()
    // void __cdecl Tile::*()
    // RecursiveColorUpdate
    // void __cdecl Tile::*()
    // void __cdecl Tile::*(const char*, int)
    // void __cdecl Tile::*()
    // int __cdecl Tile::*(const char*, int)
    // void __cdecl Tile::*()
    // int __cdecl Tile::*(const char*)
    // const char* __cdecl Tile::*(int)
    // int __cdecl Tile::*(const char*)
    // int __cdecl Tile::*(const char*, char*)
    // Tile* __cdecl Tile::*(NiNode*)
    // bool __cdecl Tile::*(const char*)
    // Tile* __cdecl Tile::*(bool)
    // void __cdecl Tile::*(Tile*)
    // int __cdecl Tile::*()
    // int __cdecl Tile::*()
    // void __cdecl Tile::*()
    // void __cdecl Tile::*(Tile*)
    // void __cdecl Tile::*()
    // void __cdecl Tile::*()
    // void __cdecl Tile::*()
    // void __cdecl Tile::*()
    // void __cdecl Tile::*()
    // Tile* __cdecl Tile::*(Tile*, const char*)
    // Tile* __cdecl Tile::*(Tile*, const char*)
    // Tile* __cdecl Tile::*(Tile*, int)
    // Tile* __cdecl Tile::*(int)
    // Tile* __cdecl Tile::*(Tile::enumType)
    // float __cdecl Tile::*()
    // float __cdecl Tile::*(Tile*)
    // void __cdecl Tile::*(bool)
    // void __cdecl Tile::*()
    // void __cdecl Tile::*()
    // void __cdecl Tile::*(const char*, const char*, BSStringT<char>*, NiRect<float>*)
    // void __cdecl Tile::*(bool)
    // bool __cdecl Tile::*()
    // Tile& __cdecl Tile::*(const Tile&)
    // void __cdecl Tile::*()
};
FNV_STATIC_ASSERT(sizeof(Tile) == 56);
FNV_STATIC_ASSERT(offsetof(Tile, m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(offsetof(Tile, m_kChildTileList) == 4);
FNV_STATIC_ASSERT(offsetof(Tile, m_kValues) == 16);
FNV_STATIC_ASSERT(offsetof(Tile, StringProvider) == 32);
FNV_STATIC_ASSERT(offsetof(Tile, pParent) == 40);
FNV_STATIC_ASSERT(offsetof(Tile, m_pRenderedNodeEntry) == 44);
FNV_STATIC_ASSERT(offsetof(Tile, uiFlags) == 48);
FNV_STATIC_ASSERT(offsetof(Tile, m_bFlagAfterUiFlags) == 52);
FNV_STATIC_ASSERT(offsetof(Tile, m_bSpeechChallengeFailure) == 53);
#endif
