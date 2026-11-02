// fallout_shared/modelloader_decls.h: declares QueuedFileLoad, QueuedReference
#ifndef MODELLOADER_DECLS_H
#define MODELLOADER_DECLS_H

class QueuedFileLoad
{
  public:
    unsigned char padding[0x34];
    unsigned char fileIndex;
    unsigned char GetFileIndex();
};
class QueuedReference
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    void ProcessLoadedAnimIdle();
};
#endif
namespace std {
template <class T> struct char_traits;
template <class T> class allocator;
template <class T, class Traits, class Alloc> class basic_string
{
  public:
    unsigned char layout[24];
    unsigned int capacity;
    basic_string& assign(const T*, unsigned int);
    basic_string& assign(const basic_string&, unsigned int, unsigned int);
    bool _Inside(const T*);
    bool _Grow(unsigned int, bool);
    T* _Myptr();
    void _Eos(unsigned int);
};
}
void FUN_0044ccd0(char*, unsigned int, const char*, unsigned int);
