#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//直接插入排序
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

	//直接插入排序
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

//直接插入排序
void Sort(int* nArr, int num)
{
	int temp = 0;

	//遍历数组
	for (int i = 1; i < num; i++)
	{
		//如果比前一个数字小
		if (nArr[i] < nArr[i - 1])
		{
			//存进临时空间
			temp = nArr[i];

			//寻找合适的插入位置
			for (int j = i; j > -1; j--)
			{
				if (temp < nArr[j - 1] && j > 0)//j > 0防止数组越界比较
				{
					nArr[j] = nArr[j - 1];
				}
				//如果temp已经不小于nArr[j - 1]  代表已经找到合适的位置  然后插入数字  跳出循环
				else
				{
					nArr[j] = temp;
					break;
				}
			}
		}
	}
}
