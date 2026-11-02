
// src/havok/common/visualize/serialize/hkdisplayserializeostream.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/visualize/serialize/hkdisplayserializeostream.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// @fnv 0x00dda830
unsigned int FUN_00dda830(const unsigned int* puiValues)
{
    return 4 * (3 * (puiValues[4] + puiValues[1])) + 8;
}

void __stdcall WriteFloatArray(unsigned int, unsigned int);
// @fnv 0x00dda730
void __stdcall FUN_00dda730(unsigned int p)
{
    WriteFloatArray(p, 3);
}

struct hkMemoryAllocator
{
    virtual ~hkMemoryAllocator();
    virtual void* AllocateMemoryBlock(int numBytes);
};

struct AudioMgr
{
    int unk00, unk04, unk08, unk0c;
    hkMemoryAllocator* unk10;
    hkMemoryAllocator& heap()
    {
        return *unk10;
    }
};

struct BSAudio;
__declspec(nothrow) BSAudio* __cdecl FUN_00c85750();
inline AudioMgr* audio()
{
    return (AudioMgr*)FUN_00c85750();
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    hkBool(const hkBool& o)
    {
        m_cBooleanValue = o.m_cBooleanValue;
    }
};

struct RefObj
{
    void* m_vtbl;
    short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    __declspec(nothrow) void FUN_00c905b0();
};

struct FUN_00d27460 : RefObj
{
    int pad[(0x1c - 8) / 4];
    __declspec(nothrow) FUN_00d27460(int a, int b);
};

inline void* hkAlloc(int n)
{
    RefObj* p = (RefObj*)audio()->heap().AllocateMemoryBlock(n);
    p->m_usMemSizeAndFlags = (short)n;
    return p;
}

inline void* operator new(unsigned int, void* p)
{
    return p;
}

struct FUN_00d60830 : RefObj
{
    RefObj* m_8;
    __declspec(nothrow) FUN_00d60830(RefObj* o, hkBool b);
};

extern "C" char DAT_010d7db8[];

struct FUN_00dda6e0 : FUN_00d60830
{
    FUN_00dda6e0(int a);
};

// Constructs a FUN_00d60830 base with a newly allocated FUN_00d27460(a, 0x2000), sets the vtable, and calls FUN_00c905b0 on m_8.
// @fnv 0x00dda6e0
FUN_00dda6e0::FUN_00dda6e0(int a) : FUN_00d60830(new(hkAlloc(sizeof(FUN_00d27460))) FUN_00d27460(a, 0x2000), false)
{
    m_vtbl = DAT_010d7db8;
    m_8->FUN_00c905b0();
}

struct DDA7C0Vector4
{
    float x;
    float y;
    float z;
    float w;
};

struct DDA7C0Triangle
{
    int m_kPointA;
    int m_kPointB;
    int m_iThirdValue;
    int m_iMaterialIndex;
};

template <class T> struct DDA7C0Array
{
    T* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};

struct DDA7C0Geometry
{
    DDA7C0Array<DDA7C0Vector4> m_kVertices;
    DDA7C0Array<DDA7C0Triangle> m_uiTriangleCount;
};

struct DDA7C0OStream
{
    void writeInt32(unsigned int value);
    void writeVector(const DDA7C0Vector4& v);
    void writeTriangle(const DDA7C0Triangle& t);

    void WriteGeometry(const DDA7C0Geometry& geometry);
};

// Writes the vertex count and vertices, then the triangle count and triangles, of a geometry to the stream.
// @fnv 0x00dda7c0
void DDA7C0OStream::WriteGeometry(const DDA7C0Geometry& geometry)
{
    int numVertices = geometry.m_kVertices.m_iElementCount;
    writeInt32(numVertices);
    for (int i = 0; i < numVertices; i++)
        writeVector(geometry.m_kVertices.m_data[i]);
    int numTriangles = geometry.m_uiTriangleCount.m_iElementCount;
    writeInt32(numTriangles);
    for (int i = 0; i < numTriangles; i++)
        writeTriangle(geometry.m_uiTriangleCount.m_data[i]);
}

namespace fnv_00ddabb0 {
struct Allocator
{
    virtual void ReportDiagnostic();
    virtual void unused1();
    virtual void Free(void* block, unsigned int size);
};
struct AllocatorHolder
{
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    unsigned int unk0c;
    Allocator* allocator;
};
AllocatorHolder* __cdecl FUN_00c85750();
struct FUN_00ddabb0_shell
{
    void* unk00;
    unsigned short size;
    void FUN_00d60590();
    FUN_00ddabb0_shell* FUN_00ddabb0(unsigned int flags);
};
// Calls FUN_00d60590, then if bit 0 of flags is set frees this through the allocator from FUN_00c85750, and returns this.
// @fnv 0x00ddabb0
FUN_00ddabb0_shell* FUN_00ddabb0_shell::FUN_00ddabb0(unsigned int flags)
{
    FUN_00d60590();
    if (flags & 1)
    {
        AllocatorHolder* holder = FUN_00c85750();
        holder->allocator->Free(this, size);
    }
    return this;
}
}  // namespace fnv_00ddabb0

// Stand-in for the class that owns WriteUInt16 (the game's own class name for
// the neighbourhood is hkOArchive; no layout information is needed here because
// the function never touches a member).
//
// The original is a __thiscall member with ONE 4-byte stack argument (the
// callers do `mov ecx,<object> / push <arg> / call WriteUInt16`, and the body
// ends in `ret 4`).  It forwards `this` (ECX) unchanged to WriteSwapped and
// passes the ADDRESS of its own incoming argument as the first argument of
// that call, followed by the constants 2 and 1:
//
//     push 1
//     push 2
//     lea eax, [esp+0xc]      ; &argument  (the incoming stack slot)
//     push eax
//     call 0x00d60600
//     ret 4
//
// WriteSwapped is a __thiscall member of its own (it uses ECX as `this` and
// pops three 4-byte arguments), so it is only DECLARED here: the call target
// is then bound by the checker from the original's own bytes.

struct hkOArchiveStandIn
{
    void WriteSwapped(void* p, int n, int m);  // declared, never defined
    void WriteUInt16(unsigned int value);
};

// @fnv 0x00d60920
void hkOArchiveStandIn::WriteUInt16(unsigned int value)
{
    WriteSwapped(&value, 2, 1);
}

#include <xmmintrin.h>
struct S_00dda740_Vector4
{
    float x, y, z, w;
    __m128& q()
    {
        return reinterpret_cast<__m128&>(*this);
    }
    const __m128& q() const
    {
        return reinterpret_cast<const __m128&>(*this);
    }
};

struct S_00dda740_Matrix3
{
    S_00dda740_Vector4 m_kColumn0;
    S_00dda740_Vector4 m_kColumn1;
    S_00dda740_Vector4 m_kColumn2;
    S_00dda740_Matrix3(const S_00dda740_Matrix3& o)
    {
        m_kColumn0.q() = o.m_kColumn0.q();
        m_kColumn1.q() = o.m_kColumn1.q();
        m_kColumn2.q() = o.m_kColumn2.q();
    }
};

struct S_00dda740_Transform
{
    S_00dda740_Matrix3 m_rotation;
    S_00dda740_Vector4 m_vTranslation;
};

struct S_00dda740_Quaternion
{
    S_00dda740_Vector4 m_vec;
    void FUN_00cb26e0(const S_00dda740_Matrix3& r);
};

struct S_00dda740
{
    void WriteFloatArray(const float* data, int n);
    void WriteTransform(const S_00dda740_Transform& t);
};

// Converts the rotation matrix to a quaternion and writes the translation and quaternion components to the stream.
// @fnv 0x00dda740
void S_00dda740::WriteTransform(const S_00dda740_Transform& t)
{
    S_00dda740_Vector4 trans = t.m_vTranslation;
    __declspec(align(16)) S_00dda740_Matrix3 rot = t.m_rotation;
    __declspec(align(16)) S_00dda740_Quaternion q;
    q.FUN_00cb26e0(rot);
    WriteFloatArray(&trans.x, 3);
    WriteFloatArray(&q.m_vec.x, 4);
}

int FUN_00dda830(int value);

// Returns a constant chosen by the int at param+0x50 (0x1d plus FUN_00dda830(param+8) for 6), or 1 for other values.
// @fnv 0x00dda850
int FUN_00dda850(int param)
{
    int result = 1;
    switch (*(int*)(param + 0x50))
    {
    case 6:
        result = FUN_00dda830(*(int*)(param + 8));
        return result + 0x1d;
    case 1:
    case 5:
        return 0x35;
    case 8:
    case 9:
        return 0x41;
    case 3:
        return 0x19;
    case 4:
        return 0x25;
    case 2:
    case 7:
        result = 0x29;
        break;
    }
    return result;
}

struct __declspec(align(16)) Vec4A
{
    union
    {
        __m128 quad;
        float f[4];
    };
    Vec4A& operator=(const Vec4A& o)
    {
        _mm_store_ps(f, _mm_load_ps(o.f));
        return *this;
    }
};
struct Shape
{
    int unk00, unk04;
    DDA7C0Geometry* geom;
    int unk0c;
    int unk10, unk14, unk18, unk1c, unk20, unk24, unk28, unk2c;
    int unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int tag;
    int unk54, unk58, unk5c;
    Vec4A vec60;
    int i70, i74, i78, i7c;
    float f80;
    int i84, i88;
    const void* FUN_00de1150();
    const void* FUN_00de1160();
    void* GetValue(void* out);
    void* GetVec4At70(void* out);
    float FUN_00de5350();
    float FUN_00de5340();
    int FUN_00de5360();
    void* CopyVec4ToBuffer(void* out);
    void* GetQuad16(void* out);
    void* CopyStatsTo(void* out);
    float FUN_00de4900();
    float FUN_00de48e0();
    float FUN_00de48f0();
    int FUN_00de4910();
    const void* FUN_00de4df0();
    const void* FUN_00de4de0();
    const void* FUN_00de4e00();
    const float* FUN_00de4e10();
};
struct DDA8C0Writer
{
    void FUN_00d605b0(int v);
    void WriteTransform(const void* p);
    void FUN_00dda730(const void* p);
    void HashUInt(float f);
    void WriteInt(int v);
    void WriteGeometry(const DDA7C0Geometry& geometry);
    void WriteShape(Shape* p);
};
// Writes a Shape to the stream by dispatching on its tag and serializing the tag-specific fields via the writer's hash and write helpers.
// @fnv 0x00dda8c0
void DDA8C0Writer::WriteShape(Shape* p)
{
    Vec4A t[6];
    int tag = p->tag;
    FUN_00d605b0(tag);
    switch (tag)
    {
    case 6: {
        WriteTransform(&p->unk10);
        WriteGeometry(*p->geom);
        break;
    }
    case 1: {
        WriteTransform(&p->unk10);
        t[0] = p->vec60;
        HashUInt(t[0].f[3]);
        FUN_00dda730(&t[0]);
        WriteInt(p->i70);
        WriteInt(p->i74);
        break;
    }
    case 8: {
        WriteTransform(&p->unk10);
        HashUInt(p->f80);
        FUN_00dda730(&p->vec60);
        FUN_00dda730(&p->i70);
        WriteInt(p->i84);
        WriteInt(p->i88);
        break;
    }
    case 9: {
        WriteTransform(&p->unk10);
        HashUInt(p->f80);
        FUN_00dda730(&p->vec60);
        FUN_00dda730(&p->i70);
        WriteInt(p->i84);
        WriteInt(p->i88);
        break;
    }
    case 2: {
        WriteTransform(&p->unk10);
        FUN_00dda730(&p->vec60);
        break;
    }
    case 3: {
        FUN_00dda730(p->FUN_00de1150());
        FUN_00dda730(p->FUN_00de1160());
        break;
    }
    case 4: {
        FUN_00dda730(p->GetValue(&t[1]));
        FUN_00dda730(p->GetVec4At70(&t[2]));
        HashUInt(p->FUN_00de5350());
        HashUInt(p->FUN_00de5340());
        WriteInt(p->FUN_00de5360());
        break;
    }
    case 5: {
        FUN_00dda730(p->CopyVec4ToBuffer(&t[3]));
        FUN_00dda730(p->GetQuad16(&t[4]));
        FUN_00dda730(p->CopyStatsTo(&t[5]));
        HashUInt(p->FUN_00de4900());
        HashUInt(p->FUN_00de48e0());
        HashUInt(p->FUN_00de48f0());
        WriteInt(p->FUN_00de4910());
        break;
    }
    case 7: {
        FUN_00dda730(p->FUN_00de4df0());
        FUN_00dda730(p->FUN_00de4de0());
        FUN_00dda730(p->FUN_00de4e00());
        HashUInt(*p->FUN_00de4e10());
        break;
    }
    }
}
