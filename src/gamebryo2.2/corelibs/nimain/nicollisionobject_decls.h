// gamebryo2.2/corelibs/nimain/nicollisionobject_decls.h: declares NiObject, NiCollisionObject, NiStream, NiAVObject
#ifndef NICOLLISIONOBJECT_DECLS_H
#define NICOLLISIONOBJECT_DECLS_H

class NiStream;
class NiAVObject;
class NiObject
{
  public:
    NiObject();
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    unsigned int m_uiRefCount;
};
class NiCollisionObject : public NiObject
{
  public:
    NiCollisionObject(NiAVObject*);
    virtual void LoadBinary(NiStream&);
    virtual void LinkObject(NiStream&);
    void SetSceneObject(NiAVObject*);
    NiAVObject* m_pkSceneObject;
};
class NiStream
{
  public:
    void ResetStreamState();
    NiObject* GetLoadedObject();
};
class NiAVObject : public NiObject
{
  public:
    unsigned char padding[0x14];
    NiCollisionObject* m_spCollisionObject;
    void AssignCollisionObject(NiCollisionObject*);
};
#endif
