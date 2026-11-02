
// src/havok/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/dynamics/constraint/setup/hkpconstraintsolversetup.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct State
{
    int unk00;
    void* owner;
    int unk08;
    int eventCode;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    void* resetA;
    int unk24;
    void* desiredA;
    void* currentA;
    void* resetB;
    int unk34;
    void* desiredB;
    void* currentB;
    int callbackFlags;
    int unk44;
    volatile float* end;
    volatile float* current;
};
void __cdecl FUN_00d8aac0(void* owner, void* current, int eventCode, int flags);
// Optionally resets currentA/currentB to their reset values, zeroes the float range up to end, and notifies callbacks when current differs from desired.
// @fnv 0x00d88340
void __cdecl FUN_00d88340(State* state, int reset)
{
    if (reset == 0)
    {
        state->currentA = state->resetA;
        state->currentB = state->resetB;
    }
    volatile float* p = state->current;
    while (p < state->end)
    {
        *p = 0.0f;
        ++p;
    }
    state->current = state->end;
    if (state->currentA != state->desiredA)
        FUN_00d8aac0(state->owner, state->currentA, state->eventCode, state->callbackFlags);
    if (state->currentB != state->desiredB)
        FUN_00d8aac0(state->owner, state->currentB, state->eventCode, state->callbackFlags);
    state->currentA = state->desiredA;
    state->currentB = state->desiredB;
}

struct D88310Bool
{
    char m_cBooleanValue;

    D88310Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
};

struct D88310Stream
{
    int unk00;
    int unk04;
    int unk08;
    char* m_kRayStart;
    char* m_kRayEnd;
    char* m_pTileTemplate;
};

// @fnv 0x00d88310
D88310Bool __cdecl FUN_00d88310(const D88310Stream* stream, const void* unused, int numBlocks)
{
    int available = (int)(stream->m_kRayEnd - stream->m_pTileTemplate);
    if (stream->m_pTileTemplate == stream->m_kRayStart)
        numBlocks++;
    if (numBlocks * 128 > available - 16)
        return false;
    return true;
}

// @fnv 0x00d88300
void __cdecl FUN_00d88300()
{}

struct D88470Sub
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    unsigned short amountA;
    unsigned short unk16;
    unsigned short amountB;
    unsigned short unk1a;
};

struct D88470Elem
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    unsigned char type;
    unsigned char unk1d;
    unsigned char unk1e;
    unsigned char unk1f;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    D88470Sub* sub;
};

struct D88470Obj
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    unsigned int limitA;
    unsigned int initA;
    int unk2c;
    int unk30;
    unsigned int limitB;
    unsigned int initB;
    int unk3c;
    int unk40;
    unsigned int limitSum;
    unsigned int initSum;
};

// Accumulates amountA per element type and amountB*4 into totals, then returns true if the sums stay within obj's limitSum, limitA and limitB.
// @fnv 0x00d88470
D88310Bool __cdecl CheckTotalsWithinLimits(D88470Obj* obj, D88470Elem** begin, int count)
{
    unsigned int totals[2];
    totals[0] = obj->initA;
    totals[1] = obj->initB;
    unsigned int sum = obj->initSum;
    unsigned int uiSum1 = 0;
    unsigned int uiSum2 = 0;
    D88470Elem** end = begin + count;
    int iCount = ((char*)end - (char*)begin + 3) / 4;
    D88470Elem** p = begin;
    if (iCount >= 2)
    {
        do
        {
            D88470Elem* pElem = p[0];
            unsigned int uiTypeIndex = pElem->type >= 5 ? 1 : 0;
            D88470Sub* s = pElem->sub;
            uiSum1 += s->amountB * 4;
            totals[uiTypeIndex] += s->amountA;
            pElem = p[1];
            uiTypeIndex = pElem->type >= 5 ? 1 : 0;
            s = pElem->sub;
            uiSum2 += s->amountB * 4;
            totals[uiTypeIndex] += s->amountA;
            p += 2;
        } while ((int)p < (int)(end - 1));
    }
    if (p < end)
    {
        D88470Elem* pElem = *p;
        unsigned int uiTypeIndex = pElem->type >= 5 ? 1 : 0;
        D88470Sub* s = pElem->sub;
        sum += s->amountB * 4;
        totals[uiTypeIndex] += s->amountA;
    }
    sum += uiSum1 + uiSum2;
    if (sum <= obj->limitSum && totals[0] + 4 <= obj->limitA && totals[1] + 4 <= obj->limitB)
        return true;
    else
        return false;
}

union __declspec(intrin_type) __declspec(align(16)) __m128
{
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};

extern "C" __m128 _mm_setzero_ps();

struct hkVector4D886
{
    __m128 m_vComponents;

    hkVector4D886()
    {}
    hkVector4D886(const hkVector4D886& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void operator=(const hkVector4D886& v)
    {
        m_vComponents = v.m_vComponents;
    }
    void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
};

struct hkpVelocityAccumulatorD886
{
    unsigned char m_type;
    unsigned char m_iValueAtOffset0C;
    unsigned char unk02, unk03;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    unsigned int unk0C;
    hkVector4D886 m_vLinearVelocity;
    hkVector4D886 m_vAngularVelocity;
    hkVector4D886 m_vInverseInertiaAndMass;
    hkVector4D886 m_vCenterOfMass;
    hkVector4D886 m_scratch1;
    hkVector4D886 m_scratch2;
    hkVector4D886 m_scratch3;

    void setFixed()
    {
        m_fGravityFactor = 0.0f;
        m_type = 1;
        m_vInverseInertiaAndMass.setZero4();
        m_vLinearVelocity.setZero4();
        m_vAngularVelocity.setZero4();
        m_vCenterOfMass.setZero4();
        m_scratch1.setZero4();
        m_scratch2.setZero4();
        m_scratch3.setZero4();
    }
};

struct hkpSolverSumVelocitiesD886
{
    hkVector4D886 m_vLinearVelocity;
    hkVector4D886 m_vAngularVelocity;
};

struct hkStepInfoD886;

struct hkpEntityD886
{
    unsigned int unk00[41];
    unsigned int m_uiFilterInfo;
};

struct hkpConstraintSolverResourcesD886
{
    const hkStepInfoD886* m_pStepInfo;
    unsigned int unk04, unk08;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorA;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorB;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorC;
    hkpSolverSumVelocitiesD886* m_sumVelocities;
};

hkpVelocityAccumulatorD886* __cdecl FUN_00d29830(const hkStepInfoD886* pkInfo, hkpEntityD886* const* ppkEntities,
                                                 unsigned int uiNumEntities, int iMotionOffset,
                                                 hkpVelocityAccumulatorD886* pkAccumulatorsOut);

// @fnv 0x00d88670
void __cdecl FUN_00d88670(hkpConstraintSolverResourcesD886& kResources, hkpEntityD886* const* ppkEntities,
                          unsigned int uiNumEntities)
{
    if (!uiNumEntities)
    {
        return;
    }

    if (kResources.m_pVelocityAccumulatorC == kResources.m_pVelocityAccumulatorA)
    {
        hkpVelocityAccumulatorD886* pkFixed = kResources.m_pVelocityAccumulatorC;
        pkFixed->setFixed();
        kResources.m_pVelocityAccumulatorC = pkFixed + 1;
        hkpSolverSumVelocitiesD886* pkFixedSumVel = kResources.m_sumVelocities;
        pkFixedSumVel->m_vAngularVelocity.setZero4();
        pkFixedSumVel->m_vLinearVelocity.setZero4();
    }

    for (unsigned int i = 0; i < uiNumEntities; i++)
    {
        ppkEntities[i]->m_uiFilterInfo = reinterpret_cast<unsigned int>(kResources.m_pVelocityAccumulatorC + i) -
                                         reinterpret_cast<unsigned int>(kResources.m_pVelocityAccumulatorA);
    }

    hkpVelocityAccumulatorD886* pkAccumulator = kResources.m_pVelocityAccumulatorC;
    hkpSolverSumVelocitiesD886* pkSumVel =
        kResources.m_sumVelocities + ppkEntities[0]->m_uiFilterInfo / sizeof(hkpVelocityAccumulatorD886);
    kResources.m_pVelocityAccumulatorC =
        FUN_00d29830(kResources.m_pStepInfo, ppkEntities, uiNumEntities, 0xe0, pkAccumulator);

    for (unsigned int i = 0; i < uiNumEntities; i++)
    {
        pkSumVel->m_vLinearVelocity = pkAccumulator->m_vCenterOfMass;
        pkSumVel->m_vAngularVelocity = pkAccumulator->m_scratch1;
        pkAccumulator->m_vCenterOfMass.setZero4();
        pkAccumulator->m_scratch1.setZero4();
        pkAccumulator++;
        pkSumVel++;
    }

    kResources.m_pVelocityAccumulatorC->m_type = 3;
}

struct S88_Allocator;

struct S88_Router
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S88_Allocator* m_pStreamAllocator;
    S88_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
};

S88_Router* __cdecl FUN_00c85750();
void __cdecl ResizeAudioStream(S88_Allocator& a, void* array, int sizeElem);

template <typename T> struct S88_PadSpu
{
    T m_kStorage;
    void operator=(T v)
    {
        m_kStorage = v;
    }
    operator T() const
    {
        return m_kStorage;
    }
    T val() const
    {
        return m_kStorage;
    }
};

struct S88_Transform
{
    hkVector4D886 c0, c1, c2, t;
};

struct S88_MotionState
{
    S88_Transform m_kMotionTransform;
    const S88_Transform& getTransform() const
    {
        return m_kMotionTransform;
    }
};

struct S88_Motion
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S88_MotionState m_kMotionState;
    const S88_MotionState* GetMotionState() const
    {
        return &m_kMotionState;
    }
};

struct S88_Collidable
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
    float m_fAllowedPenetrationDepth;
};

struct S88_Entity
{
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    S88_Collidable m_kCollidable;
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
    unsigned int m_uiFilterInfo;
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
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    S88_Motion m_pMotionState;
    S88_Motion* getMotion()
    {
        return &m_pMotionState;
    }
    const S88_Collidable* getCollidable() const
    {
        return &m_kCollidable;
    }
};

struct S88_Atom
{
    short m_type;
};

struct S88_QueryIn;

struct S88_ConstraintData
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual int getType() const;
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void BuildJacobianCallback(const S88_QueryIn& in);
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    S88_Atom* m_pAtom;
};

struct S88_Internal
{
    int unk00;
    S88_Entity* m_kActorEntries[2];
    S88_Atom* m_kBridgeAtoms;
    unsigned short m_iAtomsSize;
    unsigned char m_ucCallbackRequest;
    unsigned char unk13;
    int unk14;
    unsigned short m_iSolverElementTemporaryCount;
    short unk1A;
    void* m_pRuntime;
    S88_Atom* getAtoms() const
    {
        return m_kBridgeAtoms;
    }
    unsigned short getAtomsSize() const
    {
        return m_iAtomsSize;
    }
};

struct S88_Instance
{
    int unk00;
    int unk04;
    int unk08;
    S88_ConstraintData* m_data;
    int unk10;
    int unk14;
    int unk18;
    unsigned char m_priority;
    unsigned char unk1D;
    unsigned char unk1E;
    unsigned char unk1F;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    S88_Internal* m_pConstraintInternal;
    int getPriority() const
    {
        return m_priority;
    }
    S88_Internal* getInternal()
    {
        return m_pConstraintInternal;
    }
    const S88_ConstraintData* getData() const
    {
        return m_data;
    }
    S88_ConstraintData* getDataRw() const
    {
        return m_data;
    }
    void* getRuntime() const
    {
        return m_pConstraintInternal->m_pRuntime;
    }
};

struct S88_QueryIn
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
    S88_PadSpu<const hkpVelocityAccumulatorD886*> m_pBodyA;
    S88_PadSpu<const hkpVelocityAccumulatorD886*> m_pBodyB;
    S88_PadSpu<const S88_Transform*> m_kBodyALocalFrame;
    S88_PadSpu<const S88_Transform*> m_kBodyBLocalFrame;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    S88_PadSpu<S88_Instance*> m_pConstraintChainInstance;
    S88_PadSpu<void*> m_pByteBuffer;
    int unk68;
    S88_PadSpu<unsigned int> m_uiParameterA;
    S88_PadSpu<unsigned int> m_uiParameterB;
    S88_PadSpu<void*> m_pUserData;
};

struct S88_Schema;

struct S88_QueryOut
{
    S88_PadSpu<S88_Schema*> m_pQueryResultSchema;
};

struct S88_BufferState
{
    S88_Schema* m_pRayStart;
    S88_Schema* m_kRayEnd;
    S88_Schema* m_pTileTemplate;
    S88_Schema* m_pValues;
};

struct S88_Backup
{
    hkVector4D886 m_kTranslationalVelocity;
    hkVector4D886 m_kAngularVelocity;
};

struct S88_Resources
{
    void* m_pStepInfo;
    void* m_pSolverInfo;
    S88_QueryIn* m_pConstraintQueryIn;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorA;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorB;
    hkpVelocityAccumulatorD886* m_pVelocityAccumulatorC;
    S88_Backup* m_pBodyABackup;
    S88_Backup* m_pBodyBBackup;
    S88_BufferState m_akBufferStates[2];
    char* m_pBufferA;
    char* m_pBufferB;
    char* m_pBufferC;
    char* m_pBufferD;
};

struct S88_SchemaInfo
{
    S88_Instance* m_pHavokConstraint;
    S88_Schema* m_pConstraintSchema;
    float m_fAllowedPenetrationDepth;
};

struct S88_Array
{
    S88_SchemaInfo* m_data;
    int m_iElementCount;
    int m_iCapacityState;
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    S88_SchemaInfo& AllocatePair()
    {
        S88_Allocator& alloc = FUN_00c85750()->heap();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(alloc, this, sizeof(S88_SchemaInfo));
        }
        return m_data[m_iElementCount++];
    }
};

template <typename T> inline T* S88_addByteOffset(T* base, long offset)
{
    return reinterpret_cast<T*>(reinterpret_cast<char*>(base) + offset);
}

template <typename T> inline T S88_min2(T x, T y)
{
    return x < y ? x : y;
}

void __cdecl FUN_00d92900(S88_ConstraintData* data, const S88_QueryIn* in, S88_Atom* atom, int type);
void __cdecl FUN_00d72190(S88_Atom* atom, const S88_QueryIn& in, D88310Bool writeHeader, S88_QueryOut& out);
void __cdecl FUN_00d6f460(const S88_Atom* atoms, int atomsSize, const S88_QueryIn& in, S88_QueryOut& out);

inline void S88_buildJacobianFromAtoms(S88_Atom* atoms, int atomsSize, const S88_QueryIn& in, S88_QueryOut& out)
{
    if (atoms->m_type == 0x16)
    {
        FUN_00d72190(atoms, in, D88310Bool(true), out);
    }
    else
    {
        FUN_00d6f460(atoms, atomsSize, in, out);
    }
}

// @fnv 0x00d88760
void __cdecl FUN_00d88760(S88_Resources& s, S88_Instance** constraints, int numConstraints, S88_Array& constraintStatus)
{
    S88_QueryIn& in = *s.m_pConstraintQueryIn;
    S88_QueryOut out;

    for (S88_Instance **cp = constraints, **end = constraints + numConstraints; cp < end; cp++)
    {
        S88_Instance* instance = *cp;
        int prio = (instance->getPriority() == 5);
        S88_Entity** entities = &instance->getInternal()->m_kActorEntries[0];
        S88_Motion* motionA = entities[0]->getMotion();
        S88_Motion* motionB = entities[1]->getMotion();

        hkpVelocityAccumulatorD886* pAccumulatorA =
            S88_addByteOffset(s.m_pVelocityAccumulatorA, entities[0]->m_uiFilterInfo);
        hkpVelocityAccumulatorD886* pAccumulatorB =
            S88_addByteOffset(s.m_pVelocityAccumulatorA, entities[1]->m_uiFilterInfo);
        in.m_pBodyA = pAccumulatorA;
        in.m_pBodyB = pAccumulatorB;

        S88_Backup* backupA = &s.m_pBodyABackup[entities[0]->m_uiFilterInfo >> 7];
        S88_Backup* backupB = &s.m_pBodyABackup[entities[1]->m_uiFilterInfo >> 7];
        pAccumulatorA->m_vCenterOfMass = backupA->m_kTranslationalVelocity;
        pAccumulatorA->m_scratch1 = backupA->m_kAngularVelocity;
        pAccumulatorB->m_vCenterOfMass = backupB->m_kTranslationalVelocity;
        pAccumulatorB->m_scratch1 = backupB->m_kAngularVelocity;

        const S88_MotionState* pMotionStateA = motionA->GetMotionState();
        const S88_MotionState* pMotionStateB = motionB->GetMotionState();
        in.m_kBodyALocalFrame = &pMotionStateA->getTransform();
        in.m_kBodyBLocalFrame = &pMotionStateB->getTransform();
        in.m_pConstraintChainInstance = instance;
        in.m_pByteBuffer = instance->getRuntime();
        in.m_uiParameterA = (unsigned short)(entities[0]->m_uiFilterInfo >> 7);
        in.m_uiParameterB = (unsigned short)(entities[1]->m_uiFilterInfo >> 7);
        in.m_pUserData = instance->getRuntime();

        S88_SchemaInfo& info = constraintStatus.AllocatePair();
        info.m_pHavokConstraint = instance;
        info.m_pConstraintSchema = s.m_akBufferStates[prio].m_pTileTemplate;
        info.m_fAllowedPenetrationDepth = S88_min2(entities[0]->getCollidable()->m_fAllowedPenetrationDepth,
                                                   entities[1]->getCollidable()->m_fAllowedPenetrationDepth);

        out.m_pQueryResultSchema = s.m_akBufferStates[prio].m_pTileTemplate;

        if (instance->getData()->getType() == 11)
        {
            S88_ConstraintData* data = instance->getDataRw();
            FUN_00d92900(data, &in, data->m_pAtom, 1);
        }

        if (instance->m_pConstraintInternal->m_ucCallbackRequest & 4)
        {
            instance->getDataRw()->BuildJacobianCallback(in);
        }

        S88_buildJacobianFromAtoms(instance->m_pConstraintInternal->getAtoms(),
                                   instance->m_pConstraintInternal->getAtomsSize(), in, out);

        s.m_akBufferStates[prio].m_pTileTemplate = out.m_pQueryResultSchema;
        s.m_pBufferC += instance->m_pConstraintInternal->m_iSolverElementTemporaryCount * 4;

        pAccumulatorA->m_vCenterOfMass.setZero4();
        pAccumulatorA->m_scratch1.setZero4();
        pAccumulatorB->m_vCenterOfMass.setZero4();
        pAccumulatorB->m_scratch1.setZero4();
    }

    *(int*)s.m_akBufferStates[0].m_pTileTemplate = 0;
    *(int*)s.m_akBufferStates[1].m_pTileTemplate = 0;
}

struct S883_Vector4
{
    __m128 m_vComponents;
    __forceinline void setZero4()
    {
        m_vComponents = _mm_setzero_ps();
    }
    __forceinline void operator=(const S883_Vector4& v)
    {
        m_vComponents = v.m_vComponents;
    }
};

struct S883_Matrix3
{
    S883_Vector4 m_kColumn0;
    S883_Vector4 m_kColumn1;
    S883_Vector4 m_kColumn2;
    __forceinline S883_Vector4& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    __forceinline void setZero()
    {
        S883_Vector4 zero;
        zero.setZero4();
        getColumn(0) = zero;
        getColumn(1) = zero;
        getColumn(2) = zero;
    }
};

struct S883_Accumulator
{
    unsigned char m_type;
    unsigned char m_iValueAtOffset0C;
    unsigned char unk02;
    unsigned char unk03;
    unsigned int m_uiDeactivationClass;
    float m_fGravityFactor;
    unsigned int unk0c;
    S883_Vector4 m_vLinearVelocity;
    S883_Vector4 m_vAngularVelocity;
    S883_Vector4 m_vInverseInertiaAndMass;
    S883_Vector4 m_vCenterOfMass;
    S883_Matrix3 m_kCoreFromWorldMatrix;

    __forceinline S883_Vector4& getCenterOfMassInWorld()
    {
        return m_vCenterOfMass;
    }
    __forceinline S883_Matrix3& getCoreFromWorldMatrix()
    {
        return m_kCoreFromWorldMatrix;
    }
    __forceinline void setFixed()
    {
        m_type = 1;
        m_fGravityFactor = 0.0f;
        m_vInverseInertiaAndMass.setZero4();
        m_vLinearVelocity.setZero4();
        m_vAngularVelocity.setZero4();
        getCenterOfMassInWorld().setZero4();
        getCoreFromWorldMatrix().setZero();
    }
};

struct S883_EntityArray
{
    void** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    __forceinline int GetLogicalSize() const
    {
        return m_iElementCount;
    }
};

struct S883_Island
{
    void* m_ppVirtualMethodTable;
    int unk04;
    int unk08;
    int m_iSchemaByteSize;
    int unk10;
    int m_iSolverElementTemporaryCount;
    int unk18;
    int m_maxConstraintInfoSize;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    S883_EntityArray m_kActorEntries;
    __forceinline const S883_EntityArray& GetEntities() const
    {
        return m_kActorEntries;
    }
};

struct S883_TaskHeader
{
    int m_iJobId;
    int m_iValueAt04;
    int m_iValueAt08;
    long m_sReferenceCount;
    int m_iValueAt10;
    void* m_buffer;
    int m_iBufferSize;
    int m_iValueAt1C;
    char m_cValueAt20;
    char m_bSplitCheckRequested;
    void* m_pPointerAt24;
    int unk28;
    int unk2c;
    S883_Accumulator* m_pAccumulatorA;
    void* m_pVelocityAccumulatorB;
    short m_usValueAt38;
    short m_usValueAt3A;
    void* m_pByteArrayAt3C;
    void* m_pIntegerArrayAt40;
};

// Lays out accumulator, schema and solver-element-temporary regions in buffer, sets taskHeader pointers and sizes, and initialises the first accumulator as fixed.
// @fnv 0x00d883c0
int __cdecl FUN_00d883c0(const S883_Island& island, char* buffer, int bufferSize, S883_TaskHeader& taskHeader)
{
    taskHeader.m_buffer = buffer;
    int numEntities = island.GetEntities().GetLogicalSize();
    taskHeader.m_pAccumulatorA = reinterpret_cast<S883_Accumulator*>(buffer);
    int sizeForAccumulators = island.GetEntities().GetLogicalSize() * sizeof(S883_Accumulator) + 0x90;
    buffer += sizeForAccumulators;

    int numBlocks = 0;
    {
        int blockSize = 0x90;
        numBlocks = island.m_maxConstraintInfoSize / blockSize + 1;
        numBlocks += 3;
        numBlocks *= 2;
    }

    taskHeader.m_pByteArrayAt3C = buffer;
    int sizeForSchemas = island.m_iSchemaByteSize + 16;
    sizeForSchemas += numBlocks << 4;
    buffer += sizeForSchemas;

    int sizeForElemTemp = island.m_iSolverElementTemporaryCount * 4 + 8;
    sizeForElemTemp += numBlocks * 12;
    sizeForElemTemp = (sizeForElemTemp + 15) & ~15;
    taskHeader.m_pIntegerArrayAt40 = buffer;
    buffer += sizeForElemTemp;

    int size = (int)(buffer - (char*)taskHeader.m_buffer);
    taskHeader.m_iBufferSize = size;

    if (taskHeader.m_buffer)
    {
        S883_Accumulator* accum = taskHeader.m_pAccumulatorA;
        accum->setFixed();
        accum[numEntities + 1].m_type = 3;
    }
    return size;
}

extern "C" void _mm_prefetch(char const*, int);
extern "C" __declspec(dllimport) void* __stdcall TlsGetValue(unsigned long);
extern unsigned long DAT_0126835c;
extern const char str_010d3d70[];
extern const char str_010d3d60[];

// hkMemoryAllocator
struct S88b50_Allocator
{
    virtual void v00();
    virtual void* AllocateMemoryBlock(int numBytes);
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void* AllocateBufferWithSize(int& reqNumBytesInOut);
    virtual void ReturnMemory(void* p, int numBytes);
    template <typename T> T* _bufAlloc(int& reqNumInOut)
    {
        int n = reqNumInOut;
        void* p = AllocateBufferWithSize(n);
        reqNumInOut = n;
        return static_cast<T*>(p);
    }
    template <typename T> void _bufFree(void* p, int numElem)
    {
        ReturnMemory(p, numElem);
    }
};
struct S88b50_Stack
{
    char* m_pTileTemplate;
    int unk04;
    int unk08;
    void* allocateStack(int numBytes)
    {
        char* current = m_pTileTemplate;
        m_pTileTemplate = current + numBytes;
        return current;
    }
};
struct S88b50_Router
{
    S88b50_Stack m_aiEntries;
    S88b50_Allocator* m_pTemp;
    S88b50_Allocator* m_pStreamAllocator;
    S88b50_Allocator* m_pDebugAllocator;
    S88b50_Allocator* m_pSolver;
    S88b50_Stack& stack()
    {
        return m_aiEntries;
    }
    S88b50_Allocator& temp()
    {
        return *m_pTemp;
    }
    S88b50_Allocator& heap()
    {
        return *m_pStreamAllocator;
    }
    S88b50_Allocator& solver()
    {
        return *m_pSolver;
    }
    static S88b50_Router& GetMonitorStream()
    {
        return *(S88b50_Router*)FUN_00c85750();
    }
};
static __forceinline char* S88b50_allocateStack(int n)
{
    S88b50_Router& mem = S88b50_Router::GetMonitorStream();
    return static_cast<char*>(mem.stack().allocateStack((n + 127) & ~127));
}

struct S88b50_ConstraintInternal
{
    S88_Instance* m_pHavokConstraint;
    struct S88b50_Entity* m_kActorEntries[2];
    S88_Atom* m_kBridgeAtoms;
    unsigned short m_iAtomsSize;
    unsigned char m_ucCallbackRequest;
    unsigned char m_priority;
    int unk14;
    int unk18;
    void* m_pRuntime;
    int unk20;
    int unk24;
    int unk28;
    int unk2c;
    S88_Atom* getAtoms() const
    {
        return m_kBridgeAtoms;
    }
    unsigned short getAtomsSize() const
    {
        return m_iAtomsSize;
    }
    int getPriority() const
    {
        return m_priority;
    }
};
struct S88b50_SmallArray
{
    S88b50_ConstraintInternal* m_data;
    unsigned short m_iElementCount;
    unsigned short m_iCapacityState;
    const S88b50_ConstraintInternal* begin() const
    {
        return m_data;
    }
    const S88b50_ConstraintInternal* end() const
    {
        return m_data + m_iElementCount;
    }
};
// hkpEntity
struct S88b50_PtrArray
{
    void* m_data;
    int m_iElementCount;
    int m_iCapacityState;
};
// hkpWorld
struct S88b50_World
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    void* m_pSimulation;
    int unk0C;
    hkVector4D886 m_kGravity;
    void* m_pFixedIsland;
    void* m_pFixedRigidBody;
    S88b50_PtrArray m_kActiveSimulationIslands;
    S88b50_PtrArray m_kInactiveSimulationIslands;
    S88b50_PtrArray m_kDirtySimulationIslands;
    void* m_pMaintenanceManager;
    void* m_pMemoryWatchDog;
    char m_bAssertOnRunningOutOfSolverMemory;
    void* m_pJobSemaphore;
    void* m_pKdTreeManager;
    char m_bUseKdTree;
    void* m_pBroadPhaseDispatcher;
    void* m_pPhantomBroadPhaseListener;
    void* m_pEntityEntityBroadPhaseListener;
    void* m_pBroadPhaseBorderListener;
    void* m_pMultithreadedSimulationJobData;
    void* m_pCollisionInput;
    void* getCollisionInput() const
    {
        return m_pCollisionInput;
    }
};
// hkpCdBody
struct S88b50_CdBody
{
    const void* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const void* m_pMotionState;
    const S88b50_CdBody* m_parent;
    const S88_Transform& getTransform() const
    {
        return *(const S88_Transform*)m_pMotionState;
    }
};
// hkpLinkedCollidable
struct S88b50_Collidable : S88b50_CdBody
{
    signed char m_iOwnerOffset;
    unsigned char m_uiForceCollideOntoPpu;
    unsigned short m_uiShapeSizeOnSpu;
    unsigned int m_broadPhaseId;
    signed char m_cBroadPhaseType;
    signed char m_broadPhaseOwnerOffset;
    signed char m_ucObjectQualityType;
    unsigned int m_uiCollisionFilterData;
    unsigned int m_bvMin0;
    unsigned int m_bvMin1;
    unsigned int m_bvMin2;
    unsigned int m_bvExpansionMinAndShift;
    unsigned int m_bvMax0;
    unsigned int m_bvMax1;
    unsigned int m_bvMax2;
    unsigned int m_bvExpansionMaxAndPadding;
    unsigned short m_bvNumChildShapeAabbs;
    unsigned short m_bvCapacityChildShapeAabbs;
    void* m_bvChildShapeAabbs;
    void* m_bvChildShapeKeys;
    float m_fAllowedPenetrationDepth;
    S88b50_PtrArray m_kCollisionEntries;
};
// hkpEntity
struct S88b50_Entity
{
    void* m_ppVirtualMethodTable;
    unsigned short m_usMemSizeAndFlags;
    short m_sReferenceCount;
    S88b50_World* m_pOwningWorld;
    unsigned int m_ulUserData;
    S88b50_Collidable m_kCollidable;
    unsigned int m_mtThreadId;
    unsigned short m_mtMarkCount;
    unsigned short m_mtMarkBitStack;
    const char* m_name;
    S88b50_PtrArray m_kProperties;
    void* m_kNextStreamField;
    void* m_pWorldObjectOwner;
    signed char m_materialResponseType;
    float m_materialFriction;
    float m_materialRestitution;
    void* m_pEntityUserData;
    float m_fBulletSpread;
    void* m_pShape;
    unsigned int m_uiFilterInfo;
    unsigned short m_usStorageIndex;
    unsigned short m_usNextProcessCallbackDelay;
    S88b50_SmallArray m_eSmallArraySerializeOverrideType;
    S88b50_PtrArray m_kSlaveConstraints;
    S88b50_PtrArray m_pByteBuffer;
    void* m_pSimulationIsland;
    signed char m_iAutoRemoveLevel;
    unsigned char m_ucNumShapeKeysInContactPointProperties;
    unsigned char m_ucResponseModifierFlags;
    unsigned int m_uiUniqueId;
    void* m_spuCallbackUtil;
    unsigned short m_spuCallbackCapacity;
    unsigned char m_spuCallbackEventFilter;
    unsigned char m_spuCallbackUserFilter;
    S88_Motion m_pMotionState;
    S88_Motion* getMotion()
    {
        return &m_pMotionState;
    }
    const S88b50_SmallArray& getConstraintMasters() const
    {
        return m_eSmallArraySerializeOverrideType;
    }
    S88b50_World* getWorld() const
    {
        return m_pOwningWorld;
    }
    const S88b50_Collidable* getCollidable() const
    {
        return &m_kCollidable;
    }
};
static __forceinline S88b50_Entity* S88b50_getEntityA(const S88_Instance* i)
{
    return (S88b50_Entity*)i->unk14;
}
static __forceinline S88b50_Entity* S88b50_getEntityB(const S88_Instance* i)
{
    return (S88b50_Entity*)i->unk18;
}

// hkpSimulationIsland
struct S88b50_Island
{
    int unk00;
    int unk04;
    int m_iMaxSchemaSize;
    int m_iSchemaByteSize;
    int m_iSolverResultCount;
    int m_iSolverElementTemporaryCount;
    void* m_pOwningWorld;
};
struct S88b50_InplaceArray
{
    const S88b50_ConstraintInternal** m_data;
    int m_iElementCount;
    int m_iCapacityState;
    const S88b50_ConstraintInternal* m_kStorage[256];
    void init()
    {
        m_data = m_kStorage;
        m_iElementCount = 0;
        m_iCapacityState = 256 | 0x80000000;
    }
    int getCapacity() const
    {
        return m_iCapacityState & 0x3fffffff;
    }
    int GetLogicalSize() const
    {
        return m_iElementCount;
    }
    const S88b50_ConstraintInternal*& operator[](int i)
    {
        return m_data[i];
    }
    void AddBack(const S88b50_ConstraintInternal* const& t)
    {
        S88b50_Allocator& alloc = S88b50_Router::GetMonitorStream().heap();
        if (m_iElementCount == getCapacity())
        {
            ResizeAudioStream(*(S88_Allocator*)&alloc, this, sizeof(t));
        }
        m_data[m_iElementCount] = t;
        m_iElementCount++;
    }
    void destroy()
    {
        S88b50_Allocator& alloc = S88b50_Router::GetMonitorStream().heap();
        m_iElementCount = 0;
        if ((m_iCapacityState & 0x80000000) == 0)
        {
            alloc._bufFree<const S88b50_ConstraintInternal*>(m_data, getCapacity() * 4);
        }
    }
};

struct S88b50_GotoSchema
{
    float m_kHeader;
    long m_offset;
    static void setType(S88b50_GotoSchema* schema, signed char type)
    {
        schema->m_kHeader = (float)(schema->m_kHeader + 1.1920928955078125e-07);
        *(signed char*)S88_addByteOffset(schema, 0) = type;
    }
    void initGoto(S88_Schema* destination)
    {
        m_offset = (char*)destination - (char*)this;
        setType(this, 2);
    }
};

struct S88b50_MonitorStream
{
    int unk00;
    char* m_kRayEnd;
    int unk08;
    char* m_pCurrentCommand;
    static S88b50_MonitorStream& GetMonitorStream()
    {
        return *(S88b50_MonitorStream*)TlsGetValue(DAT_0126835c);
    }
    bool memoryAvailable() const
    {
        return m_kRayEnd < m_pCurrentCommand;
    }
    char* GetStreamEnd()
    {
        return m_kRayEnd;
    }
    void setEnd(char* e)
    {
        m_kRayEnd = e;
    }
};
struct S88b50_AddValueCommand
{
    const char* m_pCommandName;
    float m_uiFilterValue;
};

struct S88b50_BreachedHeader
{
    int m_iBreachCount;
    int unk04;
    int unk08;
    int unk0C;
    void* getElem(int index)
    {
        return (char*)this + 16 + index * 32;
    }
};

template <typename T> inline T S88b50_max2(T x, T y)
{
    return x > y ? x : y;
}

int __cdecl FUN_00d8d030(const void* solverInfo, char* schemas, hkpVelocityAccumulatorD886* accum, char* elemTemps);
void __cdecl FUN_00df0680(const void* solverInfo, char* elemTemps, char* schemas, hkpVelocityAccumulatorD886* accum);
int __cdecl FUN_00d29bf0(const void* solverInfo, const hkStepInfoD886* stepInfo,
                         const hkpVelocityAccumulatorD886* accums, S88b50_Entity* const* bodies, int numBodies,
                         int offset);
void __cdecl FUN_00d1a330(const void* input, S88b50_Entity* const* bodies, int numBodies);
void __cdecl FUN_00d01700(void* world, void* elems, int n);

// hkMatrix3
struct S88b50_Matrix3
{
    hkVector4D886 m_kColumn0;
    hkVector4D886 m_kColumn1;
    hkVector4D886 m_kColumn2;
    hkVector4D886& getColumn(int i)
    {
        return (&m_kColumn0)[i];
    }
    void setZero()
    {
        hkVector4D886 zero;
        zero.setZero4();
        getColumn(0) = zero;
        getColumn(1) = zero;
        getColumn(2) = zero;
    }
};
static __forceinline void S88b50_setFixed(hkpVelocityAccumulatorD886& a)
{
    a.m_type = 1;
    a.m_fGravityFactor = 0.0f;
    a.m_vInverseInertiaAndMass.setZero4();
    a.m_vLinearVelocity.setZero4();
    a.m_vAngularVelocity.setZero4();
    a.m_vCenterOfMass.setZero4();
    reinterpret_cast<S88b50_Matrix3&>(a.m_scratch1).setZero();
}

static __forceinline void S88b50_buildAccumulators(const hkStepInfoD886& info, S88b50_Entity* const* bodies,
                                                   int numBodies, hkpVelocityAccumulatorD886* accumulators)
{
    S88b50_setFixed(*accumulators);
    for (int i = 0; i < numBodies; i++)
    {
        unsigned int newVal = (i + 1) * 128;
        if (newVal != bodies[i]->m_uiFilterInfo)
        {
            bodies[i]->m_uiFilterInfo = newVal;
        }
    }
    hkpVelocityAccumulatorD886* accumEnd =
        FUN_00d29830(&info, (hkpEntityD886* const*)bodies, numBodies, 0xe0, accumulators + 1);
    accumEnd->m_type = 3;
}

template <int SIZE> inline void S88b50_forcePrefetch(const void* p)
{
    const char* q = (const char*)p;
    _mm_prefetch(q, 0);
    if (SIZE > 64)
    {
        _mm_prefetch(q + 64, 0);
    }
    if (SIZE > 128)
    {
        _mm_prefetch(q + 128, 0);
    }
    if (SIZE > 192)
    {
        _mm_prefetch(q + 192, 0);
    }
}

static __forceinline void S88b50_buildJacobianElement(const S88b50_ConstraintInternal* c, S88_QueryIn& in,
                                                      hkpVelocityAccumulatorD886* accusIn, S88_QueryOut& out)
{
    S88b50_forcePrefetch<256>(c->getAtoms());
    if (c->getAtomsSize() > 256)
    {
        S88b50_forcePrefetch<256>(S88_addByteOffset(c->getAtoms(), 256));
        if (c->getAtomsSize() > 512)
        {
            S88b50_forcePrefetch<256>(S88_addByteOffset(c->getAtoms(), 512));
        }
    }
    S88b50_Entity* rA = c->m_kActorEntries[0];
    S88b50_Entity* rB = c->m_kActorEntries[1];
    S88_Motion* mA = rA->getMotion();
    S88_Motion* mB = rB->getMotion();
    in.m_pBodyA = S88_addByteOffset(accusIn, rA->m_uiFilterInfo);
    in.m_pBodyB = S88_addByteOffset(accusIn, rB->m_uiFilterInfo);
    in.m_kBodyALocalFrame = &mA->GetMotionState()->getTransform();
    in.m_kBodyBLocalFrame = &mB->GetMotionState()->getTransform();
    in.m_pConstraintChainInstance = c->m_pHavokConstraint;
    in.m_pByteBuffer = c->m_pRuntime;
    in.m_uiParameterA = (unsigned short)(rA->m_uiFilterInfo >> 7);
    in.m_uiParameterB = (unsigned short)(rB->m_uiFilterInfo >> 7);
    in.m_pUserData = in.m_pByteBuffer;
    S88_buildJacobianFromAtoms(c->getAtoms(), c->getAtomsSize(), in, out);
}

static __forceinline void S88b50_buildJacobianElements(S88_QueryIn& in, S88b50_Entity* const* bodies, int numBodies,
                                                       hkpVelocityAccumulatorD886* accusIn, S88_Schema* schemaOut,
                                                       S88_Schema* schemaOutEnd, S88_Schema* schemaOutB)
{
    S88_QueryOut out;
    out.m_pQueryResultSchema = schemaOut;
    S88b50_Entity* const* e = bodies;
    S88b50_Entity* const* eEnd = bodies + numBodies;
    S88b50_InplaceArray criticalConstraints;
    criticalConstraints.init();
    for (; e < eEnd; e++)
    {
        const S88b50_ConstraintInternal* c = (*e)->getConstraintMasters().begin();
        const S88b50_ConstraintInternal* cEnd = (*e)->getConstraintMasters().end();
        for (; c < cEnd; c++)
        {
            if (c->m_ucCallbackRequest & 0xd)
            {
                in.m_pConstraintChainInstance = c->m_pHavokConstraint;
                in.m_pByteBuffer = c->m_pRuntime;
                S88b50_Entity* rA = S88b50_getEntityA(c->m_pHavokConstraint);
                S88b50_Entity* rB = S88b50_getEntityB(c->m_pHavokConstraint);
                in.m_pBodyA = S88_addByteOffset(accusIn, rA->m_uiFilterInfo);
                in.m_pBodyB = S88_addByteOffset(accusIn, rB->m_uiFilterInfo);
                in.m_kBodyALocalFrame = &rA->getCollidable()->getTransform();
                in.m_kBodyBLocalFrame = &rB->getCollidable()->getTransform();
                if (c->m_ucCallbackRequest & 9)
                {
                    S88_ConstraintData* data = c->m_pHavokConstraint->getDataRw();
                    S88_Atom* atom = data->m_pAtom;
                    FUN_00d92900(data, &in, atom, 2);
                }
                if (c->m_ucCallbackRequest & 4)
                {
                    S88_ConstraintData* data = c->m_pHavokConstraint->getDataRw();
                    data->BuildJacobianCallback(in);
                }
            }
            if (c->getPriority() >= 4)
            {
                criticalConstraints.AddBack(c);
                continue;
            }
            if (out.m_pQueryResultSchema >= schemaOutEnd)
            {
                S88b50_GotoSchema* s = (S88b50_GotoSchema*)out.m_pQueryResultSchema.val();
                s->initGoto(schemaOutB);
                out.m_pQueryResultSchema = schemaOutB;
                schemaOutEnd = (S88_Schema*)-1;
            }
            S88b50_buildJacobianElement(c, in, accusIn, out);
        }
    }
    for (int i = 0; i < criticalConstraints.GetLogicalSize(); i++)
    {
        const S88b50_ConstraintInternal* c = criticalConstraints[i];
        if (out.m_pQueryResultSchema >= schemaOutEnd)
        {
            S88b50_GotoSchema* s = (S88b50_GotoSchema*)out.m_pQueryResultSchema.val();
            s->initGoto(schemaOutB);
            out.m_pQueryResultSchema = schemaOutB;
            schemaOutEnd = (S88_Schema*)-1;
        }
        S88b50_buildJacobianElement(c, in, accusIn, out);
    }
    *(int*)out.m_pQueryResultSchema.val() = 0;
    criticalConstraints.destroy();
}

static __forceinline int S88b50_integrate2(const void* solverInfo, const hkStepInfoD886& stepInfo,
                                           const hkpVelocityAccumulatorD886* accumulators, S88b50_Entity* const* bodies,
                                           int numBodies)
{
    int numInactiveFrames = FUN_00d29bf0(solverInfo, &stepInfo, accumulators + 1, bodies, numBodies, 0xe0);
    FUN_00d1a330(bodies[0]->getWorld()->getCollisionInput(), bodies, numBodies);
    return numInactiveFrames;
}

// Allocates solver buffers, builds velocity accumulators and Jacobian schemas, solves the constraint system, and integrates the island bodies.
// @fnv 0x00d88b50
int __cdecl FUN_00d88b50(const hkStepInfoD886& stepInfo, const void* solverInfo, S88_QueryIn& constraintQueryIn,
                         S88b50_Island& island, void* preallocatedBuffer, int preallocatedBufferSize,
                         S88b50_Entity* const* bodies, int numBodies)
{
    int result = 0;
    char* scratch2 = 0;
    int scratch2Size = 0;

    int accumulatorSize = numBodies * 128 + 0x90;
    int schemaSize = island.m_iSchemaByteSize + 16;
    int elemTempSize = island.m_iSolverElementTemporaryCount * 4 + 8;
    elemTempSize = (elemTempSize + 15) & ~15;
    char* schemasB = 0;

    int totalSize = accumulatorSize + schemaSize + elemTempSize;
    char* scratch;
    char* buffer;
    char* bufferEnd;
    if (preallocatedBuffer == 0)
    {
        scratch = S88b50_Router::GetMonitorStream().solver()._bufAlloc<char>(totalSize);
        buffer = scratch;
        bufferEnd = buffer + totalSize;
    }
    else
    {
        scratch = 0;
        buffer = (char*)preallocatedBuffer;
        bufferEnd = buffer + preallocatedBufferSize;
    }

    hkpVelocityAccumulatorD886* accumulators;
    char* schemas;
    char* schemasEnd;
    char* elemTemp;
redoAll:
    accumulators = (hkpVelocityAccumulatorD886*)buffer;
    buffer += accumulatorSize;
    schemas = buffer;
    buffer += schemaSize;
    schemasEnd = buffer;
redoElemTemp:
    elemTemp = buffer;
    buffer += elemTempSize;
    if (buffer <= bufferEnd)
    {
        S88b50_buildAccumulators(stepInfo, bodies, numBodies, accumulators);
        for (int i = 0; i < island.m_iSolverElementTemporaryCount; i++)
        {
            ((float*)elemTemp)[i] = 0.0f;
        }
        S88b50_buildJacobianElements(constraintQueryIn, bodies, numBodies, accumulators, (S88_Schema*)schemas,
                                     (S88_Schema*)schemasEnd, (S88_Schema*)schemasB);

        int solveResult = FUN_00d8d030(solverInfo, schemas, accumulators, elemTemp);
        {
            S88b50_MonitorStream& mStream = S88b50_MonitorStream::GetMonitorStream();
            if (mStream.memoryAvailable())
            {
                S88b50_AddValueCommand* h = (S88b50_AddValueCommand*)mStream.GetStreamEnd();
                h->m_pCommandName = str_010d3d70;
                h->m_uiFilterValue = (float)island.m_iSolverResultCount;
                mStream.setEnd((char*)(h + 1));
            }
        }
        {
            S88b50_MonitorStream& mStream = S88b50_MonitorStream::GetMonitorStream();
            if (mStream.memoryAvailable())
            {
                S88b50_AddValueCommand* h = (S88b50_AddValueCommand*)mStream.GetStreamEnd();
                h->m_pCommandName = str_010d3d60;
                h->m_uiFilterValue = (float)numBodies;
                mStream.setEnd((char*)(h + 1));
            }
        }
        if (solveResult == 1)
        {
            FUN_00df0680(solverInfo, elemTemp, schemas, accumulators);
            result = S88b50_integrate2(solverInfo, stepInfo, accumulators, bodies, numBodies);
            S88b50_BreachedHeader* h = (S88b50_BreachedHeader*)schemas;
            if (h->m_iBreachCount != 0)
            {
                FUN_00d01700(island.m_pOwningWorld, h->getElem(0), h->m_iBreachCount);
            }
        }
        if (scratch2 != 0)
        {
            S88b50_Router::GetMonitorStream().temp().ReleaseBlock(scratch2, scratch2Size);
        }
        if (scratch != 0)
        {
            S88b50_Router::GetMonitorStream().solver()._bufFree<char>(scratch, totalSize);
        }
        return result;
    }
    else
    {
        if (schemas >= bufferEnd)
        {
            scratch2Size = (int)(buffer - scratch);
            scratch2 = (char*)S88b50_Router::GetMonitorStream().temp().AllocateMemoryBlock(scratch2Size);
            buffer = scratch2;
            bufferEnd = buffer + scratch2Size;
            goto redoAll;
        }
        int minSchemaSize = island.m_iMaxSchemaSize + 16;
        if (schemasEnd >= bufferEnd)
        {
            int freeSchemaSpace = (int)(bufferEnd - schemas - minSchemaSize);
            int maxFree = S88b50_max2(freeSchemaSpace, 0);
            int schemaBSize = island.m_iSchemaByteSize + minSchemaSize - maxFree;
            scratch2Size = elemTempSize + schemaBSize;
            scratch2 = (char*)S88b50_Router::GetMonitorStream().temp().AllocateMemoryBlock(scratch2Size);
            if (freeSchemaSpace < 0)
            {
                buffer = scratch2;
                bufferEnd = buffer + scratch2Size;
                schemas = buffer;
                buffer = buffer + island.m_iSchemaByteSize + 16;
                schemasEnd = buffer;
                schemasB = 0;
            }
            else
            {
                schemasEnd = bufferEnd - minSchemaSize;
                buffer = scratch2;
                bufferEnd = buffer + scratch2Size;
                schemasB = buffer;
                buffer += schemaBSize;
            }
        }
        else
        {
            int size = elemTempSize;
            scratch2 = S88b50_allocateStack(size);
            buffer = scratch2;
            bufferEnd = buffer + size;
        }
        goto redoElemTemp;
    }
}
