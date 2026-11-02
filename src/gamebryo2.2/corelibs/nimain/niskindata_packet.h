// gamebryo2.2/corelibs/nimain/niskindata_packet.h: declares SkinMapContext, SkinBoneContainer, NiSkinData

class ShaderBufferRecord;
template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char*, T&);
};
struct SkinMapContext
{
    NiTStringPointerMap<ShaderBufferRecord*>* map;
};
struct SkinBoneContainer
{
    char padding[0x44];
    unsigned int count;
};
class NiSkinData
{
  public:
    char padding[8];
    SkinBoneContainer* bones;
    unsigned int unused;
    const char* root;
    const char** names;
    bool MapSkinData(SkinMapContext& context);
};
