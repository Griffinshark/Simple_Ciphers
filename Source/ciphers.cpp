#include "ciphers.h"

std::string ciphers::VigenereEncrypt(std::string toEncrypt)
{
    std::string keyword{"SHARKS"};
    std::string key{KeyGenerator(keyword, static_cast<int>(toEncrypt.size()))};
    std::string encryptedWord;

    // E[i] = (P[i] + K[i]) % 26 | We add 'A' to get the char onto the capital letters for ASCII
    for (int i = 0; i < toEncrypt.size(); ++i)
    {
        encryptedWord += char(((toEncrypt[i] + key[i]) % 26) + 'A');
    }

    return encryptedWord;
}

std::string ciphers::VigenereDecrypt(std::string toDecrypt)
{
    std::string keyword{"SHARKS"};
    std::string key{KeyGenerator(keyword, static_cast<int>(toDecrypt.size()))};
    std::string decryptedWord;

    for (int i = 0; i < toDecrypt.size(); ++i)
    {
        // D[i] = (E[i] - K[i]) % 26 | negative values mess this up so we use abs() | We add 'A' to get the chars
        // onto the capital letters for ASCII
        decryptedWord += char((abs(toDecrypt[i] - key[i]) % 26) + 'A');
    }

    return decryptedWord;
}

std::string ciphers::CaesarEncrypt(const std::string& toEncrypt)
{
    int key{11};
    std::string shiftedAlphabet;

    // Create new "shifted" alphabet starting from ASCII 'A'
    for (int i = 0; i < 26; ++i)
    {
        shiftedAlphabet += char(((i + key) % 26) + 'A');
    }

    std::string encryptedWord;

    // Encrypt word with the new shifted alphabet
    for (char i : toEncrypt)
    {
        encryptedWord += shiftedAlphabet[i - 'A'];
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

        // If shift goes past 'A', continue at 'Z'
        if (shift < 65)
        {
            shift = 91 - (65 - shift);
        }

        // Add the current character shifted
        decryptedWord += char(shift);
    }

    return decryptedWord;
}

std::string ciphers::KeyGenerator(std::string keyword, int length)
{
    std::string key;
    int digitCount{0};

    // Generate key from keyword
    for (int i = 0; i < length; ++i)
    {
        // Reached the end of the keyword -> repeat from the beginning of the keyword
        if (digitCount >= keyword.size())
        {
            digitCount = 0;
        }

        // Add the next keyword char to the key
        key += keyword[digitCount];

        ++digitCount;
    }

    return key;
}
