#ifndef NIDEFAULTAVOBJECTPALETTE_MAPS_H
#define NIDEFAULTAVOBJECTPALETTE_MAPS_H


class ShaderBufferRecord;

template <class T> class NiTStringPointerMap
{
  public:
    bool GetAt(const char*, T&);
};

#endif
