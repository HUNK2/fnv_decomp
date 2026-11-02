
// src/havok/physics/dynamics/world/util/hkpworldconstraintutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/world/util/hkpworldconstraintutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00d27820_Node;
struct S_00d27820_Buf
{
    char* data;
    int size;
};
struct S_00d27820_Rec
{
    S_00d27820_Node* link[3];
    int unk0c, unk10;
    unsigned short px, py, pz;
    unsigned char idx;
    int cnt;
    unsigned short sz;
    unsigned short slot;
    int unk24, unk28, unk2c;
};
struct S_00d27820_Arr
{
    struct S_00d27820_Node** data;
    int count;
};
struct S_00d27820_Node
{
    int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    S_00d27820_Rec* unk30;
    int unk34, unk38, unk3c, unk40, unk44, unk48, unk4c;
    int unk50, unk54, unk58, unk5c, unk60, unk64, unk68, unk6c;
    int unk70, unk74, unk78, unk7c, unk80, unk84, unk88, unk8c;
    int unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    S_00d27820_Rec* unkac;
    unsigned short unkb0;
    unsigned short unkb2;
    S_00d27820_Arr arr;
    int unkbc;
    S_00d27820_Buf buf;
};
struct S_00d27820_Vec
{
    int unk00, x, y, z;
    S_00d27820_Vec& Sub(unsigned a, unsigned b, unsigned c)
    {
        x -= a;
        y -= b;
        z -= c;
        return *this;
    }
};
struct S_00d27820_A
{
    int unk00, unk04;
    S_00d27820_Vec vec;
    int unk18;
    int cnt;
    int unk20;
    unsigned char unk24;
    unsigned char flags;
};
struct S_00d27820_P
{
    int unk00, unk04;
    S_00d27820_A* unk08;
    int unk0c, unk10, unk14, unk18, unk1c;
    int unk20, unk24, unk28, unk2c;
    S_00d27820_Rec* unk30;
    void FUN_00c905b0();
};
void __cdecl FUN_00cb1270(int a, int b, char* c);

// Removes the record p->unk30 from its node lists, shifts the following records down, adjusts buffer sizes and counts, and calls FUN_00c905b0.
// @fnv 0x00d27820
void DetachRecord(S_00d27820_P* p)
{
    S_00d27820_Rec* pRec = p->unk30;
    S_00d27820_A* a = p->unk08;
    a->flags = (a->flags & ~2) | 1;
    unsigned x = pRec->px;
    unsigned y = pRec->py;
    unsigned z = pRec->pz;
    if (p->unk30)
    {
        S_00d27820_A* a2 = p->unk08;
        a2->vec.Sub(x, y, z);
        S_00d27820_Rec* pRec2 = p->unk30;
        pRec2->py -= y;
        pRec2->pz -= z;
        pRec2->px -= x;
    }
    a->cnt--;
    p->unk08 = 0;
    S_00d27820_Node* c = pRec->link[2 - pRec->idx];
    unsigned short slot = pRec->slot;
    S_00d27820_Arr* arr = &c->arr;
    S_00d27820_Node** data = arr->data;
    S_00d27820_Node* pLastNode = data[arr->count - 1];
    data[slot] = pLastNode;
    arr->count--;
    pLastNode->unk30->slot = slot;
    S_00d27820_Node* d = pRec->link[pRec->idx + 1];
    int delta = 0;
    if (pRec->cnt)
    {
        delta = -(int)pRec->sz;
        int iTotal = pRec->sz + pRec->cnt;
        S_00d27820_Buf* pBuf = &d->buf;
        FUN_00cb1270(pRec->cnt, iTotal, pBuf->data + (pBuf->size - iTotal));
        pBuf->size -= pRec->sz;
        pRec->cnt = 0;
    }
    p->unk30 = 0;
    S_00d27820_Rec* pIter = pRec;
    S_00d27820_Rec* end = d->unkac + d->unkb0 - 1;
    while (pIter < end)
    {
        *pIter = pIter[1];
        pIter->link[0]->unk30 = pIter;
        pIter->cnt = pIter->cnt ? pIter->cnt + delta : 0;
        pIter++;
    }
    d->unkb0--;
    p->FUN_00c905b0();
}

typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;

struct hkpConstraintAtom
{
    hkUint16 m_type;
    hkUint16 unk02;
    int unk04;
    int unk08;
    int unk0C;
};

struct GenericConstraintAtomScheme
{
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;

    void clear()
    {
        m_iMaxSchemaSize = 0;
        m_iSchemaByteSize = 0;
        m_iSolverResultCount = 0;
        m_iSolverElementTemporaryCount = 0;
    }
};

struct hkpConstraintDataInfo : GenericConstraintAtomScheme
{
    hkpConstraintAtom* m_kBridgeAtoms;
    int m_usSizeOfAllAtoms;
};

struct hkpModifierConstraintAtom : hkpConstraintAtom
{
    hkUint16 m_usModifierAtomSize;
    hkUint16 m_iChildSize;
    hkpConstraintAtom* m_pChildAtom;

    int FUN_00d22090(GenericConstraintAtomScheme& infoOut, hkUint8& usedFlagsOut);
};

struct hkpConstraintData
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v0A();
    virtual void v0B();
    virtual void v0C();
    virtual void v0D();
    virtual void v0E();
    virtual void PopulateInfo(hkpConstraintDataInfo& infoOut) const;
};

struct hkpEntity
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    hkUint16 unkD0;
    hkUint8 m_ucResponseModifierFlags;
};

struct ConstraintRuntimeInfo
{
    int unk00;
    int unk04;
    int unk08;
    hkpConstraintAtom* m_kBridgeAtoms;
    hkUint16 m_iAtomsSize;
    hkUint8 m_ucCallbackRequest;
    hkUint8 unk13;
    hkUint16 m_iSchemaByteSize;
};

struct hkpConstraintInstance;

struct hkpConstraintOwner
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void checkAccessRw();

    int unk04;
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;

    void AccumulateStats(hkpConstraintInstance* constraint, GenericConstraintAtomScheme& delta);
};

struct hkpConstraintInstance
{
    int unk00;
    int unk04;
    int unk08;
    hkpConstraintData* m_data;
    hkpModifierConstraintAtom* m_pConstraintModifier;
    hkpEntity* m_pEntityA;
    hkpEntity* m_pEntityB;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    ConstraintRuntimeInfo* m_pConstraintInternal;
};

extern const hkUint16 DAT_010cb7a8[];

hkpModifierConstraintAtom* __cdecl FUN_00d277f0(hkpConstraintInstance* instance);

// Splices newModifier into the modifier atom chain of instance, updating child pointers and accumulating solver stats on the owner.
// @fnv 0x00d27960
void __cdecl FUN_00d27960(hkpConstraintInstance* instance, hkpConstraintOwner& constraintOwner,
                          hkpModifierConstraintAtom* newModifier)
{
    constraintOwner.checkAccessRw();

    hkpModifierConstraintAtom* lastModifier = FUN_00d277f0(instance);
    ConstraintRuntimeInfo* pConstraintInternal = instance->m_pConstraintInternal;

    if (newModifier->m_type == 0x1a && lastModifier)
    {
        newModifier->m_pChildAtom = lastModifier->m_pChildAtom;
        newModifier->m_iChildSize = lastModifier->m_iChildSize;
        lastModifier->m_pChildAtom = newModifier;
        lastModifier->m_iChildSize = newModifier->m_usModifierAtomSize;
    }
    else if (instance->m_pConstraintModifier && instance->m_pConstraintModifier->m_type == 0x1b)
    {
        newModifier->m_pChildAtom = instance->m_pConstraintModifier->m_pChildAtom;
        newModifier->m_iChildSize = instance->m_pConstraintModifier->m_iChildSize;
        instance->m_pConstraintModifier->m_pChildAtom = newModifier;
        instance->m_pConstraintModifier->m_iChildSize = newModifier->m_usModifierAtomSize;
    }
    else
    {
        instance->m_pConstraintModifier = newModifier;
        if (pConstraintInternal)
        {
            newModifier->m_pChildAtom = pConstraintInternal->m_kBridgeAtoms;
            newModifier->m_iChildSize = pConstraintInternal->m_iAtomsSize;
            pConstraintInternal->m_kBridgeAtoms = newModifier;
            pConstraintInternal->m_iAtomsSize = newModifier->m_usModifierAtomSize;
        }
        else
        {
            hkpConstraintDataInfo info;
            instance->m_data->PopulateInfo(info);
            newModifier->m_pChildAtom = info.m_kBridgeAtoms;
            newModifier->m_iChildSize = (hkUint16)info.m_usSizeOfAllAtoms;
        }
    }

    if (pConstraintInternal)
    {
        GenericConstraintAtomScheme info;
        info.clear();
        hkUint8 usedFlags = 0;
        int callbackRequest = newModifier->FUN_00d22090(info, usedFlags);
        constraintOwner.AccumulateStats(instance, info);

        usedFlags &=
            (instance->m_pEntityA->m_ucResponseModifierFlags | instance->m_pEntityB->m_ucResponseModifierFlags);
        hkUint16 extra = DAT_010cb7a8[usedFlags & 7];
        constraintOwner.m_iSchemaByteSize -= extra;
        instance->m_pConstraintInternal->m_iSchemaByteSize = instance->m_pConstraintInternal->m_iSchemaByteSize - extra;
        if (instance->m_pConstraintInternal)
        {
            instance->m_pConstraintInternal->m_ucCallbackRequest |= (hkUint8)callbackRequest;
        }
    }
}

namespace fnv_00d27ac0 {
struct Entity;
struct Constraint;
struct Atom
{
    unsigned short type;
    unsigned short unk02;
    unsigned int unk04, unk08, unk0c;
    unsigned short size;
};
struct ConstraintInfo
{
    unsigned int unk00;
    unsigned int runtimeBytes;
    unsigned int unk08, unk0c;
    Atom* atoms;
    unsigned short atomSize;
};
struct RuntimeInfo
{
    unsigned int size;
    unsigned int unk04;
};
struct ConstraintData
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1c();
    virtual void slot20();
    virtual void GetRuntimeInfo(unsigned int, RuntimeInfo*);
    virtual void slot28();
    virtual void AddInstance(Constraint*, void*, unsigned int);
    virtual void slot30();
    virtual unsigned char* WantsRuntime(unsigned char*);
    virtual void slot38();
    virtual void GetConstraintInfo(ConstraintInfo*);
};
struct __declspec(align(16)) ConstraintInternal
{
    Constraint* constraint;
    Entity* bodies[2];
    Atom* atoms;
    unsigned short atomSize;
    unsigned char flags;
    unsigned char priority;
    unsigned short unk14, unk16, unk18;
    unsigned char masterIndex;
    unsigned char callbacks;
    char* runtime;
    unsigned short runtimeSize;
    unsigned short slaveIndex;
    unsigned int unk24, unk28, unk2c;
};
struct InternalArray
{
    ConstraintInternal* data;
    unsigned short size;
    unsigned short capacity;
    void FUN_00d27f50(int, ConstraintInternal*);
};
struct ConstraintPointer
{
    Constraint* value;
    __forceinline void Set(Constraint* x)
    {
        value = x;
    }
};
struct ConstraintArray
{
    ConstraintPointer* data;
    int size;
    unsigned int capacity;
};
struct ByteArray
{
    char* data;
    unsigned int size;
    unsigned int capacity;
};
struct Island
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, count;
    void AccumulateStats(Constraint*, ConstraintInfo*);
};
struct Entity
{
    unsigned int unk00;
    unsigned int unk04;
    void* world;
    unsigned int unk0c;
    unsigned int unk10;
    unsigned int unk14;
    unsigned int unk18;
    unsigned int unk1c;
    unsigned int unk20;
    unsigned int unk24;
    unsigned int unk28;
    unsigned int unk2c;
    unsigned int unk30;
    unsigned int unk34;
    unsigned int unk38;
    unsigned int unk3c;
    unsigned int unk40;
    unsigned int unk44;
    unsigned int unk48;
    unsigned int unk4c;
    unsigned int unk50;
    unsigned int unk54;
    unsigned int unk58;
    unsigned int unk5c;
    unsigned int unk60;
    unsigned int unk64;
    unsigned int unk68;
    unsigned int unk6c;
    unsigned int unk70;
    unsigned int unk74;
    unsigned int unk78;
    unsigned int unk7c;
    unsigned int unk80;
    unsigned int unk84;
    unsigned int unk88;
    unsigned int unk8c;
    unsigned int unk90;
    unsigned int unk94;
    unsigned int unk98;
    unsigned int unk9c;
    unsigned int unka0;
    unsigned int unka4;
    unsigned int unka8;
    InternalArray constraints;
    ConstraintArray slaves;
    ByteArray runtime;
    Island* island;
    unsigned short unkD0;
    unsigned char responseFlags;
    unsigned char unkD3;
    unsigned int uid;
    unsigned int unkD8, unkDC, unkE0, unkE4;
    unsigned char motionType;
};
struct Constraint
{
    virtual void slot00();
    virtual void slot04();
    virtual void slot08();
    virtual void slot0c();
    virtual void slot10();
    virtual void slot14();
    virtual void* GetInternal();
    unsigned int unk04;
    Island* island;
    ConstraintData* data;
    Atom* atoms;
    Entity* bodies[2];
    unsigned char priority;
    unsigned char wantRuntime;
    unsigned short unk1e;
    unsigned int unk20, unk24, unk28, unk2c;
    ConstraintInternal* internal;
    unsigned int uid;
    void FUN_00c90510();
};
void FUN_00cb5570(void*, Entity*, Entity*);
unsigned char FUN_00d22120(Atom*, ConstraintInfo*, unsigned char*);
extern unsigned short DAT_010cb7a8[];
struct MemoryRouter
{
    unsigned int unk00, unk04, unk08, unk0c;
    void* heap;
};
MemoryRouter* FUN_00c85750();
void FUN_00c908c0(void*, ByteArray*, int, int);
void ResizeAudioStream(void*, ConstraintArray*, int);
void FUN_00cb1270(void*, const void*, int);
// Initializes a ConstraintInternal entry, inserts it into the master entity's constraint array, allocates runtime memory, and registers the constraint as a slave.
// @fnv 0x00d27ac0
ConstraintPointer* FUN_00d27ac0(void* unused, Constraint* constraint)
{
    constraint->FUN_00c90510();
    ConstraintInfo info;
    constraint->data->GetConstraintInfo(&info);
    ConstraintInternal entry;
    entry.constraint = constraint;
    entry.bodies[0] = constraint->bodies[0];
    entry.bodies[1] = constraint->bodies[1];
    if (constraint->atoms)
    {
        entry.atoms = constraint->atoms;
        entry.atomSize = constraint->atoms->size;
    }
    else
    {
        entry.atoms = info.atoms;
        entry.atomSize = info.atomSize;
    }
    entry.priority = constraint->priority;
    if (entry.bodies[0]->motionType != 5 && entry.bodies[1]->motionType != 5 &&
        entry.bodies[0]->island != entry.bodies[1]->island)
        FUN_00cb5570(entry.bodies[0]->world, entry.bodies[0], entry.bodies[1]);
    entry.masterIndex = entry.bodies[0]->motionType == 5;
    Entity* master = entry.bodies[entry.masterIndex];
    constraint->island = master->island;
    ++constraint->island->count;
    unsigned int atomType = entry.atoms->type;
    entry.callbacks = 1;
    entry.flags = 0;
    if (atomType == 1)
    {
        entry.flags = 2;
        unsigned char result;
        if (*constraint->data->WantsRuntime(&result))
            entry.flags |= 4;
        entry.callbacks = constraint->GetInternal() == 0;
    }
    else if (atomType == 20)
        entry.flags = 2;
    unsigned char flags = 0;
    if (constraint->atoms)
        entry.flags |= FUN_00d22120(constraint->atoms, &info, &flags);
    if (atomType == 22)
    {
        unsigned char combined = constraint->bodies[1]->responseFlags | constraint->bodies[0]->responseFlags;
        combined -= combined & flags;
        info.runtimeBytes += DAT_010cb7a8[combined & 7];
    }
    entry.unk16 = 0;
    entry.unk18 = 0;
    entry.unk14 = 0;
    constraint->internal = &entry;
    constraint->island->AccumulateStats(constraint, &info);
    InternalArray& array = master->constraints;
    unsigned short count = array.size;
    int index = 0;
    for (; index < (int)count; ++index)
    {
        ConstraintInternal& current = array.data[index];
        if (entry.priority < current.priority)
            break;
        if (entry.priority > current.priority)
            continue;
        unsigned int incomingUid = entry.constraint->uid;
        unsigned int currentUid = current.constraint->uid;
        if (incomingUid < currentUid)
            break;
        if (incomingUid > currentUid)
            continue;
        Entity* other =
            (Entity*)((unsigned int)current.bodies[0] ^ (unsigned int)current.bodies[1] ^ (unsigned int)master);
        Entity* incoming =
            (Entity*)((unsigned int)entry.bodies[0] ^ (unsigned int)entry.bodies[1] ^ (unsigned int)master);
        if (incoming->uid < other->uid)
            break;
    }
    int firstChanged = count < (array.capacity & 0x3fff) ? index : 0;
    array.FUN_00d27f50(index, &entry);
    for (int i = firstChanged; i < (int)array.size; ++i)
    {
        ConstraintInternal* changed = &array.data[i];
        Constraint* owner = changed->constraint;
        owner->internal = changed;
    }
    ConstraintInternal* internal = constraint->internal;
    RuntimeInfo runtimeInfo;
    internal->constraint->data->GetRuntimeInfo(constraint->wantRuntime, &runtimeInfo);
    unsigned int runtimeSize = (runtimeInfo.size + 15) & ~15u;
    runtimeInfo.size = runtimeSize;
    internal->runtimeSize = (unsigned short)runtimeSize;
    if (runtimeSize)
    {
        ByteArray& storage = master->runtime;
        int oldSize = storage.size;
        char* oldData = storage.data;
        int newSize = oldSize + runtimeSize;
        MemoryRouter* router = FUN_00c85750();
        if ((int)(storage.capacity & 0x3fffffff) < newSize)
            FUN_00c908c0(router->heap, &storage, newSize, 1);
        storage.size = oldSize + runtimeInfo.size;
        char* position = storage.data;
        int displacement = storage.data - oldData;
        int i = 0;
        for (; i < index; ++i)
        {
            ConstraintInternal& current = array.data[i];
            if (current.runtime)
            {
                current.runtime += displacement;
                position = current.runtime + current.runtimeSize;
            }
        }
        int tailSize = (int)storage.size - (int)(position + internal->runtimeSize - master->runtime.data);
        FUN_00cb1270(position + internal->runtimeSize, position, tailSize);
        displacement += internal->runtimeSize;
        internal->runtime = position;
        for (++i; i < (int)array.size; ++i)
        {
            ConstraintInternal& current = array.data[i];
            char* oldRuntime = current.runtime;
            current.runtime = oldRuntime ? oldRuntime + displacement : 0;
        }
    }
    else
        internal->runtime = 0;
    ConstraintData* instanceData = internal->constraint->data;
    instanceData->AddInstance(constraint, internal->runtime, internal->runtimeSize);
    Entity* slave = internal->bodies[1 - internal->masterIndex];
    internal->slaveIndex = (unsigned short)slave->slaves.size;
    ConstraintArray& slaves = slave->slaves;
    MemoryRouter* router = FUN_00c85750();
    if (slaves.size == (int)(slaves.capacity & 0x3fffffff))
        ResizeAudioStream(router->heap, &slaves, 4);
    ConstraintPointer* insertion = slaves.data + slaves.size;
    insertion->value = constraint;
    ++slaves.size;
    return insertion;
}
}  // namespace fnv_00d27ac0
