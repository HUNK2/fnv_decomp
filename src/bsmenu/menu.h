// bsmenu/menu.h: declares MenuValueDescriptor
#ifndef FNV_BSMENU_MENU_H
#define FNV_BSMENU_MENU_H
#include "menu_decls.h"
class MenuValueDescriptor
{
  public:
    unsigned int m_uiValueId;
    char* m_pName;
    ~MenuValueDescriptor();
};
// @fnv 0x00a0be70
MenuValueDescriptor::~MenuValueDescriptor()
{
    if (m_pName)
    {
        void* pointer = m_pName;
        g_memoryManager.Deallocate(pointer);
    }
    m_pName = 0;
}
#endif
