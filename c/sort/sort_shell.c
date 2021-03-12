/* Copyright (c) 2021 Andy Lee : lixudong777@gmail.com */
/*
    希尔shell排序
*/
void swap(int v[], int i, int j);

void shsort(int v[], int n)
{
	int gap, i, j;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = gap; i < n; ++i)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
				swap(v, j, j + gap);
}