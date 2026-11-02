#ifndef PATHINGREQUEST_DECLS_H
#define PATHINGREQUEST_DECLS_H

class Actor;
class BGSLoadFormBuffer;
class TESForm;
class TESObjectREFR;
class TESPackage;
class PlayerCharacter;
class BGSLoadFormBufferView
{
  public:
    virtual unsigned char GetVersion();
    virtual TESForm* GetForm();
    virtual TESObjectREFR* GetReference();
    virtual Actor* GetActor();
};
class Calendar
{
  public:
    unsigned int GetDaysPassed();
};
class MobileObject
{
  public:
    TESPackage* GetCurrentPackage();
};
extern PlayerCharacter* g_thePlayer;
class BGSLoadFormBuffer
{
  public:
    virtual unsigned char GetVersion();
    void ReadTypedData(void*, unsigned int);
    int ReadElementCount();
};
class PathingLocationLoadView
{
  public:
    virtual void vfn_0();
    virtual void LoadGame(BGSLoadFormBuffer*);
};
class PathingAvoidanceNode
{
  public:
    void LoadPathingAvoidNode(BGSLoadFormBuffer*);
};
template <class T, unsigned int N> class BSSimpleArray;
class PathingAvoidNodeArray
{
  public:
    char data[24];
    PathingAvoidNodeArray();
    ~PathingAvoidNodeArray();
    PathingAvoidNodeArray* Destroy(unsigned int);
    void FUN_006e3960();
    void FUN_006e39d0();

    static void* operator new(unsigned int);
    static void operator delete(void*, unsigned int);
    void SetSize(unsigned int, bool);
    PathingAvoidanceNode* FUN_006a1400(unsigned int);
};
extern unsigned char DAT_0106d1d8;
extern unsigned char DAT_0106d1e4;
class PathingAvoidNodeArrayDestructionView
{
  public:
    void Destruct();
};
class PathingAvoidPointerView
{
  public:
    PathingAvoidPointerView& Assign(PathingAvoidNodeArray*);
    PathingAvoidNodeArray* Get();
};

int Warning(const char*, ...);
class FUN_006e4080 : public PathingRequest
{
  public:
    char extra[60];
    FUN_006e4080();
};
class PathingRequestClosePoint : public PathingRequest
{
  public:
    char extra[8];
    PathingRequestClosePoint();
};
class PathingRequestFlee : public PathingRequest
{
  public:
    char extra[4];
    PathingRequestFlee();
};
class PathingRequestCoveredMove : public PathingRequest
{
  public:
    char extra[44];
    PathingRequestCoveredMove();
};
class PathingRequestLOS : public PathingRequest
{
  public:
    char extra[40];
    PathingRequestLOS();
};
class PathingRequestOptimalLocation : public PathingRequest
{
  public:
    char extra[16];
    PathingRequestOptimalLocation();
};
class FUN_006e4a50 : public PathingRequest
{
  public:
    char extra[92];
    FUN_006e4a50();
};
extern const float runtimeFloatSettingDefault65;
extern const NiPoint3 pathingrequestZero;
#endif
