#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "ex3.h"

void main() {
	char c;
	read_record(fname);
	printf("********** 명령어 ********** \n");
	printf("P: Print all records \n");
	printf("S: Search record \n");
	printf("C: Change record \n");
	printf("W: Write record \n");
	printf("Q: Save and quit \n");
	printf("**************************** \n");

	while (1) {
		printf("\nCommand> ");
		c = _getch(); //
		_putch(c); //
		c = toupper(c);

		switch (c) {
			case 'P':
				print_record();
				break;

			case 'S':
				search_record();
				break;

			case 'C':
				change_record();
				break;

			case 'W':
				write_record(fname);
				break;

			case 'Q':
				printf("\n");
				exit(1);
				break;

			default:
				printf("Unknown command ! \n");
				break;
		}
	}
}

void read_record(char* fname) {
	printf("Reading record from grade.txt ... \n");

	int i = 0;

	FILE* ifp;
	ifp = fopen(fname, "r");
	
	while (fscanf(ifp, "%s %d %s", r[i].name, &r[i].id, r[i].grade) == 3)
		++i;
	num_record = i;
	
	fclose(ifp);

	printf("%d records have read. \n", num_record);
}

void print_record() {
	printf("\n------------------------------------ \n");

	for (int i = 0; i < num_record; i++) {
		printf("%10s %10d %10s \n", r[i].name, r[i].id, r[i].grade);
	}

	printf("------------------------------------ \n");
}

void search_record() {
	int i;
	char s_name[10];

	printf(" Search name : ");
	scanf("%s", s_name);

	for (i = 0; i < num_record; i++) {
		if (strcmp(s_name, r[i].name) == 0) {
			printf("    Name   : %s \n", r[i].name);
			printf("    ID     : %d \n", r[i].id);
			printf("    Grade  : %s \n", r[i].grade);
		}
	}
}

void change_record() {
	char c_name[10];
	char c_grade[4];
	puts("");

	printf("  Name : ");
	scanf("%s", c_name);

	printf("  Grade : ");
	scanf("%s", c_grade);

	for (int i = 0; i < num_record; i++) {
		if (strcmp(c_name, r[i].name) == 0) {
			strcpy(r[i].grade, c_grade);
		}
	}

	printf("\nRecord changed! \n");
}

void write_record(char* fname) {
	puts("");

	int i = 0;
	
	FILE* file;
	file = fopen(fname, "w");
	
	for (int i = 0; i < num_record; i++) {
		fprintf(file, "%s %d %s\n", r[i].name, r[i].id, r[i].grade);
	}
	
	fclose(file);

	printf("%d records have written to grade.txt.\n", num_record);
}
