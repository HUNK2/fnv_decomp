// Unit-local PC header for fallout_shared/tessound.cpp.
// TESSound below is the PC layout inferred from codegen:
//   +0x00..0x2F first base (TESBoundAnimObject, 48 bytes)
//   +0x30..0x3B second base (TESSoundFile: vtable + BSString, 12 bytes)
//   +0x3C..0x43 filename BSString member (8 bytes)
//   +0x68 m_cSoundFlag
#ifndef FNV_TESSOUND_UNIT_H
#define FNV_TESSOUND_UNIT_H

#include "layout_support.h"
#include "TESForm.h"
#include "TESFile.h"
// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_TESSOUND_SOUND_DATA_H
#define FNV_TESSOUND_SOUND_DATA_H
class TESSound__SOUND_DATA;
#pragma pack(push, 4)
class TESSound__SOUND_DATA
{
  public:
    unsigned char iMin;                       // +0x0, 1 bytes
    unsigned char iMax;                       // +0x1, 1 bytes
    char m_cPitchAdjustment;                  // +0x2, 1 bytes
    unsigned char m_ucUnused;                 // +0x3, 1 bytes
    unsigned int iFlags;                      // +0x4, 4 bytes
    unsigned short m_uiFrequency;             // +0x8, 2 bytes
    unsigned short m_aucAttenuationBytes;     // +0xA, 2 bytes
    unsigned short m_auiAttenuationCurve[5];  // +0xC, 10 bytes
    unsigned short m_uiReverbAttenuation;     // +0x16, 2 bytes
    unsigned int iPriority;                   // +0x18, 4 bytes
    unsigned int m_uiTrailingValue1;          // +0x1C, 4 bytes
    unsigned int m_uiTrailingValue2;          // +0x20, 4 bytes
    void Endian();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESSound__SOUND_DATA) == 36);
FNV_STATIC_ASSERT(offsetof(TESSound__SOUND_DATA, iMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESSound__SOUND_DATA, iMax) == 1);
FNV_STATIC_ASSERT(offsetof(TESSound__SOUND_DATA, m_cPitchAdjustment) == 2);
FNV_STATIC_ASSERT(offsetof(TESSound__SOUND_DATA, m_ucUnused) == 3);
FNV_STATIC_ASSERT(offsetof(TESSound__SOUND_DATA, iFlags) == 4);
FNV_STATIC_ASSERT(offsetof(TESSound__SOUND_DATA, m_uiFrequency) == 8);
FNV_STATIC_ASSERT(offsetof(TESSound__SOUND_DATA, m_aucAttenuationBytes) == 10);
FNV_STATIC_ASSERT(offsetof(TESSound__SOUND_DATA, m_auiAttenuationCurve) == 12);
FNV_STATIC_ASSERT(offsetof(TESSound__SOUND_DATA, m_uiReverbAttenuation) == 22);
FNV_STATIC_ASSERT(offsetof(TESSound__SOUND_DATA, iPriority) == 24);
FNV_STATIC_ASSERT(offsetof(TESSound__SOUND_DATA, m_uiTrailingValue1) == 28);
FNV_STATIC_ASSERT(offsetof(TESSound__SOUND_DATA, m_uiTrailingValue2) == 32);
#endif
// Unit-local copy of the 12-byte legacy SNDX sound header (first fields of
// it, then copies the fields into data.
#pragma pack(push, 4)
class TESSound__SOUND_DATA2
{
  public:
    unsigned char iMin;                    // +0x0
    unsigned char iMax;                    // +0x1
    char m_cPitchAdjustment;               // +0x2
    unsigned char m_ucUnused;              // +0x3
    unsigned int iFlags;                   // +0x4
    unsigned short m_uiFrequency;          // +0x8
    unsigned short m_aucAttenuationBytes;  // +0xA
    void Endian();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESSound__SOUND_DATA2) == 12);
// The 2008 TESSound.cpp saw a 32-bit TESFile::GetTESForm: the Load form
// check compares the call result with cmp eax,imm and no movzx, which is
// unreproducible through the closure's unsigned char declaration (any use of
// a uchar call result in a 32-bit compare extends it). The shim below recovers
// the original static type; it binds the real GetTESForm target.
struct TESFileFormInt : public TESFile
{
    int GetTESForm();
};
// Zero-size tag used to select the 16-bit overload below. The tag is passed
// as a value-initialized temporary, which is why each call site materializes
// a zero byte on the stack.
template <int Value> struct EndianSizeTag
{
};
void BSEndian(unsigned short* data, EndianSizeTag<2> type);
#pragma pack(push, 4)
// Unit-local scaffolding for the TESSound bases. TESBoundAnimObject derives
// from TESForm through TESObject/TESBoundObject on PC; the intermediate
// members live in the padding below. Only sizes, polymorphism and the
// constructor matter for this unit's codegen.
// ReadTypedData is the canonical TESForm::ReadTypedData(TESFile*, void*, unsigned short)
// chunk reader; it is declared on the scaffold base because the task closure
// TESForm.h does not declare it.
class TESBoundAnimObject : public TESForm
{
  public:
    virtual ~TESBoundAnimObject();
    unsigned char layoutPadding18[0x18];
    TESBoundAnimObject();
    void ReadTypedData(TESFile* file, void* buffer, unsigned short size);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundAnimObject) == 0x30);
// TESSoundFile is vtable + sound-path string (12 bytes); its constructor
// builds the string, matching the observed subobject construction.
// SetSoundFile is the real filename virtual called by the FNAM chunk handler
// through the second vtable (slot 4, first new virtual after the four
// BaseFormComponent slots).
#pragma pack(push, 4)
class TESSoundFile : public BaseFormComponent
{
  public:
    virtual void SetSoundFile(const char* fileName);
    virtual ~TESSoundFile();
    BSStringT<char> m_kSoundFile;  // +0x4
    TESSoundFile();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESSoundFile) == 0xC);
FNV_STATIC_ASSERT(offsetof(TESSoundFile, m_kSoundFile) == 0x4);
#pragma pack(push, 4)
class TESSound : public TESBoundAnimObject, public TESSoundFile
{
  public:
    BSStringT<char> cFileName;  // +0x3C, second filename string
    TESSound__SOUND_DATA data;  // +0x44, 36 bytes
    char m_cSoundFlag;          // +0x68, 1 byte
    unsigned char layoutPadding69[3];
    TESSound();
    void ResetFormData();
    static void InitializeMagicSystem();
    bool Load(TESFile* file);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESSound) == 0x6C);
FNV_STATIC_ASSERT(offsetof(TESSound, data) == 0x44);
FNV_STATIC_ASSERT(offsetof(TESSound, m_cSoundFlag) == 0x68);
// MEM_CONTEXT as in include/layout_support.h (the unit-local layout_support.h in this directory, which wine resolves
// first, does not declare it).
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
    MEM_CONTEXT_MEM_CONTEXT_TES_ACTOR = 50,
    MEM_CONTEXT_MEM_CONTEXT_ANIMATION = 51,
    MEM_CONTEXT_MEM_CONTEXT_PLAYER = 52,
    MEM_CONTEXT_MEM_CONTEXT_DIALOGUE = 53,
    MEM_CONTEXT_MEM_CONTEXT_INVENTORY = 54,
    MEM_CONTEXT_MEM_CONTEXT_FACEGEN_SYSTEM = 55,
    MEM_CONTEXT_MEM_CONTEXT_FACEGEN_EGM = 56,
    MEM_CONTEXT_MEM_CONTEXT_FACEGEN_EGT = 57,
    MEM_CONTEXT_MEM_CONTEXT_FACEGEN_GEOM = 58,
    MEM_CONTEXT_MEM_CONTEXT_UNKNOWN = 59,
    MEM_CONTEXT_MEM_CONTEXT_UNKNOWN_DIRECTX = 60,
    MEM_CONTEXT_MEM_CONTEXT_DEBUG_CONTEXT_A = 61,
    MEM_CONTEXT_MEM_CONTEXT_DEBUG_CONTEXT_B = 62,
    MEM_CONTEXT_MEM_CONTEXT_DEBUG_CONTEXT_C = 63,
    MEM_CONTEXT_MEM_CONTEXT_DEBUG_CONTEXT_D = 64,
    MEM_CONTEXT_MEM_CONTEXT_TOTAL = 65,
    MEM_CONTEXT_MEM_CONTEXT_DEFAULT = 65,
    MEM_CONTEXT_MEM_CONTEXT_COUNT = 66,
};
// Canonical AutoMemContext declaration (decomp/include/AutoMemContext.h),
// repeated here because the task include closure does not bundle it.
#pragma pack(push, 4)
class AutoMemContext
{
  public:
    MEM_CONTEXT m_eMemoryContext;  // +0x0
    AutoMemContext(MEM_CONTEXT context, bool track, const char* file, int line);
    ~AutoMemContext();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(AutoMemContext) == 0x4);
FNV_STATIC_ASSERT(offsetof(AutoMemContext, m_eMemoryContext) == 0x0);
#endif
