#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>
#define MAX 100
void stu_close(FILE* fp)
{
	fclose(fp);
	fp = NULL;
}
void stu_byname(FILE* fp,int num)
{
	char name[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int i,j,k,ret,count;
	srand((unsigned int)time(NULL));
	fp = fopen("D:\\linux\\student.txt", "w+");
		for(i=0;i<num;i++)
		{
            
                ret = rand();
                ret=ret%1000000000;
                printf("%09d ",ret);
				fprintf(fp,"%09d ",ret);
            for(k=0;k<3;k++)
            {
                ret = rand();
                ret=ret%2;
                printf("%c",name[ret]);
                fprintf(fp,"%c",name[ret]);
            }
			for(j=0;j<20;j++)
            {
                ret = rand()%2;
                printf(" %d",ret); 
				fprintf(fp," %d",ret);       
			}
			fprintf(fp,"\n");
			printf("\n");
		}
		
}
int main()
{
	int num = 90;
	char file[32];
	scanf("%s", &file);
	FILE* fp;
	fp = fopen("D:\\linux\\student.txt", "w+");
	if (fp == NULL)
	{
		printf("Open Failed: % s\n", strerror(errno));
		return;
	}
	stu_byname(fp,num);
	stu_close(fp);
    return 0;
}
