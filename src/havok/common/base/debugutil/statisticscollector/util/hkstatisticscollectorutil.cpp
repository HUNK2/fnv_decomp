
// src/havok/common/base/debugutil/statisticscollector/util/hkstatisticscollectorutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/common/base/debugutil/statisticscollector/util/hkstatisticscollectorutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" int __cdecl FUN_00cb10d0(const char* s);

class Hasher
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual int Hash(const char* s, int len);
};

struct Audio
{
    char pad[0x10];
    Hasher* hasher;
    Hasher& GetHasher()
    {
        return *hasher;
    }
};

extern "C" Audio* __cdecl FUN_00c85750();

class Handler
{
  public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void Emit(int kind, int a, const char* s, int len, int hash);
};

// If s is non-null, computes its length plus one, hashes it via the audio hasher, and emits it through h with kind 1 and *a.
// @fnv 0x00cf5fe0
extern "C" void __cdecl EmitStringWithHash(int* pValue, const char* pString, Handler* pHandler)
{
    if (pString)
    {
        int len = FUN_00cb10d0(pString) + 1;
        int hash = FUN_00c85750()->GetHasher().Hash(pString, len);
        pHandler->Emit(1, *pValue, pString, len, hash);
    }
}

struct Format
{
    bool* GetLastNodeFlag(unsigned int*);
};
struct Destination
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void WriteDirect(void*, unsigned int, int);
    virtual void WriteFormatted(Format*, void*, unsigned int, int);
};
// @fnv 0x00cf6030
void __cdecl WriteToDestination(void* data, unsigned int size, Format* format, Destination* destination)
{
    unsigned int originalSize = size;
    if (originalSize)
    {
        if (*format->GetLastNodeFlag(&size))
            destination->WriteDirect(data, originalSize, 0);
        else
            destination->WriteFormatted(format, data, originalSize, 0);
    }
}

namespace fnv_00cf6080 {
struct S_00cf6080_Allocator
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1C();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void* vfn_2C(void* p, int numBytes);
};
struct S_00cf6080_Router
{
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    S_00cf6080_Allocator* unk10;
    S_00cf6080_Allocator* heap()
    {
        return unk10;
    }
};
S_00cf6080_Router* FUN_00c85750();

struct S_00cf6080_Listener
{
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0C();
    virtual void vfn_10();
    virtual void vfn_14(int type, int a, void* p, int numBytes, void* result);
};

// @fnv 0x00cf6080
void FUN_00cf6080(int a, void* p, int aiOldCount, int newCount, int elemSize, S_00cf6080_Listener* listener)
{
    void* result = FUN_00c85750()->heap()->vfn_2C(p, newCount * elemSize);
    listener->vfn_14(3, a, p, aiOldCount * elemSize, result);
}
}  // namespace fnv_00cf6080

struct Target
{
    int FUN_00d470d0();
};

struct TypeInfo
{
    unsigned char m_ucKind;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int unk04;
    short m_sValue;
};

TypeInfo* __cdecl FUN_00d868a0(int aiType);

struct Thing
{
    int unk00;
    int unk04;
    int unk08;
    unsigned char unk0c;
    unsigned char m_ucType;

    Target* FUN_00d86910();
};

// Reads the type from apThing, looks up its TypeInfo, and returns m_sValue if positive, else the result of FUN_00d470d0 for kind 0x19, otherwise -1.
// @fnv 0x00cf61c0
int __cdecl GetThingValue(Thing* apThing)
{
    unsigned char ucType = apThing->m_ucType;
    if (ucType == 0)
        return -1;

    TypeInfo* pInfo = FUN_00d868a0(ucType);
    short sValue = pInfo->m_sValue;
    if (sValue > 0)
        return sValue;

    if (pInfo->m_ucKind == 0x19)
        return apThing->FUN_00d86910()->FUN_00d470d0();

    return -1;
}

struct hkBool
{
    char m_cBooleanValue;
    hkBool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct Shape;

struct Container
{
    __declspec(nothrow) int FUN_00d46f70() const;
    __declspec(nothrow) const Shape* FUN_00d46f80(int i) const;
};

__declspec(nothrow) hkBool __cdecl GetFlagByState(const Shape* s);

// Calls FUN_00d46f70 for a count, then GetFlagByState on each shape from FUN_00d46f80, returning false on the first failure and true otherwise.
// @fnv 0x00cf6330
hkBool __cdecl FUN_00cf6330(const Container* apContainer)
{
    int n = apContainer->FUN_00d46f70();
    for (int i = 0; i < n; i++)
    {
        if (!GetFlagByState(apContainer->FUN_00d46f80(i)))
            return false;
    }
    return true;
}

// FUN_00cf60d0 - 69 bytes at 0x00cf60d0
//
// The function forwards to one of two virtual slots of its last argument,
// choosing between them on the flag byte that the walker writes through the
// pointer it is handed.  The walker returns the very pointer it was given, so
// the test reads the byte through the returned pointer.

struct FNV_C60d0_Walker
{
    void* unk00;
    void* unk04;
    void* unk08;
    void* unk0c;
    bool* GetLastNodeFlag(bool* outFlag);
};

struct FNV_C60d0_Sink
{
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(void* a0, void* a1, int flag);
    virtual void v4(void* a0, void* a1, void* a2, int flag);
};

// @fnv 0x00cf60d0
extern "C" void __cdecl FUN_00cf60d0(void* pA0, void* pA1, FNV_C60d0_Walker* pWalker, FNV_C60d0_Sink* pSink)
{
    void* p = pA1;
    if (p)
    {
        bool flag;
        bool* pf = pWalker->GetLastNodeFlag(&flag);
        if (*pf)
        {
            pSink->v3(pA0, p, 1);
        }
        else
        {
            pSink->v4(pWalker, pA0, p, 1);
        }
    }
}

void* __cdecl FUN_00cf60d0(void* context, const void* a, const void* b, const void* c);

// @fnv 0x00cf6120
void* __cdecl CallWithNullContext(const void* a, const void* b, const void* c)
{
    return FUN_00cf60d0(0, a, b, c);
}

struct SpawnedObject
{
    int CalleeA(int aiArg);
};

void __cdecl CalleeB_00cf60d0(int aiA, int aiB, int aiC, int aiD);

// Calls CalleeA on the object at aiSecond with aiFirst; if it returns nonzero, passes 0, aiFirst, the result and aiSecond to CalleeB_00cf60d0.
// @fnv 0x00cf6140
void __cdecl CallObjectMethodAndDispatch(int aiFirst, int aiSecond)
{
    SpawnedObject* pObj = (SpawnedObject*)aiSecond;
    int result = pObj->CalleeA(aiFirst);
    if (result != 0)
    {
        CalleeB_00cf60d0(0, aiFirst, result, aiSecond);
    }
}

struct FUN_00d46f70_Obj
{
    int __thiscall FUN_00d46f70();
    FUN_00d46f70_Obj* __thiscall FUN_00d46d50();
};

extern FUN_00d46f70_Obj DAT_01268748;

// @fnv 0x00cf6170
unsigned char* FUN_00cf6170(unsigned char* result, FUN_00d46f70_Obj* object)
{
    if (object != 0)
    {
        do
        {
            if (object == &DAT_01268748)
                break;

            if (object->FUN_00d46f70() > 0)
            {
                *result = 1;
                return result;
            }

            object = object->FUN_00d46d50();
        } while (object != 0);
    }

    *result = 0;
    return result;
}

struct SceneNode
{
    SceneNode* Advance();
};

unsigned char* FUN_00cf6330(SceneNode** where, SceneNode* node);

// @fnv 0x00cf6380
unsigned char* FUN_00cf6380(unsigned char* pResult, SceneNode* pStartNode)
{
    SceneNode* cur = pStartNode;
    do
    {
        unsigned char* flag = FUN_00cf6330(&pStartNode, cur);
        if (*flag == 0)
        {
            *pResult = 0;
            return pResult;
        }
        cur = cur->Advance();
    } while (cur != 0);
    *pResult = 1;
    return pResult;
}

struct CF63C0Bool
{
    char m_cBooleanValue;

    CF63C0Bool(bool b)
    {
        m_cBooleanValue = (char)b;
    }
    operator bool() const
    {
        return m_cBooleanValue != 0;
    }
};

struct CF63C0Class
{
    int GetObjectAlignment() const;
    CF63C0Bool hasVtable() const;
};

CF63C0Bool __cdecl FUN_00cf6380(const CF63C0Class& pClassInfo);

struct CF63C0Writer
{
    virtual void unk00();
    virtual void unk04();
    virtual void unk08();
    virtual void writeObjectWithVtable(void* context, const void* object, bool recurse);
    virtual void WriteObjectWithClass(const CF63C0Class& pClassInfo, void* context, const void* object, bool recurse);
};

// @fnv 0x00cf63c0
void __cdecl WriteObjectArray(void* context, const CF63C0Class& pClassInfo, const void* data, int count,
                              CF63C0Writer& writer)
{
    if (count)
    {
        if (!FUN_00cf6380(pClassInfo))
        {
            const char* cur = static_cast<const char*>(data);
            int size = pClassInfo.GetObjectAlignment();
            if (pClassInfo.hasVtable())
            {
                for (int i = 0; i < count; i++)
                {
                    writer.writeObjectWithVtable(context, cur, true);
                    cur += size;
                }
            }
            else
            {
                for (int i = 0; i < count; i++)
                {
                    writer.WriteObjectWithClass(pClassInfo, context, cur, true);
                    cur += size;
                }
            }
        }
    }
}

struct Node
{
    Node* FUN_00d46d50();
};

void __cdecl WriteReflectedMembers(void* a, Node* b, void* c);

// If a1 is non-null, walks the linked list starting at a2, calling WriteReflectedMembers(a1, p, a3) for each node.
// @fnv 0x00cf6920
void __cdecl FUN_00cf6920(void* a1, Node* apNode, void* apArg)
{
    if (a1 == 0)
        return;
    Node* p = apNode;
    do
    {
        WriteReflectedMembers(a1, p, apArg);
        p = p->FUN_00d46d50();
    } while (p != 0);
}

// Candidate for GetFlagByState  (0x00cf62b0, 80 bytes)
//
// The original:
//   mov ecx,[esp+8]            ; the object
//   mov ax,word [ecx+0x10]     ; a 16-bit flag field
//   shr ax,9 / test al,1 / jne  -> set *out = 1
//   movzx eax,byte [ecx+0xc]   ; a byte "type" field
//   dec eax / cmp eax,0x20 / ja -> set *out = 0
//   movzx edx,byte [eax+map] / jmp [edx*4+jt]   (33-case two level switch)
//   ... 3 clusters: *out=1, *out=0, and one that calls a helper.
//
// The helper at 0x00d86910 is a __thiscall member that returns the dword at
// this+4; it must be a real call (not inlined) so that `this` stays in ECX.

struct FNV_Cf62b0_Obj
{
    unsigned int unk00;
    int m04;  // returned by the helper (0x00d86910)
    unsigned char unk08;
    unsigned char unk09;
    unsigned char unk0a;
    unsigned char unk0b;
    unsigned char unk0c;  // the "type" byte
    unsigned char unk0d;
    unsigned short unk0e;
    unsigned short unk10;  // the flag word
    int __thiscall FUN_cf62b0_get04();
};

__declspec(noinline) int __thiscall FNV_Cf62b0_Obj::FUN_cf62b0_get04()
{
    return m04;
}

extern "C" void __cdecl FUN_cf62b0_next(unsigned char* out, int node);

// @fnv 0x00cf62b0
unsigned char* GetFlagByState(unsigned char* pucOut, FNV_Cf62b0_Obj* pObj)
{
    bool bFlagSet = ((pObj->unk10 >> 9) & 1) != 0;
    if (bFlagSet)
    {
        *pucOut = 1;
        return pucOut;
    }

    unsigned int uiStateIndex = (unsigned int)pObj->unk0c - 1;
    switch (uiStateIndex)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 20:
    case 23:
    case 29:
    case 30:
    case 31:
        *pucOut = 1;
        return pucOut;

    case 18:
    case 19:
    case 21:
    case 22:
    case 25:
    case 26:
    case 27:
    case 28:
    case 32:
        *pucOut = 0;
        return pucOut;

    case 24:
        FUN_cf62b0_next(pucOut, pObj->FUN_cf62b0_get04());
        return pucOut;

    default:
        *pucOut = 0;
        return pucOut;
    }
}

struct Meta64;
struct Writer64;
struct Flags64
{
    unsigned short value;
    unsigned short get() const
    {
        return value;
    }
};
struct Member64
{
    const char* name;
    Meta64* pClassInfo;
    void* enumeration;
    unsigned char type, subtype;
    short cArraySize;
    Flags64 flags;
    unsigned short offset;
    void* attributes;
    int FUN_00d86940();
    Meta64* FUN_00d86910();
};
struct Meta64
{
    int FUN_00d46f70();
    Member64* FUN_00d46f80(int);
    int FUN_00d470d0();
};
struct Pair64
{
    void* data;
    int count;
};
struct Homogeneous64
{
    Meta64* pClassInfo;
    void* data;
    int count;
};
struct Variant64
{
    void* object;
    Meta64* pClassInfo;
};
struct Array64
{
    void* data;
    int count;
    int capacity;
};
struct Access64
{
    void* data;
    Member64* member;
    Access64(void*, Member64*);
    char** FUN_00d87220(int);
    const char* FUN_00d87230(int);
    Pair64* FUN_00d87340(int);
    Homogeneous64* FUN_00d87350(int);
};
struct Writer64
{
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void Begin(const char*);
    virtual void End();
    int unk04, unk08, unk0c;
    unsigned char includeStorage;
    void EmitString(const char*, const char*);
};
int __cdecl MemberSize64(Member64*);
void __cdecl EmitStringWithHash(Member64*, const char*, Writer64*);
void __cdecl FUN_00cf6080(const char*, void*, int, int, int, Writer64*);
void __cdecl FUN_00cf6460(Member64*, void*, int, Writer64*);
void __cdecl WriteObjectArray(const char*, Meta64*, void*, int, Writer64*);
void __cdecl WriteToDestination(const char*, void*, Meta64*, Writer64*);
void __cdecl FUN_00cf60d0(const char*, void*, Meta64*, Writer64*);
int __cdecl GetThingValue(Member64*);

// @fnv 0x00cf6580
void __cdecl WriteReflectedMembers(void* base, Meta64* apMeta, Writer64* writer)
{
    if (!base)
        return;
    int count = apMeta->FUN_00d46f70();
    for (int i = 0; i < count; ++i)
    {
        Member64* m = apMeta->FUN_00d46f80(i);
        if (((unsigned char)(m->flags.get() >> 9) & 1) != 0)
            continue;
        switch (m->type)
        {
        case 29: {
            Access64 value(base, m);
            int n = m->FUN_00d86940();
            if (n <= 1)
                EmitStringWithHash(m, *value.FUN_00d87220(0), writer);
            else
                for (int j = 0; j < n; ++j)
                    EmitStringWithHash(m, *value.FUN_00d87220(j), writer);
            break;
        }
        case 33: {
            Access64 value(base, m);
            int n = m->FUN_00d86940();
            if (n <= 1)
            {
                const char* name = m->name;
                writer->EmitString(name, value.FUN_00d87230(0));
            }
            else
                for (int j = 0; j < n; ++j)
                {
                    const char* name = m->name;
                    writer->EmitString(name, value.FUN_00d87230(j));
                }
            break;
        }
        case 22: {
            Array64* a = (Array64*)((char*)base + m->offset);
            if ((a->capacity & 0x80000000u) && !writer->includeStorage)
                break;
            int length = a->count;
            int capacity = a->capacity & 0x3fffffff;
            int size = GetThingValue(m);
            if (size < 0)
                break;
            bool pointers = m->subtype == 20;
            const char* name;
            if (pointers)
            {
                writer->Begin(m->name);
                name = "array";
            }
            else
                name = m->name;
            FUN_00cf6080(name, a->data, length, capacity, size, writer);
            FUN_00cf6460(m, a->data, length, writer);
            if (pointers)
                writer->End();
            break;
        }
        case 26: {
            Access64 value(base, m);
            Pair64 a = *value.FUN_00d87340(0);
            void* data = a.data;
            int length = a.count;
            int size = GetThingValue(m);
            if (size < 0)
                break;
            writer->Begin(m->name);
            FUN_00cf6080(m->name, data, length, length, size, writer);
            FUN_00cf6460(m, data, length, writer);
            writer->End();
            break;
        }
        case 27: {
            Access64 value(base, m);
            Homogeneous64 a = *value.FUN_00d87350(0);
            Meta64* itemClass = a.pClassInfo;
            void* data = a.data;
            int length = a.count;
            if (length > 0 && itemClass && data)
            {
                writer->Begin(m->name);
                const char* name = m->name;
                FUN_00cf6080(name, data, length, length, itemClass->FUN_00d470d0(), writer);
                WriteObjectArray(m->name, itemClass, data, length, writer);
                writer->End();
            }
            break;
        }
        case 20:
            if (m->subtype == 25)
            {
                void* data = *(void**)((char*)base + m->offset);
                const char* name = m->name;
                WriteToDestination(name, data, m->FUN_00d86910(), writer);
            }
            break;
        case 28: {
            Variant64* a = (Variant64*)((char*)base + m->offset);
            if (a->object && a->pClassInfo)
                WriteToDestination(m->name, a->object, a->pClassInfo, writer);
            break;
        }
        case 25: {
            const char* name = m->name;
            void* data = (char*)base + m->offset;
            FUN_00cf60d0(name, data, m->FUN_00d86910(), writer);
            break;
        }
        }
    }
}

struct hkClassMember
{
    const char* m_name;
    void* m_class;
    void* m_pClassEnum;
    unsigned char m_type;
    enum Type
    {
        TYPE_VOID
    };
    Type getType() const
    {
        return (Type)m_type;
    }
};

struct hkClass
{
    int GetNumDeclaredMembers() const;
    const hkClassMember& GetDeclaredMember(int i) const;
    void touch() const
    {}
};

struct hkStringPtr
{
    const char* m_pcText;
};

struct StringArrayAccessor
{
    void* m_pTargetObject;
    const hkClassMember* m_kMemberDescriptor;

    StringArrayAccessor(const void* object, const hkClassMember* member);
    const char*& GetStringPointerAt(int index);
    hkStringPtr& GetStringPtr(int index);
};

int __cdecl FUN_00cb0fa0(const char* a, const char* b);

// Finds the declared member named "name" in pClassInfo and returns its string value, or "unnamed" when the pointer is null.
// @fnv 0x00cf6210
static __declspec(noinline) const char* FUN_00cf6210(const void* object, const hkClass& pClassInfo)
{
    const int n = pClassInfo.GetNumDeclaredMembers();
    for (int i = 0; i < n; i++)
    {
        const hkClassMember& member = pClassInfo.GetDeclaredMember(i);
        const char* name = member.m_name;
        if (FUN_00cb0fa0(name, "name") != 0)
            continue;
        StringArrayAccessor accessor(object, &member);
        switch (member.getType())
        {
        case 0x1d: {
            const char* s = accessor.GetStringPointerAt(0);
            if (&pClassInfo)
                return s ? s : "unnamed";
            return s ? s : "unnamed";
        }
        case 0x21: {
            const char* s = (const char*)((unsigned int)accessor.GetStringPtr(0).m_pcText & ~1u);
            return s ? s : "unnamed";
        }
        }
    }
    return 0;
}

const void* volatile g_obj;
const hkClass* volatile g_klass;
const char* volatile g_out;
void caller_cf6210()
{
    g_out = FUN_00cf6210(g_obj, *g_klass);
}

extern const char DAT_01094398[];
extern const char DAT_010cc458[];
int __cdecl FUN_00cb0fa0(const char*, const char*);
struct TaggedString64
{
    unsigned int bits;
};
static __declspec(noinline) const char* FUN_00cf6210(Meta64* pClassInfo, void* object)
{
    if (!pClassInfo)
        return 0;
    int count = pClassInfo->FUN_00d46f70();
    for (int i = 0; i < count; ++i)
    {
        Member64* m = pClassInfo->FUN_00d46f80(i);
        if (FUN_00cb0fa0(m->name, DAT_01094398) == 0)
        {
            Access64 access(object, m);
            switch (m->type)
            {
            case 0x21: {
                TaggedString64* slot = (TaggedString64*)access.FUN_00d87230(0);
                const char* name = (const char*)(slot->bits & ~1u);
                return name ? name : DAT_010cc458;
            }
            case 0x1d: {
                const char* name = *access.FUN_00d87220(0);
                return name ? name : DAT_010cc458;
            }
            }
        }
    }
    return 0;
}

// Processes each element according to member subtype, calling the corresponding writer or helper for recognized subtypes.
// @fnv 0x00cf6460
void __cdecl FUN_00cf6460(Member64* member, void* elements, int count, Writer64* writer)
{
    if (count <= 0)
        return;
    switch (member->subtype)
    {
    case 0x14: {
        Meta64* meta = member->FUN_00d86910();
        if (!meta)
            return;
        for (int i = 0; i < count; ++i)
        {
            const char* name = FUN_00cf6210(meta, ((void**)elements)[i]);
            if (!name)
                name = member->name;
            WriteToDestination(name, ((void**)elements)[i], meta, writer);
        }
        return;
    }
    case 0x19: {
        Meta64* meta = member->FUN_00d86910();
        if (!meta)
            return;
        WriteObjectArray(member->name, meta, elements, count, writer);
        return;
    }
    case 0x1d:
        for (int i = 0; i < count; ++i)
            EmitStringWithHash(member, ((const char**)elements)[i], writer);
        return;
    case 0x21: {
        for (int i = 0; i < count; ++i)
            writer->EmitString(member->name, (const char*)((const char**)elements + i));
        return;
    }
    }
}
