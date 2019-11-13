#pragma once
#include <stdio.h>
#include <stdbool.h>

typedef struct treeNode
{
	int data;
	struct treeNode* left;
	struct treeNode* right;
} TREE_NODE;

typedef struct
{
	int count;
	TREE_NODE* root;
} BST_TREE;

BST_TREE* bstCreate();
void bstDestroy(BST_TREE* tree);
static void _bstDestroy(TREE_NODE* root);

bool bstInsert(BST_TREE* tree, int data);
TREE_NODE* _insert(TREE_NODE*, TREE_NODE*);
bool bstDelete(BST_TREE* tree, int key);
TREE_NODE* _delete(TREE_NODE*, int);
TREE_NODE* bstSearch(BST_TREE* tree, int key);
TREE_NODE* _search(TREE_NODE*, int);

bool bstEmpty(BST_TREE* tree);
int bstCount(BST_TREE* tree);
