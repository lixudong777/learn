/* Copyright (c) 2021 Andy Lee : lixudong777@gmail.com */
/*
	快速排序
*/
#include <stdlib.h>
void swap(int v[], int i, int j);

void qksort2(int v[], int n)
{
	int last, i;

	if (n <= 1)
		return;
	swap(v, 0, rand() % n);
	last = 0;
	for (i = 1; i < n; ++i)
		if (v[i] < v[0])
			swap(v, ++last, i);
	swap(v, 0, last);
	qksort2(v, last);
	qksort2(v + last + 1, n - last - 1);
}
void quicksort(int v[], int left, int right)
{
	int last, i;

	if (left >= right)
		return ;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; ++i)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	quicksort(v, left, last - 1);
	quicksort(v, last + 1, right);
}
void qksort(int v[], int n)
{
	quicksort(v, 0, n - 1);
}