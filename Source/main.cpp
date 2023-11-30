#include <iostream>
#include "brute_force.h"
#include "ciphers.h"

int main() {
    std::string password;
    std::string encryptedWord;

    // User inputs password
    std::cout << "Enter the password: ";
    std::cin >> password;

    // Choose encryption method (Caesar or Vigenere)
    int choice;
    std::cout << "Select encryption method: \n";
    std::cout << "1. Caesar\n2. Vigenere\n";
    std::cin >> choice;

    if (choice == 1) {
        // Caesar cipher
        int shift;
        std::cout << "Enter shift value: ";
        std::cin >> shift;

        // Encrypt using Caesar cipher
        encryptedWord = ciphers::CaesarEncrypt(password, shift);
    } else if (choice == 2) {
        // Vigenere cipher
        std::string keyword;
        std::cout << "Enter keyword: ";
        std::cin >> keyword;

        // Encrypt using Vigenere cipher
        encryptedWord = ciphers::VigenereEncrypt(password, keyword);
    } else {
        std::cout << "Invalid choice!\n";
        return 1;
    }

    // Display the encrypted word
    std::cout << "Encrypted word: " << encryptedWord << std::endl;

    // Perform decryption (user input)
    std::string decryptedWord;
    std::cout << "\nEnter the encrypted word: ";
    std::cin >> encryptedWord;

    if (choice == 1) {
        // Caesar cipher
        int shift;
        std::cout << "Enter shift value: ";
        std::cin >> shift;

        // Decrypt using Caesar cipher
        decryptedWord = ciphers::CaesarDecrypt(encryptedWord, shift);
    } else if (choice == 2) {
        // Vigenere cipher
        std::string keyword;
        std::cout << "Enter keyword: ";
        std::cin >> keyword;

        // Decrypt using Vigenere cipher
        decryptedWord = ciphers::VigenereDecrypt(encryptedWord, keyword);
    } else {
        std::cout << "Invalid choice!\n";
        return 1;
    }

    // Display the decrypted word
    std::cout << "Decrypted word: " << decryptedWord << std::endl;

    // Perform attack (user input)
    std::cout << "\nPerforming attack...\n";

    // Need to implement the attack methods here based on user choice

    return 0;
}
