#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//快速排序
void Sort(int* nArr, int start, int end);

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

	//快速排序
	Sort(nArr, 0, num - 1);

	printf("这是从小到大排序后的数组:");
	for (int i = 0; i < num; i++)
	{
		printf("%d ", nArr[i]);
	}
	printf("\n");



	system("pause");
	return 0;
}

//快速排序
void Sort(int* nArr, int start, int end)
{
	int high = end,
		low = start;

	//标准数
	int stand = nArr[start];

	if (end > start)
	{
		while (low < high)
		{
			//如果高位大于标准数
			while (nArr[high] >= stand && low < high)
			{
				high--;
			}
			//如果高位小于标准数
			nArr[low] = nArr[high];

			//如果低位小于标准数
			while (nArr[low] <= stand && low < high)
			{
				low++;
			}
			//如果低位大于标准数
			nArr[high] = nArr[low];
		}
		//low与high重合  这里下标用low和high都可以  因为他们已经重合
		nArr[low] = stand;

		//将数组分开处理
		//递归低位
		Sort(nArr, start, low);
		//递归高位
		Sort(nArr, low + 1, end);
	}
}
