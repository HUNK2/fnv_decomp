// fallout_shared/tempeffects/original_bstempeffectsimpledecal.h: declares NiPoint3, QueuedFile, AutoMemContext, BSTempEffectSimpleDecal
#ifndef FNV_ORIGINAL_BSTEMPEFFECTSIMPLEDECAL_H
#define FNV_ORIGINAL_BSTEMPEFFECTSIMPLEDECAL_H


// Authored declarations for the BSTempEffectSimpleDecal unit. The canonical
// generated headers do not yet carry every member this unit calls, so this
// header keeps the translation unit self-contained. Canonical additions
// requested from the operator:
//   - NiPoint3.h: the three-float constructor and
//     NiPoint3 Cross(const NiPoint3&) const.
//   - the shared NiPointer template: operator T*() const and the out-of-line
//     assignment operator used by engine pointer members.
//   - a canonical generated BSTempEffectSimpleDecal.h layout once more of the
//     class is reconstructed.
// Enumerators and member names mirror the canonical generated declarations.

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
    MEM_CONTEXT_MEM_CONTEXT_LODTREES = 37,
    MEM_CONTEXT_MEM_CONTEXT_SHADERS = 38,
    MEM_CONTEXT_MEM_CONTEXT_IMAGE_SPACE = 39,
    MEM_CONTEXT_MEM_CONTEXT_HAIRSHADER = 40,
    MEM_CONTEXT_MEM_CONTEXT_PRECIPITATION = 41,
    MEM_CONTEXT_MEM_CONTEXT_PROCESSES = 42,
    MEM_CONTEXT_MEM_CONTEXT_COMBAT_AI = 43,
    MEM_CONTEXT_MEM_CONTEXT_GLOBAL_LISTS = 44,
    MEM_CONTEXT_MEM_CONTEXT_PATHING = 45,
    MEM_CONTEXT_MEM_CONTEXT_NAVMESH = 46,
    MEM_CONTEXT_MEM_CONTEXT_TES_DEFAULT_OBJECTS = 47,
    MEM_CONTEXT_MEM_CONTEXT_TES_FORMS = 48,
    MEM_CONTEXT_MEM_CONTEXT_TES_REFERENCES = 49,
    MEM_CONTEXT_MEM_CONTEXT_TES_ACTOR = 50
};

class NiPoint3
{
  public:
    float x;  // +0x0
    float y;  // +0x4
    float z;  // +0x8
    NiPoint3(float xPos, float yPos, float zPos);
    NiPoint3 Cross(const NiPoint3& point) const;
};

// Shared engine pointer template. Assignment and conversion stay out of line;
// the PC engine bodies are separate functions, not inlined template code.
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* pObject = 0);
    ~NiPointer();
    operator T*() const;
    NiPointer& operator=(T* pObject);
};

// Asynchronous file task recorded by the engine RTTI as QueuedFile (0x28
// bytes, IOTask base). The construction argument is the IO priority byte.
// The engine task fields live behind the declared storage; the constructor
// itself stays external to this unit.
class QueuedFile
{
  public:
    QueuedFile(int ioPriority);
    virtual ~QueuedFile();

  private:
    unsigned char taskStorage[0x24];
};

class AutoMemContext
{
  public:
    MEM_CONTEXT m_eMemoryContext;  // +0x0
    AutoMemContext(MEM_CONTEXT context, bool track, const char* file, int line);
    ~AutoMemContext();
};

class BSTempEffectSimpleDecal
{
  public:
    static void QueueDecalDataFile();

  protected:
    static NiPointer<QueuedFile> ms_pPreloadDecalDataFile;
};

#endif
