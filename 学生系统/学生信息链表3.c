#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
 struct student
{
	char name[11];
	char num[11];
	int score;
};
 struct node
{
	struct student data;
	struct node* next;
};
void menu()  //�˵���ʾ 
{
	printf("--------�˵�---------\n");
	printf("-------0.�˳�-------\n");
	printf("-------1.¼��--------\n");
	printf("-------2.���--------\n");
	printf("-------3.����--------\n");
    printf("-------4.�޸�--------\n"); 
    printf("-------5.ɾ��--------\n");
}
struct node* Initialist ()  //����һ��ͷ�ڵ� 
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;
	return head;
}
void insertlist(struct node* head,struct student arry[],int n)  //���ṹ���������ͷ������ 
{   
    int i=0;
	struct node* pr = head;  //����һ��ǰ��ָ�� 
	struct node* su ;        //����һ�����ָ�� 
	while(i<n)
	{
		su = (struct node*)malloc(sizeof(struct node));
		su->data = arry[i];
		su->next = pr->next;
		pr->next = su;
		pr = su;
		i++;
	}
	pr->next = NULL;
}
void printlist(struct node* head)  //���ѧ����Ϣ 
{
	struct node* pmove = head->next;
	while(pmove!=NULL)
	{
		printf("������%s\tѧ�ţ�%s\t������%d\n",pmove->data.name,pmove->data.num,pmove->data.score);
		pmove = pmove->next;
	}
}

int main()
{    int n,i;
	system("color 0E"); 
    int choice=1;
	while(choice){	
		menu(); 
		printf("����ѡ��(0-5)��");
		scanf("%d",&choice);
		struct node* head = Initialist();  //����ĳ�ʼ��������һ��ͷ��� 
	    struct student xuesheng[100];
		switch(choice)
		{ case 0: printf("�˳�����\n");
		          exit(0); 
				  break; //�˳����� 
		  case 1: printf("����ѧ����Ϣ\n");
		         
                    printf("������ѧ��������:");
                          scanf("%d",&n);
                                printf("������ѧ���������Ϣ������\tѧ��\t����\n");
                                       for(i=0;i<n;i++)
                                   {
    	                            scanf("%s%s%d",xuesheng[i].name,xuesheng[i].num,&xuesheng[i].score);
                                   	}        //�ȶ���һ���ṹ�����鴢��ѧ����Ϣ 
                                   
									 insertlist(head,xuesheng,n);      //���ṹ���е����ݲ��뵽������ 
									 break;
          case 2:  printf("���ѧ����Ϣ��\n");
                   printlist(head);
                   
                   break;
		  								 
                                   	
			default:
				printf("��������");	
		}
		system("pause");
		
		system("cls");
		
		
	}

	
	
	return 0;
}

