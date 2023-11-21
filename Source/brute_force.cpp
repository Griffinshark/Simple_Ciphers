#include "brute_force.h"

#include <string>
#include <cstring>

char BruteForce::getShiftedLetter(const char c, const int key){
    // Returns the new letter after the key shift.
    if (isupper(c)){
        int val = c - key - 65;

        if (val < 0){ return (91 + val); }
        return (val % 26 + 65);
    }

    int val = c - key - 97;

    if (val < 0){ return (123 + val); }
    return (val % 26 + 97);
}

char BruteForce::getShiftedDigit(const char n, const int key){
    // Returns the new digit after the key shift.
    int val = n - key - 48;

    if (val < 0){ return (58 + val); }
    return (val % 10 + 48);
}

std::string BruteForce::caesarAttack(const std::string ciphertext, const std::string plaintext){
    // Tries out every possible key until a match with the plaintext is found.
    // Handles lower/upper case letters, numbers and symbols.
    // Returns the decrypted string.

    std::string decryptedText = "";

    for(int i = 0; i < 26; i++){
        for(char c : plaintext){
            if (isalpha(c)){ 
                decryptedText += getShiftedLetter(c, i); 
                continue;
            }

            if (isdigit(c)){ 
                decryptedText += getShiftedDigit(c, i); 
                continue;
            }

            decryptedText += c;
        }
        if (decryptedText == plaintext){ break; }
    }

    return decryptedText;
}

std::string BruteForce::vigenereAttack(const std::string ciphertext, const std::string plaintext){ return ""; }
