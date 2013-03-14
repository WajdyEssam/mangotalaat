#ifndef RECIEPTREADER_H
#define RECIEPTREADER_H

#include "reciept.h"

class RecieptReader
{
public:
    static Reciept read(QString fileName);
};

#endif // RECIEPTREADER_H
