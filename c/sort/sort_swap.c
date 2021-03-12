/* Copyright (c) 2021 Andy Lee : lixudong777@gmail.com */
/*
    将数组中的两个数字交交换
*/
void swap(int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}