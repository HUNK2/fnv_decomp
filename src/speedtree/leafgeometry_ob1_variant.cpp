
// src/speedtree/leafgeometry_ob1_variant.cpp - flag-variant unit created 2026-10-27 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /Od /Oy- /GS /EHsc /Gy /Ob1 (unit src/speedtree/leafgeometry.cpp lists /MT /Od /Oy- /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.

// src/speedtree/leafgeometry.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/speedtree/leafgeometry.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
struct LeafLod
{
    char b[0x44];
};
struct SpeedTreeLodData
{
    char m_auiShapeKeys[0x28];
    unsigned short m_usValueAt28;
    char m_pAuxiliaryObject[2];
    LeafLod* m_pLeafLod;
    void FUN_00b27820();
};
struct FUN_00b28440_Class
{
    float x;
    float y;
    float z;
    FUN_00b28440_Class& Scale(float scale);
};
struct FUN_00b27870_Class
{
    unsigned char m_bValueAt00;
    unsigned char m_auiShapeKeys[7];
    unsigned short m_usValueAt08;
    unsigned char m_pAuxiliaryObject[6];
    float** m_ppFloatData;
    unsigned char m_pad3[4];
    float* m_pCopiedLodData;
    unsigned short m_usValue;

    const float* CopyLodData(unsigned int& aiFloatCount);
};
void* __cdecl _memmove(void* dest, const void* src, unsigned int count);
extern "C" bool FUN_00b0d7a0();
extern const float DAT_01012054;
struct FUN_00b28720_Class
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float* m_pLeafTable;

    void SetLeafTableEntry(int nLeaf, const float* pSrc);
};
struct LodB28
{
    char pad[0x10];
    char *p10, *p14, *p18, *p1c, *p20, *p24, *p28, *p2c, *p30, *p34, *p38;
    int pad3c;
    char* p40;
};
struct CB28
{
    char pad[0x28];
    unsigned short count;
    char pad2[2];
    LodB28* lods;
    void FreeLodBuffers();
};

struct Vec3
{
    float v[3];
    __forceinline void Set(float a, float b, float c)
    {
        v[0] = a;
        v[1] = b;
        v[2] = c;
    }
    __forceinline Vec3(float a = 0, float b = 0, float c = 0)
    {
        Set(a, b, c);
    }
    __forceinline Vec3(const float* p)
    {
        Set(p[0], p[1], p[2]);
    }
    __forceinline float& operator[](int n)
    {
        return v[n];
    }
    inline float FUN_00b04d40(const Vec3& other) const
    {
        float squared = (other.v[0] - v[0]) * (other.v[0] - v[0]) + (other.v[1] - v[1]) * (other.v[1] - v[1]) +
                        (other.v[2] - v[2]) * (other.v[2] - v[2]);
        int bits = (*reinterpret_cast<int*>(&squared) >> 1) + 0x1fc00000;
        return *reinterpret_cast<float*>(&bits);
    }
};
struct GlobalObject_00b3f100
{
    float values[5];
    int count;
    ~GlobalObject_00b3f100();
};
struct Bounds
{
    GlobalObject_00b3f100 lo, hi;
    Bounds();
    inline Bounds FUN_00b3caa0(const Vec3& p) const
    {
        Bounds result = *this;
        if (p.v[0] < result.lo.values[0])
            result.lo.values[0] = p.v[0];
        if (p.v[1] < result.lo.values[1])
            result.lo.values[1] = p.v[1];
        if (p.v[2] < result.lo.values[2])
            result.lo.values[2] = p.v[2];
        if (p.v[0] > result.hi.values[0])
            result.hi.values[0] = p.v[0];
        if (p.v[1] > result.hi.values[1])
            result.hi.values[1] = p.v[1];
        if (p.v[2] > result.hi.values[2])
            result.hi.values[2] = p.v[2];
        return result;
    }
    inline Bounds FUN_00b3c9a0(const Bounds& b) const
    {
        Bounds result = *this;
        for (int i = 0; i < 3; ++i)
        {
            if (b.lo.values[i] < lo.values[i])
                result.lo.values[i] = b.lo.values[i];
            if (b.hi.values[i] > hi.values[i])
                result.hi.values[i] = b.hi.values[i];
        }
        return result;
    }
};
struct Allocator
{
    void* p;
    inline void deallocate(void* value)
    {
        ::operator delete(value);
    }
    inline ~Allocator()
    {
        deallocate(p);
    }
};
struct AllocatorTag
{
    AllocatorTag();
    AllocatorTag(const AllocatorTag&);
};
struct FloatIterator
{
    float* current;
    void* owner;
};
struct FloatDerivedIterator : FloatIterator
{
};
struct VectorStorage
{
    Allocator allocator;
    int unk04, unk08;
    float *first, *last, *end;
    void initializeProxy(AllocatorTag tag);
    void copyAllocator(const AllocatorTag& tag);
    inline VectorStorage(AllocatorTag tag)
    {
        AllocatorTag copied(tag);
        initializeProxy(copied);
        copyAllocator(tag);
    }
};
struct FUN_00449fd0 : VectorStorage
{
    unsigned int maxSize() const;
    float* acquire(unsigned int n);
    void overflow();
    inline bool allocate(unsigned int n)
    {
        first = last = end = 0;
        if (!n)
            return false;
        if (maxSize() < n)
            overflow();
        else
        {
            float* storage = acquire(n);
            first = last = storage;
            end = first + n;
        }
        return true;
    }
    inline FUN_00449fd0() : VectorStorage(AllocatorTag())
    {
        float* initial = 0;
        first = initial;
        last = initial;
        end = initial;
    }
    void destroyRange(float* begin, float* finish);
    void releaseStorage(float* begin, unsigned int capacity);
    void releaseBytes(float* begin, unsigned int bytes);
    __forceinline void destroyElement(float* value)
    {
        typedef float Element;
        value->~Element();
    }
    inline void FUN_0065f240()
    {
        float* begin = first;
        float* finish = last;
        float* limit = end;
        if (begin)
        {
            unsigned int count = (unsigned int)(finish - begin);
            float* current = begin;
            while (count--)
            {
                destroyElement(current);
                ++current;
            }
            unsigned int capacity = (unsigned int)(limit - begin);
            unsigned int bytes = capacity * sizeof(float);
            releaseBytes(begin, bytes);
        }
        first = last = end = 0;
    }
    unsigned int size() const;
    unsigned int capacity() const;
    float* construct(float* where, unsigned int n, const float& value);
    FloatDerivedIterator endIter();
    FloatIterator insert(FloatIterator where, const float& value);
    inline void PushBack(const float& f)
    {
        unsigned int length = size();
        unsigned int space = capacity();
        if (length < space)
            last = construct(last, 1, f);
        else
        {
            FloatIterator where = endIter();
            insert(where, f);
        }
    }
    inline ~FUN_00449fd0()
    {
        FUN_0065f240();
    }
    inline float& operator[](unsigned int n);
};
void __cdecl FUN_00ec7c56();
inline float& FUN_00449fd0::operator[](unsigned int n)
{
    if (n >= (unsigned int)(last - first))
        FUN_00ec7c56();
    return first[n];
}
struct LeafRecord
{
    int unk00, unk04, unk08;
    unsigned short vertexCount, unk0e;
    unsigned char* textures;
    int unk14;
    float* vertices;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c, unk40;
};
struct LeafGeometry
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18;
    unsigned short textureCount, unk1e;
    Vec3* sizes;
    Vec3* origins;
    unsigned short lodCount, unk2a;
    LeafRecord* lods;
    void FUN_00b27910(Bounds& output);
};
// @fnv 0x00b27910
void LeafGeometry::FUN_00b27910(Bounds& output)
{
    if (origins && sizes && lods)
    {
        FUN_00449fd0 radii;
        for (int i = 0; i < textureCount; ++i)
        {
            Vec3 center(origins[i][0] * sizes[i][0], origins[i][1] * sizes[i][1], 0);
            float radius = 0;
            if (radius < center.FUN_00b04d40(Vec3(0, 0, 0)))
                radius = center.FUN_00b04d40(Vec3(0, 0, 0));
            if (radius < center.FUN_00b04d40(Vec3(sizes[i][0], 0, 0)))
                radius = center.FUN_00b04d40(Vec3(sizes[i][0], 0, 0));
            if (radius < center.FUN_00b04d40(Vec3(sizes[i][0], sizes[i][1], 0)))
                radius = center.FUN_00b04d40(Vec3(sizes[i][0], sizes[i][1], 0));
            if (radius < center.FUN_00b04d40(Vec3(0, sizes[i][1], 0)))
                radius = center.FUN_00b04d40(Vec3(0, sizes[i][1], 0));
            radii.PushBack(radius);
        }
        for (int j = 0; j < lodCount; ++j)
        {
            LeafRecord* lod = &lods[j];
            for (unsigned int k = 0; k < lod->vertexCount; ++k)
            {
                Bounds bounds;
                const float* vertex5 = &lod->vertices[k * 3];
                Vec3 position(vertex5);
                float radius = radii[lod->textures[k] / 2];
                bounds = bounds.FUN_00b3caa0(Vec3(position.v[0] + radius, position.v[1], position.v[2]));
                bounds = bounds.FUN_00b3caa0(Vec3(position.v[0] - radius, position.v[1], position.v[2]));
                bounds = bounds.FUN_00b3caa0(Vec3(position.v[0], position.v[1] + radius, position.v[2]));
                bounds = bounds.FUN_00b3caa0(Vec3(position.v[0], position.v[1] - radius, position.v[2]));
                bounds = bounds.FUN_00b3caa0(Vec3(position.v[0], position.v[1], position.v[2] + radius));
                bounds = bounds.FUN_00b3caa0(Vec3(position.v[0], position.v[1], position.v[2] - radius));
                output = output.FUN_00b3c9a0(bounds);
            }
        }
    }
}

struct Matrix4f
{
    float m_afMatrix[16];
};

struct Vector3D
{
    float m_fComponents[3];

    Vector3D()
    {}
    Vector3D(float x, float y, float z)
    {
        Set(x, y, z);
    }
    void Set(float x, float y, float z)
    {
        m_fComponents[0] = x;
        m_fComponents[1] = y;
        m_fComponents[2] = z;
    }
    Vector3D FUN_00b05000(const Matrix4f& cTransform)
    {
        Vector3D result;
        result.m_fComponents[0] =
            cTransform.m_afMatrix[12] +
            (cTransform.m_afMatrix[8] * m_fComponents[2] +
             (cTransform.m_afMatrix[4] * m_fComponents[1] + cTransform.m_afMatrix[0] * m_fComponents[0]));
        result.m_fComponents[1] =
            cTransform.m_afMatrix[13] +
            (cTransform.m_afMatrix[9] * m_fComponents[2] +
             (cTransform.m_afMatrix[5] * m_fComponents[1] + cTransform.m_afMatrix[1] * m_fComponents[0]));
        result.m_fComponents[2] =
            cTransform.m_afMatrix[14] +
            (cTransform.m_afMatrix[10] * m_fComponents[2] +
             (cTransform.m_afMatrix[6] * m_fComponents[1] + cTransform.m_afMatrix[2] * m_fComponents[0]));
        return result;
    }
};

struct S00b28280_Lod
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usNumLeaves;
    short unk0e;
    int unk10;
    int unk14;
    float* m_ppFloatData;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    float* m_pLeafNormals;
};

struct S00b28280_Leaf
{
    char unk00;
    unsigned char m_bValueAt00;
    short unk02;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned short m_usValueAt08;
    short unk1e;
    FUN_00b28440_Class* m_pRockingGroups;
    int unk24;
    unsigned short m_usValueAt28;
    short unk2a;
    S00b28280_Lod* m_pLeafLod;

    void FUN_00b28280(const Matrix4f& cTransform);
};

// @fnv 0x00b28280
void S00b28280_Leaf::FUN_00b28280(const Matrix4f& cTransform)
{
    if (m_pLeafLod && m_pRockingGroups)
    {
        float fScale5;
        int i;
        S00b28280_Lod* pLodA;
        int j_;
        float* pLeafVertex4;

        for (i = 0; i < m_usValueAt28; ++i)
        {
            pLodA = &m_pLeafLod[i];
            for (j_ = 0; j_ < pLodA->m_usNumLeaves; ++j_)
            {
                pLeafVertex4 = pLodA->m_ppFloatData + j_ * 3;
                Vector3D cCoord6(pLeafVertex4[0], pLeafVertex4[1], pLeafVertex4[2]);
                cCoord6 = cCoord6.FUN_00b05000(cTransform);
                _memmove(pLeafVertex4, &cCoord6, 12);

                if (m_bValueAt00)
                {
                    float* kPLeafNormal = pLodA->m_pLeafNormals + j_ * 3;
                    Vector3D cNormal5(kPLeafNormal[0], kPLeafNormal[1], kPLeafNormal[2]);
                    cNormal5 = cNormal5.FUN_00b05000(cTransform);
                    _memmove(kPLeafNormal, &cNormal5, 12);
                }
            }
        }

        fScale5 = *(const float*)&cTransform;
        for (int k = 0; k < m_usValueAt08; ++k)
        {
            m_pRockingGroups[k].Scale(fScale5);
        }
    }
}

void __cdecl FUN_00ec7c56();
struct Vec3B28480
{
    Vec3B28480()
    {
        m_fComponents[2] = 0.0f;
        m_fComponents[1] = 0.0f;
        m_fComponents[0] = 0.0f;
    }
    float m_fComponents[3];
};
struct LeafB28480
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    Vec3B28480 m_kFirstVector;
    int unk3C;
    int unk40;
    int unk44;
    Vec3B28480 m_kTranslation;
};
struct LeafVectorB28480
{
    void* m_pkProxy;
    int m_iAux;
    int m_iAlval;
    LeafB28480* m_pkFirst;
    LeafB28480* m_pkLast;
    LeafB28480* m_pkEnd;
    unsigned int size() const
    {
        return m_pkLast - m_pkFirst;
    }
    const LeafB28480& operator[](unsigned int uiPos) const
    {
        if (!(uiPos < size()))
            FUN_00ec7c56();
        return *(m_pkFirst + uiPos);
    }
};
struct LeafSourceB28480
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    LeafVectorB28480 m_vLeaves;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    unsigned short m_usValueAt28;
    unsigned short unk42;
    int unk44;
    int unk48;
    int m_nTextureWidth;
    int m_nTextureHeight;
    int m_nStyle;
};
struct LeafGeometryB28480
{
    int unk00;
    int unk04;
    unsigned short m_usValueAt28;
    unsigned short unk0A;
    int m_nStyle;
    int m_nTextureWidth;
    int m_nTextureHeight;
    float* m_pfTexCoords;
    unsigned short m_usNumLeaves;
    unsigned short unk1E;
    Vec3B28480* m_pPositions;
    Vec3B28480* m_pLeafVectors;
    void FUN_00b29380(unsigned short usLod, int nSeed);
    void FUN_00b28480(unsigned short usLod, int nSeed, const LeafSourceB28480* pSource);
};

// @fnv 0x00b28480
void LeafGeometryB28480::FUN_00b28480(unsigned short usLod, int nSeed, const LeafSourceB28480* pSource)
{
    m_usValueAt28 = pSource->m_usValueAt28;
    m_nStyle = pSource->m_nStyle;
    m_nTextureWidth = pSource->m_nTextureWidth;
    m_nTextureHeight = pSource->m_nTextureHeight;
    m_usNumLeaves = pSource->m_vLeaves.size();
    m_pPositions = new Vec3B28480[m_usNumLeaves];
    m_pLeafVectors = new Vec3B28480[m_usNumLeaves];
    for (int i = 0; i < m_usNumLeaves; ++i)
    {
        m_pPositions[i] = pSource->m_vLeaves[i].m_kTranslation;
        m_pLeafVectors[i] = pSource->m_vLeaves[i].m_kFirstVector;
    }
    int nNumTexCoords = m_usNumLeaves * m_usValueAt28 * 2 * 4 * 4;
    m_pfTexCoords = new float[nNumTexCoords];
    FUN_00b29380(usLod, nSeed);
}

namespace LeafMatrices {

struct NiPoint3
{
    float x, y, z;
    NiPoint3()
    {
        x = y = z = 0.0f;
    }
    NiPoint3(float afX, float afY, float afZ)
    {
        x = afX;
        y = afY;
        z = afZ;
    }
    float& operator[](int aiIndex)
    {
        return (&x)[aiIndex];
    }
    void Set(float afX, float afY, float afZ)
    {
        x = afX;
        y = afY;
        z = afZ;
    }
};

struct LeafPoint
{
    float x, y, z;
};

struct ThreeByThreeMatrix
{
    float m[9];
};

struct LeafRows
{
    NiPoint3 akRow[4];
    LeafRows()
    {}
};

struct LeafData
{
    bool bValid;
    char pad01[7];
    int iIndex;
    char pad0C[0x30];
};

struct LeafEntry
{
    LeafData kData;
    bool bComputed;
    char pad3D[7];
    bool IsComputed() const
    {
        return bComputed;
    }
};

struct LeafSettings
{
    char pad00[0x10];
    int iMode;
    int GetMode() const
    {
        return iMode;
    }
};

void* __cdecl FUN_00ec44d0(void* apDest, const void* apSrc, unsigned int auiSize);

struct LeafBuilder
{
    int iUnk00;
    LeafSettings* pSettings;
    unsigned short usRowCount;
    unsigned short usUnk0A;
    void* pUnk0C;
    float** ppMatrices;
    int iUnk14;
    int iUnk18;
    unsigned short usLeafCount;
    unsigned short usUnk1E;
    NiPoint3* pDirections;
    NiPoint3* pPositions;
    unsigned short usEntryCount;
    unsigned short usUnk2A;
    LeafEntry* pEntries;

    void FUN_00b29190(unsigned short ausIndex);
    void FUN_00b288f0(LeafData* apOut, unsigned short ausIndex, int aiUnused1, int aiUnused2, float afScale);
};

// @fnv 0x00b288f0
void LeafBuilder::FUN_00b288f0(LeafData* apOut, unsigned short ausIndex, int aiUnused1, int aiUnused2, float afScale)
{
    if (pEntries && ausIndex < usEntryCount && ppMatrices && pPositions && pDirections && pSettings && pUnk0C)
    {
        LeafEntry* pEntry = &pEntries[ausIndex];
        if (!pEntry->IsComputed())
        {
            if (pSettings->GetMode() == 1)
                FUN_00b29190(ausIndex);
            float fFactor = 1.0f;
            if (ausIndex > 0)
                fFactor = 1.0f + ausIndex * afScale;
            NiPoint3 akRows[4];
            NiPoint3 akCopyCur[4];
            for (int i = 0; i < usLeafCount * 2; ++i)
            {
                NiPoint3 kPos = pPositions[i / 2];
                if (i % 2 == 0)
                    kPos[0] = 1.0f - kPos[0];
                NiPoint3* pDir = &pDirections[i / 2];
                ThreeByThreeMatrix kMatIn;
                kMatIn.m[0] = 0.0f;
                kMatIn.m[1] = (1.0f - kPos[0]) * fFactor * pDir->x;
                kMatIn.m[2] = (1.0f - kPos[1]) * fFactor * pDir->y;
                kMatIn.m[3] = 0.0f;
                kMatIn.m[4] = -(kPos[0] * pDir->x) * fFactor;
                kMatIn.m[5] = kMatIn.m[2];
                kMatIn.m[6] = 0.0f;
                kMatIn.m[7] = kMatIn.m[4];
                kMatIn.m[8] = -(kPos[1] * pDir->y) * fFactor;
                LeafPoint kTransVal;
                kTransVal.x = 0.0f;
                kTransVal.y = kMatIn.m[1];
                kTransVal.z = kMatIn.m[8];
                akRows[0].x = kMatIn.m[0];
                akRows[0].y = kMatIn.m[1];
                akRows[0].z = kMatIn.m[2];
                akRows[1].Set(kMatIn.m[3], kMatIn.m[4], kMatIn.m[5]);
                akRows[2].Set(kMatIn.m[6], kMatIn.m[7], kMatIn.m[8]);
                akRows[3].Set(kTransVal.x, kTransVal.y, kTransVal.z);
                for (int j = 0; j < usRowCount; ++j)
                {
                    akCopyCur[0] = akRows[0];
                    akCopyCur[1] = akRows[1];
                    akCopyCur[2] = akRows[2];
                    akCopyCur[3] = akRows[3];
                    float* pDest = ppMatrices[ausIndex] + usRowCount * 16 * i + j * 16;
                    FUN_00ec44d0(pDest, &akCopyCur[0], 0xc);
                    pDest += 4;
                    FUN_00ec44d0(pDest, &akCopyCur[1], 0xc);
                    pDest += 4;
                    FUN_00ec44d0(pDest, &akCopyCur[2], 0xc);
                    pDest += 4;
                    FUN_00ec44d0(pDest, &akCopyCur[3], 0xc);
                    pDest += 4;
                }
            }
            pEntry->bComputed = true;
        }
        *apOut = pEntry->kData;
        apOut->bValid = true;
        apOut->iIndex = ausIndex;
    }
}

}

namespace leafwind {

struct Matrix4f
{
    float m_fComponents[4][4];
};

struct Vector3D
{
    float m_fComponents[3];

    Vector3D(float fX = 0.0f, float fY = 0.0f, float fZ = 0.0f)
    {
        m_fComponents[2] = fZ;
        m_fComponents[1] = fY;
        m_fComponents[0] = fX;
    }
    void Set(float fX, float fY, float fZ)
    {
        m_fComponents[0] = fX;
        m_fComponents[1] = fY;
        m_fComponents[2] = fZ;
    }
    float& operator[](int nIndex)
    {
        return m_fComponents[nIndex];
    }
    Vector3D FUN_00b05000(const Matrix4f& cTransform) const
    {
        float fX = cTransform.m_fComponents[3][0] + cTransform.m_fComponents[2][0] * m_fComponents[2] +
                   cTransform.m_fComponents[1][0] * m_fComponents[1] +
                   cTransform.m_fComponents[0][0] * m_fComponents[0];
        float fY = cTransform.m_fComponents[3][1] + cTransform.m_fComponents[2][1] * m_fComponents[2] +
                   cTransform.m_fComponents[1][1] * m_fComponents[1] +
                   cTransform.m_fComponents[0][1] * m_fComponents[0];
        float fZ = cTransform.m_fComponents[3][2] + cTransform.m_fComponents[2][2] * m_fComponents[2] +
                   cTransform.m_fComponents[1][2] * m_fComponents[1] +
                   cTransform.m_fComponents[0][2] * m_fComponents[0];
        return Vector3D(fX, fY, fZ);
    }
};

inline float Interpolate(float fStart, float m_fEndValue, float fNormalizedPosition)
{
    return fStart + (m_fEndValue - fStart) * fNormalizedPosition;
}

extern Matrix4f* DAT_011f8d88;

struct WindEngine
{
    static const Matrix4f& GetWindMatrix(unsigned short usIndex)
    {
        return DAT_011f8d88[usIndex];
    }
};

struct SLeafLod
{
    int unk00;
    int unk04;
    int unk08;
    unsigned short m_usValueAt0C;
    unsigned short unk0e;
    int unk10;
    int unk14;
    float* m_pFloatArrayAt18;
    int unk1c;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    float* m_pFloatArrayAt34;
    unsigned char* m_pByteArrayAt38;
    int unk3c;
    float* m_pOrigCoordCenterCoords;
};

void* memcpy(void* pDest, const void* pSrc, unsigned int uiSize);

class CLeafGeometryWind
{
  public:
    unsigned char unk00;
    unsigned char m_bWindEnabled;
    unsigned short unk02;
    void* m_pLeafTreeRuntime;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    unsigned short m_usValueAt28;
    unsigned short unk2a;
    SLeafLod* m_pLeafLod;

    void FUN_00b29190(unsigned short usLod);
};

// @fnv 0x00b29190
void CLeafGeometryWind::FUN_00b29190(unsigned short usLod)
{
    SLeafLod* pLod;

    if (m_pLeafTreeRuntime && usLod < m_usValueAt28 && m_bWindEnabled && m_pLeafLod && (pLod = m_pLeafLod + usLod) &&
        pLod->m_pOrigCoordCenterCoords && pLod->m_pFloatArrayAt18)
    {
        Vector3D cPos;
        Vector3D cNewPos;

        for (int i = 0; i < pLod->m_usValueAt0C; ++i)
        {
            float fWeight = pLod->m_pFloatArrayAt34[i];
            const float* pOrigCoord = pLod->m_pOrigCoordCenterCoords + i * 3;
            cPos.Set(pOrigCoord[0], pOrigCoord[1], pOrigCoord[2]);
            unsigned char ucWindMatrix = pLod->m_pByteArrayAt38[i];
            cPos = cPos.FUN_00b05000(WindEngine::GetWindMatrix(ucWindMatrix));
            cNewPos.Set(Interpolate(pOrigCoord[0], cPos[0], fWeight), Interpolate(pOrigCoord[1], cPos[1], fWeight),
                        Interpolate(pOrigCoord[2], cPos[2], fWeight));
            memcpy(pLod->m_pFloatArrayAt18 + i * 3, &cNewPos, 12);
        }
    }
}

}
