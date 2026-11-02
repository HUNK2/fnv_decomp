// fallout_shared/package_decls_rtti_variant.h: declares TESObjectREFR, MobileObject, PackageTargetRecord, DurationData, TESPackage and more

class TESPatrolPackageData;
class TESObjectREFR
{
  public:
    TESObjectREFR* GetLinkedRef();
};
class MobileObject : public TESObjectREFR
{
};
class PackageTargetRecord
{
  public:
    int GetTargetKind();
    TESObjectREFR* GetReferenceTarget();
    float FUN_0084d030();
};
class DurationData
{
  public:
    unsigned int time, duration;
    DurationData();
    ~DurationData();
    void Copy(DurationData*);
};
enum PTYPE
{
    PT_DUMMY
};
class TESPackage
{
  public:
    virtual ~TESPackage();  // the original class is polymorphic (rtti_variants.py)
  public:
    char base[20];
    unsigned int flags18, flags;
    unsigned char type;
    char pad21;
    unsigned short f22, f24;
    char pad26[2];
    TESPatrolPackageData* data;
    unsigned int f2c, f30, f34;
    DurationData schedule;
    char pad40[8];
    unsigned int f48;
    static float GetPackageDefaultFloat();
    bool IsMustReachLocation();
    bool UsesPackageAnimation();
    bool IsFlag10000Set();
    PTYPE GetPackType();
    const TESPatrolPackageData* GetPackagePatrolData();
    bool IsPackageBlockingGreeting();
    PackageTargetRecord* GetTarget();
    TESObjectREFR* GetResolvedTargetReference(MobileObject*);
    void CopyScheduleFrom(DurationData*);
    void ResetFormData();
    void SetTrespassEnabled(bool);
    unsigned int FUN_00676280(MobileObject*);
    bool GetPackageSearchRadius(MobileObject*, float&);
    bool FUN_00673890();
    bool FUN_00674d20();
    bool FUN_00670ed0();
    bool IsFlag10Set();
    bool IsFlag80Set();
    bool FUN_00670f40();
    bool FUN_00670f60();
    bool IsMustComplete();
};
class ImageSpaceModifierInstanceDOF
{
  public:
    char pad[24];
    unsigned int flags;
    void FUN_005bbd60(bool);
};
extern float gPackageLocationRadius;
class TimeGlobal
{
  public:
    float FUN_0084d030();
};
