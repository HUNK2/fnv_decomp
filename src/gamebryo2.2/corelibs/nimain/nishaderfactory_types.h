// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_NISHADERFACTORY_PRIVATE_TYPES_H
#define FNV_NISHADERFACTORY_PRIVATE_TYPES_H

#include "layout_support.h"
#include "NiFixedString.h"
#include "NiRefObject.h"
class DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry_____;
class NiGlobalConstantEntry;
class NiRenderer;
class NiShaderFactory;
class RefCountedNamedObject;
class NiTFixedStringMap_NiGlobalConstantEntry___;
class NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry___;
class
    NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry_____AntiBloatAllocator;
class DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry_____
{
  public:
    // void* __cdecl DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >::*()
    // void __cdecl DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >::*(void*)
};
FNV_STATIC_ASSERT(sizeof(DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry_____) == 1);
class
    NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry_____AntiBloatAllocator
    : public DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry_____
{
  public:
    // base DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
FNV_STATIC_ASSERT(
    sizeof(
        NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry_____AntiBloatAllocator) ==
    4);
FNV_STATIC_ASSERT(
    offsetof(
        NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry_____AntiBloatAllocator,
        m_uiCount) == 0);
class NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry___
{
  public:
    void** m_ppVirtualMethodTable;                                                     // +0x0, 4 bytes
    unsigned int m_uiHashSize;                                           // +0x4, 4 bytes
    NiTMapItem<NiFixedString, NiGlobalConstantEntry*>** m_ppkHashTable;  // +0x8, 4 bytes
    NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry_____AntiBloatAllocator
        m_kItemCount;  // +0xC, 4 bytes
    // NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>
    // unsigned int __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*()
    // bool __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*()
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*(NiFixedString&, NiGlobalConstantEntry*)
    // bool __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*(NiFixedString&)
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*()
    // bool __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*(const NiFixedString&, NiGlobalConstantEntry*&)
    // void* __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*()
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*(void*&, NiFixedString&, NiGlobalConstantEntry*&)
    // unsigned int __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*(const NiFixedString&)
    // bool __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*(const NiFixedString&, const NiFixedString&)
    // NiTMapItem<NiFixedString,NiGlobalConstantEntry *>* __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*(const NiFixedString&)
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*(NiTMapItem<NiFixedString,NiGlobalConstantEntry *>*, NiFixedString&, NiGlobalConstantEntry*)
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*(NiTMapItem<NiFixedString,NiGlobalConstantEntry *>*)
    // NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>& __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*(const NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>&)
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*()
    // void __cdecl NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *>::*()
};
FNV_STATIC_ASSERT(
    sizeof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry___) ==
    16);
FNV_STATIC_ASSERT(
    offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry___,
             m_ppVirtualMethodTable) == 0);
FNV_STATIC_ASSERT(
    offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry___,
             m_uiHashSize) == 4);
FNV_STATIC_ASSERT(
    offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry___,
             m_ppkHashTable) == 8);
FNV_STATIC_ASSERT(
    offsetof(NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry___,
             m_kItemCount) == 12);
class NiTFixedStringMap_NiGlobalConstantEntry___
    : public NiTFixedStringMapBase_DFALL_NiTMapItem_NiFixedString_NiGlobalConstantEntry______NiGlobalConstantEntry___
{
  public:
    // base NiTFixedStringMapBase<DFALL<NiTMapItem<NiFixedString,NiGlobalConstantEntry *> >,NiGlobalConstantEntry *> at +0x0, size 16
    // NiTFixedStringMap<NiGlobalConstantEntry *>
    // void __cdecl NiTFixedStringMap<NiGlobalConstantEntry *>::*()
    // NiTMapItem<NiFixedString,NiGlobalConstantEntry *>* __cdecl NiTFixedStringMap<NiGlobalConstantEntry *>::*()
    // void __cdecl NiTFixedStringMap<NiGlobalConstantEntry *>::*(NiTMapItem<NiFixedString,NiGlobalConstantEntry *>*)
    // NiTFixedStringMap<NiGlobalConstantEntry *>& __cdecl NiTFixedStringMap<NiGlobalConstantEntry *>::*(const NiTFixedStringMap<NiGlobalConstantEntry *>&)
    // void __cdecl NiTFixedStringMap<NiGlobalConstantEntry *>::*()
    // void __cdecl NiTFixedStringMap<NiGlobalConstantEntry *>::*()
};
FNV_STATIC_ASSERT(sizeof(NiTFixedStringMap_NiGlobalConstantEntry___) == 16);
class NiShaderFactory : public NiRefObject
{
  public:
    static NiShaderFactory* __cdecl GetInstance();

  protected:
    static NiShaderFactory* ms_pShaderFactory;

  public:
    // base NiRefObject at +0x0, size 8
    NiTFixedStringMap_NiGlobalConstantEntry___ m_kGlobalConstantEntryMap;  // +0x8, 16 bytes
    bool(__cdecl* m_pFindGlobalConstantEntry)(const char*, NiRenderer*, int, char**, bool,
                                              RefCountedNamedObject**);                               // +0x18, 4 bytes
    unsigned int(__cdecl* GlobalConstantEntryRegistry)(const char*, NiRenderer*, const char*, bool);  // +0x1C, 4 bytes
    unsigned int(__cdecl* GlobalConstantMapContext)(const char*, unsigned int, bool);                 // +0x20, 4 bytes
    // NiShaderFactory
    // void __cdecl NiShaderFactory::*()
    // void __cdecl NiShaderFactory::*()
    // NiShaderFactory* __cdecl NiShaderFactory::*()
    // void __cdecl NiShaderFactory::*()
    // void __cdecl NiShaderFactory::*(RefCountedNamedObject*)
    // void __cdecl NiShaderFactory::*(RefCountedNamedObject*)
    // void __cdecl NiShaderFactory::*()
    // bool __cdecl NiShaderFactory::*(bool __cdecl (const char*, NiRenderer*, int, char**, bool, RefCountedNamedObject**)*)
    // bool __cdecl NiShaderFactory::*(const char*, int, char**, bool)
    // bool __cdecl NiShaderFactory::*(unsigned int __cdecl (const char*, NiRenderer*, const char*, bool)*)
    // unsigned int __cdecl NiShaderFactory::*(const char*, const char*, bool)
    // bool __cdecl NiShaderFactory::*(unsigned int __cdecl (const char*, unsigned int, bool)*)
    // unsigned int __cdecl NiShaderFactory::*(unsigned int, bool, const char*, ...)
    // bool __cdecl NiShaderFactory::*(const NiFixedString&)
    // bool __cdecl NiShaderFactory::*(const NiFixedString&, unsigned int&, const void*&)
    // bool __cdecl NiShaderFactory::*(const NiFixedString&, unsigned int, const void*)
    // NiGlobalConstantEntry* __cdecl NiShaderFactory::*(const NiFixedString&)
    // const char* __cdecl NiShaderFactory::*(void*&)
    // const char* __cdecl NiShaderFactory::*(void*&)
    // void __cdecl NiShaderFactory::*(const char*)
    // void __cdecl NiShaderFactory::*(const char*)
    // void __cdecl NiShaderFactory::*()
    // NiShaderFactory& __cdecl NiShaderFactory::*(const NiShaderFactory&)
    // void __cdecl NiShaderFactory::*()
};
FNV_STATIC_ASSERT(sizeof(NiShaderFactory) == 36);
FNV_STATIC_ASSERT(offsetof(NiShaderFactory, m_kGlobalConstantEntryMap) == 8);
FNV_STATIC_ASSERT(offsetof(NiShaderFactory, m_pFindGlobalConstantEntry) == 24);
FNV_STATIC_ASSERT(offsetof(NiShaderFactory, GlobalConstantEntryRegistry) == 28);
FNV_STATIC_ASSERT(offsetof(NiShaderFactory, GlobalConstantMapContext) == 32);
#endif
