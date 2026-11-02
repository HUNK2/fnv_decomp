#ifndef FNV_NISMARTPOINTER_H
#define FNV_NISMARTPOINTER_H

#include "nismartpointer_decls.h"

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    ~NiPointer()
    {
        T* object = m_pObject;
        if (object)
        {
            if (InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)) == 0)
                object->DeleteThis();
        }
    }
    NiPointer<T>& operator=(T* object)
    {
        T* previous = m_pObject;
        if (previous != object)
        {
            if (previous)
                NiPointerRefOps<T>::Dec(previous);
            m_pObject = object;
            if (object)
                NiPointerRefOps<T>::Inc(object);
        }
        return *this;
    }
    NiPointer<T>& operator=(const NiPointer<T>& other)
    {
        T* object = other.m_pObject;
        if (m_pObject != object)
        {
            if (m_pObject)
                NiPointerRefOps<T>::Dec(m_pObject);
            m_pObject = object;
            if (m_pObject)
                NiPointerRefOps<T>::Inc(m_pObject);
        }
        return *this;
    }
};

template <> class NiPointer<KFModel>
{
  public:
    KFModel* m_pObject;
    NiPointer<KFModel>& operator=(KFModel* object);
};

// @fnv 0x0044b070
NiPointer<KFModel>& NiPointer<KFModel>::operator=(KFModel* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            m_pObject->FUN_0044b050();
        m_pObject = object;
        if (m_pObject)
            m_pObject->FUN_0044b010();
    }
    return *this;
}

template <> class NiPointer<LoadedFile>
{
  public:
    LoadedFile* m_pObject;
    NiPointer<LoadedFile>& operator=(LoadedFile* object);
};

// @fnv 0x0044b220
NiPointer<LoadedFile>& NiPointer<LoadedFile>::operator=(LoadedFile* object)
{
    if (m_pObject != object)
    {
        if (m_pObject)
            m_pObject->FUN_0044b180();
        m_pObject = object;
        if (m_pObject)
            m_pObject->FUN_0044b0f0();
    }
    return *this;
}

template <> class NiPointer<WaitableObject>
{
  public:
    WaitableObject* m_pObject;
    NiPointer<WaitableObject>& operator=(const NiPointer<WaitableObject>& other);
};

// @fnv 0x006e5cc0
NiPointer<WaitableObject>& NiPointer<WaitableObject>::operator=(const NiPointer<WaitableObject>& other)
{
    if (m_pObject != other.m_pObject)
    {
        if (m_pObject)
            m_pObject->FUN_00401970();
        m_pObject = other.m_pObject;
        if (m_pObject)
            m_pObject->FUN_0040f6e0();
    }
    return *this;
}

class MemoryManager;
extern MemoryManager g_memoryManager;
// @fnv 0x00401020
MemoryManager* FUN_00401020()
{
    return &g_memoryManager;
}

// @fnv 0x0042f4c0
NavMeshPtr& NavMeshPtr::operator=(const NavMeshPtr& other)
{
    return FUN_0042fdc0(other);
}

// @fnv 0x006d1bc0
void PathingRequest::SetDestination(PathingLocation* value)
{
    destination = *value;
}

// @fnv 0x006d61e0
void PathingRequest::SetAvoidNodeArray(BSSimpleArray<void*, 1024>* value)
{
    avoid.Assign(reinterpret_cast<PathingAvoidNodeArray*>(value));
}

template <> class NiPointer<NiD3DPixelShader>
{
  public:
    NiD3DPixelShader* m_pObject;
    ~NiPointer();
};
#pragma optimize("gty", on)
// @fnv 0x00b66f20
NiPointer<NiD3DPixelShader>::~NiPointer()
{
    NiD3DPixelShader* object = m_pObject;
    if (object && InterlockedDecrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount)) == 0)
        object->DeleteThis();
}
#pragma optimize("", off)

// @fnv 0x004483e0
KFModel* KFModelLookup::Lookup(const char* key)
{
    KFModel* result = 0;
    if (table->Lookup(key, result))
        return result;
    return 0;
}

template <> class NiPointer<NiGPUProgram>
{
  public:
    NiGPUProgram* m_pObject;
    NiPointer& operator=(NiGPUProgram*);
};
#pragma optimize("gty", on)
// @fnv 0x00a5f860
NiPointer<NiGPUProgram>& NiPointer<NiGPUProgram>::operator=(NiGPUProgram* object)
{
    NiGPUProgram* previous = m_pObject;
    if (previous != object)
    {
        if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        m_pObject = object;
        if (object)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount));
    }
    return *this;
}
#pragma optimize("", off)

#pragma optimize("gty", on)
// @fnv 0x00a67260
void NiGPUProgramOwner::SetProgram(NiGPUProgram* object)
{
    NiGPUProgram* previous = program;
    if (previous != object)
    {
        if (previous && InterlockedDecrement(reinterpret_cast<volatile long*>(&previous->m_uiRefCount)) == 0)
            previous->DeleteThis();
        program = object;
        if (object)
            InterlockedIncrement(reinterpret_cast<volatile long*>(&object->m_uiRefCount));
    }
}
#pragma optimize("", off)

// @fnv 0x008df900
ActorPathingMessageQueue::ActorPathingMessageQueue() : BSTCommonLLMessageQueue<QueuedMessage>(&g_011d77f0)
{}

#endif
