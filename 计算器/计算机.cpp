#include<stdio.h>
#define N 3
void add();
void subt();
void mult();
void divid();
void chengjie();
main(void)
{
	printf("1.�ӷ�\n"); 
	printf("2.����\n");
	printf("3.�˷�\n");
	printf("4.����\n");
	printf("5.!");
	while(1)
	{
	int i;
	printf("������1-5\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:add();
		break;
		case 2:subt();
		break;
		case 3:mult();
		break;
		case 4:divid();
		break;
		case 5:chengjie();
		break;
		default:printf("����");
	}
	}
} 
void add()
{
	int a[N],b,c=0;
	for(b=0;b<N;b++)
	scanf("%d",&a[b]);
	for(b=0;b<N;b++)
	c+=a[b];
	printf("%d",c);
}
void subt()
{
	int a[N],b,c=0,z=0;
	for(b=0;b<N;b++)
	scanf("%d",&a[b]);
	c=a[0];
	for(b=0;b<N-1;b++)
	c=c-a[b+1];
	printf("%d",c);
}
void mult()
{
	int a[N],b,c=0;
	for(b=0;b<N;b++)
	scanf("%d",&a[b]);
	c=a[0];
	for(b=0;b<N-1;b++)
	c=c*a[b+1];
	printf("%d",c);
}
void divid()
{
	int a[N],b,c=0;
	for(b=0;b<N;b++)
	scanf("%d",&a[b]);
	c=a[0];
	for(b=0;b<N-1;b++)
	c=c/a[b+1];
	printf("%d",c);
}
void chengjie()
{
	int a,b,c=1;
	printf("������һ����Ҫ�Ľ׳�"); 
	scanf("%d",&b);
	for(a=1;a<=b;a++)
	c*=a;
	printf("%d",c);	
}