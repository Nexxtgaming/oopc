#include "Stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test_push(Stack* test_stack_ptr, int num_of_push) {
	printf("number of pushes: %d \n", num_of_push);

	for (int i = 0; i < num_of_push; i++) {
		int element = rand() % 100;
		push(test_stack_ptr, element);
		printf("pushing %d, dynamic array size %d index of top element %d \n",
			   element, test_stack_ptr->array_size, test_stack_ptr->top);
	}
}

void test_pop(Stack* test_stack_ptr, int num_of_pop) {
	printf("number of pop: %d \n", num_of_pop);

	for (int i = 0; i < num_of_pop; i++) {
		int deleted_item = pop(test_stack_ptr);
		printf("poping %d, dynamic arrray size %d index of top element %d \n",
			   deleted_item, test_stack_ptr->array_size, test_stack_ptr->top);
	}
}

int main() {
	Stack test_stack;
	Stack* test_stack_ptr = &test_stack;

	init(test_stack_ptr);
	srand(time(NULL));

	int num_of_push = 5;
	int num_of_pop = 5;

	test_push(test_stack_ptr, num_of_push);
	test_pop(test_stack_ptr, num_of_pop);

	destroy(test_stack_ptr);
	return 0;
}
