#ifndef FNV_ORIGINAL_GARBAGECOLLECTOR_H
#define FNV_ORIGINAL_GARBAGECOLLECTOR_H

// Original PC lock adapters forward to the shared collector spin lock.
// The PC callers also pass the blocking-mode argument retained by this API.
void LockGarbageCollector(const char* name, bool blocking);
void UnlockGarbageCollector(bool blocking);

#endif
