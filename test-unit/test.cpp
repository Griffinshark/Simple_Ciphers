#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../Source/brute_force.h"
#include "../Source/brute_force.cpp"
#include "../Source/ciphers.h"
#include "../Source/ciphers.cpp"

#include <string>

/*
	To check output (At the Simple_Ciphers directory):
		g++ -std=c++14 -Werror -Wuninitialized -o test test-unit/test.cpp && ./test
*/

TEST_CASE("Function: caesar attack", "[brute-force]"){
	// key = 7
	REQUIRE(BruteForce::caesarAttack("hXDLYAFg", "aQWERTYz") == "aQWERTYz");
	REQUIRE(BruteForce::caesarAttack("zayhdilyyf", "strawberry") == "strawberry");
	REQUIRE(BruteForce::caesarAttack("ZAYHDILYYF", "STRAWBERRY") == "STRAWBERRY");
	
}

TEST_CASE("Function: vigenere attack", "[brute-force]"){
	// please uncomment line 46 and comment line 47 in the function
	REQUIRE(BruteForce::vigenereAttack("XELXBMYOWJ", "STRAWBERRY") == "STRAWBERRY");
	REQUIRE(BruteForce::vigenereAttack("HGECZGGOCYLKAUVUKOAPGIIKFAEIKBNHLKNFHCWAAHSQF", "PNEUMONOULTRAMICROSCOPICSILICOVOLCANOCONIOSIS") == "PNEUMONOULTRAMICROSCOPICSILICOVOLCANOCONIOSIS");
} 

TEST_CASE("Function: attack", "[brute-force]"){
	// please uncomment line 46 and comment line 47 in the function vigenereAttack
	REQUIRE(BruteForce::attack("XELXBMYOWJ", "STRAWBERRY") == true);
	REQUIRE(BruteForce::attack("ZAYHDILYYF", "STRAWBERRY") == true);
} 