// fallout_shared/facegen/bsfacegenmorph_decls.h: declares BSFaceGenMorph, NiPoint3, BSFaceGenMorphDifferential, BSFaceGenMorphStatistical, MagicCaster and more
#ifndef BSFACEGENMORPH_DECLS_H
#define BSFACEGENMORPH_DECLS_H


class NiTriBasedGeom;
class BSFaceGenBaseMorphExtraData;
class BSFaceGenMorph
{
  public:
    BSFaceGenMorph();
    ~BSFaceGenMorph();
    void** m_ppVirtualMethodTable;
};

class NiPoint3
{
  public:
    NiPoint3();
    NiPoint3 operator*(float) const;
    NiPoint3 operator-(const NiPoint3&) const;
    NiPoint3& operator+=(const NiPoint3&);
    float x;
    float y;
    float z;
};

class BSFaceGenMorph_d006606e0 : public BSFaceGenMorph
{
  public:
    BSFaceGenMorph_d006606e0()
    {}
    ~BSFaceGenMorph_d006606e0();
};
class BSFaceGenMorphDifferential : public BSFaceGenMorph_d006606e0
{
  public:
    NiPoint3* m_pkDeltas;
    unsigned int m_uiVertexCount;
    BSFaceGenMorphDifferential(unsigned int count);
    void ApplyDifferentialMorph(NiTriBasedGeom*, BSFaceGenBaseMorphExtraData*, float);
};

class BSFaceGenMorphStatistical : public BSFaceGenMorph_d006606e0
{
  public:
    unsigned long* m_puiVertexIndices;
    unsigned int m_uiVertexCount;
    unsigned int m_uiFirstIndex;
    BSFaceGenMorphStatistical(unsigned int count, unsigned int firstIndex);
    void ApplyDifferentialMorph(NiTriBasedGeom*, BSFaceGenBaseMorphExtraData*, float);
};

extern "C" char DAT_01065cc4[];
extern "C" char DAT_01065cd0[];

class MagicItem;
class MagicCaster
{
  public:
    virtual void SetSelectedMagicItem(MagicItem*);
};
class GeometryVertexBuffer
{
  public:
    char* m_pkDeltas;
    unsigned int stride;
    unsigned int third;

    void SetVertex(unsigned int, const NiPoint3&);
    GeometryVertexBuffer();
    void FUN_00534570(unsigned int, NiPoint3&);
    void CopyV3(NiPoint3&);
    void SetPoint(const NiPoint3&);
    void AddToA();
};
class NiGeometryData
{
  public:
    unsigned short GetVertexCount();
    void FUN_00a67410(GeometryVertexBuffer&);
};
class NiGeometry
{
  public:
    NiGeometryData* FUN_005495f0();
};
class NiTriBasedGeom : public NiGeometry
{
};
class BSFaceGenBaseMorphExtraData
{
  public:
    NiPoint3* FUN_0084e3a0();
};
unsigned int MinUnsigned(unsigned int, unsigned int);
#endif
