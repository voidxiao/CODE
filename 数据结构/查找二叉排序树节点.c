#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
	int data;
	struct treenode* left;
	struct treenode* right;
}TreeNode;

//创建二叉排序树
void createSearchTree(TreeNode** temp, int data);

//查找节点
TreeNode* searchNode(TreeNode* temp, int value);

int main(void)
{
	int nArr[7] = { 7, 3, 10, 12, 5, 1, 9 };
	//创建二叉排序树
	TreeNode* root = NULL;
	for (int i = 0; i < 7; i++)
	{
		createSearchTree(&root, nArr[i]);
	}

	//查找节点
	TreeNode* node = searchNode(root, 3);
	printf("%p\ndata:%d\nleft:%p  data:%d\nright:%p  data:%d\n", node, node->data,\
		node->left,node->left->data,node->right, node->right->data);

	printf("-----------------------------\n");

	//找一个没有的节点
	node = searchNode(root, 100);
	printf("%p\n", node);


	system("pause");
	return 0;
}

//创建二叉排序树
void createSearchTree(TreeNode** temp, int data)
{
	if (*temp == NULL)
	{
		*temp = (TreeNode*)malloc(sizeof(TreeNode));
		(*temp)->data = data;
		(*temp)->left = NULL;
		(*temp)->right = NULL;
	}
	if ((*temp)->data > data)
	{
		createSearchTree(&((*temp)->left), data);
	}
	if ((*temp)->data < data)
	{
		createSearchTree(&((*temp)->right), data);
	}
}

//查找节点
TreeNode* searchNode(TreeNode* temp, int value)
{
	static TreeNode* node = NULL;

	if (temp->data == value)
	{
		return temp;
	}
	if (temp->data > value && temp->left != NULL)
	{
		node = searchNode(temp->left, value);
	}
	if (temp->data < value && temp->right != NULL)
	{
		node = searchNode(temp->right, value);
	}
	return node;
}
