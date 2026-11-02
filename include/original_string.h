#ifndef FNV_ORIGINAL_STRING_H
#define FNV_ORIGINAL_STRING_H

// recovered from the char Set body and the original unsigned maximum and
// strlen forwarding bodies. They call the original code during reconstruction.
template <class T> unsigned int BSStringLength(const T* text);
unsigned int BSStringCapacityMaximum(unsigned int length, unsigned int minimum);

#endif
