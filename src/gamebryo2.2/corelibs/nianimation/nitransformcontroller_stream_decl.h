// gamebryo2.2/corelibs/nianimation/nitransformcontroller_stream_decl.h: declares NiStream
#ifndef NITRANSFORMCONTROLLER_STREAM_DECL_H
#define NITRANSFORMCONTROLLER_STREAM_DECL_H

class NiObject;
class NiStream
{
  public:
    void ResetStreamState();
    NiObject* GetLoadedObject();
};
#endif
