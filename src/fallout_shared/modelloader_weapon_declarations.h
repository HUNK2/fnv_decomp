// REVIEW PROPOSAL ONLY: declaration/layout closure for 0x00446390.
// Same existing modelloader.cpp translation unit only. No implementation body.
// Include after immutable modelloader_packet.h and selector_same_tu_types.h.
// xNVSE data declarations; JohnnyGuitarNVSE public getter identity/return type.
#ifndef MODELLOADER_WEAPON_GETTER_CLOSURE_H
#define MODELLOADER_WEAPON_GETTER_CLOSURE_H
#ifndef FNV_MODELLOADER_SELECTOR_SAME_TU_DECLARATIONS_H
#error Include the reviewed selector_same_tu_types.h declarations first.
#endif

class BGSProjectile;
class SpellItem;
class BGSImpactDataSet;
class TESObjectSTAT;
class TESObjectIMOD;

// xNVSE common/ITypes.h:125-159, declaration-only representation.
// The real member remains Bitfield<T>, never a byte-array or integer substitute.
template <typename T> class Bitfield {
public:
    Bitfield();
    ~Bitfield();
    void Clear(void);
    void RawSet(unsigned long data);
    void Set(unsigned long data);
    void Clear(unsigned long data);
    void UnSet(unsigned long data);
    void Mask(unsigned long data);
    void Toggle(unsigned long data);
    void Write(unsigned long data, bool state);
    T Get(void) const;
    T Get(unsigned long data) const;
    T Extract(unsigned long bit) const;
    T ExtractField(unsigned long shift, unsigned long length);
    bool IsSet(unsigned long data) const;
    bool IsUnSet(unsigned long data) const;
    bool IsClear(unsigned long data) const;
private:
    T field;
};
typedef Bitfield<unsigned char> Bitfield8;
typedef Bitfield<unsigned long> Bitfield32;

// New complete embedded components. All bases reuse BaseFormComponent unchanged.
// xNVSE GameForms.h:554-566.
class TESAttackDamageForm : public BaseFormComponent {
public:
    TESAttackDamageForm();
    ~TESAttackDamageForm();
    virtual unsigned short GetDamage(void);
    unsigned short damage;
    unsigned short unk0;
};
// xNVSE GameForms.h:841-849.
class BGSAmmoForm : public BaseFormComponent {
public:
    BGSAmmoForm();
    ~BGSAmmoForm();
    TESForm* ammo;
};
// xNVSE GameForms.h:776-785.
class BGSClipRoundsForm : public BaseFormComponent {
public:
    BGSClipRoundsForm();
    ~BGSClipRoundsForm();
    unsigned char clipRounds;
    unsigned char padding[3];
};
// xNVSE GameForms.h:871-878. Preserve its published declaration; do not invent a slot.
class BGSPreloadable : public BaseFormComponent {
public:
    BGSPreloadable();
    ~BGSPreloadable();
    virtual void Fn_04(void);
};

// JG BSEnums.hpp:1221-1240. C++03 typedef replaces its equivalent C++11 using.
struct _WeaponType {
    enum Type {
        HAND_TO_HAND_MELEE = 0,
        ONE_HAND_MELEE = 1,
        TWO_HAND_MELEE = 2,
        ONE_HAND_PISTOL = 3,
        ONE_HAND_PISTOL_ENERGY = 4,
        TWO_HAND_RIFLE = 5,
        TWO_HAND_AUTOMATIC = 6,
        TWO_HAND_RIFLE_ENERGY = 7,
        TWO_HAND_HANDLE = 8,
        TWO_HAND_LAUNCHER = 9,
        ONE_HAND_GRENADE = 10,
        ONE_HAND_MINE = 11,
        ONE_HAND_LUNCHBOX_MINE = 12,
        ONE_HAND_THROWN = 13,
        COUNT
    };
};
typedef _WeaponType::Type WEAPON_TYPE;

// Full xNVSE GameForms.h:2606-2896 data layout (including every published field).
// UInt8/UInt16/UInt32 spelling is expanded to their exact primitive typedefs.
class TESObjectWEAP : public TESBoundObject
{
public:
	TESObjectWEAP();
	~TESObjectWEAP();

	enum EWeaponType {
		kWeapType_HandToHandMelee = 0,
		kWeapType_OneHandMelee,
		kWeapType_TwoHandMelee,
		kWeapType_OneHandPistol,
		kWeapType_OneHandPistolEnergy,
		kWeapType_TwoHandRifle,
		kWeapType_TwoHandAutomatic,
		kWeapType_TwoHandRifleEnergy,
		kWeapType_TwoHandHandle,
		kWeapType_TwoHandLauncher,
		kWeapType_OneHandGrenade,
		kWeapType_OneHandMine,
		kWeapType_OneHandLunchboxMine,
		kWeapType_OneHandThrown,
		kWeapType_Last	// During animation analysis, player weapon can be classified as 0x0C = last
	};

	enum EWeaponSounds {
		kWeapSound_Shoot3D = 0,
		kWeapSound_Shoot2D,
		kWeapSound_Shoot3DLooping,
		kWeapSound_NoAmmo,
		kWeapSound_Swing = kWeapSound_NoAmmo,
		kWeapSound_Block,
		kWeapSound_Idle,
		kWeapSound_Equip,
		kWeapSound_Unequip
	};

	enum EHandGrip {
		eHandGrip_Default	= 0xFF,
		eHandGrip_1			= 0xE6,
		eHandGrip_2			= 0xE7,
		eHandGrip_3			= 0xE8,
		eHandGrip_4			= 0xE9,
		eHandGrip_5			= 0xEA,
		eHandGrip_6			= 0xEB,
		eHandGrip_Count		= 7,
	};

	enum EAttackAnimations {
		eAttackAnim_Default =		255,
		eAttackAnim_Attack3 =		38,
		eAttackAnim_Attack4 =		44,
		eAttackAnim_Attack5 =		50,
		eAttackAnim_Attack6 =		56,
		eAttackAnim_Attack7 =		62,
		eAttackAnim_Attack8 =		68,
		eAttackAnim_Attack9 =		144,
		eAttackAnim_AttackLeft =	26,
		eAttackAnim_AttackLoop =	74,
		eAttackAnim_AttackRight =	32,
		eAttackAnim_AttackSpin =	80,
		eAttackAnim_AttackSpin2 =	86,
		eAttackAnim_AttackThrow =	114,
		eAttackAnim_AttackThrow2 =	120,
		eAttackAnim_AttackThrow3 =	126,
		eAttackAnim_AttackThrow4 =	132,
		eAttackAnim_AttackThrow5 =	138,
		eAttackAnim_AttackThrow6 =	150,
		eAttackAnim_AttackThrow7 =	156,
		eAttackAnim_AttackThrow8 =	162,
		eAttackAnim_PlaceMine =		102,
		eAttackAnim_PlaceMine2 =	108,
		eAttackAnim_Count =			23,
	};

	enum ReloadAnim {
		eReload_A = 0,
		eReload_B,
		eReload_C,
		eReload_D,
		eReload_E,
		eReload_F,
		eReload_G,
		eReload_H,
		eReload_I,
		eReload_J,
		eReload_K,
		eReload_L,
		eReload_M,
		eReload_N,
		eReload_O,
		eReload_P,
		eReload_Q,
		eReload_R,
		eReload_S,
		eReload_W,
		eReload_X,
		eReload_Y,
		eReload_Z,
		eReload_Count,
	};
	typedef char reload_count_check[(eReload_Count == 23) ? 1 : -1];

	enum EWeaponFlags1 {
		eFlag_IgnoresNormalWeapResist	= 0x1,
		eFlag_IsAutomatic				= 0x2,
		eFlag_HasScope					= 0x4,
		eFlag_CantDrop					= 0x8,
		eFlag_HideBackpack				= 0x10,
		eFlag_EmbeddedWeapon			= 0x20,
		eFlag_No1stPersonISAnims		= 0x40,
		Eflag_NonPlayable				= 0x80
	};

	enum EWeaponFlags2 {
		eFlag_PlayerOnly				= 0x1,
		eFlag_NPCsUseAmmo				= 0x2,
		eFlag_NoJamAfterReload			= 0x4,
		eFlag_ActionPointOverride		= 0x8,
		eFlag_MinorCrime				= 0x10,
		eFlag_FixedRange				= 0x20,
		eFlag_NotUsedNormalCombat		= 0x40,
		eFlag_DamageToWeaponOverride	= 0x80,
		eFlag_No3rdPersonISAnims		= 0x100,
		eFlag_BurstShot					= 0x200,
		eFlag_RumbleAlternate			= 0x400,
		eFlag_LongBurst					= 0x800,
	};

	enum EEmbedWeapAV {
		eEmbedAV_Perception				= 0,
		eEmbedAV_Endurance,
		eEmbedAV_LeftAttack,
		eEmbedAV_RightAttack,
		eEmbedAV_LeftMobility,
		eEmbedAV_RightMobility,
		eEmbedAV_Brain,
	};

	enum EOnHit {
		eOnHit_Normal					= 0,
		eOnHit_DismemberOnly,
		eOnHit_ExplodeOnly,
		eOnHit_NoDismemberOrExplode,
	};

	enum ERumblePattern {
		eRumblePattern_Constant			= 0,
		eRumblePattern_Square,
		eRumblePattern_Triangle,
		eRumblePattern_Sawtooth
	};

	enum ECritDamageFlags {
		eCritDamage_OnDeath				= 0x1
	};

	enum
	{
		kWeaponModEffect_None = 0,
		kWeaponModEffect_IncreaseDamage,
		kWeaponModEffect_IncreaseClipCapacity,
		kWeaponModEffect_DecreaseSpread,
		kWeaponModEffect_DecreaseWeight,
		kWeaponModEffect_Unused05,
		kWeaponModEffect_RegenerateAmmo,
		kWeaponModEffect_DecreaseEquipTime,
		kWeaponModEffect_IncreaseRateOfFire,		// 8
		kWeaponModEffect_IncreaseProjectileSpeed,
		kWeaponModEffect_IncreaseMaxCondition,
		kWeaponModEffect_Silence,
		kWeaponModEffect_SplitBeam,
		kWeaponModEffect_VATSBonus,
		kWeaponModEffect_IncreaseZoom,				// 14
	};

	// bases
	TESFullName					fullName;			// 030
	TESModelTextureSwap			textureSwap;		// 03C
	TESIcon						icon;				// 05C
	TESScriptableForm			scritpable;			// 068
	TESEnchantableForm			enchantable;		// 074
	TESValueForm				value;				// 084
	TESWeightForm				weight;				// 08C
	TESHealthForm				health;				// 094
	TESAttackDamageForm			attackDmg;			// 09C
	BGSAmmoForm					ammo;				// 0A4
	BGSClipRoundsForm			clipRounds;			// 0AC
	BGSDestructibleObjectForm	destructible;		// 0B4
	BGSRepairItemList			repairItemList;		// 0BC
	BGSEquipType				equipType;			// 0C4
	BGSPreloadable				preloadable;		// 0CC
	BGSMessageIcon				messageIcon;		// 0D0
	BGSBipedModelList			bipedModelList;		// 0E0
	BGSPickupPutdownSounds		pickupPutdownSounds;// 0E8

	unsigned char				eWeaponType;		// 0F4
	unsigned char				pad[3];
	float				animMult;			// 0F8
	float				reach;				// 0FC
	Bitfield8			weaponFlags1;		// 100
	unsigned char				handGrip;			// 101
	unsigned char				ammoUse;			// 102
	unsigned char				reloadAnim;			// 103
	float				minSpread;			// 104
	float				spread;				// 108
	unsigned long				unk10C;				// 10C
	float				sightFOV;			// 110
	unsigned long				unk114;				// 114
	BGSProjectile		* projectile;		// 118
	unsigned char				baseVATSChance;		// 11C
	unsigned char				attackAnim;			// 11D
	unsigned char				numProjectiles;		// 11E
	unsigned char				embedWeaponAV;		// 11F
	float				minRange;			// 120
	float				maxRange;			// 124
	unsigned long				onHit;				// 128
	Bitfield32			weaponFlags2;		// 12C
	float				animAttackMult;		// 130
	float				fireRate;			// 134
	float				AP;					// 138
	float				rumbleLeftMotor;	// 13C
	float				rumbleRightMotor;	// 140
	float				rumbleDuration;		// 144
	float				damageToWeaponMult;	// 148
	float				animShotsPerSec;	// 14C
	float				animReloadTime;		// 150
	float				animJamTime;		// 154		
	float				aimArc;				// 158
	unsigned long				weaponSkill;		// 15C - actor value
	unsigned long				rumblePattern;		// 160 - reload anim?
	float				rumbleWavelength;	// 164
	float				limbDamageMult;		// 168
	unsigned long				resistType;			// 16c - actor value
	float				sightUsage;			// 170
	float				semiAutoFireDelayMin;	// 174
	float				semiAutoFireDelayMax;	// 178
	unsigned long				unk17C;				// 17C - 0-0x10: 0x8:str req 0x10: - skill req  - 0xb:kill impulse B158 - mod 1 val B15C - Mod 2 val Effects: 0x1: e(zoom) 0x2: a 0x3:0 0x4-6: Values c-e Mod Effects Val2:1-3 
	unsigned long				effectMods[3];		// 180
	float				value1Mod[3];		// 18C
	unsigned long				powerAttackAnimOverride;	// 198
	unsigned long				strRequired;		// 19C
	unsigned char				unk1A0;				// 1A0
	unsigned char				modReloadAnim;		// 1A1
	unsigned char				pad1A2[2];			// 1A2
	float				regenRate;			// 1A4
	float				killImpulse;		// 1A8
	float				value2Mod[3];		// 1AC
	float				impulseDist;		// 1B8
	unsigned long				skillRequirement;	// 1BC
	unsigned short				criticalDamage;		// 1C0
	unsigned char				unk1C2[2];			// 1C2
	float				criticalPercent;	// 1C4
	unsigned char				critDamageFlags;	// 1C8
	unsigned char				pad1C9[3];			// 1C9
	SpellItem			* criticalEffect;	// 1CC
	TESModel			shellCasingModel;	// 1DO
	TESModel			targetNIF;			// 1E8 - target NIF
	TESModel			model200;			// 200 - could be a texture swap
	unsigned long				unk218;				// 218
	TESSound			* sounds[12];		// 21C
	BGSImpactDataSet	* impactDataSet;	// 24C
	TESObjectSTAT		* worldStatic;		// 250
	TESObjectSTAT		* mod1Static;		// 254
	TESObjectSTAT		* mod2Static;		// 258
	TESObjectSTAT		* mod3Static;		// 25C
	TESObjectSTAT		* mod12Static;		// 260
	TESObjectSTAT		* mod13Static;		// 264
	TESObjectSTAT		* mod23Static;		// 268
	TESObjectSTAT		* mod123Static;		// 26C
	TESModelTextureSwap	textureMod1;		// 270 Mod 1
	TESModelTextureSwap	textureMod2;		// 290 Mod 2
	TESModelTextureSwap	textureMod3;		// 2B0 Mod 3
	TESModelTextureSwap	textureMod12;		// 2D0 Mod 1-2
	TESModelTextureSwap	textureMod13;		// 2F0 Model 1-3
	TESModelTextureSwap	textureMod23;		// 310 Model 2-3
	TESModelTextureSwap	textureMod123;		// 330 Model 1-2-3
	TESObjectIMOD		* itemMod1;			// 350
	TESObjectIMOD		* itemMod2;			// 354
	TESObjectIMOD		* itemMod3;			// 358
	unsigned long				unk35C;				// 35C
	unsigned long				unk360;				// 360
	unsigned long				soundLevel;			// 364
	unsigned long				unk368;				// 368
	unsigned long				unk36C;				// 36C
	unsigned long				unk370;				// 370
	unsigned long				unk374;				// 374
	unsigned long				unk378;				// 378
	unsigned long				unk37C;				// 37C
	unsigned long				recharge;			// 380 maybe recharge
	bool				isLoopingReload;	// 384
	unsigned char				unk385[3];			// 385



    // JG TESObjectWEAP.hpp:245; TESObjectWEAP.cpp:3-4 names PC address 0x00446390.
    WEAPON_TYPE GetWeaponType() const;
};

// C++03 layout checks. These are proposed checks, not a claim of compilation.
typedef char weapon_size_check_Bitfield8[(sizeof(Bitfield8) == 0x1) ? 1 : -1];
typedef char weapon_size_check_Bitfield32[(sizeof(Bitfield32) == 0x4) ? 1 : -1];
typedef char weapon_size_check_WEAPON_TYPE[(sizeof(WEAPON_TYPE) == 0x4) ? 1 : -1];
typedef char weapon_size_check_TESAttackDamageForm[(sizeof(TESAttackDamageForm) == 0x8) ? 1 : -1];
typedef char weapon_size_check_BGSAmmoForm[(sizeof(BGSAmmoForm) == 0x8) ? 1 : -1];
typedef char weapon_size_check_BGSClipRoundsForm[(sizeof(BGSClipRoundsForm) == 0x8) ? 1 : -1];
typedef char weapon_size_check_BGSPreloadable[(sizeof(BGSPreloadable) == 0x4) ? 1 : -1];
typedef char weapon_size_check_TESObjectWEAP[(sizeof(TESObjectWEAP) == 0x388) ? 1 : -1];
typedef char weapon_offset_check_0[(offsetof(TESObjectWEAP, fullName) == 0x030) ? 1 : -1];
typedef char weapon_offset_check_1[(offsetof(TESObjectWEAP, textureSwap) == 0x03c) ? 1 : -1];
typedef char weapon_offset_check_2[(offsetof(TESObjectWEAP, icon) == 0x05c) ? 1 : -1];
typedef char weapon_offset_check_3[(offsetof(TESObjectWEAP, scritpable) == 0x068) ? 1 : -1];
typedef char weapon_offset_check_4[(offsetof(TESObjectWEAP, enchantable) == 0x074) ? 1 : -1];
typedef char weapon_offset_check_5[(offsetof(TESObjectWEAP, value) == 0x084) ? 1 : -1];
typedef char weapon_offset_check_6[(offsetof(TESObjectWEAP, weight) == 0x08c) ? 1 : -1];
typedef char weapon_offset_check_7[(offsetof(TESObjectWEAP, health) == 0x094) ? 1 : -1];
typedef char weapon_offset_check_8[(offsetof(TESObjectWEAP, attackDmg) == 0x09c) ? 1 : -1];
typedef char weapon_offset_check_9[(offsetof(TESObjectWEAP, ammo) == 0x0a4) ? 1 : -1];
typedef char weapon_offset_check_10[(offsetof(TESObjectWEAP, clipRounds) == 0x0ac) ? 1 : -1];
typedef char weapon_offset_check_11[(offsetof(TESObjectWEAP, destructible) == 0x0b4) ? 1 : -1];
typedef char weapon_offset_check_12[(offsetof(TESObjectWEAP, repairItemList) == 0x0bc) ? 1 : -1];
typedef char weapon_offset_check_13[(offsetof(TESObjectWEAP, equipType) == 0x0c4) ? 1 : -1];
typedef char weapon_offset_check_14[(offsetof(TESObjectWEAP, preloadable) == 0x0cc) ? 1 : -1];
typedef char weapon_offset_check_15[(offsetof(TESObjectWEAP, messageIcon) == 0x0d0) ? 1 : -1];
typedef char weapon_offset_check_16[(offsetof(TESObjectWEAP, bipedModelList) == 0x0e0) ? 1 : -1];
typedef char weapon_offset_check_17[(offsetof(TESObjectWEAP, pickupPutdownSounds) == 0x0e8) ? 1 : -1];
typedef char weapon_offset_check_18[(offsetof(TESObjectWEAP, eWeaponType) == 0x0f4) ? 1 : -1];
typedef char weapon_offset_check_19[(offsetof(TESObjectWEAP, pad) == 0x0f5) ? 1 : -1];
typedef char weapon_offset_check_20[(offsetof(TESObjectWEAP, animMult) == 0x0f8) ? 1 : -1];
typedef char weapon_offset_check_21[(offsetof(TESObjectWEAP, reach) == 0x0fc) ? 1 : -1];
typedef char weapon_offset_check_22[(offsetof(TESObjectWEAP, weaponFlags1) == 0x100) ? 1 : -1];
typedef char weapon_offset_check_23[(offsetof(TESObjectWEAP, handGrip) == 0x101) ? 1 : -1];
typedef char weapon_offset_check_24[(offsetof(TESObjectWEAP, ammoUse) == 0x102) ? 1 : -1];
typedef char weapon_offset_check_25[(offsetof(TESObjectWEAP, reloadAnim) == 0x103) ? 1 : -1];
typedef char weapon_offset_check_26[(offsetof(TESObjectWEAP, minSpread) == 0x104) ? 1 : -1];
typedef char weapon_offset_check_27[(offsetof(TESObjectWEAP, spread) == 0x108) ? 1 : -1];
typedef char weapon_offset_check_28[(offsetof(TESObjectWEAP, unk10C) == 0x10c) ? 1 : -1];
typedef char weapon_offset_check_29[(offsetof(TESObjectWEAP, sightFOV) == 0x110) ? 1 : -1];
typedef char weapon_offset_check_30[(offsetof(TESObjectWEAP, unk114) == 0x114) ? 1 : -1];
typedef char weapon_offset_check_31[(offsetof(TESObjectWEAP, projectile) == 0x118) ? 1 : -1];
typedef char weapon_offset_check_32[(offsetof(TESObjectWEAP, baseVATSChance) == 0x11c) ? 1 : -1];
typedef char weapon_offset_check_33[(offsetof(TESObjectWEAP, attackAnim) == 0x11d) ? 1 : -1];
typedef char weapon_offset_check_34[(offsetof(TESObjectWEAP, numProjectiles) == 0x11e) ? 1 : -1];
typedef char weapon_offset_check_35[(offsetof(TESObjectWEAP, embedWeaponAV) == 0x11f) ? 1 : -1];
typedef char weapon_offset_check_36[(offsetof(TESObjectWEAP, minRange) == 0x120) ? 1 : -1];
typedef char weapon_offset_check_37[(offsetof(TESObjectWEAP, maxRange) == 0x124) ? 1 : -1];
typedef char weapon_offset_check_38[(offsetof(TESObjectWEAP, onHit) == 0x128) ? 1 : -1];
typedef char weapon_offset_check_39[(offsetof(TESObjectWEAP, weaponFlags2) == 0x12c) ? 1 : -1];
typedef char weapon_offset_check_40[(offsetof(TESObjectWEAP, animAttackMult) == 0x130) ? 1 : -1];
typedef char weapon_offset_check_41[(offsetof(TESObjectWEAP, fireRate) == 0x134) ? 1 : -1];
typedef char weapon_offset_check_42[(offsetof(TESObjectWEAP, AP) == 0x138) ? 1 : -1];
typedef char weapon_offset_check_43[(offsetof(TESObjectWEAP, rumbleLeftMotor) == 0x13c) ? 1 : -1];
typedef char weapon_offset_check_44[(offsetof(TESObjectWEAP, rumbleRightMotor) == 0x140) ? 1 : -1];
typedef char weapon_offset_check_45[(offsetof(TESObjectWEAP, rumbleDuration) == 0x144) ? 1 : -1];
typedef char weapon_offset_check_46[(offsetof(TESObjectWEAP, damageToWeaponMult) == 0x148) ? 1 : -1];
typedef char weapon_offset_check_47[(offsetof(TESObjectWEAP, animShotsPerSec) == 0x14c) ? 1 : -1];
typedef char weapon_offset_check_48[(offsetof(TESObjectWEAP, animReloadTime) == 0x150) ? 1 : -1];
typedef char weapon_offset_check_49[(offsetof(TESObjectWEAP, animJamTime) == 0x154) ? 1 : -1];
typedef char weapon_offset_check_50[(offsetof(TESObjectWEAP, aimArc) == 0x158) ? 1 : -1];
typedef char weapon_offset_check_51[(offsetof(TESObjectWEAP, weaponSkill) == 0x15c) ? 1 : -1];
typedef char weapon_offset_check_52[(offsetof(TESObjectWEAP, rumblePattern) == 0x160) ? 1 : -1];
typedef char weapon_offset_check_53[(offsetof(TESObjectWEAP, rumbleWavelength) == 0x164) ? 1 : -1];
typedef char weapon_offset_check_54[(offsetof(TESObjectWEAP, limbDamageMult) == 0x168) ? 1 : -1];
typedef char weapon_offset_check_55[(offsetof(TESObjectWEAP, resistType) == 0x16c) ? 1 : -1];
typedef char weapon_offset_check_56[(offsetof(TESObjectWEAP, sightUsage) == 0x170) ? 1 : -1];
typedef char weapon_offset_check_57[(offsetof(TESObjectWEAP, semiAutoFireDelayMin) == 0x174) ? 1 : -1];
typedef char weapon_offset_check_58[(offsetof(TESObjectWEAP, semiAutoFireDelayMax) == 0x178) ? 1 : -1];
typedef char weapon_offset_check_59[(offsetof(TESObjectWEAP, unk17C) == 0x17c) ? 1 : -1];
typedef char weapon_offset_check_60[(offsetof(TESObjectWEAP, effectMods) == 0x180) ? 1 : -1];
typedef char weapon_offset_check_61[(offsetof(TESObjectWEAP, value1Mod) == 0x18c) ? 1 : -1];
typedef char weapon_offset_check_62[(offsetof(TESObjectWEAP, powerAttackAnimOverride) == 0x198) ? 1 : -1];
typedef char weapon_offset_check_63[(offsetof(TESObjectWEAP, strRequired) == 0x19c) ? 1 : -1];
typedef char weapon_offset_check_64[(offsetof(TESObjectWEAP, unk1A0) == 0x1a0) ? 1 : -1];
typedef char weapon_offset_check_65[(offsetof(TESObjectWEAP, modReloadAnim) == 0x1a1) ? 1 : -1];
typedef char weapon_offset_check_66[(offsetof(TESObjectWEAP, pad1A2) == 0x1a2) ? 1 : -1];
typedef char weapon_offset_check_67[(offsetof(TESObjectWEAP, regenRate) == 0x1a4) ? 1 : -1];
typedef char weapon_offset_check_68[(offsetof(TESObjectWEAP, killImpulse) == 0x1a8) ? 1 : -1];
typedef char weapon_offset_check_69[(offsetof(TESObjectWEAP, value2Mod) == 0x1ac) ? 1 : -1];
typedef char weapon_offset_check_70[(offsetof(TESObjectWEAP, impulseDist) == 0x1b8) ? 1 : -1];
typedef char weapon_offset_check_71[(offsetof(TESObjectWEAP, skillRequirement) == 0x1bc) ? 1 : -1];
typedef char weapon_offset_check_72[(offsetof(TESObjectWEAP, criticalDamage) == 0x1c0) ? 1 : -1];
typedef char weapon_offset_check_73[(offsetof(TESObjectWEAP, unk1C2) == 0x1c2) ? 1 : -1];
typedef char weapon_offset_check_74[(offsetof(TESObjectWEAP, criticalPercent) == 0x1c4) ? 1 : -1];
typedef char weapon_offset_check_75[(offsetof(TESObjectWEAP, critDamageFlags) == 0x1c8) ? 1 : -1];
typedef char weapon_offset_check_76[(offsetof(TESObjectWEAP, pad1C9) == 0x1c9) ? 1 : -1];
typedef char weapon_offset_check_77[(offsetof(TESObjectWEAP, criticalEffect) == 0x1cc) ? 1 : -1];
typedef char weapon_offset_check_78[(offsetof(TESObjectWEAP, shellCasingModel) == 0x1d0) ? 1 : -1];
typedef char weapon_offset_check_79[(offsetof(TESObjectWEAP, targetNIF) == 0x1e8) ? 1 : -1];
typedef char weapon_offset_check_80[(offsetof(TESObjectWEAP, model200) == 0x200) ? 1 : -1];
typedef char weapon_offset_check_81[(offsetof(TESObjectWEAP, unk218) == 0x218) ? 1 : -1];
typedef char weapon_offset_check_82[(offsetof(TESObjectWEAP, sounds) == 0x21c) ? 1 : -1];
typedef char weapon_offset_check_83[(offsetof(TESObjectWEAP, impactDataSet) == 0x24c) ? 1 : -1];
typedef char weapon_offset_check_84[(offsetof(TESObjectWEAP, worldStatic) == 0x250) ? 1 : -1];
typedef char weapon_offset_check_85[(offsetof(TESObjectWEAP, mod1Static) == 0x254) ? 1 : -1];
typedef char weapon_offset_check_86[(offsetof(TESObjectWEAP, mod2Static) == 0x258) ? 1 : -1];
typedef char weapon_offset_check_87[(offsetof(TESObjectWEAP, mod3Static) == 0x25c) ? 1 : -1];
typedef char weapon_offset_check_88[(offsetof(TESObjectWEAP, mod12Static) == 0x260) ? 1 : -1];
typedef char weapon_offset_check_89[(offsetof(TESObjectWEAP, mod13Static) == 0x264) ? 1 : -1];
typedef char weapon_offset_check_90[(offsetof(TESObjectWEAP, mod23Static) == 0x268) ? 1 : -1];
typedef char weapon_offset_check_91[(offsetof(TESObjectWEAP, mod123Static) == 0x26c) ? 1 : -1];
typedef char weapon_offset_check_92[(offsetof(TESObjectWEAP, textureMod1) == 0x270) ? 1 : -1];
typedef char weapon_offset_check_93[(offsetof(TESObjectWEAP, textureMod2) == 0x290) ? 1 : -1];
typedef char weapon_offset_check_94[(offsetof(TESObjectWEAP, textureMod3) == 0x2b0) ? 1 : -1];
typedef char weapon_offset_check_95[(offsetof(TESObjectWEAP, textureMod12) == 0x2d0) ? 1 : -1];
typedef char weapon_offset_check_96[(offsetof(TESObjectWEAP, textureMod13) == 0x2f0) ? 1 : -1];
typedef char weapon_offset_check_97[(offsetof(TESObjectWEAP, textureMod23) == 0x310) ? 1 : -1];
typedef char weapon_offset_check_98[(offsetof(TESObjectWEAP, textureMod123) == 0x330) ? 1 : -1];
typedef char weapon_offset_check_99[(offsetof(TESObjectWEAP, itemMod1) == 0x350) ? 1 : -1];
typedef char weapon_offset_check_100[(offsetof(TESObjectWEAP, itemMod2) == 0x354) ? 1 : -1];
typedef char weapon_offset_check_101[(offsetof(TESObjectWEAP, itemMod3) == 0x358) ? 1 : -1];
typedef char weapon_offset_check_102[(offsetof(TESObjectWEAP, unk35C) == 0x35c) ? 1 : -1];
typedef char weapon_offset_check_103[(offsetof(TESObjectWEAP, unk360) == 0x360) ? 1 : -1];
typedef char weapon_offset_check_104[(offsetof(TESObjectWEAP, soundLevel) == 0x364) ? 1 : -1];
typedef char weapon_offset_check_105[(offsetof(TESObjectWEAP, unk368) == 0x368) ? 1 : -1];
typedef char weapon_offset_check_106[(offsetof(TESObjectWEAP, unk36C) == 0x36c) ? 1 : -1];
typedef char weapon_offset_check_107[(offsetof(TESObjectWEAP, unk370) == 0x370) ? 1 : -1];
typedef char weapon_offset_check_108[(offsetof(TESObjectWEAP, unk374) == 0x374) ? 1 : -1];
typedef char weapon_offset_check_109[(offsetof(TESObjectWEAP, unk378) == 0x378) ? 1 : -1];
typedef char weapon_offset_check_110[(offsetof(TESObjectWEAP, unk37C) == 0x37c) ? 1 : -1];
typedef char weapon_offset_check_111[(offsetof(TESObjectWEAP, recharge) == 0x380) ? 1 : -1];
typedef char weapon_offset_check_112[(offsetof(TESObjectWEAP, isLoopingReload) == 0x384) ? 1 : -1];
typedef char weapon_offset_check_113[(offsetof(TESObjectWEAP, unk385) == 0x385) ? 1 : -1];

#endif
