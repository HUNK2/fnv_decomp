// gamebryo2.2/corelibs/niconsolerenderer/nid3ddefaultshader_decls.h: declares NiFixedString, NiGlobalStringTable, NiD3DShader
#ifndef NID3DDEFAULTSHADER_DECLS_H
#define NID3DDEFAULTSHADER_DECLS_H
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
class NiFixedString
{
  public:
    char* m_handle;
};
extern NiFixedString EmptyFS;
class NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);
extern void* const DAT_010eecac[];
class NiD3DShader
{
  public:
    NiD3DShader();
    void* const* vtable;
    unsigned int referenceCount;
    NiFixedString name;
    unsigned char padding0c[20];
    bool bestImplementation;
    unsigned char padding21[3];
    bool usesRenderState;
    bool usesLightState;
    unsigned char padding26[2];
    void* shaderDeclaration;
    void* renderStateGroup;
    void* pixelConstantMap;
    void* vertexConstantMap;
    unsigned int currentPass;
    unsigned char padding3c[20];
};
class NiD3DDefaultShader : public NiD3DShader
{
  public:
    NiD3DDefaultShader();
    unsigned int field50, field54, field58;
};
#endif
