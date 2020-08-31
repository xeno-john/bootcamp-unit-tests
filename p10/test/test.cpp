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
    double *temp = new double;

	MyTestFixture ()
	{
		/* Initialization code here */
        pthread_create_RET = 0;
        pthread_join_RET = 0;
        pthread_mutex_lock_RET = 0;
        pthread_mutex_unlock_RET = 0;
        pthread_cond_broadcast_RET = 0;
        pthread_cond_destroy_RET = 0;
        pthread_mutex_destroy_RET = 0;
        *temp = 0;
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


TEST_F(MyTestFixture,ThreadsFail)
{
    pthread_create_RET = 1;
    pthread_join_RET = 1;
    ASSERT_NE(0,handle_threads());
}

TEST_F(MyTestFixture,PthreadCreateFails)
{
    pthread_create_RET = 1;
    ASSERT_NE(0,handle_threads());
}

TEST_F(MyTestFixture,PthreadMutexLockFails)
{
    pthread_mutex_lock_RET = 1;
    ASSERT_NE(0,handle_threads());
}

TEST_F(MyTestFixture,PthreadMutexUnlockFails)
{
    pthread_mutex_unlock_RET = 1;
    ASSERT_NE(0,handle_threads());
}

TEST_F(MyTestFixture,PthreadJoinFails)
{
    pthread_join_RET = 1;
    ASSERT_NE(0,handle_threads());
}

TEST_F(MyTestFixture,PthreadCondBroadcastFails)
{
    pthread_cond_broadcast_RET = 1;
    ASSERT_NE(0,handle_threads());
}

TEST_F(MyTestFixture,PthreadCondDestroyFails)
{
    pthread_cond_destroy_RET = 1;
    ASSERT_NE(0,handle_threads());
}

TEST_F(MyTestFixture,PthreadMutexDestroyFails)
{
    pthread_mutex_destroy_RET = 1;
    ASSERT_NE(0,handle_threads());
}

TEST_F(MyTestFixture,PthreadMutexLockFailsOnTask)
{
    pthread_mutex_lock_RET = 1;
    ASSERT_EQ(NULL,task((void*)temp));
}

TEST_F(MyTestFixture,PthreadMutexUnlockFailsOnTask)
{
    pthread_mutex_unlock_RET = 1;
    ASSERT_EQ(NULL,task((void*)temp));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}