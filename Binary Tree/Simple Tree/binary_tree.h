#pragma once

#define boolean unsigned char
#define true 1
#define false 0

typedef int Element;

typedef struct tree_node* tree_pointer;
typedef struct tree_node {
	Element data;
	tree_pointer left;
	tree_pointer right;
} tree_node;

tree_pointer build_simple_tree();
int bt_count(tree_pointer ptr);
int bt_sum(tree_pointer ptr);
int bt_height(tree_pointer ptr);
void bt_show_preorder(tree_pointer ptr);
void bt_free(tree_pointer ptr);
