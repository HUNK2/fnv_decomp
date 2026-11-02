// Names of nested/template specializations use the canonical generator identifier mapping.
#ifndef FNV_FR2MATRIXVTC_FLOAT_H
#define FNV_FR2MATRIXVTC_FLOAT_H

#include "layout_support.h"
class FR2MatrixVTC_float_;
class std___Allocator_base_float_;
class std___Container_base0;
class std___Vector_val_float_std__allocator_float___;
class std__allocator_float_;
class std__vector_float_std__allocator_float___;
#pragma pack(push, 4)
class std___Container_base0
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(std___Container_base0) == 1);
#pragma pack(push, 4)
class std___Allocator_base_float_
{
  public:
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(std___Allocator_base_float_) == 1);
#pragma pack(push, 4)
class std__allocator_float_ : public std___Allocator_base_float_
{
  public:
    // base std::_Allocator_base<float> at +0x0, size 1
    // address
    // allocator<float>
    // void __cdecl std::allocator<float>::*(float*, unsigned int)
    // allocate
    // construct
    // void __cdecl std::allocator<float>::*(float*)
    // unsigned int __cdecl std::allocator<float>::*()
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(std__allocator_float_) == 1);
#pragma pack(push, 4)
class std___Vector_val_float_std__allocator_float___ : public std___Container_base0
{
  public:
    float* _Myfirst;               // +0x0, 4 bytes
    float* _Mylast;                // +0x4, 4 bytes
    float* _Myend;                 // +0x8, 4 bytes
    std__allocator_float_ _Alval;  // +0xC, 1 bytes
    unsigned char layoutPaddingD[3];
    // _Vector_val<float,std::allocator<float> >
    // void __cdecl std::_Vector_val<float,std::allocator<float> >::*()
    // void __cdecl std::_Vector_val<float,std::allocator<float> >::*()
    // void* __cdecl std::_Vector_val<float,std::allocator<float> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(std___Vector_val_float_std__allocator_float___) == 16);
FNV_STATIC_ASSERT(offsetof(std___Vector_val_float_std__allocator_float___, _Myfirst) == 0);
FNV_STATIC_ASSERT(offsetof(std___Vector_val_float_std__allocator_float___, _Mylast) == 4);
FNV_STATIC_ASSERT(offsetof(std___Vector_val_float_std__allocator_float___, _Myend) == 8);
FNV_STATIC_ASSERT(offsetof(std___Vector_val_float_std__allocator_float___, _Alval) == 12);
#pragma pack(push, 4)
class std__vector_float_std__allocator_float___ : public std___Vector_val_float_std__allocator_float___
{
  public:
    // base std::_Vector_val<float,std::allocator<float> > at +0x0, size 16
    // vector<float,std::allocator<float> >
    // void __cdecl std::vector<float,std::allocator<float> >::*(unsigned int, const float*)
    // operator=
    // void __cdecl std::vector<float,std::allocator<float> >::*(std::vector<float,std::allocator<float> >&&)
    // push_back
    // void __cdecl std::vector<float,std::allocator<float> >::*(float&&)
    // insert
    // swap
    // void __cdecl std::vector<float,std::allocator<float> >::*()
    // void __cdecl std::vector<float,std::allocator<float> >::*(unsigned int)
    // unsigned int __cdecl std::vector<float,std::allocator<float> >::*()
    // begin
    // end
    // std::_Vector_iterator<std::_Vector_val<float,std::allocator<float> > > __cdecl std::vector<float,std::allocator<float> >::*(std::_Vector_const_iterator<std::_Vector_val<float,std::allocator<float> > >)
    // rbegin
    // rend
    // std::_Vector_const_iterator<std::_Vector_val<float,std::allocator<float> > > __cdecl std::vector<float,std::allocator<float> >::*()
    // std::_Vector_const_iterator<std::_Vector_val<float,std::allocator<float> > > __cdecl std::vector<float,std::allocator<float> >::*()
    // std::reverse_iterator<std::_Vector_const_iterator<std::_Vector_val<float,std::allocator<float> > > > __cdecl std::vector<float,std::allocator<float> >::*()
    // std::reverse_iterator<std::_Vector_const_iterator<std::_Vector_val<float,std::allocator<float> > > > __cdecl std::vector<float,std::allocator<float> >::*()
    // void __cdecl std::vector<float,std::allocator<float> >::*()
    // resize
    // unsigned int __cdecl std::vector<float,std::allocator<float> >::*()
    // unsigned int __cdecl std::vector<float,std::allocator<float> >::*()
    // bool __cdecl std::vector<float,std::allocator<float> >::*()
    // std::allocator<float> __cdecl std::vector<float,std::allocator<float> >::*()
    // at
    // operator[]
    // data
    // front
    // back
    // void __cdecl std::vector<float,std::allocator<float> >::*()
    // void __cdecl std::vector<float,std::allocator<float> >::*(unsigned int, const float&)
    // erase
    // void __cdecl std::vector<float,std::allocator<float> >::*()
    // void __cdecl std::vector<float,std::allocator<float> >::*(unsigned int, const float&)
    // bool __cdecl std::vector<float,std::allocator<float> >::*(unsigned int)
    // void __cdecl std::vector<float,std::allocator<float> >::*(float*, float*)
    // unsigned int __cdecl std::vector<float,std::allocator<float> >::*(unsigned int)
    // bool __cdecl std::vector<float,std::allocator<float> >::*(const float*)
    // void __cdecl std::vector<float,std::allocator<float> >::*(unsigned int)
    // void __cdecl std::vector<float,std::allocator<float> >::*()
    // void __cdecl std::vector<float,std::allocator<float> >::*(std::_Vector_const_iterator<std::_Vector_val<float,std::allocator<float> > >, unsigned int, const float&)
    // float* __cdecl std::vector<float,std::allocator<float> >::*(float*, unsigned int, const float*)
    // void __cdecl std::vector<float,std::allocator<float> >::*()
    // void __cdecl std::vector<float,std::allocator<float> >::*()
    // void __cdecl std::vector<float,std::allocator<float> >::*(float*, float*)
    // void* __cdecl std::vector<float,std::allocator<float> >::*(unsigned int)
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(std__vector_float_std__allocator_float___) == 16);
#pragma pack(push, 4)
class FR2MatrixVTC_float_
{
  public:
    std__vector_float_std__allocator_float___ data;  // +0x0, 16 bytes
    unsigned int m_uiRowCount;                       // +0x10, 4 bytes
    unsigned int m_uiColumnCount;                    // +0x14, 4 bytes
    // operator[]
    // operator=
    // operator*
    // operator+
    // operator-
    // operator*=
    // operator+=
    // operator-=
};
#pragma pack(pop)
FNV_STATIC_ASSERT(sizeof(FR2MatrixVTC_float_) == 24);
FNV_STATIC_ASSERT(offsetof(FR2MatrixVTC_float_, data) == 0);
FNV_STATIC_ASSERT(offsetof(FR2MatrixVTC_float_, m_uiRowCount) == 16);
FNV_STATIC_ASSERT(offsetof(FR2MatrixVTC_float_, m_uiColumnCount) == 20);
#endif
