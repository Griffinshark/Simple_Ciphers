#ifndef SIMPLE_CIPHERS_CIPHERS_H
#define SIMPLE_CIPHERS_CIPHERS_H
#include <string>

namespace ciphers
{
    std::string VigenereEncrypt(std::string toEncrypt);
    std::string VigenereDecrypt(std::string toDecrypt);

    // Encrypts the given lowercase alphabetic string via the "Caesar Cipher"
    std::string CaesarEncrypt(const std::string& toEncrypt);

    // Decrypts the given lowercase alphabetic string via the "Caesar Cipher"
    std::string CaesarDecrypt(const std::string& toDecrypt);
}

#endif //SIMPLE_CIPHERS_CIPHERS_H
