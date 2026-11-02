// gamebryo2.2/corelibs/nimain/ni2dbuffer.cpp: Ni2DBuffer, MyBuf, Fake, FakeBuffer (6 functions)

#include "ni2dbuffer_decls.h"

// Creates the renderer data if missing, then asks the renderer to create a depth-stencil surface for this buffer; returns false on failure.
// @fnv 0x00a8f200
bool Ni2DBuffer::CreateRendererData(const NiPixelFormat& format, MultiSamplePreference preference)
{
    if (!rendererData)
    {
        if (!IsKindOfType(&DAT_011f603c))
            return false;
        NiRenderer* renderer = NiRenderer::ms_pRenderer;
        if (renderer && !renderer->CreateDepthStencil(this, format, preference))
            return false;
    }
    return true;
}

struct NiObject;

bool __stdcall IsSameAs(NiObject* pkObject);

bool __stdcall FUN_00a88a50(NiObject* pkObject);
// @fnv 0x00a88a50
bool __stdcall FUN_00a88a50(NiObject* pkObject)
{
    if (IsSameAs(pkObject))
        return true;
    return false;
}

__declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
struct NiRefObject
{
    virtual ~NiRefObject();
    long rc;
};
struct RendererDataStub
{
    virtual void Slot0();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
            DeleteThis();
    }
};
struct RDPtr
{
    RendererDataStub* p;
    ~RDPtr()
    {
        if (p)
            p->DecRefCount();
    }
};
struct Ni2DBufferStub : NiRefObject
{
    unsigned int w, h;
    RDPtr rd;
};
extern int DAT_0109f4dc;
void __cdecl __Dummy_00b6fef0(void*, unsigned int);
// @fnv 0x00a8f330
Ni2DBufferStub* __fastcall DestroyNi2DBuffer(Ni2DBufferStub* self, int unused, unsigned char flags)
{
    *(int**)self = &DAT_0109f4dc;
    self->rd.~RDPtr();
    self->NiRefObject::~NiRefObject();
    if (flags & 1)
        __Dummy_00b6fef0(self, 0x14);
    return self;
}

struct RendererHack
{
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual bool vf69(const void* a, const void* b, const void* c, unsigned int d, unsigned int e);
};
struct MyBuf
{
    unsigned char _pad[16];
    void* sp;
    bool CopyRectTo(MyBuf* pkDest, void* pkSrcRect, unsigned int uiDestX, unsigned int uiDestY);
};
// @fnv 0x00a8f0a0
bool MyBuf::CopyRectTo(MyBuf* pkDest, void* pkSrcRect, unsigned int uiDestX, unsigned int uiDestY)
{
    NiRenderer* pkRenderer = NiRenderer::ms_pRenderer;
    if (sp == 0 || pkRenderer == 0 || pkDest->sp == 0)
        return false;
    return ((RendererHack*)pkRenderer)->vf69(this, pkDest, pkSrcRect, uiDestX, uiDestY);
}

struct Fake;
struct HackRenderer
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual void v67();
    virtual void v68();
    virtual void v69();
    virtual bool ProcessRenderRequest(Fake* a1, Fake* a2, void* a3, void* a4, int a5);
};
struct Fake
{
    char _pad[16];
    void* m_pRendererData;
    bool CopySurface(Fake* pkDest, void* pkSrcRect, void* pkDestRect, int ePref);
};
// If this, the renderer and pkDest all have a renderer pointer, forwards to the renderer's copy call with the rects and preference; otherwise returns false.
// @fnv 0x00a8f0f0
bool Fake::CopySurface(Fake* pkDest, void* pkSrcRect, void* pkDestRect, int ePref)
{
    HackRenderer* pkRenderer = (HackRenderer*)NiRenderer::ms_pRenderer;
    if (m_pRendererData != 0 && pkRenderer != 0 && pkDest->m_pRendererData != 0)
        return pkRenderer->ProcessRenderRequest(this, pkDest, pkSrcRect, pkDestRect, ePref);
    return false;
}

struct StrArr
{
    char _pad0[8];
    unsigned short _max;
    unsigned short _size;
    char _pad1[2];
    unsigned short _grow;
    void SetSize(unsigned int);
    void SetAt(unsigned int, char*&);
};
struct Base380
{
    void AppendCameraPathEntries(StrArr*);
};
struct FakeBuffer : Base380
{
    void AppendString(StrArr*);
};
extern char const* const g_011f603c_arg1;
char* _FUN_00a7d330(char const*);
// Calls the base handler, obtains a string from g_011f603c_arg1, grows pkStrings if full, then stores the string at index _size.
// @fnv 0x00a8f380
void FakeBuffer::AppendString(StrArr* pkStrings)
{
    AppendCameraPathEntries(pkStrings);
    char* pcStr = _FUN_00a7d330(g_011f603c_arg1);
    unsigned int uiSize = pkStrings->_size;
    unsigned int uiMax = pkStrings->_max;
    if (uiSize >= uiMax)
        pkStrings->SetSize(pkStrings->_grow + uiSize);
    pkStrings->SetAt(uiSize, pcStr);
}
