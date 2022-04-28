#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include "arrayqueue.h"

void main() {
	char c, e;

	printf("*************Command************* \n");
	printf("+<c> : AddQ c, - : Delete Q, \n");
	printf("S : Show, Q : Quit \n");
	printf("********************************* \n");

	while (1) {
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);

		switch (c) {
			case '+':
				e = _getch();
				_putch(e);
				addq(e);
				break;

			case '-':
				e = deleteq();
				if (is_empty != true)
					printf("\n %c", e);
				break;

			case 'S':
				queue_show();
				break;

			case 'Q':
				printf("\n");
				exit(1);

			default: break;
		}
	}
}

void addq(Element e) { //queue[front]는 항상 empty
	if ((rear + 1) % MAX_SIZE == front) { //front 0&rear9, front 1&rear 0, front 2&rear 1, 
		is_empty = false;
		printf("\nqueue is full \n");
	}
	else {
		is_empty = false;
		rear = (rear + 1) % MAX_SIZE;
		queue[rear] = e;
	}
}

Element deleteq() {
	if (rear == front) {
		is_empty = true;
		printf("\nqueue is empty \n");
	}
	else {
		is_empty = false;
		front = (front + 1) % MAX_SIZE; //front는 첫 번째 원소의 가장 앞을 가리킴
		return queue[front];
	}
}

void queue_show() {
	puts("");

	if (rear == front)
		printf("queue is empty \n");
	else {
		for (int i = front % MAX_SIZE; i % MAX_SIZE != rear; i++) {
			printf("%2c", queue[(i + 1) % MAX_SIZE]);
		}
	}
}
