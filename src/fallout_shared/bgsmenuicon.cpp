// fallout_shared/bgsmenuicon.cpp: BGSMenuIcon (6 functions)

#include "TESForm.h"
#include "TESFile.h"
#include "TESIcon.h"
#include <malloc.h>

class BGSMenuIcon : public TESForm
{
  public:
    TESIcon icon;
    bool Load(TESFile* file);
};

class TESTextureLoader
{
  public:
    static void ReadTextureData(TESTexture* texture, TESFile* file);
};

struct ChunkLoadState
{
    char* chunkData;
    unsigned int chunkID;
};

// Checks the form type is 5, loads the record header, then reads EDID, OBND and ICON chunks until no chunk remains.
// @fnv 0x00590350
bool BGSMenuIcon::Load(TESFile* file)
{
    unsigned char formType;
    ChunkLoadState chunkState;

    formType = file->GetTESForm();
    if (formType != 5)
        return false;

    LoadRecordHeader(file);
    while ((chunkState.chunkID = file->GetChunkID()) != 0)
    {
        switch (chunkState.chunkID)
        {
        case 0x44494445:
            chunkState.chunkData = (char*)_alloca(file->GetChunkSize());
            file->GetChunkData(chunkState.chunkData, 0x200);
            SetEditorID_AtRuntime(chunkState.chunkData);
            break;
        case 0x444e424f:
            readOBNDSubRecord(file);
            break;
        case 0x4e4f4349:
            TESTextureLoader::ReadTextureData(this ? static_cast<TESTexture*>(&icon) : 0, file);
            break;
        }

        if (!file->NextChunk())
            break;
    }
    return true;
}

struct FUN_005902a0_Class
{
    void FUN_005902d0();
    void* Release(unsigned int flags);
};

// Calls FUN_005902d0, then deletes this if flags has bit 0 set, and returns this.
// @fnv 0x005902a0
void* FUN_005902a0_Class::Release(unsigned int flags)
{
    FUN_005902d0();
    if (flags & 1)
        operator delete(this);
    return this;
}

void __fastcall FUN_00483710(void* p);

struct FUN_00483630_holder
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    virtual ~FUN_00483630_holder();
};

struct FUN_005902d0 : FUN_00483630_holder, TESIcon
{
    virtual ~FUN_005902d0();
};

// Destructor for FUN_005902d0 that calls FUN_00483710 on this.
// @fnv 0x005902d0
FUN_005902d0::~FUN_005902d0()
{
    FUN_00483710(this);
}

struct FUN_004855a0_shell
{
    void M();
};
struct FUN_00485680_shell
{
    void M();
};
struct FUN_0048e370_obj
{
    void FUN_0048e370(unsigned int);
};
struct FUN_00509280_obj
{
    void FUN_004855a0();
    void FUN_0048e370(unsigned int);
    void FUN_00485680();
    void FUN_00590470();
};
// @fnv 0x00590470
void FUN_00509280_obj::FUN_00590470()
{
    ((FUN_004855a0_shell*)this)->M();
    ((FUN_0048e370_obj*)((char*)this + 0x18))->FUN_0048e370(0x4e4f4349);
    ((FUN_00485680_shell*)this)->M();
}

extern const void* DAT_01183028;
struct FUN_005e78f0_t
{
    void FUN_004851b0(TESForm*);
};
struct FUN_005904a0_shell
{
    void FUN_004851b0(TESForm*);
    void FUN_005904a0(TESForm* form);
};
// Casts the TESForm to BGSMenuIcon and calls FUN_004851b0 on it if the cast succeeds.
// @fnv 0x005904a0
void FUN_005904a0_shell::FUN_005904a0(TESForm* form)
{
    BGSMenuIcon* icon = dynamic_cast<BGSMenuIcon*>(form);
    if (!icon)
        return;
    FUN_004851b0(icon);
}

struct FUN_005e79a0_t
{
    bool FUN_00485270(TESForm* apCompare);
};
struct FUN_005904e0_s
{
    bool FUN_005904e0(TESForm* apCompare);
};
// Returns true if apCompare is not a BGSMenuIcon or the base comparison returns true.
// @fnv 0x005904e0
bool FUN_005904e0_s::FUN_005904e0(TESForm* apCompare)
{
    BGSMenuIcon* pcomp = dynamic_cast<BGSMenuIcon*>(apCompare);
    if (!pcomp)
        return true;
    if (((FUN_005e79a0_t*)this)->FUN_00485270(pcomp))
        return true;
    return false;
}
