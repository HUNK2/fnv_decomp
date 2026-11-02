// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_BGSSAVELOADQUEUEDSUBBUFFERMAP_H
#define FNV_BGSSAVELOADQUEUEDSUBBUFFERMAP_H

#include "layout_support.h"
#include "TESForm.h"
#include "layout_support.h"
class BGSLoadGameSubBuffer;
class BGSLoadGameBuffer;
class BGSLoadFormBuffer;
class LoadGameSubBufferQueue;
class DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer___;
class NiTMap_TESForm___BGSLoadGameSubBuffer_;
class NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_;
class NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer___AntiBloatAllocator;
#pragma pack(push, 4)
class BGSLoadGameSubBuffer
{
  public:
    char* pBuffer;  // +0x0, 4 bytes
    void LoadGame(BGSLoadGameBuffer* buffer);
    BGSLoadFormBuffer* CreateFormBuffer(TESForm* form);
    void ReadAnimationState(TESForm* form);
    void RestoreAnimation(TESForm* form);
    void LoadHavokData(TESForm* form);
    void FUN_00435b20();
    // BGSLoadGameSubBuffer
    // void __cdecl BGSLoadGameSubBuffer::*(char*)
    // void __cdecl BGSLoadGameSubBuffer::*()
    // void __cdecl BGSLoadGameSubBuffer::*(TESForm*)
    // void __cdecl BGSLoadGameSubBuffer::*(TESForm*)
    // void __cdecl BGSLoadGameSubBuffer::*(TESForm*)
    // void __cdecl BGSLoadGameSubBuffer::*(TESForm*)
    // void __cdecl BGSLoadGameSubBuffer::*(TESForm*)
    // void __cdecl BGSLoadGameSubBuffer::*(BGSSaveGameBuffer*)
    // void __cdecl BGSLoadGameSubBuffer::*(BGSLoadGameBuffer*)
    // char* __cdecl BGSLoadGameSubBuffer::*()
    // BGSLoadFormBuffer* __cdecl BGSLoadGameSubBuffer::*(TESForm*)
    // void __cdecl BGSLoadGameSubBuffer::*(BGSSaveFormBuffer*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSLoadGameSubBuffer) == 4);
FNV_STATIC_ASSERT(offsetof(BGSLoadGameSubBuffer, pBuffer) == 0);
#pragma pack(push, 4)
class DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer___
{
  public:
    // void* __cdecl DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >::*()
    // void __cdecl DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >::*(void*)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer___) == 1);
#pragma pack(push, 4)
class NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer___AntiBloatAllocator
    : public DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer___
{
  public:
    // base DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> > at +0x0, size 1
    unsigned int m_uiCount;  // +0x0, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(
    sizeof(
        NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer___AntiBloatAllocator) ==
    4);
FNV_STATIC_ASSERT(
    offsetof(
        NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer___AntiBloatAllocator,
        m_uiCount) == 0);
#pragma pack(push, 4)
class NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_
{
  public:
    void** m_ppVirtualMethodTable;                                              // +0x0, 4 bytes
    unsigned int m_uiHashSize;                                    // +0x4, 4 bytes
    NiTMapItem<TESForm*, BGSLoadGameSubBuffer>** m_ppkHashTable;  // +0x8, 4 bytes
    NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer___AntiBloatAllocator
        m_kItemCount;  // +0xC, 4 bytes
    // NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>
    // unsigned int __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*(TESForm*, BGSLoadGameSubBuffer)
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*(TESForm*)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*()
    // bool __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*(TESForm*, BGSLoadGameSubBuffer&)
    // void* __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*(void*&, TESForm*&, BGSLoadGameSubBuffer&)
    // NiTMapItem<TESForm *,BGSLoadGameSubBuffer>* __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*(TESForm*)
    // NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>& __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*(const NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>&)
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*()
    // void __cdecl NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(
    sizeof(NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_) == 16);
FNV_STATIC_ASSERT(
    offsetof(NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_, m_ppVirtualMethodTable) ==
    0);
FNV_STATIC_ASSERT(
    offsetof(NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_,
             m_uiHashSize) == 4);
FNV_STATIC_ASSERT(
    offsetof(NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_,
             m_ppkHashTable) == 8);
FNV_STATIC_ASSERT(
    offsetof(NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_,
             m_kItemCount) == 12);
#pragma pack(push, 4)
class NiTMap_TESForm___BGSLoadGameSubBuffer_
    : public NiTMapBase_DFALL_NiTMapItem_TESForm___BGSLoadGameSubBuffer____TESForm___BGSLoadGameSubBuffer_
{
  public:
    NiTMap_TESForm___BGSLoadGameSubBuffer_(unsigned int hashSize = 37);
    ~NiTMap_TESForm___BGSLoadGameSubBuffer_();
    // base NiTMapBase<DFALL<NiTMapItem<TESForm *,BGSLoadGameSubBuffer> >,TESForm *,BGSLoadGameSubBuffer> at +0x0, size 16
    // NiTMap<TESForm *,BGSLoadGameSubBuffer>
    // void __cdecl NiTMap<TESForm *,BGSLoadGameSubBuffer>::*()
    // NiTMapItem<TESForm *,BGSLoadGameSubBuffer>* __cdecl NiTMap<TESForm *,BGSLoadGameSubBuffer>::*()
    // void __cdecl NiTMap<TESForm *,BGSLoadGameSubBuffer>::*(NiTMapItem<TESForm *,BGSLoadGameSubBuffer>*)
    // NiTMap<TESForm *,BGSLoadGameSubBuffer>& __cdecl NiTMap<TESForm *,BGSLoadGameSubBuffer>::*(const NiTMap<TESForm *,BGSLoadGameSubBuffer>&)
    // void __cdecl NiTMap<TESForm *,BGSLoadGameSubBuffer>::*()
    // void __cdecl NiTMap<TESForm *,BGSLoadGameSubBuffer>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(NiTMap_TESForm___BGSLoadGameSubBuffer_) == 16);
#pragma pack(push, 4)
class LoadGameSubBufferQueue
{
  public:
    NiTMap_TESForm___BGSLoadGameSubBuffer_ m_kSubBuffersByType[3];  // +0x0, 48 bytes
    LoadGameSubBufferQueue();
    void QueueAnimationAndCharController();
    void ProcessQueuedSubBuffers(QUEUED_SUB_BUFFER_TYPE type);
    void ProcessSubBuffer(QUEUED_SUB_BUFFER_TYPE type, BGSLoadFormBuffer* buffer, TESForm* form);
    // LoadGameSubBufferQueue
    // void __cdecl LoadGameSubBufferQueue::*()
    // void __cdecl LoadGameSubBufferQueue::*(QUEUED_SUB_BUFFER_TYPE, BGSLoadFormBuffer*, TESForm*)
    // void __cdecl LoadGameSubBufferQueue::*()
    // void __cdecl LoadGameSubBufferQueue::*(QUEUED_SUB_BUFFER_TYPE)
    // LoadGameSubBufferQueue& __cdecl LoadGameSubBufferQueue::*(const LoadGameSubBufferQueue&)
    // void* __cdecl LoadGameSubBufferQueue::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(LoadGameSubBufferQueue) == 48);
FNV_STATIC_ASSERT(offsetof(LoadGameSubBufferQueue, m_kSubBuffersByType) == 0);
#endif
