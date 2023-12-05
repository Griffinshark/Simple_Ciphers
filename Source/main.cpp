#include <iostream>
#include <chrono>
#include <algorithm>
#include "brute_force.h"
#include "ciphers.h"

// Data Source:
// https://github.com/CTzatzakis/Wordlists/blob/master/Words.list

// References:
// https://www.geeksforgeeks.org/caesar-cipher-in-cryptography/
// https://www.geeksforgeeks.org/vigenere-cipher/
// https://www.cs.cmu.edu/~pattis/15-1XX/common/handouts/ascii.html
// https://www.javatpoint.com/vigenere-cipher
// https://inventwithpython.com/cracking/chapter20.html
// https://cmake.org/cmake/help/latest/command/include_directories.html
// https://www.youtube.com/watch?v=QYaQStudgnE

bool isAllLetters(const std::string &str) {
    for (char ch : str) {
        if (!isalpha(ch)) {
            return false;
        }
    }
    return true;
}

std::string getInput(){
    // ensures passwords are uppercase and contain only letters
    std::string str;
    std::cin >> str;

    while(!isAllLetters(str)){
         std::cout << "Input should not contain special characters nor digits. Please re-enter: \n";
         std::cin >> str; 
    }

    std::transform(str.begin(), str.end(), str.begin(), toupper);
    return str;
}

int main() {
    std::string password;
    std::string encryptedCaesar;
    std::string encryptedVigenere;
    std::string decryptedCaesar;
    std::string decryptedVigenere;
    std::string keyword;
    int shift;

    std::cout << "Welcome to simple ciphers! Please enter a password with no special characters nor digits: \n";
    password = getInput();

    // Caesar Encryption
    std::cout << "\nEncrypting using Caesar Cipher...\n";
    std::cout << "Enter the shift for Caesar Cipher: \n";
    std::cin >> shift;

    auto startEncryptCaesar = std::chrono::steady_clock::now();
    encryptedCaesar = ciphers::CaesarEncrypt(password, shift);
    auto endEncryptCaesar = std::chrono::steady_clock::now();
    auto durationEncryptCaesar = endEncryptCaesar - startEncryptCaesar;

    std::cout << "Encrypted Password (Caesar Cipher): " << encryptedCaesar << "\n";
    std::cout << "Encryption Time (Caesar Cipher): "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(durationEncryptCaesar).count()
              << " nanoseconds\n\n";

    // Vigenere Encryption
    std::cout << "\nEncrypting using Vigenere Cipher...\n";
    std::cout << "Enter the keyword for Vigenere Cipher: \n";
    keyword = getInput();

    while( keyword.size() > password.size() ){
        std::cout << "Keyword must not be longer than password. Please re-enter: \n";
        keyword = getInput();
    }

    auto startEncryptVigenere = std::chrono::steady_clock::now();
    encryptedVigenere = ciphers::VigenereEncrypt(password, keyword);
    auto endEncryptVigenere = std::chrono::steady_clock::now();
    auto durationEncryptVigenere = endEncryptVigenere - startEncryptVigenere;

    std::cout << "Encrypted Password (Vigenere Cipher): " << encryptedVigenere << "\n";
    std::cout << "Encryption Time (Vigenere Cipher): "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(durationEncryptVigenere).count()
              << " nanoseconds\n\n";

    // Compare encryption times
    if (durationEncryptCaesar < durationEncryptVigenere) {
        std::cout << "Encryption using Caesar Cipher was faster!\n\n";
    } else if (durationEncryptCaesar > durationEncryptVigenere) {
        std::cout << "Encryption using Vigenere Cipher was faster!\n\n";
    } else {
        std::cout << "Encryption times were equal!\n\n";
    }

    // Decrypt Caesar Cipher
    auto startDecryptCaesar = std::chrono::steady_clock::now();
    decryptedCaesar = ciphers::CaesarDecrypt(encryptedCaesar, shift);
    auto endDecryptCaesar = std::chrono::steady_clock::now();
    auto durationDecryptCaesar = endDecryptCaesar - startDecryptCaesar;

    std::cout << "Decrypted Password (Caesar Cipher): " << decryptedCaesar << "\n";
    std::cout << "Decryption Time (Caesar Cipher): "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(durationDecryptCaesar).count()
              << " nanoseconds\n\n";

    // Decrypt Vigenere Cipher
    auto startDecryptVigenere = std::chrono::steady_clock::now();
    decryptedVigenere = ciphers::VigenereDecrypt(encryptedVigenere, keyword);
    auto endDecryptVigenere = std::chrono::steady_clock::now();
    auto durationDecryptVigenere = endDecryptVigenere - startDecryptVigenere;

    std::cout << "Decrypted Password (Vigenere Cipher): " << decryptedVigenere << "\n";
    std::cout << "Decryption Time (Vigenere Cipher): "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(durationDecryptVigenere).count()
              << " nanoseconds\n\n";

    // Compare decryption times
    if (durationDecryptCaesar < durationDecryptVigenere) {
        std::cout << "Decryption using Caesar Cipher was faster!\n\n";
    } else if (durationDecryptCaesar > durationDecryptVigenere) {
        std::cout << "Decryption using Vigenere Cipher was faster!\n\n";
    } else {
        std::cout << "Decryption times were equal!\n\n";
    }

    // Brute Force Attacks
    std::cout << "Performing Brute-Force Attacks...\n";

    // Brute Force Attack for Caesar Cipher
    auto startAttackCaesar = std::chrono::steady_clock::now();
    bool caesarAttackSuccess = BruteForce::attack(encryptedCaesar, password);
    auto endAttackCaesar = std::chrono::steady_clock::now();
    auto durationAttackCaesar = endAttackCaesar - startAttackCaesar;

    if (caesarAttackSuccess) {
        std::cout << "Brute-Force Attack (Caesar Cipher) SUCCESSFUL\n";
        std::cout << "Attack Time (Caesar Cipher): "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(durationAttackCaesar).count()
                  << " nanoseconds\n\n";
    } else {
        std::cout << "Brute-Force Attack (Caesar Cipher) FAILED\n\n";
    }

    // Brute Force Attack for Vigenere Cipher
    auto startAttackVigenere = std::chrono::steady_clock::now();
    bool vigenereAttackSuccess = BruteForce::attack(encryptedVigenere, password);
    auto endAttackVigenere = std::chrono::steady_clock::now();
    auto durationAttackVigenere = endAttackVigenere - startAttackVigenere;

    if (vigenereAttackSuccess) {
        std::cout << "Brute-Force Attack (Vigenere Cipher) SUCCESSFUL\n";
        std::cout << "Attack Time (Vigenere Cipher): "
                  << std::chrono::duration_cast<std::chrono::nanoseconds>(durationAttackVigenere).count()
                  << " nanoseconds\n\n";
    } else {
        std::cout << "Brute-Force Attack (Vigenere Cipher) FAILED\n\n";
    }

    // Compare brute-force attack times
    if (durationAttackCaesar < durationAttackVigenere) {
        std::cout << "Brute-Force Attack using Caesar Cipher was faster!\n";
    } else if (durationAttackCaesar > durationAttackVigenere) {
        std::cout << "Brute-Force Attack using Vigenere Cipher was faster!\n";
    } else {
        std::cout << "Brute-Force Attack times were equal!\n";
    }

    return 0;
}
