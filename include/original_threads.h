#ifndef FNV_ORIGINAL_THREADS_H
#define FNV_ORIGINAL_THREADS_H

class OSGlobals;
// These declarations are bound by the generated interop layer, and resolved
// to the original executable addresses by the COFF comparator manifest.
extern OSGlobals* g_osGlobals;
unsigned int gm_GetCurrentThreadId();

#endif
