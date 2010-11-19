// -*- mode:c++ -*-

#include <cxxtest/TestSuite.h>

#include <string.h>

class TestString : public CxxTest::TestSuite {
public:
	void testContains(void) {
		TS_ASSERT(ec::string::contains("String", "tr"));
		TS_ASSERT(not(ec::string::contains("String", "2r")));
		TS_ASSERT(ec::string::contains("", ""));
		TS_ASSERT(not(ec::string::contains("", "2")));
		TS_ASSERT(ec::string::contains("1231", ""));
	}

	void testEndsWith(void) {
		TS_ASSERT(ec::string::endswith("String", "g"));
		TS_ASSERT(ec::string::endswith("String", "ing"));
		TS_ASSERT(ec::string::endswith("String", ""));
		TS_ASSERT(not(ec::string::endswith("String", "1")));
		TS_ASSERT(not(ec::string::endswith("String", " ")));
	}

	void testIsSpace(void) {
		TS_ASSERT(not(ec::string::isspace("String")));
		TS_ASSERT(ec::string::isspace(" \t\r\n"));
		TS_ASSERT(ec::string::isspace("\n"));
	}

	void testJoin(void) {
		std::vector<std::string> words;
		words.push_back("Hello");
		words.push_back("World!");

		TS_ASSERT_EQUALS(ec::string::join("", words), "HelloWorld!");
		TS_ASSERT_EQUALS(ec::string::join(" : ", words), "Hello : World!");
		TS_ASSERT_EQUALS(ec::string::join("\n", words), "Hello\nWorld!");

		words.clear();
		TS_ASSERT_EQUALS(ec::string::join("", words), "");
		TS_ASSERT_EQUALS(ec::string::join("::", words), "");
	}

	void testLower(void) {
		TS_ASSERT_EQUALS(ec::string::lower("HellO"), "hello");
		TS_ASSERT_EQUALS(ec::string::lower(".HellO1\n"), ".hello1\n");
		TS_ASSERT_EQUALS(ec::string::lower(""), "");
	}

	void testUpper(void) {
		TS_ASSERT_EQUALS(ec::string::upper("HellO"), "HELLO");
		TS_ASSERT_EQUALS(ec::string::upper(".HellO1\n"), ".HELLO1\n");
		TS_ASSERT_EQUALS(ec::string::upper(""), "");
	}

	void testReplace(void) {
		TS_ASSERT_EQUALS(ec::string::replace("__pa_par_apat_", "pa", "MO"),
										 "__MO_MOr_aMOt_");
	}
};
