// gamebryo2.2/corelibs/nimain/niskinpartition_decls.h: declares NiAccumulator, NiSkinPartition, Partition

class NiCamera;
class NiAccumulator
{
  public:
    unsigned int refCount;
    const NiCamera* m_pkAccumulationCamera;
    virtual void SetSortingCamera(const NiCamera* camera);
};
class NiSkinPartition
{
  public:
    class Partition
    {
      public:
        void* vtable;
        unsigned short* m_pusBonePalette;
        float* m_pfVertexWeights;
        unsigned short* m_pusSourceVertexIndices;
        unsigned char* m_pucBoneIndices;
        unsigned short* m_pusTriList;
        unsigned short* m_pusStripLengths;
        unsigned short m_usVertices, m_usTriangles, m_usBoneCount, m_usStrips, m_usWeightsPerVertex;
        void* m_pkGeometryRendererData;
        unsigned int GetStripIndexCount();
    };
};
