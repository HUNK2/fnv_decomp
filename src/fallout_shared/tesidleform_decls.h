// fallout_shared/tesidleform_decls.h: declares NiFormArray
#ifndef TESIDLEFORM_DECLS_H
#define TESIDLEFORM_DECLS_H
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);
class NiFormArray
{
  public:
    unsigned char storage[24];
    NiFormArray();
};
#endif
