
#include "nitpool_decls.h"
template<>
// @fnv 0x00e7f160
void ObjectPool<D3DRenderStateGroup,NiTNewInterface<D3DRenderStateGroup> >::AddPoolBlock(unsigned int n) {
 ObjectPoolBlock<D3DRenderStateGroup,NiTNewInterface<D3DRenderStateGroup> >* p = new ObjectPoolBlock<D3DRenderStateGroup,NiTNewInterface<D3DRenderStateGroup> >(n);
 for (unsigned int i=0; i<n; ++i) freeObjects.Add(p->GetAt(i));
 p->next = containers;
 containers = p;
}
