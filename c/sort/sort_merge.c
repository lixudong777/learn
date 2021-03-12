/* Copyright (c) 2021 Andy Lee : lixudong777@gmail.com */
/*
	归并排序法
	
*/
#include <stdio.h>
#include <stdlib.h>

static void merge(int v[], int left, int mid, int right);
static void test_sort_result(int v[], int n)
{
	int i;

	printf(" Result");
	for (i = 0; i < n - 1; ++i)
		if (v[i] > v[i + 1])
		{
			printf("..Error.");
			return;
		}
	printf("..OK.");
}
void test_merge(void)
{
	int v[] = {2, 4, 6, 8, 1, 3, 5, 7};
	int n = sizeof(v) / sizeof(*v);
	int i;


	for (i = 0; i < n; ++i)
		printf("%3d", v[i]);
	printf("\n");
	merge(v, 0, 3, 7);
	for (i = 0; i < n; ++i)
		printf("%3d", v[i]);
	printf("\n");

}
static void merge(int v[], int left, int mid, int right)
{
	int *temp;
	int i, j, k;

	temp = (int *) malloc((right - left + 1) * sizeof(int));

	i = left;
	j = mid + 1;
	k = 0;
	while (i <= mid && j <= right)
		if (v[i] < v[j])
			temp[k++] = v[i++];
		else
			temp[k++] = v[j++];
	while (i <= mid)
		temp[k++] = v[i++];
	while (j <= right)
		temp[k++] = v[j++];
	for (i = 0; i < k; ++i)
		v[left + i] = temp[i];
}
void mergesort(int v[], int left, int right)
{
	int mid;

	if (left >= right)
		return;
	mid = (left + right) / 2;
	mergesort(v, left, mid);
	mergesort(v, mid + 1, right);
	merge(v, left, mid, right);
}
void mgsort(int v[], int n)
{
	mergesort(v, 0, n - 1);
}
void test_mgsort()
{
	int v[11];
	int n = sizeof(v) / sizeof(*v);
	int i;

	for (i = 0; i < n; ++i)
		v[i] = rand() % 100;
	mgsort(v, n);
	for (i = 0; i < n; ++i)
		printf("%3d", v[i]);
	test_sort_result(v, n);

	printf("\n");
}
int main()
{
	test_merge();
	test_mgsort();
	return 0;
}