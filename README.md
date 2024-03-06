# Introduction
This was a collaborative project involving, as the title suggests, simple ciphers. In this project we test two simple ciphers: Caesar Cipher and Vigenere Cipher. The Caesar Cipher
performs a simple character shift based upon the provided shift. The Vigenere Cipher performs individual character shifts based upon a provided keyword. This program will take in 
a password to encrypt. Then it will ask for a shift and encrypt with Caesar Cipher. It will then output the encryption and time to encrypt. Then the program will ask for a keyword 
and encrypt the password using Vigenere Cipher and display the encryption with the time to encrypt. The program will then determine which method encrypted faster. Next, the
program will decrypt each encryption and display the decrypted password as well as the time to decrypt and display which decryption was faster. 

Finally, there is a small hacking demonstration the program goes through. The demonstration is showing that a hacker first assumes the encrypted password was encrypted using Caesar 
Cipher and does a brute force attack of shifting through every possible key shift until a match is found. If no match is found, the hacker assumes the password is Vigenere encrypted. 
In this case, the hacker is assumed to have a Vigenere decrypter handy and is able to throw various keywords into the decrypter till an unencrypted password is determined. For this, 
the hacker uses a dictionary file to test various possible keywords. If a match is eventually found, the password is unencrypted. In the normal functionality of the program, both 
encryptions are tested using the hacking methods and the hacking/attack time is displayed, as well as, which attack was faster.

# Installation
Download the repo and ensure that the file "Words.txt," located in the "Source" folder, is in the working directory.
