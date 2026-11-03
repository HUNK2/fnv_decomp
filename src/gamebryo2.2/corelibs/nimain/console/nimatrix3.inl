
#include "nimatrix3_decls.h"

// @fnv 0x00476930
void ThreeByThreeMatrix::GetRow(unsigned int row, NiPoint3& point)
{
    point.x = *(float*)((char*)m_afEntries + row * 12);
    point.y = *(float*)((char*)m_afEntries + row * 12 + 4);
    point.z = *(float*)((char*)m_afEntries + row * 12 + 8);
}

// @fnv 0x004D9AE0
bool ThreeByThreeMatrix::operator==(const ThreeByThreeMatrix& matrix) const
{
    return m_afEntries[0] == matrix.m_afEntries[0]
        && m_afEntries[1] == matrix.m_afEntries[1]
        && m_afEntries[2] == matrix.m_afEntries[2]
        && m_afEntries[3] == matrix.m_afEntries[3]
        && m_afEntries[4] == matrix.m_afEntries[4]
        && m_afEntries[5] == matrix.m_afEntries[5]
        && m_afEntries[6] == matrix.m_afEntries[6]
        && m_afEntries[7] == matrix.m_afEntries[7]
        && m_afEntries[8] == matrix.m_afEntries[8];
}

// @fnv 0x0043F8D0
ThreeByThreeMatrix ThreeByThreeMatrix::operator+(const ThreeByThreeMatrix& matrix) const
{
    ThreeByThreeMatrix result;
   
    result.m_afEntries[0] = m_afEntries[0] * matrix.m_afEntries[0] + m_afEntries[1] * matrix.m_afEntries[3] + m_afEntries[2] * matrix.m_afEntries[6];
    result.m_afEntries[3] = m_afEntries[3] * matrix.m_afEntries[0] + m_afEntries[4] * matrix.m_afEntries[3] + m_afEntries[5] * matrix.m_afEntries[6];
    result.m_afEntries[6] = m_afEntries[6] * matrix.m_afEntries[0] + m_afEntries[7] * matrix.m_afEntries[3] + m_afEntries[8] * matrix.m_afEntries[6];
    result.m_afEntries[1] = m_afEntries[0] * matrix.m_afEntries[1] + m_afEntries[1] * matrix.m_afEntries[4] + m_afEntries[2] * matrix.m_afEntries[7];
    result.m_afEntries[4] = m_afEntries[3] * matrix.m_afEntries[1] + m_afEntries[4] * matrix.m_afEntries[4] + m_afEntries[5] * matrix.m_afEntries[7];
    result.m_afEntries[7] = m_afEntries[6] * matrix.m_afEntries[1] + m_afEntries[7] * matrix.m_afEntries[4] + m_afEntries[8] * matrix.m_afEntries[7];
    result.m_afEntries[2] = m_afEntries[0] * matrix.m_afEntries[2] + m_afEntries[1] * matrix.m_afEntries[5] + m_afEntries[2] * matrix.m_afEntries[8];
    result.m_afEntries[5] = m_afEntries[3] * matrix.m_afEntries[2] + m_afEntries[4] * matrix.m_afEntries[5] + m_afEntries[5] * matrix.m_afEntries[8];
    result.m_afEntries[8] = m_afEntries[6] * matrix.m_afEntries[2] + m_afEntries[7] * matrix.m_afEntries[5] + m_afEntries[8] * matrix.m_afEntries[8];
    return result;
}

#pragma optimize("gty", on)
// @fnv 0x00A69970
NiPlane::NiPlane(const NiPoint3& n,float c) : normal(n), constant(c) {}

#pragma optimize("", off)

// @fnv 0x006404B0
void NiAVObject::SetLocalRotation(float angle,float x,float y,float z) { rotation.MakeAxisAngleRotation(angle,x,y,z); }

// @fnv 0x0045BBA0
NiPoint3 NiAVObject::GetWorldTranslation() {
 NiPoint3 result;

 worldRotation.NiMatrix3_GetCol(0,result);
 return result;
}

// @fnv 0x004768C0
ThreeByThreeMatrix ThreeByThreeMatrix::Transpose() {
 NiPoint3 rows[3];
 GetRow(0,rows[0]); GetRow(1,rows[1]); GetRow(2,rows[2]);
 return ThreeByThreeMatrix(rows[0],rows[1],rows[2]);
}

// @fnv 0x0043F850
void ThreeByThreeMatrix::SetYRotation(float angle) {
 float s,c;
 FUN_004169a0(angle,s,c);
 m_afEntries[0]=c; m_afEntries[1]=0.0f; m_afEntries[2]=-s;
 m_afEntries[3]=0.0f; m_afEntries[4]=1.0f; m_afEntries[5]=0.0f;
 m_afEntries[6]=s; m_afEntries[7]=0.0f; m_afEntries[8]=c;
}

// @fnv 0x0062C250
NiTransform NiTransform::operator*(const NiTransform& other) const {
 NiTransform result;
 result.scale=scale*other.scale;
 result.rotation=rotation*other.rotation;
 result.translation=translation+NiPosData::ComputePositionAtTime(scale,rotation*other.translation);
 return result;
}

// @fnv 0x004168A0
void ThreeByThreeMatrix::MakeAxisAngleRotation(float angle,float x,float y,float z) {
 struct {float omc,xy,ys,xz,zs,z2,yz,xs,c,s,x2,y2;} v;
 FUN_004169a0(angle,v.s,v.c);
 v.omc=1.0f-v.c;
 v.x2=x*x; v.y2=y*y; v.z2=z*z;
 v.xy=x*y*v.omc; v.xz=x*z*v.omc; v.yz=y*z*v.omc;
 v.xs=x*v.s; v.ys=y*v.s; v.zs=z*v.s;
 m_afEntries[0]=v.x2*v.omc+v.c;
 m_afEntries[1]=v.xy+v.zs; m_afEntries[2]=v.xz-v.ys;
 m_afEntries[3]=v.xy-v.zs; m_afEntries[4]=v.y2*v.omc+v.c; m_afEntries[5]=v.yz+v.xs;
 m_afEntries[6]=v.xz+v.ys; m_afEntries[7]=v.yz-v.xs; m_afEntries[8]=v.z2*v.omc+v.c;
}

// @fnv 0x004B46A0
bool ThreeByThreeMatrix::Inverse(ThreeByThreeMatrix& out) {
 struct { int col,row; float det,inv; } v;
 out.m_afEntries[0]=m_afEntries[4]*m_afEntries[8]-m_afEntries[5]*m_afEntries[7];
 out.m_afEntries[1]=m_afEntries[2]*m_afEntries[7]-m_afEntries[1]*m_afEntries[8];
 out.m_afEntries[2]=m_afEntries[1]*m_afEntries[5]-m_afEntries[2]*m_afEntries[4];
 out.m_afEntries[3]=m_afEntries[5]*m_afEntries[6]-m_afEntries[3]*m_afEntries[8];
 out.m_afEntries[4]=m_afEntries[0]*m_afEntries[8]-m_afEntries[2]*m_afEntries[6];
 out.m_afEntries[5]=m_afEntries[2]*m_afEntries[3]-m_afEntries[0]*m_afEntries[5];
 out.m_afEntries[6]=m_afEntries[3]*m_afEntries[7]-m_afEntries[4]*m_afEntries[6];
 out.m_afEntries[7]=m_afEntries[1]*m_afEntries[6]-m_afEntries[0]*m_afEntries[7];
 out.m_afEntries[8]=m_afEntries[0]*m_afEntries[4]-m_afEntries[1]*m_afEntries[3];
 v.det=m_afEntries[0]*out.m_afEntries[0]+m_afEntries[1]*out.m_afEntries[3]+m_afEntries[2]*out.m_afEntries[6];
 if(FUN_00408820(v.det)<=DAT_01017cf8) return false;
 v.inv=1.0f/v.det;
 for(v.row=0;v.row<3;v.row++)
  for(v.col=0;v.col<3;v.col++)
   ((float(*)[3])out.m_afEntries)[v.row][v.col]*=v.inv;
 return true;
}
