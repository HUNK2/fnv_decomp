// gamebryo2.2/corelibs/niconsolerenderer/nigeometrygroup_decls.h: declares NiGeometryGroup, NiGeometryBufferData
#ifndef NIGEOMETRYGROUP_DECLS_H
#define NIGEOMETRYGROUP_DECLS_H

extern void* NiGeometryGroup_vtable[];
extern void* NiGeometryBufferData_vtable[];
extern long(__stdcall* DAT_00fdf0e4)(volatile long*, long);
class NiGeometryBufferData;
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);
class NiGeometryGroup
{
  public:
    NiGeometryGroup();
    void RemoveObject(NiGeometryBufferData*);
    void** m_ppVirtualMethodTable;
    long m_uiRefCount;
    void* m_pD3DDevice;
};
class NiGeometryBufferData
{
  public:
    NiGeometryBufferData();
    void ReleaseBuffers();
    void** m_ppVirtualMethodTable;
    unsigned int m_uiValue1;
    NiGeometryGroup* m_pkOwnerGroup;
    unsigned int m_uiGroupIndex;
    void* m_pkVertexDeclaration;
    bool m_bIsInitialized;
    unsigned int m_uiVertexCount;
    unsigned int m_uiVertexDataSize;
    unsigned int m_uiRegisterStreamCount;
    unsigned int* m_puiVertexStrides;
    void** m_ppkVertexBuffers;
    unsigned int m_uiStartIndex;
    unsigned int m_uiPrimitiveCount;
    void* m_pkIndexBuffer;
    unsigned int m_uiBufferSize;
    unsigned int m_eRequestType;
    unsigned int m_uiIndexArrayCount;
    unsigned int m_uiMinimumIndex;
    unsigned int m_uiMaximumIndex;
    const unsigned short* m_pusIndexData;
    const unsigned short* m_pusIndexArray;
};
#endif
