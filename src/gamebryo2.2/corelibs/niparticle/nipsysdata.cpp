
#include "nipsysdata_types_NiPSysData.h"
#include "nipsysdata_types_NiStream.h"
#include "nipsysdata_types_NiParticleInfo.h"
#include "nipsysdata_types_NiQuaternion.h"
#include "MemoryManager.h"
#include "nipsysdata_stream.h"

extern MemoryManager g_memoryManager;
void* _NiMalloc(unsigned int size);
extern "C" void* fnv_zlib_memset(void* dst, int value, unsigned long size);
