#ifndef SIMPLE_CIPHERS_CIPHERS_H
#define SIMPLE_CIPHERS_CIPHERS_H
#include <string>

namespace ciphers
{
    // Encrypts the given lowercase alphabetic string via the "Vigenere Cipher"
    std::string VigenereEncrypt(std::string toEncrypt);

    // Decrypts the given lowercase alphabetic string via the "Vigenere Cipher"
    std::string VigenereDecrypt(std::string toDecrypt);

    // Encrypts the given lowercase alphabetic string via the "Caesar Cipher"
    std::string CaesarEncrypt(const std::string& toEncrypt);

    // Decrypts the given lowercase alphabetic string via the "Caesar Cipher"
    std::string CaesarDecrypt(const std::string& toDecrypt);

    // Take in keyword and length and generates key to return
    std::string KeyGenerator(std::string keyword, int length);
}

#endif //SIMPLE_CIPHERS_CIPHERS_H
