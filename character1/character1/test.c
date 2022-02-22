#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//不创建第三个变量进行数据交换
void test11(int a, int b)
{
	a = a + b;//8
	b = a - b;//5
	a = a - b;//3
	printf("after1: a = %d,b = %d\n", a, b);
}
void test22(int a, int b)
{
	a = a ^ b;
	//0101
	//0011
	//0110
	b = a ^ b;
	//0110
	//0011
	//0101
	a = a ^ b;
	//0110
	//0101
	//0011
	printf("after2: a = %d,b = %d\n", a, b);
}

//求一个整数在内存中的二进制中1的个数
void test1(int num)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		//num = 1010
		// 1  = 0001
		if ((num >> i) & 1 == 1)
		{
			count++;
		}
	}
	printf("二进制中1的个数 = %d\n", count);
}
void test2(int num)
{
	int count = 0;
	while (num)
	{
		if (num % 2 == 1)
		{
			count++;
		}
		num = num / 2;
		//10%2=0 10/2=5
		// 5%2=1  5/2=2
		// 2%2=0  2/2=1
		// 1%2=1  1/2=0
	}
	printf("二进制中1的个数 = %d\n", count);
}
void test3(int num)
{
	int i = 0;
	int count = 0;
	while (num)
	{
		count++;
		num = num & (num - 1);
		//1010    1000
		//1001 -> 0111
		//1000    0000
	}
	printf("二进制中1的个数 = %d\n", count);
}
int main()
{
	//不创建第三个变量进行数据交换
	int a = 5;
	int b = 3;
	printf("before: a = %d,b = %d\n", a, b);
	//方法1
	test11(a, b);
	//方法2
	test22(a, b);
/*-------------------------------------------------*/
	//求一个整数在内存中的二进制中1的个数
	int num = 10;
	//方法1
	test1(num);
	//方法2
	test2(num);
	//方法3
	test3(num);
	return 0;
}


