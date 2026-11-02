// bshavok/bhkunaryaction.h: declares bhkUnaryAction
#ifndef FNV_BHKUNARYACTION_H
#define FNV_BHKUNARYACTION_H
#include <xmmintrin.h>
class bhkUnaryAction
{
  public:
    __m128 value;
    void Set(float x, float y, float z, float w);
};
// @fnv 0x004b4d50
void bhkUnaryAction::Set(float x, float y, float z, float w)
{
    value = _mm_setr_ps(x, y, z, w);
}
#endif
