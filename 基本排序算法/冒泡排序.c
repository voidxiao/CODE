#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//ð������
void Sort(int* nArr, int num);

int main(void)
{
	int* nArr = NULL;
	int num = 0;
	printf("������Ҫ�������ٸ�����:");
	scanf("%d", &num);
	nArr = (int*)malloc(sizeof(int) * num);

	printf("������һ������,ÿ������һ������\n");
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &nArr[i]);
	}

	printf("������������:");
	for (int i = 0; i < num; i++)
	{
		printf("%d ", nArr[i]);
	}
	printf("\n");

	Sort(nArr, num);

	printf("���Ǵ�С����������������:");
	for (int i = 0; i < num; i++)
	{
		printf("%d ", nArr[i]);
	}
	printf("\n");



	system("pause");
	return 0;
}

//ð������
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
