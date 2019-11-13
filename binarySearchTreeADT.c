#pragma once
#include <stdio.h>
#include <stdbool.h>
#include "binarySearchTreeADT.h"

BST_TREE* bstCreate()
{
	BST_TREE* tree = (BST_TREE*)malloc(sizeof(BST_TREE));
	if (tree)
	{
		tree->root = NULL;
		tree->count = 0;
	}

	return tree;
}

void bstDestroy(BST_TREE* tree)
{
	if (tree)
	{
		_bstDestroy(tree->root);
		tree->count = 0;

		free(tree);
	}
}

void _bstDestroy(TREE_NODE* root)
{
	if (root == NULL)
	{
		return;
	}

	if (root->left)
	{
		_bstDestroy(root->left);
	}

	if (root->right)
	{
		_bstDestroy(root->right);
	}

	free(root);
}


bool bstInsert(BST_TREE* tree, int data)
{
	TREE_NODE *pNode = NULL;

	pNode = (TREE_NODE*)malloc(sizeof(TREE_NODE));
	if (!pNode)
	{
		return NULL;
	}
	
	pNode->left = NULL;
	pNode->right = NULL;
	pNode->data = data;

	if (tree->count == 0)
	{
		tree->root = pNode;
	}
	else
		_insert(tree->root, pNode);

	(tree->count)++;
	return true;
}

TREE_NODE* _insert(TREE_NODE* root, TREE_NODE* newNode)
{
	if (root == NULL)
	{
		return newNode;
	}

	if (newNode->data < root->data)
	{
		root->left = _insert(root->left, newNode);
	}
	else
	{
		root->right = _insert(root->right, newNode);
	}

}

bool bstDelete(BST_TREE* tree, int key)
{
	TREE_NODE *dtrNode = (TREE_NODE*)malloc(sizeof(TREE_NODE));

	if (tree->count == 0)
	{
		return false;
	}
	else if (tree->count == 1)
	{
		free(root);
	}
	
	_delete(tree->root, key);
	(tree->count)--;
	return true;

}

bool* _delete(TREE_NODE *root, int key)
{
	if (key < root->data)
	{
		root->left = _delete(root->left, key);
	}

	else if (key > root->data)
	{
		root->right = _delete(root->right, key);
	}

	else
	{

		if (!root->right)
		{
			delPtr = root;
			root = root->left;
			free(delPtr);
			return true;
		}

		else if (!root->left)
		{
			delPtr = root;
			root = root->right;
			free(delPtr);
			return true;
		}

		else
		{
			for (delPtr = root->left; delPtr->right != NULL; delPtr = delPtr->right);
			root->data = delPtr->data;
			root->left = _delete(root->left, delPtr->data);
		}
	}

	return true;
}

TREE_NODE* bstSearch(BST_TREE* tree, int key)
{
	return _search(tree->root, key);
}

TREE_NODE* _search(TREE_NODE* root, int key)
{
	if (!root)
	{
		return NULL;
	}

	if (root->data < key)
	{
		return(root->right, key);
	}
	else if (root->data > key)
	{
		return(root->left, key);
	}
	else
		return root;
}

bool bstEmpty(BST_TREE* tree)
{
	if (tree->count <= 0)
	{
		return true;
	}

	return false;
}

int bstCount(BST_TREE* tree)
{
	return tree->count;
}