// fallout_shared/tesdescription_decls.h: declares TESDataHandler, TESFile, CombatProcedure, BaseFormComponent, TESForm and more

class TESDataHandler
{
    char padding[0x620];
    bool loadDescription;

  public:
    bool LoadDescriptionForForm();
};
class TESForm;
enum CHUNK_ID
{
    CHUNK_NONE = 0
};
class TESFile
{
  public:
    unsigned int GetOffset();
    void ReadTESInfo(TESForm*, CHUNK_ID);
};
class CombatController;
class CombatProcedure
{
  public:
    void Initialize(CombatController*);
};
class BaseFormComponent
{
  public:
    BaseFormComponent();
    virtual void Init();
    virtual void Free();
    virtual void CopyFromBase(BaseFormComponent*);
    virtual bool CompareWithBase(BaseFormComponent*);
};
class TESForm
{
  public:
    virtual void Init();
};
class TESDescription : public BaseFormComponent
{
  public:
    unsigned long m_uiDescriptionFileOffset;
    TESDescription();
    virtual void InitializeComponent();
    static void ReadDescriptionFromFile(TESDescription*, TESFile*);
    const char* GetDescription(TESForm*, CHUNK_ID);
    void LoadDescriptionForForm(TESForm*, CHUNK_ID);
};

extern TESDataHandler* g_dataHandler;
class NiNode;
template <class T> class NiPointer
{
  public:
    T* operator->() const;
};
template <class T> class BSStringT
{
    char storage[8];
};
extern BSStringT<char> g_menuParsedXML;
extern const char g_011c72c0_arg1[];
