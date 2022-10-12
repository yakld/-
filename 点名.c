#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<pthread.h>
#define MAX 100
typedef struct StuInfo
{
	int id;
	char name[100];
    int list[21];
}StuInfo;
void stu_open(char* file, FILE* fp,StuInfo* s,int num)
{
	int i = 0;
	int j;
	for (i = 0; i < num; i++)
	{
        s[i].list[0]=0;
        fscanf(fp,"%09d %s", &(s[i].id), s[i].name);
        for(j=1;j<21;j++)
        {
        	fscanf(fp,"%d",&(s[i].list[j]));
		}
	}
	return;
}
void stu_close(char* file, FILE* fp)
{
	fclose(fp);
	fp = NULL;
}
void stu_byname(StuInfo* s,int num)
{
    FILE* fp = fopen("D:\\linux\\order.txt", "w+");
	char buf[MAX];
	int count;
	int i,j;
	for(count=j=1;j<21;j++,count=j)
	{
		printf("第%d次点名",j);
		fprintf(fp,"第%d次点名",j);
		for(i=0;i<num;i++)
		{
			if(s[i].list[count-1]==0)
			{
				fprintf(fp," %09d%s",s[i].id,s[i].name);
				printf("  %09d%s",s[i].id,s[i].name);
			}
		}
		printf("\n");
		fprintf(fp,"\n");
	}
}
int main()
{
	StuInfo s[91];
	int num = 90;
	char file[32];
	printf("请输入学生名单\n");
	scanf("%s", &file);
	FILE* fp;
	fp = fopen(file, "r+");
	if (fp == NULL)
	{
		printf("Open Failed: % s\n", strerror(errno));
		return;
	}
	stu_open(file,fp,s,num);
	stu_close(file,fp);
	stu_byname(s,num);
    return 0;
}
