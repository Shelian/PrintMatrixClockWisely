#ifndef __PRINTMATRIXCLOCKWISELY_H__
#define __PRINTMATRIXCLOCKWISELY_H__
#include<iostream>
using namespace std;

void PrintMatrixInCircle(int** matrix, int cols, int rows, int start)
{
	int EndX = cols - 1 - start;//��ֹ��
	int EndY = rows - 1 - start;//��ֹ��

	//��->�Ҵ�ӡ
	for (int i = start; i <= EndX; i++)
	{
		cout << matrix[start][i] << " ";
	}

	//�������´�ӡ    ->����������������
	if (start < EndY)
	{
		for (int i = start + 1; i <= EndY; i++)
		{
			cout << matrix[i][EndX] << " ";
		}
	}

	//���������ӡ   ��������������������
	if (start < EndX && start < EndY)
	{
		for (int i = EndX - 1; i >= start; --i)
		{
			cout << matrix[EndY][i] << " ";
		}
	}

	//�������ϴ�ӡ  ����������������
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

	int start = 0;//��ӡ���ǵڼ�Ȧ
	while (cols > start * 2 && rows > start * 2)//һȦһȦ�Ĵ�ӡ����c���д���Ȧ������2�Ǽ�����ӡ
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