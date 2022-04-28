#include <stdio.h>
#include "arraystack.h"

void main() {
	char c, e;

	printf("********************Command******************** \n");
	printf("+<c> : push c, - : pop, \n");
	printf("S : show, Q : quit \n");

	while (1) {
		printf("\nCommand>");
		c = _getch();
		_putch(c);
		c = toupper(c);

		switch (c) {
		case '+':
			e = _getch();
			_putch(e);
			push(e);
			break;

		case '-':
			e = pop();
			if (e != NULL)
				printf("\n %c \n", e);
			break;

		case 'S':
			stack_show();
			break;

		case 'Q':
			printf("\n");
			exit(1);

		default: break;
		}
	}
}

void push(Element e) { //require: 스택 포화 X, result: 스택에 e 삽입
	if (top == MAX_SIZE - 1) {
		printf("\n stack is full \n");
	}
	else {
		stack[++top] = e;
	}
}

Element pop() { //require: 스택 비어있지 X, result 스택 원소 반환
	if (top == -1) {
		printf("\n stack is empty \n");
		return 0;
	}
	else {
		return stack[top--];
	}
}

void stack_show() { //result: 스택 내용 보여줌
	if (top == -1) {
		printf("\n stack is empty \n");
	}
	else {
		puts("");

		for (int i = 0; i <= top; i++) {
			printf(" %c ", stack[i]);
		}
	}
}
