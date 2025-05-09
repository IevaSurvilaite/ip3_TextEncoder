//Isvestine klase

#ifndef LEET_SPEAK_ENCODING_H
#define LEET_SPEAK_ENCODING_H

#include "EncodingStrategy.h"
#include <string>
#include <unordered_map>

class LeetSpeakEncoding : public EncodingStrategy
{
private:
    static const std::unordered_map<char, std::string> leetMap;
public:
    std::string encode(const std::string& text) const override;
};

#endif // LEET_SPEAK_ENCODING_H
