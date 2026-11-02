// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_MODELLOADER_H
#define FNV_MODELLOADER_H

#include "layout_support.h"
#include "TESObjectREFR.h"
#include "layout_support.h"
class BackgroundCloneThread;
class LockFreeCaseInsensitiveStringMap_KFModel___;
class LockFreeCaseInsensitiveStringMap_LoadedFile___;
class LockFreeCaseInsensitiveStringMap_Model___;
class LockFreeMap_AnimIdle___NiPointer_QueuedAnimIdle___;
class LockFreeMap_Animation___NiPointer_QueuedReplacementKFList___;
class LockFreeMap_BSFileEntry___NiPointer_QueuedTexture___;
class LockFreeMap_TESObjectREFR___NiPointer_QueuedHelmet___;
class LockFreeMap_TESObjectREFR___NiPointer_QueuedReference___;
class LockFreeQueue_NiPointer_AttachDistant3DTask___;
class ModelLoader;
#pragma pack(push, 4)
class ModelLoader
{
  public:
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
    void QueueModelLoad(const char*, bool, unsigned int);
    LockFreeCaseInsensitiveStringMap_Model___* m_pLoadedModelMap;                                 // +0x0, 4 bytes
    LockFreeCaseInsensitiveStringMap_KFModel___* m_pLoadedKFModelMap;                             // +0x4, 4 bytes
    LockFreeMap_TESObjectREFR___NiPointer_QueuedReference___* m_pQueuedReferenceMap;              // +0x8, 4 bytes
    LockFreeMap_TESObjectREFR___NiPointer_QueuedReference___* m_pQueuedReferenceUpdateMap;        // +0xC, 4 bytes
    LockFreeMap_AnimIdle___NiPointer_QueuedAnimIdle___* m_pQueuedAnimIdleMap;                     // +0x10, 4 bytes
    LockFreeMap_Animation___NiPointer_QueuedReplacementKFList___* m_pQueuedReplacementKFListMap;  // +0x14, 4 bytes
    LockFreeMap_TESObjectREFR___NiPointer_QueuedHelmet___* m_pQueuedHelmetMap;                    // +0x18, 4 bytes
    LockFreeQueue_NiPointer_AttachDistant3DTask___* m_pDistant3DTaskQueue;                        // +0x1C, 4 bytes
    LockFreeMap_BSFileEntry___NiPointer_QueuedTexture___* m_pQueuedTextureMap;                    // +0x20, 4 bytes
    LockFreeCaseInsensitiveStringMap_LoadedFile___* m_pLoadedFileMap;                             // +0x24, 4 bytes
    BackgroundCloneThread* m_pBackgroundCloneThread;                                              // +0x28, 4 bytes
    bool m_bLoadTexturesDegraded;                                                                 // +0x2C, 1 bytes
    unsigned char layoutPadding2D[3];
    // void __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*(BSFile*, bool)
    // bool __cdecl ModelLoader::*(const char*, IO_TASK_PRIORITY, QueuedFile*)
    // void __cdecl ModelLoader::*(MagicItem*, EffectSetting*, IO_TASK_PRIORITY)
    // void __cdecl ModelLoader::*(TESObjectREFR*, IO_TASK_PRIORITY, bool)
    // void __cdecl ModelLoader::*(TESModel*, IO_TASK_PRIORITY, QueuedFile*, TESObjectREFR*)
    // void __cdecl ModelLoader::*(TESModel*, IO_TASK_PRIORITY, QueuedFile*, TESObjectREFR*, bool, bool)
    // void __cdecl ModelLoader::*(BSSimpleList<char const *>*, IO_TASK_PRIORITY, QueuedFile*, const char*)
    // void __cdecl ModelLoader::*(BSSimpleList<char const *>*, Animation*, IO_TASK_PRIORITY, QueuedFile*, const char*)
    // void __cdecl ModelLoader::*(TESNPC*, NiPointer<QueuedHead>&, IO_TASK_PRIORITY, QueuedFile*)
    // void __cdecl ModelLoader::*(BipedAnim*, NiPointer<QueuedHelmet>&, IO_TASK_PRIORITY, QueuedFile*, BIPED_OBJECT)
    // KFModel* __cdecl ModelLoader::*(const char*, AnimIdle*, IO_TASK_PRIORITY, TESObjectREFR*)
    // void __cdecl ModelLoader::*(const char*, IO_TASK_PRIORITY, QueuedFile*, IO_FILE_INDEX)
    // void __cdecl ModelLoader::*(const char*, IO_TASK_PRIORITY, QueuedFile*, IO_FILE_INDEX)
    // void __cdecl ModelLoader::*(TESModel*, IO_TASK_PRIORITY, QueuedFile*, int)
    // void __cdecl ModelLoader::*(TESModel*, IO_TASK_PRIORITY, QueuedFile*, int)
    // bool __cdecl ModelLoader::*(BSFileEntry*, IO_TASK_PRIORITY, QueuedFile*)
    // void __cdecl ModelLoader::*(const char*, bool, unsigned int)
    // void __cdecl ModelLoader::*(const char*, bool)
    // void __cdecl ModelLoader::*(Animation*)
    // void __cdecl ModelLoader::*(AnimIdle*)
    // void __cdecl ModelLoader::*(TESObjectREFR*)
    // void __cdecl ModelLoader::*(TESObjectCELL*)
    // bool __cdecl ModelLoader::*(TESObjectREFR*)
    // TESModel* __cdecl ModelLoader::*(TESBoundObject*, TESObjectREFR*)
    // bool __cdecl ModelLoader::*(TESObjectREFR*, TESModel*, IO_TASK_PRIORITY, bool)
    // void __cdecl ModelLoader::*(TESObjectCELL*)
    // void __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*(AttachDistant3DTask*)
    // bool __cdecl ModelLoader::*()
    // bool __cdecl ModelLoader::*()
    // bool __cdecl ModelLoader::*(bool)
    // bool __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*(NiAVObject*)
    // bool __cdecl ModelLoader::*(const char*, LoadedFile*)
    // void __cdecl ModelLoader::*(const char*)
    // LoadedFile* __cdecl ModelLoader::*(const char*)
    // void __cdecl ModelLoader::*(const char*, ...)
    // void __cdecl ModelLoader::*(int, int*, int*, bool)
    // void __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*()
    // bool __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*(float)
    // unsigned int __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*(QueuedReference*)
    // void __cdecl ModelLoader::*(TESObjectREFR*)
    // void __cdecl ModelLoader::*(AnimIdle*)
    // void __cdecl ModelLoader::*(Animation*)
    // void __cdecl ModelLoader::*(TESObjectREFR*)
    // bool __cdecl ModelLoader::*(BSFileEntry*, QueuedTexture*)
    // void __cdecl ModelLoader::*(BSFileEntry*)
    // QueuedTexture* __cdecl ModelLoader::*(BSFileEntry*)
    // bool __cdecl ModelLoader::*()
    // unsigned int __cdecl ModelLoader::*()
    // unsigned int __cdecl ModelLoader::*()
    // unsigned int __cdecl ModelLoader::*()
    // bool __cdecl ModelLoader::*(const char*, Model*)
    // bool __cdecl ModelLoader::*(const char*, KFModel*)
    // NiNode* __cdecl ModelLoader::*(const char*, ENUM_LOD_MULT, bool, bool, bool, bool)
    // KFModel* __cdecl ModelLoader::*(const char*)
    // void __cdecl ModelLoader::*(const char*, NiPointer<bhkPoseArray>&)
    // bool __cdecl ModelLoader::*(const char*, NiPointer<Model>&)
    // BSSimpleList<char const *>* __cdecl ModelLoader::*(const char*, const char*, BSSimpleList<char const *>*)
    // BSSimpleList<char const *>* __cdecl ModelLoader::*(const char*)
    // BSSimpleList<char const *>* __cdecl ModelLoader::*(const char*, bool, bool, ANIM_GROUP_WEAPON_ENUM)
    // BSSimpleList<char const *>* __cdecl ModelLoader::*(BSSimpleList<char const *>*, BSSimpleList<char const *>*)
    // bool __cdecl ModelLoader::*(TESObjectCELL*)
    // FindKFModel
    // void __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*(bool)
    // void __cdecl ModelLoader::*(const char*)
    // void __cdecl ModelLoader::*(const char*)
    // void __cdecl ModelLoader::*(TESObjectREFR*, NiNode*)
    // void __cdecl ModelLoader::*(NiNode*)
    // bool __cdecl ModelLoader::*()
    // void __cdecl ModelLoader::*(Model*, const char*)
    // void* __cdecl ModelLoader::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ModelLoader) == 48);
FNV_STATIC_ASSERT(offsetof(ModelLoader, m_pLoadedModelMap) == 0);
FNV_STATIC_ASSERT(offsetof(ModelLoader, m_pLoadedKFModelMap) == 4);
FNV_STATIC_ASSERT(offsetof(ModelLoader, m_pQueuedReferenceMap) == 8);
FNV_STATIC_ASSERT(offsetof(ModelLoader, m_pQueuedReferenceUpdateMap) == 12);
FNV_STATIC_ASSERT(offsetof(ModelLoader, m_pQueuedAnimIdleMap) == 16);
FNV_STATIC_ASSERT(offsetof(ModelLoader, m_pQueuedReplacementKFListMap) == 20);
FNV_STATIC_ASSERT(offsetof(ModelLoader, m_pQueuedHelmetMap) == 24);
FNV_STATIC_ASSERT(offsetof(ModelLoader, m_pDistant3DTaskQueue) == 28);
FNV_STATIC_ASSERT(offsetof(ModelLoader, m_pQueuedTextureMap) == 32);
FNV_STATIC_ASSERT(offsetof(ModelLoader, m_pLoadedFileMap) == 36);
FNV_STATIC_ASSERT(offsetof(ModelLoader, m_pBackgroundCloneThread) == 40);
FNV_STATIC_ASSERT(offsetof(ModelLoader, m_bLoadTexturesDegraded) == 44);
#endif
