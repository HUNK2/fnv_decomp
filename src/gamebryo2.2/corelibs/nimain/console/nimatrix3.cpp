
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct TransformRecord {
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    bool __thiscall FUN_00a58990(unsigned int parameter, float* result);
    void __thiscall FUN_00a58b00(unsigned int parameter, float* result);
    void __thiscall GetMatrix(unsigned int parameter, float* output);
};

// @fnv 0x00a59980
void TransformRecord::GetMatrix(unsigned int parameter, float* pafMatrix)
{
    TransformRecord recordCopy = *this;
    float intermediate[2];
    bool negate = recordCopy.FUN_00a58990(parameter, intermediate);
    recordCopy.FUN_00a58b00(parameter, intermediate);
    pafMatrix[0] = recordCopy.unk00;
    pafMatrix[1] = recordCopy.unk0C;
    pafMatrix[2] = recordCopy.unk18;
    pafMatrix[3] = recordCopy.unk04;
    pafMatrix[4] = recordCopy.unk10;
    pafMatrix[5] = recordCopy.unk1C;
    if (negate) {
        pafMatrix[6] = -recordCopy.unk08;
        pafMatrix[7] = -recordCopy.unk14;
        pafMatrix[8] = -recordCopy.unk20;
    } else {
        pafMatrix[6] = recordCopy.unk08;
        pafMatrix[7] = recordCopy.unk14;
        pafMatrix[8] = recordCopy.unk20;
    }
}

struct S_00a59a30_BinaryStream;
typedef unsigned int (__cdecl *S_00a59a30_ReadFn)(S_00a59a30_BinaryStream* pkThis, void* pvBuffer,
    unsigned int uiBytes, unsigned int* puiComponentSizes, unsigned int uiNumComponents);

struct S_00a59a30_BinaryStream {
    void* vtbl;
    unsigned int m_uiStreamFlags;
    S_00a59a30_ReadFn m_pfnRead;

    unsigned int BinaryRead(void* pvBuffer, unsigned int uiTotalBytes, unsigned int* puiComponentSizes,
        unsigned int uiNumComponents)
    {
        unsigned int uiBytesRead = m_pfnRead(this, pvBuffer, uiTotalBytes, puiComponentSizes, uiNumComponents);
        m_uiStreamFlags += uiBytesRead;
        return uiBytesRead;
    }
};

template <class T>
inline void S_00a59a30_BinaryStreamLoad(S_00a59a30_BinaryStream& kStream, T* pValue, unsigned int uiNumEls)
{
    unsigned int uiComponentSize = sizeof(T);
    kStream.BinaryRead(pValue, uiNumEls * sizeof(T), &uiComponentSize, 1);
}

struct S_00a59a30_Stream {
    S_00a59a30_BinaryStream* GetIStr() { return unk24c; }
    int unk0;
    int unk4;
    int unk8;
    int unkc;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
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
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    int unkdc;
    int unke0;
    int unke4;
    int unke8;
    int unkec;
    int unkf0;
    int unkf4;
    int unkf8;
    int unkfc;
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    S_00a59a30_BinaryStream* unk24c;
};

struct S_00a59a30_Matrix3 {
    float m_afEntries[3][3];
    void LoadFromStream(S_00a59a30_Stream& kStream);
};

// Reads the 3x3 matrix elements from the stream's binary reader, loading each element individually.
// @fnv 0x00a59a30
void S_00a59a30_Matrix3::LoadFromStream(S_00a59a30_Stream& kStream)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            S_00a59a30_BinaryStreamLoad(*kStream.GetIStr(), &m_afEntries[i][j], 1);
    }
}

extern "C" double __cdecl acos(double dValue);

extern const float g_fA58510Pi;

// Returns acos(fValue) when fValue is between -1 and 1, 0.0 when it is 1 or above, and g_fA58510Pi when it is -1 or below.
// @fnv 0x00a58510
float __cdecl AcosClamped(float fValue)
{
    if (-1.0 < fValue) {
        if (fValue < 1.0f)
            return (float)acos(fValue);
        else
            return 0.0f;
    } else {
        return g_fA58510Pi;
    }
}

extern float DAT_0109afc4;

extern "C" double __cdecl fabs(double value);

class FUN_00a598a0_cls {
public:
    void ZeroSmallValues();
};

// Scans a 3x3 block of floats and sets each element to zero when its absolute value is at or below DAT_0109afc4.
// @fnv 0x00a598a0
void FUN_00a598a0_cls::ZeroSmallValues()
{
    double threshold = DAT_0109afc4;
    float zero = 0.0f;
    float *p = (float *)this;
    int rows = 3;
    while (rows != 0) {
        int cols = 3;
        do {
            float mag = (float)fabs((double)*p);
            if ((double)mag <= threshold) {
                if (*p != zero) {
                    *p = zero;
                }
            }
            p++;
        } while (--cols != 0);
        rows--;
    }
}

struct S_00a59a90_Bin {
    unsigned int unk00;
    unsigned int m_uiPos;
    unsigned int unk08;
    unsigned int (__cdecl* m_pfnRead)(S_00a59a90_Bin*, void*, unsigned int, unsigned int*, unsigned int);
    unsigned int Read(void* p, unsigned int bytes, unsigned int* sz, unsigned int n) {
        return m_pfnRead(this, p, bytes, sz, n);
    }
};
static __forceinline void S_BinRead(S_00a59a90_Bin* bin, void* v, unsigned int bytes) {
    unsigned int sz = 4;
    bin->m_uiPos += bin->Read(v, bytes, &sz, 1);
}
struct FUN_00a59a90_cls {
    float m[9];
    void ZeroSmallValues();
    void ReadMatrixFromStream(void* pOther);
};
// Calls ZeroSmallValues, then reads nine floats from the stream at pOther+0x250 into the 3x3 matrix m.
// @fnv 0x00a59a90
void FUN_00a59a90_cls::ReadMatrixFromStream(void* pOther)
{
    char* pObj = (char*)pOther;
    ZeroSmallValues();
    float* p = m;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            S_BinRead(*(S_00a59a90_Bin**)(pObj + 0x250), p, 4);
            p++;
        }
    }
}

struct Point314 {float x,y,z;};
// Transforms each of count source points by a 3x3 matrix plus translation, writing the results to destination.
// @fnv 0x00a582f0
extern "C" void FUN_00a582f0(const float* matrix,const float* translation,unsigned int count,const Point314* source,Point314* destination) {
 for(unsigned int i=0;i<count;++i) {
  destination[i].x=matrix[0]*source[i].x+translation[0]+matrix[1]*source[i].y+source[i].z*matrix[2];
  destination[i].y=matrix[3]*source[i].x+translation[1]+matrix[4]*source[i].y+matrix[5]*source[i].z;
  destination[i].z=matrix[6]*source[i].x+translation[2]+source[i].y*matrix[7]+matrix[8]*source[i].z;
 }
}

#include "fnv_asm_helpers.h"   // project x87 helpers (fnv_SinCos, fnv_FloatToInt), kept last so earlier code is unchanged

class Matrix3A588 {
public:
    float m_afEntries[3][3];

    Matrix3A588 FUN_00a588a0(const Matrix3A588& kMat) const;
};

// @fnv 0x00a588a0
Matrix3A588 Matrix3A588::FUN_00a588a0(const Matrix3A588& kMat) const
{
    Matrix3A588 kPrd;
    kPrd.m_afEntries[0][0] = m_afEntries[0][0] * kMat.m_afEntries[0][0] + m_afEntries[1][0] * kMat.m_afEntries[1][0]
        + m_afEntries[2][0] * kMat.m_afEntries[2][0];
    kPrd.m_afEntries[1][0] = m_afEntries[0][1] * kMat.m_afEntries[0][0] + m_afEntries[1][1] * kMat.m_afEntries[1][0]
        + m_afEntries[2][1] * kMat.m_afEntries[2][0];
    kPrd.m_afEntries[2][0] = m_afEntries[0][2] * kMat.m_afEntries[0][0] + m_afEntries[1][2] * kMat.m_afEntries[1][0]
        + m_afEntries[2][2] * kMat.m_afEntries[2][0];
    kPrd.m_afEntries[0][1] = m_afEntries[0][0] * kMat.m_afEntries[0][1] + m_afEntries[1][0] * kMat.m_afEntries[1][1]
        + m_afEntries[2][0] * kMat.m_afEntries[2][1];
    kPrd.m_afEntries[1][1] = m_afEntries[0][1] * kMat.m_afEntries[0][1] + m_afEntries[1][1] * kMat.m_afEntries[1][1]
        + m_afEntries[2][1] * kMat.m_afEntries[2][1];
    kPrd.m_afEntries[2][1] = m_afEntries[0][2] * kMat.m_afEntries[0][1] + m_afEntries[1][2] * kMat.m_afEntries[1][1]
        + m_afEntries[2][2] * kMat.m_afEntries[2][1];
    kPrd.m_afEntries[0][2] = m_afEntries[0][0] * kMat.m_afEntries[0][2] + m_afEntries[1][0] * kMat.m_afEntries[1][2]
        + m_afEntries[2][0] * kMat.m_afEntries[2][2];
    kPrd.m_afEntries[1][2] = m_afEntries[0][1] * kMat.m_afEntries[0][2] + m_afEntries[1][1] * kMat.m_afEntries[1][2]
        + m_afEntries[2][1] * kMat.m_afEntries[2][2];
    kPrd.m_afEntries[2][2] = m_afEntries[0][2] * kMat.m_afEntries[0][2] + m_afEntries[1][2] * kMat.m_afEntries[1][2]
        + m_afEntries[2][2] * kMat.m_afEntries[2][2];
    return kPrd;
}

// Rotation matrix builder: three angles -> 3x3 matrix (Z * (Y * X) style composition).
// FUN_00a59660: thiscall, three float angles on the stack.

struct Mat3 {
    float m[9];
    Mat3* FUN_0043f8d0(Mat3* pResult, Mat3* pInput);
};

struct FUN_00a59660_cls {
    Mat3 value;
    void FUN_00a59660(float fAngle1, float fAngle2, float fAngle3);
};

// @fnv 0x00a59660
void FUN_00a59660_cls::FUN_00a59660(float fAngle1, float fAngle2, float fAngle3)
{
    Mat3 kMat[4];
    float fSin, fCos;

    fnv_SinCos(fAngle2, fSin, fCos);
    kMat[0].m[0] = 1.0f;
    kMat[0].m[1] = 0.0f;
    kMat[0].m[2] = 0.0f;
    kMat[0].m[3] = 0.0f;
    kMat[0].m[4] = fCos;
    kMat[0].m[5] = fSin;
    kMat[0].m[6] = 0.0f;
    kMat[0].m[7] = -fSin;
    kMat[0].m[8] = fCos;

    fnv_SinCos(fAngle3, fSin, fCos);
    kMat[1].m[0] = fCos;
    kMat[1].m[1] = 0.0f;
    kMat[1].m[2] = -fSin;
    kMat[1].m[3] = 0.0f;
    kMat[1].m[4] = 1.0f;
    kMat[1].m[5] = 0.0f;
    kMat[1].m[6] = fSin;
    kMat[1].m[7] = 0.0f;
    kMat[1].m[8] = fCos;

    fnv_SinCos(fAngle1, fSin, fCos);
    kMat[2].m[0] = fCos;
    kMat[2].m[1] = fSin;
    kMat[2].m[2] = 0.0f;
    kMat[2].m[3] = -fSin;
    kMat[2].m[4] = fCos;
    kMat[2].m[5] = 0.0f;
    kMat[2].m[6] = 0.0f;
    kMat[2].m[7] = 0.0f;
    kMat[2].m[8] = 1.0f;

    Mat3* pFirst = kMat[0].FUN_0043f8d0(&kMat[3], &kMat[1]);
    Mat3* pSecond = kMat[2].FUN_0043f8d0(&kMat[0], pFirst);
    value = *pSecond;
}

#include <math.h>
inline float NiACos(float fValue)
{
    if (-1.0f < fValue) {
        if (fValue < 1.0f)
            return float(acos(fValue));
        else
            return 0.0f;
    } else {
        return g_fA58510Pi;
    }
}

inline float NiSqrt(float fValue)
{
    return float(sqrt(fValue));
}

struct FUN_00a58550_cls {
    float unk00;
    float unk04;
    float unk08;
    float unk0C;
    float unk10;
    float unk14;
    float unk18;
    float unk1C;
    float unk20;
    void GetAxisAngle(float* angle, float* ax, float* ay, float* az) const;
};

// Extracts the rotation axis and angle from a 3x3 matrix, normalizing the axis and handling degenerate cases.
// @fnv 0x00a58550
void FUN_00a58550_cls::GetAxisAngle(float* angle, float* apAxisX, float* apAxisY, float* apAxisZ) const
{
    float trace = unk00 + unk10 + unk20;
    float c = (trace - 1.0) * 0.5;
    *angle = NiACos(c);

    *apAxisX = unk14 - unk1C;
    *apAxisY = unk18 - unk08;
    *apAxisZ = unk04 - unk0C;

    float len = NiSqrt(*apAxisX * *apAxisX + *apAxisY * *apAxisY + *apAxisZ * *apAxisZ);
    if (len > 1e-6f) {
        float inv = 1.0f / len;
        *apAxisX = *apAxisX * inv;
        *apAxisY = *apAxisY * inv;
        *apAxisZ = *apAxisZ * inv;
        return;
    }

    if (*angle > 1.0f) {
        *apAxisX = NiSqrt((unk00 + 1.0) * 0.5);
        *apAxisY = NiSqrt((unk10 + 1.0) * 0.5);
        *apAxisZ = NiSqrt((unk20 + 1.0) * 0.5);

        float t1 = (*apAxisX * unk00 + unk04 * *apAxisY) + unk08 * *apAxisZ - *apAxisX;
        float t2 = (unk0C * *apAxisX + unk10 * *apAxisY) + unk14 * *apAxisZ - *apAxisY;
        float t3 = (unk18 * *apAxisX + unk1C * *apAxisY) + unk20 * *apAxisZ - *apAxisZ;
        float s = t1 * t1 + t2 * t2 + t3 * t3;
        if (s < 1e-6f) {
            return;
        }
        *apAxisZ = -*apAxisZ;
        t1 = (*apAxisX * unk00 + unk04 * *apAxisY) + unk08 * *apAxisZ - *apAxisX;
        t2 = (unk0C * *apAxisX + unk10 * *apAxisY) + unk14 * *apAxisZ - *apAxisY;
        t3 = (unk18 * *apAxisX + unk1C * *apAxisY) + unk20 * *apAxisZ - *apAxisZ;
        s = t1 * t1 + t2 * t2 + t3 * t3;
        if (s < 1e-6f) {
            return;
        }
        *apAxisY = -*apAxisY;
        t1 = (*apAxisX * unk00 + unk04 * *apAxisY) + unk08 * *apAxisZ - *apAxisX;
        t2 = (unk0C * *apAxisX + unk10 * *apAxisY) + unk14 * *apAxisZ - *apAxisY;
        t3 = (unk18 * *apAxisX + unk1C * *apAxisY) + unk20 * *apAxisZ - *apAxisZ;
        s = t1 * t1 + t2 * t2 + t3 * t3;
        if (s < 1e-6f) {
            return;
        }
    } else {
        *apAxisX = 1.0f;
        *apAxisY = 0.0f;
        *apAxisZ = 0.0f;
    }
}

struct S_00a58990 {
    float unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20;
    bool FUN_00a58990(float* diag, float* subd);
};

// Writes diagonal and subdiagonal values from the matrix fields and updates those fields in place.
// @fnv 0x00a58990
bool S_00a58990::FUN_00a58990(float* diag, float* subd)
{
    float m01 = unk04;
    float m02 = unk08;
    float m11 = unk10;
    float m12 = unk14;
    float m22 = unk20;
    diag[0] = unk00;
    if (fabs(m02) >= 1e-08f) {
        subd[0] = (float)sqrt(m02 * m02 + m01 * m01);
        float inv = 1.0f / subd[0];
        m01 *= inv;
        m02 *= inv;
        float tmp = 2.0f * m01 * m12 + m02 * (m22 - m11);
        diag[1] = m11 + m02 * tmp;
        diag[2] = m22 - m02 * tmp;
        subd[1] = m12 - m01 * tmp;
        unk00 = 1.0f;
        unk04 = 0.0f;
        unk08 = 0.0f;
        unk0c = 0.0f;
        unk18 = 0.0f;
        unk10 = m01;
        unk14 = m02;
        unk1c = m02;
        unk20 = -m01;
        return true;
    }
    diag[1] = m11;
    diag[2] = m22;
    subd[0] = m01;
    subd[1] = m12;
    unk00 = 1.0f;
    unk04 = 0.0f;
    unk08 = 0.0f;
    unk0c = 0.0f;
    unk14 = 0.0f;
    unk18 = 0.0f;
    unk1c = 0.0f;
    unk10 = 1.0f;
    unk20 = 1.0f;
    return false;
}

float FUN_00a811f0(float fY, float fX);

static float DAT_011a9444 = 1.5707964f;

static inline float S_00a592c0_ASin(float fValue)
{
    if (-1.0f < fValue)
    {
        if (fValue < 1.0f)
            return float(asin(fValue));
        else
            return DAT_011a9444;
    }
    else
    {
        return -DAT_011a9444;
    }
}

struct S_00a592c0_Matrix3 {
    float m_afEntries[3][3];

    bool DecomposeToEulerAngles(float& rfXAngle, float& rfYAngle, float& rfZAngle) const;
};

// Extracts X, Y, and Z rotation angles from the 3x3 matrix entries, returning false when the pitch is at a gimbal lock limit.
// @fnv 0x00a592c0
bool S_00a592c0_Matrix3::DecomposeToEulerAngles(float& rfXAngle, float& rfYAngle, float& rfZAngle) const
{
    rfYAngle = -S_00a592c0_ASin(m_afEntries[0][2]);
    if (rfYAngle < DAT_011a9444)
    {
        if (rfYAngle > -DAT_011a9444)
        {
            rfXAngle = -FUN_00a811f0(-m_afEntries[1][2], m_afEntries[2][2]);
            rfZAngle = -FUN_00a811f0(-m_afEntries[0][1], m_afEntries[0][0]);
            return true;
        }
        else
        {
            float fRmY = FUN_00a811f0(m_afEntries[1][0], m_afEntries[1][1]);
            rfZAngle = 0.0f;
            rfXAngle = fRmY - rfZAngle;
            return false;
        }
    }
    else
    {
        float fRpY = FUN_00a811f0(m_afEntries[1][0], m_afEntries[1][1]);
        rfZAngle = 0.0f;
        rfXAngle = rfZAngle - fRpY;
        return false;
    }
}

struct Matrix161 {
    float entry[3][3];

    Matrix161* FUN_0043f8d0(Matrix161* result, const Matrix161* other) const;
    void FUN_00a59540(float xAngle, float yAngle, float zAngle);
};

// @fnv 0x00a59540
void Matrix161::FUN_00a59540(float xAngle, float yAngle, float zAngle)
{
    Matrix161 rotations[3];
    float sine, cosine;
    fnv_SinCos(xAngle, sine, cosine);

    Matrix161& x = rotations[2];
    x.entry[0][0] = 1.0f;
    x.entry[0][1] = 0.0f;
    x.entry[0][2] = 0.0f;
    x.entry[1][0] = 0.0f;
    x.entry[1][1] = cosine;
    x.entry[1][2] = sine;
    x.entry[2][0] = 0.0f;
    x.entry[2][1] = -sine;
    x.entry[2][2] = cosine;

    fnv_SinCos(yAngle, sine, cosine);

    Matrix161& y = rotations[0];
    y.entry[0][0] = cosine;
    y.entry[0][1] = 0.0f;
    y.entry[0][2] = -sine;
    y.entry[1][0] = 0.0f;
    y.entry[1][1] = 1.0f;
    y.entry[1][2] = 0.0f;
    y.entry[2][0] = sine;
    y.entry[2][1] = 0.0f;
    y.entry[2][2] = cosine;

    fnv_SinCos(zAngle, sine, cosine);

    Matrix161& z = rotations[1];
    z.entry[0][0] = cosine;
    z.entry[0][1] = sine;
    z.entry[0][2] = 0.0f;
    z.entry[1][0] = -sine;
    z.entry[1][1] = cosine;
    z.entry[1][2] = 0.0f;
    z.entry[2][0] = 0.0f;
    z.entry[2][1] = 0.0f;
    z.entry[2][2] = 1.0f;

    Matrix161 temporary;
    Matrix161* yz = y.FUN_0043f8d0(&temporary, &z);
    *this = *x.FUN_0043f8d0(&y, yz);
}

struct ThreeByThreeMatrix {
    float m[9];
    ThreeByThreeMatrix() {}
    ThreeByThreeMatrix(float a, float b, float c, float d, float e, float f, float g, float h, float i)
    {
        m[0] = a; m[1] = b; m[2] = c;
        m[3] = d; m[4] = e; m[5] = f;
        m[6] = g; m[7] = h; m[8] = i;
    }
    ThreeByThreeMatrix FUN_0043f8d0(const ThreeByThreeMatrix& r) const;
    void FUN_00a59780(float fZ, float fY, float fX);
};

// @fnv 0x00a59780
void ThreeByThreeMatrix::FUN_00a59780(float fZ, float fY, float fX)
{
    float c,s;
    fnv_SinCos(fX,s,c);
    ThreeByThreeMatrix kX(1.0f, 0.0f, 0.0f, 0.0f, c, s, 0.0f, -s, c);
    fnv_SinCos(fY,s,c);
    ThreeByThreeMatrix kY(c, 0.0f, -s, 0.0f, 1.0f, 0.0f, s, 0.0f, c);
    fnv_SinCos(fZ,s,c);
    ThreeByThreeMatrix kZ(c, s, 0.0f, -s, c, 0.0f, 0.0f, 0.0f, 1.0f);
    *this = kZ.FUN_0043f8d0(kY.FUN_0043f8d0(kX));
}


ThreeByThreeMatrix ThreeByThreeMatrix::FUN_0043f8d0(const ThreeByThreeMatrix& r) const
{
    ThreeByThreeMatrix product;
    for(int c=0;c<3;++c)
        for(int row=0;row<3;++row)
            product.m[row*3+c] = m[row*3]*r.m[c] + m[row*3+1]*r.m[3+c] + m[row*3+2]*r.m[6+c];
    return product;
}

#include <string.h>
void* NiMalloc(unsigned int);
int _NiSprintf(char*, unsigned int, const char*, ...);
struct FloatMatrix3 {
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    char* ToString(const char* name);
};
// Formats the 3x3 matrix into a heap-allocated string prefixed by name, using _NiSprintf into a NiMalloc buffer.
// @fnv 0x00a598f0
char* FloatMatrix3::ToString(const char* name) {
    unsigned int size = strlen(name) + 128;
    char* result = static_cast<char*>(NiMalloc(size));
    _NiSprintf(result, size, "%s = ((%g,%g,%g),(%g,%g,%g),(%g,%g,%g))", name,
        m00,m01,m02,m10,m11,m12,m20,m21,m22);
    return result;
}

struct EigenMatrixRow { float first, second, third; };
struct EigenMatrix { float cell[3][3]; bool FUN_00a58b00(float* diagonal, float* subdiagonal); };
static __forceinline void EigenRotate(float& left, float& right, float cosine, float sine)
{
    float oldRight = right;
    right = sine*left + cosine*oldRight;
    left = cosine*left - sine*oldRight;
}




// Iteratively updates the matrix and diagonal and subdiagonal arrays, returning true when both subdiagonal entries are zero.
// @fnv 0x00a58b00
bool EigenMatrix::FUN_00a58b00(float* diagonal, float* subdiagonal)
{
    EigenMatrix* matrix = this;
    float scratch, sine, cosine, sum, difference, discriminant, low, high;
    for (int iteration = 0; iteration < 32; ++iteration)
    {
        sum = (float)fabs(diagonal[0]) + (float)fabs(diagonal[1]);
        if ((float)fabs(subdiagonal[0]) + sum == sum)
        {
            subdiagonal[0] = 0.0f;
            sum = (float)fabs(diagonal[1]) + (float)fabs(diagonal[2]);
            if ((float)fabs(subdiagonal[1]) + sum == sum)
            {
                subdiagonal[1] = 0.0f;
                return true;
            }
            sum = diagonal[2] + diagonal[1];
            difference = diagonal[1] - diagonal[2];
            discriminant = (float)sqrt((float)(difference*difference + 4.0*subdiagonal[1]*subdiagonal[1]));
            low = (float)(0.5*(sum-discriminant));
            high = (float)(0.5*(sum+discriminant));
            if (difference >= 0.0f)
            {
                cosine = subdiagonal[1];
                sine = diagonal[1] - low;
            }
            else
            {
                cosine = diagonal[2] - low;
                sine = subdiagonal[1];
            }
            scratch = 1.0f / (float)sqrt((float)(cosine*cosine + sine*sine));
            cosine *= scratch;
            sine *= scratch;
            
                scratch = matrix->cell[0][2];
                matrix->cell[0][2] = sine*matrix->cell[0][1] + cosine*scratch;
                matrix->cell[0][1] = cosine*matrix->cell[0][1] - sine*scratch;
            
                scratch = matrix->cell[1][2];
                matrix->cell[1][2] = sine*matrix->cell[1][1] + cosine*scratch;
                matrix->cell[1][1] = cosine*matrix->cell[1][1] - sine*scratch;
            
                scratch = matrix->cell[2][2];
                matrix->cell[2][2] = sine*matrix->cell[2][1] + cosine*scratch;
                matrix->cell[2][1] = cosine*matrix->cell[2][1] - sine*scratch;
            
            diagonal[1] = low;
            diagonal[2] = high;
            subdiagonal[1] = 0.0f;
            return true;
        }
        sum = (float)fabs(diagonal[1]) + (float)fabs(diagonal[2]);
        if ((float)fabs(subdiagonal[1]) + sum == sum)
        {
            subdiagonal[1] = 0.0f;
            sum = (float)fabs(diagonal[0]) + (float)fabs(diagonal[1]);
            if ((float)fabs(subdiagonal[0]) + sum == sum)
            {
                subdiagonal[0] = 0.0f;
                return true;
            }
            sum = diagonal[0] + diagonal[1];
            difference = diagonal[0] - diagonal[1];
            discriminant = (float)sqrt((float)(difference*difference + 4.0*subdiagonal[0]*subdiagonal[0]));
            low = (float)(0.5*(sum-discriminant));
            high = (float)(0.5*(sum+discriminant));
            if (difference >= 0.0f)
            {
                cosine = subdiagonal[0];
                sine = diagonal[0] - low;
            }
            else
            {
                cosine = diagonal[1] - low;
                sine = subdiagonal[0];
            }
            scratch = 1.0f / (float)sqrt((float)(cosine*cosine + sine*sine));
            cosine *= scratch;
            sine *= scratch;
            for (int rowIndex = 0; rowIndex < 3; ++rowIndex)
            {
                scratch = matrix->cell[rowIndex][1];
                matrix->cell[rowIndex][1] = sine*matrix->cell[rowIndex][0] + cosine*scratch;
                matrix->cell[rowIndex][0] = cosine*matrix->cell[rowIndex][0] - sine*scratch;
            }
            diagonal[0] = low;
            diagonal[1] = high;
            subdiagonal[0] = 0.0f;
            return true;
        }
        float ratio = (diagonal[1] - diagonal[0]) / (2.0f * subdiagonal[0]);
        float root = (float)sqrt((float)(ratio*ratio + 1.0f));
        float off = subdiagonal[1];
        float shifted = diagonal[2] - diagonal[0];
        if (ratio >= 0.0f)
            shifted += subdiagonal[0] / (ratio + root);
        else
            shifted += subdiagonal[0] / (ratio - root);
        if ((float)fabs(off) >= (float)fabs(shifted))
        {
            ratio = shifted/off;
            sine = 1.0f/(float)sqrt((float)(ratio*ratio+1.0));
            cosine = ratio*sine;
        }
        else
        {
            ratio = off/shifted;
            cosine = 1.0f/(float)sqrt((float)(ratio*ratio+1.0));
            sine = ratio*cosine;
        }
        for (int rowIndex = 0; rowIndex < 3; ++rowIndex)
        {
            scratch = matrix->cell[rowIndex][2];
            matrix->cell[rowIndex][2] = sine*matrix->cell[rowIndex][1] + cosine*scratch;
            matrix->cell[rowIndex][1] = cosine*matrix->cell[rowIndex][1] - sine*scratch;
        }
        float update = (diagonal[1]-diagonal[2])*sine + (2.0f*subdiagonal[1])*cosine;
        float coupled = cosine*subdiagonal[0];
        off = sine*subdiagonal[0];
        shifted = cosine*update-subdiagonal[1];
        update *= sine;
        if ((float)fabs(off) >= (float)fabs(shifted))
        {
            ratio = shifted/off;
            root = (float)sqrt((float)(ratio*ratio+1.0f));
            subdiagonal[1] = off*root;
            sine = 1.0f/root;
            cosine = ratio*sine;
        }
        else
        {
            ratio = off/shifted;
            root = (float)sqrt((float)(ratio*ratio+1.0f));
            subdiagonal[1] = shifted*root;
            cosine = 1.0f/root;
            sine = ratio*cosine;
        }
        
            scratch = matrix->cell[0][1];
            matrix->cell[0][1] = sine*matrix->cell[0][0] + cosine*scratch;
            matrix->cell[0][0] = cosine*matrix->cell[0][0] - sine*scratch;
        
            scratch = matrix->cell[1][1];
            matrix->cell[1][1] = sine*matrix->cell[1][0] + cosine*scratch;
            matrix->cell[1][0] = cosine*matrix->cell[1][0] - sine*scratch;
        
            scratch = matrix->cell[2][1];
            matrix->cell[2][1] = sine*matrix->cell[2][0] + cosine*scratch;
            matrix->cell[2][0] = cosine*matrix->cell[2][0] - sine*scratch;
        
        float middle = diagonal[1] - update;
        diagonal[2] += update;
        update = (diagonal[0]-middle)*sine + (2.0f*coupled)*cosine;
        subdiagonal[0] = cosine*update-coupled;
        update *= sine;
        diagonal[1] = middle+update;
        diagonal[0] -= update;
    }
    return false;
}
