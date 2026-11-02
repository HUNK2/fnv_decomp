// gamebryo2.2/corelibs/nimain/ninode_packet_decls.h: declares NiPropertyState, MemoryManager, NiStream, NiUpdateData, CloningProcess and more
#ifndef NINODE_PACKET_DECLS_H
#define NINODE_PACKET_DECLS_H

class NiObject;
class NiPropertyState
{
  public:
    void ReleaseAllRefs();
};
class MemoryManager
{
  public:
    void Deallocate(void*);
};
extern MemoryManager g_memoryManager;
inline void DestroyPropertyState(NiPropertyState* p)
{
    if (p)
    {
        p->ReleaseAllRefs();
        g_memoryManager.Deallocate(p);
    }
}

class NiStream
{
  public:
    unsigned char pad[0xD8];
    unsigned int m_uiFormatVersion;
    unsigned int ReadUnsignedInteger();
    unsigned int GetLinkID();
    NiObject* GetLoadedObject();
};

class NiNode;
class NiAVObject;
class NiFixedString;
class NiUpdateData
{
  public:
    float time;
    bool updateControllers;
    bool forceUpdate;
};
class NiCullingProcess;
class NiBound;
class CloningProcess;
class ShaderBufferRecord;

template <class T> class NiPointer
{
};
template <class T> class NiTNewInterface
{
};

template <class T, class U> class NiTArray
{
  public:
    unsigned int m_unknown;
    NiAVObject** m_children;
    unsigned short m_usMaxSize;
    unsigned short m_usArraySize;
    unsigned short m_usEffectiveSize;
    unsigned short m_usGrowBy;
    void SetSize(unsigned int size);
};

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

class NiAVObject
{
  public:
    unsigned char pad[0x14];
    NiNode* m_pParentNode;
    void* m_spCollisionObject;
    NiBound* m_pkWorldBound;
    unsigned char padFlags[0x0C];
    union
    {
        unsigned int m_uiObjectFlags;
        struct
        {
            unsigned int m_flagPad0 : 13;
            unsigned int m_bFlag13 : 1;
            unsigned int m_flagPad1 : 5;
            unsigned int m_bFlag19 : 1;
            unsigned int m_flagPad2 : 12;
        } m_flags;
    };
    unsigned char pad2[0x68];
    virtual void Slot00();
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
    virtual NiAVObject* MakeClone(CloningProcess& process);
    void FUN_00a5ac90(NiAVObject*, CloningProcess&);
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void ProcessClone(CloningProcess& process);
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual NiAVObject* GetObjectByName(const NiFixedString& name);
    virtual void Slot40();
    virtual void UpdateDownwardPass(NiUpdateData&, unsigned int);
    void UpdateTimeControllers(NiUpdateData&, bool);
    virtual void UpdateSelectedDownwardPass(NiUpdateData&, unsigned int);
    virtual void UpdateRigidDownwardPass(NiUpdateData&, unsigned int);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState*);
    void BuildPropertyState(NiPropertyState*, bool, NiPropertyState*&);
    virtual void Slot45();
    virtual void UpdateWorldData(NiUpdateData& data);
    virtual void UpdateWorldBound();
    virtual void UpdateTransformAndBounds(NiUpdateData& data);
    virtual void Slot49();
    virtual void Slot50();
    virtual void Slot51();
    virtual void Slot52();
    virtual void OnVisible(NiCullingProcess& culler);
    virtual void Slot54();
    void Cull(NiCullingProcess& culler);
    void EnsureWorldBound();
    unsigned char SelectedFlag() const
    {
        return (m_uiObjectFlags >> 1) & 1;
    }
    unsigned char RigidFlag() const
    {
        return (m_uiObjectFlags >> 4) & 1;
    }
    unsigned char TransformFlag() const
    {
        return (m_uiObjectFlags >> 2) & 1;
    }
    unsigned char BoundFlag13() const
    {
        return (m_uiObjectFlags >> 13) & 1;
    }
    unsigned char BoundFlag19() const
    {
        return (m_uiObjectFlags >> 19) & 1;
    }
};

class NiPoint3
{
  public:
    float x, y, z;
};
class NiBound
{
  public:
    NiPoint3 m_kCenter;
    float m_fBoundRadius;
    void Merge(const NiBound* other);
    void Set(const NiPoint3& center, float radius)
    {
        m_kCenter = center;
        m_fBoundRadius = radius;
    }
};

extern NiBound DAT_011f4288;
inline const NiBound& GetBound(NiAVObject* object)
{
    return object->m_pkWorldBound ? *object->m_pkWorldBound : DAT_011f4288;
}

class NiNode : public NiAVObject
{
  public:
    void CopyMemberData(NiNode*, CloningProcess&);
    virtual void UpdateDownwardPass(NiUpdateData&, unsigned int);
    virtual void UpdateSelectedDownwardPass(NiUpdateData&, unsigned int);
    virtual void UpdatePropertiesDownwardPass(NiPropertyState*);
    NiTArray<NiPointer<NiAVObject>, NiTNewInterface<NiPointer<NiAVObject> > > m_kChildList;
    virtual void LoadBinary(NiStream& stream);
    virtual void LinkObject(NiStream& stream);
    virtual void ProcessClone(CloningProcess& process);
    virtual NiAVObject* GetObjectByName(const NiFixedString& name);
    virtual void OnVisible(NiCullingProcess& culler);
    virtual void AttachChildInAvailableSlot(NiAVObject*, bool);
    virtual void Slot56();
    virtual void Slot57();
    virtual void Slot58();
    virtual void Slot59();
    virtual void Slot60();
    virtual void Slot61();
    virtual void ReplaceNthObject(unsigned int index, NiAVObject* object);
    virtual void UpdateWorldBound();
    virtual void UpdateTransformAndBounds(NiUpdateData& data);
    virtual void UpdateUpwardPass();
};

class NiPointLight
{
  public:
    unsigned char pad[0xC4];
    float value;
    void FUN_0050dd20(float);
    void FUN_004bc2c0();
};
#endif
