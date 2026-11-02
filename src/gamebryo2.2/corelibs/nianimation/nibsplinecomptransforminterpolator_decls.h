// private decls for nibsplinecomptransforminterpolator.cpp (army-glm-5230)
class NiBinaryStream
{
  public:
    void* vtable;
    unsigned int position;
    unsigned int(__cdecl* read)(NiBinaryStream*, void*, unsigned int, unsigned int*, unsigned int);
    void ReadComp(void* value, unsigned int size, unsigned int componentSize)
    {
        unsigned int uiComponentSize = componentSize;
        position += read(this, value, size, &uiComponentSize, 1);
    }
};
