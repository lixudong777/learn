#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h> //memcpy()
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>

#ifndef _HEAD_H
#define _HEAD_H

/* define PRN_... 6 */
#define PRN_VAL(val, type) 	printf("(variable) "#val":\t%"#type"\n", val)
#define PRN_VAR(val, type) 	printf("(variable) "#val":\t%"#type"\n", val)
#define PRN_FUN(fun, type) 	printf("(function) "#fun":\t%"#type"\n", fun)
#define PRN_CAL(fun)		printf("(function) "#fun"\n");fun
#define PRN_SEN(sen)		printf("(sentence) "#sen";\n");sen
#define PRN_STR(str)		printf(#str"\n")
#define PRN_PRN				printf

#define OK_STR "---OK---\n"
#define ERR_STR "---Err---\n"

/* type */
#define Ispace Isspace  	/* same */
int Isspace(int c);
int Isdigit(int c);
int Isupper(int c);
int Islower(int c);
int Isalpha(int c);
int Isalnum(int c);
int Toupper(int c);
int Tolower(int c);

/* string */
size_t Strlen(const char *dest);
char *Strcpy(char *dest, const char *src);
char *Strncpy(char *dest, const char *src, size_t n);
char *Strcat(char *dest, const char *src);
char *Strncat(char *dest, const char *src, size_t n);
int Strcmp(const char *s, const char *t);
int Strncmp(const char *s, const char *t, size_t n);
char *Strstr(const char *dest, const char *sub);
size_t Strindex(const char *dest, const char *sub);
char *Strchr(const char *dest, char chr);
char *Strrchr(const char *dest, char chr);
size_t Strspn(const char *dest, const char *pre);
size_t Strcspn(const char *dest, const char *npre);
char *Strpbrk(const char *dest, const char *npre);
char *Strrev(char *dest);
char *Strtrim(char *dest);
char *Strsqz(char *dest, char c);
char *Strdup(const char *dest);
char *Strtoup(char *dest);
char *Strtolow(char *dest);
char *Strsqzs(char *dest, const char *s);


/* convert */
int Atoi(const char *s);
double Atof(const char *s);
char *Itoa(int n, char *dest);


/* word */
int Getline(FILE *fp, char *dest, int lim);
int Getword(FILE *fp, char *dest, int lim);
int Strsearch(const char *s, char *v[], int n);

/* tree */

/* mem */
union header_union
{
	struct
	{
		union header_union *next;
		unsigned size;
	} s;
	long never_use;
};
typedef union header_union header;

header mem_base;
header *mem_freep;
#define NALLOC 10

static header *mem_more(unsigned nu);
void *sbrk (long nu) ;
//void *sbrk(int n);
void *mem_alloc(unsigned nbytes);
void mem_free(void *ap);
#endif   /* #ifndef HEAD_H */

