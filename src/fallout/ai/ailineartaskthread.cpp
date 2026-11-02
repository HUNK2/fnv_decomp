// fallout/ai/ailineartaskthread.cpp: AILinearTaskThread, Thr (3 functions)

class GlobalObject_008c71b0
{
    int value;

  public:
    GlobalObject_008c71b0(int);
    GlobalObject_008c71b0(const GlobalObject_008c71b0&);
};
class hkMemoryAllocator
{
  public:
    virtual void vfn_0();
    virtual void* vfn_4(int);
};
class OSGlobals
{
  public:
    unsigned int GetUptimeMilliseconds();
};
enum MagicSystem__CastingType
{
    CastingType0
};
class TESEnchantableForm
{
  public:
    void SetCastingType(MagicSystem__CastingType);
};
class InterfaceManager
{
  public:
    void FUN_00984f60(unsigned int);
};
class BGSPerkEntry;
template <class T> class BSSimpleList
{
  public:
    T& GetItem();
};
class hkMemorySystem
{
  public:
    static hkMemorySystem* GetMonitorStream();
    void GetMonitorStream(void*, int);
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c(void*, const char*, GlobalObject_008c71b0);
};
class PointerCallback
{
  public:
    static void HandlePointer(void*);
};
class TESDataHandler
{
  public:
    void BuildCompiledFileList();
};
extern TESDataHandler* g_dataHandler;
class AILinearTaskThread
{
  public:
    char padding[0x50];
    char memoryRouter[0x24];
    void* memory;
    void StartTaskThread();
};
// @fnv 0x008c6ff0
void AILinearTaskThread::StartTaskThread()
{
    hkMemorySystem::GetMonitorStream()->vfn_c(memoryRouter, "AILinearTaskThread", GlobalObject_008c71b0(1));
    PointerCallback::HandlePointer(memoryRouter);
    ((TESEnchantableForm*)memoryRouter)
        ->SetCastingType((MagicSystem__CastingType)((OSGlobals*)memoryRouter)->GetUptimeMilliseconds());
    ((InterfaceManager*)memoryRouter)->FUN_00984f60(((OSGlobals*)memoryRouter)->GetUptimeMilliseconds());
    memory = ((hkMemoryAllocator*)((OSGlobals*)memoryRouter)->GetUptimeMilliseconds())->vfn_4(0x32000);
    ((hkMemorySystem*)&((BSSimpleList<BGSPerkEntry*>*)memoryRouter)->GetItem())->GetMonitorStream(memory, 0x32000);
    g_dataHandler->BuildCompiledFileList();
}

void __cdecl operator delete(void*);
struct FUN_008c7830
{
    void FUN_008c7860();
    FUN_008c7830* FUN_008c7830_(unsigned int aiFlags);
};
// Calls FUN_008c7860, frees this with operator delete when aiFlags has bit 0 set, and returns this.
// @fnv 0x008c7830
FUN_008c7830* FUN_008c7830::FUN_008c7830_(unsigned int aiFlags)
{
    FUN_008c7860();
    if (aiFlags & 1)
        operator delete(this);
    return this;
}

struct Alloc
{
    virtual void v0();
    virtual void v4();
    virtual void v8(void* p, int n);
};
struct Fin
{
    void Done();
};
struct Router
{
    Alloc* GetAlloc();
    Fin* Next(int a, int b);
};
struct HkSys
{
    virtual void v0();
    virtual void v4();
    virtual void v8();
    virtual void vc();
    virtual void v10(Router* r, GlobalObject_008c71b0 g);
};
void hkInit();
HkSys* hkGet();
struct Thr
{
    char padding[0x50];
    Router memoryRouter;
    char pad2[0x20];
    void* memory;
    void InitMemory();
};
// @fnv 0x008c7110
void Thr::InitMemory()
{
    memoryRouter.GetAlloc()->v8(memory, 0x32000);
    hkInit();
    hkGet()->v10(&memoryRouter, GlobalObject_008c71b0(1));
    memoryRouter.Next(0, 0)->Done();
}
