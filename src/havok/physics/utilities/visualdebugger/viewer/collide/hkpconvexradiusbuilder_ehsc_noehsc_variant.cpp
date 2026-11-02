
// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder_ehsc_noehsc_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS /EHs-c- /Gy (unit src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/havok/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/visualdebugger/viewer/collide/hkpconvexradiusbuilder.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
};

struct NineIntegerRecord
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    hkMemoryAllocator* m_pStreamAllocator;

    hkMemoryAllocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

NineIntegerRecord* __cdecl FUN_00c85750();

void __cdecl FUN_00c908c0(hkMemoryAllocator* alloc, void* array, int newCapacity, int elemSize);

struct hkTransform;

struct hkVector4
{
    float x;
    float y;
    float z;
    float w;

    void FUN_00c7f640(const hkTransform& t, const hkVector4& v);
};

template <typename T> struct hkArray
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;

    hkArray() : m_data(0), m_iElementCount(0), m_iCapacityState(0x80000000)
    {}
    ~hkArray()
    {
        ClearAndRelease();
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    T& operator[](int i)
    {
        return m_data[i];
    }
    const T& operator[](int i) const
    {
        return m_data[i];
    }
    T* begin()
    {
        return m_data;
    }
    void reserve(int n)
    {
        hkMemoryAllocator& alloc = FUN_00c85750()->heap();
        const int capacity = getCapacity();
        if (capacity < n)
        {
            int cap2 = 2 * capacity;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(T));
        }
    }
    void SetSizeAndGrow(int n)
    {
        reserve(n);
        m_iElementCount = n;
    }
    void ClearAndRelease()
    {
        hkMemoryAllocator& alloc = FUN_00c85750()->heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc.ReturnMemory(m_data, getCapacity() * sizeof(T));
        }
        m_data = 0;
        m_iCapacityState = 0x80000000;
    }
};

struct hkGeometry
{
    hkArray<hkVector4> m_kVertices;
    hkArray<hkVector4> m_uiTriangleCount;

    static void* operator new(unsigned int nbytes)
    {
        return FUN_00c85750()->heap().AllocateMemoryBlock(nbytes);
    }
};

struct FloatArrayDescriptor
{
    const float* m_kVertices;
    int m_iStridedVertexCount;
    int m_iVertexStride;
};

struct hkReferencedObject
{
    void* m_vtbl;
    unsigned short m_usMemSizeAndFlags;
    unsigned short m_sReferenceCount;

    static void* operator new(unsigned int nbytes)
    {
        hkReferencedObject* b = static_cast<hkReferencedObject*>(FUN_00c85750()->heap().AllocateMemoryBlock(nbytes));
        b->m_usMemSizeAndFlags = static_cast<unsigned short>(nbytes);
        return b;
    }
};

struct hkpShape : hkReferencedObject
{
};

struct FUN_00de1d20_Shape : hkpShape
{
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

    FUN_00de1d20_Shape(hkGeometry* geom);
};

struct VertexSource;

void __cdecl FUN_00d5a6a0(const VertexSource* src, hkArray<hkVector4>* verticesOut);
void __cdecl InitAndSetB(const FloatArrayDescriptor& vertices, hkGeometry& geometryOut);

// @fnv 0x00de3360
static __declspec(noinline) hkpShape* FUN_00de3360(const VertexSource* src, const hkTransform& transform)
{
    hkArray<hkVector4> localVertices;
    FUN_00d5a6a0(src, &localVertices);
    const int numVertices = localVertices.GetLogicalSize();
    if (numVertices < 1)
    {
        return 0;
    }

    hkArray<hkVector4> vertices;
    vertices.SetSizeAndGrow(numVertices);
    for (int i = 0; i < numVertices; i++)
    {
        vertices[i].FUN_00c7f640(transform, localVertices[i]);
    }

    hkGeometry* geom = new hkGeometry;

    FloatArrayDescriptor stridedVerts;
    stridedVerts.m_iStridedVertexCount = vertices.GetLogicalSize();
    stridedVerts.m_iVertexStride = sizeof(hkVector4);
    stridedVerts.m_kVertices = (const float*)vertices.begin();
    InitAndSetB(stridedVerts, *geom);

    hkpShape* shape = new FUN_00de1d20_Shape(geom);
    return shape;
}

hkpShape* BuildConvexShapeEntry(const VertexSource* src, const hkTransform& transform)
{
    return FUN_00de3360(src, transform);
}
