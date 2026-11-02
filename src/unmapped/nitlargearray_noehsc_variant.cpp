
// src/unmapped/nitlargearray_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /Gy (unit src/unmapped/nitlargearray.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long* lpAddend);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long* lpAddend);
typedef char* GlobalStringHandle;
struct NiGlobalStringTable
{
    static GlobalStringHandle ms_pcEmptyString;
    static unsigned int* GetRefCount(GlobalStringHandle handle)
    {
        return (unsigned int*)(handle - 8);
    }
    static void IncRefCount(GlobalStringHandle& handle)
    {
        if (handle == ms_pcEmptyString)
            return;
        InterlockedIncrement((volatile long*)GetRefCount(handle));
    }
    static void DecRefCount(GlobalStringHandle& handle)
    {
        if (handle == ms_pcEmptyString)
            return;
        InterlockedDecrement((volatile long*)GetRefCount(handle));
    }
};
GlobalStringHandle AddString(const char* pcString);
class NiFixedString
{
  public:
    NiFixedString(const char* pcString = 0)
    {
        if (pcString == 0)
            m_kHandle = NiGlobalStringTable::ms_pcEmptyString;
        else
            m_kHandle = AddString(pcString);
    }
    ~NiFixedString()
    {
        NiGlobalStringTable::DecRefCount(m_kHandle);
    }
    NiFixedString& operator=(const NiFixedString& kString)
    {
        if (m_kHandle != kString.m_kHandle)
        {
            GlobalStringHandle kHandle = kString.m_kHandle;
            NiGlobalStringTable::IncRefCount(kHandle);
            NiGlobalStringTable::DecRefCount(m_kHandle);
            m_kHandle = kHandle;
        }
        return *this;
    }
    GlobalStringHandle m_kHandle;
};
struct NiFixedStringArray
{
    virtual void v00();
    NiFixedString* m_pBase;
    unsigned int m_uiMaxSize;
    unsigned int m_uiSize;
    unsigned int m_uiESize;
    unsigned int m_uiGrowBy;
    void Clear();
};

struct MemoryManager
{
    void Deallocate(void* pvMem);
};
extern MemoryManager _g_memoryManager;

void operator delete[](void* p)
{
    _g_memoryManager.Deallocate(p);
}

bool operator!=(const NiFixedString& a, const NiFixedString& b)
{
    return a.m_kHandle != b.m_kHandle;
}

NiFixedString* __cdecl FUN_00a63ae0(unsigned int auiCount);

struct MyNiFixedStringArray : public NiFixedStringArray
{
    void FUN_00a65140(unsigned int uiMaxSize);
};

// @fnv 0x00a65140
void MyNiFixedStringArray::FUN_00a65140(unsigned int uiMaxSize)
{
    if (uiMaxSize == m_uiMaxSize)
    {
        return;
    }

    unsigned int i;
    if (uiMaxSize < m_uiSize)
    {
        for (i = uiMaxSize; i < m_uiSize; i++)
        {
            if (m_pBase[i] != NiFixedString(0))
            {
                m_pBase[i] = NiFixedString(0);
                m_uiESize--;
            }
        }

        m_uiSize = uiMaxSize;
    }

    NiFixedString* pSaveBase = m_pBase;
    m_uiMaxSize = uiMaxSize;
    if (uiMaxSize > 0)
    {
        m_pBase = FUN_00a63ae0(m_uiMaxSize);

        for (i = 0; i < m_uiSize; i++)
        {
            m_pBase[i] = pSaveBase[i];
        }

        for (i = m_uiSize; i < m_uiMaxSize; i++)
        {
            m_pBase[i] = NiFixedString(0);
        }
    }
    else
    {
        m_pBase = 0;
    }

    delete[] pSaveBase;
}
