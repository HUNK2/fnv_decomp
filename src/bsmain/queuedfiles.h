// Authored reconstruction of the bsmain/queuedfiles.h unit (Doc Speech30 aid
// segment): QueuedFile::HandleChildCompletion and QueuedFile::SetParent.
//
// covered PC functions as QueuedFile::HandleChildCompletion (0x0043bde0, 37
// bytes) and QueuedFile::SetParent (0x00443aa0, 65 bytes). Class layouts come
// from the same extraction: QueuedFile is a 40-byte IOTask with aeMemoryContext at
// +0x18, m_pParent at +0x1c, pChildren at +0x20 and pAdditionalParents at
// +0x24; QueuedFile's introducing virtuals occupy vtable offsets 0x20
// (DispatchToManager), 0x24 (HandleChildCompletion) and 0x28 (OnChildCompletion), which the
// deployed FalloutNV vtable confirms. QueuedChildren is a 20-byte
// BSSimpleArray<NiPointer<QueuedFile>,1024> with a 16-byte array base and the
// finished-child counter at +0x10.
#ifndef FNV_BSMAIN_QUEUEDFILES_H
#define FNV_BSMAIN_QUEUEDFILES_H


// Memory context enumeration of the engine allocation tracker, matching the
// deployed MEM_CONTEXT declaration used by the sibling engine units.
enum MEM_CONTEXT
{
    MEM_CONTEXT_MEM_CONTEXT_STATICVARS = 0,
    MEM_CONTEXT_MEM_CONTEXT_EXTERNAL = 1,
    MEM_CONTEXT_MEM_CONTEXT_DEBUG = 2,
    MEM_CONTEXT_MEM_CONTEXT_POOL = 3,
    MEM_CONTEXT_MEM_CONTEXT_RENDERER_OVERHEAD = 4,
    MEM_CONTEXT_MEM_CONTEXT_SHADER_OVERHEAD = 5,
    MEM_CONTEXT_MEM_CONTEXT_TASK_OVERHEAD = 6,
    MEM_CONTEXT_MEM_CONTEXT_EFFECTS_OVERHEAD = 7,
    MEM_CONTEXT_MEM_CONTEXT_STRING_TABLES = 8,
    MEM_CONTEXT_MEM_CONTEXT_GAMESETTING = 9,
    MEM_CONTEXT_MEM_CONTEXT_GAME_OVERHEAD = 10,
    MEM_CONTEXT_MEM_CONTEXT_AUDIO = 11,
    MEM_CONTEXT_MEM_CONTEXT_FONTS = 12,
    MEM_CONTEXT_MEM_CONTEXT_INTERFACE = 13,
    MEM_CONTEXT_MEM_CONTEXT_LOCALMAP = 14,
    MEM_CONTEXT_MEM_CONTEXT_GAMEBRIO = 15,
    MEM_CONTEXT_MEM_CONTEXT_HAVOK = 16,
    MEM_CONTEXT_MEM_CONTEXT_SAVELOAD = 17,
    MEM_CONTEXT_MEM_CONTEXT_LOADERS = 18,
    MEM_CONTEXT_MEM_CONTEXT_ARCHIVES = 19,
    MEM_CONTEXT_MEM_CONTEXT_MOVIEPLAYER = 20,
    MEM_CONTEXT_MEM_CONTEXT_SCRIPTS = 21,
    MEM_CONTEXT_MEM_CONTEXT_MASTER_FILE = 22,
    MEM_CONTEXT_MEM_CONTEXT_BSFILE = 23,
    MEM_CONTEXT_MEM_CONTEXT_FILESYSTEM = 24,
    MEM_CONTEXT_MEM_CONTEXT_WORLD_SG = 25,
    MEM_CONTEXT_MEM_CONTEXT_CELLS = 26,
    MEM_CONTEXT_MEM_CONTEXT_LAND = 27,
    MEM_CONTEXT_MEM_CONTEXT_GRASS = 28,
    MEM_CONTEXT_MEM_CONTEXT_WATER = 29,
    MEM_CONTEXT_MEM_CONTEXT_TREEART = 30,
    MEM_CONTEXT_MEM_CONTEXT_TREESYSTEM = 31,
    MEM_CONTEXT_MEM_CONTEXT_SHADOWS = 32,
    MEM_CONTEXT_MEM_CONTEXT_SKY = 33,
    MEM_CONTEXT_MEM_CONTEXT_LODMANAGER = 34,
    MEM_CONTEXT_MEM_CONTEXT_LODLANDSCAPE = 35,
    MEM_CONTEXT_MEM_CONTEXT_LODBUILDINGS = 36,
    MEM_CONTEXT_MEM_CONTEXT_SHADERS = 37,
    MEM_CONTEXT_MEM_CONTEXT_IMAGE_SPACE = 38,
    MEM_CONTEXT_MEM_CONTEXT_HAIRSHADER = 39,
    MEM_CONTEXT_MEM_CONTEXT_PRECIPITATION = 40,
    MEM_CONTEXT_MEM_CONTEXT_PROCESSES = 41,
    MEM_CONTEXT_MEM_CONTEXT_COMBAT_AI = 42,
    MEM_CONTEXT_MEM_CONTEXT_GLOBAL_LISTS = 43,
    MEM_CONTEXT_MEM_CONTEXT_PATHING = 44,
    MEM_CONTEXT_MEM_CONTEXT_NAVMESH = 45,
    MEM_CONTEXT_MEM_CONTEXT_TES_DEFAULT_OBJECTS = 47,
    MEM_CONTEXT_MEM_CONTEXT_TES_FORMS = 48,
    MEM_CONTEXT_MEM_CONTEXT_TES_REFERENCES = 49,
    MEM_CONTEXT_MEM_CONTEXT_TES_ACTOR = 50
};

// Shared engine pointer template. The pointer conversion and the assignment
// operator stay out of line: the PC engine bodies are separate functions
// (NiPointer<QueuedFile>::operator QueuedFile*() const at 0x00559450 and
// NiPointer<QueuedFile>::operator= at 0x006f74f0), not inlined template code.
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* pObject = 0);
    ~NiPointer();
    operator T*() const;
    NiPointer& operator=(T* pObject);
};

// Engine array with a fixed growth policy; 16 bytes, carried as the base of
// the child and parent collections.
template <class T, unsigned int Growth> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;
    T* pBuffer;
    unsigned int iSize;
    unsigned int SimpleArrayStorage;
    unsigned int GetSize();
    T& GetAt(int index);
};

class QueuedFile;

// Tracks the child tasks of a file and how many have already finished.
class QueuedChildren : public BSSimpleArray<NiPointer<QueuedFile>, 1024>
{
  public:
    virtual ~QueuedChildren();
    void AddFinishedChild();
    unsigned int GetChildCountFinished();

  private:
    volatile unsigned int m_uiChildCountFinished;  // +0x10
};

// Tracks the additional parents registered on a file.
class QueuedParents : public BSSimpleArray<NiPointer<QueuedFile>, 1024>
{
  public:
    virtual ~QueuedParents();
};

// Root of the IO task tree. BSTask<T>'s virtuals occupy vtable offsets 0x00
// (destructor), 0x04 (Run), 0x08 (Finish), 0x0c (Cancel) and 0x10
// (GetDescription); the task storage fills IOTask to its engine size of 24
// bytes.
class BSTask
{
  public:
    virtual ~BSTask();
    virtual void Run();
    virtual void Finish();
    virtual void Cancel();
    virtual bool GetDescription(char* pDescription, unsigned int uiSize);

  private:
    unsigned char taskStorage[0x14];
};

class IOTask : public BSTask
{
  public:
    virtual void ProcessLoadedAnimIdle();        // vtable offset 0x14
    virtual void GenerateKey();                  // vtable offset 0x18
    virtual void ChangePriority(int iPriority);  // vtable offset 0x1c; IO_TASK_PRIORITY ABI
};

// Asynchronous file task recorded by the engine as QueuedFile (40 bytes,
// IOTask base).
class QueuedFile : public IOTask
{
  public:
    virtual void DispatchToManager();                         // vtable offset 0x20
    virtual void HandleChildCompletion(QueuedFile* apChild);  // vtable offset 0x24
    virtual void OnChildCompletion();                         // vtable offset 0x28

    void SetParent(QueuedFile* apParent);
    void AddAdditionalParent(QueuedFile* apParent);
    unsigned int GetChildCount();
    unsigned int GetChildCountFinished();
    bool GetAllChildrenFinished();

  protected:
    void AddChild(QueuedFile* apChild);

    MEM_CONTEXT aeMemoryContext;        // +0x18
    NiPointer<QueuedFile> m_pParent;    // +0x1c
    QueuedChildren* pChildren;          // +0x20
    QueuedParents* pAdditionalParents;  // +0x24
};

// Out-of-line definitions live in the companion translation unit.
#endif
