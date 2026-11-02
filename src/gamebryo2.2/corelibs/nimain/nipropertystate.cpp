// gamebryo2.2/corelibs/nimain/nipropertystate.cpp: free functions (1 function)

#include "nipropertystate_decls.h"

// Copies the seven property pointers from other, releasing the old references and adding references to the new ones.
// @fnv 0x00a89900
NiPropertyState& NiPropertyState::operator=(const NiPropertyState& other)
{
    for (unsigned int i = 0; i < 7; ++i)
    {
        if (m_spProperties[i] != other.m_spProperties[i])
        {
            if (m_spProperties[i])
                m_spProperties[i]->DecRefCount();
            m_spProperties[i] = other.m_spProperties[i];
            if (m_spProperties[i])
                m_spProperties[i]->IncRefCount();
        }
    }
    return *this;
}
