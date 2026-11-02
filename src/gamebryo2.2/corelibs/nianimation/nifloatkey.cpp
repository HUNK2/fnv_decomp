
// src/gamebryo2.2/corelibs/nianimation/nifloatkey.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nifloatkey.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct AnimationKey
{
    int _00;
    int _04;
};
struct TimedAnimationKey : AnimationKey
{
    float _08;
    float _0c;
};
bool __cdecl AreRecordsEqual(const AnimationKey&, const AnimationKey&);
// Returns false if AreRecordsEqual rejects the keys, otherwise compares the two float fields of the keys for equality.
// @fnv 0x00a26f30
bool FUN_00a26f30(const AnimationKey& key0, const AnimationKey& key1)
{
    const TimedAnimationKey* pKey1Floats = (const TimedAnimationKey*)&key1;
    const TimedAnimationKey* pKey0Floats = (const TimedAnimationKey*)&key0;
    if (!AreRecordsEqual(key0, key1))
        return false;
    return pKey0Floats->_08 == pKey1Floats->_08 && pKey0Floats->_0c == pKey1Floats->_0c;
}

struct MyIn
{
    int _pad;
    int pos;
    int(__cdecl* read)(MyIn*, void*, unsigned int, unsigned int*, unsigned int);
};
struct MyStream
{
    char _pad[0x24C];
    MyIn* input;
};
// Reads 4 bytes from the stream's input into pValue and advances the input position by the bytes read.
// @fnv 0x00a26df0
void FUN_00a26df0(MyStream* pkStream, void* pValue)
{
    MyIn* __restrict pkInput = pkStream->input;
    unsigned int uiSize = 4;
    pkInput->pos += pkInput->read(pkInput, pValue, 4, &uiSize, 1);
}

struct NiBinaryStream
{
    int _0;
    unsigned int position;
    unsigned int (*read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
};
struct NiStream
{
    char _pad[0x24C];
    NiBinaryStream* input;
};
struct Base_00a26eb0
{
    int _0;
    void AccumulateAnimSink(NiStream&);
};
struct Holder_00a26eb0 : Base_00a26eb0
{
    float m;
    void FUN_00a26eb0(NiStream&);
};
// Calls the base stream reader, then reads 4 bytes from stream.input into m and advances the stream position by the bytes read.
// @fnv 0x00a26eb0
void Holder_00a26eb0::FUN_00a26eb0(NiStream& stream)
{
    Base_00a26eb0::AccumulateAnimSink(stream);
    NiBinaryStream* __restrict input = stream.input;
    unsigned int size = 4;
    input->position += input->read(input, &m, 4, &size, 1);
}

struct SOut
{
    int f0;
    int pos;
    int f8;
    int(__cdecl* fn)(SOut*, void*, int, unsigned int*, int);
};
struct SStream
{
    char pad[0x250];
    SOut* out;
};
struct SObj
{
    char pad[4];
    float v;
};
void __cdecl CallAnimCallback(SStream*, SObj*);
// Calls CallAnimCallback, then writes the float at a2->v into the stream's output via its fn callback and advances pos by the bytes written.
// @fnv 0x00a26ef0
void WriteFloatToStream(SStream* pStream, SObj* pObj)
{
    CallAnimCallback(pStream, pObj);
    SOut* __restrict output = pStream->out;
    unsigned int size = 4;
    output->pos += output->fn(output, &pObj->v, 4, &size, 1);
}

typedef void(__cdecl* BA26E20Func)(void*);

void __cdecl CreateFloatKeys(void* pvKeys);
void __cdecl DeleteFloatKeys(void* pvKeys);
void __cdecl EqualFloatKeys(void* pvKeys);
void __cdecl SaveFloatKeys(void* pvKeys);
void __cdecl CopyFloatKeys(void* pvKeys);
void __cdecl InsertFloatKey(void* pvKeys);
void __cdecl InterpFloatKey(void* pvKeys);
void __cdecl IsPosedFloatKey(void* pvKeys);

extern bool g_bA26E20Registered;
extern BA26E20Func g_apfnA26E20CurvesCopy[];
extern BA26E20Func g_apfnA26E20Interp1[];
extern BA26E20Func g_apfnA26E20Interp2[];
extern BA26E20Func g_apfnA26E20Cubic[];
extern BA26E20Func g_apfnA26E20Create[];
extern BA26E20Func g_apfnA26E20Delete[];
extern BA26E20Func g_apfnA26E20Equal[];
extern BA26E20Func g_apfnA26E20Save[];
extern BA26E20Func g_apfnA26E20Copy[];
extern unsigned char g_aucA26E20KeySize[];
extern BA26E20Func g_apfnA26E20Insert[];
extern BA26E20Func g_apfnA26E20Interp[];
extern BA26E20Func g_apfnA26E20IsPosed[];

// Registers the float-key operations in the global function tables and key-size table, returning 1 on first registration and 0 if already registered.
// @fnv 0x00a26e20
int __cdecl RegisterFloatKeyOps()
{
    if (g_bA26E20Registered)
        return 0;

    g_bA26E20Registered = true;
    g_apfnA26E20CurvesCopy[0] = 0;
    g_apfnA26E20Interp1[0] = 0;
    g_apfnA26E20Interp2[0] = 0;
    g_apfnA26E20Cubic[0] = 0;
    g_apfnA26E20Create[0] = CreateFloatKeys;
    g_apfnA26E20Delete[0] = DeleteFloatKeys;
    g_apfnA26E20Equal[0] = EqualFloatKeys;
    g_apfnA26E20Save[0] = SaveFloatKeys;
    g_apfnA26E20Copy[0] = CopyFloatKeys;
    g_aucA26E20KeySize[0] = 8;
    g_apfnA26E20Insert[0] = InsertFloatKey;
    g_apfnA26E20Interp[0] = InterpFloatKey;
    g_apfnA26E20IsPosed[0] = IsPosedFloatKey;
    return 1;
}

class NiFloatKeyA26
{
  public:
    enum KeyType
    {
        NOINTERP,
        LINKEY,
        BEZKEY,
        TCBKEY,
        EULERKEY,
        STEPKEY
    };

    float GetTime() const
    {
        return m_fTime;
    }
    float GetValue() const
    {
        return m_fValue;
    }

    NiFloatKeyA26* GetKeyPointerByIndex(unsigned int uiIndex, unsigned char ucKeySize)
    {
        return (NiFloatKeyA26*)((char*)this + uiIndex * ucKeySize);
    }

    static float InterpolatePosition(float fTime, NiFloatKeyA26* pkKeys, KeyType eType, unsigned int uiNumKeys,
                                     unsigned int& uiLastIdx, unsigned char ucSize);
    static float GetValueAtTime(float fTime, NiFloatKeyA26* pkKeys, KeyType eType, unsigned int uiNumKeys,
                                unsigned char ucSize);

    float m_fTime;
    float m_fValue;
};

extern float g_fDefaultValueA26;

// Returns the key value at fTime, clamping to the first/last key outside the range and otherwise delegating to the interpolating lookup.
// @fnv 0x00a26d70
float NiFloatKeyA26::GetValueAtTime(float fTime, NiFloatKeyA26* pkKeys, KeyType eType, unsigned int uiNumKeys,
                                    unsigned char ucSize)
{
    if (uiNumKeys)
    {
        if (fTime < pkKeys->GetTime())
            return pkKeys->GetValue();

        if (fTime > pkKeys->GetKeyPointerByIndex(uiNumKeys - 1, ucSize)->GetTime())
            return pkKeys->GetKeyPointerByIndex(uiNumKeys - 1, ucSize)->GetValue();

        unsigned int uiLastIdx = 0;
        return InterpolatePosition(fTime, pkKeys, eType, uiNumKeys, uiLastIdx, ucSize);
    }
    return g_fDefaultValueA26;
}

struct S00a26b40_Key
{
    float time;
    float value;
};
typedef void(__cdecl* S00a26b40_Interp)(float, const S00a26b40_Key*, const S00a26b40_Key*, float*);
extern S00a26b40_Interp DAT_011f3c90[];

static inline const S00a26b40_Key& S00a26b40_At(const S00a26b40_Key* keys, unsigned int i, unsigned char keySize)
{
    return *(const S00a26b40_Key*)((const char*)keys + i * keySize);
}

// Selects a key interval for time, interpolates when a next key exists, and updates lastIndex on the multi-key path.
// @fnv 0x00a26b40
float __cdecl InterpolateKey(float time, const S00a26b40_Key* keys, unsigned int type, unsigned int count,
                             unsigned int* lastIndex, unsigned char keySize)
{
    if (count == 1 || time == -3.4028234663852886e+38)
        return keys->value;

    unsigned int end = count - 1;
    unsigned int last = *lastIndex;
    float lastTime = S00a26b40_At(keys, last, keySize).time;
    if (time < lastTime)
    {
        last = 0;
        lastTime = keys->time;
    }
    float nextTime = 0.0f;
    unsigned int next = last + 1;
    __assume(next <= end);
    for (; next <= end; next++)
    {
        nextTime = S00a26b40_At(keys, next, keySize).time;
        if (time <= nextTime)
            break;
        lastTime = nextTime;
        last++;
    }
    float result;
    if (next < count)
    {
        float t = (time - lastTime) / (nextTime - lastTime);
        DAT_011f3c90[type](t, &S00a26b40_At(keys, last, keySize), &S00a26b40_At(keys, next, keySize), &result);
    }
    else
        result = S00a26b40_At(keys, last, keySize).value;
    *lastIndex = last;
    return result;
}
