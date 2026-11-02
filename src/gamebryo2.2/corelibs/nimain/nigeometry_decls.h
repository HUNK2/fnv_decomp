// gamebryo2.2/corelibs/nimain/nigeometry_decls.h: declares NiRTTI, NiCollisionObject, NiCullingProcess, NiBinaryReader, NiFixedString and more
#ifndef FNV_TASK_NIGEOMETRY_DECLS_H
#define FNV_TASK_NIGEOMETRY_DECLS_H

class NiAVObject;
class NiRTTI
{
  public:
    bool IsExactly(const NiRTTI* type) const
    {
        return this == type;
    }
};
class NiGeometry;
class NiBound;
class NiTransform;
class CloningProcess;
class NiGeometryData;
class NiCollisionObject
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual NiCollisionObject* Clone(CloningProcess&);
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Unk24(void* state);
    virtual void Unk25();
};
class NiCullingProcess
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Append(NiGeometry* geometry);
};
class NiStream;
struct NiBinaryReader
{
    typedef int(__cdecl* ReadProc)(NiBinaryReader*, unsigned int*, unsigned int, void*, unsigned int);
    void* m_ppVirtualMethodTable;
    unsigned int m_uiPosition;
    ReadProc m_pRead;
};
class NiFixedString
{
  public:
    char* m_pObject;
};
template <class T> void ReadBinaryValue(NiStream& stream, T& value);
template <> void ReadBinaryValue<unsigned int>(NiStream& stream, unsigned int& value);
class NiObject
{
  public:
    virtual ~NiObject();
    virtual void DeleteThis();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual NiObject* Clone(CloningProcess& process);
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void ProcessClone(CloningProcess& process);
    unsigned int m_uiRefCount;
};
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* value);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* value);
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    operator T*()
    {
        return m_pObject;
    }
    T* operator->()
    {
        return m_pObject;
    }
    NiPointer<T>& operator=(T* object)
    {
        T* old = m_pObject;
        if (old != object)
        {
            if (old && InterlockedDecrement((long volatile*)&old->m_uiRefCount) == 0)
                old->DeleteThis();
            m_pObject = object;
            if (object)
                InterlockedIncrement((long volatile*)&object->m_uiRefCount);
        }
        return *this;
    }
};
class NiProperty
{
  public:
    virtual ~NiProperty();
    virtual void DeleteThis();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual int GetType();
    unsigned int m_uiRefCount;
};
class NiPropertyState
{
  public:
    NiPointer<NiProperty> m_kProperties[8];
    NiPropertyState& operator=(const NiPropertyState& other);
};
class NiPropertyNode
{
  public:
    NiPropertyNode* m_pkNext;
    unsigned int m_uiPad;
    NiPointer<NiProperty> m_pkProperty;
    static NiPointer<NiProperty>& GetNext(NiPropertyNode*& pos)
    {
        NiPointer<NiProperty>& value = pos->m_pkProperty;
        pos = pos->m_pkNext;
        return value;
    }
};
extern unsigned int DAT_011f42a4;
extern unsigned int DAT_011f42a0;
class RecursiveSpinLock
{
  public:
    void Lock(const char* name);
};
class ShaderBufferRecord;
template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char* key, T& value);
};
class CloningProcess
{
  public:
    NiTStringPointerMap<ShaderBufferRecord*>* m_pCloneMap;
};
class NiPoint3
{
  public:
    float x, y, z;
    static const NiPoint3 ZERO;
};
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#pragma intrinsic(memcpy)
class NiBound
{
  public:
    NiPoint3 center;
    union
    {
        float radius;
        unsigned int radiusBits;
    };
    NiBound()
    {}
    NiBound(const NiBound& b) : center(b.center), radiusBits(b.radiusBits)
    {}
    void SetCenterAndRadius(const NiPoint3& point, float value)
    {
        center = point;
        radius = value;
    }
    void Update(const NiBound&, const NiTransform&);
    void TransformPoint(const NiTransform&);
    bool FUN_00a92660(const NiBound&);
};
extern NiBound DAT_011f4288;
inline const NiBound& __fastcall PreviousBound(NiBound* b)
{
    return b ? *b : DAT_011f4288;
}
inline bool BoundFlag(unsigned int bits, unsigned int shift)
{
    return (bits >> shift) & 1;
}
inline NiBound CopyWorldBound(NiBound* b)
{
    return b ? *b : DAT_011f4288;
}
class MemoryManager
{
  public:
    void* Allocate(unsigned int);
};
extern MemoryManager g_memoryManager;
class NiLODNode;
class NiScreenLODData
{
  public:
    void UpdateScreenBound(NiLODNode*);
};
class NiTransform
{
  public:
    unsigned int values[13];
};
class NiFlags
{
  public:
    unsigned int bits;
    bool GetBit(unsigned int pos) const
    {
        return (bits >> pos) & 1;
    }
};
class NiObjectNET
{
  public:
    void CopyMemberData(NiObjectNET*, CloningProcess&);
};
class NiAVObject
{
  public:
    virtual void Slot00();
    virtual void Slot01();
    virtual NiRTTI* GetRTTI();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void SetWorldBound(NiBound*);
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void FinalUpdate(bool update);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState* state);
    virtual void LoadBinary(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);
    virtual void LinkObject(NiStream& stream);
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void ApplyPropertyState(const NiPropertyState&);
    void SetName(const NiFixedString&);
    void SetSelectiveUpdateFlags(bool&, bool, bool&);
    void CopyMemberData();
    void FUN_00a5ac90(NiAVObject*, CloningProcess&);
    void FUN_00a5abe0(NiAVObject*, void*, CloningProcess&);
    void AssignCollisionObject(NiCollisionObject*);
    unsigned char m_pad18[0x14];
    void* m_pParentNode;
    NiPointer<NiCollisionObject> m_spCollisionObject;
    NiBound* m_worldBound;
    unsigned char m_kProperties[0xc];
    unsigned int m_flags;
    NiTransform m_kLocalTransform;
    NiTransform m_worldTransform;
    unsigned char m_uiContentCount[0x1c];
};
class NiGeometryData : public NiObject
{
};
template <> NiPointer<NiAVObject>& NiPointer<NiAVObject>::operator=(NiAVObject*);
class NiMemObject
{
  public:
    static void* operator new(unsigned int) throw();
    static void* operator new(unsigned int, void* memory) throw()
    {
        return memory;
    }
};
class NiD3DShaderInterface : public NiMemObject
{
  public:
    NiD3DShaderInterface() throw();
    bool IsExactKindOf(const NiRTTI* type)
    {
        return GetRTTI()->IsExactly(type);
    }
    virtual void vfn_00();
    virtual void vfn_04();
    virtual NiRTTI* GetRTTI();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void Attach(NiAVObject*);
    char data[0x10];
};
inline NiD3DShaderInterface* CreateGeometryShader()
{
    NiD3DShaderInterface* shader = 0;
    void* memory = NiMemObject::operator new(sizeof(NiD3DShaderInterface));
    if (memory)
        shader = new (memory) NiD3DShaderInterface;
    return shader;
}
inline bool& TestGeometryShaderType(NiD3DShaderInterface* object, const NiRTTI* type, bool& result)
{
    result = (unsigned char)(object->GetRTTI() == type) & 255;
    return result;
}
inline bool NiIsExactKindOf(const NiRTTI* type, NiD3DShaderInterface* object)
{
    return object ? object->IsExactKindOf(type) : false;
}
extern NiRTTI DAT_011f5d08;
class NiTexture
{
  public:
    const NiFixedString& GetFilename();
};
class NiD3DShaderProgram
{
  public:
    const char* GetName();
};
class MagicItem;
class NonActorMagicCaster
{
  public:
    void SetSelectedMagicItem(MagicItem*);
};
class NiController
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void Update();
    char pad[0x2c];
    NiController* next;
};
struct NiGeometryProperties
{
    char pad[12];
    NiPropertyState* state;
};
class NiGeometry : public NiAVObject
{
  public:
    NiPointer<NiGeometryData> m_spGeometryData;
    NiPointer<NiObject> m_spSkinningInstance;
    NiD3DShaderInterface* m_shader;
    void SetSelectiveUpdateFlags(bool&, bool, bool&);
    virtual void UpdateWorldBound();
    const NiBound& GetBoundingVolume() const
    {
        if (m_worldBound)
            return *m_worldBound;
        return DAT_011f4288;
    }
    bool GetFlag19() const
    {
        return ((const NiFlags*)&m_flags)->GetBit(19);
    }
    bool GetFlag13() const
    {
        return ((const NiFlags*)&m_flags)->GetBit(13);
    }
    bool GetFlag22() const
    {
        return (m_flags >> 22) & 1;
    }
    void SetFlag22(bool value)
    {
        unsigned int flags = m_flags;
        if (value)
            flags |= 0x400000;
        else
            flags &= ~0x400000;
        m_flags = flags;
    }
    NiGeometry* CopyMemberData();
    void UpdatePropertyControllers(NiGeometryProperties&);
    virtual void OnVisible(NiCullingProcess& process);
    virtual void LinkObject(NiStream& stream);
    virtual void ReplaceModelData(NiGeometryData* data);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState* state);
    virtual void LoadBinary(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);
};
class NiStream
{
  public:
    NiObject* GetLoadedObject();
    void ResetStreamState();
    void ReadStringTableEntry(NiFixedString& value);
    void ReadFixedString(NiFixedString& value);
};
#endif
