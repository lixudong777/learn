/* Copyright (c) 2021 Andy Lee : lixudong777@gmail.com */
/*
	堆排序
*/
#include <stdio.h>
void swap(int v[], int i, int j);

static void heapify(int v[], int n, int head)
{
	int child, temp;

	for (temp = v[head]; 2 * head + 1 < n; head = child)
	{
		child = 2 * head + 1;
		if (child < n - 1 && v[child + 1] > v[child])
			++child;
		if (temp < v[child])
			v[head] = v[child];
		else
			break;
	}
	v[head] = temp;
}
void hpsort(int v[], int n)
{
	int i;

	for (i = n / 2; i >= 0; --i)
		heapify(v, n, i);
	for (i = n - 1; i >= 0; --i)
	{
		swap(v, 0, i);
		heapify(v, i, 0);
	}
}

void hpsort_test(int v[], int n)
{
	int i, j;

	printf("\n-------\n0: ");
	for (j = 0; j < n; ++j)
		printf("%3d", v[j]);

	for (i = n / 2; i >= 0; --i)
	{
		heapify(v, n, i);
	}
	printf("\nstart:\n1: ");
	for (j = 0; j < n; ++j)
		printf("%3d", v[j]);
	printf("\nmove:\n");
	for (i = n - 1; i >= 0; --i)
	{
		printf("*: ");
		for (j = 0; j < n; ++j)
			printf("%3d", v[j]);
		printf("\n");
		swap(v, 0, i);
		printf("+: ");
		for (j = 0; j < n; ++j)
			printf("%3d", v[j]);
		printf("\n");
		heapify(v, i, 0);
		printf("-: ");
		for (j = 0; j < n; ++j)
			printf("%3d", v[j]);
		printf("\n");
	}
}
