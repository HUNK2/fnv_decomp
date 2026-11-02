// gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderprogramfactory_packet.h: declares NiD3DShaderProgramFactory, DirectoryEntry

class NiShader;
class NiD3DShaderProgramCreator;
template <class K, class V> class NiTPointerMap
{
};
template <class B, class V> class NiTStringTemplateMap
{
  public:
    void SetAt(const char*, NiShader*);
};
typedef NiTStringTemplateMap<NiTPointerMap<const char*, NiShader*>, NiShader*> CreatorMap;
extern CreatorMap* DAT_0126fa14;
extern "C" const char* __cdecl strchr(const char*, int);
extern "C" int __cdecl tolower(int);
class NiD3DShaderProgramFactory
{
  public:
    const char* GetNextName(void*&);
    static bool RegisterCreator(const char*, NiD3DShaderProgramCreator*);
    static void CreateFactoryInstance();
};
struct DirectoryEntry
{
    DirectoryEntry* next;
    unsigned int unused;
    const char* value;
};
