#include <stdio.h>
#include "singly-linked-list.h"
#define TEST_COUNT 2

int test_list_init();
void print_result(int result[TEST_COUNT], int test);
int test_1_list_init();
int test_2_list_destroy();

int main()
{
	int i, results[TEST_COUNT];

	results[0] = test_1_list_init();
	results[1] = test_2_list_destroy();

	printf("Running unit tests...\n\n");

	for (i = 0; i < TEST_COUNT; i++)
	{
		print_result(results, i);
	}
}

void print_result(int result[TEST_COUNT], int test)
{
	if (test >= TEST_COUNT)
	{
		printf(
			"That test doesn't exist. There are %d tests and you passed index \
			%d\n",
			TEST_COUNT, test);
	}

	if (result[test] != 0)
	{
		printf("%d. \x1b[1;31mFAIL\x1b[0m with error no %d!\n", test + 1, result[test]);
	}
	else
	{
		printf("%d. \x1b[1;32mPASS\x1b[0m\n", test + 1);
	}
}

int test_1_list_init()
{
	List list;
	list_init(&list, NULL);

	if (list.head != NULL)
		return 1;
	else if (list.tail != NULL)
		return 2;
	else if (list.destroy != NULL)
		return 3;
	else
		return 0;
}

int test_2_list_destroy()
{
	return 1;
}
