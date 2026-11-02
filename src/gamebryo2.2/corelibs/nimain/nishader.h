// gamebryo2.2/corelibs/nimain/nishader.h: declares NiRTTI, NiObject, NiAVObject, GarbageCollectorObjectPtr, NiShader

#pragma optimize("", off)
class NiRTTI
{
  public:
    const char* m_pcName;
    const NiRTTI* m_pBaseRTTI;
};
class NiObject
{
  public:
    bool IsKindOfType(const NiRTTI*) const;
};
class NiAVObject : public NiObject
{
};
bool FUN_0043b300(const NiRTTI*, NiAVObject*);
class GarbageCollectorObjectPtr
{
  public:
    unsigned int storage[2];
    NiAVObject* operator->() const;
};
extern NiRTTI DAT_01267b70;
GarbageCollectorObjectPtr* FUN_00c85ef0(GarbageCollectorObjectPtr*, NiAVObject*, const NiRTTI*);
class NiShader
{
  public:
    virtual ~NiShader();
    virtual void DeleteThis();
    virtual const NiRTTI* GetRTTI() const;
    static NiAVObject* DynamicCast(NiAVObject*);
    NiShader* DynamicCast(const NiRTTI*);
    __forceinline bool IsKindOfType(const NiRTTI* type) const
    {
        const NiRTTI* current = GetRTTI();
        while (current)
        {
            if (current == type)
                return true;
            current = current->m_pBaseRTTI;
        }
        return false;
    }
};
// @fnv 0x0043b300
bool FUN_0043b300(const NiRTTI* type, NiAVObject* object)
{
    if (!object)
        return false;
    return object->IsKindOfType(type);
}

// @fnv 0x004b5a50
NiAVObject* NiShader::DynamicCast(NiAVObject* object)
{
    GarbageCollectorObjectPtr result;
    return FUN_00c85ef0(&result, object, &DAT_01267b70)->operator->();
}

#pragma optimize("", on)
// @fnv 0x00b4f580
NiShader* NiShader::DynamicCast(const NiRTTI* type)
{
    return IsKindOfType(type) ? this : 0;
}
#pragma optimize("", off)
