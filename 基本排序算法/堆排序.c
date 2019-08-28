//堆排序
void Sort(int* nArr, int size)//第二个参数是数组的大小
{
	int temp = 0;
	//最后一个非叶子节点
	int start = ((size - 1) - 1) / 2;

	//调整为大顶堆
	for (int i = start; i > -1; i--)
	{
		resetHeap(nArr, size, i);
	}

  //把第一个最大的和最后一个最小的互换  把size - 1  让最后一个最大的不参与递归调整
	//就这样让最大的一直往后靠  最终升序排序完成
	if (size > 0)
	{
		temp = nArr[0];
		nArr[0] = nArr[size - 1];
		nArr[size - 1] = temp;
		Sort(nArr, size - 1);
	}

}

//调整为大顶堆
void resetHeap(int* nArr, int size, int index)
{
	int temp = 0;
	int max = index;

	//比较节点大小
	if (2 * index + 1 < size && nArr[max] < nArr[2 * index + 1])
	{
		max = 2 * index + 1;
	}
	if (2 * index + 2 < size && nArr[max] < nArr[2 * index + 2])
	{
		max = 2 * index + 2;
	}

	//调整节点
	if (max != index)
	{
		temp = nArr[index];
		nArr[index] = nArr[max];
		nArr[max] = temp;
		resetHeap(nArr, size, max);
	}
}
