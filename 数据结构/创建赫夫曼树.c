#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
	int data;
	struct treenode* left;
	struct treenode* right;
}TreeNode;

//创建赫夫曼树
TreeNode* createTree(int* nArr, int num);

//排序二叉树集合
void sort(TreeNode** Tree, int num);

//为最小的两个数创建父节点
TreeNode* createNode(TreeNode* left, TreeNode* right);

//从二叉树集合中移除掉这最小的两个数
TreeNode** rmNode(TreeNode** Tree, int* num, TreeNode* left, TreeNode* right);

//把创建的父节点放进二叉树集合中
TreeNode** setNode(TreeNode** Tree, int* num, TreeNode* node);

//前序遍历
void frontShow(TreeNode* temp);


int main(void)
{
	//创建一个数组
	int nArr[] = { 3, 7, 8, 29, 5, 11, 23, 14 };
	int num = sizeof(nArr) / 4;
	//创建赫夫曼树
	TreeNode* root = createTree(nArr, num);

	//打印以下看看结果
	frontShow(root);
	printf("\n");



	system("pause");
	return 0;
}

//创建赫夫曼树
TreeNode* createTree(int* nArr, int num)
{
	//创建一个二叉树集合
	TreeNode** Tree = (TreeNode**)malloc(sizeof(TreeNode**) * num);
	for (int i = 0; i < num; i++)
	{
		Tree[i] = (TreeNode*)malloc(sizeof(TreeNode));
		Tree[i]->data = nArr[i];
		Tree[i]->left = NULL;
		Tree[i]->right = NULL;
	}

	//循环处理
	while (num > 1)
	{
		//从小到大排序二叉树集合
		sort(Tree, num);

		//拿到最小的两个数
		TreeNode* left = Tree[0];
		TreeNode* right = Tree[1];

		//创建最小两个数的父节点
		TreeNode* node = createNode(left, right);

		//从二叉树集合中移除掉这最小的两个数
		Tree = rmNode(Tree, &num, left, right);

		//把创建的父节点放进二叉树集合中
		Tree = setNode(Tree, &num, node);

	}




	return Tree[0];
}

//排序二叉树集合
void sort(TreeNode** Tree, int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = i + 1; j < num; j++)
		{
			if (Tree[i]->data > Tree[j]->data)
			{
				TreeNode* temp = Tree[i];
				Tree[i] = Tree[j];
				Tree[j] = temp;
			}
		}
	}
}

//为最小的两个数创建父节点
TreeNode* createNode(TreeNode* left, TreeNode* right)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = left->data + right->data;
	temp->left = left;
	temp->right = right;

	return temp;
}

//从二叉树集合中移除掉这最小的两个数
TreeNode** rmNode(TreeNode** Tree, int* num, TreeNode* left, TreeNode* right)
{
	TreeNode** temp = (TreeNode**)malloc(sizeof(TreeNode**) * *num);
	int j = 0;
	for (int i = 0; i < *num; i++)
	{
		if (Tree[i] != left && Tree[i] != right)
		{
			temp[j] = Tree[i];
			j++;
		}
	}
	free(Tree);
	*num -= 2;

	return temp;
}

//把创建的父节点放进二叉树集合中
TreeNode** setNode(TreeNode** Tree, int* num, TreeNode* node)
{
	TreeNode** temp = (TreeNode**)malloc(sizeof(TreeNode**) * (*num + 1));
	int i = 0;
	for (i = 0; i < *num; i++)
	{
		temp[i] = Tree[i];
	}
	temp[i] = node;
	free(Tree);
	(*num)++;
	return temp;
}

//前序遍历
void frontShow(TreeNode* temp)
{
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
