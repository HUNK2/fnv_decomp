
// src/gamebryo2.2/corelibs/nianimation/nicolorkey.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/gamebryo2.2/corelibs/nianimation/nicolorkey.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct NiStream;
struct blob16
{
    char b[16];
};
struct AnimationKey
{
    static int RegisterObjectLoader();
    static void RegisterSupportedFunctions(int, int);
    static AnimationKey* CreateObjectFromStream(NiStream*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveToStream(NiStream*, AnimationKey*, unsigned int);
    static void SaveBinary(NiStream*, AnimationKey*);
    static void Copy(AnimationKey*, void*);
    static AnimationKey* CreateArray(unsigned int);
    static void DeleteArray(AnimationKey*);
    static bool Insert(float, AnimationKey**, unsigned int*);
    static float ComputeMaxCurvature(AnimationKey*, unsigned int);
    static void Interpolate(float, void*, void*, void*);
    static void InterpolateD1(float, void*, void*, void*);
    static void InterpolateD2(float, void*, void*, void*);
    static bool Equal(void*, void*);
    static void FillDerivedVals(AnimationKey*, unsigned int, unsigned char);
    void SetTime(float);
    float GetTime();
    AnimationKey* GetKeyPointerByIndex(unsigned int, unsigned char);
    static unsigned char GetKeySize(int, int);
    static int* GetCurvatureFunction(int, int);
    static int* GetInterpFunction(int, int);
    static int* GetInterpD1Function(int, int);
    static int* GetInterpD2Function(int, int);
    static int* GetFillDerivedFunction(int, int);
    static int* GetCreateFunction(int, int);
    static int* GetSaveFunction(int, int);
    static int* GetEqualFunction(int, int);
    static int* GetCopyFunction(int, int);
    static int* GetArrayFunction(int, int);
    static int* GetDeleteFunction(int, int);
    static int* GetInsertFunction(int, int);
    static void AddKeyToArray(int, int, void*, unsigned int, float, float, AnimationKey**, unsigned int*);
    static void RemoveKeyFromArray(int, int, AnimationKey**, unsigned int*, float, float);
    static void SetCreateFunction(int, int, int*);
    static void SetCurvatureFunction(int, int, int*);
    static void SetInterpFunction(int, int, int*);
    static void SetInterpD1Function(int, int, int*);
    static void SetInterpD2Function(int, int, int*);
    static void SetEqualFunction(int, int, int*);
    static void SetCopyFunction(int, int, int*);
    static void SetArrayFunction(int, int, int*);
    static void SetDeleteFunction(int, int, int*);
    static void SetInsertFunction(int, int, int*);
    static void SetSaveFunction(int, int, int*);
    static void SetFillDerivedValsFunction(int, int, int*);
    static void SetKeySize(int, int, unsigned char);
    static bool OkayToInsert(float, void*, unsigned int, unsigned int*, unsigned char);
    void* __vecDelDtor(unsigned int);
    float m_fTime;
};
typedef char _sizecheck_NiAnimationKey[sizeof(AnimationKey) == 4 ? 1 : -1];
struct ColorAnimationKey : public AnimationKey
{
    static int RegisterObjectLoader();
    static void RegisterSupportedFunctions(int, int);
    static AnimationKey* CreateObjectFromStream(NiStream*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveToStream(NiStream*, AnimationKey*, unsigned int);
    static void SaveBinary(NiStream*, AnimationKey*);
    static void Copy(AnimationKey*, void*);
    static AnimationKey* CreateArray(unsigned int);
    static void DeleteArray(AnimationKey*);
    static bool Insert(float, AnimationKey**, unsigned int*);
    static float ComputeMaxCurvature(AnimationKey*, unsigned int);
    static void Interpolate(float, void*, void*, void*);
    static void InterpolateD1(float, void*, void*, void*);
    static void InterpolateD2(float, void*, void*, void*);
    static bool Equal(void*, void*);
    static void FillDerivedVals(AnimationKey*, unsigned int, unsigned char);
    void SetColor(void*);
    void* GetColor();
    static struct blob16 InterpolatePosition(float, ColorAnimationKey*, int, unsigned int, unsigned int*,
                                             unsigned char);
    ColorAnimationKey* GetKeyPointerByIndex(unsigned int, unsigned char);
    static unsigned char GetKeySize(int);
    static int* GetInterpFunction(int);
    static int* GetCreateFunction(int);
    static int* GetSaveFunction(int);
    static int* GetEqualFunction(int);
    static int* GetCopyFunction(int);
    static int* GetArrayFunction(int);
    static int* GetDeleteFunction(int);
    static int* GetInsertFunction(int);
    static void SetDefault(void*);
    static struct blob16 GenInterpDefault(float, ColorAnimationKey*, int, unsigned int, unsigned char);
    void* __vecDelDtor(unsigned int);
    char m_kRgbaColor[16];
};
typedef char _sizecheck_NiColorKey[sizeof(ColorAnimationKey) == 20 ? 1 : -1];
struct RgbaColor
{
    void Clamp();
    void Scale();
    static void LoadBinary(NiStream*, RgbaColor*, unsigned int);
    void LoadBinary(NiStream*);
    static void SaveBinary(NiStream*, RgbaColor*, unsigned int);
    void SaveBinary(NiStream*);
    char* FormatToBuffer(char*);
    float Luminance();
    void __dflt_ctor_closure();
    float r;
    float g;
    float b;
    float a;
};
typedef char _sizecheck_NiColorA[sizeof(RgbaColor) == 16 ? 1 : -1];

typedef void(__cdecl* InterpFn)(float, const char*, const char*, void*);
extern InterpFn DAT_011f3cd8[];
extern double DAT_010241b0;

// Returns a table color directly when count is one or f matches DAT_010241b0; otherwise interpolates adjacent entries and updates pIdx.
// @fnv 0x00a296c0
RgbaColor __cdecl InterpolateColor(float afTime, const char* table, unsigned int interp, unsigned int count,
                                   unsigned int* pIdx, unsigned char stride)
{
    if (count == 1 || afTime == DAT_010241b0)
    {
        return *(const RgbaColor*)(table + 4);
    }
    unsigned int idx = *pIdx;
    unsigned int last = count - 1;
    float prevVal = *(const float*)(table + stride * idx);
    if (afTime < prevVal)
    {
        prevVal = *(const float*)table;
        idx = 0;
    }
    float fCurTime = 0.0f;
    unsigned int i = idx + 1;
    __assume(i <= last);
    for (; i <= last; ++i, ++idx)
    {
        fCurTime = *(const float*)(table + stride * i);
        if (afTime <= fCurTime)
            break;
        prevVal = fCurTime;
    }
    RgbaColor color;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
    color.a = 0.0f;
    float t = (afTime - prevVal) / (fCurTime - prevVal);
    DAT_011f3cd8[interp](t, table + stride * idx, table + stride * i, &color);
    *pIdx = idx;
    return color;
}
