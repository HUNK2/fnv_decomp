// fallout/magic/scripteffect_decls.h: declares BGSLoadFormBuffer, ScriptLocals, Script, ActorMover, MagicTarget and more

class TESObjectREFR;
class BGSLoadFormBuffer
{
  public:
    void ReadTypedData(void*, unsigned int);
};
class ScriptLocals
{
  public:
    void* master;
    char flags;
    void* action;
    void* local;
    void* effect;
    ScriptLocals();
    ~ScriptLocals();
    void LoadGame(BGSLoadFormBuffer*);
};
class Script
{
  public:
    ScriptLocals* GetOrCreateScriptLocals();
    void AdvanceScript(TESObjectREFR*, ScriptLocals*, float);
};
class ActorMover
{
  public:
    unsigned int GetCurrentMoveModeType();
};
class MagicTarget
{
  public:
    virtual void vfn_0();
    virtual TESObjectREFR* GetActor();
};
class ActiveEffect
{
  public:
    char data[68];
    virtual void LoadGame(BGSLoadFormBuffer*);
};
class ScriptEffect : public ActiveEffect
{
  public:
    Script* pScript;
    ScriptLocals* m_pScriptLocals;
    virtual void Update(float);
    void LoadGame(BGSLoadFormBuffer*);
};
