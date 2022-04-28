#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "bst_dictionary.h"

void main() {
	char c, fname[20];
	char w1[100], * w2;
	int wcount;

	printf("************* Command ************\n");
	printf("R: Read data, S: Search data \n");
	printf("P: Print inorder, Q: Quit \n");
	printf("**********************************\n");

	while (1) {
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);
		
		switch (c) {
			case 'R':
				printf("\n Dictionary file name: ");
				scanf("%s", fname);
				wcount = build_dictionary(fname);
				printf(" Total number of words: %d \n", wcount);
				break;

			case 'S':
				printf("\n Word: ");
				scanf("%s", w1);
				w2 = bst_search(w1);
				if (w2) printf(" Meaning: %s \n", w2);
				else printf(" No such word ! \n");
				break;

			case 'P':
				printf("\n");
				bst_show_inorder(root);
				break;

			case 'Q':
				printf("\n");
				exit(1);

			default: break;
		}
	}
}

int build_dictionary(char* fname) {
	FILE* file = fopen(fname, "r");

	int cnt = 0;
	char w1[100], w2[100];

	while (!feof(file)) {
		fscanf(file, "%s %s\n", w1, w2);
		bst_insert(w1, w2);
		cnt++;
	}

	fclose(file);
	return cnt; // 단어 개수 맞나 확인
}

void bst_insert(char* w1, char* w2) {
	tree_pointer new_node = (tree_pointer)malloc(sizeof(tree_node));
	strcpy(new_node->w1, w1);
	strcpy(new_node->w2, w2);
	new_node->left = new_node->right = NULL;

	if (root == NULL) root = new_node;
	else {
		tree_pointer tmp, back;
		tmp = back = root;

		while(tmp) {
			if (strcmp(new_node->w1, tmp->w1) == 0) return;

			if (strcmp(new_node->w1, tmp->w1) > 0) {
				back = tmp;
				tmp = tmp->right;
			}
			else {
				back = tmp;
				tmp = tmp->left;
			}
		}

		if (strcmp(new_node->w1, back->w1) > 0) back->right = new_node;
		else back->left = new_node;
	}
}

char* bst_search(char* w1) {
	tree_pointer tmp = root;

	while (tmp) {
		if (strncmp(w1, tmp->w1, 10) == 0) return tmp->w2;

		if (strncmp(w1, tmp->w1, 10) > 0) {
			tmp = tmp->right;
		}
		else tmp = tmp->left;
	}

	return NULL;
}

void bst_show_inorder(tree_pointer ptr) {
	if (ptr == NULL) return;

	bst_show_inorder(ptr->left);
	printf(" %s %s \n", ptr->w1, ptr->w2);
	bst_show_inorder(ptr->right);
}
