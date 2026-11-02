
// src/fallout_shared/pathfinding/pathingrequestoptimallocation.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/pathfinding/pathingrequestoptimallocation.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct PathingRequest
{
    void __thiscall DestroyPathingRequest();
};

struct PathingRequestOptimalLocation : PathingRequest
{
    void* FUN_006e5d70(unsigned int flags);
};

extern void _delete(void* p, unsigned int size);

// @fnv 0x006e5d70
void* PathingRequestOptimalLocation::FUN_006e5d70(unsigned int flags)
{
    this->PathingRequest::DestroyPathingRequest();
    if (flags & 1)
        _delete(this, 0xc0);
    return this;
}

namespace fnv_006e5d10 {
struct PathingRequest
{
    char* m_szName;
    PathingRequest(void);
};

extern float g_011c7b14_arg1;

struct FUN_006e5d10 : PathingRequest
{
    char pad[0x0b0 - 0x004];
    float fPointHeight;
    float m_fUnknownValue2;
    float m_fUnknownValue3;
    float m_fUnknownValue4;
    FUN_006e5d10();
};

// Initializes the PathingRequest base, sets m_szName to "p]n" and stores 128.0f and g_011c7b14_arg1 into four float fields.
// @fnv 0x006e5d10
FUN_006e5d10::FUN_006e5d10() : PathingRequest()
{
    m_szName = "p]n";
    fPointHeight = 128.0f;
    m_fUnknownValue2 = g_011c7b14_arg1;
    m_fUnknownValue3 = 128.0f;
    m_fUnknownValue4 = g_011c7b14_arg1;
}
}  // namespace fnv_006e5d10

namespace fnv_006e5e60 {
struct PathingRequest
{
    char pad[0xB0];
    void CopyTo(PathingRequest* apDest);
    void FUN_00507610(float fVal);
    void FUN_006e5ee0(float fVal);
    void FUN_006e4ef0(float fVal);
    void FUN_006e4320(float fVal);
};

struct PathingRequestOptimalLocation
{
    PathingRequest base;
    float fPointHeight;
    float m_fUnknownValue2;
    float m_fUnknownValue3;
    float m_fUnknownValue4;
    void FUN_006e5e60(PathingRequest* apDest);
};

// @fnv 0x006e5e60
void PathingRequestOptimalLocation::FUN_006e5e60(PathingRequest* apDest)
{
    PathingRequest* pdest = apDest;
    base.CopyTo(pdest);
    pdest->FUN_00507610(fPointHeight);
    pdest->FUN_006e5ee0(m_fUnknownValue2);
    pdest->FUN_006e4ef0(m_fUnknownValue3);
    pdest->FUN_006e4320(m_fUnknownValue4);
}
}  // namespace fnv_006e5e60

struct S_006e5db0_Src
{
    float GetFloatAtOffsetB0();
    float GetFieldB4Float();
    float GetFieldB8Float();
    float FUN_0099e040();
};
struct S_006e5db0_Base
{
    S_006e5db0_Base(S_006e5db0_Src* src);
    virtual ~S_006e5db0_Base();
    char pad[0xb0 - 4];
};
struct FUN_006e5db0 : S_006e5db0_Base
{
    float unkb0, unkb4, unkb8, unkbc;
    FUN_006e5db0(S_006e5db0_Src* src);
    virtual ~FUN_006e5db0();
};
// @fnv 0x006e5db0
FUN_006e5db0::FUN_006e5db0(S_006e5db0_Src* pSource) : S_006e5db0_Base(pSource)
{
    unkb0 = pSource->GetFloatAtOffsetB0();
    unkb4 = pSource->GetFieldB4Float();
    unkb8 = pSource->GetFieldB8Float();
    unkbc = pSource->FUN_0099e040();
}
