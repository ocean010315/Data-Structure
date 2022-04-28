#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked_queue.h"

void main() {
	char c, e;

	front = rear = NULL;

	printf("****************Command**************** \n");
	printf("+<c> : AddQ, - : DeleteQ, \n");
	printf("S: Show, Q: Quit \n");
	printf("*************************************** \n");

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
				if (is_queue_empty()) {
					printf("\n Queue is empty !!! \n");
				}
				else {
					e = deleteq();
					printf("\n %c ", e);
				}
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

void addq(Element e) {
	queue_pointer tmp = (queue_pointer)malloc(sizeof(struct queue));
	tmp->item = e;
	tmp->link = NULL;
	
	if (front == NULL) {
		front = rear = tmp;
	}
	else {
		rear->link = tmp;
		rear = tmp;
	}
}

Element deleteq() {
	queue_pointer tmp;
	Element item;

	if (is_queue_empty()) {
		item = NULL;
		printf("\n Queue is empty ! \n");
		return item;
	}
	else {
		item = front->item;
		tmp = front;
		front = front->link;

		free(tmp);

		return item;
	}
}

void queue_show() {
	queue_pointer tmp = front;
	
	puts("");
	while (tmp) {
		printf("%3c", tmp->item);
		tmp = tmp->link;
	}
}

boolean is_queue_empty() {
	if (front == NULL)
		return true;
	else
		return false;
}
