//pastovi klase+antrastes failas

/*
Author: Ieva Survilaite, VU Software Engineering 1 course 1 group

TextEncoder - strategy sablonas.
Bazine klase EncodingStrategy apibrezia kodavimo pasirinkimo strategija,
o konkretus ReverseEncoding, LeetSpeakEncoding ja igyvendina.
Pastovi klase TextEncoder deleguoja teksto kodavima.

Using Makefile: creates main.exe and tests.exe files.
*/

#ifndef TEXT_ENCODER_H
#define TEXT_ENCODER_H

#include "EncodingStrategy.h"
#include <string>
#include <memory>

class TextEncoder
{
private:
    std::unique_ptr<EncodingStrategy> strategy;

public:
    TextEncoder(std::unique_ptr<EncodingStrategy> strategy);
    void setStrategy(std::unique_ptr<EncodingStrategy> strategy);
    std::string encode(const std::string& text) const;
};

#endif // TEXT_ENCODER_H
