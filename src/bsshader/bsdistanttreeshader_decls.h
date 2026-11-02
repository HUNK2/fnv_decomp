#ifndef BSDISTANTTREESHADER_DECLS_H
#define BSDISTANTTREESHADER_DECLS_H


#include "bsdistanttreeshader_types_BSDistantTreeShader.h"
#include "bsdistanttreeshader_types_NiD3DShaderConstantMap.h"
#include "bsdistanttreeshader_types_NiPointer_NiGPUProgram_.h"
#include "bsdistanttreeshader_types_NiConsoleShaderDeclaration.h"

class NiRenderer;
extern NiRenderer* DAT_011f9508;
extern "C" unsigned int __security_cookie;
extern "C" void* fnv_zlib_memset(void*, int, unsigned long);
extern "C" int __cdecl sprintf_s(char*, unsigned int, const char*);
extern "C" void __fastcall __security_check_cookie(unsigned int);

class NiMemObjectAllocation
{
  public:
    static void* operator new(unsigned int size);
};

class NiD3DShaderConstantMapCalls
{
  public:
    NiD3DShaderConstantMap* Create(GraphicsRenderer*, NiGPUProgram__ProgramType);
};

class NiPointerDispatch
{
  public:
    NiPointer_NiGPUProgram_& Replace(NiGPUProgram*);
};

class BSDistantTreeShaderDispatch
{
  public:
    virtual void pad00();
    virtual void pad01();
    virtual void pad02();
    virtual void pad03();
    virtual void pad04();
    virtual void pad05();
    virtual void pad06();
    virtual void pad07();
    virtual void pad08();
    virtual void pad09();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void slot19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void pad39();
    virtual void pad40();
    virtual void pad41();
    virtual void pad42();
    virtual void pad43();
    virtual void pad44();
    virtual void pad45();
    virtual void pad46();
    virtual void pad47();
    virtual void slot48(NiD3DVertexDeclaration*);
    virtual void pad49();
    virtual void pad50();
    virtual void pad51();
    virtual void pad52();
    virtual void pad53();
    virtual void pad54();
    virtual void pad55();
    virtual void pad56();
    virtual void pad57();
    virtual void pad58();
    virtual void pad59();
    virtual void pad60();
    virtual void pad61();
    virtual void pad62();
    virtual void pad63();
    virtual void pad64();
    virtual void pad65();
    virtual void pad66();
    virtual void pad67();
    virtual void pad68();
    virtual void pad69();
    virtual void pad70();
    virtual void slot71();
};

class NiConsoleDeclarationDispatch
{
  public:
    virtual void pad00();
    virtual void pad01();
    virtual void pad02();
    virtual void pad03();
    virtual void pad04();
    virtual void pad05();
    virtual void pad06();
    virtual void pad07();
    virtual void pad08();
    virtual void pad09();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void slot35(int, int, int, int, int);
    virtual void pad36();
    virtual void slot37(int, int, int, int, int, int, int, int);
    virtual void pad38();
    virtual void pad39();
    virtual void pad40();
    virtual void pad41();
    virtual void pad42();
    virtual void pad43();
    virtual void pad44();
    virtual void slot45();
};

class BeamStage
{
  public:
    static void CreateNewStage(NiPointer<BeamStage>&);
    void FUN_00e7def0(unsigned int);
    void ReturnToPool();
};
class NiD3DPass
{
  public:
    static void CreateD3DPass(NiPointer<NiD3DPass>&);
    void FUN_00e802b0(unsigned int, BeamStage*);
};
void ConfigureBeamStage(BeamStage*, unsigned int, unsigned int, unsigned int, bool);
#include "MemoryManager.h"
extern unsigned int DAT_012007b8;
extern "C" int fnv_particle_shader_renderer_level;
#endif
