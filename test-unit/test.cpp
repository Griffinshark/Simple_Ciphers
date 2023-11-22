#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "../Source/brute_force.h"
#include "../Source/brute_force.cpp"

#include <string>

/*
	To check output (At the Simple_Ciphers directory):
		g++ -std=c++14 -Werror -Wuninitialized -o test test-unit/test.cpp && ./test
*/

TEST_CASE("Function: caesar decryption", "[brute-force]"){
	// key = 7

	REQUIRE(BruteForce::caesarAttack("hXDLYAFg", "aQWERTYz") == "aQWERTYz");
	REQUIRE(BruteForce::caesarAttack("8xhg9dze", "1qaz2wsx") == "1qaz2wsx");
	REQUIRE(BruteForce::caesarAttack("7890123456", "0123456789") == "0123456789");
	REQUIRE(BruteForce::caesarAttack("^dMwte@fp#JRL^jcRAja%@*Z", "^wFpmx@yi#CKE^cvKTct%@*S") == "^wFpmx@yi#CKE^cvKTct%@*S");
}