/* Copyright (c) 2021 Andy Lee : lixudong777@gmail.com */
/*
	kmp 排序法
*/
#include <stdio.h>		// printf()
#include <stdlib.h>		// malloc(), exit()
#include <string.h>		// strlen(), strncmp()

void getlps(const char *pat, int *lps)
{
	int pat_len = strlen(pat);
	int i, j;

	lps[0] = 0;
	for (i = 1, j = 0; i < pat_len; )
	{
		if (pat[i] == pat[j])
		{
			++j;
			lps[i] = j;
			++i;
		}
		else if (j != 0)
			j = lps[j - 1];
		else 
		{
			lps[i] = 0;
			++i;
		}
	}
}
int kmp_search(const char *txt, const char *pat)
{
	int txt_len = strlen(txt);	
	int pat_len = strlen(pat);
	int t, p;
	int *lps;

	lps = (int *) malloc(pat_len * sizeof(int));
	if (lps == NULL)
	{
		printf("malloc() return NULL\n");
		exit(1);
	}
	getlps(pat, lps);
	t = p = 0;
	for (t = p = 0; t < txt_len && p < pat_len;  )
	{
		if (pat[p] == txt[t])
		{ 
			++p;
			++t;
		}
		else if (p != 0) 
			p = lps[p - 1]; 
		else 
			++t;
	}
	free(lps);
	if (p == pat_len)
		return t - p;
	return -1;
}

