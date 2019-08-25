#include<stdlib.h>
#include<stdio.h>

typedef struct treenode
{
	int data;
	struct treenode* left;
	struct treenode* right;
}TreeNode;

typedef struct
{
	TreeNode* root;
}Tree;

//创建节点
TreeNode* createNode(int value);

//前序遍历
void frontShow(TreeNode* temp);
//中序遍历
void minShow(TreeNode* temp);
//后序遍历
void rearShow(TreeNode* temp);

int main(void)
{
	//创建一棵树
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	//创建根节点
	TreeNode* root = createNode(1);
	//把根节点放到树中
	tree->root = root;
	//为根节点创建左子节点
	root->left = createNode(2);
	//为根节点创建右子节点
	root->right = createNode(3);
	//为根节点的左子节点创建子节点
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	//为根节点的右子节点创建子节点
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	//前序遍历
	frontShow(root);
	printf("\n");
	//中序遍历
	minShow(root);
	printf("\n");
	//后序遍历
	rearShow(root);
	printf("\n");





	system("pause");
	return 0;
}

//创建节点
TreeNode* createNode(int value)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

//前序遍历
void frontShow(TreeNode* temp)
{
	printf("%d ", temp->data);
	if (temp->left != NULL)
	{
		frontShow(temp->left);
	}
	if (temp->right != NULL)
	{
		frontShow(temp->right);
	}
}

//中序遍历
void minShow(TreeNode* temp)
{
	if (temp->left != NULL)
	{
		minShow(temp->left);
	}
	printf("%d ", temp->data);
	if (temp->right != NULL)
	{
		minShow(temp->right);
	}
}

//后序遍历
void rearShow(TreeNode* temp)
{
	if (temp->left != NULL)
	{
		rearShow(temp->left);
	}
	if (temp->right != NULL)
	{
		rearShow(temp->right);
	}
	printf("%d ", temp->data);
}
