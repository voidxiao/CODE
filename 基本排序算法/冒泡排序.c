#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//冒泡排序
void Sort(int* nArr, int num);


int main(void)
{
	int* nArr = NULL;
	int num = 0;
	printf("请问你要输入多少个数字:");
	scanf("%d", &num);
	nArr = (int*)malloc(sizeof(int) * num);

	printf("请输入一个数组,每次输入一个数字\n");
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &nArr[i]);
	}

	printf("输入的数组是:");
	for (int i = 0; i < num; i++)
	{
		printf("%d ", nArr[i]);
	}
	printf("\n");

	Sort(nArr, num);

	printf("这是从小到大排序后的数组:");
	for (int i = 0; i < num; i++)
	{
		printf("%d ", nArr[i]);
	}
	printf("\n");



	system("pause");
	return 0;
}

//冒泡排序
void Sort(int* nArr, int num)
{
	int temp = 0;

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (nArr[j] > nArr[j + 1])
			{
				temp = nArr[j + 1];
				nArr[j + 1] = nArr[j];
				nArr[j] = temp;
			}
		}
	}
}
