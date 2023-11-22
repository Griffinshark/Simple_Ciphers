#ifndef SIMPLE_CIPHERS_BRUTE_FORCE_H
#define SIMPLE_CIPHERS_BRUTE_FORCE_H

#include <string>

class BruteForce{
    /* Decrypt a given ciphertext using brute force attacks */
    public:
        static std::string caesarAttack(const std::string ciphertext, const std::string plaintext);
        static std::string vigenereAttack(const std::string ciphertext, const std::string plaintext);

    private:
        static char getShiftedLetter(const char c, const int key);
        static char getShiftedDigit(const char c, const int key);
};

#endif // SIMPLE_CIPHERS_BRUTE_FORCE_H
