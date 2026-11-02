
// src/fallout_shared/pathfinding/pathingrequestflee.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestflee.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct PathingRequest
{
    ~PathingRequest();
    static void operator delete(void* p, unsigned int size);
};

struct PathingRequestFlee : PathingRequest
{
    PathingRequestFlee();
    ~PathingRequestFlee();
    void* DestroyAndFree(unsigned int flags);
};

// Destructs the PathingRequest base and, when flags has bit 0 set, frees this with size 0xb4; returns this.
// @fnv 0x006e53c0
void* PathingRequestFlee::DestroyAndFree(unsigned int flags)
{
    this->PathingRequest::~PathingRequest();
    if (flags & 1)
        PathingRequest::operator delete(this, 0xb4);
    return this;
}

namespace fnv_006e54b0 {
struct BGSSaveFormBuffer
{
    void SaveData(void* a1, int a2, int a3);
};

struct PathingRequest
{
    void SaveGame(BGSSaveFormBuffer* apSaveGameBuffer);
};

struct FUN_006e54b0_shell : PathingRequest
{
    void FUN_006e54b0(BGSSaveFormBuffer* apSaveGameBuffer);
};

// Calls PathingRequest::SaveGame and then writes 4 bytes from this+0xb0 into the save buffer.
// @fnv 0x006e54b0
void FUN_006e54b0_shell::FUN_006e54b0(BGSSaveFormBuffer* apSaveGameBuffer)
{
    PathingRequest::SaveGame(apSaveGameBuffer);
    apSaveGameBuffer->SaveData(this + 0xb0, 4, 0);
}
}  // namespace fnv_006e54b0

struct BGSLoadFormBuffer
{
    void ReadTypedData(void* p, unsigned int size);
};

struct PathingRequestLoadGameHelper
{
    void LoadGame(BGSLoadFormBuffer* buffer);
};

struct PathingRequestFlee;

struct PathingRequestFleeShell : PathingRequestFlee
{
    void FUN_006e54e0(BGSLoadFormBuffer* apLoadGameBuffer);
};

// Loads the base game state from the buffer, then reads 4 bytes into the field at offset 0xb0.
// @fnv 0x006e54e0
void PathingRequestFleeShell::FUN_006e54e0(BGSLoadFormBuffer* apLoadGameBuffer)
{
    ((PathingRequestLoadGameHelper*)this)->LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData((void*)((char*)this + 0xb0), 4);
}

extern int DAT_0106d300;
struct PathingRequestHelper
{
    PathingRequestHelper();
};
struct FUN_006e5390 : PathingRequestHelper
{
    FUN_006e5390();
};
struct FUN_006e5390_Off
{
    char pad[0xb0];
    float f;
};
// Sets the vtable pointer to DAT_0106d300 and stores 128.0f at offset 0xb0 of this object.
// @fnv 0x006e5390
FUN_006e5390::FUN_006e5390()
{
    *(void**)this = (void*)&DAT_0106d300;
    ((FUN_006e5390_Off*)this)->f = 128.0f;
}

namespace fnv_006e5470 {
struct PathingRequest
{
    void CopyTo(PathingRequest*);
};

struct PathingRequestFlee : PathingRequest
{
    char _pad[0xb0];
    float m_fFleeDistance;
    void CopyToWithFleeData(PathingRequest*);
};

// @fnv 0x006e5470
void PathingRequestFlee::CopyToWithFleeData(PathingRequest* apDest)
{
    PathingRequest* pdest = apDest;
    PathingRequest::CopyTo(pdest);
    ((PathingRequestFlee*)pdest)->m_fFleeDistance = m_fFleeDistance;
}
}  // namespace fnv_006e5470

class C6E5400Request
{
  public:
    float GetGoalRadius() const;
};

class C6E5400Base
{
  public:
    C6E5400Base(C6E5400Request* pkRequest);
    virtual ~C6E5400Base();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
};

class FUN_006e5400 : public C6E5400Base
{
  public:
    FUN_006e5400(C6E5400Request* pkRequest);
    virtual ~FUN_006e5400();

    float m_fGoalRadius;
};

// Constructs the base from pkRequest and stores pkRequest->GetGoalRadius() into m_fGoalRadius.
// @fnv 0x006e5400
FUN_006e5400::FUN_006e5400(C6E5400Request* pkRequest) : C6E5400Base(pkRequest)
{
    m_fGoalRadius = pkRequest->GetGoalRadius();
}
