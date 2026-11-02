// bsmain/iomanager_decls.h: declares IOManager, IOTask
#ifndef IOMANAGER_DECLS_H
#define IOMANAGER_DECLS_H

class IOManager
{
  public:
    void SubmitTask();
    void FUN_0043d6b0(IOManager* task);
};
extern IOManager* DAT_01202d98;
class IOTask
{
  public:
    void GenerateKey();
    unsigned short FUN_0043dc10();
    unsigned char GetPriority();
    unsigned int InitScriptRunLockTask();
    void SetKey(char, unsigned int, unsigned char, unsigned short);
};
#endif
