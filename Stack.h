#pragma once

#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>

typedef struct {
	int * array;
	int array_size;
	int top;
} Stack;

void init(Stack* s);
void destroy(Stack* s);
void push(Stack* s, int element);
int pop(Stack* s);
bool isEmpty(Stack* s);

#endif
