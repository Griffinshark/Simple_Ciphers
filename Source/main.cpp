#include <iostream>
#include <chrono>
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

int main()
{
    std::string password;
    std::string encryptedPassword;
    std::string keyword;
    int shift;
    bool caesarUsed{false};
    bool vigenereUsed{false};

    bool exit{false};

    std::cout << "Welcome to simple ciphers! You will be able to test the speed of two basic ciphers, Caesar and Vinegere.\n";
    std::cout << "You will also be able to perform a brute-force attack for each and see how long it takes to break the cipher\n";
    std::cout << "Which one do you favor?\n";
    std::cout << "------------------------------------\n";

    // Menu Loop
    while (!exit)
    {
        std::cout << "Please enter a number from the menu:\n";
        std::cout << "1. Enter New Password\n";
        std::cout << "2. Encrypt Password\n";
        std::cout << "3. Decrypt Password\n";
        std::cout << "4. Perform Attack\n";
        std::cout << "5. Exit\n";

        int choice;
        std::cin >> choice;
        std::cout << '\n';

        // New Password
        if (choice == 1)
        {
            // User inputs password
            std::cout << "Enter the password: \n";
            std::cin >> password;

            for (char& c : password){
                if (isalpha(c)){ 
                    c = toupper(c); 
                    continue;
                }

                std::cout << "Invalid password. Please use only letters\n";
                password = "";
                break;
                
            }
            std::cout << '\n';
        }
        // Encrypt Password
        else if (choice == 2 && !password.empty())
        {
            std::cout << "1. Encrypt with Caesar Cipher\n";
            std::cout << "2. Encrypt with Vigenere Cipher\n";
            std::cin >> choice;
            std::cout << '\n';

            // Caesar Cipher
            if (choice == 1)
            {
                // Obtain shift from user
                std::cout << "Please enter shift: \n";
                std::cin >> shift;

                // Encrypt
                auto start = std::chrono::steady_clock::now();
                encryptedPassword = ciphers::CaesarEncrypt(password, shift);
                auto end = std::chrono::steady_clock::now();
                auto duration = end - start;

                // Display Encrypted Password and decryption time
                std::cout << "Encrypted Password: " << encryptedPassword << "\n";
                std::cout << "Encryption Time: "
                          << std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()
                          << " nanoseconds\n\n";

                caesarUsed = true;
            }
            // Vigenere Cipher
            else if (choice == 2)
            {
                // Obtain keyword from user
                std::cout << "Please enter keyword: \n";
                std::cin >> keyword;

                if (keyword > password){ 
                    std::cout << "Invalid: Keyword cannot be larger than password!";
                    std::cout << '\n';
                    keyword = "";
                }

                for (char& c : keyword){
                    if (isalpha(c)){ 
                        c = toupper(c); 
                        continue;
                    }

                    std::cout << "Invalid password. Please use only letters\n";
                    keyword = "";
                    break;
                }

                if (keyword != ""){
                // Encrypt
                auto start = std::chrono::steady_clock::now();
                encryptedPassword = ciphers::VigenereEncrypt(password, keyword);
                auto end = std::chrono::steady_clock::now();
                auto duration = end - start;

                // Display Encrypted Password and decryption time
                std::cout << "Encrypted Password: " << encryptedPassword << "\n\n";
                std::cout << "Encryption Time: "
                          << std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()
                          << " nanoseconds\n\n";

                vigenereUsed = true;
                }
            }
            // Invalid Choice
            else
            {
                std::cout << "Invalid choice!\n";
            }
        }
        // Decrypt Password
        else if (choice == 3)
        {
            std::string decryptedPassword;

            if (caesarUsed)
            {
                // Decrypt
                auto start = std::chrono::steady_clock::now();
                decryptedPassword = ciphers::CaesarDecrypt(encryptedPassword, shift);
                auto end = std::chrono::steady_clock::now();
                auto duration = end - start;

                // Display decrypted password and decryption time
                std::cout << "Decrypted Password: " << decryptedPassword << '\n';
                std::cout << "Decryption Time: "
                          << std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()
                          << " nanoseconds\n\n";
            }
            else if (vigenereUsed)
            {
                // Decrypt
                auto start = std::chrono::steady_clock::now();
                decryptedPassword = ciphers::VigenereDecrypt(encryptedPassword, keyword);
                auto end = std::chrono::steady_clock::now();
                auto duration = end - start;

                // Display decrypted password and decryption time
                std::cout << "Decrypted Password: " << decryptedPassword << '\n';
                std::cout << "Decryption Time: "
                          << std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()
                          << " nanoseconds\n\n";
            }
            else
            {
                std::cout << "No password to decrypt!\n\n";
            }
        }
        // Perform Attack
        else if (choice == 4 && !encryptedPassword.empty())
        {
            auto start = std::chrono::steady_clock::now();
            if (BruteForce::attack(encryptedPassword, password))
            {
                auto end = std::chrono::steady_clock::now();
                auto duration = end - start;

                // Display SUCCESSFUL attack and attack time
                std::cout << "Attack SUCCESSFUL \n";
                std::cout << "Attack Time: "
                          << std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count()
                          << " nanoseconds\n\n";
            }
        }
        // Exit
        else if (choice == 5)
        {
            exit = true;
        }
        // Invalid Choice
        else
        {
            std::cout << "Invalid choice!\n\n";
        }
    }
}