
// src/gamebryo2.2/corelibs/nicollision/niobbleaf.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nicollision/niobbleaf.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00eb8250_Pt
{
    float x, y, z;
};

struct S_00eb8250_Tri
{
    S_00eb8250_Pt* m_kPointA;
    S_00eb8250_Pt* m_kPointB;
    S_00eb8250_Pt* m_iThirdValue;
};

struct S_00eb8250_Edges
{
    void* m_e0;
    void* m_e1;
    void* m_e2;
};

int __cdecl FUN_00eb7dc0(void* a, void* b, S_00eb8250_Tri* tri, S_00eb8250_Pt* n, float d, int p3, float p4, int p5,
                         int p6);

// Computes the triangle's normal and plane offset, then tests it against all three edge pairs via FUN_00eb7dc0, OR-ing the results.
// @fnv 0x00eb8250
int __cdecl FUN_00eb8250(S_00eb8250_Edges* e, S_00eb8250_Tri* tri, int p3, float p4, int p5, int p6)
{
    S_00eb8250_Pt u, v, n;
    u.x = tri->m_kPointB->x - tri->m_kPointA->x;
    u.y = tri->m_kPointB->y - tri->m_kPointA->y;
    u.z = tri->m_kPointB->z - tri->m_kPointA->z;
    v.x = tri->m_iThirdValue->x - tri->m_kPointA->x;
    v.y = tri->m_iThirdValue->y - tri->m_kPointA->y;
    v.z = tri->m_iThirdValue->z - tri->m_kPointA->z;
    n.x = u.y * v.z - u.z * v.y;
    n.y = u.z * v.x - u.x * v.z;
    n.z = u.x * v.y - u.y * v.x;
    const S_00eb8250_Pt& a = *tri->m_kPointA;
    float d = a.x * n.x + a.y * n.y + a.z * n.z;
    int r = FUN_00eb7dc0(e->m_e0, e->m_e1, tri, &n, d, p3, p4, p5, p6);
    r |= FUN_00eb7dc0(e->m_e0, e->m_e2, tri, &n, d, p3, p4, p5, p6);
    r |= FUN_00eb7dc0(e->m_e1, e->m_e2, tri, &n, d, p3, p4, p5, p6);
    return r;
}

// FUN_00eb85d0 - 170 bytes.
//
// The pack's unit file is empty, so the whole object graph is modelled here
// from the disassembly of the original.
//
// Frame layout (ESP relative, the function has no frame pointer):
//   [esp-0x40] .. [esp-0x01]   one 0x40-byte local node structure
//       +0x00  shape*        (stack parameter 1)
//       +0x04  shape*        (stack parameter 2)
//       +0x08  shape*        (stack parameter 3)
//       +0x0c  shape*        (stack parameter 4)
//       +0x10  int           pointer handed to ComputeContactTime
//       +0x14  float[3]      in-vector, also handed to ComputeContactTime
//       +0x20  float[3]      out-vector of the first ProjectOntoAxes call
//       +0x2c  float[3]      out-vector of the second ProjectOntoAxes call
//       +0x38  shape*        &this->m_8c
//       +0x3c  shape*        &pObj->m_8c
//
// `this` (ECX) and the first stack argument are two physics objects of the
// same type: both own a sub-object at +0x04 and a shape at +0x8c.

struct FNV_Shape
{
    int unk00;
};

struct FNV_Vec3
{
    float x;
    float y;
    float z;
};

// the sub-object at +0x04 of a physics object; its method takes the node's
// in-vector and produces an out-vector.
struct FNV_Body
{
    int unk00;
    void ProjectOntoAxes(FNV_Vec3* in, FNV_Vec3* out);
};

struct FNV_Node
{
    FNV_Shape* m_00;
    FNV_Shape* m_04;
    FNV_Shape* m_08;
    FNV_Shape* m_0c;
    int m_10;
    FNV_Vec3 m_14;
    FNV_Vec3 m_20;
    FNV_Vec3 m_2c;
    FNV_Shape* m_38;
    FNV_Shape* m_3c;
};

struct FNV_PhysObj
{
    int unk00;
    FNV_Body m_04;
    double unk08;
    double unk10;
    double unk18;
    double unk20;
    double unk28;
    double unk30;
    double unk38;
    double unk40;
    double unk48;
    double unk50;
    double unk58;
    double unk60;
    double unk68;
    double unk70;
    double unk78;
    double unk80;
    int unk88;
    FNV_Shape m_8c;

    int RunSwapTests(FNV_Node* node);
    int FUN_00eb85d0(FNV_PhysObj* pObj, FNV_Shape* a2, FNV_Shape* a3, FNV_Shape* a4, FNV_Shape* a5, unsigned char* a6);
};

extern int ComputeContactTime(FNV_PhysObj* a, FNV_PhysObj* b, int* c, FNV_Vec3* d);

// @fnv 0x00eb85d0
int FNV_PhysObj::FUN_00eb85d0(FNV_PhysObj* pObj, FNV_Shape* pShape0, FNV_Shape* pShape1, FNV_Shape* pShape2,
                              FNV_Shape* pShape3, unsigned char* pbResult)
{
    FNV_Node node;
    node.m_38 = 0;
    node.m_3c = 0;
    node.m_00 = pShape0;
    node.m_04 = pShape1;
    node.m_08 = pShape2;
    node.m_0c = pShape3;

    if (ComputeContactTime(this, pObj, &node.m_10, &node.m_14))
    {
        *pbResult = 1;
        node.m_38 = &this->m_8c;
        node.m_3c = &pObj->m_8c;
        this->m_04.ProjectOntoAxes(&node.m_14, &node.m_20);
        pObj->m_04.ProjectOntoAxes(&node.m_14, &node.m_2c);
        return this->RunSwapTests(&node);
    }
    return 0;
}

struct S_00eb8680_Sub
{
    int unk00;
    int unk04;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int FUN_00eba680(S_00eb8680_Sub* other);
    void UpdateWorldBounds(void* p);
};

struct S_00eb8680_Obj
{
    virtual bool vfn0();
    virtual bool vfn1();
    virtual bool vfn2(void* a, void* b, void* c, void* d, unsigned e, int f, int g);
    S_00eb8680_Sub sub;
    void* unk80;
    void* unk84;
    int unk88;
    __forceinline bool S_try(void* p, void* a2, void* a3, void* a4, unsigned n, int k1, int k2)
    {
        return vfn2(p, a2, a3, a4, n, k1, k2);
    }
    bool FUN_00eb8680(S_00eb8680_Obj* other, unsigned char* a2, unsigned char* a3, void* a4, unsigned count, int k1,
                      int k2);
};

// @fnv 0x00eb8680
bool S_00eb8680_Obj::FUN_00eb8680(S_00eb8680_Obj* other, unsigned char* pDataA, unsigned char* pDataB, void* a4,
                                  unsigned count, int k1, int k2)
{
    if (k1 != unk88)
    {
        sub.UpdateWorldBounds(pDataA + 0x68);
        unk88 = k1;
    }
    if (k2 != other->unk88)
    {
        other->sub.UpdateWorldBounds(pDataB + 0x68);
        other->unk88 = k2;
    }
    if (!sub.FUN_00eba680(&other->sub))
        return false;
    if (other->vfn1() || count == 0 || (!other->unk80 && !other->unk84))
        return true;
    return S_try(other->unk80, pDataA, pDataB, a4, count - 1, k1, k2) ||
           S_try(other->unk84, pDataA, pDataB, a4, count - 1, k1, k2);
}

struct S_00eb8790_Transform
{
    int unk00;
};

struct S_00eb8790_Body
{
    int unk00;
    int unk04;
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
    int unk60;
    int unk64;
    S_00eb8790_Transform m_kMotionTransform;  // 68
};

struct S_00eb8790_Volume
{
    int unk00, unk04, unk08;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    void UpdateWorldBounds(const S_00eb8790_Transform& transform);
    int FUN_00eba680(const S_00eb8790_Volume& other);
};

struct S_00eb8790_Node
{
    virtual void v0();
    virtual bool isLeaf();
    virtual void v2();
    virtual int FUN_00eb8790(S_00eb8790_Node* other, int a1, int a2, S_00eb8790_Body* bodyA, S_00eb8790_Body* bodyB,
                             int a5, int depth, int stampA, int stampB, int a9);

    int FUN_00eb85d0(S_00eb8790_Node* other, int a1, int a2, S_00eb8790_Body* bodyA, S_00eb8790_Body* bodyB, int a9);
    int FUN_00eb9b00(S_00eb8790_Node* other, int a1, int a2, S_00eb8790_Body* bodyA, S_00eb8790_Body* bodyB, int a9);

    S_00eb8790_Volume m_iBufferSize;  // 04
    S_00eb8790_Node* m_childA;        // 80
    S_00eb8790_Node* m_childB;        // 84
    int m_stamp;                      // 88
};

// @fnv 0x00eb8790
int S_00eb8790_Node::FUN_00eb8790(S_00eb8790_Node* other, int a1, int a2, S_00eb8790_Body* bodyA,
                                  S_00eb8790_Body* bodyB, int a5, int depth, int stampA, int stampB, int a9)
{
    if (stampA != m_stamp)
    {
        m_iBufferSize.UpdateWorldBounds(bodyA->m_kMotionTransform);
        m_stamp = stampA;
    }
    if (stampB != other->m_stamp)
    {
        other->m_iBufferSize.UpdateWorldBounds(bodyB->m_kMotionTransform);
        other->m_stamp = stampB;
    }
    if (!m_iBufferSize.FUN_00eba680(other->m_iBufferSize))
        return 0;
    if (!other->isLeaf())
    {
        if (depth && (other->m_childA || other->m_childB))
        {
            int result = FUN_00eb8790(other->m_childA, a1, a2, bodyA, bodyB, a5, depth - 1, stampA, stampB, a9);
            if (result >= 1)
                return result;
            S_00eb8790_Node* pChildB = other->m_childB;
            result = FUN_00eb8790(pChildB, a1, a2, bodyA, bodyB, a5, depth - 1, stampA, stampB, a9);
            if (result >= 1)
                return result;
            return 0;
        }
        return FUN_00eb9b00(other, a1, a2, bodyA, bodyB, a9);
    }
    if (a5 < 0 && depth < 0)
        return FUN_00eb85d0(other, a1, a2, bodyA, bodyB, a9);
    return FUN_00eb9b00(other, a1, a2, bodyA, bodyB, a9);
}

// ComputeBarycentric: barycentric-style solve over three edge vectors from a base point.
struct Vec3f
{
    float x;
    float y;
    float z;
    Vec3f(const Vec3f& a, const Vec3f& b) : x(a.x - b.x), y(a.y - b.y), z(a.z - b.z)
    {}
    float Dot(const Vec3f& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
};

// Computes barycentric coordinates of a4 relative to triangle (a1,a2,base) and writes them to out.
// @fnv 0x00eb72b0
void ComputeBarycentric(const Vec3f* apVertex0, const Vec3f* apVertex1, const Vec3f* apVertex2, const Vec3f* apPoint,
                        Vec3f* apBarycentric)
{
    Vec3f p(*apVertex0, *apVertex2);
    Vec3f v1(*apVertex1, *apVertex2);
    Vec3f r(*apPoint, *apVertex2);

    float d11 = p.Dot(p);
    float fDot01 = p.Dot(v1);
    float fDot11 = v1.Dot(v1);
    float fDot02 = p.Dot(r);
    float fDot12 = v1.Dot(r);
    float fInvDenom = 1.0f / (d11 * fDot11 - fDot01 * fDot01);
    float s = (fDot11 * fDot02 - fDot01 * fDot12) * fInvDenom;
    apBarycentric->x = s;
    float t = (d11 * fDot12 - fDot01 * fDot02) * fInvDenom;
    apBarycentric->y = t;
    apBarycentric->z = 1.0f - s - t;
}

// @fnv 0x00ee8990
bool FUN_00ee8990()
{
    return false;
}

struct Vec3
{
    float x;
    float y;
    float z;
    Vec3()
    {}
    Vec3(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }
    Vec3 operator-(const Vec3& pt) const
    {
        return Vec3(x - pt.x, y - pt.y, z - pt.z);
    }
    Vec3 Cross(const Vec3& pt) const
    {
        return Vec3(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
    }
    void NiPoint3_Unitize();
};

struct SubA
{
    int unk00;
    void UpdateWorldBounds(void* p);
};

struct Node
{
    int unk00;
    int unk04;
    Vec3 m_08;
    float m_14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Vec3 m_28;
};

struct Helper
{
    int unk00;
    Node* GetTexture(void* p);
};

struct Rec
{
    int unk00;
    int unk04;
    unsigned char m_08;
    int unk0c;
    unsigned char m_10;
    int unk14;
    Helper m_18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    unsigned char unk30;
    unsigned char m_31;
};

struct Owner
{
    int unk00;
    SubA m_04;
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
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int m_88;
    Vec3* m_8c;
    Vec3* m_90;
    Vec3* m_94;
};

extern "C" unsigned char __cdecl FUN_00eadb90(Vec3* a, Vec3* b, Vec3* c, Vec3* d, Vec3* e, unsigned char f, Vec3* g,
                                              float* h, float* i, int* j);

struct Obj5
{
    int unk00;
    int unk04;
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
    int unk60;
    int unk64;
    int m_68;
};

struct FUN_00eb8930_cls : Owner
{
    int FUN_00eb8930(Vec3* a1, Vec3* a2, Rec* a3, unsigned char* out, Obj5* a5, int a6);
};

// Calls an intersection helper and, on success, stores its returned point and parameter in a node, with an optional triangle normal.
// @fnv 0x00eb8930
int FUN_00eb8930_cls::FUN_00eb8930(Vec3* a1, Vec3* a2, Rec* apRec, unsigned char* pOutHit, Obj5* apObj5, int a6)
{
    if (a6 != m_88)
    {
        m_04.UpdateWorldBounds(&apObj5->m_68);
        m_88 = a6;
    }
    unsigned char flag = apRec->m_10;
    int index;
    float u;
    float t;
    Vec3 point;
    unsigned char ok = FUN_00eadb90(a1, a2, m_8c, m_90, m_94, flag, &point, &t, &u, &index);
    *pOutHit = ok;
    if (ok == 0)
        return 0;
    Node* n = apRec->m_18.GetTexture(apObj5);
    n->m_08 = point;
    n->m_14 = t;
    if (apRec->m_31 != 0)
    {
        Vec3 ub = *m_90 - *m_8c;
        Vec3 wa = *m_94 - *m_8c;
        Vec3 cross = ub.Cross(wa);
        cross.NiPoint3_Unitize();
        n->m_28 = cross;
    }
    return 0;
}

struct Vec
{
    float x, y, z;
    Vec()
    {}
    Vec(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Vec operator+(const Vec& b) const
    {
        Vec r;
        r.x = x + b.x;
        r.y = y + b.y;
        r.z = z + b.z;
        return r;
    }
    float Dot(const Vec& b) const
    {
        return x * b.x + y * b.y + z * b.z;
    }
};
inline Vec operator*(float s, const Vec& v)
{
    Vec r;
    r.x = v.x;
    r.x *= s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}
inline Vec operator*(const Vec& v, float s)
{
    Vec r;
    r.x = v.x;
    r.x *= s;
    r.y = v.y * s;
    r.z = v.z * s;
    return r;
}
// Finds up to two intersection times and points where the moving segment start+velocity*t to end+velocity*t crosses the plane defined by normal and plane.
// @fnv 0x00eb7440
int __cdecl IntersectPlane(float duration, const Vec& normal, float plane, const Vec& velocity, const Vec& start,
                           const Vec& end, float& time0, Vec& point0, float& time1, Vec& point1)
{
    float delta = duration - 0.0f;
    float d00 = (start + 0.0f * velocity).Dot(normal) - plane;
    float d01 = (end + 0.0f * velocity).Dot(normal) - plane;
    float d10 = (start + duration * velocity).Dot(normal) - plane;
    float d11 = (end + duration * velocity).Dot(normal) - plane;
    int found = 0;
    if (d00 * d01 <= 0.0f)
    {
        if (d00 == 0.0f && d01 == 0.0f)
        {
            time0 = 0.0f;
            time1 = 0.0f;
            point0 = start + time0 * velocity;
            point1 = end + velocity * time1;
            return 1;
        }
        time0 = 0.0f;
        float fraction = d00 / (d00 - d01);
        point0 = ((1.0f - fraction) * start + fraction * end) + 0.0f * velocity;
        found = 1;
    }
    if (d00 * d10 <= 0.0f)
    {
        if (d00 == 0.0f && d10 == 0.0f)
        {
            time0 = 0.0f;
            time1 = duration;
            point0 = start + time0 * velocity;
            point1 = start + time1 * velocity;
            return 1;
        }
        float time = 0.0f + delta * d00 / (d00 - d10);
        Vec point = start + time * velocity;
        if (found)
        {
            time1 = time;
            point1 = point;
            if (time0 > time1)
            {
                float saved = time0;
                time0 = time1;
                time1 = saved;
                Vec savedPoint = point0;
                point0 = point1;
                point1 = savedPoint;
            }
            return 1;
        }
        time0 = time;
        point0 = point;
        found = 1;
    }
    if (d01 * d11 <= 0.0f)
    {
        if (d01 == 0.0f && d11 == 0.0f)
        {
            time0 = 0.0f;
            time1 = duration;
            point0 = end + time0 * velocity;
            point1 = end + time1 * velocity;
            return 1;
        }
        float time = 0.0f + delta * d01 / (d01 - d11);
        Vec point = end + time * velocity;
        if (found)
        {
            time1 = time;
            point1 = point;
            if (time0 > time1)
            {
                float saved = time0;
                time0 = time1;
                time1 = saved;
                Vec savedPoint = point0;
                point0 = point1;
                point1 = savedPoint;
            }
            return 1;
        }
        time0 = time;
        point0 = point;
        found = 1;
    }
    if (d10 * d11 <= 0.0f)
    {
        if (d10 == 0.0f && d11 == 0.0f)
        {
            time0 = duration;
            time1 = duration;
            point0 = start + velocity * time0;
            point1 = end + time1 * velocity;
            return 1;
        }
        float fraction = d10 / (d10 - d11);
        Vec point = ((1.0f - fraction) * start + fraction * end) + duration * velocity;
        if (found)
        {
            time1 = duration;
            point1 = point;
            if (time0 > time1)
            {
                float saved = time0;
                time0 = time1;
                time1 = saved;
                Vec savedPoint = point0;
                point0 = point1;
                point1 = savedPoint;
            }
            return 1;
        }
        time0 = duration;
        point0 = point;
        found = 1;
    }
    if (found)
    {
        time1 = time0;
        point1 = point0;
        return 1;
    }
    return 0;
}

extern "C" void _ReadWriteBarrier();
struct S_eb6b90_Point
{
    float x, y, z;

    S_eb6b90_Point()
    {}
    S_eb6b90_Point(float fX, float fY, float fZ)
    {
        x = fX;
        y = fY;
        z = fZ;
    }

    float XValue() const
    {
        return x;
    }
    const float& YRef() const
    {
        return y;
    }
    float YValue() const
    {
        return y;
    }
    const float& ZRef() const
    {
        return z;
    }
    S_eb6b90_Point operator+(const S_eb6b90_Point& pt) const
    {
        return S_eb6b90_Point(x + pt.x, y + pt.y, z + pt.z);
    }
    S_eb6b90_Point operator-(const S_eb6b90_Point& pt) const
    {
        return S_eb6b90_Point(x - pt.x, y - pt.y, z - pt.z);
    }
    S_eb6b90_Point operator/(float fScalar) const
    {
        float inverse = 1.0f / fScalar;
        return S_eb6b90_Point(inverse * x, inverse * y, inverse * z);
    }
    S_eb6b90_Point operator*(float fScalar) const
    {
        return S_eb6b90_Point(fScalar * x, fScalar * y, fScalar * z);
    }
    float operator*(const S_eb6b90_Point& pt) const
    {
        return x * pt.x + y * pt.y + z * pt.z;
    }
    S_eb6b90_Point& operator+=(const S_eb6b90_Point& pt)
    {
        x += pt.x;
        y += pt.y;
        z += pt.z;
        return *this;
    }
    S_eb6b90_Point& operator-=(const S_eb6b90_Point& pt)
    {
        x -= pt.x;
        y -= pt.y;
        z -= pt.z;
        return *this;
    }
    S_eb6b90_Point Cross(const S_eb6b90_Point& pt) const
    {
        return S_eb6b90_Point(y * pt.z - z * pt.y, z * pt.x - x * pt.z, x * pt.y - y * pt.x);
    }

    void NiPoint3_Unitize();  // Unitize
};

inline S_eb6b90_Point operator*(float k, const S_eb6b90_Point& p)
{
    return S_eb6b90_Point(k * p.x, k * p.y, k * p.z);
}
inline float DotThird(const S_eb6b90_Point& a, const S_eb6b90_Point& b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
struct S_eb6b90_Matrix
{
    float m_afEntries[3][3];
    S_eb6b90_Matrix()
    {}
};

struct S_eb6b90_Transform
{
    S_eb6b90_Matrix m_kOrientation;
    S_eb6b90_Point m_kTranslation;
    float m_fScale;

    S_eb6b90_Transform()
    {}
    void FUN_00a86bf0();
};

struct S_eb6b90_Root;
struct S_eb6b90_Box
{
    S_eb6b90_Point m_kCenterPosition;
    S_eb6b90_Point m_akBasis[3];
    float m_afExtents[3];
    S_eb6b90_Point m_kWorldCenter;
    S_eb6b90_Point m_akWorldBasis[3];
    float m_afWorldExtent[3];
    S_eb6b90_Root* m_pkTreeNode;

    S_eb6b90_Point& Center()
    {
        return m_kCenterPosition;
    }
    S_eb6b90_Point& Basis(int i)
    {
        return m_akBasis[i];
    }
    S_eb6b90_Box()
    {
        m_pkTreeNode = 0;
    }
    void UpdateWorldBounds(const S_eb6b90_Transform& kXform);  // Transform
};

struct S_eb6b90_Root;

struct S_eb6b90_Payload
{
    S_eb6b90_Box m_kBoundsBox;
    int unk80;
    int unk84;
    int unk88;
};
extern void* DAT_010f1b70;
struct S_eb6b90_Node
{

    virtual bool IsTerminalNode()
    {
        return false;
    }
    S_eb6b90_Payload payload;

    S_eb6b90_Node()
    {
        payload.unk88 = 0;
        payload.unk80 = 0;
        payload.unk84 = 0;
    }
};

struct FUN_00eb6b90 : S_eb6b90_Node
{
    S_eb6b90_Point* m_apkWorldVertex[3];

    FUN_00eb6b90(S_eb6b90_Root* pkRoot, unsigned short* pusTriList, S_eb6b90_Point* pkVertex,
                 S_eb6b90_Point* pkWorldVertex, unsigned short m_usTriangleID);
};

// Initializes a triangle node by computing its bounding box center, basis axes, and extents from three vertices.
// @fnv 0x00eb6b90
FUN_00eb6b90::FUN_00eb6b90(S_eb6b90_Root* pkRoot, unsigned short* pusTriList, S_eb6b90_Point* pkVertex,
                           S_eb6b90_Point* pkWorldVertex, unsigned short m_usTriangleID)
{
    unsigned short triStart = 3 * m_usTriangleID;
    unsigned short vi = pusTriList[triStart];
    m_apkWorldVertex[0] = pkWorldVertex + vi;
    const S_eb6b90_Point& kP0 = pkVertex[vi];
    ++triStart;
    vi = pusTriList[triStart];
    m_apkWorldVertex[1] = pkWorldVertex + vi;
    const S_eb6b90_Point& kP1 = pkVertex[vi];
    ++triStart;
    vi = pusTriList[triStart];
    m_apkWorldVertex[2] = pkWorldVertex + vi;
    const S_eb6b90_Point& kMid = pkVertex[vi];
    S_eb6b90_Point& kTargetCenter = payload.m_kBoundsBox.Center();
    S_eb6b90_Point* akAxis = payload.m_kBoundsBox.m_akBasis;
    float* extent = payload.m_kBoundsBox.m_afExtents;
    kTargetCenter = (kP0 + kP1 + kMid) / 3.0f;

    akAxis[0] = kP1 - kP0;
    akAxis[0].NiPoint3_Unitize();
    akAxis[1] = kMid - kP0;
    float projection = akAxis[0] * akAxis[1];
    akAxis[1] -= projection * akAxis[0];
    akAxis[1].NiPoint3_Unitize();
    akAxis[2] = akAxis[0].Cross(akAxis[1]);

    S_eb6b90_Point minCoord(0.0f, 0.0f, 0.0f);
    S_eb6b90_Point maxCoord(0.0f, 0.0f, 0.0f);
    S_eb6b90_Point kDiff;
    float fX;
    float fY;
    float fZ;

    {
        kDiff = kP0 - kTargetCenter;
        fX = akAxis[0] * kDiff;
        fY = akAxis[1] * kDiff;
        fZ = akAxis[2] * kDiff;
        if (fX < minCoord.x)
            minCoord.x = fX;
        else if (fX > maxCoord.x)
            maxCoord.x = fX;
        if (fY < minCoord.y)
            minCoord.y = fY;
        else if (fY > maxCoord.y)
            maxCoord.y = fY;
        if (fZ < minCoord.z)
            minCoord.z = fZ;
        else if (fZ > maxCoord.z)
            maxCoord.z = fZ;
    }
    {
        kDiff = kP1 - kTargetCenter;
        fX = akAxis[0] * kDiff;
        fY = akAxis[1] * kDiff;
        fZ = akAxis[2] * kDiff;
        if (fX < minCoord.x)
            minCoord.x = fX;
        else if (fX > maxCoord.x)
            maxCoord.x = fX;
        if (fY < minCoord.y)
            minCoord.y = fY;
        else if (fY > maxCoord.y)
            maxCoord.y = fY;
        if (fZ < minCoord.z)
            minCoord.z = fZ;
        else if (fZ > maxCoord.z)
            maxCoord.z = fZ;
    }
    {
        kDiff = kMid - kTargetCenter;
        fX = akAxis[0] * kDiff;
        fY = akAxis[1] * kDiff;
        fZ = akAxis[2] * kDiff;
        if (fX < minCoord.x)
            minCoord.x = fX;
        else if (fX > maxCoord.x)
            maxCoord.x = fX;
        if (fY < minCoord.y)
            minCoord.y = fY;
        else if (fY > maxCoord.y)
            maxCoord.y = fY;
        if (fZ < minCoord.z)
            minCoord.z = fZ;
        else if (fZ > maxCoord.z)
            maxCoord.z = fZ;
    }

    S_eb6b90_Point kExtent = 0.5f * (maxCoord - minCoord);
    extent[0] = kExtent.x;
    extent[1] = kExtent.y;
    extent[2] = kExtent.z;

    S_eb6b90_Point kP2 = 0.5f * (maxCoord + minCoord);
    kTargetCenter += akAxis[0] * kP2.x + akAxis[1] * kP2.y + akAxis[2] * kP2.z;

    S_eb6b90_Transform usIndex;
    usIndex.FUN_00a86bf0();
    payload.m_kBoundsBox.UpdateWorldBounds(usIndex);

    payload.m_kBoundsBox.m_pkTreeNode = pkRoot;
}

int __cdecl IntersectPlane(float, S_00eb8250_Pt*, float, int, void*, void*, float*, S_00eb8250_Pt*, float*,
                           S_00eb8250_Pt*);
// Clips barycentric coordinates to the positive octant and updates the bound and point when a nearer candidate is found.
// @fnv 0x00eb7dc0
int __cdecl FUN_00eb7dc0(void* a, void* b, S_00eb8250_Tri* apTriangle, S_00eb8250_Pt* apNormal, float d, int p3,
                         float p4, volatile int apNearestDistance, int apHitPoint)
{
    float t;
    struct Geometry
    {
        float distanceA, distanceB;
        S_00eb8250_Pt coordA, distance, pointB, pointA;
    } g;
    (void)g.distanceB;
    if (!IntersectPlane(p4, apNormal, d, p3, a, b, &g.distanceA, &g.coordA, &g.distanceB, &g.distance))
        goto noHit;
    ComputeBarycentric((const Vec3f*)apTriangle->m_kPointA, (const Vec3f*)apTriangle->m_kPointB, (const Vec3f*)apTriangle->m_iThirdValue,
                       (const Vec3f*)&g.coordA, (Vec3f*)&g.pointA);
    ComputeBarycentric((const Vec3f*)apTriangle->m_kPointA, (const Vec3f*)apTriangle->m_kPointB, (const Vec3f*)apTriangle->m_iThirdValue,
                       (const Vec3f*)&g.distance, (Vec3f*)&g.pointB);
    do
    {
        if (g.pointA.x < 0.0f)
        {
            if (g.pointB.x < 0.0f)
                return 0;
            t = g.pointA.x / (g.pointA.x - g.pointB.x);
            float clippedy = t * g.pointB.y + (1.0f - t) * g.pointA.y;
            if (!(clippedy >= 0.0f))
                goto noHit;
            float clippedz = t * g.pointB.z + (1.0f - t) * g.pointA.z;
            if (!(clippedz >= 0.0f))
                goto noHit;
            float* pNearestDistance = (float*)apNearestDistance;
            float fInterpDistance = t * g.distanceB + (1.0f - t) * g.distanceA;
            if (fInterpDistance < *pNearestDistance)
            {
                *pNearestDistance = fInterpDistance;
                g.pointB.x = t * g.distance.x;
                g.pointB.y = t * g.distance.y;
                g.pointB.z = t * g.distance.z;
                g.distanceB = 1.0f - t;
                g.pointA.x = g.distanceB * g.coordA.x;
                g.pointA.y = g.distanceB * g.coordA.y;
                g.pointA.z = g.distanceB * g.coordA.z;
                g.distance.x = static_cast<const volatile float&>(g.pointA.x) + g.pointB.x;
                g.distance.y = g.pointA.y + g.pointB.y;
                g.distance.z = g.pointA.z + g.pointB.z;
                *(S_00eb8250_Pt*)apHitPoint = g.distance;
            }
            return 1;
        }
        else if (g.pointA.y < 0.0f)
        {
            if (g.pointB.y < 0.0f)
                break;
            t = g.pointA.y / (g.pointA.y - g.pointB.y);
            float clippedx = t * g.pointB.x + (1.0f - t) * g.pointA.x;
            if (!(clippedx >= 0.0f))
                return 0;
            float clippedz = t * g.pointB.z + (1.0f - t) * g.pointA.z;
            if (!(clippedz >= 0.0f))
                return 0;
            float* pNearestDistance = (float*)apNearestDistance;
            float fInterpDistance = t * g.distanceB + (1.0f - t) * g.distanceA;
            if (fInterpDistance < *pNearestDistance)
            {
                *pNearestDistance = fInterpDistance;
                g.pointB.x = t * g.distance.x;
                g.pointB.y = t * g.distance.y;
                g.pointB.z = t * g.distance.z;
                g.distanceB = 1.0f - t;
                g.pointA.x = g.distanceB * g.coordA.x;
                g.pointA.y = g.distanceB * g.coordA.y;
                g.pointA.z = g.distanceB * g.coordA.z;
                g.distance.x = static_cast<const volatile float&>(g.pointA.x) + g.pointB.x;
                g.distance.y = g.pointA.y + g.pointB.y;
                g.distance.z = g.pointA.z + g.pointB.z;
                *(S_00eb8250_Pt*)apHitPoint = g.distance;
            }
            return 1;
        }
        else if (g.pointA.z < 0.0f)
        {
            if (g.pointB.z < 0.0f)
            {
            noHit:
                return 0;
            }
            t = g.pointA.z / (g.pointA.z - g.pointB.z);
            float clippedx = t * g.pointB.x + (1.0f - t) * g.pointA.x;
            if (clippedx >= 0.0f)
            {
                float clippedy = t * g.pointB.y + (1.0f - t) * g.pointA.y;
                if (!(clippedy >= 0.0f))
                    return 0;
                float* pNearestDistance = (float*)apNearestDistance;
                float fInterpDistance = t * g.distanceB + g.distanceA * (1.0f - t);
                if (fInterpDistance < *pNearestDistance)
                {
                    *pNearestDistance = fInterpDistance;
                    g.pointB.x = t * g.distance.x;
                    g.pointB.y = t * g.distance.y;
                    g.pointB.z = t * g.distance.z;
                    g.distanceB = 1.0f - t;
                    g.pointA.x = g.distanceB * g.coordA.x;
                    g.pointA.y = g.distanceB * g.coordA.y;
                    g.pointA.z = g.distanceB * g.coordA.z;
                    g.distance.x = static_cast<const volatile float&>(g.pointA.x) + g.pointB.x;
                    g.distance.y = g.pointA.y + g.pointB.y;
                    g.distance.z = g.pointA.z + g.pointB.z;
                    *(S_00eb8250_Pt*)apHitPoint = g.distance;
                }
                return 1;
            }
        }
        else
        {
            goto inside;
        }
    } while (false);
    return 0;
inside:
    float* pNearestDistance = (float*)apNearestDistance;
    if (g.distanceA < *pNearestDistance)
    {
        *pNearestDistance = g.distanceA;
        *(S_00eb8250_Pt*)apHitPoint = g.coordA;
    }
    return 1;
}

struct Point3
{
    float x, y, z;
    Point3 operator+(const Point3& b) const
    {
        return Point3(x + b.x, y + b.y, z + b.z);
    }
    Point3()
    {}
    Point3(float a, float b, float c) : x(a), y(b), z(c)
    {}
    Point3 operator-(const Point3& v) const
    {
        return Point3(x - v.x, y - v.y, z - v.z);
    }
};

extern "C" __declspec(noalias) int __cdecl FUN_00eb8250(S_00eb8250_Edges*, S_00eb8250_Tri*, const Point3&, float,
                                                        float*, Point3*);
struct PhysObjInfo
{
    int unk00;
    float duration;
    int unk08;
    int unk0c;
    Point3 velocity;
};

struct PhysObj_eb83b0
{
    int unk00;
    FNV_Body m_04;
    double unk08;
    double unk10;
    double unk18;
    double unk20;
    double unk28;
    double unk30;
    double unk38;
    double unk40;
    double unk48;
    double unk50;
    double unk58;
    double unk60;
    double unk68;
    double unk70;
    int unk78;
    PhysObjInfo* unk7c;
    double unk80;
    int unk88;
    FNV_Shape m_8c;
};

inline Point3 operator*(float t, const Point3& p)
{
    return Point3(t * p.x, t * p.y, t * p.z);
}
// Computes the earliest collision time and contact point between two physical objects using their shapes, velocities, and duration.
// @fnv 0x00eb83b0
int ComputeContactTime(PhysObj_eb83b0* apObjA, PhysObj_eb83b0* apObjB, float* pfTimeOut, Point3* apContactOut)
{
    PhysObjInfo* pInfoA = apObjA->unk7c;
    float duration = pInfoA->duration;
    Point3* velocityB = &apObjB->unk7c->velocity;
    float timeA = 3.402823466e+38F;
    Point3 vContactA, vContactB;
    Point3 relativeVelocity;
    relativeVelocity = pInfoA->velocity - *velocityB;
    int hitA = FUN_00eb8250((S_00eb8250_Edges*)&apObjA->m_8c, (S_00eb8250_Tri*)&apObjB->m_8c, relativeVelocity,
                            duration, &timeA, &vContactA);
    float timeB = 3.402823466e+38F;
    relativeVelocity = *velocityB - pInfoA->velocity;
    int hitB = FUN_00eb8250((S_00eb8250_Edges*)&apObjB->m_8c, (S_00eb8250_Tri*)&apObjA->m_8c, relativeVelocity,
                            duration, &timeB, &vContactB);
    if (hitA)
    {
        if (hitB)
        {
            if (timeA <= timeB)
            {
                *pfTimeOut = timeA;
                *apContactOut = vContactA + timeA * (*velocityB);
            }
            else
            {
                *pfTimeOut = timeB;
                *apContactOut = vContactB + timeB * pInfoA->velocity;
            }
        }
        else
        {
            *pfTimeOut = timeA;
            *apContactOut = vContactA + timeA * (*velocityB);
        }
    }
    else
    {
        if (hitB)
        {
            *pfTimeOut = timeB;
            *apContactOut = vContactB + timeB * pInfoA->velocity;
        }
    }
    return hitA || hitB;
}
