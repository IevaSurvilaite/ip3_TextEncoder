//Isvestine klase

#ifndef REVERSE_ENCODING_H
#define REVERSE_ENCODING_H

#include "EncodingStrategy.h"
#include <string>

class ReverseEncoding : public EncodingStrategy
{
public:
    std::string encode(const std::string& text) const override;
};


#endif // REVERSE_ENCODING_H
