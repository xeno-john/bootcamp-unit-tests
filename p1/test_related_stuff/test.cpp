#include<gtest/gtest.h>
#include<iostream>
#include "stubs.c"

using namespace std;

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
    uint32_t tester;
    char* dummy_char;
    void* dummy_void;

	MyTestFixture ()
	{
		/* Initialization code here */
        tester = 0;
        fgets_RET = NULL;
        dummy_char = new char[NUM_OF_BITS]; /* preparing an allocated memory location to be returns by stubbed fgets */
        dummy_void = new double[NUM_OF_BITS];
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
        delete dummy_char;
        free(dummy_void);
        dummy_void = NULL;
	}
};

TEST_F(MyTestFixture,handlesMallocFailure)
{    
    ASSERT_EQ(NULL,print_bits(9));
}

TEST_F(MyTestFixture,PrecisionTest)
{
    /* negative input is not possible because it is verified in the 
     * main function of the program
     * -> not relevant to test
     * and bigger numbers than 4294967295 are not allowed in C++
     */
    malloc_RET = (void*)dummy_void;
    
    ASSERT_STREQ("00000000000000000000000000000011",print_bits(3));
}

TEST_F(MyTestFixture,handlesFgetsFailure)
{    
    ASSERT_EQ(0,validate_input(&tester));
}

TEST_F(MyTestFixture,handlesValidInput)
{    
    strcpy(dummy_char,"39131"); /* make the string returned by fgets have a valid content */

    fgets_RET = dummy_char; /* set the return of fgets to the freshly allocated and instantiated char* */

    ASSERT_EQ(1,validate_input(&tester));

}

TEST_F(MyTestFixture,handlesInvalidInput)
{    
    strcpy(dummy_char,""); /* make the string returned by fgets have an ivalid content */

    fgets_RET = dummy_char; /* set the return of fgets to the freshly allocated and instantiated char* */

    ASSERT_EQ(0,validate_input(&tester));
}

TEST_F(MyTestFixture,handlesNegativeInput)
{    
    strcpy(dummy_char,"-59"); /* make the string returned by fgets have a invalid content (negative nr not allowed) */

    fgets_RET = dummy_char; /* set the return of fgets to the freshly allocated and instantiated char* */

    ASSERT_EQ(0,validate_input(&tester));
}

TEST_F(MyTestFixture,handlesOutOfDomainNumber)
{    
    strcpy(dummy_char,"9999999999999999999"); /* ERANGE set */

    fgets_RET = dummy_char; /* set the return of fgets to the freshly allocated and instantiated char* */

    ASSERT_EQ(0,validate_input(&tester));
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}