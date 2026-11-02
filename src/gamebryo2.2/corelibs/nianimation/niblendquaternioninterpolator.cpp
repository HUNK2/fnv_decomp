
// src/gamebryo2.2/corelibs/nianimation/niblendquaternioninterpolator.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/niblendquaternioninterpolator.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiStream;

struct RgbaColor
{
    void LoadBinary(NiStream&);
};

struct NiBlendInterpolator
{
    virtual void LoadBinary(NiStream&);
};

struct NiBlendQuaternionInterpolator : NiBlendInterpolator
{
    void FUN_00a554c0(NiStream&);
};

// @fnv 0x00a554c0
void NiBlendQuaternionInterpolator::FUN_00a554c0(NiStream& kStream)
{
    NiBlendInterpolator::LoadBinary(kStream);
    ((RgbaColor*)((char*)this + 0x30))->LoadBinary(kStream);
}

namespace fnv_00a554e0 {
struct NiStream
{
    virtual ~NiStream();
};

struct NiQuaternion
{
    void SaveBinary(NiStream*);
};

struct NiBlendInterpolator
{
    virtual ~NiBlendInterpolator();
};

struct NiBlendQuaternionInterpolator : NiBlendInterpolator
{
    NiQuaternion m_kQuaternionValue;
    void FUN_00a554e0(NiStream*);
};

struct FUN_00a37ec0_tgt
{
    void FUN_00a37ec0(NiStream*);
};

// @fnv 0x00a554e0
void NiBlendQuaternionInterpolator::FUN_00a554e0(NiStream* kStream)
{
    ((FUN_00a37ec0_tgt*)this)->FUN_00a37ec0(kStream);
    ((NiQuaternion*)((char*)this + 0x30))->SaveBinary(kStream);
}
}  // namespace fnv_00a554e0

extern int g_011f4064;

// @fnv 0x00a55500
int* __cdecl FUN_00a55500()
{
    return &g_011f4064;
}

void __fastcall FUN_00a36890(void*);
extern int DAT_011f4208;
extern int DAT_011f420c;
extern int DAT_011f4210;
extern int DAT_011f4214;
extern int DAT_0109a3ac;

struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int);
};

// @fnv 0x00a55470
void* __cdecl FUN_00a55470()
{
    void* p = BSFadeNode::operator new(0x40);
    if (p)
    {
        FUN_00a36890(p);
        *(int**)((char*)p + 0) = &DAT_0109a3ac;
        *(int*)((char*)p + 0x30) = DAT_011f4208;
        *(int*)((char*)p + 0x34) = DAT_011f420c;
        *(int*)((char*)p + 0x38) = DAT_011f4210;
        *(int*)((char*)p + 0x3c) = DAT_011f4214;
        return p;
    }
    return 0;
}

struct NiInterpolator
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
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual bool IsQuaternionInterpolator();
};

// Returns whether the given NiInterpolator is a quaternion interpolator by calling its IsQuaternionInterpolator method.
// @fnv 0x00a55450
bool __stdcall FUN_00a55450(NiInterpolator* pkInterpolator)
{
    return pkInterpolator->IsQuaternionInterpolator();
}

struct NiQuaternion
{
    float x, y, z, w;
};
struct CloneOwner
{
    void FUN_00a37510(void*, void*);
};
struct FUN_00a55510_shell : NiBlendQuaternionInterpolator
{
    void* CloneInterpolator(void* kCloning);
};
// @fnv 0x00a55510
void* FUN_00a55510_shell::CloneInterpolator(void* kCloning)
{
    void* pkObject = BSFadeNode::operator new(0x40);
    if (pkObject)
    {
        FUN_00a36890(pkObject);
        *(int*)pkObject = (int)&DAT_0109a3ac;
        *(NiQuaternion*)((char*)pkObject + 0x30) = *(NiQuaternion*)&DAT_011f4208;
    }
    else
    {
        pkObject = 0;
    }
    ((CloneOwner*)this)->FUN_00a37510(pkObject, kCloning);
    *(NiQuaternion*)((char*)pkObject + 0x30) = *(NiQuaternion*)((char*)this + 0x30);
    return pkObject;
}

struct FUN_00a37260_shell
{
    void NormalizeWeights();
};

struct FUN_00a555c0_shell
{
    bool FUN_00a555c0(float fTime, void* pkTarget, void* kValue);
};

struct FUN_00a556b0_shell
{
    bool FUN_00a556b0(float fTime, void* pkTarget, void* kValue);
};

struct FUN_00a55920_shell : NiBlendQuaternionInterpolator
{
    bool Interpolate(float fTime, void* pkInterpTarget, NiQuaternion* kValue);
};

// @fnv 0x00a55920
bool FUN_00a55920_shell::Interpolate(float fTime, void* pkInterpTarget, NiQuaternion* kValue)
{
    bool bReturnValue = false;
    unsigned char ucCount = *(unsigned char*)((char*)this + 0xe);
    if (ucCount == 1)
    {
        bReturnValue = ((FUN_00a555c0_shell*)this)->FUN_00a555c0(fTime, pkInterpTarget, kValue);
    }
    else if (ucCount > 0)
    {
        ((FUN_00a37260_shell*)this)->NormalizeWeights();
        bReturnValue = ((FUN_00a556b0_shell*)this)->FUN_00a556b0(fTime, pkInterpTarget, kValue);
    }
    *(float*)((char*)this + 8) = fTime;
    return bReturnValue;
}

struct StrArr
{
    void* m_pData;
    unsigned int m_uiCapacity;
    unsigned short m_uiSize;
    unsigned short m_uiCount;
    unsigned short m_uiReserved;
    unsigned short m_uiGrowSize;

    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};

struct FUN_00a38080_shell
{
    void FUN_00a38080(StrArr*);
};

struct FUN_00a6e190_shell
{
    float x;
    float y;
    float z;
    float w;

    char* FUN_00a6e190(const char*);
};

char* __cdecl _FUN_00a7d330(int);
char* FUN_00a6e190(const char*);

extern char str_01098800[];

struct FUN_00a55980_shell : NiBlendQuaternionInterpolator
{
    void AppendInterpolatorStrings(StrArr*);
};

// @fnv 0x00a55980
void FUN_00a55980_shell::AppendInterpolatorStrings(StrArr* pkStrings)
{
    reinterpret_cast<FUN_00a38080_shell*>(this)->FUN_00a38080(pkStrings);

    char* pString = _FUN_00a7d330(g_011f4064);

    unsigned int uiIndex = pkStrings->m_uiCount;
    unsigned int uiSize = pkStrings->m_uiSize;
    if (uiIndex >= uiSize)
        pkStrings->SetSize(pkStrings->m_uiGrowSize + uiIndex);

    pkStrings->SetAt(uiIndex, pString);

    pString = reinterpret_cast<FUN_00a6e190_shell*>(reinterpret_cast<unsigned char*>(this) + 0x30)
                  ->FUN_00a6e190(str_01098800);

    uiIndex = pkStrings->m_uiCount;
    uiSize = pkStrings->m_uiSize;
    if (uiIndex >= uiSize)
        pkStrings->SetSize(pkStrings->m_uiGrowSize + uiIndex);

    pkStrings->SetAt(uiIndex, pString);
}

struct FUN_00a55590_sub
{
    bool Check(void* pkParam);
};

struct FUN_00a55590_cls
{
    int unk00;
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
    FUN_00a55590_sub m_30;

    bool Probe(void* pkParam);
    unsigned char CheckWithOffset(void* pkParam);
};

// Returns false if Probe(pkParam) fails, otherwise returns the negation of m_30.Check(pkParam + 0x30).
// @fnv 0x00a55590
unsigned char FUN_00a55590_cls::CheckWithOffset(void* pkParam)
{
    if (!Probe(pkParam))
    {
        return false;
    }
    return !m_30.Check((char*)pkParam + 0x30);
}

extern float DAT_0109696c;
extern int DAT_011f4208;
extern int DAT_011f420c;
extern int DAT_011f4210;
extern int DAT_011f4214;

struct NiQuadWords
{
    int m_00;
    int m_04;
    int m_08;
    int m_0c;
};

struct FUN_00a555c0_target
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
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual bool v38(float t, void* p2, NiQuadWords* out);
};

struct FUN_00a555c0_cls
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char m_0c;
    unsigned char unk0d;
    unsigned char unk0e;
    unsigned char unk0f;
    int unk10;
    int unk14;
    FUN_00a555c0_target* m_18;
    int unk1c;
    float m_20;
    int unk24;
    int unk28;
    int unk2c;
    NiQuadWords m_30;
    bool FUN_00a555c0(float t, void* p2, NiQuadWords* out);
};

// @fnv 0x00a555c0
bool FUN_00a555c0_cls::FUN_00a555c0(float t, void* p2, NiQuadWords* out)
{
    if ((m_0c & 1) != 0)
    {
        t = m_20;
    }
    if (t == DAT_0109696c)
    {
        out->m_00 = DAT_011f4208;
        out->m_04 = DAT_011f420c;
        out->m_08 = DAT_011f4210;
        out->m_0c = DAT_011f4214;
        m_30.m_00 = out->m_00;
        m_30.m_04 = out->m_04;
        m_30.m_08 = out->m_08;
        m_30.m_0c = out->m_0c;
        return false;
    }
    FUN_00a555c0_target* tgt = m_18;
    NiQuadWords* pCachedQuad = &m_30;
    if (tgt->v38(t, p2, pCachedQuad) == false)
    {
        out->m_00 = DAT_011f4208;
        out->m_04 = DAT_011f420c;
        out->m_08 = DAT_011f4210;
        *(volatile int*)&out->m_0c = DAT_011f4214;
        pCachedQuad->m_00 = *(volatile int*)&out->m_00;
        pCachedQuad->m_04 = out->m_04;
        pCachedQuad->m_08 = out->m_08;
        pCachedQuad->m_0c = out->m_0c;
        return false;
    }
    out->m_00 = pCachedQuad->m_00;
    out->m_04 = pCachedQuad->m_04;
    out->m_08 = pCachedQuad->m_08;
    out->m_0c = pCachedQuad->m_0c;
    return true;
}

struct NiQuat
{
    float w, x, y, z;
    NiQuat()
    {}
    NiQuat(float fW, float fX, float fY, float fZ) : w(fW), x(fX), y(fY), z(fZ)
    {}
    NiQuat Negate() const;
    void Sum4(const NiQuat& q, float fW, float fX, float fY, float fZ)
    {
        w = q.w + fW;
        x = q.x + fX;
        y = q.y + fY;
        z = q.z + fZ;
    }
    NiQuat FUN_00a39120(float f) const;
    void FUN_00a38560();
    void SetValues(float fW, float fX, float fY, float fZ)
    {
        w = fW;
        x = fX;
        y = fY;
        z = fZ;
    }
    NiQuat operator+(const NiQuat& q) const
    {
        return NiQuat(w + q.w, x + q.x, y + q.y, z + q.z);
    }
    static float Dot(const NiQuat& p, const NiQuat& q)
    {
        return p.w * q.w + p.x * q.x + p.y * q.y + p.z * q.z;
    }
};
struct QInterp
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
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual bool Update(float fTime, void* pkTarget, NiQuat& kValue);
};
struct InterpArrayItem
{
    QInterp* m_spControllerInterpolator;
    float m_fWeight;
    float m_fNormalizedWeight;
    int m_cPriority;
    float m_fEaseSpinner;
    float m_fLastEvaluationTime;
};
struct QBlendInterp
{
    void* vtbl;
    int unk04;
    float unk08;
    unsigned char m_uiObjectFlags;
    unsigned char m_ucArraySize;
    unsigned char m_ucInterpCount;
    unsigned char m_ucSingleIdx;
    int unk10;
    InterpArrayItem* m_pInterpArray;
    int unk18, unk1c, unk20, unk24, unk28, unk2c;
    NiQuat m_kValue;
    bool GetUpdateTimeForItem(float& fTime, unsigned char uc)
    {
        InterpArrayItem& kItem = m_pInterpArray[uc];
        if (!kItem.m_spControllerInterpolator || kItem.m_fNormalizedWeight == 0.0f)
            return false;
        if (m_uiObjectFlags & 1)
            fTime = kItem.m_fLastEvaluationTime;
        return fTime != DAT_0109696c;
    }
    bool FUN_00a556b0(float fTime, void* pkTarget, NiQuat& kValue);
};
// @fnv 0x00a556b0
bool QBlendInterp::FUN_00a556b0(float fTime, void* pkTarget, NiQuat& kValue)
{
    m_kValue.SetValues(0.0f, 0.0f, 0.0f, 0.0f);
    bool bModified = false;
    float fTotalWeight = 0.0f;
    for (unsigned char uc = 0; uc < m_ucArraySize; uc++)
    {
        InterpArrayItem& kItem = m_pInterpArray[uc];
        if (kItem.m_spControllerInterpolator && kItem.m_fNormalizedWeight > 0.0f)
        {
            float fUpdateTime = fTime;
            if (!GetUpdateTimeForItem(fUpdateTime, uc))
                continue;
            NiQuat kQuat;
            if (kItem.m_spControllerInterpolator->Update(fUpdateTime, pkTarget, kQuat))
            {
                if (fTotalWeight > 0.0f)
                {
                    float fCos = NiQuat::Dot(m_kValue, kQuat);
                    if (fCos < 0.0f)
                        kQuat = kQuat.Negate();
                }
                kQuat = kQuat.FUN_00a39120(m_pInterpArray[uc].m_fNormalizedWeight);
                m_kValue = m_kValue.FUN_00a39120(fTotalWeight);
                float fZ = m_kValue.z;
                float fY = m_kValue.y;
                float fX = m_kValue.x;
                float fW = m_kValue.w;
                m_kValue.Sum4(kQuat, fW, fX, fY, fZ);
                m_kValue.FUN_00a38560();
                bModified = true;
                fTotalWeight += m_pInterpArray[uc].m_fNormalizedWeight;
            }
        }
    }
    if (!bModified)
    {
        m_kValue = *(NiQuat*)&DAT_011f4208;
        kValue = m_kValue;
        return false;
    }
    kValue = m_kValue;
    return true;
}
