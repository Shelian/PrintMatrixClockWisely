#ifndef __PRINTMATRIXCLOCKWISELY_H__
#define __PRINTMATRIXCLOCKWISELY_H__
#include<iostream>
using namespace std;

void PrintMatrixInCircle(int** matrix, int cols, int rows, int start)
{
	int EndX = cols - 1 - start;//终止列
	int EndY = rows - 1 - start;//终止行

	//左->右打印
	for (int i = start; i <= EndX; i++)
	{
		cout << matrix[start][i] << " ";
	}

	//从上往下打印    ->条件：至少有两行
	if (start < EndY)
	{
		for (int i = start + 1; i <= EndY; i++)
		{
			cout << matrix[i][EndX] << " ";
		}
	}

	//从右往左打印   条件：至少有两行两列
	if (start < EndX && start < EndY)
	{
		for (int i = EndX - 1; i >= start; --i)
		{
			cout << matrix[EndY][i] << " ";
		}
	}

	//从下往上打印  条件：至少有三行
	if (start < EndY - 1)
	{
		for (int i = EndY - 1; i >= start + 1; --i)
		{
			cout << matrix[i][start] << " ";
		}
	}
}


void PrintMatrixClockWisely(int** matrix, int cols, int rows)
{
	if (matrix == NULL || cols <= 0 || rows <= 0)
	{
		return;
	}

	int start = 0;//打印的是第几圈
	while (cols > start * 2 && rows > start * 2)//一圈一圈的打印，当c行列大于圈数乘以2是继续打印
	{
		PrintMatrixInCircle(matrix, cols, rows, start);
		start++;
	}
}


void test()
{
	int a[5][5] = { { 1, 2, 3, 4, 5 },
				{ 6, 7, 8, 9, 10 },
				{ 11, 12, 13, 14, 15 },
				{ 16, 17, 18, 19, 20 },
				{ 21, 22, 23, 24, 25 }, };

	PrintMatrixClockWisely((int**)a, 5, 5);
}

#endif //__PRINTMATRIXCLOCKWISELY_H__