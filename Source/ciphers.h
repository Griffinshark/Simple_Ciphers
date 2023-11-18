#ifndef SIMPLE_CIPHERS_CIPHERS_H
#define SIMPLE_CIPHERS_CIPHERS_H
#include <string>

namespace ciphers
{
    std::string VigenereEncrypt(std::string toEncrypt);
    std::string VigenereDecrypt(std::string toDecrypt);
    std::string CaesarEncrypt(std::string toEncrypt);
    std::string CaesarDecrypt(std::string toDecrypt);
}

#endif //SIMPLE_CIPHERS_CIPHERS_H
