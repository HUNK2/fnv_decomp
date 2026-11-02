
// src/havok/physics/utilities/dynamics/savecontactpoints/hkpsavecontactpointsendianutil.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/utilities/dynamics/savecontactpoints/hkpsavecontactpointsendianutil.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct S_00e062a0_Block
{
    int unk00;
};

struct S_00e062a0_Base
{
    int unk00;
};

struct S_00e062a0_Mesh : S_00e062a0_Base
{
    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
    int unk24;
    unsigned char m_ucCount;
    unsigned char unk29;
    unsigned char m_ucStride;
    unsigned char unk2B;
    int unk2C;
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    char* m_pcData;
    int m_iDataSize;
    int unk58;
    int unk5C;
    int unk60;
    int unk64;
    int unk68;
    int unk6C;
    int unk70;
    S_00e062a0_Block m_kBlockA;
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
    S_00e062a0_Block m_kBlockB;
    int unk118;
    int unk11C;
    int unk120;
    int unk124;
    int unk128;
    int m_iFormat;
};

struct S_00e062a0_Tag
{
    S_00e062a0_Tag()
    {}
    int m_iValue;
};

struct S_00e062a0_Flag
{
    bool m_bValue;
};

void ProcessInput(void* pkStream, S_00e062a0_Block* pkBlockA, S_00e062a0_Block* pkBlockB, S_00e062a0_Flag kFlag,
                  S_00e062a0_Flag* pkFlag, const S_00e062a0_Tag& kTag);

template <class T> inline void S_00e062a0_Swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

static inline void S_00e062a0_Swap32(char* pc)
{
    char* pcEnd = pc + 3;
    S_00e062a0_Swap(pc[0], pcEnd[0]);
    S_00e062a0_Swap(pc[1], pcEnd[-1]);
}

// @fnv 0x00e062a0
void SwapMeshRecords(void* pkStream, S_00e062a0_Mesh* pkMesh)
{
    S_00e062a0_Flag kFlag;
    kFlag.m_bValue = true;
    ProcessInput(pkStream, &pkMesh->m_kBlockA, &pkMesh->m_kBlockB, kFlag, &kFlag, S_00e062a0_Tag());

    int iStride = pkMesh->m_ucStride;
    int iRecordCount = pkMesh->m_iDataSize / iStride;
    pkMesh->m_iFormat = 0x103;
    for (int iRecordIndex = 0; iRecordIndex < iRecordCount; iRecordIndex++)
    {
        char* pcRecord = pkMesh->m_pcData + iRecordIndex * iStride;
        S_00e062a0_Swap32(pcRecord + 0x10);
        S_00e062a0_Swap32(pcRecord);
        S_00e062a0_Swap32(pcRecord + 4);
        S_00e062a0_Swap32(pcRecord + 8);
        for (int j = 0; j < pkMesh->m_ucCount * 2; j++)
            S_00e062a0_Swap32(&pcRecord[0x14 + j * 4]);
    }
}
