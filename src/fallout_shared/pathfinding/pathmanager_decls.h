// fallout_shared/pathfinding/pathmanager_decls.h: declares QueuedMessage, ActorPathingMessageQueue, NiMemObject, PathingSolution, Pathing and more

class WaitableObject;
class PathingRequest;
class ActorPathingMessageQueue;
class PathingSolution;

template <class T> class NiPointer;

template <> class NiPointer<WaitableObject>
{
  public:
    WaitableObject* m_pObject;
    NiPointer<WaitableObject>& operator=(const NiPointer<WaitableObject>&);
};

template <> class NiPointer<PathingRequest>
{
  public:
    PathingRequest* m_pObject;
    NiPointer();
    NiPointer(const NiPointer<PathingRequest>&);
    ~NiPointer();
    operator PathingRequest*() const;
};

template <> class NiPointer<ActorPathingMessageQueue>
{
  public:
    ActorPathingMessageQueue* m_pObject;
    NiPointer();
    NiPointer(const NiPointer<ActorPathingMessageQueue>&);
    ~NiPointer();
    operator ActorPathingMessageQueue*() const;
};

template <> class NiPointer<PathingSolution>
{
  public:
    PathingSolution* m_pObject;
    NiPointer();
    NiPointer(PathingSolution*);
    NiPointer(const NiPointer<PathingSolution>&);
    ~NiPointer();
    operator PathingSolution*() const;
    NiPointer<PathingSolution>& operator=(PathingSolution*);
};

enum PATHING_MESSAGE_TYPE
{
    PATHING_MESSAGE_TYPE_PMT_UNDEF = -1,
    PATHING_MESSAGE_TYPE_PMT_OK = 0,
    PATHING_MESSAGE_TYPE_PMT_ERROR = 1
};

class QueuedMessage
{
  public:
    int m_eMessageType;
    NiPointer<WaitableObject> m_pPathingSolution;
    QueuedMessage(PATHING_MESSAGE_TYPE type, const NiPointer<PathingSolution>& solution);
    ~QueuedMessage();
    QueuedMessage& operator=(const QueuedMessage&);
};

class ActorPathingMessageQueue
{
  public:
    virtual ~ActorPathingMessageQueue();
    virtual bool Push(const QueuedMessage& msg);
};

class NiMemObject
{
  public:
    static void* operator new(unsigned int size);
    static void operator delete(void* p, unsigned int);
};

class PathingSolution : public NiMemObject
{
  public:
    char pad[0x44];
    PathingSolution();
};

class Pathing
{
  public:
    static bool BuildPath(PathingRequest* pRequest, PathingSolution* m_pOutputSolution);
};

class RecursiveSpinLock
{
  public:
    void Lock(const char*);
    void Unlock();
};

class ParentSpaceNode;
template <class T, int N> class BSSimpleArray
{
  public:
    unsigned int GetSize();
};

class TESObjectREFR
{
  public:
    int pad;
    int state;
};

template <class T> class NiTNewInterface;

template <class T, class Allocator> class NiTArray
{
  public:
    T& GetAt(unsigned int);
};

struct Struct_004b0680
{
    int m_val;
    void* m_ptr;
    Struct_004b0680(int val, void* ptr);
    ~Struct_004b0680();
};

class PathingTaskData
{
  public:
    int pad00;
    bool bFlag04;
    char pad05[0x13];
    NiPointer<PathingRequest> m_pPathingRequest;
    NiPointer<PathingSolution> m_pPathingSolution;
    char pad20[0x40];
    NiPointer<ActorPathingMessageQueue> spQueue;

    bool HasPendingMessages();
    void Process();
    void FUN_006ea330();
    bool FUN_005dc980();
};

class PerformanceMeasurement;
class PerformanceTimerManager
{
  public:
    PerformanceMeasurement* Register(char*, char*, bool, bool);
};

enum MEM_CONTEXT
{
    MEM_CONTEXT_DEFAULT = 0x2d
};

class AutoMemContext
{
  public:
    int m_eMemoryContext;
    AutoMemContext(MEM_CONTEXT context, bool track, const char* file, int line);
    ~AutoMemContext();
};

class PathManagerImpl
{
  public:
    char pad[0x14c0];
    PathManagerImpl();
    bool Initialize();
    bool BuildPath(NiPointer<PathingRequest> m_pPathingRequest, NiPointer<ActorPathingMessageQueue> spQueue);

    bool FUN_006eb790();
    void FUN_006eb7b0();
    bool GetByteAtOffsetC34();
    void DispatchPathingMessage(const Struct_004b0680& item);
};

union SETTING_VALUE
{
    bool b;
    int i;
    float f;
    char* s;
};

class INISettingCollection;

template <class T> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};

class GlobalObject_0045cf30 : public SettingT<INISettingCollection>
{
};
extern GlobalObject_0045cf30 g_011d77cc;

struct DummyTimer
{
    void FUN_00483710();
};

class PathManager
{
  public:
    PathManagerImpl* m_pPathManagerImpl;
    PerformanceTimerManager m_kPerformanceTimerManager;
    PathManager();
    bool Initialize();
    bool BuildPath(NiPointer<PathingRequest> m_pPathingRequest, NiPointer<ActorPathingMessageQueue> spQueue,
                   bool bAsync);

    static PathManager* GetRandomGenerator();
    PathManagerImpl* FUN_00559450();
    DummyTimer* FUN_00717e50();
};

extern "C" char DAT_0103a1bc[];
extern "C" char DAT_0106d624[];
extern "C" char DAT_0106d560[];
