/* Copyright (c) 2021 Andy Lee : lixudong777@gmail.com */
/*
    插入排序
*/
void swap(int v[], int i, int j);
void insort(int v[], int n)
{
	int i, j, temp;

	for (i = 1; i < n; ++i)
	{
		temp = v[i];
		for (j = i; j > 0 && temp < v[j - 1]; --j)
			v[j] = v[j - 1];
		v[j] = temp;
	}
}