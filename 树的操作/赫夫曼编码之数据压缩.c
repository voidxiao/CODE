/*
	因为没有函数来实现一些功能  所以写了很多实现功能的函数
	也没有分多文件  所以比较乱
	虽然代码不怎么好  但还好 目标还是达成了
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct treenode
{
	char data;
	int value;
	struct treenode* left;
	struct treenode* right;
}TreeNode;

//储存字符与对应出现次数的结构体
typedef struct keyvalue
{
	char key;
	int value;
}keyValue;

//储存赫夫曼编码键值
typedef struct keycode
{
	char key;
	char* code;
}keyCode;
//增加keyCode
keyCode** createKeycode(keyCode** code, int index)
{
	keyCode** temp = (keyCode**)malloc(sizeof(keyCode**) * (index + 1));
	for (int i = 0; i < index; i++)
	{
		temp[i] = code[i];
	}
	temp[index] = (keyCode*)malloc(sizeof(keyCode));
	temp[index]->key = '\0';
	temp[index]->code = "\0";
	free(code);

	return temp;
}
//后接str
keyCode* setCode(keyCode* code, char* str)
{
	keyCode* temp = (keyCode*)malloc(sizeof(keyCode));
	temp->key = code->key;
	int size = strlen(code->code);
	int strsize = strlen(str);
	char* arr = (char*)malloc(sizeof(char) * (size + strsize));
	for (int i = 0; i <= size; i++)
	{
		arr[i] = code->code[i];
	}
	strcat(arr, str);
	temp->code = arr;
	return temp;
}
//复制一份键值
keyCode* clone(keyCode* source)
{
	keyCode* temp = (keyCode*)malloc(sizeof(keyCode));
	temp->code = source->code;
	temp->key = source->key;
	return temp;
}
//递归返回时  切掉最后一位code
keyCode* rmCode(keyCode* code)
{
	keyCode* temp = (keyCode*)malloc(sizeof(keyCode));
	temp->key = code->key;
	int len = strlen(code->code);
	char* arr = (char*)malloc(sizeof(char) * len);
	for (int i = 0; i < len; i++)
	{
		if (i == (len - 1))
		{
			arr[i] = '\0';
			break;
		}
		arr[i] = code->code[i];
	}
	temp->code = arr;
	return temp;
}
//置空
keyCode* resetCode(keyCode* code)
{
	keyCode* temp = (keyCode*)malloc(sizeof(keyCode));
	temp->key = '\0';
	temp->code = "\0";
	free(code);
	return temp;
}

//创建赫夫曼树
TreeNode* huffmanTree(char* str, int strLen);

//统计字符串中字符与对应出现次数
keyValue** countStr(char* str, int strLen, int* countNum);
//动态创建
keyValue** setKey(keyValue** count, int* countNum, char str);

//创建节点集合
TreeNode** createTree(keyValue** count, int countNum);
//创建节点
TreeNode* createNode(keyValue* count);

//排序节点
void sort(TreeNode** Tree, int TreeNum);

//取出value最小的两位数
TreeNode** rmNode(TreeNode** Tree, int* TreeNum, TreeNode* left, TreeNode* right);
//为最小两位数创建父节点
TreeNode* createFather(TreeNode* left, TreeNode* right);

//把父节点放回节点集合
TreeNode** setNode(TreeNode** Tree, int* TreeNum, TreeNode* node);


//创建赫夫曼编码表
keyCode** createHuffCode(TreeNode* temp, int* index);
//统计编码
keyCode** count(TreeNode* temp, keyCode** code, int* index);

//编码
char* createCode(char* str, int strLen, keyCode** code, int codeNum);

//字符串后接字符串
char* strConnect(char* strSource, char* str);

//压缩编码
char* compress(char* huffcode);

int main(void)
{
	char* str = "talk is cheap. show me the code";
	int strLen = strlen(str);

	TreeNode* Tree = (TreeNode*)malloc(sizeof(TreeNode));
	//创建赫夫曼树
	Tree = huffmanTree(str, strLen);

	//创建赫夫曼编码表
	int index = 0;
	keyCode** code = createHuffCode(Tree, &index);

	//编码
	char* huffcode = createCode(str, strLen, code, index);

	//压缩编码
	char* huffCompressCode = compress(huffcode);

	//看一下压缩后的编码
	printf("%s\n", huffCompressCode);

	system("pause");
	return 0;
}

//创建赫夫曼树
TreeNode* huffmanTree(char* str, int strLen)
{
	//统计字符串中字符与对应出现次数
	int countNum = 0;
	keyValue** count = countStr(str, strLen, &countNum);


	//创建节点集合
	int TreeNum = countNum;
	TreeNode** Tree = createTree(count, countNum);

	//循环执行
	while (TreeNum > 1)
	{
		//排序节点
		sort(Tree, TreeNum);

		//取出value最小的两个节点
		TreeNode* left = Tree[0];
		TreeNode* right = Tree[1];
		//从集合中移除
		Tree = rmNode(Tree, &TreeNum, left, right);

		//为最小两位数创建父节点
		TreeNode* node = createFather(left, right);

		//把父节点放回节点集合中
		Tree = setNode(Tree, &TreeNum, node);

	}

	return Tree[0];
}

//统计字符串中字符与对应出现次数
keyValue** countStr(char* str, int strLen, int* countNum)
{
	int index = 0;
	keyValue** count = NULL;

	//遍历字符串
	for (int i = 0; i < strLen; i++)
	{
		for (int j = 0; j < *countNum; j++)
		{
			if (str[i] == count[j]->key)
			{
				count[j]->value++;
				index = 1;
				break;
			}
			else
			{
				index = 0;
			}
		}
		if (index == 0)
		{
			count = setKey(count, countNum, str[i]);
		}
	}
	return count;
}
//动态创建
keyValue** setKey(keyValue** count, int* countNum, char str)
{
	keyValue** temp = (keyValue**)malloc(sizeof(keyValue**) * ((*countNum) + 1));
	int i = 0;
	for (i; i < *countNum; i++)
	{
		temp[i] = count[i];
	}
	temp[i] = (keyValue*)malloc(sizeof(keyValue));
	temp[i]->key = str;
	temp[i]->value = 1;
	(*countNum)++;
	free(count);
	return temp;
}

//创建节点集合
TreeNode** createTree(keyValue** count, int countNum)
{
	TreeNode** temp = (TreeNode**)malloc(sizeof(TreeNode**) * countNum);
	for (int i = 0; i < countNum; i++)
	{
		temp[i] = createNode(count[i]);
	}

	return temp;
}

//创建节点
TreeNode* createNode(keyValue* count)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = count->key;
	temp->value = count->value;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

//排序节点
void sort(TreeNode** Tree, int TreeNum)
{
	for (int i = 0; i < TreeNum - 1; i++)
	{
		for (int j = i + 1; j < TreeNum; j++)
		{
			if (Tree[i]->value > Tree[j]->value)
			{
				TreeNode* temp = Tree[j];
				Tree[j] = Tree[i];
				Tree[i] = temp;
			}
		}
	}
}

//取出value最小的两位数
TreeNode** rmNode(TreeNode** Tree, int* TreeNum, TreeNode* left, TreeNode* right)
{
	TreeNode** temp = (TreeNode**)malloc(sizeof(TreeNode**) * ((*TreeNum) - 2));
	for (int i = 0, j = 0; i < (*TreeNum); i++)
	{
		if (Tree[i] != left && Tree[i] != right)
		{
			temp[j++] = Tree[i];
		}
	}
	(*TreeNum) -= 2;
	free(Tree);
	return temp;
}

//为最小两位数创建父节点
TreeNode* createFather(TreeNode* left, TreeNode* right)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->data = '\0';
	temp->left = left;
	temp->right = right;
	temp->value = ((left->value) + (right->value));

	return temp;
}

//把父节点放回节点集合
TreeNode** setNode(TreeNode** Tree, int* TreeNum, TreeNode* node)
{
	TreeNode** temp = (TreeNode**)malloc(sizeof(TreeNode**) * ((*TreeNum) + 1));
	int i = 0;
	for (i; i < (*TreeNum); i++)
	{
		temp[i] = Tree[i];
	}
	temp[i] = node;
	(*TreeNum)++;
	free(Tree);

	return temp;
}

//创建赫夫曼编码表
keyCode** createHuffCode(TreeNode* temp, int* index)
{
	keyCode** code = (keyCode**)malloc(sizeof(keyCode**));
	code = createKeycode(code, *index);

	//统计编码
	code = count(temp, code, index);


	return code;
}

//统计编码
keyCode** count(TreeNode* temp, keyCode** code, int* index)
{
	//拿到根节点
	//static TreeNode* root = NULL;
	//if (root == NULL)
	//{
	//	root = temp;
	//}

	if (temp->data != '\0')
	{
		code[*index]->key = temp->data;
		(*index)++;
		code = createKeycode(code, *index);
		//复制一份
		code[*index] = clone(code[(*index) - 1]);
		//字符串去掉最后一位
		//code[*index] = rmCode(code[(*index) - 1]);
	}
	if (temp->left != NULL)
	{
		code[*index] = setCode(code[*index], "0");
		code = count(temp->left, code, index);
	}
	//if (temp == root)
	//{
	//	code[*index] = resetCode(code[*index]);
	//}
	if (temp->right != NULL)
	{
		code[*index] = setCode(code[*index], "1");
		code = count(temp->right, code, index);
	}
	//去除字符串code最后一位
	code[*index] = rmCode(code[*index]);
	return code;
}

//编码
char* createCode(char* str, int strLen, keyCode** code, int codeNum)
{
	char* temp = NULL;

	for (int i = 0; i < strLen; i++)
	{
		for (int j = 0; j < codeNum; j++)
		{
			if (str[i] == code[j]->key)
			{
				temp = strConnect(temp, code[j]->code);
			}
		}
	}

	return temp;
}

//字符串后接字符串
char* strConnect(char* strSource, char* str)
{
	if (strSource == NULL)
	{
		int strLen = strlen(str);
		char* temp = (char*)malloc(sizeof(str));
		for (int i = 0; i < strLen; i++)
		{
			temp[i] = str[i];
		}
		temp[strLen] = '\0';
		return temp;
	}
	else
	{
		int sourceLen = strlen(strSource);
		int strLen = sizeof(str);
		char* temp = (char*)malloc(sourceLen + strLen);
		for (int i = 0; i < sourceLen; i++)
		{
			temp[i] = strSource[i];
		}
		for (int i = sourceLen, j = 0; i < (int)((strlen(str)) + sourceLen); i++, j++)
		{
			temp[i] = str[j];
		}
		temp[(strlen(str)) + sourceLen] = '\0';
		return temp;
	}
}

//压缩编码
char* compress(char* huffcode)
{
	int huffcodeLen = strlen(huffcode);
	int line = huffcodeLen / 8;
	if (huffcodeLen % 8 != 0)
	{
		line++;
	}
	char** arr = (char**)malloc(sizeof(char*) * line);
	for (int i = 0; i < line; i++)
	{
		arr[i] = (char*)malloc(8);
	}
	int n = 0;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (n < huffcodeLen)
			{
				arr[i][j] = huffcode[n++];
			}
			else
			{
				arr[i][j] = '\0';
			}
		}
	}


	//装十进制编码的int数组
	int* nArr = (int*)malloc(sizeof(int) * line);
	//初始化为零
	for (int i = 0; i < line; i++)
	{
		nArr[i] = 0;
	}
	//把二进制转为十进制
	int lastLineNum = huffcodeLen % 8;
	for (int i = 0; i < line; i++)
	{
		for (int j = 7, n = 1; j > -1; j--, n *= 2)
		{
			//最后一行也许不是满的
			if (i == line - 1 && j == 7 && lastLineNum != 0)
			{
				j = lastLineNum - 1;
			}
			nArr[i] += (arr[i][j] - '0') * n;
		}
	}

	//释放arr空间
	for (int i = 0; i < line; i++)
	{
		free(arr[i]);
	}
	free(arr);
	arr = NULL;

	//就申请一个足够大的空间吧  麻烦不大
	int max = line * 8;
	char* temp = (char*)malloc(max);
	//初始化一下
	for (int i = 0; i < max; i++)
	{
		temp[i] = '\0';
	}
	for (int i = 0; i < line; i++)
	{
		char buf[8] = { '\0' };
		_itoa(nArr[i], buf, 10);
		strcat(temp, buf);
		strcat(temp, " ");
	}
	strcat(temp, "\0");
	int tempLen = strlen(temp);

	return temp;
}
