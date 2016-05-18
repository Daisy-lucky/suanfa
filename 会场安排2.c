#include <stdio.h>

typedef struct 
{
	int time;
	int judge;
}list;

int a[200];
list b[200];
int n;
void duqu()//从文本中读取时间 
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
  		if ( fscanf( fp , "%d" ,&a[i] ) !=1 )
   	 	break ;
  		i++;
  		fgetc(fp) ;//过滤掉分隔符
	}
 	fclose(fp);
	n=i;
	printf("i=%d\n" , i );
 	while( --i >= 0 )
 	{
  		printf("%d," , a[i] );
  		if ( i %10 == 0 )
   		printf("\n") ;
 	}

}
void cunchu()//将读取的时间信息存储进结构体数组中 
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i%2==0)
		{
			b[i].time=a[i];
			b[i].judge=1;
		}
		else
		{
			b[i].time=a[i];
			b[i].judge=-1;
		}
	}
}

void paixu()//对结构体数组中的时间进行排序 
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j+i<n-2;j++)
		{
			if(b[j].time>b[j+1].time)
			{
				int p,q;
				p=b[j].time;
				q=b[j].judge;
				b[j].time=b[j+1].time;
				b[j].judge=b[j+1].judge;
				b[j+1].time=p;
				b[j+1].judge=q;
			
			}
		}	
	}	
}

int tongji()//统计出的会场个数 
{
	int i=0;
	int num=0;
	int c[200];
	for(;i<n;i++)
	{
		num=num+b[i].judge;
		c[i]=num;
	}
	int x=0;
	for(i=0;i<n;i++)
	{
		if(c[i]>x)
		{
			x=c[i];
		}
	}
	return x;
}

int main()
{
	duqu();
	cunchu();
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d %d",b[i].time,b[i].judge);
		printf("\n");
	}
	paixu();
	printf("-----------------------------\n");
	for(i=0;i<n;i++)
	{
		printf("%d %d",b[i].time,b[i].judge);
		printf("\n");
	}
	printf("-------------------------------\n");
	int x=tongji();
	printf("需要的会场个数为%d",x);
}
