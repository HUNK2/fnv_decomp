// bsshader/imagespacemanager_geometry.h: declares NiUpdateData, NiGlobalStringTable, NiScreenElementsData, NiAVObject, NiScreenElements and more
#ifndef IMAGESPACEMANAGER_GEOMETRY_H
#define IMAGESPACEMANAGER_GEOMETRY_H

#include "NiObject.h"
#include "NiFixedString.h"
class NiUpdateData
{
  public:
    float time;
    bool a, b, c, d, e;
};
class NiGlobalStringTable
{
  public:
    static char* AddString(const char*);
};
extern NiFixedString EmptyFS;
class NiScreenElementsData : public NiObject
{
  public:
    char padding[0x70 - 8];
    static void* operator new(unsigned int) throw();
    static void operator delete(void*);
    NiScreenElementsData(bool, bool, unsigned short, int, int, int, int, int, int);
    bool FUN_00a87ae0(int, int, int);
    bool SetRectangleBounds(int, float, float, float, float);
    bool FUN_00a88130(int, int, float, float, float, float);
    void FUN_00a87900();
};
class NiAVObject : public NiObject
{
  public:
    void SetName(const NiFixedString&);
    void UpdateSceneObject();
    void Update(NiUpdateData&);
};
class NiScreenElements : public NiAVObject
{
  public:
    char padding[0xb8 - 8];
    NiScreenElementsData* data;
    char tail[8];
    static void* operator new(unsigned int) throw();
    static void operator delete(void*);
    NiScreenElements(NiScreenElementsData*);
    NiScreenElementsData* GetData()
    {
        return data;
    }
};
template <class T> class GeometryPointer
{
  public:
    T* m_pObject;
    T* operator->() const
    {
        return m_pObject;
    }
    operator T*() const
    {
        return m_pObject;
    }
    GeometryPointer& operator=(T* p)
    {
        if (m_pObject != p)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = p;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
};
class GeometryString : public NiFixedString
{
  public:
    GeometryString(const char* s)
    {
        m_kHandle = NiGlobalStringTable::AddString(s);
    }
    ~GeometryString()
    {
        if (m_kHandle != EmptyFS.m_kHandle)
            InterlockedDecrement(reinterpret_cast<volatile long*>(m_kHandle - 8));
    }
};
#endif

extern const float DAT_0104a494;
extern const float DAT_010162c0;
extern const float DAT_01012054;
