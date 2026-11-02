
// src/speedtree/lightingengine_ob1_variant.cpp - flag-variant unit created 2026-10-25 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/lightingengine.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/lightingengine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/lightingengine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern double FUN_00ec6054(double);

struct Vec3
{
    float x, y, z;
    __forceinline float& operator[](int index)
    {
        return ((float*)this)[index];
    }
    __forceinline Vec3()
    {
        x = y = z = 0.0f;
    }
    __forceinline Vec3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    void FUN_00b12790()
    {
        float lengthSquared = x * x + y * y + z * z;
        float length = (float)FUN_00ec6054(lengthSquared);
        float reciprocal = 1.0f / length;
        x *= reciprocal;
        y *= reciprocal;
        z *= reciprocal;
    }
    float FUN_00b2a180(void* ptr)
    {
        const Vec3& rhs = *(const Vec3*)ptr;
        float value = x * rhs.x + y * rhs.y + z * rhs.z;
        return value;
    }
    Vec3 FUN_00b13040(void*);
    Vec3 AddVector(const Vec3& rhs)
    {
        return Vec3(x + rhs.x, y + rhs.y, z + rhs.z);
    }
    Vec3 ScaleSwizzled(float value)
    {
        return Vec3(x * value, y * value, z * value);
    }
    Vec3& FUN_00b2a1c0(void* ptr)
    {
        const Vec3& rhs = *(const Vec3*)ptr;
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    float FUN_00b04d40(Vec3* rhs)
    {
        float squared = (rhs->z - z) * (rhs->z - z) + (rhs->y - y) * (rhs->y - y) + (rhs->x - x) * (rhs->x - x);
        int bits = *(int*)&squared;
        bits = (bits >> 1) + 0x1fc00000;
        return *(float*)&bits;
    }
};
struct FourFloatVector
{
    float x, y, z, w;
    void* AddVector(void*, Vec3*, void*, float);
    void* AddVector(void*, void*);
    void* ScaleSwizzled();
};
struct Color
{
    float r, g, b;
    __forceinline const float& operator[](int index) const
    {
        return ((const float*)this)[index];
    }
};
static __declspec(noinline) unsigned int PackChannel(float value, bool adjust, unsigned char alpha)
{
    if (adjust)
        value *= (float)(alpha / 255.0);
    if (value > 1.0)
        value = 1.0f;
    if (value < 0.0)
        value = 0.0f;
    return (unsigned int)(int)(value * 255.0);
}
struct GameContext
{
    int unk00;
    Vec3 rotation;
    int unk10;
    unsigned int packed14;
    unsigned char alpha18, unk19, unk1a, unk1b;
    Vec3 location;
    void FUN_00b40430(float*);
    void FUN_00b404c0(const Color& values, bool adjust)
    {
        unsigned int packed = PackChannel(values.r, adjust, alpha18);
        packed += PackChannel(values.g, adjust, alpha18) << 8;
        packed += PackChannel(values.b, adjust, alpha18) << 16;
        packed14 = packed - 0x1000000;
    }
    void FUN_00b40210(int, Vec3*, float);
    float FUN_00b04d40(Vec3*);
};
struct Record;
struct Iterator
{
    int unk00, unk04;
    void FUN_00b42980(int, Record*);
    __forceinline Iterator(int value, Record* owner)
    {
        FUN_00b42980(value, owner);
    }
    bool FUN_00b2ac30(Iterator*);
    GameContext*& FUN_00b2ab50();
    void FUN_00b2abc0();
    __forceinline bool operator!=(Iterator const& rhs)
    {
        return !FUN_00b2ac30((Iterator*)&rhs);
    }
    __forceinline GameContext*& operator->()
    {
        return FUN_00b2ab50();
    }
};
struct Record
{
    int unk00, unk04, unk08;
    int origin, destination, unk14;
    __forceinline int getBegin()
    {
        return origin;
    }
    __forceinline int GetStreamEnd()
    {
        return destination;
    }
    __forceinline Iterator begin()
    {
        return Iterator(origin, this);
    }
    __forceinline Iterator end()
    {
        return Iterator(destination, this);
    }
};
struct DeviceData
{
    Vec3 position;
    Vec3 scale;
    Vec3 mix;
    int unk24, unk28, unk2c;
    float transformMode;
    float constant, linear, quadratic;
};
extern DeviceData DAT_011ad168[8];
extern unsigned char DAT_011f8d50[8];
extern float DAT_01012054;
extern double DAT_01012060;
extern double DAT_01012070;
__forceinline void BlendWeight(float& weight, float blend)
{
    weight = weight * (1.0 - blend) + blend;
}
struct Scene
{
    int unk00, unk04, unk08, unk0c;
    int unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    int unk30, unk34;
    int state38, unk3c, unk40, unk44;
    Vec3 colors48;
    int unk54, unk58, unk5c;
    Vec3 position60;
    int unk6c;
    float blend70;
    int flags74;
    __forceinline float GetBlend()
    {
        return blend70;
    }
    void FUN_00b2a210(int output, Record* records, int count);
};
// @fnv 0x00b2a210
void Scene::FUN_00b2a210(int output, Record* records, int count)
{
    if (state38 == 1 && flags74 != 0)
    {
        for (int i = 0; i < count; ++i)
        {
            Iterator it = records[i].begin();
            for (; it != records[i].end(); it.FUN_00b2abc0())
            {
                void* location = &it->location;
                void* rotationW = &it->rotation;
                Color origin20;
                it->FUN_00b40430(&origin20.r);
                Vec3 best;
                float maximumW2 = DAT_01012054;
                Vec3 result5;
                for (int j = 0; j < 8; ++j)
                {
                    if (DAT_011f8d50[j])
                    {
                        Vec3 dir(DAT_011ad168[j].position.x, DAT_011ad168[j].position.y, DAT_011ad168[j].position.z);
                        Vec3 normal_29 =
                            DAT_011ad168[j].transformMode == DAT_01012060 ? dir : dir.FUN_00b13040(rotationW);
                        normal_29.FUN_00b12790();
                        float weight = normal_29.FUN_00b2a180(location);
                        if (weight >= maximumW2)
                        {
                            maximumW2 = weight;
                            best = dir;
                        }
                        if (weight < DAT_01012060)
                            weight = 0.0f;
                        BlendWeight(weight, blend70);
                        if ((flags74 & 1) != 0)
                        {
                            Vec3 pos29(position60.x, position60.y, position60.z);
                            Vec3 combined5(DAT_011ad168[j].mix.x * colors48.x, DAT_011ad168[j].mix.y * colors48.y,
                                           DAT_011ad168[j].mix.z * colors48.z);
                            float falloff = 1.0f;
                            if (DAT_011ad168[j].transformMode != DAT_01012060)
                            {
                                float dist8 = ((Vec3*)rotationW)->FUN_00b04d40(&dir);
                                float polynomial = DAT_011ad168[j].constant + DAT_011ad168[j].linear * dist8 +
                                                   DAT_011ad168[j].quadratic * dist8 * dist8;
                                if (polynomial != DAT_01012060)
                                    falloff = 1.0f / polynomial;
                            }
                            Vec3 attenuation((weight * DAT_011ad168[j].scale.x) * origin20[0],
                                             (weight * DAT_011ad168[j].scale.y) * origin20[1],
                                             (weight * DAT_011ad168[j].scale.z) * origin20[2]);
                            result5.FUN_00b2a1c0(
                                &pos29.AddVector(combined5.AddVector(attenuation).ScaleSwizzled(falloff)));
                        }
                    }
                }
                result5[0]<DAT_01012060 ? result5[0] = 0.0 : result5[0]> DAT_01012070 ? result5[0] = 1.0
                                                                                      : result5[0] = result5[0];
                result5[1]<DAT_01012060 ? result5[1] = 0.0 : result5[1]> DAT_01012070 ? result5[1] = 1.0
                                                                                      : result5[1] = result5[1];
                result5[2]<DAT_01012060 ? result5[2] = 0.0 : result5[2]> DAT_01012070 ? result5[2] = 1.0
                                                                                      : result5[2] = result5[2];
                if ((flags74 & 1) != 0)
                {
                    it->FUN_00b404c0((Color&)result5, 0);
                }
                if ((flags74 & 2) != 0)
                {
                    it->FUN_00b40210(output, &best, blend70);
                }
            }
        }
    }
}

struct FUN_0044a4c0
{
    int iAl;
    char acBuf[16];
    int iSize;
    int iRes;
    FUN_0044a4c0(const char* s);
    FUN_0044a4c0(const FUN_0044a4c0& r);
    ~FUN_0044a4c0()
    {
        FUN_0044a730(true, 0);
    }
    void FUN_0044a730(bool b, unsigned n);
};
struct FUN_00b096a0
{
    int aiBase[9];
    FUN_00b096a0(const FUN_0044a4c0& s);
    virtual ~FUN_00b096a0();
};
struct FUN_00b09480 : FUN_00b096a0
{
    FUN_00b09480(const FUN_0044a4c0& msg, bool bErrno);
    virtual ~FUN_00b09480();
};
struct ByteVec
{
    int i0;
    int i4;
    int i8;
    char* pFirst;
    char* pLast;
};
struct Parser
{
    unsigned uiPos;
    ByteVec kData;
    int GetNextElement();
    float FUN_00b3ed20();
};
inline void DeadTop()
{
    int aiD[63];
    aiD[14] = 0;
}
struct LightQ
{
    int iMode;
    float afA[13];
    int iCount;
    float afB[13];
    float fScale;
    int iX;
    int iY;
    float afC[13];
    void FUN_00b2a940(Parser* p);
};
// @fnv 0x00b2a940
void LightQ::FUN_00b2a940(Parser* p)
{
    DeadTop();
    int iToken = p->GetNextElement();
    do
    {
        switch (iToken)
        {
        case 0x1f42:
            iMode = p->GetNextElement();
            break;
        case 0x1f43:
            for (int i = 0; i < 13; i++)
                afA[i] = p->FUN_00b3ed20();
            break;
        case 0x1f44:
            iCount = p->GetNextElement();
            break;
        case 0x1f45:
            for (int j = 0; j < 13; j++)
                afB[j] = p->FUN_00b3ed20();
            break;
        case 0x1f46:
            fScale = p->FUN_00b3ed20();
            break;
        case 0x1f47:
            iX = p->GetNextElement();
            break;
        case 0x1f48:
            iY = p->GetNextElement();
            break;
        case 0x1f49:
            for (int k = 0; k < 13; k++)
                afC[k] = p->FUN_00b3ed20();
            break;
        default:
            throw FUN_00b09480("malformed lighting information", false);
        }
        iToken = p->GetNextElement();
    } while (iToken != 0x1f41);
}
