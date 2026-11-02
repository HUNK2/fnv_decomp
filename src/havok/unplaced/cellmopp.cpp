
// src/havok/unplaced/cellmopp.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout shared/havok/cellmopp.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct GlobalObject_004aff00
{
    void RemoveAll();
};
struct FUN_00621e60
{
    void FUN_00621e80();
    void Clear();
};
// @fnv 0x00621e60
void FUN_00621e60::Clear()
{
    FUN_00621e80();
    ((GlobalObject_004aff00*)((char*)this + 8))->RemoveAll();
}

struct FUN_00622780
{
    void Clear();
};

struct FUN_00621e40Class
{
    void FUN_00621e40();
};

// @fnv 0x00621e40
void FUN_00621e40Class::FUN_00621e40()
{
    ((FUN_00622780*)this)->Clear();
}

struct FUN_00622290_cls
{
    int __thiscall FUN_00622290(int a, int b, int c);
    void __thiscall SetPackedValue(int a, int b, int c);
};

// Calls SetPackedValue with the three arguments, then returns this.
// @fnv 0x00622290
int __thiscall FUN_00622290_cls::FUN_00622290(int a, int b, int c)
{
    SetPackedValue(a, b, c);
    return (int)this;
}

struct FUN_006222c0_class
{
    void SetPackedValue(unsigned int a, unsigned int c, unsigned int b);
};

// @fnv 0x006222c0
void FUN_006222c0_class::SetPackedValue(unsigned int auiLow, unsigned int auiHigh, unsigned int auiMid)
{
    *(unsigned int*)this = (auiHigh << 0x10) | (auiMid << 8) | auiLow;
}

struct FUN_006222f0_Class
{
    void FUN_006222f0(int a);
};
// @fnv 0x006222f0
void FUN_006222f0_Class::FUN_006222f0(int aiValue)
{
    *(int*)((char*)this + 4) = aiValue;
    *(int*)((char*)this + 0x24) = aiValue;
}

extern const char* const g_01268350_arg1;

struct bhkBvTreeShape
{
    const char* const* GetArg1Ptr();
};

// @fnv 0x006223c0
const char* const* bhkBvTreeShape::GetArg1Ptr()
{
    return &g_01268350_arg1;
}

void* __fastcall FUN_00577190(void*);

struct FUN_006223d0
{
    void* FUN_00577190();
};

// @fnv 0x006223d0
void* FUN_006223d0::FUN_00577190()
{
    return ::FUN_00577190(this);
}

extern "C" void* g_01268350;

struct FUN_00622420_Class
{
    void* __thiscall GetGlobalPtr();
};

// @fnv 0x00622420
void* __thiscall FUN_00622420_Class::GetGlobalPtr()
{
    return &g_01268350;
}

int __fastcall FUN_009938b0(void*);

struct FUN_00622470
{
    bool IsCreated();
};

// @fnv 0x00622470
bool FUN_00622470::IsCreated()
{
    return FUN_009938b0(reinterpret_cast<char*>(this) + 8) != 0;
}

struct Base537
{
    void FUN_00537bb0();
};
struct CellMopp_00622490
{
    void __thiscall Reset();
};
struct FUN_00622490 : Base537
{
    FUN_00622490();
};
// @fnv 0x00622490
FUN_00622490::FUN_00622490()
{
    FUN_00537bb0();
    ((CellMopp_00622490*)((char*)this + 0x10))->Reset();
}

struct FUN_00622570_Class
{
    unsigned char m_kPointB;
    unsigned char* FUN_00622570(unsigned char b);
};

// @fnv 0x00622570
unsigned char* FUN_00622570_Class::FUN_00622570(unsigned char aucValue)
{
    m_kPointB = aucValue;
    return &m_kPointB;
}

struct CellMopp_00621d90
{
    void FUN_00621dc0();
    void* __thiscall Destroy(unsigned int flags);
    static void operator delete(void* p, unsigned int size);
};
// Calls FUN_00621dc0, then frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x00621d90
void* __thiscall CellMopp_00621d90::Destroy(unsigned int flags)
{
    this->FUN_00621dc0();
    if (flags & 1)
        operator delete(this, 24);
    return this;
}

extern "C" void* DAT_0104dbac;
extern "C" int DAT_012682cc;
struct FUN_00622390_Class
{
    void __thiscall FUN_0056e6f0();
    void* __thiscall FUN_00622390();
};
// @fnv 0x00622390
void* __thiscall FUN_00622390_Class::FUN_00622390()
{
    FUN_0056e6f0();
    *(void**)this = &DAT_0104dbac;
    ++DAT_012682cc;
    return this;
}

struct FUN_00622440_Class
{
    void __thiscall FUN_00caff80();
    void* __thiscall FUN_00622440(unsigned int flags);
    static void operator delete(void* p, unsigned int size);
};

// @fnv 0x00622440
void* __thiscall FUN_00622440_Class::FUN_00622440(unsigned int flags)
{
    FUN_00caff80();
    if (flags & 1)
        operator delete(this, 0x14);
    return this;
}

struct This5380d0
{
    bool FUN_005380d0(unsigned int);
};
struct Flt
{
    operator unsigned int();
};
struct Arr
{
    unsigned int* GetAt(int);
};
struct CellMopp_00621ef0
{
    unsigned int* LookupFirstFormID();
};
struct CellMopp_00621e80
{
    void FUN_00621e80();
};
// Gets the array from LookupFirstFormID and, if non-null, calls FUN_005380d0 on each non-zero element of the list at this+8.
// @fnv 0x00621e80
void CellMopp_00621e80::FUN_00621e80()
{
    unsigned int* pArray = ((CellMopp_00621ef0*)this)->LookupFirstFormID();
    if (pArray)
    {
        for (unsigned int i = 0; i < FUN_009938b0((char*)this + 8); ++i)
        {
            unsigned int p = *(Flt*)((Arr*)((char*)this + 8))->GetAt(i);
            if (p)
                ((This5380d0*)pArray)->FUN_005380d0(p);
        }
    }
}

void __cdecl operator delete(void* p, unsigned int size);
struct FUN_00ca4da0
{
    ~FUN_00ca4da0();
};
struct FUN_006223f0 : FUN_00ca4da0
{
    void* __thiscall Delete(unsigned int flags);
};
// Runs the base destructor, frees this with operator delete when flags has bit 0 set, and returns this.
// @fnv 0x006223f0
void* FUN_006223f0::Delete(unsigned int flags)
{
    this->FUN_00ca4da0::~FUN_00ca4da0();
    if (flags & 1)
        operator delete(this, 0x14);
    return this;
}

struct CellMopp_006224f0
{
    void InitializeCellMopp();
    void* __thiscall Reset();
};

// Calls InitializeCellMopp, then zeroes the int at offset 0x30 and the float at 0x34, and returns this.
// @fnv 0x006224c0
void* CellMopp_006224f0::Reset()
{
    InitializeCellMopp();
    *(int*)((char*)this + 0x30) = 0;
    *(float*)((char*)this + 0x34) = 0.0f;
    return this;
}

extern int DAT_011cc1c8;

struct FUN_00621dc0_sub
{
    ~FUN_00621dc0_sub();
};

struct FUN_00621dc0_base
{
    virtual ~FUN_00621dc0_base();
    unsigned int unk04;
    void Clear();
};

struct FUN_00621dc0_cls : FUN_00621dc0_base
{
    FUN_00621dc0_sub m_08;
    virtual ~FUN_00621dc0_cls();
};

// @fnv 0x00621dc0
FUN_00621dc0_cls::~FUN_00621dc0_cls()
{
    --DAT_011cc1c8;
    Clear();
}

extern int g_i622310Count;

class B622310Base
{
  public:
    int unk04;

    B622310Base();
    virtual ~B622310Base();
};

class FUN_00622310 : public B622310Base
{
  public:
    void FUN_00cb0820(void* pvArg);

    FUN_00622310(void* pvArg);
    virtual ~FUN_00622310();
};

// Calls FUN_00cb0820 with pvArg, then increments g_i622310Count.
// @fnv 0x00622310
FUN_00622310::FUN_00622310(void* pvArg)
{
    FUN_00cb0820(pvArg);
    g_i622310Count++;
}

struct CellMoppBaseView_006815c0
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int m10;
    int m14;
    float m18;
    float m1c;
    void FUN_006815c0();
    void FUN_004b4d50(float a, float b, float c, float d);
};
struct CellMoppMemberView_00622570
{
    unsigned char m_kPointB;
    void FUN_006815c0();
    unsigned char* FUN_00622570(unsigned char b);
};
extern float DAT_01012054;
struct CellMoppCtor_006224f0 : CellMoppBaseView_006815c0
{
    CellMoppMemberView_00622570 m20;
    CellMoppCtor_006224f0* InitializeCellMopp();
};
// @fnv 0x006224f0
CellMoppCtor_006224f0* CellMoppCtor_006224f0::InitializeCellMopp()
{
    ((CellMoppBaseView_006815c0*)this)->FUN_006815c0();
    m20.FUN_006815c0();
    FUN_004b4d50(1.0f, 1.0f, 1.0f, 0.0f);
    m10 = 2;
    m14 = 2;
    m18 = 0.0f;
    m1c = DAT_01012054;
    m20.FUN_00622570(0);
    return this;
}

class C621EF0Object
{
  public:
    virtual void VFunc000();
    virtual void VFunc004();
    virtual void VFunc008();
    virtual void VFunc00C();
    virtual void VFunc010();
    virtual void VFunc014();
    virtual void VFunc018();
    virtual void VFunc01C();
    virtual void VFunc020();
    virtual void VFunc024();
    virtual void VFunc028();
    virtual void VFunc02C();
    virtual void VFunc030();
    virtual void VFunc034();
    virtual void VFunc038();
    virtual void VFunc03C();
    virtual void VFunc040();
    virtual void VFunc044();
    virtual void VFunc048();
    virtual void VFunc04C();
    virtual void VFunc050();
    virtual void VFunc054();
    virtual void VFunc058();
    virtual void VFunc05C();
    virtual void VFunc060();
    virtual void VFunc064();
    virtual void VFunc068();
    virtual void VFunc06C();
    virtual void VFunc070();
    virtual void VFunc074();
    virtual void VFunc078();
    virtual void VFunc07C();
    virtual void VFunc080();
    virtual void VFunc084();
    virtual void VFunc088();
    virtual void VFunc08C();
    virtual void VFunc090();
    virtual unsigned int GetFormID();
};

class C621EF0Pointer
{
  public:
    C621EF0Object* Get();
};

class C621EF0Array
{
  public:
    unsigned int GetSize();
    C621EF0Pointer& GetAt(unsigned int uiIndex);
};

int __cdecl C621EF0Lookup(unsigned int auiFormId);

class C621EF0Owner
{
  public:
    int unk00;
    int unk04;
    C621EF0Array m_kThirdFollowingStreamField;

    int LookupFirstFormID();
};

// @fnv 0x00621ef0
int C621EF0Owner::LookupFirstFormID()
{
    if (m_kThirdFollowingStreamField.GetSize() && m_kThirdFollowingStreamField.GetAt(0).Get())
        return C621EF0Lookup(m_kThirdFollowingStreamField.GetAt(0).Get()->GetFormID());
    else
        return 0;
}

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct B006815c0
{
    B006815c0();
};

struct FUN_00622730_S : public B006815c0
{
    float unk00;
    float unk04;
    float unk08;
    float unk0c;
    void FUN_00622730(float angle);
};

struct FUN_005610f0_Class
{
    void FUN_005610f0(NiPoint3* pos);
    void FUN_00561150(FUN_00622730_S* rot);
};

struct FUN_0056d2c0_Class
{
    void FUN_0056d2c0(void* obj);
    void FUN_00c68e30(void* obj, unsigned int color);
};

unsigned int __cdecl PackBytesBigEndian(int r, int g, int b, int a);

class FUN_00622590_Owner : public FUN_00622470
{
  public:
    int unk00;
    int unk04;
    C621EF0Array m_kThirdFollowingStreamField;

    int LookupFirstFormID();
    bool PlaceGridObjects(FUN_0056d2c0_Class* p1, const NiPoint3* pPos, int p3);
};

// @fnv 0x00622590
bool FUN_00622590_Owner::PlaceGridObjects(FUN_0056d2c0_Class* p1, const NiPoint3* pPos, int p3)
{
    bool bResultTmp = false;
    if (p1 && IsCreated())
    {
        FUN_00622730_S kRot;
        kRot.FUN_00622730(1.5707964f);
        float offsetY2 = 0.0f;
        int kIdx = 0;
        for (unsigned int aI = 0; aI < 2; aI++)
        {
            float _offsetX = -2048.0f;
            for (unsigned int j8 = 0; j8 < 2; j8++)
            {
                FUN_005610f0_Class* pObj4 = (FUN_005610f0_Class*)m_kThirdFollowingStreamField.GetAt(kIdx++).Get();
                NiPoint3 kPos = *pPos;
                kPos.x += _offsetX;
                kPos.y += offsetY2;
                pObj4->FUN_005610f0(&kPos);
                pObj4->FUN_00561150(&kRot);
                _offsetX += 2048.0;
            }
            offsetY2 += 2048.0;
        }
        if (LookupFirstFormID() == 0)
        {
            for (unsigned int k = 0; k < (unsigned int)FUN_009938b0(&m_kThirdFollowingStreamField); k++)
            {
                FUN_005610f0_Class* pObj3 = (FUN_005610f0_Class*)m_kThirdFollowingStreamField.GetAt(k).Get();
                p1->FUN_0056d2c0(pObj3);
                p1->FUN_00c68e30(pObj3, PackBytesBigEndian(0xdc, 0x96, 0x28, 0xff));
            }
        }
    }
    return bResultTmp;
}
