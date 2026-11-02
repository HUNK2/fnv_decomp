
class NiTriShapeData {
public:
    class IndexBufferBlock {
    public:
        IndexBufferBlock();
        unsigned short* m_pIndices;
        unsigned short* m_pCurrentIndex;
        unsigned int m_uiIndexCapacity;
        unsigned int m_uiUsedIndexCount;
        IndexBufferBlock* m_pkNext;
    };
};

// MSVC emits its vector constructor iterator for this array initialization.
// @fnv 0x00401050
static NiTriShapeData::IndexBufferBlock s_SNAMemBlocks[2];
