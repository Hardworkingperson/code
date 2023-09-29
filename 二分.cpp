#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//初始化一个数组
	int k = 0;//初始化我们要寻找的数字k
	int sz = sizeof(arr) / sizeof(arr[0]);//计算数组内元素的个数
	int left = 0;
	int right = sz-1;//元素的下标是元素的大小-1
	printf("请输入要查找的数字：");
	scanf("%d", &k);//输入要查找的数字k
	while (left<=right)//左下标比右下标小循环才有意义，是循环开始的条件
	{
		int mid = (left + right) / 2;//定义中间的下标
		if (k > arr[mid])
		{
			left = mid + 1;
			//如果我们要寻找的元素比中间元素大
			//就将中间元素换成最左边的元素
		}
		else if (k < arr[mid])
		{
			right = mid - 1;
			//如果我们要寻找的元素比中间元素小
            //就将中间元素换成最右边的元素
		}
		else 
		{
			printf("找到了，下标是：%d\n", mid);//如果我们要寻找的元素等于中间元素
			                                     //输出中间元素的下标，并退出循环
			break;
		}
	}
	if (left > right)//当我们全部找一遍以后，没有找到，并且跳出循环，只能输出找不到
		printf("找不到\n");
	return 0;
}
