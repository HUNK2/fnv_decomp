
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

// ResolveRelativePath: resolve a path, strip leading "..\\" components from rel,
// and copy the result into out (cdecl, /MT /Od /GS /EHsc).

extern "C" char DAT_010a46be[];
extern "C" char DAT_010a46c8[];

void __cdecl FUN_00ec7f1e(const char* a1, int a2, int a3, char* buf2, int size, int a6, int a7, int a8, int a9);
unsigned int __cdecl FUN_00ec6130(const char* s);
int __cdecl FUN_00ec8a19(const char* a, const char* b, unsigned int n);
void __cdecl FUN_00ec6bd2(char* dst, unsigned int size, const char* src);
void __cdecl FUN_00ec65a6(char* dst, unsigned int size, const char* src);
void __cdecl FUN_00ec408c();

// @fnv 0x00afe830
void __cdecl ResolveRelativePath(const char* aBasePath, const char* aRelPath, char* aOutPath)
{
    char buf2[0x104];
    aOutPath[0] = 0;
    FUN_00ec7f1e(aBasePath, 0, 0, buf2, 0x104, 0, 0, 0, 0);

    char* pX = buf2;
    int len5 = FUN_00ec6130(pX);
    if (pX[len5 - 1] == '\\')
    {
        pX[len5 - 1] = 0;
    }

    bool stripped3 = false;
    char* lastSep;
    while (FUN_00ec8a19(aRelPath, "..\\", 3) == 0)
    {
        stripped3 = true;
        lastSep = pX;
        len5 = FUN_00ec6130(pX);
        for (int i2 = len5 - 1; i2 > 0; i2--)
        {
            if (pX[i2] == '\\')
            {
                lastSep = pX + i2;
                break;
            }
        }
        if (lastSep != 0)
        {
            *lastSep = 0;
            aRelPath += 3;
        }
        else
        {
            pX = DAT_010a46be;
        }
    }

    if (stripped3)
    {
        FUN_00ec6bd2(aOutPath, 0x104, pX);
        FUN_00ec6bd2(aOutPath, 0x104, DAT_010a46c8);
        FUN_00ec6bd2(aOutPath, 0x104, aRelPath);
    }
    else
    {
        FUN_00ec65a6(aOutPath, 0x104, aRelPath);
    }
}
