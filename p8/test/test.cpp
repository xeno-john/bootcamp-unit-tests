#include<gtest/gtest.h>
#include<iostream>
#include "stubs.c"

using namespace std;

/* compile with g++ test.cpp -lgtest -lgtest_main -pthread -fpermissive -std=c++11 */

/* 
 *	generate coverage:
 *	compile with g++ test.cpp -lgtest -lgtest_main -pthread -fpermissive -std=c++11 --coverage
 *  ./a.out
 *  gcov test.cpp
 *  lcov --directory . -c -o cov.info
 *  rm -rf ../cov_dir
 *  genhtml cov.info --output-directory ../cov_dir
 */

/*********************************************************************
*
* @Test Fixture Struct
* @Struct Name:		MyTestFixture
*
*********************************************************************/

class MyTestFixture : public testing::Test
{
	/* Put any custom data members that you need */
    protected:

	MyTestFixture ()
	{
		/* Initialization code here */
        pthread_create_RET = 0;
        pthread_join_RET = 0;
	}

	void SetUp ()
	{
		/* Code here will execute just before the test ensues */
		
	}

	void TearDown ()
	{
		/* Code here will be called just after the test completes */
	}

	~MyTestFixture ()
	{
		/* Cleanup any pending stuff */
	}
};

TEST_F(MyTestFixture,WhenEverythingGoesOK)
{
    ASSERT_EQ(0,handle_threads());
}

TEST_F(MyTestFixture,WhenSomeThreadsFail)
{
	pthread_join_RET = 1;
	pthread_create_RET = 1;
    ASSERT_NE(0,handle_threads());
}

TEST_F(MyTestFixture,PthreadCreateFails)
{
	pthread_create_RET = 1;
	pthread_join_RET = 0;
	ASSERT_NE(0,handle_threads());
}

TEST_F(MyTestFixture,PthreadJoinFails)
{
	pthread_create_RET = 0;
	pthread_join_RET = 1;
	ASSERT_NE(0,handle_threads());
}

TEST_F(MyTestFixture,TaskFunction)
{
	ASSERT_NE(NULL,task((void*)(long)rand()));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}