
// src/fallout_shared/pathfinding/pathingrequesthide.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequesthide.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void __cdecl _delete(void*, unsigned int);

struct PathingRequestHide
{
    virtual ~PathingRequestHide();
    void* Destroy(unsigned int flags);
};

// Runs the destructor and, when flags has bit 0 set, frees the object with _delete; returns this.
// @fnv 0x006e55a0
void* PathingRequestHide::Destroy(unsigned int flags)
{
    this->PathingRequestHide::~PathingRequestHide();
    if (flags & 1)
        _delete(this, 0xdc);
    return this;
}

struct FUN_006e2620
{
    ~FUN_006e2620();
    char _pad[0xB0];
};
struct _Mem_2064
{
    ~_Mem_2064();
};
struct FUN_006e55e0 : FUN_006e2620
{
    _Mem_2064 _m;
    ~FUN_006e55e0();
};
// Destroys the object, running the base destructor and the destructor of the embedded member.
// @fnv 0x006e55e0
FUN_006e55e0::~FUN_006e55e0()
{}

struct BGSSaveFormBuffer
{
    void SaveData(void*, int, int);
};
struct StandIn5740
{
    void FUN_006e3230(BGSSaveFormBuffer*);
    void FUN_006e5740(BGSSaveFormBuffer*);
};
struct ThreatLocStandIn
{
    virtual void SaveGame(BGSSaveFormBuffer*);
};
// Calls FUN_006e3230, saves the object at offset 0xB0, then writes 4 bytes from offset 0xD8 to the save buffer.
// @fnv 0x006e5740
void StandIn5740::FUN_006e5740(BGSSaveFormBuffer* apSaveGameBuffer)
{
    FUN_006e3230(apSaveGameBuffer);
    ((ThreatLocStandIn*)((char*)this + 0xB0))->SaveGame(apSaveGameBuffer);
    apSaveGameBuffer->SaveData((void*)((char*)this + 0xD8), 4, 0);
}

struct BGSLoadFormBuffer
{
    void ReadTypedData(void*, unsigned int);
};
struct PathingRequest
{
    char _pad[0xB0];
    void LoadGame(BGSLoadFormBuffer*);
};
struct PathingLocation
{
    virtual void Dummy();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
struct MyHide : PathingRequest
{
    PathingLocation m_kHideLocation;
    char _pad2[0x24];
    int unkD8;
    void FUN_006e5790(BGSLoadFormBuffer*);
};
// Loads the base PathingRequest and the embedded PathingLocation from the buffer, then reads 4 bytes into unkD8.
// @fnv 0x006e5790
void MyHide::FUN_006e5790(BGSLoadFormBuffer* apLoadGameBuffer)
{
    PathingRequest::LoadGame(apLoadGameBuffer);
    m_kHideLocation.LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData(&unkD8, 4);
}

namespace fnv_006e56f0 {
struct PathingLocation
{
    PathingLocation& operator=(const PathingLocation&);
};

struct PathingRequest
{
    void CopyTo(PathingRequest* apDest);
};

struct PathingRequestHide : PathingRequest
{
    unsigned char pad0[0xb0];
    PathingLocation m_Location;
    float m_fHideDistance;
    unsigned char pad1[0x24];
    void FUN_006e56f0(PathingRequest* apDest);
};

// Copies the base PathingRequest, then copies m_Location and the float at offset 0xd8 into the destination.
// @fnv 0x006e56f0
void PathingRequestHide::FUN_006e56f0(PathingRequest* apDest)
{
    PathingRequestHide* pdest = static_cast<PathingRequestHide*>(apDest);
    PathingRequest::CopyTo(pdest);
    pdest->m_Location = m_Location;
    *reinterpret_cast<float*>(reinterpret_cast<char*>(pdest) + 0xd8) =
        *reinterpret_cast<float*>(reinterpret_cast<char*>(this) + 0xd8);
}
}  // namespace fnv_006e56f0

class B6E5640Location
{
  public:
    int unk000;
    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;

    B6E5640Location();
    ~B6E5640Location();
    B6E5640Location& operator=(const B6E5640Location& kOther);
};

class B6E5640Actor
{
  public:
    B6E5640Location* FUN_00984230();
    float FUN_00885bd0();
};

struct B6E5640Path
{
    int unk00;

    void FUN_006d2c00();
};

class B6E5640Base
{
  public:
    B6E5640Base(B6E5640Actor* pkActor);
    virtual ~B6E5640Base();

    int unk004;
    int unk008;
    int unk00C;
    int unk010;
    int unk014;
    int unk018;
    int unk01C;
    int unk020;
    int unk024;
    int unk028;
    int unk02C;
    int unk030;
    B6E5640Path m_kPath;
    int unk038;
    int unk03C;
    int unk040;
    int unk044;
    int unk048;
    int unk04C;
    int unk050;
    int unk054;
    int unk058;
    int unk05C;
    int unk060;
    int unk064;
    int unk068;
    int unk06C;
    int unk070;
    int unk074;
    int unk078;
    int unk07C;
    int unk080;
    int unk084;
    int unk088;
    int unk08C;
    int unk090;
    int unk094;
    int unk098;
    int unk09C;
    int unk0A0;
    int unk0A4;
    int unk0A8;
    int unk0AC;
};

class FUN_006e5640 : public B6E5640Base
{
  public:
    B6E5640Location m_kLocation;
    int unk0D0;
    int unk0D4;
    float m_fBoundRadius;

    FUN_006e5640(B6E5640Actor* pkActor);
    virtual ~FUN_006e5640();
};

// @fnv 0x006e5640
FUN_006e5640::FUN_006e5640(B6E5640Actor* pkActor) : B6E5640Base(pkActor)
{
    m_kLocation = *pkActor->FUN_00984230();
    m_fBoundRadius = pkActor->FUN_00885bd0();
    m_kPath.FUN_006d2c00();
}
