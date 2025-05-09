#include "TextEncoder.h"

TextEncoder::TextEncoder(std::unique_ptr<EncodingStrategy> initialStrategy)
    : strategy(std::move(initialStrategy)) {}

void TextEncoder::setStrategy(std::unique_ptr<EncodingStrategy> newStrategy)
{
    strategy = std::move(newStrategy);
}

std::string TextEncoder::encode(const std::string& text) const
{
    return strategy->encode(text);
}
