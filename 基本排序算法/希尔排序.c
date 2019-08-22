//希尔排序
void Sort(int* nArr, int num)
{
	int temp = 0;

	//遍历所有的步长
	for (int step = num / 2; step > 0; step /= 2)
	{
		//遍历步长的元素
		for (int i = step; i < num; i++)
		{
			//比较每组步长的元素  插入元素
			for (int j = i - step; j > -1; j -= step)
			{
				if (nArr[j] > nArr[j + step])
				{
					temp = nArr[j];
					nArr[j] = nArr[j + step];
					nArr[j + step] = temp;
				}
			}
		}
	}
}
