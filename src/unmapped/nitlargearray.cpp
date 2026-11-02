
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

// Assigns an empty NiFixedString to every element, then resets m_uiSize and m_uiESize to zero.
// @fnv 0x00a637d0
void NiFixedStringArray::Clear()
{
    for (unsigned int uiIndex = 0; uiIndex < m_uiSize; uiIndex++)
        m_pBase[uiIndex] = NiFixedString(0);
    m_uiSize = 0;
    m_uiESize = 0;
}
