#include "niconsolerenderstate_decls.h"
class NiFixedString { public: int value; };
extern NiFixedString EmptyFS;
extern char g_NiObjectNETExtraDataLock;
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(void*);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(void*);
class NiTexture { public: const NiFixedString& GetFilename(); };
class NiExtraData : public NiTexture {};
class NiAVObject {
public:
 char pad[16];
 NiExtraData** data;
 unsigned short count;
 NiExtraData* GetExtraData(const NiFixedString& key);
};
// @fnv 0x00a5bdd0
NiExtraData* NiAVObject::GetExtraData(const NiFixedString& key) {
 if (key.value == EmptyFS.value) return 0;
 EnterCriticalSection(&g_NiObjectNETExtraDataLock);
 short low = 0;
 short high = count - 1;
 short mid;
 while (low <= high) {
  mid = (high + low) >> 1;
  int diff = key.value;
  diff -= data[mid]->GetFilename().value;
  if (diff == 0) {
   LeaveCriticalSection(&g_NiObjectNETExtraDataLock);
   return data[mid];
  }
  if (diff > 0) low = mid + 1;
  else high = mid - 1;
 }
 LeaveCriticalSection(&g_NiObjectNETExtraDataLock);
 return 0;
}
