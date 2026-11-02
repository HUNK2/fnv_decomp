// fallout/misc/seendata_decls.h: declares BGSLoadFormBuffer, NiPoint3, SeenData, IntSeenData
#ifndef FNV_SEENDATA_DECLS_H
#define FNV_SEENDATA_DECLS_H


class BGSLoadFormBuffer
{
  public:
    void ReadTypedData(void* data, unsigned int size);
    int ReadElementCount();
};

class NiPoint3
{
  public:
    float x;
    float y;
    float z;

    NiPoint3(float x, float y, float z);
};

class SeenData
{
  public:
    void** m_ppVirtualMethodTable;
    unsigned int m_uiSeenData[8];

    void LoadGame(BGSLoadFormBuffer* buffer);
    static void GetPositionForIndex(unsigned int index, NiPoint3& position);
};

class IntSeenData : public SeenData
{
  public:
    char m_cFirstByte;
    char m_cFollowingByte;
    unsigned short layoutPadding26;
    IntSeenData* m_pNext;

    IntSeenData();
    IntSeenData(char x, char y);
    void LoadGame(BGSLoadFormBuffer* buffer);
};

extern void* DAT_01083fc4;
extern unsigned int DAT_011a31ec;
extern float DAT_011a31e8;
extern "C" void* __cdecl memset(void* destination, int value, unsigned int size);

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* pointer);

#endif
