// fallout/ai/camerashake_decls.h: declares NiFixedString, NiAVObject, NiNode, ModelLoader, FileFinder
class NiFixedString
{
  public:
    const char* handle;
    NiFixedString(const char*);
    ~NiFixedString();
};
class NiAVObject
{
  public:
    void SetName(const NiFixedString&);
};
class NiNode : public NiAVObject
{
};
class ModelLoader
{
  public:
    NiNode* LoadFile(const char*, int, bool, bool, bool, bool);
};
class FileFinder
{
  public:
    enum FILE_LOCATION
    {
        NONE = 0
    };
    static FILE_LOCATION Exist(const char*, char*, unsigned int, unsigned int);
};
extern ModelLoader* g_modelLoader;
extern NiNode* DAT_011dfecc;
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*, ...);
