#ifndef SIMPLE_CIPHERS_CIPHERS_H
#define SIMPLE_CIPHERS_CIPHERS_H
#include <string>

namespace ciphers
{
    // Encrypts the given uppercase alphabetic string via the "Vigenere Cipher"
    std::string VigenereEncrypt(const std::string& toEncrypt, const std::string& keyword);

    // Decrypts the given uppercase alphabetic string via the "Vigenere Cipher"
    std::string VigenereDecrypt(const std::string& toDecrypt, const std::string& keyword);

    // Encrypts the given uppercase alphabetic string via the "Caesar Cipher"
    std::string CaesarEncrypt(const std::string& toEncrypt, const int& key);

    // Decrypts the given uppercase alphabetic string via the "Caesar Cipher"
    std::string CaesarDecrypt(const std::string& toDecrypt, const int& key);

    // Take in keyword and length and generates key to return
    std::string KeyGenerator(const std::string& keyword, const int& length);
}

#endif //SIMPLE_CIPHERS_CIPHERS_H
