#include "head.h"
#define MASS_TEST_TIME (100 * 10 * 1 * 1 * 1)
#define REPEAT_TIME (100 * 100 * 10)
//#define MASS_TEST_TIME 2147483646

void rdsort(int v[], int n);
void qksort(int v[], int n);

void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void test_sort_result(int v[], int n)
{
	int i;

	printf(" Result");
	fflush(stdout);
	for (i = 0; i < n - 1; ++i)
		if (v[i] > v[i + 1])
		{
			printf("..Error.");
			return;
		}
	printf("..OK.");
}
void mass_sort(int n, void (*sort)(int *, int))
{
	int i, j;
	int *v;
	time_t start_t, end_t;
	double t;

	//printf("\nMAX_UNSIGNED:%10u,", UINT_MAX);
	//printf("\nMAX_LONG: %10ld", LONG_MAX);
	printf("\nMAX_INT:%10d, ", INT_MAX);
	printf("\nn  =   :%10d, ", n);

	v = (int *) malloc(n * sizeof(int));
	if (v == NULL)
	{
		printf("malloc() return NULL\n");
		return;
	}
	printf("Repeat:%3d, Start...", REPEAT_TIME);
	fflush(stdout);
	t = 0;
	for (j = 0; j < REPEAT_TIME; ++j)
	{
		for (i = 0; i < n; ++i)
			v[i] = rand() % 2147483646;
		time(&start_t);
		sort(v, n);
		time(&end_t);
		t += difftime(end_t, start_t);
	}
	printf("Finished.");
	test_sort_result(v, n);
	printf(" Time: %4.1f", t);
	printf("\n");
	free(v);
}
static int get_max(int v[], int n)
{
	int max, i;

	max = v[0];
	for (i = 1; i < n; ++i)
		if (v[i] > max)
			max = v[i];
	return max;
}
static void radix_count(int v[], int n, int radix, int exp)
{
	int *data, *count, i, id;

	count = (int *) malloc(radix * sizeof(int));
	data = (int *) malloc(n * sizeof(int));
	if (count == NULL || data == NULL)
	{
		printf("malloc() return NULL\n");
		return;
	}
	for (i = 0; i < radix; ++i)
		count[i] = 0;
	for (i = 0; i < n; ++i)
		++count[((long)(v[i]) / exp) % (long) radix];
	for (i = 1; i < radix; ++i)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; --i)
	{
		id = ((long) (v[i]) / exp) % (long) radix;
		data[count[id] - 1] = v[i];
		--count[id];
	}
	for (i = 0; i < n; ++i)
		v[i] = data[i];
	free(count);
	free(data);
}
void radix_sort(int v[], int n, int radix)
{
	long exp;
	int max = get_max(v, n);

	for (exp = 1; max / exp > 0; exp *= radix)
		radix_count(v, n, radix, exp);
}
void rdsort(int v[], int n)
{
	radix_sort(v, n, 2048);
}
void quicksort(int v[], int left, int right)
{
	int last, i;

	if (left >= right)
		return;
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
void shsort(int v[], int n)
{
	int gap, i, j;

	for (gap = n / 2; gap > 0; gap /= 2)
		for (i = 0; i < n; ++i)
			for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
				swap(v, j, j + gap);
}
#define TEST_MASS_SORT(n, fun)  do{printf(""#fun"(). ");mass_sort(n, fun);}while(0)
void test_mass()
{
	int n = MASS_TEST_TIME;
	TEST_MASS_SORT(n, rdsort);
	TEST_MASS_SORT(n, qksort);
	TEST_MASS_SORT(n, shsort);
}
int main()
{
	test_mass();
	return 0;
}
