// Unit-local header for fallout_shared/bgstextureset.cpp.
// Class layouts (TESObject through BGSTextureSet) are copied verbatim from
// the PC object is 0xA0 bytes (InitializeNullTextureSet operator new) with 6
// texture slots, a DecalData* at +0x80, flags at +0x84 and 6 file entries at
// +0x88 (ResetFormData/ClearData/Load all loop 6). Real method declarations
#ifndef FNV_BGSTEXTURESET_UNIT_H
#define FNV_BGSTEXTURESET_UNIT_H

#include "layout_support.h"
#include "BaseFormComponent.h"
#include "TESForm.h"
#include "TESTexture.h"

class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
};
class NiObject : public NiMemObject
{
  public:
    virtual ~NiObject();
    virtual void DeleteThis();
    unsigned int refs;
};

class BGSTextureSet;
class BSFileEntry;
class BSTextureSet;
class DecalData;
class ShortPoint3;
class TESBoundObject__BOUND_DATA;
class TESFormList;
class QueuedFile;

#pragma pack(push, 4)
class ShortPoint3
{
  public:
    short x;  // +0x0, 2 bytes
    short y;  // +0x2, 2 bytes
    short z;  // +0x4, 2 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ShortPoint3) == 6);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, x) == 0);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, y) == 2);
FNV_STATIC_ASSERT(offsetof(ShortPoint3, z) == 4);

#pragma pack(push, 4)
class TESBoundObject__BOUND_DATA
{
  public:
    ShortPoint3 m_kBoundMin;  // +0x0, 6 bytes
    ShortPoint3 m_kBoundMax;  // +0x6, 6 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject__BOUND_DATA) == 12);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMin) == 0);
FNV_STATIC_ASSERT(offsetof(TESBoundObject__BOUND_DATA, m_kBoundMax) == 6);

#pragma pack(push, 4)
class TESObject : public TESForm
{
  public:
    // base TESForm at +0x0, size 24
    TESFormList* m_pOwningList;    // +0x18, 4 bytes
    TESObject* m_pPreviousObject;  // +0x1C, 4 bytes
    TESObject* m_pNextObject;      // +0x20, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESObject) == 36);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pOwningList) == 24);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pPreviousObject) == 28);
FNV_STATIC_ASSERT(offsetof(TESObject, m_pNextObject) == 32);

#pragma pack(push, 4)
class TESBoundObject : public TESObject
{
  public:
    // base TESObject at +0x0, size 36
    TESBoundObject__BOUND_DATA TESBoundObjectBounds;  // +0x24, 12 bytes

    TESBoundObject();
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(TESBoundObject) == 48);
FNV_STATIC_ASSERT(offsetof(TESBoundObject, TESBoundObjectBounds) == 36);

#pragma pack(push, 4)
class BSTextureSet : public NiObject
{
  public:
    // base NiObject at +0x0, size 8
    BSTextureSet();
    virtual const char* GetTextureFilePath(int aeTextureType);
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BSTextureSet) == 8);

// TESTexture has a non-trivial constructor/destructor (0x0048e270/0x0048e2e0)
// and a texture-name getter (0x00408da0) not declared in the bundled
// TESTexture.h; declared here on a shim following the accepted
// TESTextureLoader precedent in tescasinochips.h. The texture slots use this
// shim so the constructor emits the array construction iterator.
struct BGSTESTexture : public TESTexture
{
    BGSTESTexture();
    ~BGSTESTexture();
    const char* GetTextureResourceName();
};

// Texture slots on PC (see note above).
#pragma pack(push, 4)
class BGSTextureSet : public TESBoundObject, public BSTextureSet
{
  public:
    // base TESBoundObject at +0x0, size 48
    // base BSTextureSet at +0x30, size 8
    BGSTESTexture pTextures[6];  // +0x38, 72 bytes
    DecalData* m_pDecalData;     // +0x80, 4 bytes
    unsigned short iFlags;       // +0x84, 2 bytes
    unsigned char layoutPadding86[2];
    BSFileEntry* m_ppTextureFileEntries[6];  // +0x88, 24 bytes

    BGSTextureSet();
    virtual bool Load(TESFile*);
    void ResetFormData();
    virtual void ClearData();
    virtual const char* GetTextureFilePath(int aeTextureType);
    void LoadTextures(int aePriority, QueuedFile* apQueuedFile, bool abLoad);
    static BGSTextureSet* GetEmptyTextureSet();
    static void InitializeNullTextureSet();

    static BGSTextureSet* s_pNullTextureSet;
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(BGSTextureSet) == 0xA0);
FNV_STATIC_ASSERT(offsetof(BGSTextureSet, pTextures) == 56);
FNV_STATIC_ASSERT(offsetof(BGSTextureSet, m_pDecalData) == 128);
FNV_STATIC_ASSERT(offsetof(BGSTextureSet, iFlags) == 132);
FNV_STATIC_ASSERT(offsetof(BGSTextureSet, m_ppTextureFileEntries) == 136);

// DecalData::`scalar deleting destructor' (0x007b3fa0); layout copied
#pragma pack(push, 4)
class ImpactDecalData
{
  public:
    float m_fDecalMinWidth;            // +0x0, 4 bytes
    float m_fDecalMaxWidth;            // +0x4, 4 bytes
    float m_fDecalMinHeight;           // +0x8, 4 bytes
    float m_fDecalMaxHeight;           // +0xC, 4 bytes
    float m_fProjectionDepth;          // +0x10, 4 bytes
    float m_fShininess;                // +0x14, 4 bytes
    float m_fParallaxScale;            // +0x18, 4 bytes
    unsigned char m_ucParallaxPasses;  // +0x1C, 1 bytes
    unsigned char cFlags;              // +0x1D, 1 bytes
    unsigned char layoutPadding1E[2];
    unsigned int iColor;  // +0x20, 4 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(ImpactDecalData) == 36);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fDecalMinWidth) == 0);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fDecalMaxWidth) == 4);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fDecalMinHeight) == 8);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fDecalMaxHeight) == 12);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fProjectionDepth) == 16);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fShininess) == 20);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_fParallaxScale) == 24);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, m_ucParallaxPasses) == 28);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, cFlags) == 29);
FNV_STATIC_ASSERT(offsetof(ImpactDecalData, iColor) == 32);
#pragma pack(push, 4)
class DecalData
{
  public:
    DecalData();
    bool Load(TESFile*);
    ImpactDecalData Data;  // +0x0, 36 bytes
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(DecalData) == 36);
FNV_STATIC_ASSERT(offsetof(DecalData, Data) == 0);
struct DecalDataDeleter : public DecalData
{
    void* DeleteThis(int aiFlag);
};

// ModelLoader queue call (0x00443af0) on the global at 0x011c3b3c.
struct ModelLoader
{
    void QueueTextureFile(BSFileEntry* apEntry, int aePriority, QueuedFile* apQueuedFile);
};
extern ModelLoader* g_pModelLoader;

// Bethesda memset (0x00403d30).
void* FillBytes(void* apDst, int aiValue, unsigned int auSize);

struct TESDataHandlerForms
{
    void AddFormToDataHandler(TESForm*);
};
class TESDataHandler;
extern TESDataHandler* g_dataHandler;

void* operator new(unsigned int);
void operator delete(void*);
struct TESFileChunkData16
{
    bool GetChunkData(unsigned short*);
};
struct TESTextureLoader
{
    static void ReadTextureData(TESTexture*, TESFile*);
};
struct TaskQueueInterface
{
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
int strcat_s(char*, unsigned int, const char*);
bool CleanPath(const char*, char*, unsigned int);
class FileNameHash;
class NiPoint2
{
  public:
    unsigned char last, last2, length, first;
    unsigned int crc;
    NiPoint2();
};
class FileNameHash
{
  public:
    static void CreateDirectoryAndFileHashes(const char*, FileNameHash&, FileNameHash&);
};
enum ArchiveType
{
    ARCHIVE_TEXTURES = 1
};
struct ArchiveManager
{
    static BSFileEntry* FindFileEntry(ArchiveType, FileNameHash&, FileNameHash&, const char*);
};
#endif
