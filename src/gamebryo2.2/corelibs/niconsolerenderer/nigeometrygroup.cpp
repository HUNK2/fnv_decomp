// gamebryo2.2/corelibs/niconsolerenderer/nigeometrygroup.cpp: NiGeometryGroup, NiGeometryBufferData, StandIn (6 functions)

#include "nigeometrygroup_decls.h"
// Initializes the NiGeometryGroup vtable pointer, sets m_uiRefCount to 0, and clears the second member.
// @fnv 0x00e986f0
NiGeometryGroup::NiGeometryGroup()
{
    m_ppVirtualMethodTable = NiGeometryGroup_vtable;
    DAT_00fdf0e4(&m_uiRefCount, 0);
    m_pD3DDevice = 0;
}

// @fnv 0x00e98750
void NiGeometryGroup::RemoveObject(NiGeometryBufferData* data)
{
    InterlockedDecrement(&m_uiRefCount);
    unsigned int count = data->m_uiRegisterStreamCount;
    data->m_pkOwnerGroup = 0;
    for (unsigned int i = 0; i < count; ++i)
        ((void(__thiscall*)(NiGeometryGroup*, NiGeometryBufferData*, unsigned int))m_ppVirtualMethodTable[7])(this, data, i);
    data->ReleaseBuffers();
}

// Initializes the NiGeometryBufferData object: sets the vtable pointer, zeroes all fields, sets one field to 4, and clears m_pusIndexArray.
// @fnv 0x00e947c0
NiGeometryBufferData::NiGeometryBufferData()
{
    m_ppVirtualMethodTable = NiGeometryBufferData_vtable;
    m_uiValue1 = 0;
    m_pkOwnerGroup = 0;
    m_uiGroupIndex = 0;
    m_pkVertexDeclaration = 0;
    m_bIsInitialized = false;
    m_uiVertexCount = 0;
    m_uiVertexDataSize = 0;
    m_uiRegisterStreamCount = 0;
    m_puiVertexStrides = 0;
    m_ppkVertexBuffers = 0;
    m_uiStartIndex = 0;
    m_uiPrimitiveCount = 0;
    m_pkIndexBuffer = 0;
    m_uiBufferSize = 0;
    m_eRequestType = 4;
    m_uiIndexArrayCount = 0;
    m_uiMinimumIndex = 0;
    m_uiMaximumIndex = 0;
    m_pusIndexData = 0;
    m_pusIndexArray = 0;
}

__declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

// @fnv 0x00e98730
void __fastcall FUN_00e98730(int pObject, int, int pArg)
{
    InterlockedIncrement((long volatile*)(pObject + 4));
    *(int*)(pArg + 8) = pObject;
}

void __cdecl _delete(void*, unsigned int);
struct FakeDevice
{
    virtual void F0();
    virtual void F1();
    virtual unsigned long __stdcall Release();
};
struct StandIn
{
    void* Destroy(unsigned int);
};
// Sets the vtable to NiGeometryGroup_vtable, releases the FakeDevice at offset 8 if present, and optionally deletes this with size 12.
// @fnv 0x00e98790
void* StandIn::Destroy(unsigned int auiFlags)
{
    FakeDevice* pDevice = *(FakeDevice**)((char*)this + 8);
    *(void**)this = NiGeometryGroup_vtable;
    if (pDevice)
        pDevice->Release();
    if (auiFlags & 1)
        _delete(this, 12);
    return this;
}

// FUN_00e98710 : installs the NiGeometryGroup vtable into the group object
// and, when a D3D device is attached, releases that device through the
// device's third virtual (the __stdcall Release slot).

struct FUN_00e98710_cls
{
    void** m_pVTable;
    long m_lRefCount;
    void* m_pD3DDevice;

    void FUN_00e98710();
};

// @fnv 0x00e98710
void FUN_00e98710_cls::FUN_00e98710()
{
    m_pVTable = NiGeometryGroup_vtable;

    void* device = m_pD3DDevice;
    if (device != 0)
        ((FakeDevice*)device)->Release();
}
