// bssystem/bspackedtaskqueue_decls.h: declares GarbageCollectorObjectPtr, BSPackedTask, PackedTaskQueueProcessor
#ifndef BSPACKEDTASKQUEUE_DECLS_H
#define BSPACKEDTASKQUEUE_DECLS_H

class NiAVObject;
class GarbageCollectorObjectPtr
{
  public:
    NiAVObject* operator->() const;
    unsigned char storage[12];
};
class BSPackedTask
{
  public:
    char data[32];
};
class PackedTaskQueueProcessor
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual bool vfn_10(BSPackedTask& task);
    unsigned char queueStorage[16];
    GarbageCollectorObjectPtr inputSources;
    void(__cdecl* m_pTaskCompletionCallback)(const BSPackedTask&);
    bool m_bIsProcessing;
    bool Process();
};
#endif
