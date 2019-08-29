#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
	int data;
	int leftType;
	int rightType;
	struct treenode* left;
	struct treenode* right;
}TreeNode;

//创建节点
TreeNode* createNode(int data);

//中序遍历
void minShow(TreeNode* temp);

//中序线索化二叉树
void ThreadTree(TreeNode* temp);

//中序遍历线索化二叉树
void minShowThreadTree(TreeNode* temp);

int main(void)
{
	//创建根节点
	TreeNode* root = createNode(1);
	//创建根节点的左右子节点
	root->left = createNode(2);
	root->right = createNode(3);
	//根节点左子节点创建子节点
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	//根节点右子节点创建子节点
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	//中序遍历
	minShow(root);
	printf("\n");

	//中序线索化二叉树
	ThreadTree(root);

	//中序遍历线索二叉树  对比前面的中序遍历是一样的   那就说明没问题了
	minShowThreadTree(root);
	printf("\n");




	system("pause");
	return 0;
}

//创建节点
TreeNode* createNode(int data)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = data;
	temp->leftType = 0;
	temp->rightType = 0;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
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

//中序线索化二叉树
void ThreadTree(TreeNode* temp)
{
	//当前temp的父节点
	static TreeNode* pre = NULL;

	//如果没有根节点就退出函数
	if (temp == NULL)
	{
		return;
	}

	//找到左叶子节点
	if (temp->left != NULL)
	{
		ThreadTree(temp->left);
	}

	//如果左子节点为NULL
	if (temp->left == NULL)
	{
		//让左子节点指向上一个节点  上一个节点为当前节点的前驱节点
		temp->leftType = 1;
		temp->left = pre;
	}

	//如果上一个节点不等于空  并且上一个节点的右子节点为NULL  那就指向当前节点  当前节点为它的后继节点
	if (pre != NULL && pre->right == NULL)
	{
		pre->rightType = 1;
		pre->right = temp;
	}
	pre = temp;

	if (temp->right != NULL)
	{
		ThreadTree(temp->right);
	}


}

//中序遍历线索化二叉树
void minShowThreadTree(TreeNode* temp)
{
	while (temp != NULL)
	{
		//找到leftType为1的节点
		while (temp->leftType == 0)
		{
			temp = temp->left;
		}
		//打印该节点
		printf("%d ", temp->data);

		//如果该节点的rightType为1  那就一直打印  直到不为1
		while (temp->rightType == 1)
		{
			temp = temp->right;
			printf("%d ", temp->data);
		}

		//让temp = temp->right  进行下一次循环
		temp = temp->right;
	}
}
