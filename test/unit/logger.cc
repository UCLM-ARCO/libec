// -*- mode:c++ -*-

#include <cxxtest/TestSuite.h>

#include <logger.h>

class TestLogger : public CxxTest::TestSuite {
public:

	ec::Logger* logger;

	void setUp(void) {
		logger = new ec::Logger::Logger();
	}

	void teardown(void) {
		delete logger;
	}

	void testSetLevel(void) {
		logger->set_level(ec::Logger::ALL);
		TS_ASSERT_EQUALS(logger->level, ec::Logger::ALL);
	}

};
