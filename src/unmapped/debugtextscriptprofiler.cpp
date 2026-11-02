// src/unmapped/debugtextscriptprofiler.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/debug/debugtextpages/debugtextscriptprofiler.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct Node
{
    unsigned int data;
};
struct ScriptPool
{
    void* FUN_0049fa80();
};
struct ScriptList : ScriptPool
{
    void FUN_0076b660(unsigned int* element);
    void FUN_0049fa20(Node*);
};
// Stores the value pointed to by element into the node obtained from FUN_0049fa80 at offset 8, then passes the node to FUN_0049fa20.
// @fnv 0x0076b660
void ScriptList::FUN_0076b660(unsigned int* puiElement)
{
    Node* node = static_cast<Node*>(this->FUN_0049fa80());
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(node) + 8) = *puiElement;
    FUN_0049fa20(node);
}
