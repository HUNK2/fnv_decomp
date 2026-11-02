// gamebryo2.2/corelibs/niconsolerenderer/nigeometrybufferdata.h: declares COMBaseInterface, COMUnknownInterface, NiGeometryBufferData
#ifndef NIGEOMETRYBUFFERDATA_H
#define NIGEOMETRYBUFFERDATA_H


// D3D9-style interface subset (STDMETHODCALLTYPE is __stdcall on x86).
struct COMBaseInterface
{
    virtual long __stdcall QueryInterface(const void* kRIID, void** ppkObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

struct COMUnknownInterface
{
    virtual long __stdcall QueryInterface(const void* kRIID, void** ppkObject) = 0;
    virtual unsigned long __stdcall AddRef() = 0;
    virtual unsigned long __stdcall Release() = 0;
};

class NiGeometryGroup;
class NiVBChip;

class NiGeometryBufferData
{
  public:
    NiGeometryBufferData();
    virtual ~NiGeometryBufferData();

    void ReleaseBuffers();

  protected:
    unsigned int m_uiValue1;
    NiGeometryGroup* m_pkOwnerGroup;
    unsigned int m_uiGroupIndex;
    COMUnknownInterface* m_pkVertexDeclaration;
    bool m_bIsInitialized;
    unsigned int m_uiVertexCount;
    unsigned int m_uiVertexDataSize;
    unsigned int m_uiRegisterStreamCount;
    unsigned int* m_puiVertexStrides;
    NiVBChip** m_ppkVertexBuffers;
    unsigned int m_uiStartIndex;
    unsigned int m_uiPrimitiveCount;
    COMBaseInterface* m_pkIndexBuffer;
    unsigned int m_uiBufferSize;
    unsigned int m_eRequestType;
    unsigned int m_uiIndexArrayCount;
    unsigned int m_uiMinimumIndex;
    unsigned int m_uiMaximumIndex;
    const unsigned short* m_pusIndexData;
};

#endif