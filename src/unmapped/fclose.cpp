
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

extern "C" int __cdecl _fclose(void*);

struct FUN_00d2be50
{
    int m_iWordAt00;
    int m_iWordAt04;
    void* m_8;
    char m_iThirdValue;
    void Close();
};

// @fnv 0x00d2be50
void FUN_00d2be50::Close()
{
    if (m_8 && m_iThirdValue)
        _fclose(m_8);
    m_8 = 0;
}
