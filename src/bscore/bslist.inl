
#include "bslist_decls.h"
template<>
// @fnv 0x00aa8a80
OEI::IO::IORequest* BSPointerListBase<OEI::IO::IORequest*>::RemoveHead()
{
    BSListNode<OEI::IO::IORequest*>* item = m_pkHead;
    m_pkHead = m_pkHead->next;
    if (m_pkHead)
        m_pkHead->previous = 0;
    else
        m_pkTail = 0;
    OEI::IO::IORequest* result = item->data;
    vfn_08(item);
    --m_uiCount;
    return result;
}
