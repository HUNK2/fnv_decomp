
// src/speedtree/projectedshadow_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/projectedshadow.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/projectedshadow.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/projectedshadow.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct Sub
{
    void FUN_0044a730(int a, int b);
};
struct V3
{
    float x, y, z;
    V3()
    {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }
};
struct FUN_00b3e6c0_cls
{
    V3 a;
    V3 b;
    V3 c;
    Sub s;
    FUN_00b3e6c0_cls* ClearVectors();
};

struct Vec2
{
    float x, y;
};
struct Vec3
{
    float x, y, z;
    Vec3()
    {}
    Vec3(const float* data)
    {
        x = data[0];
        y = data[1];
        z = data[2];
    }
    Vec3& operator=(const Vec3& value)
    {
        x = value.x;
        y = value.y;
        z = value.z;
        return *this;
    }
    Vec3 ScaleSwizzled(float scale) const;
    Vec3 FUN_00b13040(const Vec3& other) const;
    Vec3 AddVector(const Vec3& other) const;
    float FUN_00b04d40(const Vec3& other) const;
};
Vec3 Vec3::ScaleSwizzled(float scale) const
{
    Vec3 r;
    r.x = scale * x;
    r.y = scale * y;
    r.z = scale * z;
    return r;
}
Vec3 Vec3::FUN_00b13040(const Vec3& v) const
{
    Vec3 r;
    r.x = x - v.x;
    r.y = y - v.y;
    r.z = z - v.z;
    return r;
}
Vec3 Vec3::AddVector(const Vec3& v) const
{
    Vec3 r;
    r.x = v.x + x;
    r.y = v.y + y;
    r.z = v.z + z;
    return r;
}
float Vec3::FUN_00b04d40(const Vec3& v) const
{
    union FloatBits
    {
        float value;
        int bits;
    };
    FloatBits squared;
    squared.value = (v.z - z) * (v.z - z) + ((v.y - y) * (v.y - y) + (v.x - x) * (v.x - x));
    FloatBits estimate;
    estimate.bits = (squared.bits >> 1) + 0x1fc00000;
    return estimate.value;
}
__forceinline float Id(float x)
{
    return x;
}
__forceinline void Fill(Vec3* dst, const float* data)
{
    Vec3 r;
    r.x = data[0];
    r.y = data[1];
    r.z = data[2];
    *dst = r;
}
struct Bounds
{
    float upperX, upperY, lowerX, unknown0C, unknown10, lowerY;
    __forceinline float MapX(float value) const
    {
        float aX = lowerX;
        int p6;
        int q5;
        return Id(aX) + (upperX - aX) * Id(value);
    }
    __forceinline float MapY(float value) const
    {
        float aY = lowerY;
        int n2;
        int q1;
        return Id(aY) + (upperY - aY) * Id(value);
    }
};
struct VecRange
{
    unsigned int unknown0, unknown4, unknown8;
    float* begin;
    float* end;
    __forceinline unsigned int Size() const
    {
        return (unsigned int)(end - begin);
    }
};
struct Context
{
    unsigned int unknown00, unknown04, unknown08, unknown0C, unknown10, unknown14, unknown18, unknown1C;
    unsigned short unknown20, count;
    unsigned int unknown24, unknown28, unknown2C, unknown30, unknown34, unknown38, unknown3C;
    unsigned int unknown40, unknown44, unknown48, unknown4C, unknown50, unknown54, unknown58, unknown5C;
    unsigned int unknown60, unknown64, unknown68, unknown6C, unknown70, unknown74, unknown78, unknown7C;
    unsigned int unknown80, unknown84;
    VecRange points;
    const float* FUN_00b30f80(unsigned short index);
    void FUN_00b304f0(Vec2* uv);
};
struct Scr
{
    __forceinline static void Touch()
    {
        int s0;
        int s1;
        int s2;
        int s3;
        int s4;
        int s5;
        int s6;
        int s7;
        int s8;
        int s9;
        int s10;
        int s11;
        int s12;
        int s13;
        int s14;
        int s15;
        int s16;
        int s17;
        int s18;
        int s19;
        int s20;
        int s21;
        int s22;
        int s23;
    }
};
struct Agent
{
    Vec3 first, second;
    Vec3 ProjectOntoLine(const Vec3& start, const Vec3& end, const Vec3& point);
    void FUN_00b3ea10(Context*, Vec3, float, Bounds*);
};
// @fnv 0x00b3ea10
void Agent::FUN_00b3ea10(Context* context, Vec3 point, float extent, Bounds* bounds)
{
    Vec3 lowerAA = point.FUN_00b13040(first.ScaleSwizzled(extent));
    Vec3 kUpperA = point.AddVector(first.ScaleSwizzled(extent));
    Vec3 lowerB6 = point.FUN_00b13040(second.ScaleSwizzled(extent));
    Vec3 upperB4 = point.AddVector(second.ScaleSwizzled(extent));
    Scr::Touch();
    context->count = 0;
    for (unsigned short index3 = 0; index3 < (unsigned short)(context->points.Size() / 3); ++index3)
    {
        const float* input = context->FUN_00b30f80(index3);
        Vec3 value2;
        Fill(&value2, input);
        Vec3 projectedA7 = ProjectOntoLine(lowerAA, kUpperA, value2);
        Vec2 uv5;
        uv5.x = lowerAA.FUN_00b04d40(projectedA7) / (extent * 2.0f);
        if (bounds)
        {
            uv5.x = bounds->MapX(uv5.x);
        }
        Vec3 projectedB2 = ProjectOntoLine(lowerB6, upperB4, value2);
        uv5.y = lowerB6.FUN_00b04d40(projectedB2) / (extent * 2.0f);
        if (bounds)
        {
            uv5.y = bounds->MapY(uv5.y);
        }
        context->FUN_00b304f0(&uv5);
    }
}

#include <string>
#include <memory>
#include <stdexcept>
template <> std::string& std::string::assign(const std::string&, unsigned int, unsigned int);
template <> std::string& std::string::assign(const char*);
template <> std::_String_val<char, std::allocator<char> >::_String_val(std::allocator<char>);

struct Point3
{
    float x, y, z;
    void operator=(const Point3& r)
    {
        x = r.x;
        y = r.y;
        z = r.z;
    }
};

struct Vec3Ret
{
    float x, y, z;
    operator const Point3&() const
    {
        return *(const Point3*)this;
    }
};

class IdvFileError : public std::runtime_error
{
  public:
    IdvFileError(const std::string& message, bool system = false)
        : std::runtime_error(message + " [" + (system ? std::string(strerror(errno)) : std::string("")) + "]")
    {}
};

struct NarrowString : std::string
{
    NarrowString(std::string s) : std::string(s)
    {}
    std::string FUN_00b09f90();
};

std::string __cdecl FUN_00b18860(const char*, ...);

struct ChunkReader
{
    int GetNextElement();
    Vec3Ret GetVector3();
    std::string FUN_00b3ee40();
};

struct FrondInfo
{
    Point3 p0, p1, p2;
    std::string name;
    void FUN_00b3e750(ChunkReader*);
};

// @fnv 0x00b3e750
void FrondInfo::FUN_00b3e750(ChunkReader* reader)
{
    int token = reader->GetNextElement();
    do
    {
        switch (token)
        {
        case 0x4652:
            p0 = reader->GetVector3();
            break;
        case 0x4653:
            p1 = reader->GetVector3();
            break;
        case 0x4654:
            p2 = reader->GetVector3();
            break;
        case 0x4655: {
            NarrowString text(reader->FUN_00b3ee40());
            name = text.FUN_00b09f90();
            break;
        }
        default:
            throw IdvFileError(FUN_00b18860("malformed frond info (token %d)", token));
        }
        token = reader->GetNextElement();
    } while (token != 0x4651);
}
