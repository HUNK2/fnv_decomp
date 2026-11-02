
// src/gamebryo2.2/corelibs/niparticle/nipsyscollidermanager.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/niparticle/nipsyscollidermanager.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_01202780;

// @fnv 0x00c2d540
void* __cdecl FUN_00c2d540()
{
    return &g_01202780;
}

struct NiPSysPositionModifier
{
    void* vfn[6];
    int m_0x18;
    NiPSysPositionModifier();
    static void* __cdecl operator new(unsigned int);
};

extern int DAT_010c008c;

// Allocates and constructs a NiPSysPositionModifier, sets its vtable pointer and clears m_0x18, returning the new object or null.
// @fnv 0x00c2d5b0
NiPSysPositionModifier* __cdecl FUN_00c2d5b0()
{
    NiPSysPositionModifier* p = static_cast<NiPSysPositionModifier*>(NiPSysPositionModifier::operator new(0x1c));
    if (p)
    {
        p->NiPSysPositionModifier::NiPSysPositionModifier();
        p->vfn[0] = &DAT_010c008c;
        p->m_0x18 = 0;
        return p;
    }
    return 0;
}

struct NiMemObject
{
    char _pad_0[1];
};
typedef char _sizecheck_NiMemObject[sizeof(NiMemObject) == 1 ? 1 : -1];
struct CloningProcess
{
    void __dflt_ctor_closure();
    void* __vecDelDtor(unsigned int);
    void* m_pCloneMap;
    void* m_pProcessMap;
    int m_eCloneCopyMode;
    char m_bExactType;
    char _pad_d[3];
};
typedef char _sizecheck_NiCloningProcess[sizeof(CloningProcess) == 16 ? 1 : -1];

long __declspec(dllimport) __stdcall InterlockedDecrement(long*);
long __declspec(dllimport) __stdcall InterlockedIncrement(long*);
struct NiPSysModifier
{
    char _pad[24];
    void CopyMemberData(NiPSysModifier*, CloningProcess&);
};
struct NiPSysCollider
{
    virtual void f0();
    virtual void DeleteThis();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual NiPSysCollider* Clone(CloningProcess&);
    long m_lRefCount;
};
struct NiPSysColliderManager : NiPSysModifier
{
    NiPSysCollider* m_pFirstCollider;
    void CloneCollider(NiPSysColliderManager*, CloningProcess&);
};
// Clones the modifier and, if a collider is set, clones it into pkDest, releasing the old collider and incrementing the clone's ref count.
// @fnv 0x00c2d3b0
void NiPSysColliderManager::CloneCollider(NiPSysColliderManager* pkDest, CloningProcess& kCloning)
{
    NiPSysModifier::CopyMemberData(pkDest, kCloning);
    NiPSysCollider* pkSrc = m_pFirstCollider;
    if (pkSrc)
    {
        NiPSysCollider* pkClone = pkSrc->Clone(kCloning);
        NiPSysCollider* pkOld = pkDest->m_pFirstCollider;
        if (pkOld != pkClone)
        {
            if (pkOld && InterlockedDecrement(&pkOld->m_lRefCount) == 0)
                pkOld->DeleteThis();
            pkDest->m_pFirstCollider = pkClone;
            if (pkClone)
                InterlockedIncrement(&pkClone->m_lRefCount);
        }
    }
}

namespace fnv_00c2d410 {
struct NiPSysModifier
{
    virtual void ProcessClone(CloningProcess&);
    char _pad[20];
};
struct NiPSysCollider
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void ProcessClone(CloningProcess&);
};
struct NiPSysColliderManager : NiPSysModifier
{
    NiPSysCollider* m_pFirstCollider;
    void FUN_00c2d410(CloningProcess&);
};
// Calls the base modifier's ProcessClone, then forwards the clone request to the collider if one is set.
// @fnv 0x00c2d410
void NiPSysColliderManager::FUN_00c2d410(CloningProcess& kCloning)
{
    NiPSysModifier::ProcessClone(kCloning);
    NiPSysCollider* pkColliders = m_pFirstCollider;
    if (pkColliders)
        pkColliders->ProcessClone(kCloning);
}
}  // namespace fnv_00c2d410

namespace fnv_00c2d440 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct NiObject
{
    virtual void _f0();
    virtual void _f1();
    long volatile m_uiRefCount;
};
struct NiStream
{
    NiObject* GetLoadedObject();
};
struct NiPSysModifier
{
    virtual void LinkObject(NiStream&);
    char _pad[20];
};
struct NiPSysColliderManager : NiPSysModifier
{
    NiObject* m_pFirstCollider;
    void FUN_00c2d440(NiStream&);
};
// Links the modifier to the stream: calls NiPSysModifier::LinkObject, then swaps the referenced NiObject with refcount decrement/increment.
// @fnv 0x00c2d440
void NiPSysColliderManager::FUN_00c2d440(NiStream& kStream)
{
    NiPSysModifier::LinkObject(kStream);
    NiObject* pNewObject = kStream.GetLoadedObject();
    NiObject* pOldObject = m_pFirstCollider;
    if (pOldObject != pNewObject)
    {
        if (pOldObject)
        {
            if (InterlockedDecrement(&pOldObject->m_uiRefCount) == 0)
                pOldObject->_f1();
        }
        m_pFirstCollider = pNewObject;
        if (pNewObject)
            InterlockedIncrement(&pNewObject->m_uiRefCount);
    }
}
}  // namespace fnv_00c2d440

namespace fnv_00c2d4a0 {
struct NiStream;
struct Base31670
{
    bool FUN_00c31670(NiStream&);
};
struct NiPSysCollider
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual bool v21(NiStream&);
};
struct NiPSysColliderPtr
{
    NiPSysCollider* m_pObject;
};
struct NiPSysColliderManager
{
    char _pad[24];
    NiPSysColliderPtr m_pFirstCollider;
    bool FUN_00c2d4a0(NiStream&);
};
// @fnv 0x00c2d4a0
bool NiPSysColliderManager::FUN_00c2d4a0(NiStream& kStream)
{
    if (!((Base31670*)this)->FUN_00c31670(kStream))
        return false;
    NiPSysCollider* pkColliders = m_pFirstCollider.m_pObject;
    if (pkColliders)
        pkColliders->v21(kStream);
    return true;
}
}  // namespace fnv_00c2d4a0

namespace fnv_00c2d4d0 {
struct NiStream
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void Func30(void*);
};
struct NiPSysModifier
{
    char _pad[0x18];
    void FUN_00c31950(NiStream&);
};
struct NiPSysColliderManager : NiPSysModifier
{
    void* m_pFirstCollider;
    void FUN_00c2d4d0(NiStream&);
};
// @fnv 0x00c2d4d0
void NiPSysColliderManager::FUN_00c2d4d0(NiStream& kStream)
{
    NiPSysModifier::FUN_00c31950(kStream);
    kStream.Func30(m_pFirstCollider);
}
}  // namespace fnv_00c2d4d0

namespace fnv_00c2d5e0 {
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
void __cdecl _delete(void*, unsigned int);
struct Holder31750
{
    void FUN_00c31750();
};
struct Collider
{
    virtual void f0();
    virtual void f1();
    long m_ref;
};
struct NiPSysColliderManager
{
    char _pad[0x18];
    Collider* m_sp;
    void* ReleaseCollider(unsigned int);
};
// @fnv 0x00c2d5e0
void* NiPSysColliderManager::ReleaseCollider(unsigned int flag)
{
    Collider* p = m_sp;
    if (p != 0)
    {
        if (InterlockedDecrement((long volatile*)&p->m_ref) == 0)
            p->f1();
    }
    ((Holder31750*)this)->FUN_00c31750();
    if (flag & 1)
        _delete(this, 0x1c);
    return this;
}
}  // namespace fnv_00c2d5e0

namespace fnv_00c2d630 {
struct StrArr
{
    void* _0;
    unsigned int _4;
    unsigned short _8;
    unsigned short _a;
    unsigned short _c;
    unsigned short _e;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
char* __cdecl _FUN_00a7d330(void*);
struct NiPSysCollider
{
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void GetViewerStrings(StrArr*);
};
struct BaseMod
{
    char _0[0x18];
    void FUN_00c319e0(StrArr*);
};
struct NiPSysColliderManager : BaseMod
{
    NiPSysCollider* m_pFirstCollider;
    void FUN_00c2d630(StrArr*);
};
// @fnv 0x00c2d630
void NiPSysColliderManager::FUN_00c2d630(StrArr* pkStrings)
{
    BaseMod::FUN_00c319e0(pkStrings);
    char* pcString = _FUN_00a7d330(g_01202780);
    unsigned int uiSize = pkStrings->_a;
    if (uiSize >= pkStrings->_8)
        pkStrings->SetSize(uiSize + pkStrings->_e);
    pkStrings->SetAt(uiSize, pcString);
    m_pFirstCollider->GetViewerStrings(pkStrings);
}
}  // namespace fnv_00c2d630

struct Owner
{
    char _p[0xd4];
    float m_fPoint3Value;
};
struct Item
{
    float f[7];
};
struct Data
{
    char _p[0x50];
    unsigned short m_usElementCount;
    char _q[0x1e];
    Item* m_pItems;
};
struct Res
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void Apply(float, Data*, unsigned short);
};
struct Ctl
{
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual Res* Get(float, float*, Data*, unsigned short);
    virtual void a36();
    virtual void Begin();
};
struct FUN_00c2d300_cls
{
    int _a, _b, _c, _d;
    Owner* m_pSharedOwner;
    int _e;
    Ctl* m_pCtl;
    void UpdateItems(float t, Data* d);
};
// @fnv 0x00c2d300
void FUN_00c2d300_cls::UpdateItems(float t, Data* d)
{
    Ctl* pCtl = m_pCtl;
    if (pCtl && d->m_usElementCount > 0)
        pCtl->Begin();
    for (unsigned short usIndex = 0; usIndex < d->m_usElementCount; usIndex++)
    {
        float a = m_pSharedOwner->m_fPoint3Value;
        float fResult = t;
        pCtl = m_pCtl;
        Res* p = 0;
        if (pCtl)
            p = pCtl->Get(a, &fResult, d, usIndex);
        if (p)
            p->Apply(t, d, usIndex);
        else
            fResult = a;
        d->m_pItems[usIndex].f[5] = fResult;
    }
}

struct NiPSysPositionModifierBase_stub
{
    void FUN_00c31720();
};

struct FUN_00c2d550_cls
{
    void CloneCollider(NiPSysPositionModifier* pkNew, CloningProcess& cp);
    NiPSysPositionModifier* CreatePositionModifier(CloningProcess& cp);
    long m_lUnk;
};

// Allocates and constructs a NiPSysPositionModifier, initializes its vtable and m_0x18, then passes it to CloneCollider with cp and returns it.
// @fnv 0x00c2d550
NiPSysPositionModifier* FUN_00c2d550_cls::CreatePositionModifier(CloningProcess& cp)
{
    NiPSysPositionModifier* pkNew = (NiPSysPositionModifier*)NiPSysPositionModifier::operator new(0x1c);
    if (pkNew != 0)
    {
        reinterpret_cast<NiPSysPositionModifierBase_stub*>(pkNew)->FUN_00c31720();
        *(int**)pkNew = &DAT_010c008c;
    }
    else
    {
        pkNew = 0;
    }
    (pkNew != 0 ? (pkNew->m_0x18 = 0, this) : this)->CloneCollider(pkNew, cp);
    return pkNew;
}

struct NiObject;

struct ColliderProbe
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual bool v23(NiPSysCollider* other);
};

struct FUN_00c2d4f0_cls : NiPSysColliderManager
{
    bool FUN_00c31830(NiObject* other);
    bool IsCompatibleWith(NiObject* other);
};

// @fnv 0x00c2d4f0
bool FUN_00c2d4f0_cls::IsCompatibleWith(NiObject* other)
{
    if (!FUN_00c31830(other))
        return false;

    NiPSysColliderManager* pOtherManager = (NiPSysColliderManager*)other;
    if ((m_pFirstCollider && !pOtherManager->m_pFirstCollider) ||
        (!m_pFirstCollider && pOtherManager->m_pFirstCollider))
    {
        return false;
    }

    NiPSysCollider* pCollider = m_pFirstCollider;
    if (pCollider && pOtherManager->m_pFirstCollider)
    {
        if (!reinterpret_cast<ColliderProbe*>(pCollider)->v23(pOtherManager->m_pFirstCollider))
            return false;
    }

    return true;
}
