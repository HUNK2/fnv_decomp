// fallout_shared/tesconditionitem_decls.h: declares TESGlobal, TESFile
#ifndef FNV_TESCONDITIONITEM_DECLS_H
#define FNV_TESCONDITIONITEM_DECLS_H

class TESObjectREFR;
class TESGlobal : public TESForm
{
};

class TESFile : public TESFileStub
{
  public:
    unsigned int GetChunkID();
    bool IsEndianConversionRequired();
    bool GetChunkData(void* data, unsigned int size);
};

#endif
