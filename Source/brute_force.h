#ifndef SIMPLE_CIPHERS_BRUTE_FORCE_H
#define SIMPLE_CIPHERS_BRUTE_FORCE_H

#include <string>

class BruteForce{
    /* Decrypt a given ciphertext using brute force attacks */
    public:
        double CaesarAttack(std::string ciphertext, std::string plaintext);
        double VigenereAttack(std::string ciphertext, std::string plaintext);
};

#endif // SIMPLE_CIPHERS_BRUTE_FORCE_H
