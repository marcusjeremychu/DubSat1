#include "unity.h"
#include "dataArray.h"

void test_overloading_array(void)
{
	//Initializing array to be tested
	uint16_t myArray[10];
	uint16_t array1 = init(myArray, 10);
	addData(array1, (uint16_t)1);
	addData(array1, (uint16_t)11);
	addData(array1, (uint16_t)544);
	addData(array1, (uint16_t)245);
	addData(array1, (uint16_t)123);
	addData(array1, (uint16_t)5);
	addData(array1, (uint16_t)324);
	addData(array1, (uint16_t)89);
	addData(array1, (uint16_t)53);
	addData(array1, (uint16_t)20);
	addData(array1, (uint16_t)100);
	addData(array1, (uint16_t)3);
	addData(array1, (uint16_t)58);

	TEST_ASSERT_EQUAL_UINT16(3, getMin(array1));
	TEST_ASSERT_EQUAL_UINT16(324, getMax(array1));
	TEST_ASSERT_EQUAL_UINT16(102, getAvg(array1));
}

void test_not_full_array_with_same_numbers(void)
{
	//Initializing array to be tested
	uint16_t myArray[10];
	uint16_t array1 = init(myArray, 10);
	addData(array1, (uint16_t)2);
	addData(array1, (uint16_t)2);
	addData(array1, (uint16_t)2);
	addData(array1, (uint16_t)2);
	addData(array1, (uint16_t)2);


	TEST_ASSERT_EQUAL_UINT16(2, getMin(array1));
	TEST_ASSERT_EQUAL_UINT16(2, getMax(array1));
	TEST_ASSERT_EQUAL_UINT16(2, getAvg(array1));
}

void test_not_full_array_with_diff_numbers(void)
{
	//Initializing array to be tested
	uint16_t myArray[10];
	uint16_t array1 = init(myArray, 10);
	addData(array1, (uint16_t)22);
	addData(array1, (uint16_t)1000);
	addData(array1, (uint16_t)513);
	addData(array1, (uint16_t)3423);
	addData(array1, (uint16_t)2);


	TEST_ASSERT_EQUAL_UINT16(2, getMin(array1));
	TEST_ASSERT_EQUAL_UINT16(3423, getMax(array1));
	TEST_ASSERT_EQUAL_UINT16(992, getAvg(array1));
}

void test_not_full_array_with_diff_numbers_with_reset(void)
{
	//Initializing array to be tested
	uint16_t myArray[10];
	uint16_t array1 = init(myArray, 10);
	addData(array1, (uint16_t)22);
	addData(array1, (uint16_t)1000);
	addData(array1, (uint16_t)513);
	addData(array1, (uint16_t)3423);
	addData(array1, (uint16_t)2);


	TEST_ASSERT_EQUAL_UINT16(2, getMin(array1));
	TEST_ASSERT_EQUAL_UINT16(3423, getMax(array1));
	TEST_ASSERT_EQUAL_UINT16(992, getAvg(array1));

	resetData(array1);
	addData(array1, (uint16_t)444);
	addData(array1, (uint16_t)100);
	addData(array1, (uint16_t)5134);
	addData(array1, (uint16_t)10000);
	addData(array1, (uint16_t)50);
	addData(array1, (uint16_t)76);
	addData(array1, (uint16_t)90);
	addData(array1, (uint16_t)51);

	TEST_ASSERT_EQUAL_UINT16(50, getMin(array1));
	TEST_ASSERT_EQUAL_UINT16(10000, getMax(array1));
	TEST_ASSERT_EQUAL_UINT16(1993, getAvg(array1));
}

void test_overloading_array_with_reset(void)
{
	//Initializing array to be tested
	uint16_t myArray[10];
	uint16_t array1 = init(myArray, 10);
	addData(array1, (uint16_t)1);
	addData(array1, (uint16_t)11);
	addData(array1, (uint16_t)544);
	addData(array1, (uint16_t)245);
	addData(array1, (uint16_t)123);
	addData(array1, (uint16_t)5);
	addData(array1, (uint16_t)324);
	addData(array1, (uint16_t)89);
	addData(array1, (uint16_t)53);
	addData(array1, (uint16_t)20);
	addData(array1, (uint16_t)100);
	addData(array1, (uint16_t)3);
	addData(array1, (uint16_t)58);

	TEST_ASSERT_EQUAL_UINT16(3, getMin(array1));
	TEST_ASSERT_EQUAL_UINT16(324, getMax(array1));
	TEST_ASSERT_EQUAL_UINT16(102, getAvg(array1));

	resetData(array1);
	addData(array1, (uint16_t)1);
	addData(array1, (uint16_t)2);
	addData(array1, (uint16_t)3);
	addData(array1, (uint16_t)4);
	addData(array1, (uint16_t)5);
	addData(array1, (uint16_t)6);

	TEST_ASSERT_EQUAL_UINT16(1, getMin(array1));
	TEST_ASSERT_EQUAL_UINT16(6, getMax(array1));
	TEST_ASSERT_EQUAL_UINT16(3, getAvg(array1));
}

void test_multiple_handles(void)
{
	//Initializing array to be tested
	uint16_t myArray[10];
	uint16_t array1 = init(myArray, 10);
	addData(array1, (uint16_t)1);
	addData(array1, (uint16_t)11);
	addData(array1, (uint16_t)544);
	addData(array1, (uint16_t)245);
	addData(array1, (uint16_t)123);
	addData(array1, (uint16_t)5);
	addData(array1, (uint16_t)324);
	addData(array1, (uint16_t)89);
	addData(array1, (uint16_t)53);
	addData(array1, (uint16_t)20);
	addData(array1, (uint16_t)100);
	addData(array1, (uint16_t)3);
	addData(array1, (uint16_t)58);

	uint16_t myArray2[5];
	uint16_t array2 = init(myArray2, 5);
	addData(array2, (uint16_t)99);
	addData(array2, (uint16_t)99);
	addData(array2, (uint16_t)99);
	addData(array2, (uint16_t)99);

	TEST_ASSERT_EQUAL_UINT16(3, getMin(array1));
	TEST_ASSERT_EQUAL_UINT16(324, getMax(array1));
	TEST_ASSERT_EQUAL_UINT16(102, getAvg(array1));

	TEST_ASSERT_EQUAL_UINT16(99, getMin(array2));
	TEST_ASSERT_EQUAL_UINT16(99, getMax(array2));
	TEST_ASSERT_EQUAL_UINT16(99, getAvg(array2));


}

void test_1_before_overflow(void)
{
	//Initializing array to be tested
	uint16_t myArray[10026];
	uint16_t array1 = init(myArray, 10026);
	addData(array1, (uint16_t)60000);
	addData(array1, (uint16_t)5000);
	addData(array1, (uint16_t)500);
	addData(array1, (uint16_t)30);
	addData(array1, (uint16_t)5);


	TEST_ASSERT_EQUAL_UINT16(5, getMin(array1));
	TEST_ASSERT_EQUAL_UINT16(60000, getMax(array1));
	TEST_ASSERT_EQUAL_UINT16(13107, getAvg(array1));
}

void test_overflow(void)
{
	//Initializing array to be tested
	uint16_t myArray[10026];
	uint16_t array1 = init(myArray, 10026);
	addData(array1, (uint16_t)60000);
	addData(array1, (uint16_t)5000);
	addData(array1, (uint16_t)500);
	addData(array1, (uint16_t)30);
	addData(array1, (uint16_t)6);
	addData(array1, (uint16_t)5000);

	TEST_ASSERT_EQUAL_UINT16(6, getMin(array1));
	TEST_ASSERT_EQUAL_UINT16(60000, getMax(array1));
	TEST_ASSERT_EQUAL_UINT16(0, getAvg(array1));

}

int main(void)
{
	// run unit tests
	UNITY_BEGIN();
	RUN_TEST(test_overloading_array);
	RUN_TEST(test_not_full_array_with_same_numbers);
	RUN_TEST(test_not_full_array_with_diff_numbers);
	RUN_TEST(test_not_full_array_with_diff_numbers_with_reset);
	RUN_TEST(test_overloading_array_with_reset);
	RUN_TEST(test_multiple_handles);
	RUN_TEST(test_1_before_overflow);
	RUN_TEST(test_overflow);
	return UNITY_END();
}