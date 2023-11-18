#include "ciphers.h"

std::string ciphers::VigenereEncrypt(std::string toEncrypt)
{
    return "";
}

std::string ciphers::VigenereDecrypt(std::string toDecrypt)
{
    return "";
}

std::string ciphers::CaesarEncrypt(const std::string& toEncrypt)
{
    int key{11};
    int shift{0};
    std::string encryptedWord;

    for (char i : toEncrypt)
    {
        shift = i + key;

        // If shift goes past 'z', continue at 'a'
        if (shift > 122)
        {
            shift = 96 + (shift - 122);
        }

        // Add the current character shifted
        encryptedWord += char(shift);
    }

    return encryptedWord;
}

std::string ciphers::CaesarDecrypt(const std::string& toDecrypt)
{
    int key{11};
    int shift{0};
    std::string decryptedWord;

    for (char i : toDecrypt)
    {
        shift = i - key;

        // If shift goes past 'a', continue at 'z'
        if (shift < 97)
        {
            shift = 123 - (97 - shift);
        }

        // Add the current character shifted
        decryptedWord += char(shift);
    }

    return decryptedWord;
}
