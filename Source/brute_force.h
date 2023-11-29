#ifndef SIMPLE_CIPHERS_BRUTE_FORCE_H
#define SIMPLE_CIPHERS_BRUTE_FORCE_H

#include <string>
#include <fstream>

class BruteForce{
    /* Decrypt a given ciphertext using brute force attacks */
    public:
        static std::string caesarAttack(const std::string ciphertext, const std::string plaintext);
        static std::string vigenereAttack(const std::string ciphertext, const std::string plaintext);

    private:
        static char getShiftedLetter(const char c, const int key);
};

/*namespace BruteForceAlgorithms
{
    // Takes in an encrypted word and generates a list of all possible shifts/keys for a Caesar Cipher
    void GenerateCaesarList(const std::string& EncryptedWord);
}*/

#endif // SIMPLE_CIPHERS_BRUTE_FORCE_H
