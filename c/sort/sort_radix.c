/* Copyright (c) 2021 Andy Lee : lixudong777@gmail.com */
/*
	基数排序
*/
#include <stdlib.h>

// static int get_max(int a[], int n)
// {
// 	int i, max;

// 	max = a[0];
// 	for (i = 1; i < n; ++i)
// 		if(a[i] > max)
// 			max = a[i];
// 	return max;
// }
static int get_max(int v[], int n)
{
	int max, i;

	max = v[0];
	for (i = 1; i < n; ++i)
		if (v[i] > max)
			max = v[i];
	return max;
}
// static void radix_count(int v[], int n, int radix, int power)
// {
// 	int *temp;
// 	int *bk;
// 	int i;

// 	temp = (int *) malloc(n * sizeof(int));
// 	bk = (int *) malloc(radix * sizeof(int));
// 	if (temp == NULL || bk == NULL)
// 		return ;
// 	for (i = 0; i < radix; ++i)
// 		bk[i] = 0; 
// 	for (i = 0; i < n; ++i)
// 		++bk[(v[i] / power) % radix];
// 	for (i = 1; i < radix; ++i)
// 		bk[i] += bk[i - 1];
// 	for (i = n - 1; i >= 0; --i)
// 	{
// 		temp[bk[(v[i] / power) % radix] - 1] = v[i];
// 		--bk[(v[i] / power) % radix];
// 	}
// 	for (i = 0; i < n; ++i)
// 		v[i] = temp[i];
// 	free(temp);
// 	free(bk);
// }
static void radix_count(int v[], int n, int radix, long power)
{
	int *data, *count, i, id;

	count = (int *) malloc(radix * sizeof(int));
	data = (int *) malloc(n * sizeof(int));
	if (count == NULL || data == NULL)
		return;
	for (i = 0; i < radix; ++i)
		count[i] = 0;
	for (i = 0; i < n; ++i)
		++count[(v[i] / power) % radix];
	for (i = 1; i < radix; ++i)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; --i)
	{
		id = (v[i] / power) % radix;
		data[count[id] - 1] = v[i];
		--count[id];
	}
	for (i = 0; i < n; ++i)
		v[i] = data[i];
	free(count);
	free(data);
}
// void radix_sort(int v[], int n, int radix)
// {
// 	long power;
// 	int max = get_max(v, n);

// 	for (power = 1; max / power > 0; power *= radix)
// 		radix_count(v, n, radix, power);
// }
// void rdsort(int v[], int n)
// {
// 	radix_sort(v, n, 10);
// }
void radix_sort(int v[], int n, int radix)
{
	long power;
	int max = get_max(v, n);

	for (power = 1; max / power > 0; power *= radix)
		radix_count(v, n, radix, power);
}
void rdsort(int v[], int n)
{
	radix_sort(v, n, 2048);
}