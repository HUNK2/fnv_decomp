#ifndef FNV_NISTREAM_CPP_DECLS_H
#define FNV_NISTREAM_CPP_DECLS_H

// which this folder resolves case-insensitively to the niobject.h unit file: take the canonical include/NiObject.h and skip that file.
#include "../../../../include/NiObject.h"
#define FNV_NIOBJECT_UNIT_H
#define NiStream NiStreamAtlas
#include "nistream_types_NiStream.h"
#undef NiStream
#include "nistream_types_NiBinaryStream.h"

class NiTexture;
extern "C" bool __cdecl fnv_NiStreamGetTexture(const char* textureName, NiPointer<NiTexture>& texture);
extern "C" void __cdecl fnv_CopyFilePath(char* destination, unsigned int destinationSize, const char* source,
                                         unsigned int sourceSize);
extern "C" bool __cdecl fnv_StandardizeFilePath(char* path);
extern "C" char fnv_NiStreamCriticalSection;
extern "C" void(__stdcall* fnv_EnterCriticalSection)(void* section);
extern "C" void(__stdcall* fnv_LeaveCriticalSection)(void* section);

class NiStreamLinkIDSet : public NiTSet_unsigned_int_NiTMallocInterface_unsigned_int___
{
  public:
    void Realloc(unsigned int allocationCount);
};

class NiStreamTopObjects : public NiTLargeObjectArray_NiPointer_NiObject___
{
  public:
    void RemoveAll();
    void FUN_00cc1a10(unsigned int index, const NiPointer<NiObject>& object);
    void FUN_00a64fe0(unsigned int size);
};

class NiStreamFixedStrings : public NiTLargeObjectArray_NiFixedString_
{
  public:
    void RemoveAll();
};

class NiStream;
class NiStreamableObject : public NiObject
{
  public:
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual void Slot15() = 0;
    virtual void Slot16() = 0;
    virtual void Slot17() = 0;
    virtual void Slot18() = 0;
    virtual void Slot19() = 0;
    virtual void Slot20() = 0;
    virtual void RegisterStreamables(NiStream* stream) = 0;
};

class NiStreamVirtualView
{
  public:
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual void Slot13() = 0;
    virtual void Slot14() = 0;
    virtual bool Load() = 0;
};

typedef void(__cdecl* NiStreamPostProcess)(NiStream&, NiObject*);
class NiUnionBV
{
  public:
    void AddPostProcess(NiStreamPostProcess& function);
};
extern NiUnionBV* DAT_011f4788;
class NiShader;
template <class K, class V> class NiTPointerMap;
template <class M, class V> class NiTStringTemplateMap
{
  public:
    void SetAt(const char*, V);
};
extern NiTStringTemplateMap<NiTPointerMap<const char*, NiShader*>, NiShader*>* DAT_011f4784;
extern bool DAT_011f4780;

class NiStreamMemoryBuffer : public NiBinaryStream
{
  public:
    unsigned int m_uiPosition;
    unsigned int m_uiCapacity;
    int m_uiLogicalSize;
    char* m_pString;
    unsigned int m_uiValue1;
    void FUN_00aa2fb0(char* buffer, int size);
    void FUN_00aa2ff0();
    void NiMemStreamDestructor();
    char* FUN_00aa2d60();
};

inline void NiStreamReadUInt(NiBinaryStream* stream, unsigned int& value)
{
    unsigned int componentSize = sizeof(value);
    stream->m_uiStreamFlags += stream->m_pfnRead(stream, &value, sizeof(value), &componentSize, 1);
}

inline void NiStreamWriteUInt(NiBinaryStream* stream, unsigned int& value)
{
    unsigned int componentSize = sizeof(value);
    stream->m_uiStreamFlags += stream->m_pfnWrite(stream, &value, sizeof(value), &componentSize, 1);
}

class NiStream : public NiStreamAtlas
{
  public:
    NiObjectGroup* GetObjectGroup(unsigned int groupID);
    NiObject* GetLoadedObject();
    void SetLinkIDCount(unsigned int numberOfLinkIDs);
    void RegisterObjects();
    bool Save(NiBinaryStream* stream);
    void GetTexture(const char* textureName, NiPointer<NiTexture>& texture);
    void SetStreamPath(const char* path);
    bool Load(NiBinaryStream* stream);
    void ClearTopLevelObjects();
    void InsertObject(NiObject* object);
    void SaveTopLevelObjects();
    void ChangeObject(NiObject* object);
    NiObject* DeserializeObject();
    bool Load(char* buffer, int size);
    bool Save(char*& buffer, int& size);
    static void RegisterPostProcess(NiStreamPostProcess function);
    static int RegisterObjectLoader(const char* name, NiObject*(__cdecl* loader)());
    bool GetLastLoadedFilePath(char* buffer, unsigned int size);
};

#endif
