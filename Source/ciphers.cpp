#include "ciphers.h"

std::string ciphers::VigenereEncrypt(std::string toEncrypt)
{
    std::string keyword{"sharks"};
    std::string key{KeyGenerator(keyword, static_cast<int>(toEncrypt.size()))};

    // Generate the "Vigenere Square" ----------------------------------------------------------------------------------
    unsigned char vigenereSquare[26][26];
    int charCount{0};

    // Rows
    for (int i = 0; i < 26; ++i)
    {
        charCount = 0;

        // Columns
        for (int j = i; j < 26; ++j)
        {
            // Start at ASCII 'a' and add 'j' to get the correct character
            vigenereSquare[i][charCount] = 'a' + j;

            ++charCount;
        }

        // Happens anytime outside the first row
        if (charCount != 26)
        {
            int tailLength{26 - charCount};

            // Replace the tail end of the row with the start of the alphabet up to its length
            for (int k = 0; k < tailLength; ++k)
            {
                vigenereSquare[i][charCount] = 'a' + k;

                ++charCount;
            }
        }
    }
    // -----------------------------------------------------------------------------------------------------------------

    std::string encryptedWord;

    // Generate the encrypted word
    for (int i = 0; i < toEncrypt.size(); ++i)
    {
        encryptedWord += char(vigenereSquare[(toEncrypt[i] - 97)][(key[i] - 97)]);
    }

    return encryptedWord;
}

std::string ciphers::VigenereDecrypt(std::string toDecrypt)
{
    std::string keyword{"sharks"};
    std::string key{KeyGenerator(keyword, static_cast<int>(toDecrypt.size()))};

    // Generate the "Vigenere Square" ----------------------------------------------------------------------------------
    unsigned char vigenereSquare[26][26];
    int charCount{0};

    // Rows
    for (int i = 0; i < 26; ++i)
    {
        charCount = 0;

        // Columns
        for (int j = i; j < 26; ++j)
        {
            // Start at ASCII 'a' and add 'j' to get the correct character
            vigenereSquare[i][charCount] = 'a' + j;

            ++charCount;
        }

        // Happens anytime outside the first row
        if (charCount != 26)
        {
            int tailLength{26 - charCount};

            // Replace the tail end of the row with the start of the alphabet up to its length
            for (int k = 0; k < tailLength; ++k)
            {
                vigenereSquare[i][charCount] = 'a' + k;

                ++charCount;
            }
        }
    }
    // -----------------------------------------------------------------------------------------------------------------

    std::string decryptedWord;

    // Generate the decrypted word
    for (int i = 0; i < toDecrypt.size(); ++i)
    {
        // charCount, in this instance, is keeping track of the decrypted column
        charCount = 0;

        // Search through the row of 'key[i] - 97'
        for (int j = 0; j < 26; ++j)
        {
            if (vigenereSquare[(key[i] - 97)][j] == toDecrypt[i])
            {
                decryptedWord += char(charCount + 97);
            }

            ++charCount;
        }
    }

    return decryptedWord;
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
