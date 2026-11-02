
// src/havok/common/base/math/vector/hkvector4.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/math/vector/hkvector4.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// CheckFloatsFinite (0x00c7f4e0, 21 bytes)
//
// The original is a __thiscall member of a class whose object *is* the float
// array.  It forwards to a file-static helper FUN_00c7f4a0(out, self, count).
//
// MSVC 2008 gives an internal-linkage (file-static) helper its own internal
// "register argument" convention: instead of pushing the arguments on the
// stack they are passed in registers.  With the helper declared as
//     static void* FUN_00c7f4a0(void* out, void* self, int count)
// MSVC 2008 assigns  out->EAX, self->ESI, count->EDX  and the call site
// becomes exactly
//     mov eax,[esp+4] / push esi / mov edx,3 / mov esi,ecx / call / pop esi / ret 4
// The helper returns its first argument, which is what pins that argument
// to EAX; the parameter order (out, self, count) is what makes the call site
// materialise EDX before ESI.

struct Cls_c7f4e0
{
    float unk00[8];
    void CheckFloatsFinite(void* out);
};

static __declspec(noinline) void* FUN_00c7f4a0(void* out, void* self, int count)
{
    for (int i = 0; i < count; i++)
    {
        float v = ((float*)self)[i];
        int bits = *(int*)&v;
        if ((bits & 0x7f800000) == 0x7f800000)
        {
            *(char*)out = 0;
            return out;
        }
    }
    *(char*)out = 1;
    return out;
}

// @fnv 0x00c7f4e0
void Cls_c7f4e0::CheckFloatsFinite(void* pResult)
{
    FUN_00c7f4a0(pResult, this, 3);
}

#include <xmmintrin.h>
extern __m128 DAT_01267e30;

struct SubVecHolder;
struct FUN_00c7f700_cls
{
    __m128 m_result;
    void FUN_00c7f700(void* first, void* second);
};

struct VecSource
{
    __m128* FUN_00cac910();
};

struct HolderNode
{
    int unk00;
    int unk04;
    char* m_p08;
};

struct FUN_00c6e300_cls
{
    int unk00;
    int unk04;
    VecSource* m_p08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    HolderNode* m_p594;

    void FUN_00c89720();
    void SubtractVectors(__m128* out);
};

// Subtracts res.m_result from the selected vector and stores the difference in out.
// @fnv 0x00c6e300
void FUN_00c6e300_cls::SubtractVectors(__m128* apResult)
{
    HolderNode* holder = m_p594;
    char* base = holder ? holder->m_p08 : 0;

    FUN_00c7f700_cls res;
    res.FUN_00c7f700(base + 0xb0, (char*)this + 0x570);

    __m128* vec = &DAT_01267e30;
    VecSource* src = m_p08;
    if (src != 0)
    {
        FUN_00c89720();
        vec = src->FUN_00cac910();
        FUN_00c89720();
    }

    __m128 a = *vec;
    __m128 b = res.m_result;
    *apResult = _mm_sub_ps(a, b);
}

struct __declspec(align(16)) Vec4
{
    float x, y, z, w;
    void FUN_00c7f690(void* transform, const Vec4* value);
    void FUN_00c7f700(void* transform, const Vec4* value);
};

typedef __m128 VecArr;

struct HkBool
{
    char m_cBooleanValue;
    HkBool()
    {}
    HkBool(bool b) : m_cBooleanValue((char)b)
    {}
};

struct HitResult;

struct CastInput
{
    Vec4 from;
    Vec4 to;
    unsigned int unk20;
    void* unk24;
    CastInput() : unk20(0), unk24(0)
    {}
};

struct CollisionObject
{
    virtual void ReportDiagnostic() = 0;
    virtual void unused1() = 0;
    virtual void unused2() = 0;
    virtual void FlushUsageData() = 0;
    virtual void unused4() = 0;
    virtual void unused5() = 0;
    virtual void unused6() = 0;
    virtual void unused7() = 0;
    virtual HkBool RayCast(const CastInput& input, HitResult& result) const = 0;
    int unknown04;
    int unknown08;
    int type0c;
};

struct HitResult
{
    float normalX, normalY, normalZ, normalW;
    float fraction;
    int faceIndex;
    float unknown18, unknown1c;
    unsigned int shapeKeys[8];
    unsigned int flag40;
    int unknown44;
    int unknown48;
    int unknown4c;
    HitResult()
    {
        reset();
    }
    void reset()
    {
        fraction = 1.0f;
        faceIndex = -1;
        shapeKeys[0] = (unsigned int)-1;
        flag40 = 0;
    }
};

struct Geometry
{
    CollisionObject* collision;
    int unk04;
    void* transform;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int flags;
};

struct State
{
    int* itemAt(int index) const
    {
        return *(int**)(*(char**)((char*)this + 0x160) + index * 8 + 4);
    }
    int count() const
    {
        return *(int*)((char*)this + 0x164);
    }
};

struct Node
{
    int unk00;
    int unk04;
    State* state;
};

struct bhkCharacterController;
extern float __fastcall GetSettingFloat(bhkCharacterController* controller);

extern float DAT_01011d78;
extern float DAT_01267bcc;
extern double DAT_010290b0;
extern double DAT_0102f070;

struct bhkCharacterController
{
    void SubtractVectors(Vec4* result);
    bool FUN_00c6fa20();
};

// Casts rays between transformed points, adjusts both z coordinates by advance, and returns true when a cast fraction is below 1.
// @fnv 0x00c6fa20
bool bhkCharacterController::FUN_00c6fa20()
{
    Node* node = *(Node**)((char*)this + 0x594);
    State* state = node ? node->state : 0;
    float advance = *(float*)((char*)this + 0x564) * DAT_010290b0;
    float range = DAT_01267bcc * DAT_0102f070 + GetSettingFloat(this);
    Vec4 value;
    *(__m128*)&value = _mm_setr_ps(DAT_01011d78, range, DAT_01011d78, DAT_01011d78);
    State* transformState = node ? node->state : 0;
    value.FUN_00c7f700((char*)transformState + 0xb0, &value);
    Vec4 vStart;
    this->SubtractVectors(&vStart);
    VecArr vFinish;
    *(__m128*)&vFinish = _mm_add_ps(*(__m128*)&vStart, *(__m128*)&value);

    for (int i = 0; i < state->count(); ++i)
    {
        Geometry* geom = (Geometry*)state->itemAt(i);
        if (!geom)
            continue;
        switch (geom->flags & 0x7f)
        {
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 10:
        case 11:
        case 12:
        case 16:
        case 17:
        case 22:
        case 23:
        case 24:
        case 29:
        case 30:
            continue;
        }
        CollisionObject* __restrict shape = geom->collision;
        if (shape->type0c != 8 && shape->type0c != 6 && shape->type0c != 10)
            continue;

        Geometry* __restrict body = geom;
        CastInput input;
        HitResult result;
        input.from.FUN_00c7f690(body->transform, &vStart);
        input.to.FUN_00c7f690(geom->transform, (Vec4*)&vFinish);

        bool hit = false;
        unsigned int j = 0;
        do
        {
            result.fraction = 1.0f;
            input.from.z += advance;
            input.to.z += advance;
            result.faceIndex = -1;
            result.shapeKeys[0] = (unsigned int)-1;
            result.flag40 = 0;
            shape->RayCast(input, result);
            if (result.fraction < 1.0f)
            {
                hit = true;
                break;
            }
        } while (++j < 3);

        input.from.FUN_00c7f690(geom->transform, (Vec4*)&vFinish);
        input.to.FUN_00c7f690(geom->transform, &vStart);

        if (!hit)
        {
            for (unsigned int j = 0; j < 3; ++j)
            {
                result.fraction = 1.0f;
                input.from.z += advance;
                input.to.z += advance;
                result.faceIndex = -1;
                result.shapeKeys[0] = (unsigned int)-1;
                result.flag40 = 0;
                shape->RayCast(input, result);
                if (result.fraction < 1.0f)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

struct __declspec(align(16)) SpawnedMatrix
{
    __m128 m_row0;
    __m128 m_row1;
    __m128 m_row2;
    __m128 m_row3;
};

struct __declspec(align(16)) FUN_00c7f640_cls
{
    __m128 m_vResult;

    void FUN_00c7f640(const SpawnedMatrix* apMatrix, const __m128* apVector);
};

// Combines the vector's first three components with matrix rows 0-2, adds row3, and stores the result in m_vResult.
// @fnv 0x00c7f640
void FUN_00c7f640_cls::FUN_00c7f640(const SpawnedMatrix* apMatrix, const __m128* apVector)
{
    __m128 vVec = *apVector;
    __m128 vY = _mm_shuffle_ps(vVec, vVec, 0x55);
    __m128 vT1 = _mm_mul_ps(vY, apMatrix->m_row1);
    __m128 vX = _mm_shuffle_ps(vVec, vVec, 0);
    __m128 vT2 = _mm_mul_ps(vX, apMatrix->m_row0);
    vT1 = _mm_add_ps(vT1, vT2);
    __m128 vZ = _mm_shuffle_ps(vVec, vVec, 0xaa);
    __m128 vT3 = _mm_mul_ps(vZ, apMatrix->m_row2);
    vT3 = _mm_add_ps(vT3, apMatrix->m_row3);
    m_vResult = _mm_add_ps(vT1, vT3);
}

struct S_00c7f690_V
{
    __m128 q;
};
struct S_00c7f690_M
{
    S_00c7f690_V c0, c1, c2, c3;
};
struct FUN_00c7f690_cls
{
    void FUN_00c7f690(const S_00c7f690_M* m, const S_00c7f690_V* v);
};

// Subtracts m->c3 from v, multiplies the difference by components assembled from m->c0 through m->c2, and stores the result in this.
// @fnv 0x00c7f690
void FUN_00c7f690_cls::FUN_00c7f690(const S_00c7f690_M* apMatrix, const S_00c7f690_V* apVector)
{
    S_00c7f690_V vDelta;
    vDelta.q = _mm_sub_ps(apVector->q, apMatrix->c3.q);
    __m128 a0 = apMatrix->c0.q, a1 = apMatrix->c1.q, a2 = apMatrix->c2.q;
    __m128 vTmp0 = _mm_unpacklo_ps(a0, a1);
    __m128 vTmp1 = _mm_unpackhi_ps(a0, a1);
    a0 = _mm_movelh_ps(vTmp0, a2);
    a1 = _mm_shuffle_ps(_mm_movehl_ps(a0, vTmp0), a2, 0xd4);
    a2 = _mm_shuffle_ps(vTmp1, a2, 0xe4);
    __m128 x = _mm_shuffle_ps(vDelta.q, vDelta.q, 0x00);
    __m128 y = _mm_shuffle_ps(vDelta.q, vDelta.q, 0x55);
    __m128 z = _mm_shuffle_ps(vDelta.q, vDelta.q, 0xaa);
    ((S_00c7f690_V*)this)->q = _mm_add_ps(_mm_add_ps(_mm_mul_ps(y, a1), _mm_mul_ps(x, a0)), _mm_mul_ps(a2, z));
}

namespace fnv_00c7f700 {
struct MatrixRows3x4
{
    __m128 row0;
    __m128 row1;
    __m128 row2;
    __m128 row3;
};

struct FUN_00c7f700_cls
{
    __m128 m_result;

    void FUN_00c7f700(MatrixRows3x4* matrix, __m128* vec);
};

// Multiplies a 3D vector by the first three rows of a 3x4 matrix and stores the result in m_result.
// @fnv 0x00c7f700
void FUN_00c7f700_cls::FUN_00c7f700(MatrixRows3x4* matrix, __m128* apVector)
{
    __m128 v = *apVector;
    __m128 vx = _mm_shuffle_ps(v, v, 0x00);
    __m128 vy = _mm_shuffle_ps(v, v, 0x55);
    __m128 vz = _mm_shuffle_ps(v, v, 0xaa);

    __m128 r = _mm_mul_ps(vy, matrix->row1);
    r = _mm_add_ps(r, _mm_mul_ps(vx, matrix->row0));
    r = _mm_add_ps(r, _mm_mul_ps(vz, matrix->row2));
    m_result = r;
}
}  // namespace fnv_00c7f700

struct FUN_00c7f750_shell
{
    void __thiscall FUN_00c7f750(float* matrix, float* vector);
};
// Multiplies a 3D vector by a 3x3 matrix using SSE and stores the resulting vector in the object.
// @fnv 0x00c7f750
void __thiscall FUN_00c7f750_shell::FUN_00c7f750(float* matrix, float* vector)
{
    __m128 v = *(__m128*)vector;
    __m128 y = _mm_mul_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(1, 1, 1, 1)), *(__m128*)(matrix + 4));
    __m128 x = _mm_mul_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(0, 0, 0, 0)), *(__m128*)matrix);
    __m128 result = _mm_add_ps(y, x);
    __m128 z = _mm_mul_ps(_mm_shuffle_ps(v, v, _MM_SHUFFLE(2, 2, 2, 2)), *(__m128*)(matrix + 8));
    result = _mm_add_ps(result, z);
    *(__m128*)this = result;
}

struct QueryScalar
{
    __m128 q;
    QueryScalar()
    {}
    QueryScalar(const __m128& value) : q(value)
    {}
    QueryScalar(const QueryScalar& value) : q(value.q)
    {}
    operator float() const
    {
        float v;
        _mm_store_ss(&v, q);
        return v;
    }
};
// Character support query with triangle and general shape paths.
struct Mat16;
struct QueryVector
{
    __m128 q;
    QueryVector()
    {}
    QueryScalar get(int i) const
    {
        switch (i)
        {
        case 0:
            return q;
        case 1:
            return _mm_shuffle_ps(q, q, 85);
        case 2:
            return _mm_shuffle_ps(q, q, 170);
        default:
            return _mm_shuffle_ps(q, q, 255);
        }
    }
    float& operator()(int i)
    {
        return ((float*)&q)[i];
    }
    QueryVector(const QueryVector& x)
    {
        q = x.q;
    }
    QueryVector& operator=(const QueryVector& x)
    {
        const __m128& ref = x.q;
        q = ref;
        return *this;
    }
    void FUN_00c7f640(void* a, const QueryVector* v);
    void FUN_00c7f690(const Mat16* t, const QueryVector* v);
};
struct Mat16
{
    QueryVector col[4];
};
struct BoundingVolumeNode
{
    void* f00;
    int u04;
    BoundingVolumeNode* child;
    int type;
    union
    {
        int f10;
        float radius;
    };
    int u014;
    int u018;
    int u01c;
    union
    {
        __m128 points[3];
        struct
        {
            int u020, u024, u028, u02c, u030;
            BoundingVolumeNode* f34;
        };
    };
    int FUN_00c84f10(int key);
};
struct VarObj
{
    BoundingVolumeNode* first;
    int u04;
    int u08;
    int u0c;
    char b10;
    char u11;
    char u12;
    char u13;
    int u14;
    char type;
    char u19;
    char u1a;
    char u1b;
    int u1c;
    int u020;
    int u024;
    int u028;
    int u02c;
    int u030;
    int u034;
    int u038;
    int u03c;
    int u040;
    int u044;
    int u048;
    int u04c;
    int u050;
    int u054;
    int u058;
    int u05c;
    int u060;
    int u064;
    int u068;
    int u06c;
    int u070;
    int u074;
    int u078;
    int u07c;
    int u080;
    int u084;
    int u088;
    int u08c;
    int u090;
    int u094;
    int u098;
    int u09c;
    int u0a0;
    int u0a4;
    int u0a8;
    int u0ac;
    int u0b0;
    int u0b4;
    int u0b8;
    int u0bc;
    int u0c0;
    int u0c4;
    int u0c8;
    int u0cc;
    int u0d0;
    int u0d4;
    int u0d8;
    int u0dc;
    int u0e0;
    int u0e4;
    int u0e8;
    int u0ec;
    Mat16 mat;
};
struct ArgObj
{
    float v[4];
    int u10;
    int u14;
    int u18;
    int u1c;
    VarObj* f20;
    int u024;
    int u028;
    int u02c;
    int u030;
    int u034;
    int u038;
    int u03c;
    int u040;
    int u044;
    VarObj* f48;
    int f4c;
};
struct Sub410
{
    int s000;
    int flags;
    int s008;
    int s00c;
    int s010;
    int s014;
    int s018;
    int s01c;
    int s020;
    int s024;
    int s028;
    int s02c;
    int s030;
    int s034;
    int s038;
    int s03c;
    int s040;
    int s044;
    int s048;
    int s04c;
    int s050;
    int s054;
    int s058;
    int s05c;
    void AccumulateValue(void* a, float f);
};
struct ThisCls
{
    int u000;
    int u004;
    int u008;
    int u00c;
    int u010;
    int u014;
    int u018;
    int u01c;
    int u020;
    int u024;
    int u028;
    int u02c;
    int u030;
    int u034;
    int u038;
    int u03c;
    int u040;
    int u044;
    int u048;
    int u04c;
    int u050;
    int u054;
    int u058;
    int u05c;
    int u060;
    int u064;
    int u068;
    int u06c;
    int u070;
    int u074;
    int u078;
    int u07c;
    int u080;
    int u084;
    int u088;
    int u08c;
    int u090;
    int u094;
    int u098;
    int u09c;
    int u0a0;
    int u0a4;
    int u0a8;
    int u0ac;
    int u0b0;
    int u0b4;
    int u0b8;
    int u0bc;
    int u0c0;
    int u0c4;
    int u0c8;
    int u0cc;
    int u0d0;
    int u0d4;
    int u0d8;
    int u0dc;
    int u0e0;
    int u0e4;
    int u0e8;
    int u0ec;
    int u0f0;
    int u0f4;
    int u0f8;
    int u0fc;
    int u100;
    int u104;
    int u108;
    int u10c;
    int u110;
    int u114;
    int u118;
    int u11c;
    int u120;
    int u124;
    int u128;
    int u12c;
    int u130;
    int u134;
    int u138;
    int u13c;
    int u140;
    int u144;
    int u148;
    int u14c;
    int u150;
    int u154;
    int u158;
    int u15c;
    int u160;
    int u164;
    int u168;
    int u16c;
    int u170;
    int u174;
    int u178;
    int u17c;
    int u180;
    int u184;
    int u188;
    int u18c;
    int u190;
    int u194;
    int u198;
    int u19c;
    int u1a0;
    int u1a4;
    int u1a8;
    int u1ac;
    int u1b0;
    int u1b4;
    int u1b8;
    int u1bc;
    int u1c0;
    int u1c4;
    int u1c8;
    int u1cc;
    int u1d0;
    int u1d4;
    int u1d8;
    int u1dc;
    int u1e0;
    int u1e4;
    int u1e8;
    int u1ec;
    int u1f0;
    int u1f4;
    int u1f8;
    int u1fc;
    int u200;
    int u204;
    int u208;
    int u20c;
    int u210;
    int u214;
    int u218;
    int u21c;
    int u220;
    int u224;
    int u228;
    int u22c;
    int u230;
    int u234;
    int u238;
    int u23c;
    int u240;
    int u244;
    int u248;
    int u24c;
    int u250;
    int u254;
    int u258;
    int u25c;
    int u260;
    int u264;
    int u268;
    int u26c;
    int u270;
    int u274;
    int u278;
    int u27c;
    int u280;
    int u284;
    int u288;
    int u28c;
    int u290;
    int u294;
    int u298;
    int u29c;
    int u2a0;
    int u2a4;
    int u2a8;
    int u2ac;
    int u2b0;
    int u2b4;
    int u2b8;
    int u2bc;
    int u2c0;
    int u2c4;
    int u2c8;
    int u2cc;
    int u2d0;
    int u2d4;
    int u2d8;
    int u2dc;
    int u2e0;
    int u2e4;
    int u2e8;
    int u2ec;
    int u2f0;
    int u2f4;
    int u2f8;
    int u2fc;
    int u300;
    int u304;
    int u308;
    int u30c;
    int u310;
    int u314;
    int u318;
    int u31c;
    int u320;
    int u324;
    int u328;
    int u32c;
    int u330;
    int u334;
    int u338;
    int u33c;
    int u340;
    int u344;
    int u348;
    int u34c;
    int u350;
    int u354;
    int u358;
    int u35c;
    int u360;
    int u364;
    int u368;
    int u36c;
    int u370;
    int u374;
    int u378;
    int u37c;
    int u380;
    int u384;
    int u388;
    int u38c;
    int u390;
    int u394;
    int u398;
    int u39c;
    int u3a0;
    int u3a4;
    int u3a8;
    int u3ac;
    int u3b0;
    int u3b4;
    int u3b8;
    int u3bc;
    int u3c0;
    int u3c4;
    int u3c8;
    int u3cc;
    int u3d0;
    int u3d4;
    int u3d8;
    int u3dc;
    int u3e0;
    int u3e4;
    int u3e8;
    int u3ec;
    int u3f0;
    int u3f4;
    int u3f8;
    int u3fc;
    int u400;
    int u404;
    int u408;
    int u40c;
    Sub410 sub;
    float x470;
    float x474;
    int u478;
    int u47c;
    int u480;
    int u484;
    int u488;
    int u48c;
    int u490;
    int u494;
    int u498;
    int u49c;
    int u4a0;
    int u4a4;
    int u4a8;
    int u4ac;
    int u4b0;
    int u4b4;
    int u4b8;
    int u4bc;
    int u4c0;
    int u4c4;
    int u4c8;
    int u4cc;
    int u4d0;
    int u4d4;
    int u4d8;
    int u4dc;
    int u4e0;
    int u4e4;
    int u4e8;
    int u4ec;
    int u4f0;
    int u4f4;
    int u4f8;
    int u4fc;
    int u500;
    int u504;
    int u508;
    int u50c;
    int u510;
    int u514;
    int u518;
    int u51c;
    int u520;
    int u524;
    int u528;
    int u52c;
    int u530;
    int u534;
    int u538;
    int u53c;
    int u540;
    int u544;
    int u548;
    int u54c;
    int u550;
    int u554;
    int u558;
    int u55c;
    int u560;
    int u564;
    int u568;
    int u56c;
    int u570;
    int u574;
    int u578;
    int u57c;
    int u580;
    int u584;
    int u588;
    int u58c;
    int u590;
    int u594;
    int u598;
    int u59c;
    int u5a0;
    int u5a4;
    int u5a8;
    int u5ac;
    QueryVector slots[3];
    QueryVector unk5e0;
    float x5f0;
    float x5f4;
    int u5f8;
    void SubtractVectors(void* out);
    char FUN_00c6eb00(ArgObj* arg);
};
struct ShapeStorage
{
    __declspec(align(16)) char bytes[512];
};
struct Iface
{
    void** vtbl;
};
struct ResObj
{
    int u00;
    int u04;
    int u08;
    int u0c;
    Iface iface;
};
typedef BoundingVolumeNode*(__thiscall* ResFn)(Iface* self, int id, ShapeStorage* out);
struct RayIn
{
    QueryVector vectors[2];
    int filter;
    void* collectionFilter;
};
struct RayOut
{
    __m128 normal;
    float fraction;
    int extra;
    int u18;
    int u1c;
    unsigned int keys[8];
    int keyIndex;
};
struct Contact
{
    __m128 normal;
    int u10, u14, u18;
    float distance;
};
struct Contacts
{
    Contact hit[3];
};
union CollisionOutput
{
    RayOut ray;
    Contacts contacts;
};
struct Plane
{
    float x, y, z, w, area;
};
struct BoolResult
{
    char value;
    BoolResult(char v) : value(v)
    {}
};
struct RayShape
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual BoolResult cast(const RayIn&, RayOut&) const;
};
__declspec(noinline) void* __cdecl GetValidatedPointer(void* obj)
{
    BoundingVolumeNode* n = (BoundingVolumeNode*)obj;
    BoundingVolumeNode* result = 0;
    if (n)
    {
        int type = n->type;
        if (type == 10)
        {
            n = n->f34;
            type = n->type;
        }
        if (type == 0x17 || type == 0x1e || type == 0x1f)
            result = n;
    }
    return result;
}
void __cdecl ComputeInverseLengths(const QueryVector* triangle, Plane* plane);
void __cdecl FUN_00cd6520(const QueryVector* ray, float tolerance, const QueryVector* triangle, float radius,
                          const Plane* plane, float zero, int flags, Contacts* contacts, void* extra);
char __cdecl FUN_00c6d7e0(BoundingVolumeNode* obj, int one, char v, int id);
typedef char(__cdecl* PredFn)(int v);
extern PredFn DAT_01267bc8;
extern "C" void _ReadWriteBarrier();
extern float DAT_01011d78;
static __forceinline float scalar(__m128 x)
{
    float value;
    _mm_store_ss(&value, x);
    return value;
}
static __forceinline __m128 squared3(__m128 v)
{
    __m128 products = _mm_mul_ps(v, v);
    __m128 xy = _mm_add_ss(_mm_shuffle_ps(products, products, 85), products);
    return _mm_add_ss(_mm_shuffle_ps(products, products, 170), xy);
}
static __forceinline __m128 normalized3(__m128 v)
{
    __m128 half = _mm_set_ss(0.5f);
    __m128 three = _mm_set_ss(3.0f);
    __m128 zero = _mm_set_ss(0.0f);
    __m128 square = squared3(v);
    __m128 isZero = _mm_cmpeq_ss(square, zero);
    __m128 estimate = _mm_rsqrt_ss(square);
    __m128 correction = _mm_sub_ss(three, _mm_mul_ss(_mm_mul_ss(square, estimate), estimate));
    __m128 inverse = _mm_andnot_ps(isZero, _mm_mul_ss(_mm_mul_ss(half, estimate), correction));
    return _mm_mul_ps(_mm_shuffle_ps(inverse, inverse, 0), v);
}
static __forceinline void transformed(QueryVector& r, const Mat16& m, __m128 v)
{
    __m128 px = _mm_mul_ps(_mm_shuffle_ps(v, v, 0), m.col[0].q);
    __m128 py = _mm_mul_ps(_mm_shuffle_ps(v, v, 85), m.col[1].q);
    __m128 pz = _mm_mul_ps(_mm_shuffle_ps(v, v, 170), m.col[2].q);
    r.q = _mm_add_ps(_mm_add_ps(py, px), _mm_add_ps(pz, m.col[3].q));
}
static __forceinline __m128 make4(float x, float y, float z, float w)
{
    return _mm_setr_ps(x, y, z, w);
}
static __forceinline QueryVector subtractVectors(const QueryVector& a, const QueryVector& b)
{
    QueryVector result;
    result.q = _mm_sub_ps(a.q, b.q);
    return result;
}
struct CastWorkspace
{
    QueryVector direction, origin, endpoint;
    RayIn input;
    QueryVector pos;
    Mat16 scratch;
    CollisionOutput output;
    ShapeStorage storage;
};
// Checks filters and geometry, may run a ray cast or contact query, and returns the resulting flag.
// @fnv 0x00c6eb00
char ThisCls::FUN_00c6eb00(ArgObj* arg)
{
    ArgObj* a = arg;
    VarObj* o20 = a->f20;
    void* decoded20;
    if (o20->type == 2)
        decoded20 = (char*)o20 + (signed char)o20->b10;
    else
        decoded20 = 0;
    VarObj* o48 = a->f48;
    VarObj* decoded48;
    if (o48->type == 1)
        decoded48 = (VarObj*)((char*)o48 + (signed char)o48->b10);
    else
        decoded48 = 0;
    bool flag = false;
    int iIndex = 0;
    if (decoded48)
    {
        BoundingVolumeNode* found = 0;
        BoundingVolumeNode* n = o48->first;
        if (n)
        {
            int type = n->type;
            if (type == 10)
            {
                n = n->f34;
                type = n->type;
            }
            if (type == 0x17 || type == 0x1e || type == 0x1f)
                found = n;
        }
        int key = a->f4c;
        bool allowed = true;
        if (found && found->child)
        {
            BoundingVolumeNode* child = found->child;
            int v = key != -1 ? child->FUN_00c84f10(key) : child->f10 & 31;
            char c = 0;
            if (DAT_01267bc8)
                c = DAT_01267bc8(v);
            allowed = c == 0;
        }
        flag = allowed == 0;
        if (flag)
            goto end;
    }
    if (!decoded20 || !decoded48)
        goto end;
    {
        BoundingVolumeNode* shape = a->f48->first;
        float scale = x5f0;
        BoundingVolumeNode* node5 = 0;
        BoundingVolumeNode* pNode20 = a->f20->first;
        if (pNode20->type == 5)
        {
            node5 = pNode20;
            scale = pNode20->radius;
        }
        QueryVector direction;
        QueryVector origin;
        QueryVector endpoint;
        RayIn input;
        QueryVector pos;
        Mat16 scratch;
        CollisionOutput output;
        ShapeStorage storage;
        pos.q = _mm_load_ps(a->v);
        float sourceZ = (float)pos.get(2);
        SubtractVectors(&origin);
        if (sub.flags & 1)
        {
            unsigned i = 0;
            void* tm = &((VarObj*)decoded20)->u0b0;
            for (; i < 2; ++i)
            {
                if (node5)
                    direction.q = node5->points[i];
                else
                {
                    direction.q = make4(0.0f, (float)(x5f4 * 0.5), scale, 0.0f);
                    if (i == 1)
                        direction.q.m128_f32[1] = (float)(direction.q.m128_f32[1] * -1.0);
                }
                slots[i].FUN_00c7f640(tm, &direction);
                slots[i].q.m128_f32[2] += x470;
                input.vectors[i] = subtractVectors(pos, slots[i]);
            }
            float d0 = scalar(squared3(input.vectors[0].q));
            float d1 = scalar(squared3(input.vectors[1].q));
            iIndex = 0;
            if (!(d0 < d1))
                iIndex = 1;
            origin(0) = (float)slots[iIndex].get(0);
            origin(1) = (float)slots[iIndex].get(1);
        }
        __m128 vLeft = origin.q;
        _ReadWriteBarrier();
        direction.q = _mm_sub_ps(vLeft, pos.q);
        direction.q.m128_f32[2] = 0.0f;
        origin(2) += x470;
        __m128 vNormalized = normalized3(direction.q);
        pos.q.m128_f32[2] = (float)origin.get(2);
        float fDeltaZ = sourceZ - (float)origin.get(2);
        direction.q = vNormalized;
        char side = 1;
        if (!(fDeltaZ > 0.0f))
            side = 0;
        float limit = (float)(x470 / 3.0);
        if (fDeltaZ > limit)
        {
            if (!(sub.flags & 1))
                goto end;
            fDeltaZ = sourceZ - slots[iIndex].q.m128_f32[2] + x470;
            if (fDeltaZ > 0.0f)
            {
                if (fDeltaZ > limit)
                    goto end;
                side = 1;
            }
        }
        int childKey = a->f4c;
        if (childKey != -1)
        {
            ResObj* pResObj = (ResObj*)GetValidatedPointer(shape);
            if (pResObj)
            {
                BoundingVolumeNode* triangle = ((ResFn)pResObj->iface.vtbl[5])(&pResObj->iface, childKey, &storage);
                __m128 c0 = decoded48->mat.col[0].q;
                __m128 c1 = decoded48->mat.col[1].q;
                __m128 c2 = decoded48->mat.col[2].q;
                __m128 c3 = decoded48->mat.col[3].q;
                for (int k = 2; k >= 0; --k)
                {
                    __m128 v = triangle->points[k];
                    __m128 x = _mm_mul_ps(c0, _mm_shuffle_ps(v, v, 0));
                    __m128 y = _mm_mul_ps(c1, _mm_shuffle_ps(v, v, 85));
                    __m128 z = _mm_mul_ps(c2, _mm_shuffle_ps(v, v, 170));
                    scratch.col[k].q = _mm_add_ps(_mm_add_ps(y, x), _mm_add_ps(z, c3));
                }
                Plane plane;
                ComputeInverseLengths(scratch.col, &plane);
                input.vectors[1].q = pos.q;
                input.vectors[0].q = pos.q;
                input.vectors[1].q.m128_f32[0] -= scalar(direction.q) * x474;
                input.vectors[1].q.m128_f32[1] -= scalar(_mm_shuffle_ps(direction.q, direction.q, 85)) * x474;
                FUN_00cd6520(input.vectors, 0.05f, scratch.col, triangle->radius, &plane, 0.0f, 0, &output.contacts, 0);
                flag = output.contacts.hit[0].distance >= 0.0f && output.contacts.hit[1].distance >= 0.0f;
                goto end;
            }
        }
        {
            unsigned int uiLastKey = ~0U;
            input.filter = 0;
            input.collectionFilter = 0;
            output.ray.fraction = 1.0f;
            output.ray.extra = -1;
            output.ray.keyIndex = 0;
            output.ray.keys[0] = -1;
            endpoint.q = origin.q;
            scale = x474 + scale;
            endpoint.q.m128_f32[0] -= scalar(direction.q) * scale;
            endpoint.q.m128_f32[1] -= scalar(_mm_shuffle_ps(direction.q, direction.q, 85)) * scale;
            scratch.col[0].q = decoded48->mat.col[0].q;
            scratch.col[1].q = decoded48->mat.col[1].q;
            scratch.col[2].q = decoded48->mat.col[2].q;
            scratch.col[3].q = decoded48->mat.col[3].q;
            input.vectors[0].FUN_00c7f690(&scratch, &origin);
            input.vectors[1].FUN_00c7f690(&scratch, &endpoint);
            ((RayShape*)shape)->cast(input, output.ray);
            if (output.ray.fraction < 1.0f)
            {
                for (int j = 0; j < 8; ++j)
                {
                    unsigned int key = output.ray.keys[j];
                    if (key == -1)
                        break;
                    uiLastKey = key;
                }
                flag = FUN_00c6d7e0(shape, 1, side, uiLastKey) == 0;
            }
            else
            {
                flag = true;
            }
        }
    }
end:
    if ((sub.flags & 1) && flag)
        sub.AccumulateValue((void*)iIndex, scalar(_mm_shuffle_ps(_mm_load_ps(a->v), _mm_load_ps(a->v), 170)));
    return flag;
}
