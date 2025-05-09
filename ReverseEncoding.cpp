#include "ReverseEncoding.h"
#include "EncodingException.h"
#include <string>
#include <algorithm>

std::string ReverseEncoding::encode(const std::string& text) const
{
    if(text.empty())
    {
        throw EncodingException("Cannot reverse an empty string.");
    }

    std::string result = text;
    std::reverse(result.begin(), result.end());
    return result;
}
