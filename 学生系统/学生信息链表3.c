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
void menu()  //菜单显示 
{
	printf("--------菜单---------\n");
	printf("-------0.退出-------\n");
	printf("-------1.录入--------\n");
	printf("-------2.浏览--------\n");
	printf("-------3.查找--------\n");
    printf("-------4.修改--------\n"); 
    printf("-------5.删除--------\n");
}
struct node* Initialist ()  //创建一个头节点 
{
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head->next = NULL;
	return head;
}
void insertlist(struct node* head,struct student arry[],int n)  //将结构体数组插入头结点后面 
{   
    int i=0;
	struct node* pr = head;  //定义一个前驱指针 
	struct node* su ;        //定义一个后继指针 
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
void printlist(struct node* head)  //输出学生信息 
{
	struct node* pmove = head->next;
	while(pmove!=NULL)
	{
		printf("姓名：%s\t学号：%s\t分数：%d\n",pmove->data.name,pmove->data.num,pmove->data.score);
		pmove = pmove->next;
	}
}

int main()
{    int n,i;
	system("color 0E"); 
    int choice=1;
	while(choice){	
		menu(); 
		printf("输入选项(0-5)：");
		scanf("%d",&choice);
		struct node* head = Initialist();  //链表的初始化，建立一个头结点 
	    struct student xuesheng[100];
		switch(choice)
		{ case 0: printf("退出程序\n");
		          exit(0); 
				  break; //退出程序 
		  case 1: printf("读入学生信息\n");
		         
                    printf("请输入学生的人数:");
                          scanf("%d",&n);
                                printf("请输入学生的相关信息：姓名\t学号\t分数\n");
                                       for(i=0;i<n;i++)
                                   {
    	                            scanf("%s%s%d",xuesheng[i].name,xuesheng[i].num,&xuesheng[i].score);
                                   	}        //先定义一个结构体数组储存学生信息 
                                   
									 insertlist(head,xuesheng,n);      //将结构体中的数据插入到链表中 
									 break;
          case 2:  printf("浏览学生信息：\n");
                   printlist(head);
                   
                   break;
		  								 
                                   	
			default:
				printf("重新输入");	
		}
		system("pause");
		
		system("cls");
		
		
	}

	
	
	return 0;
}

