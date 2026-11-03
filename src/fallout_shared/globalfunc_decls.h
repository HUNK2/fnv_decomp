// fallout_shared/globalfunc_decls.h: declares BSFadeNode, NiFixedString, BipedNodeNames, NiTimeController, NiObjectNET and more
#ifndef FNV_GLOBALFUNC_DECLS_H
#define FNV_GLOBALFUNC_DECLS_H

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
// Canonical folded binding for NiFixedString string-handle conversion.
class BSFadeNode
{
  public:
    void* FUN_0043b1b0();
};
class NiFixedString
{
  public:
    char* m_kHandle;
    NiFixedString(const char*);
    ~NiFixedString();
    NiFixedString(const NiFixedString&);
};
class BipedNodeNames
{
  public:
    static void InitializeMultiBounds();
};
extern NiFixedString* DAT_011c61a4;
extern NiFixedString* DAT_011c61a8;
extern NiFixedString* DAT_011c61ac;
extern NiFixedString* DAT_011c61b0;
extern NiFixedString* DAT_011c61b4;
extern NiFixedString* DAT_011c61b8;
extern NiFixedString* DAT_011c61bc;
extern NiFixedString* DAT_011c61c0;
extern NiFixedString* DAT_011c61c4;
extern NiFixedString* DAT_011c61c8;
extern NiFixedString* DAT_011c61cc;
extern NiFixedString* DAT_011c61d0;
extern NiFixedString* DAT_011c61d4;
extern NiFixedString* DAT_011c61d8;
extern NiFixedString* DAT_011c61dc;
extern NiFixedString* DAT_011c61e0;
extern NiFixedString* DAT_011c61e4;
extern NiFixedString* DAT_011c61e8;
extern NiFixedString* DAT_011c61ec;
extern NiFixedString* DAT_011c61f0;
extern NiFixedString* DAT_011c61f4;
extern NiFixedString* DAT_011c61f8;
extern NiFixedString* DAT_011c61fc;
extern NiFixedString* DAT_011c6200;
extern NiFixedString* DAT_011c6204;
extern NiFixedString* DAT_011c6208;
extern NiFixedString* DAT_011c620c;
extern NiFixedString* DAT_011c6210;
extern NiFixedString* DAT_011c6214;
extern NiFixedString* DAT_011c6218;
extern NiFixedString* DAT_011c621c;
extern NiFixedString* DAT_011c6220;
extern NiFixedString* DAT_011c6224;
extern NiFixedString* DAT_011c6228;
extern NiFixedString* DAT_011c622c;
extern NiFixedString* DAT_011c6230;
extern NiFixedString* DAT_011c6234;
extern NiFixedString* DAT_011c6238;
extern NiFixedString* DAT_011c623c;
extern NiFixedString* DAT_011c6240;
extern NiFixedString* DAT_011c6244;
extern NiFixedString* DAT_011c6248;
extern NiFixedString* DAT_011c624c;
extern NiFixedString* DAT_011c6250;
extern NiFixedString* DAT_011c6254;
extern NiFixedString* DAT_011c6258;
extern NiFixedString* DAT_011c625c;
extern NiFixedString* DAT_011c6260;
extern NiFixedString* DAT_011c6264;
extern NiFixedString* DAT_011c6268;
extern NiFixedString* DAT_011c626c;
extern NiFixedString* DAT_011c6270;
extern NiFixedString* DAT_011c6274;
extern NiFixedString* DAT_011c6278;
enum LANGUAGE
{
    LANGUAGE_ENGLISH,
    LANGUAGE_GERMAN,
    LANGUAGE_FRENCH,
    LANGUAGE_SPANISH,
    LANGUAGE_ITALIAN,
    LANGUAGE_COUNT
};
int FUN_004b71a0();
LANGUAGE GetConfiguredLanguage();
const char* LocateString(const char*, const char*);
template <class T> unsigned int BSStringLength(const T*);
int strcat_s(char*, unsigned int, const char*);
extern "C" int memcpy_s(void*, unsigned int, const void*, unsigned int);
extern "C" unsigned int strlen(const char*);
extern const char* DAT_01189038[4];
extern const char* DAT_01188f84[5];

class NiNode;
class NiTexture;
class NiSourceTexture;
class NiRTTI;
class NiControllerManager;
class NiTimeController
{
  public:
    int FUN_00441110();
};
class NiProperty;
class NiObjectNET
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual NiNode* GetAsNiNode();
    unsigned int m_uiRefCount;
    NiFixedString m_kName;
    NiTimeController* m_pControllers;
    void* m_ppExtraData;
    unsigned short m_usExtraDataCount, m_usMaxSize;
};
class NiBound
{
  public:
    float FUN_0084d030();
};
class NiAVObject : public NiObjectNET
{
  public:
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void* GetAsNiGeometry();
    NiNode* m_pParentNode;
    void* m_spCollisionObject;
    NiBound* m_spWorldBound;
    int IsVisualObject();
    NiProperty* GetProperty(unsigned int);
    NiNode* GetParent();
    class NiExtraData* GetExtraData(const NiFixedString&);
    NiTimeController* GetController(const NiRTTI*);
};
class NiNode : public NiAVObject
{
  public:
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void RemoveObject(NiAVObject*);
    virtual void vfn_ec();
    virtual void RemoveNthObject(unsigned int);
    unsigned int FUN_0043b480();
    NiAVObject* GetAt(unsigned int);
};
class NiProperty
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual unsigned short GetTextureCount();
    virtual void vfn_ec();
    virtual void SetTexture(int, unsigned int, NiTexture*);
    virtual NiTexture* GetTexture(int, unsigned int);
};
class NiTexture
{
  public:
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual const NiFixedString& GetPath() const;
};
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T*);
    ~NiPointer();
    operator T*() const;
};
class TES
{
  public:
    void CreateTextureImage(const char*, NiPointer<NiSourceTexture>&, bool, bool);
};
extern TES* g_TES;
extern NiRTTI DAT_011f444c;
bool NiObject_IsKindOf(const NiRTTI*, NiAVObject*);

class NiExtraData
{
  public:
    bool FUN_004b5fa0();
};
class NiControllerManager
{
  public:
    NiControllerManager* GetStringAtOffset();
    virtual void vfn_0();
    virtual void vfn_4();
    virtual void vfn_8();
    virtual void vfn_c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void* vfn_90(const NiFixedString&, int);
};
class TESTopic;
template <class T> class BSSimpleList;
class TESTopicInfoData
{
  public:
    BSSimpleList<TESTopic*>* GetLinkToList();
};
extern NiNode* DAT_011c6328;
extern NiControllerManager* DAT_011c6324;
extern NiRTTI DAT_011f36ac;
const NiFixedString& FUN_00448a80();
const NiFixedString& FUN_004b5f60();
const NiFixedString& FUN_004b5f70();
const NiFixedString& FUN_004b5f80();
const NiFixedString& FUN_004b5f90();
int FUN_00404dc0(const char*, const char*);
extern "C" int _strnicmp(const char*, const char*, unsigned int);

extern NiRTTI DAT_012024e0;
int FUN_004a2c20(NiProperty*);
class TESObjectLIGH;
class EffectSetting
{
  public:
    void SetLight(TESObjectLIGH*);
};

class NiPoint3
{
  public:
    float x, y, z;
};
extern "C" float logf(float);
struct CollisionObjectCountContext
{
    void* pCurrentObject;
    bool bRecurse;
    unsigned int uiTraversalFlags;
    int iCount;
    void* pUserData;
    void* pAuxiliaryData;
    unsigned int uiFilterFlags;
};
class NiCollisionObject;
void FUN_004b6740(NiCollisionObject*, CollisionObjectCountContext*);
void FUN_00c68900(NiAVObject*, CollisionObjectCountContext*,
                  void (*)(NiCollisionObject*, CollisionObjectCountContext*));
class ActorMover
{
  public:
    unsigned int uiVirtualTable;
    NiPoint3 m_kLookAtTargetPosition;
    bool HasLookAtTarget();
    bool GetLookAtTargetPosition(NiPoint3& point);
};
class PathingGraphNode
{
  public:
    unsigned int iFlags;
    bool IsTransitionNode();
};
class BSSysInfoSystemUtility
{
  public:
    static unsigned int GetRandomGenerator();
};
class RecipeCraftingInfo
{
  public:
    int m_iRequiredLevel, m_iSkill, CategoryID, SubCategoryID;
};
class TESRecipe
{
  public:
    unsigned char layoutPadding0[0x24];
    RecipeCraftingInfo data;
    RecipeCraftingInfo* GetData();
};
class INISettingCollection;
union SETTING_VALUE
{
    bool b;
    int i;
    float f;
    const char* s;
};
template <class Collection> class SettingT
{
  public:
    SETTING_VALUE* Bool();
};
extern SettingT<INISettingCollection> DAT_011d5a30;
class bhkWorld
{
  public:
    static bool QPickCountOverride();
};
extern bool DAT_012677a3;
#endif
