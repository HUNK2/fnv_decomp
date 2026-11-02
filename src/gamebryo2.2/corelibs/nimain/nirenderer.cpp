
// src/gamebryo2.2/corelibs/nimain/nirenderer.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nimain/nirenderer.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiRenderer
{
    static NiRenderer* ms_pRenderer;
};

// @fnv 0x00a62ae0
void __cdecl FUN_00a62ae0()
{
    NiRenderer::ms_pRenderer = 0;
}

extern char const* const g_0126f0f0_arg1;

// @fnv 0x00a62b50
char const* const* __cdecl FUN_00a62b50()
{
    return &g_0126f0f0_arg1;
}

void __cdecl FUN_00a62b60();
void __cdecl _delete(void* p, unsigned int flags);
struct FUN_00a63230_shell
{
    void* __thiscall Destroy(unsigned int flags);
};
// Calls FUN_00a62b60, then if flags has bit 1 set frees this with size 0x280, and returns this.
// @fnv 0x00a63230
void* __thiscall FUN_00a63230_shell::Destroy(unsigned int flags)
{
    FUN_00a62b60();
    if (flags & 1)
        _delete(this, 0x280);
    return this;
}

struct StrArr
{
    void __thiscall SetSize(unsigned int);
    void __thiscall SetAt(unsigned int, char*&);
};
void __stdcall AppendCameraPathEntries(StrArr*);
char* __cdecl _FUN_00a7d330(const char*);
// Appends the string returned by _FUN_00a7d330 to the StrArr, growing its size when it is full.
// @fnv 0x00a63260
void __stdcall FUN_00a63260(StrArr* pkStrings)
{
    AppendCameraPathEntries(pkStrings);
    char* psz = _FUN_00a7d330(g_0126f0f0_arg1);
    unsigned int uSize = *(unsigned short*)((char*)pkStrings + 0xA);
    unsigned int uMax = *(unsigned short*)((char*)pkStrings + 8);
    if (uSize >= uMax)
        pkStrings->SetSize(uSize + *(unsigned short*)((char*)pkStrings + 0xE));
    pkStrings->SetAt(uSize, psz);
}

struct CriticalSectionA62
{
    int m_debugInfo;
    int m_lLockCount;
    int m_recursionCount;
    int m_owningThread;
    int m_lockSemaphore;
    int m_spinCount;
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(CriticalSectionA62* cs) throw();
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* p) throw();

class FUN_00a5d3d0
{
  public:
    virtual ~FUN_00a5d3d0() throw();
    virtual void DeleteThis() throw();
    long m_uiRefCount;

    void DecRefCount() throw()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class NiPointerA62
{
  public:
    T* m_pObject;
    ~NiPointerA62() throw()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
};

class NiCriticalSectionA62
{
  public:
    CriticalSectionA62 m_kCriticalSection;
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
    ~NiCriticalSectionA62() throw()
    {
        DeleteCriticalSection(&m_kCriticalSection);
    }
};

namespace NiRendererImpl {
class FUN_00a62b60 : public FUN_00a5d3d0
{
  public:
    NiPointerA62<FUN_00a5d3d0> m_acRendererDataA;
    int unk0C;
    int unk10;
    NiPointerA62<FUN_00a5d3d0> m_spDefaultMaterial;
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
    NiCriticalSectionA62 m_acRendererDataC;
    NiCriticalSectionA62 m_acRendererDataD;
    NiCriticalSectionA62 m_acRendererDataE;

    virtual ~FUN_00a62b60();
};

extern FUN_00a62b60* DAT_011f4748;

// Clears the global DAT_011f4748 pointer to null as part of the FUN_00a62b60 destructor.
// @fnv 0x00a62b60
FUN_00a62b60::~FUN_00a62b60()
{
    DAT_011f4748 = 0;
}
}

#include <math.h>
extern float DAT_0109bb88;
extern const double DAT_0101a6b0;

class NiPoint3
{
  public:
    float x, y, z;
    float GetY() const
    {
        return y;
    }
    NiPoint3()
    {}
    NiPoint3(float fX, float fY, float fZ) : x(fX), y(fY), z(fZ)
    {}
    // NiPoint3::Unitize
    __declspec(noalias) void __thiscall FUN_004a0c10();
    NiPoint3 operator+(const NiPoint3& pt) const
    {
        NiPoint3 r;
        r.x = x + pt.x;
        r.y = y + pt.y;
        r.z = z + pt.z;
        return r;
    }
    NiPoint3 operator-(const NiPoint3& pt) const
    {
        NiPoint3 r;
        r.x = x - pt.x;
        r.y = y - pt.y;
        r.z = z - pt.z;
        return r;
    }
    float operator*(const NiPoint3& pt) const
    {
        float d = x * pt.x + y * pt.y + z * pt.z;
        return d;
    }
    NiPoint3 operator*(float s) const
    {
        NiPoint3 r;
        r.x = x * s;
        r.y = y * s;
        r.z = z * s;
        return r;
    }
    NiPoint3 Cross(const NiPoint3& pt) const
    {
        NiPoint3 r;
        r.x = y * pt.z - z * pt.y;
        r.y = z * pt.x - x * pt.z;
        r.z = x * pt.y - y * pt.x;
        return r;
    }
    NiPoint3 Sub(const NiPoint3& pt) const
    {
        NiPoint3 r;
        r.x = x - pt.x;
        r.y = y - pt.GetY();
        r.z = z - pt.z;
        return r;
    }
    NiPoint3 Add(const NiPoint3& pt) const
    {
        NiPoint3 r;
        r.x = x + pt.x;
        r.y = GetY() + pt.y;
        r.z = z + pt.z;
        return r;
    }
};

struct ThreeByThreeMatrix
{
    float m[3][3];
    void __thiscall FUN_004168a0(float angle, float x, float y, float z);
    void MakeAxisAngleRotation(float angle, const NiPoint3& axis)
    {
        FUN_004168a0(angle, axis.x, axis.y, axis.z);
    }
    NiPoint3 FUN_004b4500(const NiPoint3& p) const
    {
        return NiPoint3(m[0][0] * p.x + m[0][1] * p.y + m[0][2] * p.z, m[1][0] * p.x + m[1][1] * p.y + m[1][2] * p.z,
                        m[2][0] * p.x + m[2][1] * p.y + m[2][2] * p.z);
    }
};

// NiACos: inlined until the inline budget runs out, called after that
inline float AcosClamped(float v)
{
    if (v > DAT_0101a6b0)
    {
        if (v < 1.0f)
            return acos(v);
        return 0.0f;
    }
    return DAT_0109bb88;
}

// Computes four corner points and right/up axes around a center, using a basis or target direction and a given width.
// @fnv 0x00a62be0
bool __cdecl FUN_00a62be0(const NiPoint3** basis, const NiPoint3* apCenter, const NiPoint3* target, float width,
                          NiPoint3* corners, NiPoint3* axes, NiPoint3& direction)
{
    ThreeByThreeMatrix rotMatrix;
    NiPoint3 right, up;
    const NiPoint3* normal = basis[0];
    if (!normal && !target)
        return false;
    const NiPoint3* center = apCenter;
    if (!target)
    {
        direction = *basis[0];
        const NiPoint3* current = basis[0];
        const NiPoint3& currentNormal = *current;
        NiPoint3 axis = direction.Cross(*basis[0]);
        axis.FUN_004a0c10();
        rotMatrix.FUN_004168a0(AcosClamped(currentNormal * direction), axis.x, axis.y, axis.z);
        const NiPoint3& basisRight = *basis[1];
        right = rotMatrix.FUN_004b4500(basisRight);
        normal = basis[2];
        up = rotMatrix.FUN_004b4500(*normal);
    }
    else if (!basis[0])
    {
        direction = target->Sub(*center);
        right = NiPoint3(0.0f, 0.1f, 1.0f);
        right.FUN_004a0c10();
        up = right.Cross(direction);
        up.FUN_004a0c10();
        right = up.Cross(direction);
        right.FUN_004a0c10();
    }
    else
    {
        NiPoint3 delta = *target - *center;
        delta.FUN_004a0c10();
        direction = *normal + delta;
        direction.FUN_004a0c10();
        const NiPoint3& currentNormal = *basis[0];
        NiPoint3 axis = direction.Cross(*basis[0]);
        axis.FUN_004a0c10();
        float angle = AcosClamped(direction * currentNormal);
        rotMatrix.MakeAxisAngleRotation(angle, axis);
        right = rotMatrix.FUN_004b4500(*basis[1]);
        up = rotMatrix.FUN_004b4500(*basis[2]);
    }
    direction.FUN_004a0c10();
    corners[0] = center->Add(up * (float)(width * 0.5));
    corners[1] = center->Sub(up * (float)(width * 0.5));
    corners[2] = center->Add(right * (float)(width * 0.5));
    corners[3] = center->Sub(right * (float)(width * 0.5));
    axes[0] = right;
    axes[1] = up;
    return true;
}
