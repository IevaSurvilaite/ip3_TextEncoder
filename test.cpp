/*
Ideja treciai isvestinei klasei: VowelRemoverEncoding
Si klase paveldi EncodingStrategy klase.
Si klase turi uzkloti (override'inti) std::string encode(const std::string& text) const; metoda,
kuris is duoto teksto pasalina visas balses (aeiou)
(kadangi angliska abecele, tai y nesiskaito kaip balse).
Nepamirskite atsizvelgti ir i didziasias raides
*/

// #include "VowelRemoverEncoding.h"  // jums reikes sukurti .cpp ir .h failus
#include "ReverseEncoding.h"
#include "LeetSpeakEncoding.h"
#include <iostream>
#include <memory>
#include <string>
#include <cassert>

int main()
{
    std::string lineOne = "a b c d e f g H I j k L M N O P q r s T U V w x y z";
    std::string lineTwo = "I am an enchanter. There are some who call me... Tim.";

    std::unique_ptr<EncodingStrategy> strategy;

    // testing ReverseEncoding:
    strategy = std::make_unique<ReverseEncoding>();
    assert(strategy->encode(lineOne) == "z y x w V U T s r q P O N M L k j I H g f e d c b a");
    std::cout << "Reverse encoded abc: Passed" << std::endl;

    //testing LeetSpeakEncoding:
    strategy = std::make_unique<LeetSpeakEncoding>();
    assert(strategy->encode(lineOne) == "4 8 < [) 3 f 6 # 1 j k L /V\\ /\\/ 0 p Q r 5 7 |_| \\/ vv )( \\|/ 2");
    std::cout << "Leet encoded abc: Passed" << std::endl;

    // testing VowelRemoverEncoding:
    strategy = std::make_unique<VowelRemoverEncoding>();
    //test 1:
    std::cout << "VowelRemover encoded abc (before test): " << strategy->encode(lineOne) << std::endl;
    assert(strategy->encode(lineOne) == " b c d  f g H  j k L M N  P q r s T  V w x y z");
    std::cout << "VowelRemover encoded abc: Passed! Congrats\n" << std::endl;

    //test 2:
    std::cout << "Text to encode next:\n" << lineTwo << std::endl;
    std::cout << "VowelRemover encoded text (before test):\n" << strategy->encode(lineTwo) << std::endl;
    assert(strategy->encode(lineTwo) == " m n nchntr. Thr r sm wh cll m... Tm.");
    std::cout << "VowelRemover encoded lineTwo: Passed! Congrats\n" << std::endl;

    std::cout << "\nAll tests passed." << std::endl;
    return 0;
}

