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

//前序查找
TreeNode* frontSearch(TreeNode* temp, int value);
//中序查找
TreeNode* minSearch(TreeNode* temp, int value);
//后序查找
TreeNode* rearSearch(TreeNode* temp, int value);

int main(void)
{
	//创建根节点
	TreeNode* root = createNode(1);
	//为根节点创建子节点
	root->left = createNode(2);
	root->right = createNode(3);
	//为根节点的左子节点创建节点
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	//为根节点的右子节点创建节点
	root->right->left = createNode(6);
	root->right->right = createNode(7);


	TreeNode* value = NULL;
	//前序查找
	if (value = frontSearch(root, 5))
	{
		printf("%p   data: %d\n", value, value->data);
	}
	else
	{
		printf("%s \n", (char*)value);
	}
	//中序查找
	if(value = minSearch(root, 6))
	{
		printf("%p   data: %d\n", value, value->data);
	}
	else
	{
		printf("%s \n", (char*)value);
	}
	//后序查找
	if(value = rearSearch(root, 7))
	{
		printf("%p   data: %d\n", value, value->data);
	}
	else
	{
		printf("%s \n", (char*)value);
	}




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

//前序查找
TreeNode* frontSearch(TreeNode* temp, int value)
{
	TreeNode* target = NULL;

	if (temp->data == value)
	{
		return temp;
	}
	else
	{
		if (temp->left != NULL)
		{
			target = frontSearch(temp->left, value);
		}
		//左节点找到了直接return返回target  直到第一层递归返回target  target就是所要找的节点
		if (target != NULL)
		{
			return target;
		}
		if (temp->right != NULL)
		{
			target = frontSearch(temp->right, value);
		}
	}
	//右节点找到了通过这个return返回
	return target;
}

//中序查找
TreeNode* minSearch(TreeNode* temp, int value)
{
	TreeNode* target = NULL;

	if (temp->left != NULL)
	{
		target = minSearch(temp->left, value);
	}
	if (target != NULL)
	{
		return target;
	}
	if (temp->data == value)
	{
		return temp;
	}
	if (temp->right != NULL)
	{
		target = minSearch(temp->right, value);
	}
	return target;
}

//后序查找
TreeNode* rearSearch(TreeNode* temp, int value)
{
	TreeNode* target = NULL;

	if (temp->left != NULL)
	{
		target = rearSearch(temp->left, value);
	}
	if (target != NULL)
	{
		return target;
	}
	if (temp->right != NULL)
	{
		target = rearSearch(temp->right, value);
	}
	if (temp->data == value)
	{
		return temp;
	}
	return target;
}
