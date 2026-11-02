// fallout/interface/fadermanager_update_decls.h: declares AutoMemContext, TimeGlobal, TileShaderProperty
#ifndef FADERMANAGER_UPDATE_DECLS_H
#define FADERMANAGER_UPDATE_DECLS_H

// Private declarations for the fader update's out-of-line helpers.
enum MEM_CONTEXT
{
    MEM_CONTEXT_INTERFACE = 13
};
class AutoMemContext
{
  public:
    MEM_CONTEXT m_eMemoryContext;
    AutoMemContext(MEM_CONTEXT, bool, const char*, int);
    ~AutoMemContext();
};
class TimeGlobal
{
  public:
    float GetSecondsPassed();
};
extern TimeGlobal g_timeGlobal;
class NiTexture;
class TileShaderProperty : public NiMemObject
{
  public:
    unsigned char layout[176];
    TileShaderProperty(bool);
    void SetTextureImage(NiTexture*);
    void FUN_008cc6d0(int);
    void SetAlpha(float);
};
#endif
