// fallout_shared/tesidleform.h: declares TESIdleForm
#ifndef TESIDLEFORM_H
#define TESIDLEFORM_H

#include "tesidleform_decls.h"
class TESIdleForm
{
  public:
    unsigned char storage[64];
    NiFormArray* m_pParentPath;
    NiFormArray* AssignParentPath();
};
// @fnv 0x005fe770
NiFormArray* TESIdleForm::AssignParentPath()
{
    return m_pParentPath ? m_pParentPath : (m_pParentPath = new NiFormArray);
}
#endif
