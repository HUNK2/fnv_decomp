// fallout_shared/pathfinding/pathingsolution_load_decls.h: declares BGSLoadFormBuffer
#ifndef FNV_PATHINGSOLUTION_LOAD_DECLS_H
#define FNV_PATHINGSOLUTION_LOAD_DECLS_H


class BGSLoadFormBuffer
{
  public:
    void** m_ppVirtualMethodTable;
    void ReadTypedData(void*, unsigned int);
    int ReadElementCount();
    bool ReadFormIdentifier(void*);
};

#endif
