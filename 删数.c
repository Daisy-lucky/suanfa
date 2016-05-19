#include <stdio.h>
//删数问题
// 即按高位到低位的顺序搜索，若各位数字递增，则删除最后一个数字；否则删除第一个递减区间的首字符，这样删一位便形成了一个新的数字串。然后回到串首，按上述规则再删除下一个数字
int a[200],n;
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

int weizhi()
{
	int i=0;
	while(1)
	{
		if(a[i]<a[i+1])
		{
			i++;
		}
		else
		{
			return i;
		}
	}	
}

void shanshu()
{
	int t=weizhi();
	n=n-1;
	for(;t<n;t++)
	{
		a[t]=a[t+1];
	 } 
}
main()
{
	duqu();
	printf("删除几位数");
	int i;
	scanf("%d",&i);
	for(;i>0;i--)
	{
		shanshu();
	 } 
	 for(i=0;i<n;i++)
	 {
	 	printf("%d",a[i]);
	 }
}
