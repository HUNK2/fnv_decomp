
// bscore/console/bscriticalsection_console_decls.h: declares BSCriticalSectionEntry
struct BSCriticalSectionEntry
{
    BSCriticalSectionEntry* next;
    unsigned int key;
    unsigned int value;
};
class RecursiveLock
{
  public:
    virtual void vfn_0();
    virtual unsigned int vfn_4(unsigned int key);
    unsigned int bucketCount;
    BSCriticalSectionEntry** buckets;
    void Unlock(BSCriticalSectionEntry** entry, unsigned int* key, unsigned int* value);
};
