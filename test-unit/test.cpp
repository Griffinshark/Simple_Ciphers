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
	//REQUIRE(ciphers::VigenereEncrypt("STRAWBERRY","KEY") == "CXPKAZOVPI");
	//REQUIRE(ciphers::VigenereEncrypt("STRAWBERRY","FLUX") == "XELXBMYOWJ");
	//REQUIRE(ciphers::VigenereDecrypt("CXPKAZOVPI","KEY") == "STRAWBERRY");
	//REQUIRE(ciphers::VigenereDecrypt("XELXBMYOWJ","FLUX") == "STRAWBERRY");

	//REQUIRE(BruteForce::vigenereAttack("XELXBMYOWJ", "STRAWBERRY") == "STRAWBERRY");
}