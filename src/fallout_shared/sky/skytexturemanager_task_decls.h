// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_SKYTEXTUREMANAGER_TASK_DECLS_H
#define FNV_SKYTEXTUREMANAGER_TASK_DECLS_H

#include "layout_support.h"
#include "layout_support.h"
class BSFileEntry;
class BSTask___int64_;
class IOTask;
class NiTexture;
class QueuedChildren;
class QueuedFile;
class QueuedFileEntry;
class QueuedParents;
class SkyTask;
enum BS_TASK_STATE
{
    BS_TASK_STATE_BS_TASK_STATE_PENDING = 0,
    BS_TASK_STATE_BS_TASK_STATE_QUEUED = 1,
    BS_TASK_STATE_BS_TASK_STATE_MOVING = 2,
    BS_TASK_STATE_BS_TASK_STATE_RUNNING = 3,
    BS_TASK_STATE_BS_TASK_STATE_FINISHED = 4,
    BS_TASK_STATE_BS_TASK_STATE_COMPLETED = 5,
    BS_TASK_STATE_BS_TASK_STATE_CANCELED = 6,
    BS_TASK_STATE_BS_TASK_STATE_FORCE_DWORD = 2147483647
};
#pragma pack(push, 4)
class BSTask___int64_
{
  public:
    virtual ~BSTask___int64_();
    virtual void Run();
    unsigned char layoutPadding4[4];
    volatile int BackgroundTask;  // +0x8, 4 bytes
    BS_TASK_STATE eState;         // +0xC, 4 bytes
    __int64 Key;                  // +0x10, 8 bytes
    // BSTask<__int64>
    // bool __cdecl BSTask<__int64>::*()
    // bool __cdecl BSTask<__int64>::*()
    // bool __cdecl BSTask<__int64>::*()
    // bool __cdecl BSTask<__int64>::*()
    // void __cdecl BSTask<__int64>::*()
    // void __cdecl BSTask<__int64>::*()
    // __int64 __cdecl BSTask<__int64>::*()
    // BS_TASK_STATE __cdecl BSTask<__int64>::*()
    // bool __cdecl BSTask<__int64>::*(BS_TASK_STATE, BS_TASK_STATE)
    // void __cdecl BSTask<__int64>::*()
    // void __cdecl BSTask<__int64>::*()
    // unsigned int __cdecl BSTask<__int64>::*()
    // unsigned int __cdecl BSTask<__int64>::*()
    // BSTask<__int64>& __cdecl BSTask<__int64>::*(const BSTask<__int64>&)
    // void __cdecl BSTask<__int64>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTask___int64_) == 24);
FNV_STATIC_ASSERT(offsetof(BSTask___int64_, BackgroundTask) == 8);
FNV_STATIC_ASSERT(offsetof(BSTask___int64_, eState) == 12);
FNV_STATIC_ASSERT(offsetof(BSTask___int64_, Key) == 16);
#pragma pack(push, 4)
class IOTask : public BSTask___int64_
{
  public:
    // base BSTask<__int64> at +0x0, size 24
    // IOTask
    // unsigned char __cdecl IOTask::*()
    // void __cdecl IOTask::*(unsigned char)
    // IO_TASK_PRIORITY __cdecl IOTask::*()
    // void __cdecl IOTask::*(IO_TASK_PRIORITY)
    // void __cdecl IOTask::*(char, unsigned int, unsigned char, unsigned short)
    // void __cdecl IOTask::*()
    // unsigned short __cdecl IOTask::*()
    // unsigned int __cdecl IOTask::*()
    // void __cdecl IOTask::*()
    // unsigned char __cdecl IOTask::*(__int64&)
    // unsigned int __cdecl IOTask::*(__int64&)
    // unsigned char __cdecl IOTask::*(__int64&)
    // void __cdecl IOTask::*()
    // IOTask& __cdecl IOTask::*(const IOTask&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(IOTask) == 24);
#pragma pack(push, 4)
class QueuedFile : public IOTask
{
  public:
    // base IOTask at +0x0, size 24
    MEM_CONTEXT aeMemoryContext;        // +0x18, 4 bytes
    NiPointer<QueuedFile> m_pParent;    // +0x1C, 4 bytes
    QueuedChildren* pChildren;          // +0x20, 4 bytes
    QueuedParents* pAdditionalParents;  // +0x24, 4 bytes
    // QueuedFile
    // void __cdecl QueuedFile::*()
    // void __cdecl QueuedFile::*()
    // void __cdecl QueuedFile::*()
    // void __cdecl QueuedFile::*(IO_TASK_PRIORITY)
    // void __cdecl QueuedFile::*(BS_TASK_STATE, void*)
    // void __cdecl QueuedFile::*(QueuedFile*)
    // void __cdecl QueuedFile::*(QueuedFile*)
    // unsigned int __cdecl QueuedFile::*()
    // unsigned int __cdecl QueuedFile::*()
    // bool __cdecl QueuedFile::*()
    // void __cdecl QueuedFile::*(QueuedFile*)
    // QueuedFile& __cdecl QueuedFile::*(const QueuedFile&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(QueuedFile) == 40);
FNV_STATIC_ASSERT(offsetof(QueuedFile, aeMemoryContext) == 24);
FNV_STATIC_ASSERT(offsetof(QueuedFile, m_pParent) == 28);
FNV_STATIC_ASSERT(offsetof(QueuedFile, pChildren) == 32);
FNV_STATIC_ASSERT(offsetof(QueuedFile, pAdditionalParents) == 36);
#pragma pack(push, 4)
class QueuedFileEntry : public QueuedFile
{
  public:
    // base QueuedFile at +0x0, size 40
    char* pFileName;            // +0x28, 4 bytes
    BSFileEntry* m_pFileEntry;  // +0x2C, 4 bytes
    char* GetFileName();
    // QueuedFileEntry
    // void __cdecl QueuedFileEntry::*()
    // void __cdecl QueuedFileEntry::*()
    // char* __cdecl QueuedFileEntry::*()
    // void __cdecl QueuedFileEntry::*(const char*)
    // BSFileEntry* __cdecl QueuedFileEntry::*()
    // void __cdecl QueuedFileEntry::*(BSFileEntry*)
    // bool __cdecl QueuedFileEntry::*(char*, unsigned int, char*)
    // QueuedFileEntry& __cdecl QueuedFileEntry::*(const QueuedFileEntry&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(QueuedFileEntry) == 48);
FNV_STATIC_ASSERT(offsetof(QueuedFileEntry, pFileName) == 40);
FNV_STATIC_ASSERT(offsetof(QueuedFileEntry, m_pFileEntry) == 44);
#pragma pack(push, 4)
class SkyTask : public QueuedFileEntry
{
  public:
    // base QueuedFileEntry at +0x0, size 48
    NiPointer<NiTexture>* apTextureOutput;  // +0x30, 4 bytes
    unsigned char layoutPadding34[4];
    SkyTask(NiPointer<NiTexture>* texture, const char* fileName);
    virtual void Run();
    // SkyTask
    // void __cdecl SkyTask::*()
    // bool __cdecl SkyTask::*(char*, unsigned int)
    // unsigned char __cdecl SkyTask::*()
    // void __cdecl SkyTask::*()
    // SkyTask& __cdecl SkyTask::*(const SkyTask&)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(SkyTask) == 56);
FNV_STATIC_ASSERT(offsetof(SkyTask, apTextureOutput) == 48);
#endif
