#ifndef BSFACEGENMORPHDATA_DECLS_H
#define BSFACEGENMORPHDATA_DECLS_H

void* __cdecl operator new(unsigned int);
void* __cdecl operator new[](unsigned int);
void __cdecl operator delete(void*);
extern "C" void* __cdecl memset(void*, int, unsigned int);
int __cdecl FUN_00404dc0(const char*, const char*);
const char* __cdecl PrepareScriptMessage(const char*, bool);
int __cdecl Warning(const char*, ...);
const char* __cdecl FUN_005dd830(unsigned int);
const char* __cdecl FUN_005dd840(unsigned int);
const char* __cdecl FUN_005dd850(unsigned int);
const char* __cdecl FUN_00661da0(unsigned int);
extern const char DAT_01065e40[];
extern const char DAT_01065dd0[];
extern const char DAT_01065d60[];
extern const char DAT_01065ce8[];
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3(float, float, float);
};
class BGSPerkEntry;
template <class T> class BSSimpleList;
template <> class BSSimpleList<BGSPerkEntry*>
{
  public:
    BSSimpleList* GetNext();
};
class BSFaceGenMorph
{
  public:
    virtual ~BSFaceGenMorph();
    unsigned int data[2];
};
class BSFaceGenMorphDifferential : public BSFaceGenMorph
{
  public:
    BSFaceGenMorphDifferential(unsigned int);
};
class BSFaceGenMorphStatistical : public BSFaceGenMorph
{
  public:
    unsigned int extra;
    BSFaceGenMorphStatistical(unsigned int, unsigned int);
};
template <class T> class FaceGenMatrix
{
  public:
    T* FUN_006578b0(unsigned int) const;
    unsigned int FUN_00662820();
    unsigned int data[4];
};
class MorphName
{
  public:
    const char* FUN_0044a560();
    unsigned int data[7];
};
class FaceGenTriData;
class DifferentialEntry : public MorphName
{
  public:
    unsigned int vertexData;
};
class StatisticalEntry : public MorphName
{
  public:
    unsigned int columns;
    FaceGenMatrix<float> matrix;
};
class DifferentialArray
{
  public:
    unsigned int GetEntryCount();
    DifferentialEntry* FUN_00662860(unsigned int);
    unsigned int data[6];
};
class StatisticalArray
{
  public:
    unsigned int FUN_0065cc30();
    StatisticalEntry* FUN_00662890(unsigned int);
    unsigned int data[6];
};
class FaceGenTriData
{
  public:
    unsigned char prefix[0xc0];
    DifferentialArray differential;
    StatisticalArray statistical;
    unsigned int FUN_0065c700();
    NiPoint3& FUN_0065c720(unsigned int);
};
class BSFaceGenMorphData
{
  public:
    BSFaceGenMorphData();
    virtual ~BSFaceGenMorphData();
    unsigned int ref;
};
class BSFaceGenMorphDataHead : public BSFaceGenMorphData
{
  public:
    BSFaceGenMorph** expressions;
    BSFaceGenMorph** modifiers;
    BSFaceGenMorph** phonemes;
    BSFaceGenMorph** custom;
    BSFaceGenMorphDataHead(FaceGenTriData*);
    virtual ~BSFaceGenMorphDataHead();
};
#endif
