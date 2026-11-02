// gamebryo2.2/corelibs/nianimation/nibsplineinterpolator_decls.h: declares NiBinaryStream, NiStream, NiInterpolator, NiBSplineInterpolator

#include "NiObject.h"
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    __forceinline void ReadFloat(float& value)
    {
        unsigned int componentSize = 4;
        position += read(this, &value, 4, &componentSize, 1);
    }
};
class NiStream
{
  public:
    char padding[0x24c];
    NiBinaryStream* input;
    NiObject* DeserializeObject();
};
class NiInterpolator : public NiObject
{
  public:
    float m_fLastTime;
    virtual void LoadBinary(NiStream& stream);
};
class NiBSplineInterpolator : public NiInterpolator
{
  public:
    float m_fStartTime, m_fEndTime;
    NiObject* m_spTransformData;
    NiObject* m_spSplineBasisData;
    virtual void LoadBinary(NiStream& stream);
};
__forceinline void AssignSplineObject(NiObject*& slot, NiObject* object)
{
    if (slot != object)
    {
        if (slot)
            slot->DecRefCount();
        slot = object;
        if (object)
            object->IncRefCount();
    }
}
