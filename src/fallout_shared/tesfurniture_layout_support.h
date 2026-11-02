// fallout_shared/tesfurniture_layout_support.h: declares TESFile, TESFileFormVersion, TESFullNameLoader
#ifndef FNV_LAYOUT_SUPPORT_H
#define FNV_LAYOUT_SUPPORT_H
#include <stddef.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
FNV_STATIC_ASSERT(sizeof(void*) == 4);
FNV_STATIC_ASSERT(sizeof(long) == 4);
class Script;
class Actor;
class EffectSetting;
class TESForm;
class TESFile;
class TESFaction;
class TESObjectREFR;
class MediaSet;
class MediaLocationController;
class NiNode;
class TESSound;
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    ~BSSimpleList();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    void RemoveAll();
    void RemoveHead();
    void Remove(const T& item);
    void AddTail(const T& item);
    void AddHead(T& item);
    void SetItem(const T& item);
};
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT();
    ~BSStringT();
    bool Set(const T* text, unsigned int length);
    const T* String();
};
FNV_STATIC_ASSERT(sizeof(BSSimpleList<void*>) == 8);
FNV_STATIC_ASSERT(sizeof(BSStringT<char>) == 8);
enum ENUM_FORM_ID
{
    ENUM_FORM_ID_NO_FORM = 0,
    ENUM_FORM_ID_TES4_ID = 1,
    ENUM_FORM_ID_GRUP_ID = 2,
    ENUM_FORM_ID_GMST_ID = 3,
    ENUM_FORM_ID_TXST_ID = 4,
    ENUM_FORM_ID_MICN_ID = 5,
    ENUM_FORM_ID_GLOB_ID = 6,
    ENUM_FORM_ID_CLAS_ID = 7,
    ENUM_FORM_ID_FACT_ID = 8,
    ENUM_FORM_ID_HDPT_ID = 9,
    ENUM_FORM_ID_HAIR_ID = 10,
    ENUM_FORM_ID_EYES_ID = 11,
    ENUM_FORM_ID_RACE_ID = 12,
    ENUM_FORM_ID_SOUN_ID = 13,
    ENUM_FORM_ID_ASPC_ID = 14,
    ENUM_FORM_ID_SKIL_ID = 15,
    ENUM_FORM_ID_MGEF_ID = 16,
    ENUM_FORM_ID_SCPT_ID = 17,
    ENUM_FORM_ID_LTEX_ID = 18,
    ENUM_FORM_ID_ENCH_ID = 19,
    ENUM_FORM_ID_SPEL_ID = 20,
    ENUM_FORM_ID_ACTI_ID = 21,
    ENUM_FORM_ID_TACT_ID = 22,
    ENUM_FORM_ID_TERM_ID = 23,
    ENUM_FORM_ID_ARMO_ID = 24,
    ENUM_FORM_ID_BOOK_ID = 25,
    ENUM_FORM_ID_CLOT_ID = 26,
    ENUM_FORM_ID_CONT_ID = 27,
    ENUM_FORM_ID_DOOR_ID = 28,
    ENUM_FORM_ID_INGR_ID = 29,
    ENUM_FORM_ID_LIGH_ID = 30,
    ENUM_FORM_ID_MISC_ID = 31,
    ENUM_FORM_ID_STAT_ID = 32,
    ENUM_FORM_ID_SCOL_ID = 33,
    ENUM_FORM_ID_MSTT_ID = 34,
    ENUM_FORM_ID_PWAT_ID = 35,
    ENUM_FORM_ID_GRAS_ID = 36,
    ENUM_FORM_ID_TREE_ID = 37,
    ENUM_FORM_ID_FLOR_ID = 38,
    ENUM_FORM_ID_FURN_ID = 39,
    ENUM_FORM_ID_WEAP_ID = 40,
    ENUM_FORM_ID_AMMO_ID = 41,
    ENUM_FORM_ID_NPC__ID = 42,
    ENUM_FORM_ID_CREA_ID = 43,
    ENUM_FORM_ID_LVLC_ID = 44,
    ENUM_FORM_ID_LVLN_ID = 45,
    ENUM_FORM_ID_KEYM_ID = 46,
    ENUM_FORM_ID_ALCH_ID = 47,
    ENUM_FORM_ID_IDLM_ID = 48,
    ENUM_FORM_ID_NOTE_ID = 49,
    ENUM_FORM_ID_COBJ_ID = 50,
    ENUM_FORM_ID_PROJ_ID = 51,
    ENUM_FORM_ID_LVLI_ID = 52,
    ENUM_FORM_ID_WTHR_ID = 53,
    ENUM_FORM_ID_CLMT_ID = 54,
    ENUM_FORM_ID_REGN_ID = 55,
    ENUM_FORM_ID_NAVI_ID = 56,
    ENUM_FORM_ID_CELL_ID = 57,
    ENUM_FORM_ID_REFR_ID = 58,
    ENUM_FORM_ID_ACHR_ID = 59,
    ENUM_FORM_ID_ACRE_ID = 60,
    ENUM_FORM_ID_PMIS_ID = 61,
    ENUM_FORM_ID_PGRE_ID = 62,
    ENUM_FORM_ID_PBEA_ID = 63,
    ENUM_FORM_ID_PFLA_ID = 64,
    ENUM_FORM_ID_WRLD_ID = 65,
    ENUM_FORM_ID_LAND_ID = 66,
    ENUM_FORM_ID_NAVM_ID = 67,
    ENUM_FORM_ID_TLOD_ID = 68,
    ENUM_FORM_ID_DIAL_ID = 69,
    ENUM_FORM_ID_INFO_ID = 70,
    ENUM_FORM_ID_QUST_ID = 71,
    ENUM_FORM_ID_IDLE_ID = 72,
    ENUM_FORM_ID_PACK_ID = 73,
    ENUM_FORM_ID_CSTY_ID = 74,
    ENUM_FORM_ID_LSCR_ID = 75,
    ENUM_FORM_ID_LVSP_ID = 76,
    ENUM_FORM_ID_ANIO_ID = 77,
    ENUM_FORM_ID_WATR_ID = 78,
    ENUM_FORM_ID_EFSH_ID = 79,
    ENUM_FORM_ID_TOFT_ID = 80,
    ENUM_FORM_ID_EXPL_ID = 81,
    ENUM_FORM_ID_DEBR_ID = 82,
    ENUM_FORM_ID_IMGS_ID = 83,
    ENUM_FORM_ID_IMAD_ID = 84,
    ENUM_FORM_ID_FLST_ID = 85,
    ENUM_FORM_ID_PERK_ID = 86,
    ENUM_FORM_ID_BPTD_ID = 87,
    ENUM_FORM_ID_ADDN_ID = 88,
    ENUM_FORM_ID_AVIF_ID = 89,
    ENUM_FORM_ID_RADS_ID = 90,
    ENUM_FORM_ID_CAMS_ID = 91,
    ENUM_FORM_ID_CPTH_ID = 92,
    ENUM_FORM_ID_VTYP_ID = 93,
    ENUM_FORM_ID_IPCT_ID = 94,
    ENUM_FORM_ID_IPDS_ID = 95,
    ENUM_FORM_ID_ARMA_ID = 96,
    ENUM_FORM_ID_ECZN_ID = 97,
    ENUM_FORM_ID_MESG_ID = 98,
    ENUM_FORM_ID_RGDL_ID = 99,
    ENUM_FORM_ID_DOBJ_ID = 100,
    ENUM_FORM_ID_LGTM_ID = 101,
    ENUM_FORM_ID_MUSC_ID = 102,
    ENUM_FORM_ID_IMOD_ID = 103,
    ENUM_FORM_ID_REPU_ID = 104,
    ENUM_FORM_ID_PCBE_ID = 105,
    ENUM_FORM_ID_RCPE_ID = 106,
    ENUM_FORM_ID_RCCT_ID = 107,
    ENUM_FORM_ID_CHIP_ID = 108,
    ENUM_FORM_ID_CSNO_ID = 109,
    ENUM_FORM_ID_LSCT_ID = 110,
    ENUM_FORM_ID_MSET_ID = 111,
    ENUM_FORM_ID_ALOC_ID = 112,
    ENUM_FORM_ID_CHAL_ID = 113,
    ENUM_FORM_ID_AMEF_ID = 114,
    ENUM_FORM_ID_CCRD_ID = 115,
    ENUM_FORM_ID_CMNY_ID = 116,
    ENUM_FORM_ID_CDCK_ID = 117,
    ENUM_FORM_ID_DEHY_ID = 118,
    ENUM_FORM_ID_HUNG_ID = 119,
    ENUM_FORM_ID_SLPD_ID = 120,
    ENUM_FORM_ID_FORM_ID_COUNT = 121,
};

class TESFile
{
  public:
    unsigned char GetTESForm();
    unsigned int GetChunkID();
    unsigned int GetChunkSize();
    bool IsEndianConversionRequired();
    bool GetChunkData(void* apData, unsigned int auiSize);
    bool GetChunkData(unsigned int* apData);
    bool NextChunk();
};
class TESFileFormVersion : public TESFile
{
  public:
    unsigned short GetFormVersion();
};
class TESFullName;
class TESFullNameLoader
{
  public:
    static void LoadFullNameChunk(TESFullName* apName, TESFile* apFile);
};
extern "C" void* __cdecl _alloca(size_t auiBytes);
enum CHUNK_ID
{
    CHUNK_ID_MODL_ID = 0x4c444f4d,
    CHUNK_ID_MODD_ID = 0x44444f4d,
    CHUNK_ID_MODT_ID = 0x54444f4d,
    CHUNK_ID_MOSD_ID = 0x44534f4d,
    CHUNK_ID_MODS_ID = 0x53444f4d,
    CHUNK_ID_SCRI_ID = 0x49524353,
    CHUNK_ID_DEST_ID = 0x54534544,
    CHUNK_ID_DSTD_ID = 0x44545344,
    CHUNK_ID_MNAM_ID = 0x4d414e4d,
    CHUNK_ID_EDID_ID = 0x44494445,
    CHUNK_ID_OBND_ID = 0x444e424f,
    CHUNK_ID_FULL_ID = 0x4c4c5546,
    CHUNK_ID_NAM1_ID = 0x314d414e,
    CHUNK_ID_NAM2_ID = 0x324d414e,
    CHUNK_ID_NAM3_ID = 0x334d414e,
    CHUNK_ID_NAM4_ID = 0x344d414e,
    CHUNK_ID_NAM5_ID = 0x354d414e,
    CHUNK_ID_NAM6_ID = 0x364d414e,
    CHUNK_ID_NAM7_ID = 0x374d414e,
    CHUNK_ID_HNAM_ID = 0x4d414e48,
    CHUNK_ID_ZNAM_ID = 0x4d414e5a,
    CHUNK_ID_XNAM_ID = 0x4d414e58,
    CHUNK_ID_YNAM_ID = 0x4d414e59,
    CHUNK_ID_LNAM_ID = 0x4d414e4c,
    CHUNK_ID_GNAM_ID = 0x4d414e47,
    CHUNK_ID_SNAM_ID = 0x4d414e53,
    CHUNK_ID_FNAM_ID = 0x4d414e46
};
#endif
