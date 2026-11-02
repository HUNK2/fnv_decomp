
// src/bsshader/tileshaderproperty.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/bsshader/tileshaderproperty.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" void* g_012007d8;

// @fnv 0x00bb7d60
void* __cdecl FUN_00bb7d60()
{
    return &g_012007d8;
}

struct NiGeometry;
struct ShadowSceneLight;
struct ShaderPassEntry
{
    char _0[6];
    unsigned char m_flag;
};
struct BSShaderProperty
{
    struct ShaderPassList
    {
        void Add(NiGeometry*, unsigned short, bool, unsigned char, ShadowSceneLight*, ShadowSceneLight*,
                 ShadowSceneLight*, ShadowSceneLight*);
        int _p0;
        ShaderPassEntry** m_data;
        char _p1[8];
        int m_uiItemCount;
    };
};
struct TallGrassShader
{
    void InitializeConstants(unsigned int);
    char _pad[0x38];
    unsigned int m_comb;
    BSShaderProperty::ShaderPassList* m_aiIndexedValues;
    BSShaderProperty::ShaderPassList* SetupGeometryGroup(NiGeometry*, unsigned int, unsigned int, unsigned int,
                                                         unsigned int, unsigned int);
};
// @fnv 0x00bb7a60
BSShaderProperty::ShaderPassList* TallGrassShader::SetupGeometryGroup(NiGeometry* apGeometry, unsigned int auiValue1,
                                                                      unsigned int auiValue2, unsigned int auiValue3,
                                                                      unsigned int auiValue4, unsigned int auiValue5)
{
    InitializeConstants(1);
    if (m_aiIndexedValues->m_uiItemCount == 0)
    {
        m_aiIndexedValues->Add(apGeometry, 0x42, true, 0, 0, 0, 0, 0);
        m_aiIndexedValues->m_data[m_aiIndexedValues->m_uiItemCount - 1]->m_flag = 1;
        m_comb = (auiValue3 << 8) | auiValue1;
    }
    return m_aiIndexedValues;
}

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
struct NiTexture
{
    virtual void F0()
    {}
    virtual void F1()
    {}
    long m_lRefCount;
    void IncRefCount()
    {
        InterlockedIncrement(&m_lRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_lRefCount) == 0)
            F1();
    }
};
struct TileShaderProperty
{
    char _pad[0x60];
    NiTexture* m_pkTile;
    void FUN_00bb7a10(NiTexture* apTexture);
};
// Replaces m_pkTile with apTexture, releasing the old texture and incrementing the new one's reference count when they differ.
// @fnv 0x00bb7a10
void TileShaderProperty::FUN_00bb7a10(NiTexture* apTexture)
{
    if (m_pkTile != apTexture)
    {
        if (m_pkTile)
            m_pkTile->DecRefCount();
        m_pkTile = apTexture;
        if (apTexture)
            apTexture->IncRefCount();
    }
}

// CopyTileShaderProperty : copies the tile specific part of a TileShaderProperty into
// another one.
//
// The object layout follows the game: a 0x60 byte BSShaderProperty base, the
// tile texture pointer at +0x60, a second texture pointer at +0x64, four plain
// words at +0x68..+0x74, a float at +0x78, more floats up to +0x88, a word at
// +0x8c and four bytes at +0x90..+0x93.
//
// The base class part is copied by FUN_00ba8b10 (declared here, never defined:
// the game keeps it in another unit), the tile texture is copied with the
// usual reference counting, and the remaining members are copied one by one.

struct FnvTileShaderProperty
{
    // 0x00 .. 0x5f : the opaque BSShaderProperty base of the game object
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;

    NiTexture* m_pkTile;    // +0x60
    NiTexture* m_pkTile2;   // +0x64
    unsigned int m_unk68;   // +0x68
    unsigned int m_unk6c;   // +0x6c
    unsigned int m_unk70;   // +0x70
    unsigned int m_unk74;   // +0x74
    float m_unk78;          // +0x78
    float m_unk7c;          // +0x7c
    float m_unk80;          // +0x80
    float m_unk84;          // +0x84
    float m_unk88;          // +0x88
    unsigned int m_unk8c;   // +0x8c
    unsigned char m_unk90;  // +0x90
    unsigned char m_unk91;  // +0x91
    unsigned char m_unk92;  // +0x92
    unsigned char m_unk93;  // +0x93

    void FUN_00ba8b10(FnvTileShaderProperty* dst, int flag);
    void CopyTileShaderProperty(FnvTileShaderProperty* dst, int flag);
};

// @fnv 0x00bb7ac0
void FnvTileShaderProperty::CopyTileShaderProperty(FnvTileShaderProperty* dst, int flag)
{
    FUN_00ba8b10(dst, flag);

    NiTexture* pOldTile = dst->m_pkTile;
    if (pOldTile != m_pkTile)
    {
        if (pOldTile)
            pOldTile->DecRefCount();
        NiTexture* pTileTexture = m_pkTile;
        dst->m_pkTile = pTileTexture;
        if (pTileTexture)
            pTileTexture->IncRefCount();
    }

    dst->m_unk68 = m_unk68;
    dst->m_unk6c = m_unk6c;
    dst->m_unk70 = m_unk70;
    dst->m_unk74 = m_unk74;
    dst->m_unk8c = m_unk8c;
    dst->m_unk78 = m_unk78;
    dst->m_unk93 = m_unk93;
    dst->m_unk90 = m_unk90;
}

struct NiMemObjectAllocation
{
    static void* operator new(unsigned int);
    static void operator delete(void*);
};
struct TilePropertyClone : NiMemObjectAllocation, FnvTileShaderProperty
{
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    TilePropertyClone(bool);
};
struct TileCloneSource
{
    void CopyTileShaderProperty(TilePropertyClone*, int);
    TilePropertyClone* CreateTilePropertyClone(int);
};
// Allocates a TilePropertyClone with false, initializes it via CopyTileShaderProperty with flag, and returns it.
// @fnv 0x00bb7e70
TilePropertyClone* TileCloneSource::CreateTilePropertyClone(int flag)
{
    TilePropertyClone* result = new TilePropertyClone(false);
    CopyTileShaderProperty(result, flag);
    return result;
}

namespace bb7c30 {

template <class T> class TexturePtr
{
  public:
    TexturePtr(T* pObject = 0) : m_pObject(pObject)
    {
        if (m_pObject)
            m_pObject->IncRefCount();
    }
    ~TexturePtr()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    TexturePtr& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};

struct String
{
    String() : m_pString(0), m_usLen(0), m_usMax(0)
    {}
    ~String();
    char* m_pString;
    unsigned short m_usLen;
    unsigned short m_usMax;
};

struct Color
{
    Color() : r(0.0f), g(0.0f), b(0.0f), a(0.0f)
    {}
    float r, g, b, a;
};

struct FUN_00ba8e50
{
    FUN_00ba8e50();
    ~FUN_00ba8e50();
    virtual void v00();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
};

struct FUN_00bb7c30 : FUN_00ba8e50
{
    FUN_00bb7c30(bool bFlag);

    TexturePtr<NiTexture> m_spTexture;
    TexturePtr<NiTexture> m_spTexture2;
    Color m_kFogTint;
    float m_fUnk78;
    float m_fUnk7c;
    float m_fUnk80;
    float m_fUnk84;
    float m_fUnk88;
    int m_iUnk8c;
    bool m_bUnk90;
    bool m_bUnk91;
    bool m_bUnk92;
    bool m_bFlag;
    String m_kName;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    bool m_bUnkac;
};

// Initializes the object's texture pointers, color, float fields, flags and integer fields to their default values.
// @fnv 0x00bb7c30
FUN_00bb7c30::FUN_00bb7c30(bool bFlag)
{
    m_spTexture = 0;
    m_spTexture2 = 0;
    m_kFogTint.r = 1.0f;
    m_kFogTint.g = 1.0f;
    m_kFogTint.b = 1.0f;
    m_kFogTint.a = 1.0f;
    m_fUnk78 = 1.0f;
    m_fUnk80 = 0.0f;
    m_fUnk7c = 0.0f;
    m_iUnk8c = 3;
    m_bFlag = bFlag;
    m_bUnk90 = false;
    m_bUnk91 = false;
    unk58 = 0x20;
    unk1c = 0x13;
    m_bUnkac = false;
    m_bUnk92 = false;
    m_fUnk88 = 1.0f;
    m_fUnk84 = 1.0f;
}

}

struct NiBinStream;
typedef unsigned int(__cdecl* NiBinWriteFn)(NiBinStream* pThis, const void* pvBuffer, unsigned int uiBytes,
                                            unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct NiBinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    NiBinWriteFn m_pfnWrite;
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};

struct NiStreamStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    NiBinStream* m_pBackingStream;
    void FUN_00a64ce0(unsigned int* out);
};
struct FUN_sub94
{
    void FUN_004037f0(unsigned int a, int b);
};
void __cdecl FUN_00aa10f0(unsigned int v);
template <class T> inline void SaveBin(NiBinStream& kStream, const T& val)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&val, sizeof(T), &uiSize, 1);
}

struct FUN_00bb7b60_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int m_8c;
    int unk90;
    FUN_sub94 m_94;
    void FUN_00ba92c0(NiStreamStub* a1);
    void FUN_00bb7b60(NiStreamStub* a1);
};
// Calls FUN_00ba92c0, saves m_8c to the backing stream, reads a value via FUN_00a64ce0, and passes it to m_94 and FUN_00aa10f0.
// @fnv 0x00bb7b60
void FUN_00bb7b60_cls::FUN_00bb7b60(NiStreamStub* a1)
{
    FUN_00ba92c0(a1);
    SaveBin(*a1->m_pBackingStream, m_8c);
    unsigned int v = 0;
    a1->FUN_00a64ce0(&v);
    m_94.FUN_004037f0(v, 0);
    FUN_00aa10f0(v);
}

namespace fnv_00bb7be0 {
struct NiBinStream;
typedef unsigned int(__cdecl* NiBinWriteFn)(NiBinStream* pThis, const void* pvBuffer, unsigned int uiBytes,
                                            unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct NiBinStream
{
    int unk00;
    unsigned int m_uiStreamFlags;
    int unk08;
    NiBinWriteFn m_pfnWrite;
    unsigned int BinaryWrite(const void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
                             unsigned int uiNumComponents)
    {
        unsigned int uiBytesWritten = m_pfnWrite(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesWritten;
        return uiBytesWritten;
    }
};
struct NiStreamStub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    NiBinStream* m_pBackingStream;
    void FUN_00a64160(int a1);
};

struct FUN_00bb7be0_cls
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int m_8c;
    int unk90;
    int m_94;
    void FUN_00ba9380(NiStreamStub* a1);
    void FUN_00bb7be0(NiStreamStub* a1);
};

template <class T> inline void SaveBin(NiBinStream& kStream, const T& val)
{
    unsigned int uiSize = sizeof(T);
    kStream.BinaryWrite(&val, sizeof(T), &uiSize, 1);
}
// Calls FUN_00ba9380, writes m_8c to the backing stream via SaveBin, and calls a1->FUN_00a64160 with m_94.
// @fnv 0x00bb7be0
void FUN_00bb7be0_cls::FUN_00bb7be0(NiStreamStub* a1)
{
    FUN_00ba9380(a1);
    SaveBin(*a1->m_pBackingStream, m_8c);
    a1->FUN_00a64160(m_94);
}
}  // namespace fnv_00bb7be0

class RefObject_bb7d
{
  public:
    virtual ~RefObject_bb7d();
    virtual void DeleteThis();
    volatile long m_uiRefCount;
    void IncRefCount()
    {
        InterlockedIncrement((long volatile*)&m_uiRefCount);
    }
    void DecRefCount()
    {
        if (InterlockedDecrement((long volatile*)&m_uiRefCount) == 0)
            DeleteThis();
    }
};

template <class T> class Pointer_bb7d
{
  public:
    ~Pointer_bb7d()
    {
        if (m_pObject)
            m_pObject->DecRefCount();
    }
    Pointer_bb7d& operator=(T* pObject)
    {
        if (m_pObject != pObject)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = pObject;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    T* m_pObject;
};

class TexturePool_bb7d
{
  public:
    void FUN_00aa4060(void* pvHandle);
};
extern TexturePool_bb7d DAT_011f6238;

struct PooledTexture_bb7d
{
    void* m_pvHandle;
    unsigned short m_usFirstValue;
    unsigned short m_usSecondValue;
    ~PooledTexture_bb7d()
    {
        if (m_pvHandle)
            DAT_011f6238.FUN_00aa4060(m_pvHandle);
        m_pvHandle = 0;
        m_usSecondValue = 0;
        m_usFirstValue = 0;
    }
};

class ShaderBase_bb7d
{
  public:
    virtual void v00();
    ~ShaderBase_bb7d();
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54, unk58, unk5c;
};

class FUN_00bb7d70 : public ShaderBase_bb7d
{
  public:
    virtual void v00();
    ~FUN_00bb7d70();
    Pointer_bb7d<RefObject_bb7d> m_spTexture0;
    Pointer_bb7d<RefObject_bb7d> m_spTexture1;
    int unk68, unk6c, unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c, unk90;
    PooledTexture_bb7d m_kPooled;
};

// Destructor for FUN_00bb7d70 that releases the m_spTexture0 reference.
// @fnv 0x00bb7d70
FUN_00bb7d70::~FUN_00bb7d70()
{
    m_spTexture0 = 0;
}
