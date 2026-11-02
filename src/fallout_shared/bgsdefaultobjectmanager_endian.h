// Unit-private declaration, from the supplied BSEndian symbol binding and accepted calibration.
#ifndef FNV_BGSDEFAULTOBJECTMANAGER_ENDIAN_H
#define FNV_BGSDEFAULTOBJECTMANAGER_ENDIAN_H

template <int Value> struct EndianSizeTag
{
};
void BSEndian(unsigned int* apData, EndianSizeTag<4> aeType);
#endif
