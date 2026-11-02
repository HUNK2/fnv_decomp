
// src/bsshader/bsshadermanager_nogf_variant.cpp - flag-variant unit created 2026-10-24 by flag_moves.py: the bytes and the matched neighbours of these functions
// say /MT /O2 /GS /EHsc /Gy (unit src/bsshader/bsshadermanager.cpp lists /MT /O2 /GS /EHsc /Gy /GF). Declarations copied from that unit's skeleton; move the functions to their real
// unit once identified.

#include "bsshadermanager_decls.h"
#include <stddef.h>
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
extern "C" int __cdecl sprintf_s(char*, size_t, const char*, ...);
extern "C" int __cdecl strcpy_s(char*, size_t, const char*);
extern "C" char* __cdecl strrchr(const char*, int);
extern "C" int __cdecl _strnicmp(const char*, const char*, size_t);
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
class NiRTTI;
class NiRenderer;
class BSFileEntry;
class BSFogProperty;
class NiRefObject
{
  public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int m_uiRefCount;
    __forceinline void DecRefCount()
    {
        if (!InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)))
            DeleteThis();
    }
};
class NiObject : public NiRefObject
{
  public:
    NiObject* DynamicCast(const NiRTTI*);
};
class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
};
class NiTextureRendererData
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
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual unsigned int vfn_98();
};
class NiTexture : public NiObject
{
  public:
    unsigned char objectNET[16];
    struct TextureFormatPreferences
    {
        unsigned int m_ePreferredPixelLayout, m_eAlphaFormat, m_eMipFlag;
    } m_kTextureFormatPreferences;
    NiTextureRendererData* m_pTextureRendererData;
    NiTexture* m_pkPrev;
    NiTexture* m_pkNext;
};
template <class T> class NiPointer;
template <> class NiPointer<NiTexture>
{
  public:
    NiTexture* m_pObject;
    NiPointer();
    ~NiPointer();
    NiPointer& operator=(NiTexture*);
    __forceinline void Reset()
    {
        if (m_pObject)
        {
            m_pObject->DecRefCount();
            m_pObject = 0;
        }
    }
};
class NiSourceTexture : public NiTexture
{
  public:
    void* m_spPixelData;
    const char* m_pcFileName;
    static NiSourceTexture* Create(const NiFixedString&, NiTexture::TextureFormatPreferences&, bool, bool);
};
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        FILE_NOT_FOUND = 0
    };
    FILE_LOCATION GetFileLocation(char*, char*, unsigned int, unsigned int);
};
class TextureFileEntrySetter
{
  public:
    static void SetTexture(NiTexture*, const BSFileEntry*);
};
class NiAVObject
{
  public:
    void UpdateSceneObject();
};
class ShadowSceneNode
{
  public:
    void SetFogPropertyForIndex(BSFogProperty*);
};
class BSShaderManager
{
  public:
    enum eObjectType
    {
        OBJECT_0 = 0,
        OBJECT_1 = 1
    };
    static void GetTexture(const char*, bool, NiPointer<NiTexture>&, bool, bool);
    static void BuildTexturePath(char*, const char*, const char*, bool);
    static void SetFOV(float);
    static char* GetRenderModeName();
    static void SetRenderMode(unsigned int);
    static void UpdateObjectTypeRecurse(NiAVObject*, bool, bool);
    static void SetObjectTypeRecursively(NiAVObject*, eObjectType, bool, bool);
    static void SetFogPropertyForIndex(int, BSFogProperty*);
};
extern "C" FileFinder* g_fileFinder;
extern "C" bool fnv_NiStreamGetTexture(const char*, NiPointer<NiTexture>&);
NiTexture* CreateSpawnedCubeShell(const NiFixedString&, NiRenderer*, NiTexture::TextureFormatPreferences&);
extern NiRenderer* DAT_011f9508;
extern NiTexture::TextureFormatPreferences DAT_011a9598;
extern NiRTTI DAT_011f444c;
extern const double DAT_01023128, DAT_010ad6d8;
extern float DAT_011adcc8;
extern unsigned int DAT_011f91b8;
extern void (*DAT_011f9f38)(), (*DAT_011f9f3c)();
extern void (*DAT_011f9f40[16])(), (*DAT_011f9f80[16])();
extern unsigned int (*DAT_011f91ec)(NiAVObject*);
extern ShadowSceneNode* DAT_011f91c8[4];
class SkyShaderProperty
{
  public:
    unsigned char propertyData[0x70];
    NiPointer<NiTexture> m_spTexture;
    void SetTexture(NiTexture*);
};
#pragma intrinsic(sin, cos)
// The shipped setter was built without optimization.
#pragma optimize("", off)
#pragma optimize("", on)
void __cdecl FUN_00b4f2f0(int idx, ShadowSceneNode* p);
struct ImageSpaceTexture
{
    NiTexture* GetTexture();
};
struct ImageSpaceManager
{
    char data[0x204];
    ImageSpaceTexture m_texture;
};
extern ImageSpaceManager* DAT_011f91ac;
NiTexture* GetImageSpaceTexture();
extern "C" NiTexture* DAT_011f95ec;
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(volatile long*);
void __cdecl FUN_00b54ac0(NiTexture* pkTexture);
struct PropHelper
{
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void* vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void* vfn_18();
    void* GetProperty(unsigned int);
    char _pad[0x9C];
    void** m_children;
    unsigned short _pad2;
    unsigned short m_uiItemCount;
};
void __cdecl ProcessPropertyTree(PropHelper*, int);
void __cdecl ProcessPropertyTree(PropHelper* obj, int param2);
BSFogProperty* __cdecl FUN_00b55520(int aiShadowSceneNode);
void ProcessPropertyTree(NiAVObject*, unsigned int);
void FUN_00b55b80(NiAVObject* obj);
struct tagRECT
{
    long left;
    long top;
    long right;
    long bottom;
};
extern float DAT_011f95f4;
extern float DAT_011f95f8;
extern float DAT_011f95fc;
extern float DAT_011f9600;
void __cdecl SetRectCenterAndHalfExtents(tagRECT* apLoadedRect);
struct NiStream
{
    static int __cdecl RegisterObjectLoader(const char*, NiObject*(__cdecl*)());
};
struct BSFadeNode
{
    static NiObject* __cdecl CreateObject();
};
NiObject* __cdecl FUN_00b60f50();
NiObject* __cdecl CreateNewObj();
NiObject* __cdecl CreateB6AE60Obj();
NiObject* __cdecl CreateShaderLightingProperty();
NiObject* __cdecl CreateBlobObj();
NiObject* __cdecl FUN_00ba8a00();
NiObject* __cdecl FUN_00ba9250();
NiObject* __cdecl CreateSpawnedObject90();
NiObject* __cdecl CreateObjectDerived();
NiObject* __cdecl CreateInstance();
NiObject* __cdecl FUN_00bb7ef0();
NiObject* __cdecl FUN_00bc2cb0();
NiObject* __cdecl FUN_00bc3190();
NiObject* __cdecl CreateDerived();
NiObject* __cdecl CreateInterpDerivedBc36();
NiObject* __cdecl FUN_00bc38c0();
NiObject* __cdecl CreateSpawnedObj9441();
NiObject* __cdecl CreateShaderAccumulator();
extern const char g_011f9140_arg0[];
extern const char g_011f9f00_arg0[];
extern const char g_011fa010_arg0[];
extern const char g_011fa018_arg0[];
extern const char g_011fa05c_arg0[];
extern const char g_011fa560_arg0[];
extern const char g_0120044c_arg0[];
extern const char g_01200464_arg0[];
extern const char g_012005b8_arg0[];
extern const char g_012007b0_arg0[];
extern const char g_012007c8_arg0[];
extern const char g_012007d8_arg0[];
extern const char g_01201f84_arg0[];
extern const char g_01201f90_arg0[];
extern const char g_01201f9c_arg0[];
extern const char g_01201fa8_arg0[];
extern const char g_01201fb0_arg0[];
extern const char g_01201fb8_arg0[];
extern const char g_01204378_arg0[];
void RegisterNiStreamFactories();
class B4F9A0Shader
{
  public:
    virtual void vfunc00();
    virtual void vfunc01();
    virtual void vfunc02();
    virtual void vfunc03();
    virtual void vfunc04();
    virtual void vfunc05();
    virtual void vfunc06();
    virtual void vfunc07();
    virtual void vfunc08();
    virtual void vfunc09();
    virtual void vfunc0A();
    virtual void vfunc0B();
    virtual void vfunc0C();
    virtual void vfunc0D();
    virtual void vfunc0E();
    virtual void vfunc0F();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc14();
    virtual void vfunc15();
    virtual void vfunc16();
    virtual void vfunc17();
    virtual void vfunc18();
    virtual void vfunc19();
    virtual void vfunc1A();
    virtual void vfunc1B();
    virtual void vfunc1C();
    virtual void vfunc1D();
    virtual void vfunc1E();
    virtual void vfunc1F();
    virtual void vfunc20();
    virtual void vfunc21();
    virtual void vfunc22();
    virtual void vfunc23();
    virtual void vfunc24();
    virtual void vfunc25();
    virtual void vfunc26();
    virtual void vfunc27();
    virtual void vfunc28();
    virtual void vfunc29();
    virtual void vfunc2A();
    virtual void vfunc2B();
    virtual void vfunc2C();
    virtual void vfunc2D();
    virtual void vfunc2E();
    virtual void vfunc2F();
    virtual void vfunc30();
    virtual void vfunc31();
    virtual void vfunc32();
    virtual void vfunc33();
    virtual void vfunc34();
    virtual void vfunc35();
    virtual void vfunc36();
    virtual void vfunc37();
    virtual void vfunc38();
    virtual void vfunc39();
    virtual void vfunc3A();
    virtual void vfunc3B();
    virtual void vfunc3C();
    virtual void vfunc3D();
    virtual void vfunc3E();
    virtual void vfunc3F();
    virtual void vfunc40();
    virtual void vfunc41();
    virtual void vfunc42();
    virtual void vfunc43();
    virtual void vfunc44();
    virtual void vfunc45();
    virtual void vfunc46();
    virtual void vfunc47();
    virtual void vfunc48();
    virtual void ClearCachedState();
};
class B4F9A0ShaderManager
{
  public:
    static B4F9A0Shader* ms_apShaders[35];

    static void ClearAllCachedStates();
};
int sprintf_s(char* apBuffer, unsigned int auiSize, const char* apFormat, ...);
const char* FUN_00b4f9d0(int aiShader);
struct ShaderListNode
{
    void* m_data;
    ShaderListNode* m_next;
};
class ShaderEntryBase
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual ShaderListNode* vfn_8();
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
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
};
extern ShaderEntryBase* DAT_011f9548;
extern char DAT_011f95d4;
extern char DAT_0126f554;
struct ImageSpaceTail
{
    void Tail();
};
void __cdecl FUN_00b557d0();
struct FUN_00b55b00_prop
{
    char unk00[0x1c];
    unsigned int m_uiType;
    char unk20[0x6c - 0x20];
    float m_fValue;
};
void __cdecl FUN_00b55b00(PropHelper* obj, float fValue);
extern "C" int __cdecl sprintf_s(char*, size_t, const char*, ...);
struct RTTIStub
{
    int unk00;
};
extern RTTIStub g_012021b8;
extern RTTIStub g_01200508;
extern RTTIStub g_01202040;
struct ShProp;
struct PropPtr
{
    ShProp* m_p;
    PropPtr& operator=(ShProp*);
};
struct AVObj
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual int vfn_30();
    int unk04;
    const char* m_name;
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
    PropPtr m_props[8];
    int unkbc;
    struct Shader* m_shaderC0;
    void* GetProperty(unsigned int);
    void RemoveProperty(unsigned int);
    void AttachProperty(ShProp*);
};
struct ShProp
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual int vfn_8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual ShProp* vfn_b0(AVObj*, int, int);
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
    unsigned char flags38;
    unsigned char unk39;
    unsigned short unk3a;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    void* unk58;
};
struct Shader
{
    virtual void v00();
    virtual void v04();
    virtual RTTIStub* vfn_8();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void vfn_50(AVObj*);
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual void v100();
    virtual void v104();
    virtual void v108();
    virtual void v10c();
    virtual void v110();
    virtual void v114();
    virtual int vfn_118(AVObj*, ShProp*);
};
struct Renderer
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vfn_ec(AVObj*, int, int, int);
};
extern Renderer* DAT_011f4748;
inline bool IsExactB(Shader* s, RTTIStub* r)
{
    bool b = s->vfn_8() == r;
    return b;
}
Shader* __cdecl FUN_00b55560(void*);
void __cdecl UpdateShaderProperty(AVObj* obj, bool a1, bool a2, bool a3);
void* __cdecl NiMalloc(unsigned int);
extern "C" unsigned int __cdecl strlen(const char*);
void* __cdecl _fnv_zlib_memset(void*, int, unsigned int);
struct MemoryManager
{
    void* Allocate(unsigned int);
};
extern MemoryManager _g_memoryManager;
struct StringHashMapBase
{
    virtual void vfn_0();
    virtual void vfn_4();
    unsigned int m_uiCount;
    void** m_apBuckets;
    int m_iUnk14;
    unsigned char m_bShaderEnabled;
    StringHashMapBase();
    ~StringHashMapBase();
};
StringHashMapBase::StringHashMapBase()
{
    m_uiCount = 0x25;
    m_iUnk14 = 0;
    m_apBuckets = (void**)NiMalloc(0x94);
    unsigned int uiBytes = m_uiCount;
    uiBytes += uiBytes;
    uiBytes += uiBytes;
    _fnv_zlib_memset(m_apBuckets, 0, uiBytes);
    m_bShaderEnabled = 1;
}
struct ShaderMap : StringHashMapBase
{
    virtual void vfn_8();
};
struct FUN_00b7ff40
{
    char* m_name;
    int m_unk04;
    ShaderMap m_map;
    FUN_00b7ff40(int value);
};

#include <math.h>
// Shared checkpoint chk_eaaefe0e50c64877994e, revalidated 28 October 2026.

// WIP: 6253 bytes, four native displacement bytes differ in positive-Z face.

// staged0..15 are shared cube coordinates; staged19..24 are inverse lengths.

// staged25 preserves the first-face row snapshot; staged16..18 are attenuation.

// Keep the scalar sharing and the two first-reference markers when resuming.

extern "C" void _ReadWriteBarrier();

class NiPixelFormat
{

  public:
    unsigned int flags, bitsPerPixel, srgb, rendererHint, extraData;

    unsigned int redSemantic, redRepresentation, redBits;

    unsigned int greenSemantic, greenRepresentation, greenBits;

    unsigned int blueSemantic, blueRepresentation, blueBits;

    unsigned int alphaSemantic, alphaRepresentation, alphaBits;
};

class NiMemObject
{

  public:
    static void* operator new(size_t);

    static void operator delete(void*);
};

class NiPixelData : public NiRefObject, public NiMemObject
{

  public:
    NiPixelFormat format;

    unsigned int unknown4c;

    unsigned char* pixels;

    unsigned int* widths;

    unsigned int* heights;

    unsigned int* offsets;

    unsigned int levels;

    unsigned int faces;

    unsigned int revision;

    unsigned int unknown6c;

    bool changed;

    NiPixelData(unsigned int, unsigned int, const NiPixelFormat&, unsigned int, unsigned int);
};

class PixelOwner
{

  public:
    NiPixelData* object;

    PixelOwner(NiPixelData* p) : object(p)
    {

        if (p)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
    }

    ~PixelOwner()
    {
        if (object)
            object->DecRefCount();
    }

    void Assign(NiPixelData* p)
    {

        if (object != p)
        {

            if (object)
                object->DecRefCount();

            object = p;

            if (p)
                InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
        }
    }
};

extern const NiPixelFormat DAT_011aaac8;

extern const NiPixelFormat gNiPoint3StartupSrc;

extern const NiPixelFormat DAT_011aa2e8;

extern NiPointer<NiTexture> DAT_011f9514, DAT_011f9510, DAT_011f9518, DAT_011f951c;

extern NiPointer<NiTexture> DAT_011f9520, DAT_011f9524, DAT_011f9528, DAT_011f952c;

extern NiPointer<NiTexture> DAT_011f9544, DAT_011f9530, DAT_011f953c;

extern NiPointer<NiTexture> DAT_011f9540, DAT_011f9534, DAT_011f9538;

NiTexture* FUN_00a5ff10(NiPixelData*, const char*, NiTexture::TextureFormatPreferences&);

NiTexture* CreateCubeMap(const char*, const char*, const char*, const char*, const char*, const char*, NiRenderer*,
                        const NiFixedString&, NiTexture::TextureFormatPreferences&);

int FUN_004dc060(int);

double FUN_00ec6940(double);

double FUN_00ec6940(double);

class NiGlobalStringTable
{

  public:
    static char* AddString(const char*);
};

extern char* DAT_0109b220;

struct InternedStringHeader
{
    long references;
    unsigned int length;
};

__forceinline NiFixedString::NiFixedString(const char* text)
{
    m_kHandle = NiGlobalStringTable::AddString(text);
}

__forceinline NiFixedString::~NiFixedString()
{
    char* p = m_kHandle;
    if (p != DAT_0109b220)
    {
        long& refs = (reinterpret_cast<InternedStringHeader*>(p) - 1)->references;
        InterlockedDecrement(&refs);
    }
}

__forceinline NiPointer<NiTexture>& NiPointer<NiTexture>::operator=(NiTexture* p)
{

    if (m_pObject != p)
    {

        if (m_pObject)
            m_pObject->DecRefCount();

        m_pObject = p;

        if (p)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&p->m_uiRefCount));
    }

    return *this;
}

__forceinline void CopyTextureReference(NiPointer<NiTexture>& to, const NiPointer<NiTexture>& from)
{
    if (to.m_pObject != from.m_pObject)
    {
        if (to.m_pObject)
            to.m_pObject->DecRefCount();
        to.m_pObject = from.m_pObject;
        if (to.m_pObject)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&to.m_pObject->m_uiRefCount));
    }
}

__forceinline float AttenuationCoordinate(float f)
{
    float r;
    if (f < 63.5)
        r = (float)(1.0 - f / 63.5);
    else
        r = (float)((f - 63.5) / 63.5);
    return r;
}

__forceinline float ClampUpper(float f, float d)
{
    return d < f ? d : f;
}

__forceinline float ClampLower(float f, float d)
{
    return d > f ? d : f;
}

__forceinline unsigned char ToByte(double f)
{
    return (unsigned char)f;
}

// @fnv 0x00b55bb0
void FUN_00b55bb0()
{

    NiPixelData* faceData;
    unsigned int* faceOffsets;

    NiPixelFormat cubePixelFormat;

    cubePixelFormat = DAT_011aaac8;

    PixelOwner cube(new NiPixelData(128, 128, cubePixelFormat, 1, 6));

    cube.object->revision += 1;

    unsigned char* pixel = cube.object->pixels + cube.object->offsets[0];

    float staged0;
    float staged1;
    float staged2;
    float staged3;
    float staged4;
    float staged5;
    float staged6;
    float staged7;
    float staged8;
    float staged9;
    float staged10;
    float staged11;
    float staged12;
    float staged13;
    float staged14;
    float staged15;
    float staged16;
    float staged17;
    float staged18;

    float staged19;
    float staged20;
    float staged21;
    float staged22;
    float staged23;
    float staged24;
    int loopIndex0;
    int loopIndex1;
    int loopIndex2;

    (void)staged1;
    int snapshotIndex;
    float staged25;
    (void)staged13;
    for (loopIndex0 = 0; (float)loopIndex0 < 128.0f; ++loopIndex0)
    {

        loopIndex1 = 0;
        goto firstBody;
    firstTest: {
        ++loopIndex1;
        snapshotIndex = loopIndex1;
        if ((float)snapshotIndex < 128.0f)
            goto firstBody;
        goto firstEnd;
    }
    firstBody: {

        staged4 = (float)(64.0);
        staged25 = (float)(64.0 - (float)loopIndex0);
        staged1 = staged25;
        staged2 = (float)(64.0 - (float)loopIndex1);

        staged19 = (float)sqrt((double)(float)(staged4 * staged4 + staged1 * staged1 + staged2 * staged2));
        staged19 = 1.0f / staged19;

        staged0 = staged4 * staged19;
        staged1 *= staged19;
        staged2 *= staged19;

        {
            unsigned char channel = (unsigned char)((staged2 + 1.0) * 0.5 * 255.0);
            *pixel++ = channel;
        }

        {
            unsigned char channel = (unsigned char)((staged1 + 1.0) * 0.5 * 255.0);
            *pixel++ = channel;
        }

        {
            unsigned char channel = (unsigned char)((staged0 + 1.0) * 0.5 * 255.0);
            *pixel++ = channel;
        }

        *pixel++ = 0;

        goto firstTest;
    }

    firstEnd:;
    }

    faceData = cube.object;
    faceOffsets = faceData->offsets;
    pixel = faceData->pixels + faceOffsets[0] + faceOffsets[faceData->levels];

    for (loopIndex0 = 0; (float)loopIndex0 < 128.0f; ++loopIndex0)
    {

        for (loopIndex1 = 0; (float)loopIndex1 < 128.0f; ++loopIndex1)
        {

            staged2 = (float)(64.0 - (float)loopIndex0);
            staged3 = (float)(-64.0);
            staged12 = (float)((float)loopIndex1 - 64.0);

            staged20 = staged3 * staged3 + staged2 * staged2 + staged12 * staged12;
            staged20 = sqrtf(staged20);
            staged20 = 1.0f / staged20;

            staged3 *= staged20;
            staged2 *= staged20;
            staged4 = staged12 * staged20;

            {
                unsigned char channel = (unsigned char)((staged4 + 1.0) * 0.5 * 255.0);
                *pixel++ = channel;
            }

            {
                unsigned char channel = (unsigned char)((staged2 + 1.0) * 0.5 * 255.0);
                *pixel++ = channel;
            }

            {
                unsigned char channel = (unsigned char)((staged3 + 1.0) * 0.5 * 255.0);
                *pixel++ = channel;
            }

            *pixel++ = 0;
        }
    }

    pixel = cube.object->pixels + cube.object->offsets[0] + 2 * cube.object->offsets[cube.object->levels];

    for (loopIndex1 = 0; (float)loopIndex1 < 128.0f; ++loopIndex1)
    {

        for (loopIndex2 = 0; (float)loopIndex2 < 128.0f; ++loopIndex2)
        {

            staged6 = (float)(64.0);
            staged5 = (float)((float)loopIndex2 - 64.0);
            staged7 = (float)((float)loopIndex1 - 64.0);

            staged21 = sqrtf(staged5 * staged5 + staged6 * staged6 + staged7 * staged7);
            staged21 = 1.0f / staged21;

            staged5 *= staged21;
            staged8 = staged6 * staged21;
            staged7 *= staged21;

            {
                unsigned char channel = (unsigned char)((staged7 + 1.0) * 0.5 * 255.0);
                *pixel++ = channel;
            }

            {
                unsigned char channel = (unsigned char)((staged8 + 1.0) * 0.5 * 255.0);
                *pixel++ = channel;
            }

            {
                unsigned char channel = (unsigned char)((staged5 + 1.0) * 0.5 * 255.0);
                *pixel++ = channel;
            }

            *pixel++ = 0;
        }
    }

    pixel = cube.object->pixels + cube.object->offsets[0] + 3 * cube.object->offsets[cube.object->levels];

    for (loopIndex1 = 0; (float)loopIndex1 < 128.0f; ++loopIndex1, _ReadWriteBarrier())
    {

        loopIndex2 = 0;
        goto test3_1;
    body3_1: {

        staged9 = (float)((float)loopIndex2 - 64.0);
        staged10 = (float)(-64.0);
        staged11 = (float)(64.0 - (float)loopIndex1);

        staged22 = 1.0f / sqrtf(staged10 * staged10 + staged9 * staged9 + staged11 * staged11);

        staged9 *= staged22;
        staged10 *= staged22;
        staged11 *= staged22;

        {
            unsigned char channel = (unsigned char)((staged11 + 1.0) * 0.5 * 255.0);
            *pixel++ = channel;
        }

        {
            unsigned char channel = (unsigned char)((staged10 + 1.0) * 0.5 * 255.0);
            *pixel++ = channel;
        }

        {
            unsigned char channel = (unsigned char)((staged9 + 1.0) * 0.5 * 255.0);
            *pixel++ = channel;
        }

        *pixel++ = 0;

        ++loopIndex2;
    }
    test3_1:
        if ((float)loopIndex2 < 128.0f)
            goto body3_1;
    }

    pixel = cube.object->pixels + cube.object->offsets[0] + 4 * cube.object->offsets[cube.object->levels];

    for (loopIndex0 = 0; (float)loopIndex0 < 128.0f; ++loopIndex0)
    {

        for (loopIndex2 = 0; (float)loopIndex2 < 128.0f; ++loopIndex2)
        {

            staged14 = (float)(64.0);
            staged13 = (float)((float)loopIndex2 - 64.0);
            staged4 = (float)(64.0 - (float)loopIndex0);

            staged23 = sqrtf(staged13 * staged13 + staged4 * staged4 + staged14 * staged14);
            staged23 = 1.0f / staged23;

            staged13 *= staged23;
            staged4 *= staged23;
            staged14 *= staged23;

            {
                unsigned char channel = (unsigned char)((staged14 + 1.0) * 0.5 * 255.0);
                *pixel++ = channel;
            }

            {
                unsigned char channel = (unsigned char)((staged4 + 1.0) * 0.5 * 255.0);
                *pixel++ = channel;
            }

            {
                unsigned char channel = (unsigned char)((staged13 + 1.0) * 0.5 * 255.0);
                *pixel++ = channel;
            }

            *pixel++ = 0;
        }
    }

    pixel = cube.object->pixels + cube.object->offsets[0] + 5 * cube.object->offsets[cube.object->levels];

    for (loopIndex0 = 0; (float)loopIndex0 < 128.0f; ++loopIndex0)
    {

        for (loopIndex2 = 0; (float)loopIndex2 < 128.0f; ++loopIndex2)
        {

            staged15 = (float)(-64.0);
            staged13 = (float)(64.0 - (float)loopIndex2);
            staged12 = (float)(64.0 - (float)loopIndex0);

            staged24 = (float)sqrt((double)(float)(staged13 * staged13 + staged12 * staged12 + staged15 * staged15));
            staged24 = 1.0f / staged24;

            staged13 *= staged24;
            staged12 *= staged24;
            staged15 *= staged24;

            {
                unsigned char channel = (unsigned char)((staged15 + 1.0) * 0.5 * 255.0);
                *pixel++ = channel;
            }

            {
                unsigned char channel = (unsigned char)((staged12 + 1.0) * 0.5 * 255.0);
                *pixel++ = channel;
            }

            {
                unsigned char channel = (unsigned char)((staged13 + 1.0) * 0.5 * 255.0);
                *pixel++ = channel;
            }

            *pixel++ = 0;
        }
    }

    NiTexture::TextureFormatPreferences prefs;
    prefs.m_ePreferredPixelLayout = 2;
    prefs.m_eMipFlag = 0;
    prefs.m_eAlphaFormat = 0;

    PixelOwner error(new NiPixelData(16, 16, gNiPoint3StartupSrc, 1, 1));

    pixel = error.object->pixels + error.object->offsets[0];

    for (int row = 0; 16 > row; ++row)
        for (int column = 0; column < 16; ++column)
        {

            *pixel++ = 255;

            *pixel++ = 0;

            *pixel++ = 0;

            *pixel++ = 255;
        }

    error.object->changed = true;
    error.object->revision += 1;

    {
        NiFixedString name("BSShader_DefErrorMap");
        DAT_011f9514 = FUN_00a5ff10(error.object, name.m_kHandle, DAT_011a9598);
    }

    PixelOwner normal(new NiPixelData(16, 16, DAT_011aa2e8, 1, 1));

    pixel = normal.object->pixels + normal.object->offsets[0];

    for (int row = 0; row < 16; ++row)
        for (int column = 0; column < 16; ++column)
        {

            *pixel++ = 128;

            *pixel++ = 128;

            *pixel++ = 255;
        }

    normal.object->changed = true;
    ++normal.object->revision;

    {
        NiFixedString name("BSShader_DefNormalMap");
        DAT_011f9510 = FUN_00a5ff10(normal.object, name.m_kHandle, DAT_011a9598);
    }

    PixelOwner gloss(new NiPixelData(16, 16, gNiPoint3StartupSrc, 1, 1));

    pixel = gloss.object->pixels + gloss.object->offsets[0];

    for (int row = 0; 16 > row; ++row)
        for (int column = 0; 16 > column; ++column)
        {

            *pixel++ = 128;

            *pixel++ = 128;

            *pixel++ = 255;

            *pixel++ = 64;
        }

    gloss.object->changed = true;
    ++gloss.object->revision;

    {
        NiFixedString name("BSShader_DefNormalGlossMap");
        DAT_011f9518 = FUN_00a5ff10(gloss.object, name.m_kHandle, DAT_011a9598);
    }

    normal.Assign(new NiPixelData(16, 16, DAT_011aa2e8, 1, 1));

    pixel = normal.object->pixels + normal.object->offsets[0];

    for (int row = 0; row < 16; ++row)
        for (int column = 0; column < 16; ++column)
        {

            *pixel++ = 0;
            *pixel++ = 0;
            *pixel++ = 0;
        }

    normal.object->changed = true;
    normal.object->revision += 1;

    {
        NiFixedString name("BSShader_DefHeightMap");
        DAT_011f951c = FUN_00a5ff10(normal.object, name.m_kHandle, DAT_011a9598);
    }

    BSShaderManager::GetTexture("Data\\Textures\\Effects\\WindowEnvironmentMap01.dds", true, DAT_011f9520, true, false);

    BSShaderManager::GetTexture("Data\\Textures\\Effects\\WindowEnvironmentMap02.dds", true, DAT_011f9524, true, false);

    PixelOwner secret(new NiPixelData(4, 4, gNiPoint3StartupSrc, 1, 1));

    pixel = secret.object->pixels + secret.object->offsets[0];

    for (int row = 4; row; --row)
        for (int column = 4; column; --column)
        {

            *pixel++ = 0;

            *pixel++ = 0;

            *pixel++ = 0;

            *pixel++ = 64;
        }

    ++secret.object->revision;
    secret.object->changed = true;

    {
        NiFixedString name("BSShader_HideSecretMap");
        DAT_011f9528 = FUN_00a5ff10(secret.object, name.m_kHandle, DAT_011a9598);
    }

    PixelOwner effect(new NiPixelData(4, 4, gNiPoint3StartupSrc, 1, 1));

    pixel = effect.object->pixels + effect.object->offsets[0];

    for (int row = 4; row; --row)
        for (int column = 4; column; --column)
        {

            *pixel++ = 0;

            *pixel++ = 0;

            *pixel++ = 0;

            *pixel++ = 255;
        }

    effect.object->changed = true;
    effect.object->revision++;

    {
        NiFixedString name("BSShader_DefTexEffectMap");
        DAT_011f952c = FUN_00a5ff10(effect.object, name.m_kHandle, DAT_011a9598);
    }

    char texturePath[260];

    sprintf_s(texturePath, 260, "%seyereflection.dds", "Data\\Textures\\Effects\\");

    {
        NiFixedString name("EyeReflectionCubeMap");
        DAT_011f9544 = CreateCubeMap(texturePath, texturePath, texturePath, texturePath, texturePath, texturePath,
                                    DAT_011f9508, name, DAT_011a9598);
    }

    sprintf_s(texturePath, 260, "%sreflection.dds", "Data\\Textures\\Effects\\");

    {
        NiFixedString name("ArmorReflectionCubeMap");
        reinterpret_cast<NiPointer<NiTexture>&>(DAT_011f95d4) =
            CreateCubeMap(texturePath, texturePath, texturePath, texturePath, texturePath, texturePath, DAT_011f9508,
                         name, DAT_011a9598);
    }

    sprintf_s(texturePath, 260, "%saniso.dds", "Data\\Textures\\Effects\\");

    {
        NiFixedString name(texturePath);
        DAT_011f9530 = NiSourceTexture::Create(name, DAT_011a9598, true, false);
    }

    sprintf_s(texturePath, 260, "%sNoiseMap.dds", "Data\\Textures\\Effects\\");

    {
        NiFixedString name(texturePath);
        DAT_011f953c = NiSourceTexture::Create(name, DAT_011a9598, true, false);
    }

    PixelOwner noise(new NiPixelData(4, 4, gNiPoint3StartupSrc, 1, 1));

    pixel = noise.object->pixels + noise.object->offsets[0];

    for (int row = 4; row; --row)
        for (int column = 4; column; --column)
        {

            *pixel++ = 143;
            *pixel++ = 143;
            *pixel++ = 143;
            *pixel++ = 255;
        }

    noise.object->changed = true;
    ++noise.object->revision;

    {
        NiFixedString name("BSShader_EmptyNoiseMap");
        DAT_011f9540 = FUN_00a5ff10(noise.object, name.m_kHandle, DAT_011a9598);
    }

    PixelOwner attenuation(new NiPixelData(128, 128, DAT_011aa2e8, 1, 1));

    pixel = attenuation.object->pixels + attenuation.object->offsets[0];

    for (loopIndex0 = 0; 128 > loopIndex0; ++loopIndex0)
        for (loopIndex2 = 0; loopIndex2 < 128; ++loopIndex2)
        {
            staged16 = AttenuationCoordinate((float)loopIndex2);
            staged17 = AttenuationCoordinate((float)loopIndex0);

            staged18 = staged16 * staged16 + staged17 * staged17;

            staged18 = (float)ClampLower(ClampUpper((float)staged18, (float)1.0), (float)0.0);

            staged18 = FUN_004dc060(0) == 1 ? 1.0f - staged18 : staged18;

            staged18 = (float)(staged18 * 255.0);

            unsigned char shade;

            shade = ToByte((float)FUN_00ec6940((double)staged18));

            *pixel++ = shade;
            *pixel++ = shade;
            *pixel++ = shade;
        }

    prefs.m_ePreferredPixelLayout = 2;
    prefs.m_eMipFlag = 0;
    prefs.m_eAlphaFormat = 0;

    attenuation.object->changed = true;
    attenuation.object->revision++;

    {
        NiFixedString name("BSShader_AttenuationXYZ");
        DAT_011f9534 = FUN_00a5ff10(attenuation.object, name.m_kHandle, prefs);
    }

    CopyTextureReference(DAT_011f9538, DAT_011f9534);
}
