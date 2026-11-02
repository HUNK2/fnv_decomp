// src/staging/blk_00b20000_od_ob1_variant_std_variant.cpp - variant unit created 2026-11-01 for 0x00b31270 (std::vector<int>::vector()): the real VC9 <vector>, which the
// flat stand-in in src/staging/blk_00b20000_od_ob1_variant.cpp cannot give (the constructor unwinds the vector's base classes). Same flags.
#include <vector>

namespace vec_ctor {
struct IntVectorAccess : std::vector<int>
{
    using std::vector<int>::_Buy;
};
class FUN_00b31270 : public std::_Vector_val<int, std::allocator<int> >
{
  public:
    FUN_00b31270();
    int* first;
    int* last;
    int* end;
};
// @fnv 0x00b31270
FUN_00b31270::FUN_00b31270() : std::_Vector_val<int, std::allocator<int> >()
{
    reinterpret_cast<IntVectorAccess*>(this)->_Buy(0);
}
}
