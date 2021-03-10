/*
 * hello
 */
#include <stdio.h>

int main(void) 
{
	printf("hello, world\n");
	return 0;
}
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void swap(int v[], int i, int j) {
  int temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
