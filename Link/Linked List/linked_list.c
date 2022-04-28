#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include "linked_list.h"

void main() {
	char c, e;
	list_pointer head, p;

	// dummy head 노드
	head = (list_pointer)malloc(sizeof(list_node));
	head->data = NULL;
	head->link = NULL;
	
	//print문 추가
	printf("**************Command************** \n");
	printf("+<c> : Insert c, -<c> : Delete c, \n");
	printf("?<c> : Search c, S : Show, Q : Quit \n");
	printf("*********************************** \n");

	while (1) {
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);

		switch (c) {
			case '+':
				e = _getch();
				_putch(e);
				list_insert(head, e);
				break;

			case '-':
				e = _getch();
				_putch(e);
				list_delete(head, e);
				break;
	
			case '?':
				e = _getch();
				_putch(e);
				p = list_search(head, e);

				if (p) {
					printf("\n %c is in the list. \n", e);
					printf(" Node address = %p, data = %c, link = %p \n", p, p->data, p->link);
				}
				else printf("\n %c is not in the list \n", e);
				break;

			case 'S':
				list_show(head);
				break;

			case 'Q':
				printf("\n");
				exit(1);

			default: break;
		}
	}
}

void list_insert(list_pointer head, Element e) {
	list_pointer p = (list_pointer)malloc(sizeof(list_node));

	if (p == NULL) return;

	p->data = e;
	p->link = head->link;

	head->link = p;
}

void list_delete(list_pointer head, Element e) {  //re
	if (list_empty(head)) printf("\nList is empty \n");
	else {
		list_pointer p = head, save;

		while (p) {
			if (p->link->data == e) {
				save = p->link;
				p->link = p->link->link;

				free(save);

				return;
			}
			
			p = p->link;
		}
	}
}

list_pointer list_search(list_pointer head, Element e) {
	list_pointer p = head;
	
	while (p) { //head 자체에 주소값이 있기 때문에 head->data와 head->link가 NULL이라도 while 안에 p가 참
		if (p->data == e) return p;
		p = p->link;
	}

	return NULL;
}

bool list_empty(list_pointer head) {
	if (head->link == NULL) return true;
	else return false;
}

void list_show(list_pointer head) {
	printf("\n");

	if (list_empty(head)) printf("List is empty \n");
	else {
		list_pointer p = head;

		while (p != NULL) {
			printf("%2c", p->data);
			p = p->link;
		}
	}
}
