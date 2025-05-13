//Bazine klase (strategy interface)

#ifndef ENCODING_STRATEGY_H
#define ENCODING_STRATEGY_H

#include <string>

class EncodingStrategy
{
public:
    virtual ~EncodingStrategy() = default;
    virtual std::string encode(const std::string& text) const = 0;
};

#endif // ENCODING_STRATEGY_H
