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
}

TEST_CASE("Function: vigenere attack", "[brute-force]"){
	REQUIRE(BruteForce::vigenereAttack("XELXBMYOWJ", "STRAWBERRY") == "STRAWBERRY");
	REQUIRE(BruteForce::vigenereAttack("HGECZGGOCYLKAUVUKOAPGIIKFAEIKBNHLKNFHCWAAHSQF", "PNEUMONOULTRAMICROSCOPICSILICOVOLCANOCONIOSIS") == "PNEUMONOULTRAMICROSCOPICSILICOVOLCANOCONIOSIS");
}