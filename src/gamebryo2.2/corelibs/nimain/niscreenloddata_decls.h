// gamebryo2.2/corelibs/nimain/niscreenloddata_decls.h: declares NiPoint3, NiTransform, NiBound, ScreenBone, ScreenData and more

struct NiPoint3
{
    float x, y, z;
    NiPoint3 operator+(const NiPoint3& b) const
    {
        NiPoint3 r;
        r.x = x + b.x;
        r.y = y + b.y;
        r.z = z + b.z;
        return r;
    }
};
class NiTransform
{
  public:
    float rotation[9];
    NiPoint3 translation;
    float scale;
    void InvertTransform(NiTransform& result) const;
    NiTransform operator*(const NiTransform& other) const;
};
class NiBound
{
  public:
    NiPoint3 center;
    float radius;
    NiBound& operator=(const NiBound& b)
    {
        center = b.center;
        radius = b.radius;
        return *this;
    }
    void Update(const NiBound&, const NiTransform&);
    void Merge(const NiBound*);
    void TransformPoint(const NiTransform&);
};
struct ScreenBone
{
    NiTransform transform;
    NiBound bound;
    char extra[8];
};
struct ScreenData
{
    char pad[12];
    NiTransform transform;
    ScreenBone* bones;
    unsigned int count;
};
struct ScreenObject
{
    char pad[104];
    NiTransform world;
};
class NiScreenLODData
{
  public:
    char pad[8];
    ScreenData* data;
    void* unused;
    ScreenObject* root;
    ScreenObject** objects;
    void UpdateScreenBound(NiBound& bound);
};
