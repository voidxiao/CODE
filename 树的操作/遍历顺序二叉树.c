#include<stdio.h>
#include<stdlib.h>

//长度
#define LEN 7
//根节点下标
#define ROOT 0

//创建顺序二叉树
int* createTree(int num);
//初始化节点数据
void setNodeData(int* tree);

//前序遍历顺序二叉树
void frontShow(int* tree, int index);					/*index传从哪开始遍历*/
//中序遍历
void minShow(int* tree, int index);
//后序遍历
void rearShow(int* tree, int index);

int main(void)
{
	//创建一个顺序二叉树
	int* tree = createTree(LEN);
	//初始化节点数据
	setNodeData(tree);


	//前序遍历
	frontShow(tree, ROOT);
	printf("\n");
	//中序遍历
	minShow(tree, ROOT);
	printf("\n");
	//后序遍历
	rearShow(tree, ROOT);
	printf("\n");



	system("pause");
	return 0;
}

//创建顺序二叉树
int* createTree(int num)
{
	int* temp = (int*)malloc(sizeof(int) * num);
	return temp;
}

//初始化节点数据
void setNodeData(int* tree)
{
	for (int i = 0; i < 7; i++)
	{
		tree[i] = i + 1;
	}
}

//前序遍历顺序二叉树
void frontShow(int* tree, int index)
{
	printf("%d ", tree[index]);
	if (2 * index + 1 < LEN)
	{
		frontShow(tree, 2 * index + 1);
	}
	if (2 * index + 2 < LEN)
	{
		frontShow(tree, 2 * index + 2);
	}
}

//中序遍历
void minShow(int* tree, int index)
{
	if (2 * index + 1 < LEN)
	{
		minShow(tree, 2 * index + 1);
	}
	printf("%d ", tree[index]);
	if (2 * index + 2 < LEN)
	{
		minShow(tree, 2 * index + 2);
	}
}

//后序遍历
void rearShow(int* tree, int index)
{
	if (2 * index + 1 < LEN)
	{
		rearShow(tree, 2 * index + 1);
	}
	if (2 * index + 2 < LEN)
	{
		rearShow(tree, 2 * index + 2);
	}
	printf("%d ", tree[index]);
}
