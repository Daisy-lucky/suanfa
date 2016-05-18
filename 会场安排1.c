#include <stdio.h>

int x[200],n;
typedef struct 
{
	int a;//开始时间 
	int b;//结束时间 
	int c;// 状态 
}list;


void duqu()
{
	FILE *fp=NULL;

 	int i=0;
 	fp=fopen("data.txt","r");
 	if ( !fp )
	{
		printf("文件打开出错\n");

	}
 	while( !feof(fp) )
 	{
  		if ( fscanf( fp , "%d" ,&x[i] ) !=1 )
   	 	break ;
  		i++;
  		fgetc(fp) ;//过滤掉分隔符
	}
 	fclose(fp);
	n=i;
	printf("i=%d\n" , i );
 	while( --i >= 0 )
 	{
  		printf("%d," , x[i] );
  		if ( i %10 == 0 )
   		printf("\n") ;
 	}

 } 
 
 void cunchu(list arr[])
 {
 	int i;
 	for(i=0;i<n;i++)
 	{
		if(i%2==0)
		{
			arr[i/2].a=x[i];
	
			arr[i/2].b=x[i+1];
			arr[i/2].c=0;
	
		}
 	}
 }
 
void paixu(list arr[])
{
	int i,j;
	for(i=0;i<n/2;i++)
	{
		for(j=0;i+j<n/2-1;j++)
		{
			if(arr[j].b>arr[j+1].b)
			{
				int p,q;
				p=arr[j].a;
				q=arr[j].b;
				arr[j].a=arr[j+1].a;
				arr[j].b=arr[j+1].b;
				arr[j+1].a=p;
				arr[j+1].b=q;
			}
		}
	}
}

void huichang(list arr[])
{

	int i,j;
	for(i=0;i<n/2;i++)//查找出未安排的第一个活动 
	{
		if(arr[i].c==0)
		{
			arr[i].c=1;
			break;
		}
	}
	j=i+1;
	for(;j<n/2;j++)//找出后续 
	{
		if(arr[j].c==0&&arr[j].a>arr[i].b)
		{
			arr[j].c=1;
			i=j;
		}
	}
}

int changci(list arr[])
{
	int i,num=1,x=0;//num为未安排的活动，x为需要几个会场 
	while(num!=0)//当所有未安排的活动为零时停止 
	{
		huichang(arr);
		num=0;
		for(i=0;i<n/2;i++)
		{
			if(arr[i].c==0)
			{
				num++;
			}
		}
		x=x+1;
	}
	return x;
}

 main()
 {
 	int i;
 	list arr[200];
 	duqu();
 	cunchu(arr);
 	printf("-----------------------\n");
 	paixu(arr);
 	for(i=0;i<n/2;i++)
 	{
 		printf("%d   %d\n",arr[i].a,arr[i].b);
	 }
	int x=changci(arr);
	printf("%d",x);
 }
