#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FSTART;

	int *arr[MAX_ELEMENTS+1]={};
	int **tmp,**tmp2;

	int quit=0;

	print_help();

	do
	{
		switch(menu())
		{
			case INVALID:
			{
				error("invalid input!\n");
			}
			break;
			case ADD_VALUE:
			{
				int i;
				if(!read_value(&i))
				{
					list_add(arr,i);
				}
				else
				{
					error("invalid input!\n");
				}
			}
			break;
			case PRINT_ORIGINAL:
			{
				for(tmp=arr;*tmp;tmp++)
				{
					printf("%d\n",**tmp);
				}
			}
			break;
			case PRINT_ASCENDING:
			{
				tmp2=list_copy(arr);
				list_sort(tmp2);
				for(tmp=tmp2;*tmp;tmp++)
				{
					printf("%d\n",**tmp);
				}
				free(tmp2);
			}
			break;
			case PRINT_MODAL:
			{
				tmp2=list_copy(arr);
				list_sort(tmp2);
				if(!*tmp2)
				{
					error("not enough elements");
					break;
				}
				int bestc=0,besti=0;
				int nowc=1,nowi=**tmp2;
				int inval=0;
				for(tmp=tmp2;*tmp;tmp++)
				{
					if(**tmp==nowi)
					{
						nowc++;
					}
					if(**tmp!=nowi)
					{
						if(nowc>bestc)
						{
							besti=nowi;
							bestc=nowc;
						}
						if(nowc==bestc)
						{
							inval=1;
						}
						nowi=**tmp;
						nowc=1;
					}
				}
				if(inval)
				{
					printf("none\n");
				}
				else
				{
					printf("%d\n",besti);
				}
				free(tmp2);
			}
			break;
			case PRINT_MEDIAN:
			{
				tmp=list_copy(arr);
				list_sort(tmp);
				if(!*tmp)
				{
					error("not enough elements");
					break;
				}
				int c=list_count(tmp);
				printf("%lf\n",c%2?(double)*tmp[(c)/2]:(*tmp[c/2-1]+*tmp[c/2])/2.0);
				free(tmp);
			}
			break;
			case PRINT_MEAN:
			{
				if(!*arr)
				{
					error("not enough elements");
					break;
				}
				double v=**arr;
				int i=1;
				for(tmp=arr+1;*tmp;tmp++)
				{
					v+=**tmp;
					i++;
				}
				printf("mean: %lf\n",v/i);
			}
			break;
			case PRINT_SPAN:
			{
				tmp=list_copy(arr);
				list_sort(tmp);
				if(!tmp[1])
				{
					error("not enough elements");
					break;
				}
				printf("span: %d\n",*tmp[list_count(tmp)-1]-**tmp);
				free(tmp);
			}
			break;
			case DEL_ALL:
			{
				for(tmp=arr;*tmp;tmp++)
				{
					free(*tmp);
					*tmp=0;
				}
			}
			break;
			case EXIT:
			{
				quit = 1;
			}
			break;
			default:
			{
				print_help();
			}
			break;
		}
	}while(!quit);

	for(tmp=arr;*tmp;tmp++)
	{
		free(*tmp);
	}

	FEND;
	return 0;
}

