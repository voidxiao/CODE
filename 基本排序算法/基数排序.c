//基数排序
void Sort(int* nArr, int num)
{
	//临时数组
	int* nArrTemp = (int*)malloc(sizeof(int) * num);
	//创建数组记录数字元素下标
	int index[10] = { 0 };
	//生成二维数组
	int** temp = (int**)malloc(sizeof(int*) * 10);
	for (int t = 0; t < 10; t++)
	{
		temp[t] = (int*)malloc(sizeof(int) * num);
	}

	//找出源数组中最大的数
	int max = INT_MIN;
	for (int m = 0; m < num; m++)
	{
		if (nArr[m] > max)
		{
			max = nArr[m];
		}
	}

	int fre = 0;
	//计算需要排序的次数
	while (max > 0)
	{
		max /= 10;
		fre++;
	}

	//排序循环
	for(int j = 1; fre > 0; fre--, j *= 10)
	{
		//把nArr中的数  按顺序放到二维数组中
		for (int i = 0; i < num; i++)
		{
			int mod = nArr[i] / j % 10;
			temp[mod][index[mod]++] = nArr[i];
		}

		//把二维数组中的数   按顺序取出来
		int n = 0;
		for (int i = 0; i < 10; i++)
		{
			//index数组是temp二维数组的数量记录  如果index[i] = 0  代表temp[i]中没有需要排序的数
			if (index[i] == 0)
			{
				continue;
			}
			//顺序的将数字复制回源数组中
			for (int j = 0; j < index[i]; j++)
			{
				nArr[n++] = temp[i][j];
			}
			//置空index数组  其他不管 不会造成影响  index才是主要的存取记录表
			index[i] = 0;
		}
	}
}
