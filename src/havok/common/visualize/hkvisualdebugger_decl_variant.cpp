
// src/havok/common/visualize/hkvisualdebugger_decl_variant.cpp - declaration variant unit created 2026-10-26 by decl_variants.py for paused function 0x00cd0ec0: the skeleton of src/havok/common/visualize/hkvisualdebugger.cpp
// with declarations corrected to what the original code does (unit: extern hkErrorCD0D* DAT_01268360; -> ; unit: struct FUN_00cb1600 : hkOstreamCD0D { FUN_00cb1600(char* -> ). Move the function to its real unit once
// that unit declares it this way.

// src/havok/common/visualize/hkvisualdebugger.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/hkvisualdebugger.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct FUN_00cd12b0_cls
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    unsigned int* m_10;
    int m_14;
    void RemovePair(int);
    void FUN_00cd12b0();
};
struct BSFadeNode
{
    static void* __cdecl operator new(unsigned int size);
    BSFadeNode();
    ~BSFadeNode();
};
struct FUN_00ccf890_t : BSFadeNode
{
    int m_iWordAt00;
    int m_iWordAt04;
    int m_8;
    int m_iThirdValue;
    int m_10;
    FUN_00ccf890_t();
    ~FUN_00ccf890_t();
};
BSFadeNode* CreateObject();
class hkVisualDebugger;
struct FUN_00cd1e40_target
{
    virtual void FUN_00cd1e40_virtual0() = 0;
    virtual void FUN_00cd1e40_virtual1() = 0;
    virtual void FUN_00cd1e40_virtual2(hkVisualDebugger*, unsigned short) = 0;
};
struct FUN_00cd1e40_router
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    FUN_00cd1e40_target* m_10;
};
FUN_00cd1e40_router* _D1A0E0GetMemoryRouter();
struct hkVisualDebugger
{
    unsigned int m_iWordAt00;
    unsigned short m_iWordAt04;

    void FUN_00cd1970();
    hkVisualDebugger* FUN_00cd1e40(unsigned int flags);
};
struct hkErrorCD0D
{
    virtual ~hkErrorCD0D();
    virtual void V1() throw();
    virtual void V2() throw();
    virtual int message(int iType, int aiSoundId, const char* pcDescription, const char* pcFile, int iLine) throw();
    virtual void V4() throw();
    virtual void V5() throw();
    virtual void V6() throw();
    virtual void BeginSection(int aiSoundId, const char* pcSectionName) throw();
    virtual void EndSection() throw();
};
struct hkSocketCD0D
{
    virtual ~hkSocketCD0D();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    virtual void V6();
    virtual void V7();
    virtual int listen(int iPort);
};
extern hkSocketCD0D*(__cdecl* DAT_011b3df0)();
struct hkOstreamCD0D
{
    int m_iUnk00;
    char* m_pString;
    int m_uiLogicalSize;
    void FUN_00cc00e0() throw();
    hkOstreamCD0D& FUN_00cc01c0(const char* pcString) throw();
    hkOstreamCD0D& WriteInt(int iValue) throw();
};
struct hkVisualDebuggerCD0D : hkVisualDebugger
{
    hkSocketCD0D* m_pkServer;
    void CreateServer(int iListenPort);
};
class hkStateCD0E
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual bool isActive();
};
class hkTargetCD0E
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void activate();
};
class hkControllerCD0E
{
  public:
    void FUN_00d60960(int mode);
    void FUN_00d605d0(unsigned int flags);
    void HashUInt(float t);
    hkTargetCD0E* FUN_00d60800();
};
class hkItemCD0E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    hkStateCD0E m_uiContentCount;
    int unk10;
    int unk14;
    hkControllerCD0E* m_controller;
};
struct hkEntryCD0E
{
    int m_key;
    hkItemCD0E* m_item;
};
class hkOwnerCD0E
{
  public:
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    hkEntryCD0E* m_entries;

    void ActivateEntry(int i, float t);
};
template <class T> class hkArrayCD11
{
  public:
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int indexOf(const T& t) const
    {
        for (int i = 0; i < m_iElementCount; i++)
        {
            if (m_data[i] == t)
                return i;
        }
        return -1;
    }
    void removeAt(int iIndex)
    {
        m_iElementCount--;
        if (m_iElementCount != iIndex)
            m_data[iIndex] = m_data[m_iElementCount];
    }
};
class hkpEntityCD11;
class hkpEntityTrackerCD11
{
  public:
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
    hkArrayCD11<hkpEntityCD11*> m_kActorEntries;
    hkArrayCD11<void*> m_entityData;

    void FUN_00cd1140(hkpEntityCD11* pkEntity);
};
struct FUN_00cd12e0_element
{
    unsigned int value;
    void FUN_00cb0a60();
    void FUN_00cb0c10();
};
struct FUN_00cd12e0_array
{
    FUN_00cd12e0_element* data;
    unsigned int size;
    unsigned int capacityFlags;
};
struct FUN_00cd12e0_router
{
    unsigned int m_iWordAt00;
    unsigned int m_iWordAt04;
    unsigned int m_8;
    unsigned int m_iThirdValue;
    void* heap;
};
FUN_00cd12e0_router* FUN_00c85750();
void __cdecl ResizeAudioStream(void*, FUN_00cd12e0_array*, int);
struct FUN_00cd12e0_owner
{
    void FUN_00cd12e0();
};
