/* Copyright (c) 2021 Andy Lee : lixudong777@gmail.com */
/*
冒泡排序法
*/
void swap(int v[], int i, int j);

void bbsort(int v[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; ++i)
		for (j = 0; j < n - i - 1; ++j)
			if (v[j] > v[j + 1])
				swap(v, j, j + 1);
}