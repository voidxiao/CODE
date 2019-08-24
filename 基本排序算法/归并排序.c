//归并排序
//end传数组最大下标
void Sort(int* nArr, int start, int end)
{
	int min = (start + end) / 2;
	if (start < end)
	{
		//左边部分
		Sort(nArr, start, min);
		//右边部分
		Sort(nArr, min + 1, end);
		//排序
		merger(nArr, start, min, end);
	}
}

//归并
void merger(int* nArr, int start, int min, int end)
{
	//创建临时数组
	int* temp = malloc(sizeof(int) * (end - start) + 1);
	//创建下标
	int i = start;
	int j = min + 1;
	//创建临时数组下标
	int index = 0;

	//循环归并
	while (i <= min && j <= end)
	{
		if (nArr[i] < nArr[j])
		{
			temp[index] = nArr[i++];
		}
		else
		{
			temp[index] = nArr[j++];
		}
		index++;
	}

	//将剩下的接到数组尾部
	while (i <= min)
	{
		temp[index++] = nArr[i++];
	}
	while (j <= end)
	{
		temp[index++] = nArr[j++];
	}

	//复制到源数组
	for (int n = 0; n <= end - start; n++)
	{
		nArr[n + start] = temp[n];
	}
}
