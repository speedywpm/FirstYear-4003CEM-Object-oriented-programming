#include <cxxtest/TestSuite.h>

class SomeTests : public CxxTest::TestSuite 
{
public:
	void test_bigger()
//IF SOLUTION	
	{	TS_ASSERT( 1 > 0 );
	}
//ELSE SOLUTION	
	{	TS_ASSERT( 1 < 0 );
	}
//END SOLUTION

	void test_equals()
	{	TS_ASSERT_EQUALS( 1+1, 2 );
	}

	void test_except()
	{	TS_ASSERT_THROWS_ANYTHING( throw 1 );
	}
};