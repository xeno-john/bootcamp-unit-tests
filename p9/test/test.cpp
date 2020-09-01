#include<gtest/gtest.h>
#include<iostream>
#include "stubs.c"

using namespace std;

#define RETURN_ERROR 1
#define RETURN_OK 0

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
    double *dummy = new double; /* used to return allocated zone in memory for malloc stub */
    double *temp = new double; /* used to provide an adress to some value when testing the 'task' function */

	MyTestFixture ()
	{
		/* Initialization code here */
        pthread_create_RET = RETURN_OK;
        pthread_join_RET = RETURN_OK;
        pthread_mutex_lock_RET = RETURN_OK;
        pthread_mutex_unlock_RET = RETURN_OK;
        malloc_RET = NULL;
        *temp = 0;
	}

    void set_pthread_create_RET(int new_test_value)
    {
        pthread_create_RET = new_test_value;
    }
    
    void set_pthread_join_RET(int new_test_value)
    {
        pthread_join_RET = new_test_value;
    }

    void set_pthread_mutex_lock_RET(int new_test_value)
    {
        pthread_mutex_lock_RET = new_test_value;
    }

    void set_pthread_mutex_unlock_RET(int new_test_value)
    {
        pthread_mutex_unlock_RET = new_test_value;
    }

    void set_malloc_RET(void* new_test_value)
    {
        malloc_RET = new_test_value;
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


TEST_F(MyTestFixture,AllocationFailure)
{
    ASSERT_NE(RETURN_OK,handle_threads());
}

TEST_F(MyTestFixture,AllOK)
{
    set_malloc_RET(dummy);
    ASSERT_EQ(RETURN_OK,handle_threads());
}

TEST_F(MyTestFixture,ThreadsFail)
{
    set_malloc_RET(dummy);
    set_pthread_create_RET(RETURN_ERROR);
    set_pthread_join_RET(RETURN_ERROR);
    ASSERT_NE(RETURN_OK,handle_threads());
}

TEST_F(MyTestFixture,PthreadCreateFails)
{
    set_malloc_RET(dummy);
    set_pthread_create_RET(RETURN_ERROR);
    ASSERT_NE(RETURN_OK,handle_threads());
}

TEST_F(MyTestFixture,PthreadJoinFails)
{
    set_malloc_RET(dummy);
    set_pthread_join_RET(RETURN_ERROR);
    ASSERT_NE(RETURN_OK,handle_threads());
}

TEST_F(MyTestFixture,PthreadMutexLockFails)
{
    set_pthread_mutex_lock_RET(RETURN_ERROR);
    ASSERT_EQ(NULL,task((void*)temp));
}

TEST_F(MyTestFixture,PthreadMutexUnlockFails)
{
    set_pthread_mutex_unlock_RET(RETURN_ERROR);
    ASSERT_EQ(NULL,task((void*)temp));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}