#include <stdio.h>
//ɾ������
// ������λ����λ��˳������������λ���ֵ�������ɾ�����һ�����֣�����ɾ����һ���ݼ���������ַ�������ɾһλ���γ���һ���µ����ִ���Ȼ��ص����ף�������������ɾ����һ������
int a[200],n;
void duqu()//���ı��ж�ȡʱ�� 
{
 FILE *fp=NULL;

 	int i=0;
 	fp=fopen("data.txt","r");
 	if ( !fp )
	{
		printf("�ļ��򿪳���\n");

	}
 	while( !feof(fp) )
 	{
  		if ( fscanf( fp , "%d" ,&a[i] ) !=1 )
   	 	break ;
  		i++;
  		fgetc(fp) ;//���˵��ָ���
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
	printf("ɾ����λ��");
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
