#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qsort_cmp(const void *av,const void *bv)
{
	FSTART;
	int *a=*(int **)av;
	int *b=*(int **)bv;
	FEND;
    return a==b?0:a==0?1:b==0?-1:*a-*b;
}

void list_sort(int **f)
{
	FSTART;
	qsort(f,list_count(f),sizeof(int *),qsort_cmp);
	FEND;
}

int **list_copy(int **f)
{
	FSTART;
	int **c=malloc((MAX_ELEMENTS+1)*sizeof(int *));
	memcpy(c,f,(MAX_ELEMENTS+1)*sizeof(int *));
	FEND;
	return c;
}

int list_count(int **f)
{
	FSTART;
	int i;
	for(i=0;*f;i++)
	{
		f++;
	}
	FEND;
	return i;
}

int list_add(int **f,int val)
{
	FSTART;
	int i;
	for(i=0;*f&&i<MAX_ELEMENTS;i++)
	{
		f++;
	}
	if(i>=MAX_ELEMENTS)
	{
		return 1;
	}
	*f=malloc(sizeof(int));
	**f=val;
	FEND;
	return 0;
}

int read_value(int *ptr)
{
	FSTART;
    char ch;
    static char buf[0x1000];
    *buf = 0;

    fgets(buf,sizeof(buf),stdin);

	FEND;
    return sscanf(buf,"%d%c",ptr,&ch)!=2;
}

menu_t menu(void)
{
	FSTART;
    char buf[4]= {};
    printf("> ");
    fgets(buf,sizeof(buf),stdin);

    if (buf[2]==0)
	{
		switch(*buf)
		{
			case 'n':
				FEND;
				return ADD_VALUE;
			case 'd':
				FEND;
				return DEL_ALL;
			case 's':
				FEND;
				return PRINT_ORIGINAL;
			case 'o':
				FEND;
				return PRINT_ASCENDING;
			case 'm':
				FEND;
				return PRINT_MEAN;
			case '?':
				FEND;
				return PRINT_HELP;
			case 'q':
				FEND;
				return EXIT;
		}
    }
	else
	{
		if(buf[3]==0)
		{
			if(buf[0]=='s'&&buf[1]=='p')
			{
				FEND;
				return PRINT_SPAN;
			}
			if(buf[0]=='m'&&buf[1]=='e')
			{
				FEND;
				return PRINT_MEDIAN;
			}
			if(buf[0]=='m'&&buf[1]=='o')
			{
				FEND;
				return PRINT_MODAL;
			}
		}
	}

	FEND;
	return INVALID;
}

void print_help(void)
{
	FSTART;
    puts(
        "n   add a new value\n"
		"d   delete all values\n"
        "s   print original\n"
        "o   prints the list in ascending order\n"
        "mo  prints the modal value of the list\n"
        "me  prints the median value of the list\n"
        "m   prints the mean value of the list\n"
        "sp  prints the difference of the first and the last value\n"
        "?   prints this help screen\n"
        "q   exit the program\n"
    );
	FEND;
}

