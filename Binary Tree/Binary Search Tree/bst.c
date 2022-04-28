#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "bst.h"

void main() {
	char c, grade;
	int id;

	printf("************* Command ************\n");
	printf("I: Insert data, S: Search data \n");
	printf("P: Print inorder, Q: Quit \n");
	printf("********************************** \n");
	
	while (1) {
		printf("\nCommand> ");
		c = _getch();
		_putch(c);
		c = toupper(c);

		switch (c) {
			case 'I':
				printf("\n id and grade: ");
				scanf("%d %c", &id, &grade);
				bst_insert(id, grade);
				break;

			case 'S':
				printf("\n id: ");
				scanf("%d", &id);
				grade = bst_search(id);

				if (grade) printf(" Grade of %d: %c \n", id, grade);
				else printf(" No such id ! \n");
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

void bst_insert(int key, char data) {
	tree_pointer new_node = (tree_pointer)malloc(sizeof(tree_node));
	new_node->key = key;
	new_node->data = data;
	new_node->left = new_node->right = NULL;

	if (root == NULL) {
		root = new_node;
		return;
	}
	else {
		tree_pointer tmp = root, back = root;

		while (tmp) {
			if (key == tmp->key) return;
			else if (key > tmp->key) {
				back = tmp;
				tmp = tmp->right;
			}
			else {
				back = tmp;
				tmp = tmp->left;
			}
		}

		if (key > back->key) back->right = new_node;
		else back->left = new_node;
	}
}

char bst_search(int key) {
	tree_pointer tmp = root;

	while (tmp) {
		if (key == tmp->key) return tmp->data;
		
		if (key > tmp->key) {
			tmp = tmp->right;
		}
		else tmp = tmp->left;
	}
}

void bst_show_inorder(tree_pointer ptr) {
	if (ptr == NULL) return;

	if (ptr) {
		bst_show_inorder(ptr->left);
		printf("%5d %2c \n", ptr->key, ptr->data);
		bst_show_inorder(ptr->right);
	}
}
