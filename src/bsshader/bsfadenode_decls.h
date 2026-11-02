// bsshader/bsfadenode_decls.h: declares NiMemObject, NiRefObject, NiObject, NiObjectNET, NiProperty and more
#ifndef FNV_BSFADENODE_DECLS_H
#define FNV_BSFADENODE_DECLS_H


// Private PC declarations for this translation unit. Opaque storage represents
// inherited fields that none of these three routines inspect.
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
class NiRefObject : public NiMemObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void DecRefCount()
    {
        if (!InterlockedDecrement(&m_uiRefCount))
            DeleteThis();
    }
};
class NiObject : public NiRefObject
{
};
class NiObjectNET : public NiObject
{
  public:
    unsigned char objectNetData[16];
};
class NiProperty : public NiObjectNET
{
  public:
    NiProperty();
};
class NiAlphaProperty : public NiProperty
{
  public:
    virtual ~NiAlphaProperty();
    unsigned short m_uiObjectFlags;
    unsigned char m_ucAlphaThreshold;
    NiAlphaProperty() : m_uiObjectFlags(0xEC), m_ucAlphaThreshold(0)
    {}
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (object)
                InterlockedIncrement(&object->m_uiRefCount);
        }
        return *this;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

class MemoryManager
{
  public:
    void* Allocate(unsigned int);
};
extern MemoryManager g_memoryManager;
class NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
};
class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char* s);
    static void* operator new(unsigned int n)
    {
        return g_memoryManager.Allocate(n);
    }
    static void operator delete(void*);
};

extern NiFixedString EmptyFS;

union SETTING_VALUE
{
    const char* str;
    int i;
    unsigned int u;
    float f;
    bool b;
    char c;
    unsigned char h;
};
class Setting
{
  public:
    SETTING_VALUE uValue;
    const char* pKey;
    virtual ~Setting();
    virtual bool IsPrefSetting();
};
class INISettingCollection;
template <class T> class SettingT : public Setting
{
};
class NiAVObject : public NiObjectNET
{
  public:
    unsigned char avObjectData[0x84];
};
class NiNode : public NiAVObject
{
  public:
    unsigned char childrenData[0x10];
};
class FadingSceneNode;
class BSMultiBoundRoom;
class BSPortal;
template <class T> struct BSSimpleList
{
    T m_item;
    BSSimpleList* m_pkNext;
};
class BSFadeNode : public NiNode
{
  public:
    float fNearDistSqr;
    float fFarDistSqr;
    float fLastFade;
    float fCurrentFade;
    float m_fFadeDelta;
    float fTimeSinceUpdate;
    int eMultType;
    int iFrameCounter;
    void* pUserData;
    FadingSceneNode* m_pFadingSceneNode;
    BSSimpleList<BSMultiBoundRoom*> m_kParentRooms;
    BSSimpleList<BSPortal*> m_kParentPortals;

    BSFadeNode();
    static NiObject* CreateObject();
    static void InitializeMultiBounds();
    static SettingT<INISettingCollection> ms_kMinimumFadeDistanceSetting;
    static NiPointer<NiAlphaProperty> ms_pAlphaProperty;
    static NiFixedString* ms_pFadeNodeAnimationName;
    void SetRange(float, float);
};
typedef char BSFadeNodeSizeCheck[sizeof(BSFadeNode) == 0xE4 ? 1 : -1];
typedef char NiAlphaPropertySizeCheck[sizeof(NiAlphaProperty) == 0x1C ? 1 : -1];
// PC depth texture forwarding declarations. The singleton has no known
// canonical data name, so its address-based name is kept here.
class BSRenderedTexture;
class ImageSpaceManager
{
  public:
    BSRenderedTexture* GetDepthRenderedTexture();
};
extern ImageSpaceManager* DAT_011f91ac;
class BSShaderManager
{
  public:
    static BSRenderedTexture* GetSceneDepthRenderedTexture();
};
#endif
