//简单选择排序算法
void Sort(int* nArr, int num)
{
	int temp = 0;
	int index = 0;

	//遍历数组拿基准数i
	for (int i = 0; i < num - 1; i++)
	{
		//基准数
		index = i;

		//找到最小的数的下标
		for (int j = i + 1; j < num; j++)
		{
			if (nArr[j] < nArr[index])
			{
				//记录最小数的下标
				index = j;
			}
		}
		//确定这是最小的数
		if (nArr[i] > nArr[index])
		{
			//交换
			temp = nArr[index];
			nArr[index] = nArr[i];
			nArr[i] = temp;
		}
	}
}
