// fallout_shared/pathfinding/pathingavoidnode.cpp: NavMesh, NavMeshTriangleReference, AvoidNodeList (4 functions)

#include "pathingavoidnode_decls.h"
// @fnv 0x005582f0
NavMeshTriangle* NavMesh::GetTriangle(unsigned short index)
{
    return triangles.FUN_00558dd0(index);
}
// @fnv 0x006a78d0
NavMeshTriangle* NavMeshTriangleReference::FUN_006a78d0() const
{
    return mesh->GetTriangle(triangle);
}

struct Actor;
struct BGSLoadFormBuffer;
struct BGSSaveFormBuffer;
struct SaveLoadFile;
struct ThreeByThreeMatrix;
struct NiPoint3;
struct NiQuaternion;
struct TESForm;
struct TESObjectREFR;
struct hkVector4;
struct blob4
{
    char b[4];
};
struct PathingAvoidanceNode
{
    float GetAvoidanceAtPoint(NiPoint3*);
    int GetType();
    void* GetPoint1();
    void* GetPoint2();
    float GetRadius();
    float GetCost();
    void SaveGame(BGSSaveFormBuffer*);
    void LoadGame(BGSLoadFormBuffer*);
    char m_kLocation[12];
    char TwoComponentVector[12];
    float fRadius;
    float m_fPathingCostCur;
    int eType;
};
typedef char _sizecheck_PathingAvoidNode[sizeof(PathingAvoidanceNode) == 36 ? 1 : -1];
struct BGSLoadGameBuffer
{
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
    int Load(SaveLoadFile*, unsigned int);
    int Load(SaveLoadFile*);
    void ResetReadPosition();
    void SetBuffer(char*, unsigned int, unsigned int);
    char* GetCurrentBufferPointer();
    bool ReadFormIdentifier(unsigned int*);
    unsigned int ReadFormIdentifier();
    void ReadTypedData(NiQuaternion*, unsigned int);
    void ReadTypedData(hkVector4*, unsigned int);
    void ReadTypedData(double*, unsigned int);
    void ReadTypedData(NiPoint3*, unsigned int);
    void ReadTypedData(float*, unsigned int);
    void ReadTypedData(unsigned long*, unsigned int);
    void ReadTypedData(long*, unsigned int);
    void ReadTypedData(unsigned int*, unsigned int);
    void ReadTypedData(int*, unsigned int);
    void ReadTypedData(unsigned short*, unsigned int);
    void ReadTypedData(short*, unsigned int);
    void ReadTypedData(ThreeByThreeMatrix*, unsigned int);
    void ReadTypedData(void*, unsigned int);
    char* LoadString(char*);
    int ReadElementCount();
    void AdvanceBuffer(unsigned int);
    void ReadElementData(void*, unsigned int, unsigned int);
    void ReadDataBlock(void*, unsigned int);
    void* __vecDelDtor(unsigned int);
    char* pBuffer;
    unsigned int iBufferSize;
    unsigned int m_uiReadOffset;
};
typedef char _sizecheck_BGSLoadGameBuffer[sizeof(BGSLoadGameBuffer) == 16 ? 1 : -1];
struct FUN_006dc910_shell : public PathingAvoidanceNode
{
    void LoadPathingAvoidNode(BGSLoadFormBuffer*);
};

struct BGSLoadFormBuffer : public BGSLoadGameBuffer
{
    void ReadTypedData(void*, unsigned int);
};

// Reads a type byte, two floats and a 12-byte block from the load buffer, plus a second 12-byte block when the type is 1.
// @fnv 0x006dc910
void FUN_006dc910_shell::LoadPathingAvoidNode(BGSLoadFormBuffer* apLoadGameBuffer)
{
    unsigned char ctype = 0;
    apLoadGameBuffer->ReadTypedData(&ctype, 1);
    eType = ctype;
    apLoadGameBuffer->ReadTypedData(&fRadius, 4);
    apLoadGameBuffer->ReadTypedData(&m_fPathingCostCur, 4);
    apLoadGameBuffer->ReadTypedData(&m_kLocation, 12);
    if (eType == 1)
    {
        apLoadGameBuffer->ReadTypedData(&TwoComponentVector, 12);
    }
}

struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator-(const NiPoint3&) const;
    NiPoint3 operator+(const NiPoint3&) const;
    NiPoint3 operator*(float) const;
    NiPoint3& operator+=(const NiPoint3&);
    float Dot(const NiPoint3&) const;
    float SqrLength() const;
    float GetLen() const;
    NiPoint3 Divide(float) const;
    void DivideBy(float);
};
extern NiPoint3 NiPoint3_ZERO;

struct AvoidanceVectorData
{
    NiPoint3 point1;
    NiPoint3 point2;
    float fRadius;
    float m_fPathingCostCur;
    int eType;
};

struct AvoidNodeList
{
    unsigned int GetCount();
    AvoidanceVectorData* GetAt(unsigned int);
    float FUN_006dc9f0(const NiPoint3& point, NiPoint3& outDir);
};

// @fnv 0x006dc9f0
float AvoidNodeList::FUN_006dc9f0(const NiPoint3& point, NiPoint3& outDir)
{
    float fValueSum = 0.0f;
    outDir = NiPoint3_ZERO;
    float fCostSum = 0.0f;
    unsigned int count8 = GetCount();
    if (count8 > 0)
    {
        for (unsigned int aI = 0; aI < count8; aI++)
        {
            AvoidanceVectorData* pNode = GetAt(aI);
            float fCost3 = pNode->m_fPathingCostCur;
            NiPoint3 closestPoint = pNode->point1;
            if (pNode->eType == 1)
            {
                NiPoint3 segmentDir = pNode->point2 - pNode->point1;
                NiPoint3 toPoint = point - pNode->point1;
                float fDot = toPoint.Dot(segmentDir);
                if (fDot < 0.0)
                {
                    closestPoint = pNode->point1;
                }
                else if (fDot > segmentDir.SqrLength())
                {
                    closestPoint = pNode->point2;
                }
                else
                {
                    float fSegLen = segmentDir.GetLen();
                    closestPoint = pNode->point1 + (segmentDir * fDot).Divide(fSegLen);
                }
            }
            outDir += closestPoint * fCost3;
            fValueSum += pNode->fRadius;
            fCostSum += fCost3;
        }
        outDir.DivideBy(fCostSum);
    }
    return fValueSum;
}
