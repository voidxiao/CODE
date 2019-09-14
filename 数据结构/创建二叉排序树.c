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

//验证一下  使用中序遍历  遍历出来是从小到大的  可以是认为创建成功了
void minShow(TreeNode* temp);

int main(void)
{
	int nArr[7] = { 7, 3, 10, 12, 5, 1, 9 };
	//创建二叉排序树
	TreeNode* root = NULL;
	for (int i = 0; i < 7; i++)
	{
		createSearchTree(&root, nArr[i]);
	}

	//验证一下  使用中序遍历  遍历出来是从小到大的  可以是认为创建成功了
	minShow(root);
	printf("\n");



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

//验证一下  使用中序遍历  遍历出来是从小到大的  可以是认为创建成功了
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
