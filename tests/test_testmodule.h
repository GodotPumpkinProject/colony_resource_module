#ifndef TEST_TESTMODULE_H
#define TEST_TESTMODULE_H

#include "tests/test_macros.h"

/* 
https://docs.godotengine.org/en/stable/contributing/development/core_and_modules/unit_testing.html

*/
namespace Test_colony_resources {
	TEST_SUITE("colony_resources Suite") {
		TEST_CASE("[colony_resources] Some Test!") {
			CHECK(1 == 1);
		}

	}
}

#endif
