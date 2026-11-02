// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachine_gs_nogs_variant.cpp - flag-variant unit created 2026-10-31 by flag_proofs.py: contributor code for these functions matched byte for
// byte only under /MT /O2 /GS- /EHsc /Gy (unit src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachine.cpp lists /MT /O2 /GS /EHsc /Gy). Declarations copied from that unit's skeleton; move the functions
// to their real unit once identified.


// src/havok/physics/collide/agent3/machine/1n/hkpagent1nmachine.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/agent3/machine/1n/hkpagent1nmachine.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.
void ProcessEntryPair();
void FUN_00da44d0(int, int, void*);
void FUN_00da48e0(int b, int a);
typedef unsigned int BlockPoolsize_t;
struct BlockPoolAllocator {
    virtual void unk00();
    virtual void* AllocateMemoryBlock(int numBytes);
};
struct BlockPoolMemoryRouter {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    BlockPoolAllocator* m_pStreamAllocator;

    BlockPoolAllocator& heap() { return *m_pStreamAllocator; }
};
extern "C" BlockPoolMemoryRouter& __cdecl FUN_00c85750();
void __cdecl FUN_00c908c0(BlockPoolAllocator* alloc, void* array, int numElements, int sizeElem);
void __cdecl ResizeAudioStream(void* alloc, void* array, int sizeElem);
struct BlockPoolBlock {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    unsigned char unk10;
    unsigned char unk11;
    unsigned char unk12;
    unsigned char unk13;
    int unk14;
    int unk18;

    BlockPoolBlock() { unk00 = 0; }
    static void* operator new(BlockPoolsize_t, void* p) throw() { return p; }
};
struct BlockPoolArray {
    BlockPoolBlock** m_data;
    int m_iElementCount;
    int m_iCapacityState;

    int getCapacity() const { return m_iCapacityState & 0x3fffffff; }

    void GrowArrayCapacity(BlockPoolAllocator& alloc, int n)
    {
        const int cap = getCapacity();
        if (cap < n) {
            int cap2 = 2 * cap;
            int newSize = (n < cap2) ? cap2 : n;
            FUN_00c908c0(&alloc, this, newSize, sizeof(BlockPoolBlock*));
        }
    }

    BlockPoolBlock*& _expandOne(BlockPoolAllocator& alloc)
    {
        if (m_iElementCount == getCapacity())
            ResizeAudioStream(&alloc, this, sizeof(BlockPoolBlock*));
        return m_data[m_iElementCount++];
    }
};
void __cdecl InitBlockPool(BlockPoolArray* blocks);
// hkAgentNmMachine: update the collision filter of one agent entry
struct S_00da40e0_Shape;
struct S_00da40e0_CollisionInput;
struct S_00da40e0_ContactMgr;
struct S_00da40e0_ConstraintOwner;
struct S_00da40e0_Dispatcher;
struct S_00da40e0_Bool {
    char m_cBooleanValue;
    S_00da40e0_Bool() {}
    S_00da40e0_Bool(bool b) { m_cBooleanValue = (char)b; }
    operator bool() const { return m_cBooleanValue != 0; }
};
struct __declspec(align(16)) S_00da40e0_MotionState {
    int unk00;
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
};
struct S_00da40e0_CdBody {
    const S_00da40e0_Shape* m_pCollisionShape;
    unsigned int m_uiCollisionShapeKey;
    const S_00da40e0_MotionState* m_pMotionState;
    const S_00da40e0_CdBody* m_parent;

    S_00da40e0_CdBody() {}
    S_00da40e0_CdBody(const S_00da40e0_CdBody* parent) { m_parent = parent; m_pMotionState = parent->m_pMotionState; }
    void SetCollisionShapeAndKey(const S_00da40e0_Shape* shape, unsigned int key) { m_pCollisionShape = shape; m_uiCollisionShapeKey = key; }
};
struct __declspec(align(16)) S_00da40e0_ShapeBuffer {
    unsigned int m_data[128];
};
struct S_00da40e0_ShapeContainer {
    virtual ~S_00da40e0_ShapeContainer();
    virtual int GetNumChildShapes() const;
    virtual unsigned int GetFirstKey() const;
    virtual unsigned int GetNextShapeKey(unsigned int oldKey) const;
    virtual unsigned int GetFilterInfoForKey(unsigned int key) const;
    virtual const S_00da40e0_Shape* GetShapeForKey(unsigned int key, S_00da40e0_ShapeBuffer& buffer) const;
};
struct S_00da40e0_ShapeCollectionFilter {
    virtual S_00da40e0_Bool IsCollisionEnabled(const S_00da40e0_CollisionInput& input, const S_00da40e0_CdBody& a,
        const S_00da40e0_CdBody& b, const S_00da40e0_ShapeContainer& containerShapeA,
        const S_00da40e0_ShapeContainer& containerShapeB, unsigned int keyA, unsigned int keyB) const = 0;
};
struct S_00da40e0_CollidableCollidableFilter {
    virtual void unk0();
};
struct S_00da40e0_ShapeKeyPair {
    unsigned int m_uiShapeKeyA;
    unsigned int m_uiShapeKeyB;
};
struct S_00da40e0_Entry {
    unsigned char m_ucAgentType;
    unsigned char m_ucNnTrackType;
    unsigned char m_usNumContactPoints;
    unsigned char m_iElementCount;
    S_00da40e0_ShapeKeyPair m_kShapeKeyPair;
};
struct S_00da40e0_AgentData;
typedef void (__cdecl *S_00da40e0_DestroyFunc)(S_00da40e0_Entry* entry, S_00da40e0_AgentData* agentData,
    S_00da40e0_ContactMgr* mgr, S_00da40e0_ConstraintOwner& constraintOwner, S_00da40e0_Dispatcher* dispatcher);
typedef void (__cdecl *S_00da40e0_UpdateFilterFunc)(S_00da40e0_Entry* entry, S_00da40e0_AgentData* agentData,
    const S_00da40e0_CdBody& bodyA, const S_00da40e0_CdBody& bodyB, const S_00da40e0_CollisionInput& input,
    S_00da40e0_ContactMgr* mgr, S_00da40e0_ConstraintOwner& constraintOwner);
struct S_00da40e0_Agent3Funcs {
    S_00da40e0_DestroyFunc m_pAgent3DestroyFuncs;
    void* unk04;
    void* unk08;
    void* unk0C;
    void* unk10;
    S_00da40e0_UpdateFilterFunc m_pUpdateFilterFunc;
    void* unk18;
    void* unk1C;
    void* unk20;
    void* unk24;
    void* unk28;
    void* unk2C;
    void* unk30;
    void* unk34;
    void* unk38;
    void* unk3C;
    void* unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
};
struct S_00da40e0_Dispatcher {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    int unk74;
    int unk78;
    int unk7C;
    int unk80;
    int unk84;
    int unk88;
    int unk8C;
    int unk90;
    int unk94;
    int unk98;
    int unk9C;
    int unkA0;
    int unkA4;
    int unkA8;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int unkC0;
    int unkC4;
    int unkC8;
    int unkCC;
    int unkD0;
    int unkD4;
    int unkD8;
    int unkDC;
    int unkE0;
    int unkE4;
    int unkE8;
    int unkEC;
    int unkF0;
    int unkF4;
    int unkF8;
    int unkFC;
    int unk100;
    int unk104;
    int unk108;
    int unk10C;
    int unk110;
    int unk114;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int unk12C;
    int unk130;
    int unk134;
    int unk138;
    int unk13C;
    int unk140;
    int unk144;
    int unk148;
    int unk14C;
    int unk150;
    int unk154;
    int unk158;
    int unk15C;
    int unk160;
    int unk164;
    int unk168;
    int unk16C;
    int unk170;
    int unk174;
    int unk178;
    int unk17C;
    int unk180;
    int unk184;
    int unk188;
    int unk18C;
    int unk190;
    int unk194;
    int unk198;
    int unk19C;
    int unk1A0;
    int unk1A4;
    int unk1A8;
    int unk1AC;
    int unk1B0;
    int unk1B4;
    int unk1B8;
    int unk1BC;
    int unk1C0;
    int unk1C4;
    int unk1C8;
    int unk1CC;
    int unk1D0;
    int unk1D4;
    int unk1D8;
    int unk1DC;
    int unk1E0;
    int unk1E4;
    int unk1E8;
    int unk1EC;
    int unk1F0;
    int unk1F4;
    int unk1F8;
    int unk1FC;
    int unk200;
    int unk204;
    int unk208;
    int unk20C;
    int unk210;
    int unk214;
    int unk218;
    int unk21C;
    int unk220;
    int unk224;
    int unk228;
    int unk22C;
    int unk230;
    int unk234;
    int unk238;
    int unk23C;
    int unk240;
    int unk244;
    int unk248;
    int unk24C;
    int unk250;
    int unk254;
    int unk258;
    int unk25C;
    int unk260;
    int unk264;
    int unk268;
    int unk26C;
    int unk270;
    int unk274;
    int unk278;
    int unk27C;
    int unk280;
    int unk284;
    int unk288;
    int unk28C;
    int unk290;
    int unk294;
    int unk298;
    int unk29C;
    int unk2A0;
    int unk2A4;
    int unk2A8;
    int unk2AC;
    int unk2B0;
    int unk2B4;
    int unk2B8;
    int unk2BC;
    int unk2C0;
    int unk2C4;
    int unk2C8;
    int unk2CC;
    int unk2D0;
    int unk2D4;
    int unk2D8;
    int unk2DC;
    int unk2E0;
    int unk2E4;
    int unk2E8;
    int unk2EC;
    int unk2F0;
    int unk2F4;
    int unk2F8;
    int unk2FC;
    int unk300;
    int unk304;
    int unk308;
    int unk30C;
    int unk310;
    int unk314;
    int unk318;
    int unk31C;
    int unk320;
    int unk324;
    int unk328;
    int unk32C;
    int unk330;
    int unk334;
    int unk338;
    int unk33C;
    int unk340;
    int unk344;
    int unk348;
    int unk34C;
    int unk350;
    int unk354;
    int unk358;
    int unk35C;
    int unk360;
    int unk364;
    int unk368;
    int unk36C;
    int unk370;
    int unk374;
    int unk378;
    int unk37C;
    int unk380;
    int unk384;
    int unk388;
    int unk38C;
    int unk390;
    int unk394;
    int unk398;
    int unk39C;
    int unk3A0;
    int unk3A4;
    int unk3A8;
    int unk3AC;
    int unk3B0;
    int unk3B4;
    int unk3B8;
    int unk3BC;
    int unk3C0;
    int unk3C4;
    int unk3C8;
    int unk3CC;
    int unk3D0;
    int unk3D4;
    int unk3D8;
    int unk3DC;
    int unk3E0;
    int unk3E4;
    int unk3E8;
    int unk3EC;
    int unk3F0;
    int unk3F4;
    int unk3F8;
    int unk3FC;
    int unk400;
    int unk404;
    int unk408;
    int unk40C;
    int unk410;
    int unk414;
    int unk418;
    int unk41C;
    int unk420;
    int unk424;
    int unk428;
    int unk42C;
    int unk430;
    int unk434;
    int unk438;
    int unk43C;
    int unk440;
    int unk444;
    int unk448;
    int unk44C;
    int unk450;
    int unk454;
    int unk458;
    int unk45C;
    int unk460;
    int unk464;
    int unk468;
    int unk46C;
    int unk470;
    int unk474;
    int unk478;
    int unk47C;
    int unk480;
    int unk484;
    int unk488;
    int unk48C;
    int unk490;
    int unk494;
    int unk498;
    int unk49C;
    int unk4A0;
    int unk4A4;
    int unk4A8;
    int unk4AC;
    int unk4B0;
    int unk4B4;
    int unk4B8;
    int unk4BC;
    int unk4C0;
    int unk4C4;
    int unk4C8;
    int unk4CC;
    int unk4D0;
    int unk4D4;
    int unk4D8;
    int unk4DC;
    int unk4E0;
    int unk4E4;
    int unk4E8;
    int unk4EC;
    int unk4F0;
    int unk4F4;
    int unk4F8;
    int unk4FC;
    int unk500;
    int unk504;
    int unk508;
    int unk50C;
    int unk510;
    int unk514;
    int unk518;
    int unk51C;
    int unk520;
    int unk524;
    int unk528;
    int unk52C;
    int unk530;
    int unk534;
    int unk538;
    int unk53C;
    int unk540;
    int unk544;
    int unk548;
    int unk54C;
    int unk550;
    int unk554;
    int unk558;
    int unk55C;
    int unk560;
    int unk564;
    int unk568;
    int unk56C;
    int unk570;
    int unk574;
    int unk578;
    int unk57C;
    int unk580;
    int unk584;
    int unk588;
    int unk58C;
    int unk590;
    int unk594;
    int unk598;
    int unk59C;
    int unk5A0;
    int unk5A4;
    int unk5A8;
    int unk5AC;
    int unk5B0;
    int unk5B4;
    int unk5B8;
    int unk5BC;
    int unk5C0;
    int unk5C4;
    int unk5C8;
    int unk5CC;
    int unk5D0;
    int unk5D4;
    int unk5D8;
    int unk5DC;
    int unk5E0;
    int unk5E4;
    int unk5E8;
    int unk5EC;
    int unk5F0;
    int unk5F4;
    int unk5F8;
    int unk5FC;
    int unk600;
    int unk604;
    int unk608;
    int unk60C;
    int unk610;
    int unk614;
    int unk618;
    int unk61C;
    int unk620;
    int unk624;
    int unk628;
    int unk62C;
    int unk630;
    int unk634;
    int unk638;
    int unk63C;
    int unk640;
    int unk644;
    int unk648;
    int unk64C;
    int unk650;
    int unk654;
    int unk658;
    int unk65C;
    int unk660;
    int unk664;
    int unk668;
    int unk66C;
    int unk670;
    int unk674;
    int unk678;
    int unk67C;
    int unk680;
    int unk684;
    int unk688;
    int unk68C;
    int unk690;
    int unk694;
    int unk698;
    int unk69C;
    int unk6A0;
    int unk6A4;
    int unk6A8;
    int unk6AC;
    int unk6B0;
    int unk6B4;
    int unk6B8;
    int unk6BC;
    int unk6C0;
    int unk6C4;
    int unk6C8;
    int unk6CC;
    int unk6D0;
    int unk6D4;
    int unk6D8;
    int unk6DC;
    int unk6E0;
    int unk6E4;
    int unk6E8;
    int unk6EC;
    int unk6F0;
    int unk6F4;
    int unk6F8;
    int unk6FC;
    int unk700;
    int unk704;
    int unk708;
    int unk70C;
    int unk710;
    int unk714;
    int unk718;
    int unk71C;
    int unk720;
    int unk724;
    int unk728;
    int unk72C;
    int unk730;
    int unk734;
    int unk738;
    int unk73C;
    int unk740;
    int unk744;
    int unk748;
    int unk74C;
    int unk750;
    int unk754;
    int unk758;
    int unk75C;
    int unk760;
    int unk764;
    int unk768;
    int unk76C;
    int unk770;
    int unk774;
    int unk778;
    int unk77C;
    int unk780;
    int unk784;
    int unk788;
    int unk78C;
    int unk790;
    int unk794;
    int unk798;
    int unk79C;
    int unk7A0;
    int unk7A4;
    int unk7A8;
    int unk7AC;
    int unk7B0;
    int unk7B4;
    int unk7B8;
    int unk7BC;
    int unk7C0;
    int unk7C4;
    int unk7C8;
    int unk7CC;
    int unk7D0;
    int unk7D4;
    int unk7D8;
    int unk7DC;
    int unk7E0;
    int unk7E4;
    int unk7E8;
    int unk7EC;
    int unk7F0;
    int unk7F4;
    int unk7F8;
    int unk7FC;
    int unk800;
    int unk804;
    int unk808;
    int unk80C;
    int unk810;
    int unk814;
    int unk818;
    int unk81C;
    int unk820;
    int unk824;
    int unk828;
    int unk82C;
    int unk830;
    int unk834;
    int unk838;
    int unk83C;
    int unk840;
    int unk844;
    int unk848;
    int unk84C;
    int unk850;
    int unk854;
    int unk858;
    int unk85C;
    int unk860;
    int unk864;
    int unk868;
    int unk86C;
    int unk870;
    int unk874;
    int unk878;
    int unk87C;
    int unk880;
    int unk884;
    int unk888;
    int unk88C;
    int unk890;
    int unk894;
    int unk898;
    int unk89C;
    int unk8A0;
    int unk8A4;
    int unk8A8;
    int unk8AC;
    int unk8B0;
    int unk8B4;
    int unk8B8;
    int unk8BC;
    int unk8C0;
    int unk8C4;
    int unk8C8;
    int unk8CC;
    int unk8D0;
    int unk8D4;
    int unk8D8;
    int unk8DC;
    int unk8E0;
    int unk8E4;
    int unk8E8;
    int unk8EC;
    int unk8F0;
    int unk8F4;
    int unk8F8;
    int unk8FC;
    int unk900;
    int unk904;
    int unk908;
    int unk90C;
    int unk910;
    int unk914;
    int unk918;
    int unk91C;
    int unk920;
    int unk924;
    int unk928;
    int unk92C;
    int unk930;
    int unk934;
    int unk938;
    int unk93C;
    int unk940;
    int unk944;
    int unk948;
    int unk94C;
    int unk950;
    int unk954;
    int unk958;
    int unk95C;
    int unk960;
    int unk964;
    int unk968;
    int unk96C;
    int unk970;
    int unk974;
    int unk978;
    int unk97C;
    int unk980;
    int unk984;
    int unk988;
    int unk98C;
    int unk990;
    int unk994;
    int unk998;
    int unk99C;
    int unk9A0;
    int unk9A4;
    int unk9A8;
    int unk9AC;
    int unk9B0;
    int unk9B4;
    int unk9B8;
    int unk9BC;
    int unk9C0;
    int unk9C4;
    int unk9C8;
    int unk9CC;
    int unk9D0;
    int unk9D4;
    int unk9D8;
    int unk9DC;
    int unk9E0;
    int unk9E4;
    int unk9E8;
    int unk9EC;
    int unk9F0;
    int unk9F4;
    int unk9F8;
    int unk9FC;
    int unkA00;
    int unkA04;
    int unkA08;
    int unkA0C;
    int unkA10;
    int unkA14;
    int unkA18;
    int unkA1C;
    int unkA20;
    int unkA24;
    int unkA28;
    int unkA2C;
    int unkA30;
    int unkA34;
    int unkA38;
    int unkA3C;
    int unkA40;
    int unkA44;
    int unkA48;
    int unkA4C;
    int unkA50;
    int unkA54;
    int unkA58;
    int unkA5C;
    int unkA60;
    int unkA64;
    int unkA68;
    int unkA6C;
    int unkA70;
    int unkA74;
    int unkA78;
    int unkA7C;
    int unkA80;
    int unkA84;
    int unkA88;
    int unkA8C;
    int unkA90;
    int unkA94;
    int unkA98;
    int unkA9C;
    int unkAA0;
    int unkAA4;
    int unkAA8;
    int unkAAC;
    int unkAB0;
    int unkAB4;
    int unkAB8;
    int unkABC;
    int unkAC0;
    int unkAC4;
    int unkAC8;
    int unkACC;
    int unkAD0;
    int unkAD4;
    int unkAD8;
    int unkADC;
    int unkAE0;
    int unkAE4;
    int unkAE8;
    int unkAEC;
    int unkAF0;
    int unkAF4;
    int unkAF8;
    int unkAFC;
    int unkB00;
    int unkB04;
    int unkB08;
    int unkB0C;
    int unkB10;
    int unkB14;
    int unkB18;
    int unkB1C;
    int unkB20;
    int unkB24;
    int unkB28;
    int unkB2C;
    int unkB30;
    int unkB34;
    int unkB38;
    int unkB3C;
    int unkB40;
    int unkB44;
    int unkB48;
    int unkB4C;
    int unkB50;
    int unkB54;
    int unkB58;
    int unkB5C;
    int unkB60;
    int unkB64;
    int unkB68;
    int unkB6C;
    int unkB70;
    int unkB74;
    int unkB78;
    int unkB7C;
    int unkB80;
    int unkB84;
    int unkB88;
    int unkB8C;
    int unkB90;
    int unkB94;
    int unkB98;
    int unkB9C;
    int unkBA0;
    int unkBA4;
    int unkBA8;
    int unkBAC;
    int unkBB0;
    int unkBB4;
    int unkBB8;
    int unkBBC;
    int unkBC0;
    int unkBC4;
    int unkBC8;
    int unkBCC;
    int unkBD0;
    int unkBD4;
    int unkBD8;
    int unkBDC;
    int unkBE0;
    int unkBE4;
    int unkBE8;
    int unkBEC;
    int unkBF0;
    int unkBF4;
    int unkBF8;
    int unkBFC;
    int unkC00;
    int unkC04;
    int unkC08;
    int unkC0C;
    int unkC10;
    int unkC14;
    int unkC18;
    int unkC1C;
    int unkC20;
    int unkC24;
    int unkC28;
    int unkC2C;
    int unkC30;
    int unkC34;
    int unkC38;
    int unkC3C;
    int unkC40;
    int unkC44;
    int unkC48;
    int unkC4C;
    int unkC50;
    int unkC54;
    int unkC58;
    int unkC5C;
    int unkC60;
    int unkC64;
    int unkC68;
    int unkC6C;
    int unkC70;
    int unkC74;
    int unkC78;
    int unkC7C;
    int unkC80;
    int unkC84;
    int unkC88;
    int unkC8C;
    int unkC90;
    int unkC94;
    int unkC98;
    int unkC9C;
    int unkCA0;
    int unkCA4;
    int unkCA8;
    int unkCAC;
    int unkCB0;
    int unkCB4;
    int unkCB8;
    int unkCBC;
    int unkCC0;
    int unkCC4;
    int unkCC8;
    int unkCCC;
    int unkCD0;
    int unkCD4;
    int unkCD8;
    int unkCDC;
    int unkCE0;
    int unkCE4;
    int unkCE8;
    int unkCEC;
    int unkCF0;
    int unkCF4;
    int unkCF8;
    int unkCFC;
    int unkD00;
    int unkD04;
    int unkD08;
    int unkD0C;
    int unkD10;
    int unkD14;
    int unkD18;
    int unkD1C;
    int unkD20;
    int unkD24;
    int unkD28;
    int unkD2C;
    int unkD30;
    int unkD34;
    int unkD38;
    int unkD3C;
    int unkD40;
    int unkD44;
    int unkD48;
    int unkD4C;
    int unkD50;
    int unkD54;
    int unkD58;
    int unkD5C;
    int unkD60;
    int unkD64;
    int unkD68;
    int unkD6C;
    int unkD70;
    int unkD74;
    int unkD78;
    int unkD7C;
    int unkD80;
    int unkD84;
    int unkD88;
    int unkD8C;
    int unkD90;
    int unkD94;
    int unkD98;
    int unkD9C;
    int unkDA0;
    int unkDA4;
    int unkDA8;
    int unkDAC;
    int unkDB0;
    int unkDB4;
    int unkDB8;
    int unkDBC;
    int unkDC0;
    int unkDC4;
    int unkDC8;
    int unkDCC;
    int unkDD0;
    int unkDD4;
    int unkDD8;
    int unkDDC;
    int unkDE0;
    int unkDE4;
    int unkDE8;
    int unkDEC;
    int unkDF0;
    int unkDF4;
    int unkDF8;
    int unkDFC;
    int unkE00;
    int unkE04;
    int unkE08;
    int unkE0C;
    int unkE10;
    int unkE14;
    int unkE18;
    int unkE1C;
    int unkE20;
    int unkE24;
    int unkE28;
    int unkE2C;
    int unkE30;
    int unkE34;
    int unkE38;
    int unkE3C;
    int unkE40;
    int unkE44;
    int unkE48;
    int unkE4C;
    int unkE50;
    int unkE54;
    int unkE58;
    int unkE5C;
    int unkE60;
    int unkE64;
    int unkE68;
    int unkE6C;
    int unkE70;
    int unkE74;
    int unkE78;
    int unkE7C;
    int unkE80;
    int unkE84;
    int unkE88;
    int unkE8C;
    int unkE90;
    int unkE94;
    int unkE98;
    int unkE9C;
    int unkEA0;
    int unkEA4;
    int unkEA8;
    int unkEAC;
    int unkEB0;
    int unkEB4;
    int unkEB8;
    int unkEBC;
    int unkEC0;
    int unkEC4;
    int unkEC8;
    int unkECC;
    int unkED0;
    int unkED4;
    int unkED8;
    int unkEDC;
    int unkEE0;
    int unkEE4;
    int unkEE8;
    int unkEEC;
    int unkEF0;
    int unkEF4;
    int unkEF8;
    int unkEFC;
    int unkF00;
    int unkF04;
    int unkF08;
    int unkF0C;
    int unkF10;
    int unkF14;
    int unkF18;
    int unkF1C;
    int unkF20;
    int unkF24;
    int unkF28;
    int unkF2C;
    int unkF30;
    int unkF34;
    int unkF38;
    int unkF3C;
    int unkF40;
    int unkF44;
    int unkF48;
    int unkF4C;
    int unkF50;
    int unkF54;
    int unkF58;
    int unkF5C;
    int unkF60;
    int unkF64;
    int unkF68;
    int unkF6C;
    int unkF70;
    int unkF74;
    int unkF78;
    int unkF7C;
    int unkF80;
    int unkF84;
    int unkF88;
    int unkF8C;
    int unkF90;
    int unkF94;
    int unkF98;
    int unkF9C;
    int unkFA0;
    int unkFA4;
    int unkFA8;
    int unkFAC;
    int unkFB0;
    int unkFB4;
    int unkFB8;
    int unkFBC;
    int unkFC0;
    int unkFC4;
    int unkFC8;
    int unkFCC;
    int unkFD0;
    int unkFD4;
    int unkFD8;
    int unkFDC;
    int unkFE0;
    int unkFE4;
    int unkFE8;
    int unkFEC;
    int unkFF0;
    int unkFF4;
    int unkFF8;
    int unkFFC;
    int unk1000;
    int unk1004;
    int unk1008;
    int unk100C;
    int unk1010;
    int unk1014;
    int unk1018;
    int unk101C;
    int unk1020;
    int unk1024;
    int unk1028;
    int unk102C;
    int unk1030;
    int unk1034;
    int unk1038;
    int unk103C;
    int unk1040;
    int unk1044;
    int unk1048;
    int unk104C;
    int unk1050;
    int unk1054;
    int unk1058;
    int unk105C;
    int unk1060;
    int unk1064;
    int unk1068;
    int unk106C;
    int unk1070;
    int unk1074;
    int unk1078;
    int unk107C;
    int unk1080;
    int unk1084;
    int unk1088;
    int unk108C;
    int unk1090;
    int unk1094;
    int unk1098;
    int unk109C;
    int unk10A0;
    int unk10A4;
    int unk10A8;
    int unk10AC;
    int unk10B0;
    int unk10B4;
    int unk10B8;
    int unk10BC;
    int unk10C0;
    int unk10C4;
    int unk10C8;
    int unk10CC;
    int unk10D0;
    int unk10D4;
    int unk10D8;
    int unk10DC;
    int unk10E0;
    int unk10E4;
    int unk10E8;
    int unk10EC;
    int unk10F0;
    int unk10F4;
    int unk10F8;
    int unk10FC;
    int unk1100;
    int unk1104;
    int unk1108;
    int unk110C;
    int unk1110;
    int unk1114;
    int unk1118;
    int unk111C;
    int unk1120;
    int unk1124;
    int unk1128;
    int unk112C;
    int unk1130;
    int unk1134;
    int unk1138;
    int unk113C;
    int unk1140;
    int unk1144;
    int unk1148;
    int unk114C;
    int unk1150;
    int unk1154;
    int unk1158;
    int unk115C;
    int unk1160;
    int unk1164;
    int unk1168;
    int unk116C;
    int unk1170;
    int unk1174;
    int unk1178;
    int unk117C;
    int unk1180;
    int unk1184;
    int unk1188;
    int unk118C;
    int unk1190;
    int unk1194;
    int unk1198;
    int unk119C;
    int unk11A0;
    int unk11A4;
    int unk11A8;
    int unk11AC;
    int unk11B0;
    int unk11B4;
    int unk11B8;
    int unk11BC;
    int unk11C0;
    int unk11C4;
    int unk11C8;
    int unk11CC;
    int unk11D0;
    int unk11D4;
    int unk11D8;
    int unk11DC;
    int unk11E0;
    int unk11E4;
    int unk11E8;
    int unk11EC;
    int unk11F0;
    int unk11F4;
    int unk11F8;
    int unk11FC;
    int unk1200;
    int unk1204;
    int unk1208;
    int unk120C;
    int unk1210;
    int unk1214;
    int unk1218;
    int unk121C;
    int unk1220;
    int unk1224;
    int unk1228;
    int unk122C;
    int unk1230;
    int unk1234;
    int unk1238;
    int unk123C;
    int unk1240;
    int unk1244;
    int unk1248;
    int unk124C;
    int unk1250;
    int unk1254;
    int unk1258;
    int unk125C;
    int unk1260;
    int unk1264;
    int unk1268;
    int unk126C;
    int unk1270;
    int unk1274;
    int unk1278;
    int unk127C;
    int unk1280;
    int unk1284;
    int unk1288;
    int unk128C;
    int unk1290;
    int unk1294;
    int unk1298;
    int unk129C;
    int unk12A0;
    int unk12A4;
    int unk12A8;
    int unk12AC;
    int unk12B0;
    int unk12B4;
    int unk12B8;
    int unk12BC;
    int unk12C0;
    int unk12C4;
    int unk12C8;
    int unk12CC;
    int unk12D0;
    int unk12D4;
    int unk12D8;
    int unk12DC;
    int unk12E0;
    int unk12E4;
    int unk12E8;
    int unk12EC;
    int unk12F0;
    int unk12F4;
    int unk12F8;
    int unk12FC;
    int unk1300;
    int unk1304;
    int unk1308;
    int unk130C;
    int unk1310;
    int unk1314;
    int unk1318;
    int unk131C;
    int unk1320;
    int unk1324;
    int unk1328;
    int unk132C;
    int unk1330;
    int unk1334;
    int unk1338;
    int unk133C;
    int unk1340;
    int unk1344;
    int unk1348;
    int unk134C;
    int unk1350;
    int unk1354;
    int unk1358;
    int unk135C;
    int unk1360;
    int unk1364;
    int unk1368;
    int unk136C;
    int unk1370;
    int unk1374;
    int unk1378;
    int unk137C;
    int unk1380;
    int unk1384;
    int unk1388;
    int unk138C;
    int unk1390;
    int unk1394;
    int unk1398;
    int unk139C;
    int unk13A0;
    int unk13A4;
    int unk13A8;
    int unk13AC;
    int unk13B0;
    int unk13B4;
    int unk13B8;
    int unk13BC;
    int unk13C0;
    int unk13C4;
    int unk13C8;
    int unk13CC;
    int unk13D0;
    int unk13D4;
    int unk13D8;
    int unk13DC;
    int unk13E0;
    int unk13E4;
    int unk13E8;
    int unk13EC;
    int unk13F0;
    int unk13F4;
    int unk13F8;
    int unk13FC;
    int unk1400;
    int unk1404;
    int unk1408;
    int unk140C;
    int unk1410;
    int unk1414;
    int unk1418;
    int unk141C;
    int unk1420;
    int unk1424;
    int unk1428;
    int unk142C;
    int unk1430;
    int unk1434;
    int unk1438;
    int unk143C;
    int unk1440;
    int unk1444;
    int unk1448;
    int unk144C;
    int unk1450;
    int unk1454;
    int unk1458;
    int unk145C;
    int unk1460;
    int unk1464;
    int unk1468;
    int unk146C;
    int unk1470;
    int unk1474;
    int unk1478;
    int unk147C;
    int unk1480;
    int unk1484;
    int unk1488;
    int unk148C;
    int unk1490;
    int unk1494;
    int unk1498;
    int unk149C;
    int unk14A0;
    int unk14A4;
    int unk14A8;
    int unk14AC;
    int unk14B0;
    int unk14B4;
    int unk14B8;
    int unk14BC;
    int unk14C0;
    int unk14C4;
    int unk14C8;
    int unk14CC;
    int unk14D0;
    int unk14D4;
    int unk14D8;
    int unk14DC;
    int unk14E0;
    int unk14E4;
    int unk14E8;
    int unk14EC;
    int unk14F0;
    int unk14F4;
    int unk14F8;
    int unk14FC;
    int unk1500;
    int unk1504;
    int unk1508;
    int unk150C;
    int unk1510;
    int unk1514;
    int unk1518;
    int unk151C;
    int unk1520;
    int unk1524;
    int unk1528;
    int unk152C;
    int unk1530;
    int unk1534;
    int unk1538;
    int unk153C;
    int unk1540;
    int unk1544;
    int unk1548;
    int unk154C;
    int unk1550;
    int unk1554;
    int unk1558;
    int unk155C;
    int unk1560;
    int unk1564;
    int unk1568;
    int unk156C;
    int unk1570;
    int unk1574;
    int unk1578;
    int unk157C;
    int unk1580;
    int unk1584;
    int unk1588;
    int unk158C;
    int unk1590;
    int unk1594;
    int unk1598;
    int unk159C;
    int unk15A0;
    int unk15A4;
    int unk15A8;
    int unk15AC;
    int unk15B0;
    int unk15B4;
    int unk15B8;
    int unk15BC;
    int unk15C0;
    int unk15C4;
    int unk15C8;
    int unk15CC;
    int unk15D0;
    int unk15D4;
    int unk15D8;
    int unk15DC;
    int unk15E0;
    int unk15E4;
    int unk15E8;
    int unk15EC;
    int unk15F0;
    int unk15F4;
    int unk15F8;
    int unk15FC;
    int unk1600;
    int unk1604;
    int unk1608;
    int unk160C;
    int unk1610;
    int unk1614;
    int unk1618;
    int unk161C;
    int unk1620;
    int unk1624;
    int unk1628;
    int unk162C;
    int unk1630;
    int unk1634;
    int unk1638;
    int unk163C;
    int unk1640;
    int unk1644;
    int unk1648;
    int unk164C;
    int unk1650;
    int unk1654;
    int unk1658;
    int unk165C;
    int unk1660;
    int unk1664;
    int unk1668;
    int unk166C;
    int unk1670;
    int unk1674;
    int unk1678;
    int unk167C;
    int unk1680;
    int unk1684;
    int unk1688;
    int unk168C;
    int unk1690;
    int unk1694;
    int unk1698;
    int unk169C;
    int unk16A0;
    int unk16A4;
    int unk16A8;
    int unk16AC;
    int unk16B0;
    S_00da40e0_Agent3Funcs m_kAgent3FunctionTable[1];
};
struct S_00da40e0_FilterHolder;
struct S_00da40e0_CollisionInput {
    S_00da40e0_Dispatcher* m_pCollisionDispatcher;
    int unk04;
    int unk08;
    S_00da40e0_FilterHolder* m_iFilter;
};
struct S_00da40e0_FilterHolder : S_00da40e0_CollidableCollidableFilter {
    int unk04;
    int unk08;
};
struct S_00da40e0_Filter : S_00da40e0_FilterHolder, S_00da40e0_ShapeCollectionFilter {
};
struct S_00da40e0_Input {
    const S_00da40e0_CdBody* m_pBodyA;
    const S_00da40e0_CdBody* m_pBodyB;
    const S_00da40e0_ShapeContainer* m_containerA;
    const S_00da40e0_ShapeContainer* m_containerB;
    const S_00da40e0_CollisionInput* m_pRayCastInput;
    S_00da40e0_ContactMgr* m_pContactManager;
    S_00da40e0_ConstraintOwner* m_pConstraintOwner;
};
const S_00da40e0_CdBody* __cdecl FUN_00cfe1d0(const S_00da40e0_CdBody* cdBody, S_00da40e0_CdBody* newCdBodies,
    S_00da40e0_MotionState* newMotionStates, int numSlots, unsigned char& changeCounter);
S_00da40e0_Entry* __cdecl ProcessCollisionEntry(const S_00da40e0_Input& aInput, S_00da40e0_Entry* entry, S_00da40e0_AgentData* agentData);
// hkpAgent1nMachine shape-collection filter visitor (one container side): re-check the filter for
struct ShapeCollectionFilter1n {
    virtual S_00da40e0_Bool IsCollisionEnabled(const S_00da40e0_CollisionInput& input, const S_00da40e0_CdBody& a,
        const S_00da40e0_CdBody& b, const S_00da40e0_ShapeContainer& containerShapeB, unsigned int keyB) const = 0;
    virtual S_00da40e0_Bool IsCollisionEnabled(const S_00da40e0_CollisionInput& input, const S_00da40e0_CdBody& a,
        const S_00da40e0_CdBody& b, const S_00da40e0_ShapeContainer& containerShapeA,
        const S_00da40e0_ShapeContainer& containerShapeB, unsigned int keyA, unsigned int keyB) const = 0;
};
struct Filter1n : S_00da40e0_FilterHolder, ShapeCollectionFilter1n {
};
S_00da40e0_Entry* __cdecl ProcessEntryPair(const S_00da40e0_Input& in, S_00da40e0_Entry* entry, S_00da40e0_AgentData* agentData);
union __declspec(intrin_type) __declspec(align(16)) __m128 {
    float m128_f32[4];
    unsigned __int64 m128_u64[2];
};
extern "C" __m128 _mm_setzero_ps(void);
extern const float DAT_01012054;
struct hkVector4
{
    __m128 m_vComponents;
    void setZero4() { m_vComponents = _mm_setzero_ps(); }
};
struct FourByteState
{
    unsigned char m_ucAgentType;
    unsigned char m_ucNnTrackType;
    unsigned char m_usNumContactPoints;
    unsigned char m_iElementCount;
};
struct ByteStateWithThreeIntegers : public FourByteState
{
    int m_uiCollisionShapeKey;
    int m_unk08;
    int m_unk0C;
};
struct ByteStateWithMixedNumericData : public FourByteState
{
    int m_uiCollisionShapeKey;
    int m_unk08;
    float m_fFloatValue;
    hkVector4 m_vSeparatingNormal;
};
struct hkpAgent1nSector
{
    unsigned int m_uiAgentCount;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0C;

    FourByteState* getBegin() { return (FourByteState*)(this + 1); }
    FourByteState* GetStreamEnd() { return (FourByteState*)((char*)(this + 1) + m_uiAgentCount); }
};
struct AgentSectorPointerArray
{
    hkpAgent1nSector** m_kSectors;
};
struct CollisionAgentContext;
typedef void (__cdecl *InvalidateTimFunc)(FourByteState* entry, void* agentData, CollisionAgentContext& input);
struct CollisionAgentContext
{
    char* m_pCollisionDispatcher;
};
void FUN_00da3510(AgentSectorPointerArray& agentTrack, CollisionAgentContext& input);
typedef void (__cdecl *Da35FuncPtr)(void* entry, void* payload, float fa, float fb, void* holder);
struct Da35Stream {
    int m_iElementCount;
    int unk04;
    int unk08;
    int unk0C;
};
void __cdecl FUN_00da35f0(Da35Stream*** container, float fa, float fb, void** holder);
static void* __cdecl Da35Search(Da35Stream*** container, int key1, int key2, void** out)
{
    Da35Stream** streams = *container;
    Da35Stream* stream = *streams;
    int size = stream->m_iElementCount;
    streams += 1;
    for (;;) {
        unsigned char* end = (unsigned char*)stream + size + 0x10;
        unsigned char* p = (unsigned char*)stream + 0x10;
        do {
            unsigned char cmd = p[0];
            switch (cmd) {
            case 2: case 3: case 6: case 10: case 11: case 14: {
                unsigned char* payload = p + 0x10;
                if (*(int*)(p + 8) == key2 && *(int*)(p + 4) == key1) {
                    *out = payload;
                    return p;
                }
                p += p[3];
                break;
            }
            case 4: case 5: case 12: case 13: {
                unsigned char* payload = p + 0x20;
                if (*(int*)(p + 8) == key2 && *(int*)(p + 4) == key1) {
                    *out = payload;
                    return p;
                }
                p += p[3];
                break;
            }
            case 0:
                p += p[3];
                break;
            case 1:
                return 0;
            case 7: case 8: case 9:
                break;
            default:
                break;
            }
        } while (p < end);
        stream = *streams;
        size = stream->m_iElementCount;
        streams += 1;
    }
}
struct BlockPoolHeap : BlockPoolAllocator {
    virtual void ReleaseBlock(void* p, int numBytes);
    virtual void unk0C();
    virtual void ReturnMemory(void* p, int numBytes);
};
__forceinline BlockPoolHeap& fullHeap()
{
    return static_cast<BlockPoolHeap&>(FUN_00c85750().heap());
}
void FUN_00da42b0(BlockPoolArray* blocks, S_00da40e0_Dispatcher* dispatcher, S_00da40e0_ContactMgr* mgr, S_00da40e0_ConstraintOwner& owner);
#include <string.h>
struct StreamAllocator : BlockPoolAllocator {
    virtual void ReleaseBlock(void*, int);
};
struct StreamRecord { int first; int second; void* third; void* fourth; };
struct StreamHeader { void* a; void* b; void* c; void* d; void* e; void* f; void* g; void* h; };
__forceinline static void streamCopy(void* dst, const void* src, int count) {
    const int* s = (const int*)src;
    int* d = (int*)dst;
    do {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d += 4;
        s += 4;
    } while (--count > 0);
}
void __cdecl FUN_00d2cc70(void*, const void*, unsigned int);
typedef unsigned char* (__cdecl *StreamTransform)(void*, unsigned char*, unsigned char*);
void FUN_00da44d0(int array_arg, int header_arg, void* callback);

typedef float hkReal;
typedef unsigned char hkUchar;
typedef unsigned char hkUint8;
typedef unsigned short hkUint16;
typedef unsigned int hkUint32;
typedef unsigned long __w64 hkUlong;
enum hkResult
{
HK_SUCCESS=0,
HK_FAILURE=1
};
typedef unsigned __w64 hk_size_t;
typedef hkReal hkTime;class FinishingFlag
{
public:
FinishingFlag():m_bFinishing(0){}
int m_bFinishing;
};
class hkClass;
typedef int hkBool32;
class hkBool
{
public:
typedef char CompileTimeTrueType;inline hkBool(bool b)
{
m_cBooleanValue=static_cast<char>(b);
}
inline operator bool()const
{
return m_cBooleanValue !=0;
}
private:
char m_cBooleanValue;};
extern "C"
{
extern const hkReal g_afRealLookupTable[256];
}
class QuantizedFloat8
{
public:
enum{MAX_VALUE=256};
inline QuantizedFloat8(){}
QuantizedFloat8&operator=(const float&fv);
inline QuantizedFloat8(const float f)
{
*this=f;
}
inline operator float()const
{
return g_afRealLookupTable[m_uiFilterValue];
}
public:
hkUint8 m_uiFilterValue;
};template<typename ENUM,typename STORAGE>
class hkEnum
{
public:
hkEnum()
{
}
hkEnum(ENUM e)
{
m_kStorage=static_cast<STORAGE>(e);
}
operator ENUM()const
{
return static_cast<ENUM>(m_kStorage);
}
private:
STORAGE m_kStorage;};
template<typename TYPE>
class ValueWrapper
{
public:
__forceinline ValueWrapper(){}
__forceinline ValueWrapper(TYPE e)
:m_kStorage(e)
{
}
__forceinline TYPE val()const
{
return m_kStorage;
}
__forceinline TYPE operator->()const
{
return m_kStorage;
}
__forceinline operator TYPE()const
{
return val();
}
private:
TYPE m_kStorage;};
extern "C"{
__declspec(dllimport)void*_stdcall TlsGetValue(unsigned long dwTlsIndex);}
template<typename T>
class hkThreadLocalData
{
public:
hkThreadLocalData()
{
m_slotID=TlsAlloc();
}
__forceinline T getData()const
{
return(T)(hkUlong)TlsGetValue(m_slotID);
}
unsigned long m_slotID;};
class hkMemoryAllocator
{
public:
__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}
virtual void*AllocateMemoryBlock(int numBytes)=0;
virtual void ReleaseBlock(void*p,int numBytes)=0;public:
enum MemoryState
{
MEMORY_STATE_OK,
MEMORY_STATE_OUT_OF_MEMORY
};};struct StringPointerTriple
{
public:
__forceinline StringPointerTriple();protected:
ValueWrapper<void*>m_next;};
class NineIntegerRecord
{
public:
__forceinline void*__cdecl operator new(hk_size_t,void*p){return p;}
typedef hkMemoryAllocator Allocator;
static NineIntegerRecord&__cdecl GetMonitorStream();inline Allocator&temp(){return*m_pTemp;}
inline Allocator&heap(){return*m_pStreamAllocator;}
protected:
StringPointerTriple m_aiEntries;
Allocator*m_pTemp;
Allocator*m_pStreamAllocator;
Allocator*m_pDebugAllocator;};
class hkBaseObject
{
public:
static const struct ClassMemberDescriptor Members[];public:
__forceinline hkBaseObject(){}
};
class hkStatisticsCollector;
class hkReferencedObject:public hkBaseObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
virtual ~hkReferencedObject(){}
virtual const hkClass*GetClassType()const;
virtual void CalcContentStatistics(hkStatisticsCollector*collector,const hkClass*cls)const;
public:
enum
{
MASK_MEMSIZE=0x7fff
};
hkUint16 m_usMemSizeAndFlags;
public:
hkReferencedObject(class FinishingFlag flag){}
};

extern "C"{
extern __m128 _mm_add_ss(__m128 _A,__m128 _B);
extern __m128 _mm_add_ps(__m128 _A,__m128 _B);
extern __m128 _mm_sub_ps(__m128 _A,__m128 _B);
extern __m128 _mm_mul_ps(__m128 _A,__m128 _B);
extern __m128 _mm_shuffle_ps(__m128 _A,__m128 _B,unsigned int _Imm8);
extern __m128 _mm_unpackhi_ps(__m128 _A,__m128 _B);
extern __m128 _mm_unpacklo_ps(__m128 _A,__m128 _B);
extern __m128 _mm_movehl_ps(__m128,__m128);
extern __m128 _mm_movelh_ps(__m128,__m128);
extern void _mm_store_ss(float*_V,__m128 _A);};
typedef __m128 hkQuadReal;
class hkVector4_S;
typedef const hkVector4_S&hkVector4Parameter;
class VectorComponentValue
{
public:
VectorComponentValue(const hkQuadReal&x)
:m_vValue(x)
{
}
operator hkReal()const
{
hkReal s;
_mm_store_ss(&s,m_vValue);
return s;
}
private:
hkQuadReal m_vValue;};
class hkVector4_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
__forceinline void operator=(const hkVector4_S&v);
__forceinline void setSub4(const hkVector4_S&a,const hkVector4_S&b);
__forceinline VectorComponentValue dot3(const hkVector4_S&a)const;
__forceinline hkReal&operator()(int i);
__forceinline const hkReal&operator()(int i)const;
__forceinline hkQuadReal&getQuad();
__forceinline const hkQuadReal&getQuad()const;
private:
hkQuadReal m_vComponents;
public:
operator hkQuadReal()const
{
return m_vComponents;
}
};class hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
protected:
hkVector4_S m_kColumn0;};class __declspec(align(16))hkRotation:public hkMatrix3
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
class hkTransform
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
private:
hkRotation m_rotation;};
inline hkQuadReal&hkVector4_S::getQuad()
{
return m_vComponents;
}
inline const hkQuadReal&hkVector4_S::getQuad()const
{
return m_vComponents;
}
inline void hkVector4_S::operator=(const hkVector4_S&v)
{
m_vComponents=v.m_vComponents;
}
inline void hkVector4_S::setSub4(const hkVector4_S&v0,const hkVector4_S&v1)
{
m_vComponents=_mm_sub_ps(v0.m_vComponents,v1.m_vComponents);
}
inline VectorComponentValue hkVector4_S::dot3(const hkVector4_S&a)const
{
hkQuadReal x2=_mm_mul_ps(m_vComponents,a.m_vComponents);
hkQuadReal xySum=_mm_add_ss(_mm_shuffle_ps(x2,x2,(((1)<<6)|((1)<<4)|((1)<<2)|((1)))),x2);
return _mm_add_ss(_mm_shuffle_ps(x2,x2,(((2)<<6)|((2)<<4)|((2)<<2)|((2)))),xySum);}
inline hkReal&hkVector4_S::operator()(int a)
{
return reinterpret_cast<hkReal*>(&m_vComponents)[a];
}
inline const hkReal&hkVector4_S::operator()(int a)const
{
return reinterpret_cast<const hkReal*>(&m_vComponents)[a];
}
class StringCursor
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}static StringCursor&GetMonitorStream()
{
extern hkThreadLocalData<StringCursor*>g_pMonitorStream;
return*g_pMonitorStream.getData();
}
public:
__forceinline char*__cdecl GetStreamStart(){return m_kRayStart.val();}
__forceinline char*__cdecl GetStreamEnd(){return m_kRayEnd.val();}
__forceinline char*__cdecl getCapacityMinus16(){return m_pCurrentCommand.val();}
__forceinline hkBool __cdecl memoryAvailable()
{
return GetStreamEnd()<getCapacityMinus16();
}
__forceinline void __cdecl setEnd(char*ptr){m_kRayEnd=ptr;}
public:
static void __cdecl init();
public:
ValueWrapper<char*>m_kRayStart;
ValueWrapper<char*>m_kRayEnd;
ValueWrapper<char*>m_pRayCursor;
ValueWrapper<char*>m_pCurrentCommand;
hkBool m_bFlag;
public:
struct Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::Command));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
const char*m_pCommandName;
};
struct CommandTimingEntry:public StringCursor::Command
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(StringCursor::CommandTimingEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkUint32 m_uiStartTicks;
hkUint32 m_uiEndTicks;
__forceinline void setTime();
};};
void StringCursor::CommandTimingEntry::setTime()
{
hkUint32 ticks;
__asm{
rdtsc
mov dword ptr[ticks],eax
}
m_uiStartTicks=ticks;
}
class hkAabb
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkVector4_S m_kMinimumCorner;};typedef hkUint16 hkContactPointId;
class hkContactPoint
{
public:
static const struct ClassMemberDescriptor Members[];
inline const hkVector4_S&getPosition()const;
inline const hkVector4_S&getNormal()const;
inline hkReal getDistance()const;
protected:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkVector4_S m_vContactPosition;
hkVector4_S m_vSeparatingNormal;};
inline const hkVector4_S&hkContactPoint::getPosition()const
{
return m_vContactPosition;
}
inline const hkVector4_S&hkContactPoint::getNormal()const
{
return m_vSeparatingNormal;
}
inline hkReal hkContactPoint::getDistance()const
{
return m_vSeparatingNormal(3);
}
class Vector4WithInt24W:public hkVector4_S
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};
enum CollisionShapeType
{
HK_SHAPE_INVALID=0,
HK_SHAPE_SPHERE,
HK_FIRST_SHAPE_TYPE=HK_SHAPE_SPHERE,
HK_SHAPE_CYLINDER,
HK_SHAPE_TRIANGLE,
HK_SHAPE_BOX,
HK_SHAPE_CAPSULE,
HK_SHAPE_CONVEX_VERTICES,
HK_SHAPE_COLLECTION,
HK_SHAPE_BV_TREE,
HK_SHAPE_LIST,
HK_SHAPE_MOPP,
HK_SHAPE_CONVEX_TRANSLATE,
HK_SHAPE_CONVEX_TRANSFORM,
HK_SHAPE_SAMPLED_HEIGHT_FIELD,
HK_SHAPE_EXTENDED_MESH,
HK_SHAPE_TRANSFORM,
HK_SHAPE_COMPRESSED_MESH,
HK_SHAPE_MAX_ID_SPU=HK_SHAPE_COMPRESSED_MESH+1,
HK_SHAPE_CONVEX,
HK_SHAPE_PACKED_CONVEX_VERTICES,
HK_SHAPE_MOPP_EMBEDDED,
HK_SHAPE_CONVEX_PIECE,
HK_SHAPE_MULTI_SPHERE,
HK_SHAPE_CONVEX_LIST,
HK_SHAPE_TRIANGLE_COLLECTION,
HK_SHAPE_MULTI_RAY,
HK_SHAPE_HEIGHT_FIELD,
HK_SHAPE_SPHERE_REP,
HK_SHAPE_BV,
HK_SHAPE_PLANE,
HK_SHAPE_PHANTOM_CALLBACK,
HK_SHAPE_USER0,
HK_SHAPE_USER1,
HK_SHAPE_USER2,
HK_SHAPE_MAX_ID,
HK_SHAPE_ALL=-1
};
class hkpCollisionDispatcher;
enum hkpBufferSize
{
HK_SHAPE_BUFFER_SIZE=512
};
typedef __declspec(align(16))char hkpShapeBuffer[HK_SHAPE_BUFFER_SIZE];
class hkpShapeContainer;
typedef hkUint32 hkpShapeKey;
class ShapeKeyCombination
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
hkpShapeKey m_uiShapeKeyA;
hkpShapeKey m_uiShapeKeyB;};
class hkpConvexShape;
class hkpShape:public hkReferencedObject
{
public:
static const struct ClassMemberDescriptor Members[];
__forceinline hkpShape(CollisionShapeType type);
__forceinline CollisionShapeType getType()const;
protected:
virtual void CalculateAabb(const hkTransform&localToWorld,hkReal tolerance,hkAabb&out)const=0;
public:
static void __cdecl resetShapeFunctions();
public:
public:
hkUlong m_ulUserData;
public:
hkEnum<::CollisionShapeType,hkUint32>m_type;
public:
hkpShape(class FinishingFlag flag):hkReferencedObject(flag)
{
if(flag.m_bFinishing)
{
m_type=HK_SHAPE_INVALID;
}
}
};__declspec(align(16))class AlignedHkpShape:public hkpShape{
AlignedHkpShape();
};
CollisionShapeType hkpShape::getType()const
{
return static_cast<const AlignedHkpShape*>(this)->m_type;
}
class hkpCdBody
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline const hkTransform&getTransform()const;
__forceinline const hkpShape*getShape()const;
public:
explicit __forceinline hkpCdBody(const hkpCdBody*parent);
__forceinline void SetCollisionShapeAndKey(const hkpShape*shape,hkpShapeKey key);
public:
const hkpShape*m_pCollisionShape;
hkpShapeKey m_uiCollisionShapeKey;
const void*m_pMotionState;
const hkpCdBody*m_parent;};
const hkTransform&hkpCdBody::getTransform()const
{
;
return*static_cast<const hkTransform*>(m_pMotionState);
}
const hkpShape*hkpCdBody::getShape()const
{
return m_pCollisionShape;
}
hkpCdBody::hkpCdBody(const hkpCdBody*parent)
{
m_parent=parent;
m_pMotionState=parent->m_pMotionState;
}
void hkpCdBody::SetCollisionShapeAndKey(const hkpShape*shape,hkpShapeKey key)
{
m_pCollisionShape=shape;
m_uiCollisionShapeKey=key;
}
struct GskAgentInput;
class hkpContactMgr;
struct WorldOperationEntry;
class hkpConstraintOwner;
struct hkpCollisionInput_S;
class hkpCollisionAgent;
struct hkpAgentEntry_S
{
hkUchar m_ucAgentType;
hkUchar m_ucNnTrackType;};
typedef void hkpAgentData;
struct AgentProcessingInput
{ValueWrapper<const hkpCdBody*>m_pBodyA;
ValueWrapper<const hkpCdBody*>m_pBodyB;
ValueWrapper<const hkpCdBody*>m_pAdditionalCollidableBody;
ValueWrapper<const GskAgentInput*>m_pRayCastInput;
ValueWrapper<hkpContactMgr*>m_pContactManager;
hkTransform m_kTransform;};
struct AgentSubtypeMarker:public AgentProcessingInput
{};
namespace hkAgent3
{
typedef int AgentType;
typedef hkpAgentData*(__cdecl*CreateFunc)(const AgentProcessingInput&input,hkpAgentEntry_S*entry,hkpAgentData*agentData);
typedef void(__cdecl*DestroyFunc)(hkpAgentEntry_S*entry,hkpAgentData*agentData,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner,hkpCollisionDispatcher*dispatcher);
typedef hkpAgentData*(__cdecl*ProcessFunc)(const AgentSubtypeMarker&input,hkpAgentEntry_S*entry,hkpAgentData*agentData,hkVector4_S*separatingNormalOut,WorldOperationEntry&result);
enum Symmetric
{
IS_SYMMETRIC,
IS_NOT_SYMMETRIC,
IS_NOT_SYMMETRIC_AND_FLIPPED
};
typedef void(__cdecl*SepNormalFunc)(const AgentProcessingInput&input,hkpAgentEntry_S*entry,hkpAgentData*agentData,hkVector4_S&separatingNormalOut);
typedef hkpAgentData*(__cdecl*CleanupFunc)(hkpAgentEntry_S*entry,hkpAgentData*agentData,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
typedef void(__cdecl*RemovePointFunc)(hkpAgentEntry_S*entry,hkpAgentData*agentData,hkContactPointId idToRemove);
typedef void(__cdecl*CommitPotentialFunc)(hkpAgentEntry_S*entry,hkpAgentData*agentData,hkContactPointId iContactPointId);
typedef void(__cdecl*CreateZombieFunc)(hkpAgentEntry_S*entry,hkpAgentData*agentData,hkContactPointId idTobecomeZombie);
typedef void(__cdecl*UpdateFilterFunc)(hkpAgentEntry_S*entry,hkpAgentData*agentData,const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkpCollisionInput_S&input,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
typedef void(__cdecl*CalcStatisticsFunc)(hkpAgentEntry_S*entry,hkpAgentData*agentData,const hkpCollisionInput_S&input,hkStatisticsCollector*collector);
typedef void(__cdecl*InvalidateTimFunc_S)(hkpAgentEntry_S*entry,hkpAgentData*agentData,const hkpCollisionInput_S&input);
typedef void(__cdecl*WarpTimeFunc)(hkpAgentEntry_S*entry,hkpAgentData*agentData,hkTime oldTime,hkTime newTime,const hkpCollisionInput_S&input);}
struct CollisionQualityInfo
{
__declspec(align(16))hkReal m_fMinimumCollisionSeparation;};
class hkpCollisionFilter;
class hkpConvexListFilter;
struct hkpCollisionInput_S
{
public:
hkReal getTolerance()const{return m_fScalar;}
public:
ValueWrapper<hkpCollisionDispatcher*>m_pCollisionDispatcher;
ValueWrapper<hkBool32>m_collisionQuality;
ValueWrapper<hkReal>m_fScalar;
ValueWrapper<const hkpCollisionFilter*>m_iFilter;
ValueWrapper<const hkpConvexListFilter*>m_pConvexListCollisionFilter;
struct AabbBoundsAndScale
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(hkpCollisionInput_S::AabbBoundsAndScale));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkVector4_S m_kAabbMin;
hkVector4_S m_kAabbMaximum;
hkVector4_S m_kAabbScale;
};
AabbBoundsAndScale m_aiValues;};
class hkpContactMgrFactory;
class hkpCdPointCollector;
class hkpCdBodyPairCollector;
struct ShapeSweepParameters;
class hkpCollisionDispatcher:public hkReferencedObject
{
public:
enum{
HK_MAX_RESPONSE_TYPE=8,
HK_MAX_SHAPE_TYPE=32,
HK_MAX_AGENT2_TYPES=64,
HK_MAX_AGENT3_TYPES=16,
HK_MAX_COLLISION_QUALITIES=8
};
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
typedef hkpCollisionAgent*(__cdecl*CreateFunc)(const hkpCdBody&collA,const hkpCdBody&collB,const hkpCollisionInput_S&env,hkpContactMgr*mgr);
typedef void(__cdecl*GetPenetrationsFunc)(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkpCollisionInput_S&input,hkpCdBodyPairCollector&collector);
typedef void(__cdecl*GetClosestPointsFunc)(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const hkpCollisionInput_S&input,hkpCdPointCollector&output);
typedef void(__cdecl*LinearCastFunc)(const hkpCdBody&bodyA,const hkpCdBody&bodyB,const ShapeSweepParameters&input,hkpCdPointCollector&castCollector,hkpCdPointCollector*startCollector);
struct CollisionAgentFunctionTable
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(CollisionAgentFunctionTable));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
CreateFunc m_pCreateFunc;
GetPenetrationsFunc m_pQueryPenetrationsFunc;
GetClosestPointsFunc m_pGetPenetrationsFunc;
LinearCastFunc m_pLinearCastFunc;
hkBool m_bIsFlipped;
hkBool m_bIsPredictive;
CollisionAgentFunctionTable():m_bIsFlipped(false),m_bIsPredictive(false){}
};
struct Agent3FunctionTable
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(Agent3FunctionTable));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
Agent3FunctionTable():m_bIsPredictive(false),m_bAgentFlag1(false),m_bAgentFlag2(false)
{
m_pUpdateFilterFunc=0;
m_pCalcStats=0;
m_pAgentFunction10=0;
m_pAgentFunction11=0;
m_pAgentFunction7=0;
}
__declspec(align(16))hkAgent3::CreateFunc m_pCreateFunc;
hkAgent3::DestroyFunc m_pAgent3DestroyFuncs;
hkAgent3::CleanupFunc m_pAgentFunction3;
hkAgent3::RemovePointFunc m_pAgentFunction4;
hkAgent3::CommitPotentialFunc m_pAgentFunction5;
hkAgent3::CreateZombieFunc m_pCreateZombieFunc;
hkAgent3::UpdateFilterFunc m_pUpdateFilterFunc;
hkAgent3::CalcStatisticsFunc m_pCalcStats;
hkAgent3::InvalidateTimFunc_S m_pAgentFunction10;
hkAgent3::WarpTimeFunc m_pAgentFunction11;
hkAgent3::SepNormalFunc m_pAgentFunction7;
hkAgent3::ProcessFunc m_pAgentFunction8;
hkBool m_bIsPredictive;
hkBool m_bAgentFlag1;
hkBool m_bAgentFlag2;
};
public:
hkpCollisionDispatcher(CreateFunc defaultCreationFunction,hkpContactMgrFactory*defaultContactMgrFactory);
inline hkBool32 hasAlternateType(CollisionShapeType type,CollisionShapeType alternateType);
__forceinline hkAgent3::RemovePointFunc getAgent3RemovePointFunc(hkAgent3::AgentType type);
__forceinline hkAgent3::CommitPotentialFunc getAgent3CommitPotentialFunc(hkAgent3::AgentType type);
__forceinline hkAgent3::CreateZombieFunc getAgent3CreateZombieFunc(hkAgent3::AgentType type);
public:
struct IntegerPair
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(IntegerPair));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
CollisionShapeType m_iSecond;
CollisionShapeType m_iFirst;
};
struct SymmetricAgent3FunctionTable:public Agent3FunctionTable
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(SymmetricAgent3FunctionTable));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
hkAgent3::Symmetric m_eSymmetric;
};
struct AgentTypePairPriority
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(AgentTypePairPriority));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
char m_iAgentTypeA;
char m_iAgentTypeB;
char m_priority;
};
typedef AgentTypePairPriority DebugTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
protected:
void internalRegisterCollisionAgent(hkUchar agentTypesTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE],int agentType,CollisionShapeType typeA,CollisionShapeType typeB,CollisionShapeType origA,CollisionShapeType origB,DebugTable*debugTable,int recursionDepth);
public:
enum CollisionQualityLevel
{
COLLISION_QUALITY_INVALID,
COLLISION_QUALITY_PSI,
COLLISION_QUALITY_SIMPLIFIED_TOI,
COLLISION_QUALITY_TOI,
COLLISION_QUALITY_TOI_HIGHER,
COLLISION_QUALITY_TOI_FORCED,
COLLISION_QUALITY_CHARACTER,
COLLISION_QUALITY_TMP_EXPAND_MANIFOLD
};
hkpContactMgrFactory*m_apContactMgrFactoriesByResponsePair[HK_MAX_RESPONSE_TYPE][HK_MAX_RESPONSE_TYPE];
__declspec(align(16))hkUint32 m_auiAlternateTypeFlags[HK_MAX_SHAPE_TYPE];
int m_iEntryCount;
__declspec(align(16))hkUchar m_agent2TypeMap[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
hkUchar m_agent3TypeMap[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
CollisionAgentFunctionTable m_agent2Funcs[HK_MAX_AGENT2_TYPES];
int m_iAgent2FunctionCount;
__declspec(align(16))hkUchar m_ucAgent2TypeTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
__declspec(align(16))hkUchar m_ucAgent3TypeTable[HK_MAX_SHAPE_TYPE][HK_MAX_SHAPE_TYPE];
SymmetricAgent3FunctionTable m_kAgent3FunctionTable[HK_MAX_AGENT3_TYPES];
public:
hkReal m_fExpectedMaxLinearVelocity;};hkAgent3::RemovePointFunc hkpCollisionDispatcher::getAgent3RemovePointFunc(hkAgent3::AgentType type)
{
return m_kAgent3FunctionTable[type].m_pAgentFunction4;
}
hkAgent3::CommitPotentialFunc hkpCollisionDispatcher::getAgent3CommitPotentialFunc(hkAgent3::AgentType type)
{
return m_kAgent3FunctionTable[type].m_pAgentFunction5;
}
hkAgent3::CreateZombieFunc hkpCollisionDispatcher::getAgent3CreateZombieFunc(hkAgent3::AgentType type)
{
return m_kAgent3FunctionTable[type].m_pCreateZombieFunc;
}
hkBool32 hkpCollisionDispatcher::hasAlternateType(CollisionShapeType type,CollisionShapeType alternateType)
{
;
;
return(m_auiAlternateTypeFlags[type]&(1<<alternateType));
}
class ConvexFeaturePairCache;
class ContactImpulseInfo
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
hkReal m_fAccumulatedImpulse;};class hkContactPointMaterial
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
QuantizedFloat8 m_fSlipAngle;
hkUint8 m_fElasticity;
public:
QuantizedFloat8 m_usFlags;
public:
void reset()
{
m_fSlipAngle.m_uiFilterValue=0;
m_usFlags.m_uiFilterValue=0;
m_fElasticity=0;
m_flags=CONTACT_IS_NEW;
}
enum FlagEnum
{
CONTACT_IS_NEW=1,
CONTACT_USES_SOLVER_PATH2=2,
CONTACT_BREAKOFF_OBJECT_ID=4,
CONTACT_IS_DISABLED=8
};
hkUint8 m_flags;};
class PhysicsMaterial:public ContactImpulseInfo,public hkContactPointMaterial
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}public:
hkReal m_uiUserData;
typedef hkUint32 UserData;};
__declspec(align(16))class ContactDataPhysicsMaterial:public PhysicsMaterial
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}UserData m_aiContactData[7];};class hkpContactMgr:public hkReferencedObject
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;hkReferencedObject*b=static_cast<hkReferencedObject*>(NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes)));b->m_usMemSizeAndFlags=static_cast<hkUint16>(nbytes);;return b;}
enum Type
{
TYPE_SIMPLE_CONSTRAINT_CONTACT_MGR,
TYPE_REPORT_CONTACT_MGR,
TYPE_CONVEX_LIST_CONTACT_MGR,
TYPE_NULL_CONTACT_MGR,
TYPE_USER_CONTACT_MGR,
TYPE_MAX
};__forceinline hkContactPointId addContactPoint(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&output,const ConvexFeaturePairCache*contactCache,hkContactPoint&cp);
__forceinline hkResult reserveContactPoints(int numPoints);
__forceinline void removeContactPoint(hkContactPointId cpId,hkpConstraintOwner&constraintOwner);
public:
virtual hkContactPointId CreateContactPoint(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&output,const ConvexFeaturePairCache*contactCache,hkContactPoint&cp)=0;
virtual hkResult ReserveContactPoints(int numPoints)=0;
virtual void removeContactPointImpl(hkContactPointId cpId,hkpConstraintOwner&constraintOwner)=0;public:
Type m_type;};
hkContactPointId hkpContactMgr::addContactPoint(const hkpCdBody&a,const hkpCdBody&b,const GskAgentInput&input,WorldOperationEntry&output,const ConvexFeaturePairCache*contactCache,hkContactPoint&cp)
{
return CreateContactPoint(a,b,input,output,contactCache,cp);
}
hkResult hkpContactMgr::reserveContactPoints(int numPoints)
{
return ReserveContactPoints(numPoints);
}
void hkpContactMgr::removeContactPoint(hkContactPointId cpId,hkpConstraintOwner&constraintOwner)
{
removeContactPointImpl(cpId,constraintOwner);
}
struct ContactPointWithId
{
hkContactPoint m_kPoint;
ValueWrapper<hkUint32>m_usContactPointId;};class hkStepInfo
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}public:
__declspec(align(16))ValueWrapper<hkTime>m_uiStartTime;};
struct hkpAgent1nSector_S;
struct GskAgentInput:public hkpCollisionInput_S
{
public:
GskAgentInput():m_pAgent1nSector(0){}
public:
hkStepInfo m_pStepInfo;
mutable ValueWrapper<CollisionQualityInfo*>m_pCollisionQualityInfo;
mutable hkpAgent1nSector_S*m_pAgent1nSector;};
class ConvexFeaturePairCache
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
void init(const hkpConvexShape*shapeA,const hkpConvexShape*shapeB,const hkTransform&btoa);};
__declspec(align(16))class HeapContactFeatureCache:public ConvexFeaturePairCache
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}};enum{HK_MAX_CONTACT_POINT=256};
struct CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}
public:
ValueWrapper<ContactPointWithId*>m_pAlignedPairData;
ValueWrapper<hkpConstraintOwner*>m_pConstraintOwner;
ContactPointWithId m_akContactPoints[HK_MAX_CONTACT_POINT];
struct CollisionCacheState
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(CollisionContactResults::CollisionCacheState));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
inline CollisionCacheState();
inline void flip();
public:
hkContactPoint m_vContactPoint;
ValueWrapper<hkReal>m_uiCommandId;
ValueWrapper<hkReal>m_fSeparation;
HeapContactFeatureCache m_kGskCache;
ContactDataPhysicsMaterial m_kProperties;
};
struct CollisionCacheState m_fTimeOfImpact;};
struct WorldOperationEntry:public CollisionContactResults
{
public:
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}public:
struct ContactPointAgentEntry
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(WorldOperationEntry::ContactPointAgentEntry));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
ContactPointWithId*m_vContactPoint;
hkpAgentEntry_S*m_pAgentEntry;
void*m_pUserData;
};
struct ContactPointBuffer
{
__forceinline void*__cdecl operator new(hk_size_t nbytes){;void*obj=NineIntegerRecord::GetMonitorStream().heap().AllocateMemoryBlock(static_cast<int>(nbytes));;return obj;}__forceinline void __cdecl operator delete(void*p){if(p){;NineIntegerRecord::GetMonitorStream().heap().ReleaseBlock(p,sizeof(WorldOperationEntry::ContactPointBuffer));}}__forceinline void*__cdecl operator new(hk_size_t n,void*p){;return p;}__forceinline void*__cdecl operator new[](hk_size_t,void*p){return p;}__forceinline void __cdecl operator delete(void*,void*){}__forceinline void __cdecl operator delete[](void*,void*){}class CommandArgument;
void reset()
{
m_pFirstFreeContactPoint=&m_akContactRecords[0];
m_ppFirstFreeContactPointer=&m_apContactPointPointers[0];
}
ContactPointAgentEntry*m_pFirstFreeContactPoint;
ContactPointWithId**m_ppFirstFreeContactPointer;
ContactPointWithId*m_apContactPointPointers[HK_MAX_CONTACT_POINT];
ContactPointAgentEntry m_akContactRecords[HK_MAX_CONTACT_POINT];
};
public:
ValueWrapper<ContactPointBuffer*>m_akContactRecords;};
namespace hkVector4Util_S
{
__forceinline void __cdecl dot3_3vs3(const hkVector4_S&a0,const hkVector4_S&b0,const hkVector4_S&a1,const hkVector4_S&b1,const hkVector4_S&a2,const hkVector4_S&b2,hkVector4_S&dotsOut);}
inline void __cdecl hkVector4Util_S::dot3_3vs3(const hkVector4_S&a0,const hkVector4_S&b0,const hkVector4_S&a1,const hkVector4_S&b1,const hkVector4_S&a2,const hkVector4_S&b2,hkVector4_S&dotsOut)
{
register hkQuadReal c0=_mm_mul_ps(a0.getQuad(),b0.getQuad());
register hkQuadReal c1=_mm_mul_ps(a1.getQuad(),b1.getQuad());
register hkQuadReal c2=_mm_mul_ps(a2.getQuad(),b2.getQuad());
{hkQuadReal _tmp,_ctmp;_tmp=_mm_unpacklo_ps(c0,c1);_ctmp=_mm_shuffle_ps(_mm_unpackhi_ps(c0,c1),c2,(((3)<<6)|((2)<<4)|((1)<<2)|((0))));c0=_mm_movelh_ps(_tmp,c2);c1=_mm_shuffle_ps(_mm_movehl_ps(c0,_tmp),c2,(((3)<<6)|((1)<<4)|((1)<<2)|((0))));c2=_ctmp;};
dotsOut.getQuad()=_mm_add_ps(_mm_add_ps(c0,c1),c2);}
struct hkpAgent1nTrack_S;
struct ShapeKeyAgentEntry:hkpAgentEntry_S
{
ShapeKeyCombination m_kShapeKeyPair;};
struct EmptyMarker
{};
typedef hkpAgentData*(*hkAgent1nMachine_VisitorCallback)(EmptyMarker&vin,ShapeKeyAgentEntry*entry,hkpAgentData*agentData);
extern "C"
{
void __cdecl ResetAgentTrack(hkpAgent1nTrack_S&agentTrack);
enum hkpAgentMachineMode
{
HKP_AGENT_MACHINE_MODE_1N=1,
HKP_AGENT_MACHINE_MODE_NM=2
};
void __cdecl BuildShapeCollectionBWorldOperations(hkpAgent1nTrack_S&agentTrack,const AgentSubtypeMarker&input,const hkpShapeContainer*shapeContainterB,const hkpShapeKey*hitList,WorldOperationEntry&output);
void __cdecl BuildShapePairWorldOperations(hkpAgent1nTrack_S&agentTrack,const AgentSubtypeMarker&input,const hkpShapeContainer*shapeContainerA,const hkpShapeContainer*shapeCollectionB,const ShapeKeyCombination*hitList,WorldOperationEntry&output);
void __cdecl UpdateAgentTrackShapeFilter(hkpAgent1nTrack_S&agentTrack,EmptyMarker&vin);
void __cdecl hkAgentNmMachine_UpdateShapeCollectionFilter(hkpAgent1nTrack_S&agentTrack,EmptyMarker&vin);
void __cdecl VisitTrackedAgents(hkpAgent1nTrack_S&agentTrack,EmptyMarker&vin,hkpContactMgr*mgr,hkAgent1nMachine_VisitorCallback visitor);
void __cdecl DestroyAgentTrack(hkpAgent1nTrack_S&agentTrack,hkpCollisionDispatcher*dispatch,hkpContactMgr*mgr,hkpConstraintOwner&constraintOwner);
void __cdecl CollideTrackedAgents(hkpAgent1nTrack_S&track,const hkpCollisionInput_S&input);
void __cdecl UpdateTrackedAgentTimes(hkpAgent1nTrack_S&track,hkTime oldTime,hkTime newTime,const hkpCollisionInput_S&input);
ShapeKeyAgentEntry*hkAgent1nMachine_FindAgent(hkpAgent1nTrack_S&agentTrack,ShapeKeyCombination keyPair,hkpAgentData**agentDataOut);
}
class hkpShapeContainer
{
public:
static const struct ClassMemberDescriptor Members[];
virtual ~hkpShapeContainer(){}
virtual int GetNumChildShapes()const;
virtual hkpShapeKey GetFirstKey()const=0;
virtual hkpShapeKey GetNextShapeKey(hkpShapeKey oldKey)const=0;
virtual hkUint32 GetFilterInfoForKey(hkpShapeKey key)const;
virtual const hkpShape*GetShapeForKey(hkpShapeKey key,hkpShapeBuffer&buffer)const=0;};
class hkpSphereRepShape:public hkpShape
{
public:
static const struct ClassMemberDescriptor Members[];
protected:
virtual int GetNumCollisionSpheres()const=0;
public:
hkpSphereRepShape(CollisionShapeType type):hkpShape(type){}
hkpSphereRepShape(FinishingFlag flag):hkpShape(flag){m_type=HK_SHAPE_SPHERE_REP;}
};
class hkpConvexShape:public hkpSphereRepShape
{
public:
static const struct ClassMemberDescriptor Members[];
inline hkReal getRadius()const;
protected:
virtual void GetSupportVertex(hkVector4Parameter direction,Vector4WithInt24W&supportingVertexOut)const=0;
protected:
inline hkpConvexShape(CollisionShapeType type,hkReal radius);
hkReal m_fSphereRadius;
public:
hkpConvexShape(FinishingFlag flag):hkpSphereRepShape(flag){m_type=HK_SHAPE_CONVEX;}
};inline hkReal hkpConvexShape::getRadius()const
{
return m_fSphereRadius;
}
extern hkResult __cdecl FindContactsAgainstConvexShapes(const hkTransform&transA,const hkpConvexShape*shapeA,const hkpConvexShape**shapesB,int numShapesB,const hkTransform&aTb,hkContactPoint**pointsOut);
enum hkContactPairCompare
{
HK_CONTACT_PAIR_NO_CONFLICT,
HK_CONTACT_PAIR_REJECT_NEW,
HK_CONTACT_PAIR_CONFLICT
};
static __forceinline hkContactPairCompare contactPointIsValid(hkReal radiusA,const hkContactPoint&pointToCheck,const CollisionQualityInfo&qi,hkReal radiusB,const ContactPointWithId&referenceCdPoint)
{
const hkContactPoint*referencePoint=&referenceCdPoint.m_kPoint;
hkVector4_S diff;diff.setSub4(referencePoint->getPosition(),pointToCheck.getPosition());
hkVector4_S dots;hkVector4Util_S::dot3_3vs3(pointToCheck.getNormal(),diff,referencePoint->getNormal(),diff,pointToCheck.getNormal(),referencePoint->getNormal(),dots);
hkReal d0=-dots(1);
hkReal d1=dots(0);
hkReal n0n1=dots(2);
d0+=(n0n1-1.0f)*radiusA;
d1+=(n0n1-1.0f)*radiusA;
hkReal radiusSum=radiusA+radiusB;
if(d0>radiusSum)
{
return HK_CONTACT_PAIR_NO_CONFLICT;
}
if(n0n1>0.9999f&&referenceCdPoint.m_usContactPointId==(0xffff))
{
return HK_CONTACT_PAIR_NO_CONFLICT;
}
const hkReal dist0=pointToCheck.getDistance();
const hkReal dist1=referenceCdPoint.m_kPoint.getDistance();
if(referenceCdPoint.m_usContactPointId==(0xffff)&&n0n1<0.8f&&d0+d1<0.1f&&dist0+dist1<-radiusSum*2.0f)
{
return HK_CONTACT_PAIR_CONFLICT;
}
hkReal minDeltaDistanceToAcceptNewPoint=0.0f;
if(referenceCdPoint.m_usContactPointId !=(0xffff))
{
minDeltaDistanceToAcceptNewPoint=qi.m_fMinimumCollisionSeparation*0.05f;
}
if(pointToCheck.getDistance()<=referencePoint->getDistance()-minDeltaDistanceToAcceptNewPoint)
{
return HK_CONTACT_PAIR_NO_CONFLICT;
}
return HK_CONTACT_PAIR_REJECT_NEW;}
// @fnv 0x00da3930
void __cdecl FUN_00da3930(AgentProcessingInput&input,const hkpShapeContainer*shapeCollection,WorldOperationEntry&output)
{
int numConflictContacts=0;
hkUint16 conflictContacts[HK_MAX_CONTACT_POINT];
hkUint16 newIds[HK_MAX_CONTACT_POINT];
hkpShapeBuffer shapeBuffer;
WorldOperationEntry::ContactPointBuffer*potentialContacts=output.m_akContactRecords;
{
const hkpConvexShape*shapeA=static_cast<const hkpConvexShape*>(input.m_pBodyA->getShape());
WorldOperationEntry::ContactPointAgentEntry*contactRefPtr=&potentialContacts->m_akContactRecords[0];
for(int i=0;contactRefPtr<potentialContacts->m_pFirstFreeContactPoint;i++,contactRefPtr++)
{
newIds[i]=(0xffff);
ContactPointWithId*check=contactRefPtr->m_vContactPoint;
{
hkBool hasConflict=false;
for(ContactPointWithId**pref=&potentialContacts->m_apContactPointPointers[0];pref<potentialContacts->m_ppFirstFreeContactPointer;pref++)
{
ContactPointWithId*ref=*pref;
if(check !=ref)
{
hkReal radiusB=0.0f;
hkContactPairCompare contactPairCheckResult=contactPointIsValid(shapeA->getRadius(),check->m_kPoint,*input.m_pRayCastInput->m_pCollisionQualityInfo.val(),radiusB,*ref);
if(contactPairCheckResult !=HK_CONTACT_PAIR_NO_CONFLICT)
{
if(contactPairCheckResult==HK_CONTACT_PAIR_REJECT_NEW)
{
goto tryNextPoint;
}
hasConflict=true;
}
}
}
if(hasConflict)
{
conflictContacts[numConflictContacts++]=hkUint16(i);
}
}
{
WorldOperationEntry::ContactPointAgentEntry*toCommit=&potentialContacts->m_akContactRecords[i];
ShapeKeyAgentEntry*entry=reinterpret_cast<ShapeKeyAgentEntry*>(toCommit->m_pAgentEntry);
const hkpShape*shape=shapeCollection->GetShapeForKey(entry->m_kShapeKeyPair.m_uiShapeKeyB,shapeBuffer);
hkpCdBody modifiedBodyB(input.m_pBodyB);
modifiedBodyB.SetCollisionShapeAndKey(shape,entry->m_kShapeKeyPair.m_uiShapeKeyB);
newIds[i]=input.m_pContactManager->addContactPoint(*input.m_pBodyA,modifiedBodyB,*input.m_pRayCastInput,output,0,toCommit->m_vContactPoint->m_kPoint);
if(newIds[i]!=(0xffff))
{
input.m_pContactManager->reserveContactPoints(-1);
}
}
tryNextPoint:;
}
}
{
hkpCollisionDispatcher*dis=input.m_pRayCastInput->m_pCollisionDispatcher;
for(int a=0;a<numConflictContacts;a++)
{
int i=conflictContacts[a];
WorldOperationEntry::ContactPointAgentEntry*cr=&potentialContacts->m_akContactRecords[i];
dis->getAgent3CreateZombieFunc(cr->m_pAgentEntry->m_ucNnTrackType)(cr->m_pAgentEntry,cr->m_pUserData,(0xffff));
}
}
while(numConflictContacts>=2)
{
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="T" "t" "Conflicts";h->setTime();mStream.setEnd((char*)(h+1));}};
int p0=0;
int p1=1;
{
hkReal minDot=2.0f;
for(int a=0;a<numConflictContacts;a++)
{
WorldOperationEntry::ContactPointAgentEntry*refA=&potentialContacts->m_akContactRecords[conflictContacts[a]];
const hkVector4_S*normalA=&refA->m_vContactPoint->m_kPoint.getNormal();
for(int b=a+1;b<numConflictContacts;b++)
{
WorldOperationEntry::ContactPointAgentEntry*refB=&potentialContacts->m_akContactRecords[conflictContacts[b]];
hkReal d=normalA->dot3(refB->m_vContactPoint->m_kPoint.getNormal());
if(d<minDot)
{
minDot=d;p0=a;p1=b;
}
}
}
}
{
WorldOperationEntry::ContactPointAgentEntry*ref0=&potentialContacts->m_akContactRecords[conflictContacts[p0]];
WorldOperationEntry::ContactPointAgentEntry*ref1=&potentialContacts->m_akContactRecords[conflictContacts[p1]];
ShapeKeyAgentEntry*header0=reinterpret_cast<ShapeKeyAgentEntry*>(ref0->m_pAgentEntry);
ShapeKeyAgentEntry*header1=reinterpret_cast<ShapeKeyAgentEntry*>(ref1->m_pAgentEntry);
const hkpConvexShape*shapeA=static_cast<const hkpConvexShape*>(input.m_pBodyA->getShape());
if(!input.m_pRayCastInput->m_pCollisionDispatcher->hasAlternateType(shapeA->getType(),HK_SHAPE_CONVEX)){break;}
const hkpConvexShape*shape0=static_cast<const hkpConvexShape*>(shapeCollection->GetShapeForKey(header0->m_kShapeKeyPair.m_uiShapeKeyB,shapeBuffer));
if(!input.m_pRayCastInput->m_pCollisionDispatcher->hasAlternateType(shape0->getType(),HK_SHAPE_CONVEX)){break;}
hkpShapeBuffer shapeBuffer2;
const hkpConvexShape*shape1=static_cast<const hkpConvexShape*>(shapeCollection->GetShapeForKey(header1->m_kShapeKeyPair.m_uiShapeKeyB,shapeBuffer2));
if(!input.m_pRayCastInput->m_pCollisionDispatcher->hasAlternateType(shape1->getType(),HK_SHAPE_CONVEX)){break;}
const hkpConvexShape*shapesB[2]={shape0,shape1};
hkContactPoint*points[2]={&ref0->m_vContactPoint->m_kPoint,&ref1->m_vContactPoint->m_kPoint};
FindContactsAgainstConvexShapes(input.m_pBodyA->getTransform(),shapeA,shapesB,2,input.m_kTransform,points);
}
conflictContacts[p1]=conflictContacts[--numConflictContacts];
conflictContacts[p0]=conflictContacts[--numConflictContacts];
{StringCursor&mStream=StringCursor::GetMonitorStream();if(mStream.memoryAvailable()){StringCursor::CommandTimingEntry*h=reinterpret_cast<StringCursor::CommandTimingEntry*>(mStream.GetStreamEnd());h->m_pCommandName="E" "t" "";h->setTime();mStream.setEnd((char*)(h+1));}};
}
if(numConflictContacts)
{
if(newIds[conflictContacts[0]]!=(0xffff))
{
input.m_pContactManager->removeContactPoint(newIds[conflictContacts[0]],*output.m_pConstraintOwner.val());
newIds[conflictContacts[0]]=(0xffff);
input.m_pContactManager->reserveContactPoints(1);
}
}
{
hkpCollisionDispatcher*dis=input.m_pRayCastInput->m_pCollisionDispatcher;
WorldOperationEntry::ContactPointAgentEntry*cr=potentialContacts->m_pFirstFreeContactPoint;
int numPotential=int(cr-&potentialContacts->m_akContactRecords[0]);
for(int i=numPotential-1;i>=0;i--)
{
cr--;
hkContactPointId iContactPointId=newIds[i];
if(iContactPointId !=(0xffff))
{
dis->getAgent3CommitPotentialFunc(cr->m_pAgentEntry->m_ucNnTrackType)(cr->m_pAgentEntry,cr->m_pUserData,iContactPointId);
cr->m_vContactPoint->m_usContactPointId=iContactPointId;
}
else
{
input.m_pContactManager->reserveContactPoints(-1);
dis->getAgent3RemovePointFunc(cr->m_pAgentEntry->m_ucNnTrackType)(cr->m_pAgentEntry,cr->m_pUserData,iContactPointId);
output.m_pAlignedPairData=output.m_pAlignedPairData-1;
*cr->m_vContactPoint=*output.m_pAlignedPairData;
}
}
}
}
