// bsshader/beamshader_pass.h: declares BeamTextureState, BeamStage, D3DRenderStateGroup, BeamRefPointer, NiD3DPass and more
#ifndef BEAMSHADER_PASS_H
#define BEAMSHADER_PASS_H

#include "NiRefObject.h"
class BeamTextureState
{
  public:
    void FUN_00e890c0(unsigned int, unsigned int, unsigned int, bool);
};
class BeamStage
{
  public:
    unsigned char pad0[0x10];
    BeamTextureState* state;
    unsigned char pad14[0x4c];
    unsigned int refs;
    void IncRefCount()
    {
        ++refs;
    }
    void DecRefCount()
    {
        if (--refs == 0)
            ReturnToPool();
    }
    void ReturnToPool();
    static void CreateNewStage(NiPointer<BeamStage>&);
};
class D3DRenderStateGroup
{
  public:
    static D3DRenderStateGroup* GetCurrentRenderStateGroup();
    void SetRenderState(unsigned int, unsigned int, bool);
};
class BeamRefPointer
{
  public:
    NiRefObject* object;
    void operator=(NiRefObject* p)
    {
        if (object != p)
        {
            if (object)
                object->DecRefCount();
            object = p;
            if (object)
                object->IncRefCount();
        }
    }
};
class NiD3DPass
{
  public:
    unsigned char pad0[0x14];
    unsigned int stages;
    unsigned int count;
    unsigned int GetStageCount() const
    {
        return count;
    }
    unsigned char pad1c[0x14];
    D3DRenderStateGroup* group;
    unsigned char pad34[0x10];
    BeamRefPointer pixel;
    unsigned char pad48[0x14];
    BeamRefPointer vertex;
    unsigned char pad60[4];
    unsigned int refs;
    void IncRefCount()
    {
        ++refs;
    }
    void DecRefCount()
    {
        if (--refs == 0)
            DestroyPass();
    }
    void DestroyPass();
    static void CreateD3DPass(NiPointer<NiD3DPass>&);
    void FUN_00e802b0(unsigned int, BeamStage*);
    void SetRenderState(unsigned int a, unsigned int b, bool c)
    {
        if (!group)
            group = D3DRenderStateGroup::GetCurrentRenderStateGroup();
        group->SetRenderState(a, b, c);
    }
};
class BeamPassPointer
{
  public:
    NiD3DPass* object;
    BeamPassPointer() : object(0)
    {}
    ~BeamPassPointer()
    {
        if (object)
            object->DecRefCount();
    }
    void operator=(NiD3DPass* const& p)
    {
        if (object != p)
        {
            if (object)
                object->DecRefCount();
            object = p;
            if (object)
                object->IncRefCount();
        }
    }
};
class BeamStagePointer
{
  public:
    BeamStage* object;
    BeamStagePointer() : object(0)
    {}
    ~BeamStagePointer()
    {
        if (object)
            object->DecRefCount();
    }
};
void ConfigureBeamStage(BeamStage*, unsigned int, unsigned int, unsigned int, bool);
class BeamPassShader
{
  public:
    unsigned char padding[0xb4];
    NiPointer<NiD3DPass> pass;
    NiRefObject* vertex;
    NiRefObject* pixel;
    void SetupPass();
    bool InitializePass();
};
#endif
