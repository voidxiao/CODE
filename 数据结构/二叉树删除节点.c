#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
	int data;
	struct treenode* left;
	struct treenode* right;
}TreeNode;

//创建节点
TreeNode* createNode(int data);

//遍历节点
void frontShow(TreeNode* temp);

//删除节点
void deleteNode(TreeNode** temp, int value);
//释放节点的所有下级节点
void freeNode(TreeNode* temp);

int main(void)
{
	//创建根节点
	TreeNode* root = createNode(1);
	//为根节点创建左右子节点
	root->left = createNode(2);
	root->right = createNode(3);
	//为根节点的左节点创建左右节点
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	//为根节点的右节点创建左右节点
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	//遍历节点
	frontShow(root);
	printf("\n");

	//删除节点
	deleteNode(&root, 3);

	//查看是否删除成功
	frontShow(root);
	printf("\n");


	system("pause");
	return 0;
}

//创建节点
TreeNode* createNode(int data)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

//遍历打印节点数据
void frontShow(TreeNode* temp)
{
	//判断是否为空  不为空才打印
	if (temp == NULL)
	{
		return;
	}
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

//删除节点
void deleteNode(TreeNode** temp, int value)
{
	if ((*temp)->data == value)
	{
		freeNode(*temp);
		*temp = NULL;
	}
	else
	{
		if ((*temp)->left != NULL)
		{
			deleteNode(&((*temp)->left), value);
		}
		if ((*temp)->right != NULL)
		{
			deleteNode(&((*temp)->right), value);
		}
	}
}

//释放节点的所有下级节点
void freeNode(TreeNode* temp)
{
	if (temp != NULL)
	{
		if (temp->left != NULL)
		{
			freeNode(temp->left);
			temp->left = NULL;
		}
		if (temp->right != NULL)
		{
			freeNode(temp->right);
			temp->right = NULL;
		}
		if (temp->left == NULL && temp->right == NULL)
		{
			//释放节点空间
			free(temp);
			//temp = NULL; 这样子赋NULL是没用的  因为它的父节点还指向它  所以要把父节点的左右子节点指针赋NULL
		}
	}
}
