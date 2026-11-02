// gamebryo2.2/corelibs/nimain/nitmapbase_decls.h: declares BaseFormComponent, TESFullName, NavMeshInfo, TESFile, NiUpdateData and more
#ifndef FNV_NITMAPBASE_DECLS_H
#define FNV_NITMAPBASE_DECLS_H

#include "layout_support.h"
#include "NiRefObject.h"

class NiShader;
class RefCountedNamedObject;
class NiObject;

template <> class NiPointer<RefCountedNamedObject>
{
  public:
    RefCountedNamedObject* m_pObject;
    NiPointer<RefCountedNamedObject>& operator=(const NiPointer<RefCountedNamedObject>& other)
    {
        if (m_pObject != other.m_pObject)
        {
            if (m_pObject)
                reinterpret_cast<NiRefObject*>(m_pObject)->DecRefCount();
            m_pObject = other.m_pObject;
            if (m_pObject)
                reinterpret_cast<NiRefObject*>(m_pObject)->IncRefCount();
        }
        return *this;
    }
};

template <class T_Allocator, class T_Key, class T_Data> class NiTMapBase
{
  public:
    virtual void Destructor(bool doFree);
    virtual unsigned int Hash(T_Key key);
    virtual bool Equal(T_Key key1, T_Key key2);
    virtual void FillEntry(NiTMapItem<T_Key, T_Data>* entry, T_Key key, T_Data data);
    virtual void Unk_004(NiTMapItem<T_Key, T_Data>* item);
    virtual NiTMapItem<T_Key, T_Data>* NewItem();
    virtual void Unk_006(NiTMapItem<T_Key, T_Data>* item);

    class MapEntryCount : public T_Allocator
    {
      public:
        unsigned int m_uiCount;
    };

    unsigned int m_uiHashSize;
    NiTMapItem<T_Key, T_Data>** m_ppkHashTable;
    MapEntryCount m_kItemCount;

    bool GetAt(T_Key key, T_Data& data);
    void SetAt(T_Key key, T_Data data);
    bool RemoveAt(T_Key key);
};

template <class T> class DFALL;
class CombatThreatRecord;
template <> class NiTMapBase<DFALL<NiTMapItem<unsigned int, CombatThreatRecord*> >, unsigned int, CombatThreatRecord*>
{
  public:
    char reserved[0x108];
    unsigned int count;
    bool GetFirstPos();
    NiTMapBase* Destructor(unsigned int flags);
    void FUN_008456c0();
};
class TESObjectCELL;
extern void* DAT_01031fec[];
template <> class NiTMapBase<NiTPointerAllocator<unsigned int>, int, TESObjectCELL*>
{
  public:
    void* vtable;
    NiTMapBase(unsigned int size);
    void InitArray(unsigned int size);
};
class TESForm;
extern void* DAT_01019a3c[];
template <> class NiTMapBase<NiTPointerAllocator<unsigned int>, unsigned int, TESForm*>
{
  public:
    void* vtable;
    NiTMapBase(unsigned int size, unsigned int flags);
    void FUN_004705e0(unsigned int size, unsigned int flags);
};
class BaseFormComponent
{
  public:
    BaseFormComponent();
    virtual void Init();
};
class TESFullName : public BaseFormComponent
{
  public:
    BSStringT<char> m_kName;
    TESFullName();
};
void operator delete(void* pointer);
class NavMeshInfo
{
  public:
    char reserved[12];
    TESObjectCELL* cell;
    TESObjectCELL* GetInteriorCell();
};
const char* PrepareScriptMessage(const char*, bool);
class TESFile
{
  public:
    char reserved[0x3e4];
    unsigned int flags;
    char reserved2[0x24];
    unsigned char compileIndex;
    void SetCompileIndex(unsigned char index);
};
class NiUpdateData
{
  public:
    float time;
    bool updateControllers;
    bool isMultiThreaded;
    bool flag6, flag7, flag8;
    NiUpdateData(float time, bool updateControllers, bool isMultiThreaded);
};
class BGSReconstructFormsInAllFilesMap
{
  public:
    void* vtable;
    unsigned int hashSize;
    void** hashTable;
    void* GetFirstPos();
};
class nitmapbase_FormMap
{
  public:
    char storage[16];
    nitmapbase_FormMap();
    ~nitmapbase_FormMap();
};
class FormChangeMap
{
  public:
    nitmapbase_FormMap first;
    nitmapbase_FormMap second;
    FormChangeMap();
};
#endif
