#include "Stack.h"
#include <cstring>
#include <iostream>

using namespace std;

Stack::Stack() {
	this->array = (int*)malloc(sizeof(int));
	if (this->array == NULL) {
		cout << "cannot allocate memory" << endl;
		abort();
	}
	this->top = 0;
	this->arraySize = 1;
}

void Stack::push(int element) {
	int* new_array = NULL;
	this->top += 1;

	if (this->top > this->arraySize) {
		new_array =
			(int*)realloc(this->array, this->arraySize * 2 * sizeof(int));
		if (new_array == NULL) {
			cout << "cannot reallocate memory" << endl;
			abort();
		}
		this->arraySize *= 2;
		this->array = new_array;
	}

	this->array[this->top - 1] = element;
	cout << "pushing " << element << " array size" << this->arraySize
		 << " top index" << this->top << endl;
}

bool Stack::isEmpty() {
	if (this->top == 0)
		return true;
	return false;
}

int Stack::pop() {
	if (isEmpty()) {
		printf("stack is empty \n");
		free(this->array);
		abort();
	}
	int deleted_item = this->array[this->top - 1];
	this->top--;
	return deleted_item;
}
int Stack::getTop() { return this->top; }
Stack::Stack(const Stack& other) {
	this->array = (int*)malloc(other.arraySize * sizeof(int));
	if (this->array == NULL) {
		cout << "cannot allocate memory" << endl;
		abort();
	}
	this->arraySize = other.arraySize;
	this->top = other.top;
	memmove(this->array, other.array, this->arraySize * sizeof(int));
}

const Stack& Stack::operator=(const Stack& other) {
	int* newArray;
	if (this == &other)
		return *this;
	if (this->arraySize < other.top - 1) {
		newArray = (int*)realloc(this->array, (other.top - 1) * sizeof(int));
		if (newArray == NULL) {
			cout << "cannot reallocate memory" << endl;
			abort();
		}
		this->array = newArray;
		memcpy(this->array, other.array, (other.top - 1) * sizeof(int));
		this->arraySize = other.arraySize;
		this->top = other.top;
	} else {
		memcpy(this->array, other.array, (other.top - 1) * sizeof(int));
		this->top = other.top;
	}
	return *this;
}

Stack::~Stack() {
	free(this->array);
	cout << "freeing memory" << endl;
}
