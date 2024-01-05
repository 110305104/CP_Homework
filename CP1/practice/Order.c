#pragma warning( disable : 4996 )
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <assert.h>

struct node {
	
	char val;
	struct node* left;
	struct node* right;

};
typedef struct node Node;

void preorder(Node* root)
{
	if (root != NULL)
	{
		printf("%c", root->val);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node* root)
{
	if (root != NULL)
	{
		inorder(root->left);
        printf("%c", root->val);
		inorder(root->right);
	}
}

void postorder(Node* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
        printf("%c", root->val);
	}
}
