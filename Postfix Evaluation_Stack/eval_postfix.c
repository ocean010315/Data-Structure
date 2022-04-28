#include <stdio.h>
#pragma warning(disable : 4996)
#include "eval_postfix.h"

void main() {
	char exp[100]; //postfix expression
	int result;

	while (1) {
		err_check = false;
		printf("\n Input postfix expression: ");
		scanf("%s", exp);

		result = eval_postfix(exp);
		if (err_check == false)
			printf("\n result = %d \n", result);
	}
}

void push(int e) {
	if (top == MAX_SIZE)
		err_check = true;
	else
		stack[++top] = e;
}

int pop() {
	if (top == -1) {
		err_check = true;
		return 0;
	}
	else {
		return stack[top--];
	}
}

int eval_postfix(char* exp) {
	int result = 0;

	for (int i = 0; exp[i] != '\0'; i++) {
		if (is_number(exp[i]) == true) {
			push(exp[i] - '0');
		}
		else if (is_op(exp[i]) == true) {
			int value = pop();

			switch (exp[i]) {
			case '+':
				result = value + pop();
				break;

			case '-':
				result = -1 * value + pop();
				break;

			case '*':
				result = value * pop();
				break;

			case '/':
				if (value == 0) {
					err_check = true;
					printf("\n divided by 0 error \n");
				}
				else {
					result = pop() / value;
				}
				break;
			}
			push(result);
		}
		else err_check = true;
	}

	return result;
}

boolean is_number(char c) {
	if (('0' <= c) && (c <= '9'))
		return true;
	else
		return false;
}

boolean is_op(char c) {
	if (('0' <= c) && (c <= '9'))
		return false;
	else
		return true;
}
