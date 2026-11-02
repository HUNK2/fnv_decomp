// fallout_shared/tesscriptrunmanager_decls.h: declares ScriptRunner, ScriptExecutor

class ScriptRunner
{
  public:
    TESObjectREFR* m_pReference;
    TESObject* m_pScriptObject;
    ScriptLocals* m_pScriptLocals;
    TESTopicInfo* m_pTopicInfo;
    TESGlobal* m_pGlobal;
    Script* m_pScript;
    SCRIPT_ERROR m_eScriptError;
    EXPRESSION_ERROR m_eExpressionError;
    int m_iIfStackDepth;
    int m_aiIfStack[10];
    int m_iBlockStackDepth;
    int m_aiBlockOffsets[10];
    int m_aiBlockSizes[10];
    bool m_bScriptCompileFailed;
    bool m_bExecutionFlagSet;

    ScriptRunner();
    bool ParseOutput(Script* script, SCRIPT_OUTPUT& output, unsigned int& offset, int& lineSize,
                     TESObjectREFR** reference, bool skipReference);
    void SetErrorMessage(Script* script, char* message, ...);
    bool ParseBlock(Script* script, const SCRIPT_OUTPUT output, TESObjectREFR* reference, int& blockSize,
                    const unsigned int inputOffset, unsigned int& lineOffset, const unsigned int lineNumber, bool skip,
                    bool skipBlock);
    void SetError(Script* script, SCRIPT_ERROR error);
    bool SetScriptLocalsFromExtraData(Script* script, TESObjectREFR* reference, ScriptLocals* locals);
    bool Run(Script* script, TESObjectREFR* reference, ScriptLocals* locals, TESObjectREFR* target, bool arg5,
             bool arg6, bool arg7, float arg8);
};
FNV_STATIC_ASSERT(sizeof(ScriptRunner) == 0xA4);

class ScriptExecutor
{
  public:
    ScriptRunner* m_pReusableScriptRunner;
    ScriptRunner* m_pActiveScriptRunner;

    ScriptExecutor();
    ~ScriptExecutor();
    static ScriptExecutor* Instance();
    bool Run(Script* script, TESObjectREFR* reference, ScriptLocals* locals, TESObjectREFR* target, bool arg5,
             bool arg6, bool arg7, float arg8);
};
FNV_STATIC_ASSERT(sizeof(ScriptExecutor) == 8);

extern ScriptFunctionInfo g_scriptBlocks[kScriptBlockCount];
extern const char* g_expressionErrorStrings[];
extern void DebugLog(const char* format, ...);
extern bool IsScriptDebuggingEnabled();
extern const char* PrepareScriptMessage(const char* message, bool localized);
extern "C" const char g_nestedScriptRunFormat[];
extern "C" char g_scriptRunLock;
extern int __cdecl InitScriptRunLock(void* lock);
extern void __cdecl FinishScriptRunLock(void* lock);
