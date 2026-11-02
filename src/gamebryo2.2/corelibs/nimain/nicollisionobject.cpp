// gamebryo2.2/corelibs/nimain/nicollisionobject.cpp: NiCollisionObject, MyColl, ClaimCls (10 functions)

#include "nicollisionobject_decls.h"
// @fnv 0x00a80fd0
void NiCollisionObject::LoadBinary(NiStream& stream)
{
    NiObject::LoadBinary(stream);
    stream.ResetStreamState();
}
// @fnv 0x00a80ff0
void NiCollisionObject::LinkObject(NiStream& stream)
{
    NiObject::LinkObject(stream);
    m_pkSceneObject = static_cast<NiAVObject*>(stream.GetLoadedObject());
}
// @fnv 0x00a810b0
void NiCollisionObject::SetSceneObject(NiAVObject* object)
{
    m_pkSceneObject = object;
    if (object && object->m_spCollisionObject != this)
        object->AssignCollisionObject(this);
}
// @fnv 0x00a810d0
NiCollisionObject::NiCollisionObject(NiAVObject* apSceneObject) : m_pkSceneObject(apSceneObject)
{
    if (apSceneObject && apSceneObject->m_spCollisionObject != this)
        apSceneObject->AssignCollisionObject(this);
}

extern char const* const g_01267b70_arg1;

// @fnv 0x00a810a0
char const* const* __cdecl FUN_00a810a0()
{
    return &g_01267b70_arg1;
}

struct NiObjectBase
{
    bool RegisterStreamables(NiStream&);
};
struct SceneObj
{
    virtual void f00()
    {}
    virtual void f01()
    {}
    virtual void f02()
    {}
    virtual void f03()
    {}
    virtual void f04()
    {}
    virtual void f05()
    {}
    virtual void f06()
    {}
    virtual void f07()
    {}
    virtual void f08()
    {}
    virtual void f09()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12()
    {}
    virtual void f13()
    {}
    virtual void f14()
    {}
    virtual void f15()
    {}
    virtual void f16()
    {}
    virtual void f17()
    {}
    virtual void f18()
    {}
    virtual void f19()
    {}
    virtual void f20()
    {}
    virtual bool RegisterStreamables(NiStream&)
    {
        return true;
    }
};
struct MyColl : NiObject
{
    SceneObj* m_pkSceneObject;
    bool FUN_00a81010(NiStream&);
};
// Registers the base streamables and, if m_pkSceneObject is set, registers the scene object's streamables; returns false if the base registration fails.
// @fnv 0x00a81010
bool MyColl::FUN_00a81010(NiStream& kStream)
{
    if (!((NiObjectBase*)this)->NiObjectBase::RegisterStreamables(kStream))
        return false;
    if (m_pkSceneObject)
        m_pkSceneObject->RegisterStreamables(kStream);
    return true;
}

struct FakeStream00a81040
{
    virtual void f0()
    {}
    virtual void f1()
    {}
    virtual void f2()
    {}
    virtual void f3()
    {}
    virtual void f4()
    {}
    virtual void f5()
    {}
    virtual void f6()
    {}
    virtual void f7()
    {}
    virtual void f8()
    {}
    virtual void f9()
    {}
    virtual void f10()
    {}
    virtual void f11()
    {}
    virtual void f12(void*)
    {}
};
struct FakeThis00a81040 : NiObject
{
    void* unk08;
    void FUN_00a81040(NiStream&);
};
// Links the object to the stream via NiObject::LinkObject, then calls the stream's f12 with unk08.
// @fnv 0x00a81040
void FakeThis00a81040::FUN_00a81040(NiStream& kStream)
{
    NiObject::LinkObject(kStream);
    ((FakeStream00a81040*)&kStream)->f12(unk08);
}

bool __stdcall IsSameAs(NiObject*);
struct T_00a81060
{
    char _0[8];
    void* _8;
    bool FUN_00a81060(NiObject*);
};
// Returns false if IsSameAs fails or if _8 and pkObject disagree on being null; otherwise returns true.
// @fnv 0x00a81060
bool T_00a81060::FUN_00a81060(NiObject* pkObject)
{
    if (!IsSameAs(pkObject))
        return false;
    if (_8 && !pkObject)
        return false;
    if (!_8 && pkObject)
        return false;
    return true;
}

class BA81100StringArray
{
  public:
    virtual ~BA81100StringArray();
    void SetSize(unsigned int uiMaxSize);
    void SetAt(unsigned int uiIndex, char* const& pcElement);

    unsigned int SetAtGrow(unsigned int uiIndex, char* const& pcElement)
    {
        if (uiIndex >= m_usMaxSize)
            SetSize(uiIndex + m_usGrowBy);
        SetAt(uiIndex, pcElement);
        return uiIndex;
    }
    unsigned int Add(char* const& pcElement)
    {
        return SetAtGrow(m_usSize, pcElement);
    }

    char** m_pBase;
    unsigned short m_usMaxSize;
    unsigned short m_usSize;
    unsigned short m_usESize;
    unsigned short m_usGrowBy;
};

extern const char* g_pcA81100Name;

char* __cdecl FUN_00a7d330(const char* pcString);

class BA81100Base
{
  public:
    virtual void VFunc00();
    virtual void VFunc04();
    virtual void VFunc08();
    virtual void VFunc0C();
    virtual void VFunc10();
    virtual void VFunc14();
    virtual void VFunc18();
    virtual void VFunc1C();
    virtual void VFunc20();
    virtual void VFunc24();
    virtual void VFunc28();
    virtual void VFunc2C();
    virtual void VFunc30();
    virtual void VFunc34();
    virtual void VFunc38();
    virtual void VFunc3C();
    virtual void VFunc40();
    virtual void VFunc44();
    virtual void VFunc48();
    virtual void VFunc4C();
    virtual void VFunc50();
    virtual void VFunc54();
    virtual void VFunc58();
    virtual void VFunc5C();
    virtual void VFunc60();
    virtual void AddExtraViewerStrings(BA81100StringArray* pkStrings);

    void BaseGetViewerStrings(BA81100StringArray* pkStrings);
};

class BA81100Object : public BA81100Base
{
  public:
    void FUN_00a81100(BA81100StringArray* pkStrings);
};

// Appends the base viewer strings, the A81100 name string, and any extra viewer strings to pkStrings.
// @fnv 0x00a81100
void BA81100Object::FUN_00a81100(BA81100StringArray* pkStrings)
{
    BaseGetViewerStrings(pkStrings);
    pkStrings->Add(FUN_00a7d330(g_pcA81100Name));
    AddExtraViewerStrings(pkStrings);
}

extern void* g_011f4ad4;

void* __cdecl FUN_00a7d330(void* pv);
void* __cdecl FUN_00a7d5a0(char const* pcName, void* pvObj);

struct StreamShell
{
    unsigned char unk0[8];
    unsigned short m_usSize;
    unsigned short m_usPos;
    unsigned short m_usHold;
    unsigned short m_usAdd;

    void FUN_0096ad30(unsigned int uiNewEnd);
    void FUN_0096ae90(unsigned int uiPos, void* pvData);
};

class ClaimCls
{
  public:
    unsigned char unk0[8];
    void* m_pkSceneObject;
    void WriteToStream(StreamShell& kStream);
};

// @fnv 0x00a81160
void ClaimCls::WriteToStream(StreamShell& kStream)
{
    {
        void* p = FUN_00a7d330(g_011f4ad4);
        unsigned int uiPos = kStream.m_usPos;
        unsigned int uiSize = kStream.m_usSize;
        if (uiPos >= uiSize)
        {
            kStream.FUN_0096ad30(uiPos + kStream.m_usAdd);
        }
        kStream.FUN_0096ae90(uiPos, &p);
    }
    {
        void* q = FUN_00a7d5a0("m_pkSceneObject", m_pkSceneObject);
        unsigned int uiPos = kStream.m_usPos;
        unsigned int uiSize = kStream.m_usSize;
        if (uiPos >= uiSize)
        {
            kStream.FUN_0096ad30(uiPos + kStream.m_usAdd);
        }
        kStream.FUN_0096ae90(uiPos, &q);
    }
}
