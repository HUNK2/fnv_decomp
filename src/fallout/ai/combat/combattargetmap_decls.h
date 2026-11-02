
class TESFile;
class BGSReconstructFormsInFileMap;
class BGSReconstructFormsInAllFilesMap
{
  public:
    void* GetFirstPos();
    void GetNext(void*&, TESFile*&, BGSReconstructFormsInFileMap*&);
};
class BGSSaveLoadChangesMap
{
  public:
    bool RemoveAt(unsigned int);
};
class Actor
{
  public:
    static float GetActorScale();
};
class CombatThreatRecord
{
  public:
    ~CombatThreatRecord();
    bool IsXLessThan(float);
};
class CombatTargetMapLock
{
  public:
    void AcquireLock();
    void FUN_00aa62e0();
};
class CombatTargetMap
{
  public:
    unsigned char mapStorage[16];
    CombatTargetMapLock lock;
    void ResetTargetMap();
};
