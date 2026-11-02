// Fallout: New Vegas - original source reconstruction.
// Source unit: d:/_fallout3/platforms/common/code/bsmain/bsstream.h
//
// Covered function (MSVC9 SP1 15.00.30729.01, /Od /Oy- /GS /EHsc /Gy):
//   0043cfd0  BSStream::BSStream  (116 bytes)
//
// The compiled translation unit is bsstream_h_unit.cpp, which only includes
// this header. The class introduces its own vftable through the releasing
// destructor, so the constructor's store refers to the BSStream vftable while
// the body calls the out-of-line NiStream base constructor and the out-of-line
// NiPointer<BSNodeReferences> member constructor.
//
// publicly from NiStream (base at +0x0, PC size 0x5c4) and adds the protected
// m_pObjectNameMap (+0x5c4) and m_spNodeReferences (+0x5c8) members.
#ifndef FNV_BSSTREAM_H
#define FNV_BSSTREAM_H


class NiObjectNET;
class BSNodeReferences;

// Shared engine reference-counting pointer. Construction and destruction
// stay out of line; the PC engine bodies are separate functions rather than
// inlined template code, so the member initializer below is a real call to
// ??0?$NiPointer@VBSNodeReferences@@@@QAE@PAVBSNodeReferences@@@Z.
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* pObject = 0);
    ~NiPointer();
};

template <class T> class NiTStringMap;

#pragma pack(push, 4)

// Gamebryo asset stream base. The canonical tree does not carry the engine
// nistream layout yet, so the base is declared here to keep this translation
// unit self-contained, sized to the PC runtime 0x5c4 (which includes the base
// vftable pointer) with its out-of-line constructor; BSStream reuses the
// engine's NiStream constructor body.
class NiStream
{
  public:
    NiStream();
    virtual ~NiStream();

  protected:
    unsigned char layoutPadding[0x5c0];
};

// Stream front end over the engine NiStream base: tracks the object-reference
// map and retains the node-reference root.
class BSStream : public NiStream
{
  public:
    BSStream();
    virtual ~BSStream();

  protected:
    NiTStringMap<NiObjectNET*>* m_pObjectNameMap;    // +0x5c4
    NiPointer<BSNodeReferences> m_spNodeReferences;  // +0x5c8
};

#pragma pack(pop)

// @fnv 0x0043cfd0
BSStream::BSStream() : m_spNodeReferences(0)
{
    m_pObjectNameMap = 0;
}

#endif
