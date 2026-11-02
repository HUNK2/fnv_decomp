// gamebryo2.2/corelibs/nimain/niimageconverter_worker.h: declares NiImageConverter
#ifndef NIIMAGECONVERTER_WORKER_H
#define NIIMAGECONVERTER_WORKER_H


class NiImageConverter
{
  public:
    static NiImageConverter* GetSharedImageConverter();
};

extern NiImageConverter* DAT_011f4a7c;

#endif
