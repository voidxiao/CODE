#include<stdlib.h>

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
TreeNode* create(int value);

int main(void)
{
	//创建一棵树
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	//创建一个根节点
	TreeNode* root = create(1);
	//把根节点放到树里
	tree->root = root;
	//为根节点创建左子节点
	root->left = create(2);
	//为根节点创建右子节点
	root->right = create(3);




	return 0;
}

//创建节点
TreeNode* create(int value)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}
