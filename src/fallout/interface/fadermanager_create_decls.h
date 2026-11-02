// fallout/interface/fadermanager_create_decls.h: declares NiPoint3, NiPoint2, FaderSurfaceParameters, NiFixedString, NiSortAdjustNode and more
#ifndef FADERMANAGER_CREATE_DECLS_H
#define FADERMANAGER_CREATE_DECLS_H

// Private type and helper declarations used by the two creation routines.
void* operator new[](size_t);
void* _NiMalloc(unsigned int);
int FUN_004dc1f0();
int FUN_004dc200();
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
};
class NiPoint2
{
  public:
    float x, y;
    NiPoint2();
    NiPoint2(float, float);
};
// Shader inputs used while constructing the fader surface.
struct FaderSurfaceParameters
{
    float fInitialAlpha;
    NiPoint2* pTexCoords;
};
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
};
class NiSortAdjustNode : public NiNode
{
  public:
    unsigned char layout[168];
    NiSortAdjustNode(int);
};
class NiDirectionalLight : public NiAVObject
{
  public:
    unsigned char layout[248];
    NiDirectionalLight();
    void FUN_004bc280(const NiPoint3&);
};
bool FUN_004de070();
class NiAlphaProperty : public NiObject
{
  public:
    unsigned char layout[24];
    NiAlphaProperty();
    void FUN_0049ed90(bool);
};
class NiBound
{
  public:
    void ComputeFromPoints(int, const NiPoint3*);
};
class NiTriShape : public NiAVObject
{
  public:
    unsigned char layout[192];
    NiTriShape(unsigned short, NiPoint3*, NiPoint3*, void*, NiPoint2*, unsigned short, unsigned int, unsigned short,
               unsigned short*);
    NiBound* GetSourceFilesFromForm();
};
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short usLen, usCapacity;
    BSStringT();
    ~BSStringT();
    int __cdecl PrintfString(const char*, ...);
    const char* String();
};
template <> class NiPointer<NiTexture>
{
  public:
    NiTexture* m_pObject;
    NiPointer(NiTexture*);
    ~NiPointer();
    operator NiTexture*() const;
};
class NiTexture
{
  public:
    struct TextureFormatPreferences
    {
        int pixelLayout, alphaFormat, mipMap;
    };
};
extern NiTexture::TextureFormatPreferences DAT_011a9598;
class NiSourceTexture : public NiTexture
{
  public:
    static NiSourceTexture* Create(const NiFixedString&, NiTexture::TextureFormatPreferences&, bool, bool);
    char _pdbpad_1[47];
    char m_kFilename_pad2f_pad2f_pad2f[4];
    char m_kPlatformFilename_pad33_pad33_pad33[4];
    char m_spPersistentSrcRendererData_pad37_pad37_pad37[4];
    char m_spSrcPixelData_pad3b_pad3b_pad3b[4];
    bool m_bIsStatic;
    bool m_bLoadDirectToRenderer;
    bool m_bKeepRendererDataPersistent;
    char m_cPixelLayout;
    void* m_pFile;
};
class BSShaderManager
{
  public:
    static void UpdateObjectTypeRecurse(NiAVObject*, bool, bool);
};
class NiUpdateData
{
  public:
    float fTime;
    bool m_bUpdateEnabled, m_bRender, m_bInterpolate, m_bTimeToDie, m_bVisible;
    NiUpdateData(float, bool, bool);
};
#endif
