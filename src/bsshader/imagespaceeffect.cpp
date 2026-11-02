
// src/bsshader/imagespaceeffect.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/imagespaceeffect.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct ImageSpaceEffect;
struct ImageSpaceEffectParam;
struct ImageSpaceManager;
struct ImageSpaceTexture;
struct NiScreenElements;
struct GraphicsRenderer;

struct NiTPrimitiveArray_ImageSpaceEffectParam___
{
    void SetAt(unsigned int, ImageSpaceEffectParam*&);
};

struct NiTPrimitiveArray_ImageSpaceEffect___
{
    void SetAt(unsigned int, ImageSpaceEffect*&);
};

struct NiTPrimitiveArray_int___
{
    void SetAt(unsigned int, int&);
};

struct FUN_00ba3c70_shell
{
    void SetEffectAt(int aiEffectIndex, ImageSpaceEffect* apEffect, ImageSpaceEffectParam* apParam, int aiOutput);
};

// Stores the effect, its parameter and output index into the three arrays at the given effect index.
// @fnv 0x00ba3c70
void FUN_00ba3c70_shell::SetEffectAt(int aiEffectIndex, ImageSpaceEffect* apEffect, ImageSpaceEffectParam* apParam,
                                     int aiOutput)
{
    NiTPrimitiveArray_ImageSpaceEffect___& pEffectList =
        *reinterpret_cast<NiTPrimitiveArray_ImageSpaceEffect___*>(this + 8);
    NiTPrimitiveArray_ImageSpaceEffectParam___& pEffectParamList =
        *reinterpret_cast<NiTPrimitiveArray_ImageSpaceEffectParam___*>(this + 0x18);
    NiTPrimitiveArray_int___& pEffectOutput = *reinterpret_cast<NiTPrimitiveArray_int___*>(this + 0x48);
    pEffectList.SetAt(aiEffectIndex, apEffect);
    pEffectParamList.SetAt(aiEffectIndex, apParam);
    pEffectOutput.SetAt(aiEffectIndex, aiOutput);
}

struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct FUN_00ba3b50_t
{
    void SetArrayEntry(int, int, int, int, int);
};
// Allocates a 16-byte block, stores the four arguments in it, and sets it at index a1 in the array at offset 0x38.
// @fnv 0x00ba3b50
void FUN_00ba3b50_t::SetArrayEntry(int uiIndex, int a2, int a3, int a4, int a5)
{
    int* p = (int*)g_memoryManager.Allocate(16);
    p[0] = a2;
    p[1] = a4;
    p[2] = a3;
    int t = (int)p;
    p[3] = a5;
    ((NiTPrimitiveArray_int___*)((char*)this + 0x38))->SetAt((unsigned int)uiIndex, t);
}

struct NiTPrimitiveArray_ImageSpaceTexture___
{
    void SetSize(unsigned int);
};
struct ImageSpaceEffect
{
    void SetTextureArraySize(int count);
};
// Sets the size of the four texture arrays at offsets 8, 0x18, 0x38 and 0x48 to count.
// @fnv 0x00ba3f90
void ImageSpaceEffect::SetTextureArraySize(int count)
{
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 8))->SetSize(count);
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x18))->SetSize(count);
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x38))->SetSize(count);
    ((NiTPrimitiveArray_ImageSpaceTexture___*)((char*)this + 0x48))->SetSize(count);
}

namespace fnv_00ba3ba0 {
struct P03MM
{
    void* Allocate(unsigned int);
};
extern P03MM g_memoryManager;
struct Holder
{
    char _pad[0x38];
    NiTPrimitiveArray_int___ _arr;
    void FUN_00ba3ba0(unsigned int, int, int, int, int, int, int);
};
// @fnv 0x00ba3ba0
void Holder::FUN_00ba3ba0(unsigned int auiIndex, int aiValue0, int aiValue1, int aiValue2, int aiValue3, int aiValue4,
                          int aiValue5)
{
    int* p = (int*)g_memoryManager.Allocate(24);
    p[0] = aiValue0;
    p[1] = aiValue3;
    p[2] = aiValue1;
    p[3] = aiValue4;
    p[4] = aiValue2;
    unsigned int t = auiIndex;
    int iEntry = (int)p;
    p[5] = aiValue5;
    _arr.SetAt(t, iEntry);
}
}  // namespace fnv_00ba3ba0

struct NiCamera;
struct NiAccumulator
{
    void SetSortingCamera(NiCamera const*);
};
struct HolderForAccum
{
    char _pad[0x28];
    NiTPrimitiveArray_int___ m_kArray;
    void SetAccumulatorAt(unsigned int auiIndex, NiAccumulator* apAccum, NiCamera const* apCamera);
};
// @fnv 0x00ba3cb0
void HolderForAccum::SetAccumulatorAt(unsigned int auiIndex, NiAccumulator* apAccum, NiCamera const* apCamera)
{
    m_kArray.SetAt(auiIndex, reinterpret_cast<int&>(apAccum));
    if (apAccum)
        apAccum->SetSortingCamera(apCamera);
}

class BBA3C00Heap
{
  public:
    void* Allocate(unsigned int uiSize);
};

extern BBA3C00Heap g_kBA3C00Heap;

struct BBA3C00Range
{
    int m_iStart;
    int m_iEnd;
};

struct BBA3C00Entry
{
    static void* operator new(unsigned int uiSize)
    {
        return g_kBA3C00Heap.Allocate(uiSize);
    }

    BBA3C00Range m_akRanges[4];
};

class BBA3C00EntryArray
{
  public:
    void SetAt(unsigned int uiIndex, BBA3C00Entry*& pkEntry);
};

class BBA3C00Shader
{
  public:
    void SetEntryRanges(unsigned int uiIndex, int iStart0, int iStart1, int iStart2, int iStart3, int iEnd0, int iEnd1,
                        int iEnd2, int iEnd3);

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
    int unk30;
    int unk34;
    BBA3C00EntryArray m_kEntries;
};

// Allocates a BBA3C00Entry, fills its four ranges from the start/end arguments, and stores it in m_kEntries at uiIndex.
// @fnv 0x00ba3c00
void BBA3C00Shader::SetEntryRanges(unsigned int uiIndex, int iStart0, int iStart1, int iStart2, int iStart3, int iEnd0,
                                   int iEnd1, int iEnd2, int iEnd3)
{
    BBA3C00Entry* pkEntry = new BBA3C00Entry;
    pkEntry->m_akRanges[0].m_iStart = iStart0;
    pkEntry->m_akRanges[0].m_iEnd = iEnd0;
    pkEntry->m_akRanges[1].m_iStart = iStart1;
    pkEntry->m_akRanges[1].m_iEnd = iEnd1;
    pkEntry->m_akRanges[2].m_iStart = iStart2;
    pkEntry->m_akRanges[2].m_iEnd = iEnd2;
    pkEntry->m_akRanges[3].m_iStart = iStart3;
    BBA3C00Entry* pkElement = pkEntry;
    pkEntry->m_akRanges[3].m_iEnd = iEnd3;
    m_kEntries.SetAt(uiIndex, pkElement);
}

struct S_00ba3f20_Item
{
    virtual void vf00();
    virtual void vf04(int a, int b, int c, int d);
};
struct S_00ba3f20_Obj
{
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10(int a);
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c(int a);
    int unk04;
    int unk08;
    S_00ba3f20_Item** m_items;
    unsigned short unk10;
    unsigned short m_uiItemCount;
    int unk14;
    int unk18;
    int* m_params;
    void SetEffectParams(unsigned int i);
    void ProcessItems(int a1, int a2, int a3, int a4);
};
// @fnv 0x00ba3f20
void S_00ba3f20_Obj::ProcessItems(int aiArg1, int aiArg2, int aiArg3, int aiArg4)
{
    vf10(aiArg3);
    for (int i = 0; (unsigned int)i < m_uiItemCount; i++)
    {
        SetEffectParams(i);
        vf1c(aiArg3);
        int iValue = *(volatile int*)&aiArg4;
        m_items[i]->vf04(aiArg1, aiArg2, m_params[i], iValue);
    }
    vf14();
}

template <class T> class NiTMallocInterface
{
};

template <class T, class TAlloc> class NiTArray
{
  public:
    virtual ~NiTArray();

    unsigned int GetAllocatedSize() const
    {
        return m_usMaxSize;
    }
    T GetAt(unsigned int uiIndex) const
    {
        return m_pBase[uiIndex];
    }
    void SetAt(unsigned int uiIndex, const T& element);

    T* m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

template <class T, class TAlloc> inline void NiTArray<T, TAlloc>::SetAt(unsigned int uiIndex, const T& element)
{
    if (uiIndex >= m_usSize)
    {
        m_usSize = (unsigned short)(uiIndex + 1);
        if (element != T(0))
            m_usESize++;
    }
    else
    {
        if (element != T(0))
        {
            if (m_pBase[uiIndex] == T(0))
                m_usESize++;
        }
        else
        {
            if (m_pBase[uiIndex] != T(0))
                m_usESize--;
        }
    }
    m_pBase[uiIndex] = element;
}

template <class T> class NiTPrimitiveArray : public NiTArray<T, NiTMallocInterface<T> >
{
  public:
    virtual ~NiTPrimitiveArray();
};

class ImageSpaceEffectParamView
{
  public:
    void FUN_00d47a40(int iValue);
};

class ImageSpaceEffectView
{
  public:
    virtual ~ImageSpaceEffectView();
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    NiTPrimitiveArray<ImageSpaceEffectParamView*> m_kParams;
};

struct ImageSpaceInput
{
    int iParam;
    int iValue;
};

class ImageSpaceManagerView
{
  public:
    virtual ~ImageSpaceManagerView();
    int unk04;
    NiTPrimitiveArray<ImageSpaceEffectView*> m_kEffects;
    NiTPrimitiveArray<int> unk18;
    NiTPrimitiveArray<ImageSpaceEffectParamView*> m_kParams;
    NiTPrimitiveArray<ImageSpaceInput*> m_kEffectInputs;
    NiTPrimitiveArray<int> m_kInputValues;

    void SetEffectParams(unsigned int uiIndex);
};

// Assigns input and output parameter views to an effect's parameter array and sets their values via FUN_00d47a40.
// @fnv 0x00ba3e30
void ImageSpaceManagerView::SetEffectParams(unsigned int uiEffectIndex)
{
    ImageSpaceEffectView* pkEffect = m_kEffects.GetAt(uiEffectIndex);
    int iCount = pkEffect->m_kParams.GetAllocatedSize();
    ImageSpaceInput* pkInputs = m_kEffectInputs.GetAt(uiEffectIndex);
    int iOutputIndex = m_kInputValues.GetAt(uiEffectIndex);

    for (int i = 1; i < iCount; i++)
    {
        ImageSpaceInput* pkInput = &pkInputs[i - 1];
        int iParam = pkInput->iParam;
        if (iParam >= 0)
        {
            int iValue = pkInput->iValue;
            ImageSpaceEffectParamView* pkParam = m_kParams.GetAt(iParam);
            pkEffect->m_kParams.SetAt(i, pkParam);
            if (pkParam)
                pkParam->FUN_00d47a40(iValue);
        }
    }

    ImageSpaceEffectParamView* pkOutput = m_kParams.GetAt(iOutputIndex);
    pkEffect->m_kParams.SetAt(0, pkOutput);
    if (pkOutput)
        pkOutput->FUN_00d47a40(0);
}
