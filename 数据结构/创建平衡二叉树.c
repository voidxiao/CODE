/*
	升序降序的数都没问题
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
	int data;
	struct treenode* left;
	struct treenode* right;
}TreeNode;

//创建平衡二叉树
void createTree(TreeNode** temp, int value);

//创建节点
TreeNode* createNode(int value, TreeNode* left, TreeNode* right);

//计算树的高度
int height(TreeNode* temp);

//右旋转
TreeNode** rightRotate(TreeNode** temp);

//左旋转
TreeNode** leftRotate(TreeNode** temp);


int main(void)
{
	int nArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int nArrNum = sizeof(nArr) / sizeof(int);


	TreeNode** root = (TreeNode**)malloc(sizeof(TreeNode) * nArrNum);
	//创建平衡二叉树
	for (int i = 0; i < nArrNum; i++)
	{
		root[i] = NULL;
		createTree(root, nArr[i]);
			//是否平衡
	TreeNode** temp = (TreeNode**)malloc(sizeof(TreeNode**));
	while (height((*root)->left) - height((*root)->right) > 1 || height((*root)->right) - height((*root)->left) > 1)
	{

		if (height((*root)->right) - height((*root)->left) > 1)
		{
			if (height((*root)->left) > height((*root)->right))
			{
				temp = rightRotate(root);
				(*root)->left = *temp;
			}
			//进行左旋转
			root = leftRotate(root);
		}
		if ((height((*root)->left) - height((*root)->right) > 1))
		{
			if (height((*root)->right) > height((*root)->left))
			{
				temp = leftRotate(root);
				(*root)->right = *temp;
			}
			//进行右旋转
			root = rightRotate(root);
		}
	}
	while (((*root)->left != NULL && (*root)->right != NULL) && (height((*root)->left->left) > height((*root)->left->right) || height((*root)->right->right) > height((*root)->right->left)))
	{
		if (height((*root)->left->left) > height((*root)->left->right))
		{
			temp = rightRotate(&((*root)->left));
			(*root)->left = *temp;
		}
		if (height((*root)->right->right) > height((*root)->right->left))
		{
			temp = leftRotate(&((*root)->right));
			(*root)->right = *temp;
		}
	}

	}





	system("pause");
	return 0;
}

//创建平衡二叉树
void createTree(TreeNode** temp, int value)
{
	if (*temp == NULL)
	{
		*temp = createNode(value, NULL, NULL);
	}
	if (value < (*temp)->data)
	{
		createTree(&((*temp)->left), value);
	}
	if (value > (*temp)->data)
	{
		createTree(&((*temp)->right), value);
	}
}

//创建节点
TreeNode* createNode(int value, TreeNode* left, TreeNode* right)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = value;
	temp->left = left;
	temp->right = right;
	return temp;
}

//计算树的高度
int height(TreeNode* temp)
{
	int left = 0;
	int right = 0;

	if (temp == NULL)
	{
		return 0;
	}

	if (temp->left != NULL)
	{
		left = height(temp->left);
	}
	else
	{
		left = -1;
	}
	if (temp->right != NULL)
	{
		right = height(temp->right);
	}
	else
	{
		right = -1;
	}


	//遍历到最后  每次返回都+1 最后回到根节点  得出最大高度
	return (left > right) ? (left + 1) : (right + 1);
}

//右旋转
TreeNode** rightRotate(TreeNode** temp)
{
	TreeNode** root = (TreeNode**)malloc(sizeof(TreeNode**));
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->right = (*temp)->right;
	node->left = NULL;
	node->data = (*temp)->data;
	if ((*temp)->left->right != NULL)
	{
		node->left = (*temp)->left->right;
		(*temp)->left->right = node;
	}
	else if ((*temp)->left->left != NULL)
	{
		(*temp)->left->right = node;
	}
	else
	{
		(*temp)->left = node;
	}
	root = &((*temp)->left);
	//free(temp);
	return root;
}

//左旋转
TreeNode** leftRotate(TreeNode** temp)
{
	TreeNode** root = (TreeNode**)malloc(sizeof(TreeNode**));
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = (*temp)->data;
	node->left = (*temp)->left;
	if ((*temp)->right->left != NULL)
	{
		node->right = (*temp)->right->left;
		(*temp)->right->left = node;
	}
	else if ((*temp)->right->right != NULL)
	{
		node->right = NULL;
		(*temp)->right->left = node;
	}
	else
	{
		node->right = NULL;
		(*temp)->right = node;
	}
	root = &((*temp)->right);
	//free(temp);
	return root;
}
