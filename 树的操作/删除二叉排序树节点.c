/*
	当前代码 只能删除根节点有两个子节点的二叉排序树
*/

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

//删除节点
void deleteNode(TreeNode** temp, int value);

//查找父节点
TreeNode* searchFather(TreeNode* temp, int value);

//查找需要删除的节点
TreeNode* searchNode(TreeNode* temp, int value);

//取到一棵树中最小的节点的值
TreeNode* getMinNode(TreeNode* temp);

//中序遍历查看结果是否正确
void midShow(TreeNode* temp);

int main(void)
{
	int nArr[] = { 5, 3, 8, 1, 4, 6, 10, 2, 7, 9 };
	int num = sizeof(nArr) / 4;
	//创建二叉排序树
	TreeNode* root = NULL;
	for (int i = 0; i < num; i++)
	{
		createSearchTree(&root, nArr[i]);
	}


	//删除节点
	deleteNode(&root, 5);


	//中序从小到大打印结果
	midShow(root);
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


//删除节点
void deleteNode(TreeNode** temp, int value)
{
	if ((*temp) == NULL)
	{
		return;
	}
	TreeNode* target = searchNode(*temp, value);
	TreeNode* fatherNode = searchFather(*temp, value);

	//删除的节点是叶子节点
	if (target->left == NULL && target->right == NULL)
	{
		//删除的节点是父节点的左子节点
		if (fatherNode->left == target)
		{
			fatherNode->left = NULL;
		}
		//删除的节点是父节点的右子节点
		else
		{
			fatherNode->right = NULL;
		}
		//释放空间
		free(target);
	}
	//删除有两个子节点的节点
	else if (target->left != NULL && target->right != NULL)
	{
		//取到一棵树中最小的节点的值
		TreeNode* minNode = getMinNode(target->right);

		//如果最小的值的节点还有一个右子节点   因为不可能有左子节点  如果有左子节点 那最小的值的节点  肯定就不是它
		//找到minNode的父节点
		TreeNode* minFather = searchFather(*temp, minNode->data);
		if (minNode->right != NULL)
		{
			//minNode父节点指向minNode的右子节点
			minFather->left = minNode->right;
		}
		//minNode没有子节点
		else
		{
			if (minFather->left == minNode)
			{
				minFather->left = NULL;
			}
			else
			{
				minFather->right = NULL;
			}
		}
		//把找到的最小的值的节点的值  赋给要删除的节点  这就相当于删除了
		target->data = minNode->data;
		//释放空间
		free(minNode);
	}
	//删除只有一个子节点的节点
	else
	{
		//目标节点有一个左子节点
		if (target->left != NULL)
		{
			//目标节点是父节点的左子节点
			if (fatherNode->left == target)
			{
				fatherNode->left = target->left;
			}
			else
			{
				fatherNode->right = target->left;
			}
		}
		//目标节点只有一个右子节点
		else
		{
			//目标节点是父节点的左子节点
			if (fatherNode->left == target)
			{
				fatherNode->left = target->right;
			}
			//目标节点是父节点的右子节点
			else
			{
				fatherNode->right = target->right;
			}
		}
		//释放空间
		free(target);
	}
}

//查找父节点
TreeNode* searchFather(TreeNode* temp, int value)
{
	static TreeNode* node = NULL;

	if ((temp->left != NULL && temp->left->data == value) || (temp->right != NULL && temp->right->data == value))
	{
		return temp;
	}
	if (value < temp->data && temp->left != NULL)
	{
		node = searchFather(temp->left, value);
	}
	if (value > temp->data && temp->right != NULL)
	{
		node = searchFather(temp->right, value);
	}
	return node;
}

//查找需要删除的节点
TreeNode* searchNode(TreeNode* temp, int value)
{
	static TreeNode* node = NULL;

	if (temp->data == value)
	{
		return temp;
	}
	if (temp->left != NULL && temp->data > value)
	{
		node = searchNode(temp->left, value);
	}
	if (temp->right != NULL && temp->data < value)
	{
		node = searchNode(temp->right, value);
	}
	return node;
}

//取到一棵树中最小的节点的值
TreeNode* getMinNode(TreeNode* temp)
{
	static TreeNode* min = NULL;
	if (min == NULL)
	{
		min = temp;
	}
	if (temp->data < min->data)
	{
		min = temp;
	}
	if (temp->left != NULL)
	{
		min = getMinNode(temp->left);
	}
	if (temp->right != NULL)
	{
		min = getMinNode(temp->right);
	}
	return min;
}

//中序遍历查看结果是否正确
void midShow(TreeNode* temp)
{
	if (temp->left != NULL)
	{
		midShow(temp->left);
	}
	printf("%d ", temp->data);
	if (temp->right != NULL)
	{
		midShow(temp->right);
	}
}
