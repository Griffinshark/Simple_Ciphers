#include "brute_force.h"
#include "ciphers.h"

#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>

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

std::string BruteForce::caesarAttack(const std::string ciphertext, const std::string plaintext){
    // Tries out every possible key until a match with the plaintext is found.
    // Handles upper and lower case letters in the ciphertext.

    std::string decryptedText = "";

    for(int i = 0; i < 26; i++){
        for(char c : plaintext){
            decryptedText += getShiftedLetter(c, i);
        }
        if (decryptedText == plaintext){ break; }
    }

    return decryptedText;
}

std::string BruteForce::vigenereAttack(const std::string ciphertext, const std::string plaintext){ 
    // Performs a dictionary attack to break cipher
    // Returns a decoded string if cipher was successfully decrypted and an empty string otherwise
    // ciphertext is an uppercase string

    std::ifstream file("./Source/word-test.txt");
    // std::ifstream file("words.txt");
    std::string word = "";

    if (!file.is_open()){
        std::cout << "ERROR";
    }

    if (file.is_open()){
        while (getline(file,word)){

            if (word.size() > ciphertext.size()){ continue; }

            std::string upper = "";

            for (char c : word){
                upper += toupper(c);
            }

            std::string decodedText = ciphers::VigenereDecrypt(ciphertext,upper);

            if (decodedText == plaintext){ 
               file.close();
               return decodedText; 
             }
        }
    }

    file.close();

    return ""; 
}

/*void BruteForceAlgorithms::GenerateCaesarList(const std::string& EncryptedWord)
{
    // Open the file to write to
    std::ofstream outputFile("generated_caesar.txt");
    bool test = outputFile.is_open();

    // Generate 26 shifts to account for all possible shifts
    for (int i = 0; i < 26; ++i)
    {
        std::string temp{ciphers::CaesarDecrypt(EncryptedWord, i)};
        outputFile << temp << std::endl;
    }

    outputFile.close(); 
} */
