// fallout_shared/gridarray.cpp: GridArray (7 functions)

class GridArray
{
  public:
    GridArray();
    virtual ~GridArray();
    int GetCenterX() const;
    int m_fCenterY() const;
    unsigned int GetGridDimension() const;
    void SetDimension(unsigned int dimension);
    virtual void Init();
    virtual void DetachAllCells();
    virtual void AttachAllCells();
    virtual bool SetGridPosition(int x, int y);
    virtual void Shift(int x, int y);
    virtual void Detach(unsigned int, unsigned int) = 0;
    virtual void ClearTileExtraPair(unsigned int, unsigned int) = 0;
    virtual void MoveItem(unsigned int, unsigned int, unsigned int, unsigned int) = 0;
    virtual void SwapTileExtraPair(unsigned int, unsigned int, unsigned int, unsigned int) = 0;

  protected:
    int iHorizontalPixelCenterObj;
    int iCenterPixelY;
    unsigned int uiDimension;
};

// @fnv 0x004b9e70
void GridArray::Init()
{
    iCenterPixelY = -10000;
    iHorizontalPixelCenterObj = -10000;
}

// @fnv 0x004b9eb0
void GridArray::DetachAllCells()
{
    for (unsigned int i = 0; i < uiDimension; ++i)
    {
        for (unsigned int j = 0; j < uiDimension; ++j)
        {
            Detach(i, j);
        }
    }
}

struct S004b9e20
{
    void FUN_004b9e50();
    void* DestroyIfFlagged(unsigned int);
};
void _Deallocate(void*);
// Calls FUN_004b9e50, then deallocates this when bit 0 of flags is set, and returns this.
// @fnv 0x004b9e20
void* S004b9e20::DestroyIfFlagged(unsigned int flags)
{
    FUN_004b9e50();
    if (flags & 1)
        _Deallocate(this);
    return this;
}

extern "C" void* DAT_01020634;

struct FUN_004b9e50_shell
{
    void __thiscall FUN_004b9e50();
};

// @fnv 0x004b9e50
void __thiscall FUN_004b9e50_shell::FUN_004b9e50()
{
    *reinterpret_cast<void**>(this) = &DAT_01020634;
}

struct FUN_004b9e90_shell : GridArray
{
    void CallVirtualMethod2();
};

// @fnv 0x004b9e90
void FUN_004b9e90_shell::CallVirtualMethod2()
{
    ((void(__thiscall*)(GridArray*))(*reinterpret_cast<void***>(this))[2])(this);
}

struct FUN_004b9f10_shell : GridArray
{
    bool ShiftToCell(int aiX, int aiY);
};

// Computes the offset from the current cell to (aiX, aiY), shifts by it, and returns whether the offset was non-zero.
// @fnv 0x004b9f10
bool FUN_004b9f10_shell::ShiftToCell(int aiX, int aiY)
{
    int ioffX = aiX - GetCenterX();
    int ioffY = aiY - m_fCenterY();
    Shift(ioffX, ioffY);
    if (ioffX || ioffY)
        return true;
    else
        return false;
}

int FUN_00ec7d40(int);
struct FUN_004b9f70_shell : GridArray
{
    void ShiftGrid(int x, int y);
};

// @fnv 0x004b9f70
void FUN_004b9f70_shell::ShiftGrid(int aiShiftX, int aiShiftY)
{
    unsigned int j = 0;
    unsigned int i = 0;
    iHorizontalPixelCenterObj += aiShiftX;
    iCenterPixelY += aiShiftY;
    if ((unsigned int)FUN_00ec7d40(aiShiftX) >= uiDimension || (unsigned int)FUN_00ec7d40(aiShiftY) >= uiDimension)
    {
        DetachAllCells();
        return;
    }
    while (aiShiftX != 0)
    {
        if (aiShiftX < 0)
        {
            for (i = 0; i < uiDimension; ++i)
            {
                j = uiDimension - 1;
                Detach(j, i);
                for (; j > 0; --j)
                    MoveItem(j - 1, i, j, i);
                ClearTileExtraPair(j, i);
            }
            ++aiShiftX;
        }
        else
        {
            for (i = 0; i < uiDimension; ++i)
            {
                j = 0;
                Detach(j, i);
                for (; j < uiDimension - 1; ++j)
                    MoveItem(j + 1, i, j, i);
                ClearTileExtraPair(j, i);
            }
            --aiShiftX;
        }
    }
    while (aiShiftY != 0)
    {
        if (aiShiftY < 0)
        {
            for (j = 0; j < uiDimension; ++j)
            {
                i = uiDimension - 1;
                Detach(j, i);
                for (; i > 0; --i)
                    MoveItem(j, i - 1, j, i);
                ClearTileExtraPair(j, i);
            }
            ++aiShiftY;
        }
        else
        {
            for (j = 0; j < uiDimension; ++j)
            {
                i = 0;
                Detach(j, i);
                for (; i < uiDimension - 1; ++i)
                    MoveItem(j, i + 1, j, i);
                ClearTileExtraPair(j, i);
            }
            --aiShiftY;
        }
    }
}
