// sdk/facegen/matrixvt_decls.h: declares FaceGenCoordinateValue, FR2MatrixVTCData, FaceGenCoordinateBasis
#ifndef ARMY_LUNA_2061_MATRIXVT_DECLS_H
#define ARMY_LUNA_2061_MATRIXVT_DECLS_H


#include "matrixvt_types_FR2MatrixVTC_float_.h"
struct FaceGenCoordinateValue
{
  public:
    unsigned int value;
    unsigned int layoutPadding;
    const float* FUN_00629ab0();
};

class FR2MatrixVTCData
{
  public:
    float* first;
    float* last;
    float* end;
    unsigned int layoutPadding0;
    unsigned int layoutPadding1;
    unsigned int layoutPadding2;
    void SetElementCount(unsigned int count);
};

class FaceGenCoordinateBasis
{
  public:
    FaceGenCoordinateValue FUN_0060b370(unsigned int row, unsigned int col);
};

template <class T> class FaceGenMatrix;

template <> class FaceGenMatrix<float> : public FaceGenCoordinateBasis
{
  public:
    FR2MatrixVTCData data;
    unsigned int m_uiRowCount;
    unsigned int m_uiColumnCount;

    FaceGenMatrix(unsigned int rows, unsigned int cols);
    FaceGenMatrix(const FaceGenMatrix<float>& rhs);
    ~FaceGenMatrix();

    FaceGenMatrix<float>& operator=(const FaceGenMatrix<float>& rhs);
    FaceGenMatrix<float> operator*(const FaceGenMatrix<float>& rhs);
    float GetTrace();

    float* FUN_006578b0(unsigned int index) const;
    void FUN_00658f30(const FaceGenMatrix<float>& rhs);
};

void __cdecl ReportAssertionViolation(const char* file, unsigned int line);
float __cdecl SquareFloat(float value);

#endif
