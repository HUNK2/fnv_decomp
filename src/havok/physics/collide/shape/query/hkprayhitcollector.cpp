
// src/havok/physics/collide/shape/query/hkprayhitcollector.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/projects/fallout/code/havok/source/physics/collide/shape/query/hkprayhitcollector.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

struct LinkedEntry
{
    int unk00;
    int value;
    int unk08;
    LinkedEntry* next;
};

// Walks the linked list from head, stores each node's value into output in reverse order up to capacity-1, then writes -1 and returns the count written plus one.
// @fnv 0x00cf0860
int CollectValuesReversed(int* paiValues, int capacity, LinkedEntry* head)
{
    LinkedEntry* entries[8];
    LinkedEntry* current = head;
    int count = 0;
    while (current->next)
    {
        entries[count] = current;
        current = current->next;
        ++count;
    }

    int written = 0;
    if (count > 0)
    {
        int limit = capacity - 1;
        do
        {
            if (written >= limit)
                break;
            --count;
            paiValues[written] = entries[count]->value;
            ++written;
        } while (count > 0);
    }
    paiValues[written] = -1;
    return written + 1;
}
