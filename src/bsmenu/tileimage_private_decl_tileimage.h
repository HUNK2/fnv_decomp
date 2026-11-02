// bsmenu/tileimage_private_decl_tileimage.h: declares NiTexture, TextureFormatPreferences, Tile, TileImage, TextureReceiver and more
#ifndef FNV_TILEIMAGE_PRIVATE_H
#define FNV_TILEIMAGE_PRIVATE_H

#include <stddef.h>
class NiNode;
class NiTexture;
class TileShaderProperty;
class GlobalObject_0040c150
{
  public:
    int field0;
    char* text;
    inline const GlobalObject_0040c150* Get() const
    {
        return this;
    }
    inline char* String() const
    {
        return this ? text : 0;
    }
};
extern GlobalObject_0040c150 g_011d33f0;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long*);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
class NiTexture
{
  public:
    struct TextureFormatPreferences
    {
        int layout, alpha, mip;
    };
    virtual void vfn_0();
    virtual void DeleteThis();
    long refs;
    inline void IncRefCount()
    {
        InterlockedIncrement(&refs);
    }
    inline void DecRefCount()
    {
        if (!InterlockedDecrement(&refs))
            DeleteThis();
    }
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    inline NiPointer() : m_pObject(0)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    __forceinline ~NiPointer()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    inline void Release()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    inline bool operator!() const
    {
        return m_pObject == 0;
    }
    NiPointer<T>& operator=(T*);
    NiPointer<T>& operator=(const NiPointer<T>&);
    inline operator T*() const
    {
        return m_pObject;
    }
};
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen, sMaxLen;
};
template <class T, unsigned int G> class BSSimpleArray
{
  public:
    void** m_ppVirtualMethodTable;
    T* pBuffer;
    unsigned int iSize, SimpleArrayStorage;
};
template <class T> class NiTPointerList
{
  public:
    void* m_pkHead;
    void* m_pkTail;
    unsigned int m_uiCount;
};
class Tile
{
  public:
    class Value;
    virtual ~Tile();
    virtual void Init(Tile*, const char*, Tile*);
    virtual NiNode* CalculateNode();
    virtual int GetType();
    virtual const char* GetTypeStr();
    virtual bool Unk_05(float, float);
    virtual Tile* SetTraitValue(int, float, const char*);
    virtual void ClearTextures();
    virtual TileShaderProperty* GetShaderProperty();
    void Set(int, float, bool);
    void SetTileType(int);
    void SetImageFlags(int);
    Value* GetValue(int);
    NiTPointerList<Tile*> m_kChildTileList;
    BSSimpleArray<Value*, 8> m_kValues;
    BSStringT<char> StringProvider;
    Tile* pParent;
    NiPointer<NiNode> m_pRenderedNodeEntry;
    unsigned int uiFlags;
    bool m_bFlagAfterUiFlags;
    bool m_bSpeechChallengeFailure;
};
class TileImage : public Tile
{
  public:
    virtual void Init(Tile*, const char*, Tile*);
    void UpdateTileImage();
    static void ReadFloatAttribute(const char*, float&, float, char*);
    static void ReadTextureAttribute(const char*, float&, NiPointer<NiTexture>&, float, NiPointer<NiTexture>);
    virtual Tile* SetTraitValue(int, float, const char*);
    float fScale;
    NiPointer<NiTexture> spTexture;
    NiPointer<TileShaderProperty> m_spShaderProperty;
    bool m_bTextureLoaded;
};
typedef char tileimage_size_check[sizeof(TileImage) == 0x48 ? 1 : -1];
typedef char tileimage_flags_check[offsetof(Tile, uiFlags) == 0x30 ? 1 : -1];
typedef char tileimage_texture_check[offsetof(TileImage, spTexture) == 0x3c ? 1 : -1];
class TextureReceiver
{
  public:
    void FUN_004bc320();
};
class ExtraDataList
{
  public:
    TextureReceiver* GetStartingAngle(void*);
};
class GlobalObject_00633c90
{
  public:
    char data[4];
};
extern GlobalObject_00633c90 g_011ded3c;
class NiMemObject
{
  public:
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
class BSTextureSet : public NiMemObject
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual const char* GetTexturePath(int);
    virtual void vfn_90();
    virtual void SetTexturePath(int, const char*);
    unsigned int refs;
};
class BSShaderTextureSet : public BSTextureSet
{
  public:
    BSShaderTextureSet();
    char names[48];
};
class BGSTextureSet
{
  public:
    char form[48];
    BSTextureSet textures;
    BSShaderTextureSet* BuildShaderTextureSet();
};
class TaskQueueInterface
{
  public:
    static void CopyStringToBuffer(char*, unsigned int, const char*);
};
extern "C" int __cdecl strcat_s(char*, unsigned int, const char*);
#endif
