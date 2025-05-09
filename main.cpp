#include "TextEncoder.h"
#include "ReverseEncoding.h"
#include "LeetSpeakEncoding.h"
#include "EncodingException.h"
#include <iostream>
#include <memory>
#include <string>
#include <exception>

int main()
{
    try
    {
        std::string lineOne = "a b c d e f g H I j k L M N O P q r s T U V w x y z";
        std::string lineTwo = ".tibbar etihw eht wolloF ...uoy sah xirtam ehT"; //"sedek uzu kedes semordnilap";
        std::string lineThree = "There is no spoon.\nA quick brown fox jumps over the lazy dog.";

        TextEncoder encoder(std::make_unique<ReverseEncoding>());
        std::cout << "Reverse encoded abc:\n" << encoder.encode(lineOne) << "\n" << std::endl; // polimorfizmas

        encoder.setStrategy(std::make_unique<LeetSpeakEncoding>());
        std::cout << "Leet encoded abc:\n" << encoder.encode(lineOne) << "\n" << std::endl; // polimorfizmas

        encoder.setStrategy(std::make_unique<ReverseEncoding>());
        std::cout << "Original string: " << lineTwo << std::endl;
        std::cout << "Reverse encoded: " << encoder.encode(lineTwo) << "\n" << std::endl;

        encoder.setStrategy(std::make_unique<LeetSpeakEncoding>());
        std::cout << "Original string:\n" << lineThree << std::endl;
        std::cout << "Leet encoded:\n" << encoder.encode(lineThree) << "\n" << std::endl;
    }
    catch(const EncodingException& e)
    {
        std::cerr << "Encoding error: " << e.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "Unknown error occured." << std::endl;
    }

    return 0;
}
