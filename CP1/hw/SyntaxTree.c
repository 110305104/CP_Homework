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

//   a        +       b
//operant1 operator operant2

Node* cal() {
	Node* newNode = malloc(sizeof(Node));
	char tmp;
	scanf("%c", &tmp);

	if (tmp != '(' && tmp != ')')
	{
		newNode->val = tmp; //write Operant
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}


  //Inorder
	newNode->left = cal(); //先開左節點

	scanf("%c", &newNode->val); //write Operator

	newNode->right = cal(); //再開右節點


	scanf("%c", &tmp); //read '('

	return newNode;
}



void preorder(Node* root)
{
	if (root != NULL)
	{
		printf("%c", root->val);
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {

	Node* root = cal();
	preorder(root);

	return 0;
}