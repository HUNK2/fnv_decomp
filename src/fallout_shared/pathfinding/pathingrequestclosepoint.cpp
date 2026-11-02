
// src/fallout_shared/pathfinding/pathingrequestclosepoint.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestclosepoint.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct PathingRequest
{
    char* m_Name;
    PathingRequest();
};

extern float g_011c7b14_arg1;

struct FUN_006e3f30 : PathingRequest
{
    float fPointHeight;
    float m_fUnknownValue2;
    FUN_006e3f30();
};

PathingRequest::PathingRequest()
{}

// Initializes the PathingRequest base and sets the name to "p?n" plus two float fields at offsets 0xb0 and 0xb4.
// @fnv 0x006e3f30
FUN_006e3f30::FUN_006e3f30() : PathingRequest()
{
    m_Name = "p?n";
    *(float*)((char*)this + 0xb0) = 128.0f;
    *(float*)((char*)this + 0xb4) = g_011c7b14_arg1;
}

struct PathingRequestClosePoint
{
    virtual ~PathingRequestClosePoint();
    static void __cdecl operator delete(void* p, unsigned int flags);
    void* __thiscall FUN_006e3f70(unsigned int flags);
};

// Runs the destructor and, when bit 0 of flags is set, frees the object with operator delete; returns this.
// @fnv 0x006e3f70
void* __thiscall PathingRequestClosePoint::FUN_006e3f70(unsigned int flags)
{
    this->PathingRequestClosePoint::~PathingRequestClosePoint();
    if (flags & 1)
        PathingRequestClosePoint::operator delete(this, 0xb8);
    return this;
}

namespace fnv_006e5f00 {
struct BGSSaveFormBuffer
{
    void __thiscall SaveData(void* pData, int a2, int a3);
};

struct PathingRequest
{
    void __thiscall FUN_006e3230(BGSSaveFormBuffer* apSaveGameBuffer);
};

struct PathingRequestClosePoint : PathingRequest
{
    void __thiscall FUN_006e5f00(BGSSaveFormBuffer* apSaveGameBuffer);
};

// Calls the base save routine, then writes the 4-byte values at offsets 0xb0 and 0xb4 to the save buffer.
// @fnv 0x006e5f00
void __thiscall PathingRequestClosePoint::FUN_006e5f00(BGSSaveFormBuffer* apSaveGameBuffer)
{
    FUN_006e3230(apSaveGameBuffer);
    apSaveGameBuffer->SaveData((char*)this + 0xb0, 4, 0);
    apSaveGameBuffer->SaveData((char*)this + 0xb4, 4, 0);
}
}  // namespace fnv_006e5f00

namespace fnv_006e5f50 {
struct BGSLoadFormBuffer;

struct PathingRequest
{
    void LoadGame(BGSLoadFormBuffer* apLoadGameBuffer);
};

struct BGSLoadFormBuffer
{
    void ReadTypedData(void* data, unsigned int size);
};

struct PathingRequestClosePoint : PathingRequest
{
    PathingRequestClosePoint();
    void FUN_006e5f50(BGSLoadFormBuffer* apLoadGameBuffer);
};

// Calls the base PathingRequest::LoadGame, then reads two 4-byte values from the buffer into fields at offsets 0xb0 and 0xb4.
// @fnv 0x006e5f50
void PathingRequestClosePoint::FUN_006e5f50(BGSLoadFormBuffer* apLoadGameBuffer)
{
    PathingRequest::LoadGame(apLoadGameBuffer);
    apLoadGameBuffer->ReadTypedData(this + 0xb0, 4);
    apLoadGameBuffer->ReadTypedData(this + 0xb4, 4);
}
}  // namespace fnv_006e5f50

struct PathingRequestCopyHelper
{
    void __thiscall CopyTo(PathingRequest*);
};
struct SetterA
{
    void __thiscall FUN_00507610(float);
};
struct SetterB
{
    void __thiscall FUN_006e5ee0(float);
};
struct FUN_006e4030_This
{
    char _pad[0xB0];
    float fPointHeight;
    float m_fUnknownValue2;
    void __thiscall CopyToWithClosePoint(PathingRequest* apDest);
};
// @fnv 0x006e4030
void __thiscall FUN_006e4030_This::CopyToWithClosePoint(PathingRequest* apDest)
{
    PathingRequestClosePoint* pdest = (PathingRequestClosePoint*)apDest;
    ((PathingRequestCopyHelper*)this)->CopyTo((PathingRequest*)pdest);
    ((SetterA*)pdest)->FUN_00507610(this->fPointHeight);
    ((SetterB*)pdest)->FUN_006e5ee0(this->m_fUnknownValue2);
}

struct PathBase_b5729
{
    char* m_00;
    PathBase_b5729(void* src);
    ~PathBase_b5729();
};

struct SrcArg_b5729
{
    float GetMinDist();
    float GetMaxDist();
};

struct FUN_006e3fb0_cls : PathBase_b5729
{
    FUN_006e3fb0_cls(SrcArg_b5729* src);
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
    float m_b0;
    float m_b4;
};

// Initializes the path base from src, sets m_00 to "p?n", and stores src's min and max distances into m_b0 and m_b4.
// @fnv 0x006e3fb0
FUN_006e3fb0_cls::FUN_006e3fb0_cls(SrcArg_b5729* src) : PathBase_b5729(src)
{
    m_00 = (char*)"p?n";
    m_b0 = src->GetMinDist();
    m_b4 = src->GetMaxDist();
}
