#include "Stack.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define NUM_PUSH 4
#define NUM_POP 3

using namespace std;

void test_push(Stack* stack) {
	for (int i = 0; i < NUM_PUSH; i++) {
		int element = rand() % 100;
		stack->push(element);
	}
}

void test_pop(Stack* stack) {
	for (int i = 0; i < NUM_POP; i++) {
		int deleted_item = stack->pop();
		cout << "deleted item " << deleted_item << "top index"
			 << stack->getTop() << endl;
	}
}

void runFunction1(Stack stack) { cout << "stack is passed by value" << endl; }

void runFunction2(Stack& stack) {
	cout << "stack is passed by reference" << endl;
}

void test_extended() {
	Stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);

	Stack s2(s1);
	Stack s3 = s1;

	Stack s4;
	s4.push(10);
	s4 = s1;

	runFunction1(s1); // Stack object is passed by value.
	runFunction2(s1); // Stack object is passed by reference.
}

int main() {
	srand(time(NULL));

	cout << "---------stack 1------------" << endl;
	Stack stack_1 = Stack();
	test_push(&stack_1);
	test_pop(&stack_1);

	cout << "---------stack 2------------" << endl;
	Stack stack_2 = Stack();
	test_push(&stack_2);
	test_pop(&stack_2);

	test_extended();

	return 0;
}
