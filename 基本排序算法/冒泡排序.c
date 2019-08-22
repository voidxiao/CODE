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
