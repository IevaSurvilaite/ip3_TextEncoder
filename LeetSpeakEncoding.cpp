#include "LeetSpeakEncoding.h"
#include "EncodingException.h"
#include <string>

const std::unordered_map<char, std::string> LeetSpeakEncoding::leetMap =
{
    {'a', "4"},
    {'b', "8"},
    {'c', "<"},
    {'d', "[)"},
    {'e', "3"},
    {'f', "f"},
    {'g', "6"},
    {'h', "#"},
    {'i', "1"},
    {'j', "j"},
    {'k', "k"},
    {'l', "L"},
    {'m', "/V\\"},
    {'n', "/\\/"},
    {'o', "0"},
    {'p', "p"},
    {'q', "Q"},
    {'r', "r"},
    {'s', "5"},
    {'t', "7"},
    {'u', "|_|"},
    {'v', "\\/"},
    {'w', "vv"},
    {'x', ")("},
    {'y', "\\|/"},
    {'z', "2"},
};

std::string LeetSpeakEncoding::encode(const std::string& text) const
{
    if(text.empty())
    {
        throw EncodingException("Cannot Leet encode an empty string.");
    }

    std::string result;
    for(char c : text)
    {
        char lower = std::tolower(static_cast<unsigned char>(c));
        if(leetMap.find(lower) != leetMap.end())
        {
            result += leetMap.at(lower);
        }
        else
        {
            result += c;
        }
    }
    return result;
}
