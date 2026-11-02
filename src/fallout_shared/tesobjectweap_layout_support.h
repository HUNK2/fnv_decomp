// Private declarations selected unchanged from the supplied layout_support.h.
// Contains only the templates, enum declarations and checks needed by this unit.
#ifndef FNV_TESOBJECTWEAP_LAYOUT_SUPPORT_H
#define FNV_TESOBJECTWEAP_LAYOUT_SUPPORT_H

#include <stddef.h>
#define FNV_JOIN_IMPL(a, b) a##b
#define FNV_JOIN(a, b) FNV_JOIN_IMPL(a, b)
#define FNV_STATIC_ASSERT(condition) typedef char FNV_JOIN(fnv_static_assert_, __LINE__)[(condition) ? 1 : -1]
FNV_STATIC_ASSERT(sizeof(void*) == 4);
FNV_STATIC_ASSERT(sizeof(long) == 4);
class Script;
class TESFile;
class TESForm;
class TESObjectREFR;
class TESAmmo;
class TESSound;
class SpellItem;
class BGSListForm;
template <class T> class BSSimpleList
{
  public:
    T m_item;
    BSSimpleList<T>* m_pkNext;
    BSSimpleList();
    BSSimpleList(T& item);
    ~BSSimpleList();
    T& GetItem();
    BSSimpleList<T>* GetNext();
    bool IsEmpty();
    void AddTail(T& item);
    void AddHead(T& item);
    void RemoveHead();
    void RemoveAll();
};
template <class T> class BSStringT
{
  public:
    T* pString;
    unsigned short sLen;
    unsigned short sMaxLen;
    BSStringT();
    ~BSStringT();
    const T* String();
    int PrintfString(const char* format, ...);
    bool Set(const T* text, unsigned int length);
    void Init();
    unsigned int MaxLength();
    void SetLength(unsigned int length);
    void SetMaxLength(unsigned int length);
    BSStringT<T>& operator=(const T* text);
};
FNV_STATIC_ASSERT(sizeof(BSSimpleList<void*>) == 8);
FNV_STATIC_ASSERT(sizeof(BSStringT<char>) == 8);
FNV_STATIC_ASSERT(offsetof(BSStringT<char>, pString) == 0);
FNV_STATIC_ASSERT(offsetof(BSStringT<char>, sLen) == 4);
FNV_STATIC_ASSERT(offsetof(BSStringT<char>, sMaxLen) == 6);
namespace ActorValue {
enum Index
{
    ActorValue__Index_AGGRESSION = 0,
    ActorValue__Index_CONFIDENCE = 1,
    ActorValue__Index_ENERGY = 2,
    ActorValue__Index_RESPONSIBILITY = 3,
    ActorValue__Index_MOOD = 4,
    ActorValue__Index_STRENGTH = 5,
    ActorValue__Index_PERCEPTION = 6,
    ActorValue__Index_ENDURANCE = 7,
    ActorValue__Index_CHARISMA = 8,
    ActorValue__Index_INTELLIGENCE = 9,
    ActorValue__Index_AGILITY = 10,
    ActorValue__Index_LUCK = 11,
    ActorValue__Index_ACTION_POINTS = 12,
    ActorValue__Index_CARRY_WEIGHT = 13,
    ActorValue__Index_CRITICAL_CHANCE = 14,
    ActorValue__Index_HEALING_RATE = 15,
    ActorValue__Index_HEALTH = 16,
    ActorValue__Index_MELEE_DAMAGE = 17,
    ActorValue__Index_DAMAGE_RESISTANCE = 18,
    ActorValue__Index_POISON_RESISTANCE = 19,
    ActorValue__Index_RADIATION_RESISTANCE = 20,
    ActorValue__Index_SPEED_MULT = 21,
    ActorValue__Index_FATIGUE = 22,
    ActorValue__Index_KARMA = 23,
    ActorValue__Index_EXPERIENCE_POINTS = 24,
    ActorValue__Index_PERCEPTION_CONDITION = 25,
    ActorValue__Index_ENDURANCE_CONDITION = 26,
    ActorValue__Index_LEFT_ATTACK_CONDITION = 27,
    ActorValue__Index_RIGHT_ATTACK_CONDITION = 28,
    ActorValue__Index_LEFT_MOBILITY_CONDITION = 29,
    ActorValue__Index_RIGHT_MOBILITY_CONDITION = 30,
    ActorValue__Index_BRAIN_CONDITION = 31,
    ActorValue__Index_BARTER = 32,
    ActorValue__Index_BIG_GUNS = 33,
    ActorValue__Index_ENERGY_WEAPONS = 34,
    ActorValue__Index_EXPLOSIVES = 35,
    ActorValue__Index_LOCKPICK = 36,
    ActorValue__Index_MEDICINE = 37,
    ActorValue__Index_MELEE_WEAPONS = 38,
    ActorValue__Index_REPAIR = 39,
    ActorValue__Index_SCIENCE = 40,
    ActorValue__Index_SMALL_GUNS = 41,
    ActorValue__Index_SNEAK = 42,
    ActorValue__Index_SPEECH = 43,
    ActorValue__Index_SURVIVAL = 44,
    ActorValue__Index_UNARMED = 45,
    ActorValue__Index_INVENTORY_WEIGHT = 46,
    ActorValue__Index_PARALYSIS = 47,
    ActorValue__Index_INVISIBILITY = 48,
    ActorValue__Index_CHAMELEON = 49,
    ActorValue__Index_NIGHT_EYE_BONUS = 50,
    ActorValue__Index_TURBO = 51,
    ActorValue__Index_FIRE_RESISTANCE = 52,
    ActorValue__Index_WATER_BREATHING = 53,
    ActorValue__Index_RADIATION_RADS = 54,
    ActorValue__Index_BLOODY_MESS = 55,
    ActorValue__Index_UNARMED_DAMAGE = 56,
    ActorValue__Index_ASSISTANCE = 57,
    ActorValue__Index_ELECTRICAL_RESISTANCE = 58,
    ActorValue__Index_FROST_RESISTANCE = 59,
    ActorValue__Index_ENERGY_RESISTANCE = 60,
    ActorValue__Index_EMP_RESISTANCE = 61,
    ActorValue__Index_VARIABLE_01 = 62,
    ActorValue__Index_VARIABLE_02 = 63,
    ActorValue__Index_VARIABLE_03 = 64,
    ActorValue__Index_VARIABLE_04 = 65,
    ActorValue__Index_VARIABLE_05 = 66,
    ActorValue__Index_VARIABLE_06 = 67,
    ActorValue__Index_VARIABLE_07 = 68,
    ActorValue__Index_VARIABLE_08 = 69,
    ActorValue__Index_VARIABLE_09 = 70,
    ActorValue__Index_VARIABLE_10 = 71,
    ActorValue__Index_IGNORE_CRIPPLED_LIMBS = 72,
    ActorValue__Index_DEHYDRATION = 73,
    ActorValue__Index_HUNGER = 74,
    ActorValue__Index_SLEEPDEPREVATION = 75,
    ActorValue__Index_DAMAGE_THRESHOLD = 76,
    ActorValue__Index_ACTOR_VALUE_COUNT = 77,
    ActorValue__Index_AI_ATTRIBUTE_START = 0,
    ActorValue__Index_ATTRIBUTE_START = 5,
    ActorValue__Index_ACTOR_VALUE_START = 0,
    ActorValue__Index_DERIVED_ATTRIBUTE_START = 12,
    ActorValue__Index_CONDITION_START = 25,
    ActorValue__Index_SKILL_START = 32,
    ActorValue__Index_INT_START = 46,
    ActorValue__Index_VARIABLE_START = 62,
    ActorValue__Index_AI_ATTRIBUTE_END = 5,
    ActorValue__Index_ATTRIBUTE_END = 12,
    ActorValue__Index_CONDITION_END = 32,
    ActorValue__Index_DERIVED_ATTRIBUTE_END = 32,
    ActorValue__Index_SKILL_END = 46,
    ActorValue__Index_INT_END = 62,
    ActorValue__Index_VARIABLE_END = 76,
    ActorValue__Index_ATTRIBUTE_COUNT = 7,
    ActorValue__Index_DERIVED_ATTRIBUTE_COUNT = 20,
    ActorValue__Index_SKILL_COUNT = 14,
    ActorValue__Index_AI_ATTRIBUTE_COUNT = 5,
    ActorValue__Index_CONDITION_COUNT = 7,
    ActorValue__Index_INT_COUNT = 16,
    ActorValue__Index_VALUE_NONE = -1,
    ActorValue__Index_SKILL_NONE = -1,
    ActorValue__Index_ATTRIBUTE_NONE = -1,
};
}
typedef ActorValue::Index ActorValue__Index;
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
#endif
