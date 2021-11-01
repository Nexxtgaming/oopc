#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"

void init(Stack* stack){
	stack->array = (int*)malloc(sizeof(int));
	if(stack->array == NULL)exit(1);
	stack->top = 0; 
	stack->array_size = 1;
}

void destroy(Stack* stack){
	free(stack->array);
	stack->top = 0;
	stack->array_size = 0;
}

void push(Stack* stack, int element){
	int * new_array = NULL;
	stack->top +=1;

	if(stack->top > stack->array_size){
		new_array = realloc(stack->array, stack->array_size * 2 * sizeof(int));
		if(new_array == NULL) exit(1);
		stack->array_size *=2;
		stack->array = new_array;
	}

	stack->array[stack->top-1] = element;
}

bool isEmpty(Stack* stack){
	if(stack->top == 0) return true;
	return false;
}

int pop(Stack* stack){
	if(isEmpty(stack)){
		printf("stack is empty \n");
		free(stack->array);
		abort();
	}
	int deleted_item = stack->array[stack->top-1];
	stack->top --;
	return deleted_item;
}

