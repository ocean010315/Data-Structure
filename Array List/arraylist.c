#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

void main() {
	char c;

	printf("******************** Command *******************\n");
	printf("+<c>: Insert c, -<c>: Delete c, \n");
	printf("E: ListEmpty, F: ListFull, S: ListShow, Q: Quit \n");
	printf("************************************************\n");

	while (1) {
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);

		switch (c) {
			case '+':
				c = _getch(); //
				_putch(c); //
				list_insert(c);
				break;

			case '-':
				c = _getch();
				_putch(c);
				list_delete(c);
				break;

			case 'E':
				if (list_empty()) printf("\nTRUE \n");
				else printf("\nFALSE \n");
				break;

			case 'F':
				if (list_full()) printf("\nTRUE \n");
				else printf("\nFALSE \n");
				break;

			case 'S':
				list_show();
				break;

			case 'Q':
				printf("\n");
				exit(1);

			default:
				break;
		}
	}
}

void list_insert(Element e) {
	if (list_full()) {
		printf("\nList is full !!! \n");
	}
	else {
		List[size] = e;
		size++;
	}
}

void list_delete(Element e) {
	if (list_empty()) {
		printf("\nList is Empty !!! \n");
	}
	else {
		int cnt = 0, i;

		for (i = 0; i < size; i++) {
			if (List[i] == e) {
				List[i] = List[i + 1];
				size--;
				cnt++;
			}
		}

		if (cnt == 0)
			printf("\nData does not exist !!! \n");
	}
}

boolean list_empty() {
	if (size == 0)
		return true;
	else
		return false;
}

boolean list_full() {
	if (size == MaxSize)
		return true;	//리스트가 가득 차 있으면 true
	else
		return false;
}

void list_show() {
	if (list_empty()) {
		printf("\nList is Empty !!! \n");
	}
	else {
		puts("");
		for (int i = 0; i < size; i++) {
			printf("%c ", List[i]);
		}
		puts("");
	}
}
