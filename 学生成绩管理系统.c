#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STU sizeof(struct student)
struct clsname
{
    char class1name[20];
	double class1credit; 	
    char class2name[20];
	double class2credit;	 
	char class3name[20];
	double class3credit;	 
	char class4name[20];
	double class4credit;	 
	char class5name[20];
	double class5credit;	  	
}; 

struct grade
{
   double class1;
   double class2;
   double class3;   
   double class4;  
   double class5; 		
}; 

struct student    //ѧ����Ϣ
{
    int id;                 //ѧ��
    char name[20];          //����
    struct clsname cls;   //�γ��� 
    struct grade score;     //�ɼ�
    double gpa;             //ѧ�ּ� 
    int rank;               //���� 
    struct student *next; 
};
void Menu();    //���˵�
void Add();     //����ѧ����Ϣ
void Show();    //��ʾ����ѧ����Ϣ
void Find();    //��ɰ�ѧ�Ų���ѧ����¼������ʾ
void Sort();    //��ѧ����Ϣ��������
void Insert();  //����ѧ����һ����¼����ƽ��ѧ�ּ�����
void Delete();  //ɾ��ѧ����Ϣ 

int stuCnt = 0;   //ѧ������
struct student *head;

int main()
{

        Menu();  //��ʾ�˵� 
		int num;
        scanf("%d",&num);
		while(num<0 || num >6)
        {
            printf("������һ����Чѡ�\n");
            scanf("%d",&num);
        }
		while(num>0 && num<=6)
		{
            switch(num)
            {
                case 1:
                    Add();
                    break;
                case 2:
                    Find();
                    break;
                case 3:
                    Show();
                    break;
                case 4:
                    Insert();
                    break;
                case 5:
                    Sort();
                    break;
                case 6:
                    Delete();
	                break;
		    }
		    Menu(); 
			scanf("%d",&num);
			while(num<0 || num >6)
                {
                    printf("������һ����Чѡ�\n");
                    scanf("%d",&num);
                }		    
		}
	    return 0;
}

void Menu()   //���˵�
{
    printf("*************************************************\n");
    printf("*\t\tѧ���ɼ�����ϵͳ\t\t*\n");
    printf("*************************************************\n");
    printf("*\t\t1.����ѧ����Ϣ\t\t\t*\n");
    printf("*\t\t2.����ѧ����Ϣ\t\t\t*\n");
    printf("*\t\t3.��ʾѧ����Ϣ\t\t\t*\n");
    printf("*\t\t4.����ѧ����Ϣ\t\t\t*\n");
    printf("*\t\t5.����ѧ����Ϣ\t\t\t*\n");
    printf("*\t\t6.ɾ��ѧ����Ϣ\t\t\t*\n");
    printf("*\t\t0.�˳�ϵͳ\t\t\t*\n");
    printf("*************************************************\n");
    printf("��ѡ����:");
}

void Add() 
{
	struct student *p,*p1,*pbefore;
    int i=1,x=1,num=0;
	do
    	{
	    printf("��������ѧ����Ϣ...\n");
	    p1=(struct student *) malloc(STU);
	    if(stuCnt==0)
	        {
	    	printf("����������γ���:\n");
            scanf("%s%s%s%s%s",p1->cls.class1name,p1->cls.class2name,p1->cls.class3name,p1->cls.class4name,p1->cls.class5name);
			printf("����������γ̸���ѧ�ּ�:\n"); 
			scanf("%lf%lf%lf%lf%lf",&p1->cls.class1credit,&p1->cls.class2credit,&p1->cls.class3credit,&p1->cls.class4credit,&p1->cls.class5credit);
	    	}
	    else
	        {
	        strcpy(p1->cls.class1name,head->cls.class1name);
	        strcpy(p1->cls.class2name,head->cls.class2name);
	        strcpy(p1->cls.class3name,head->cls.class3name);
	        strcpy(p1->cls.class4name,head->cls.class4name);
	        strcpy(p1->cls.class5name,head->cls.class5name);
	        p1->cls.class1credit=head->cls.class1credit;
	        p1->cls.class2credit=head->cls.class2credit;
	        p1->cls.class3credit=head->cls.class3credit;
	        p1->cls.class4credit=head->cls.class4credit;
	        p1->cls.class5credit=head->cls.class5credit;      
			}
		printf("�������ѧ����ѧ��:\n");
        scanf("%d",&p1->id);
        printf("�������ѧ��������:\n");
        scanf("%s",p1->name);
		printf("�������ѧ����%s�ɼ�:\n",p1->cls.class1name);
        scanf("%lf",&p1->score.class1);        
        printf("�������ѧ����%s�ɼ�:\n",p1->cls.class2name);
        scanf("%lf",&p1->score.class2);
        printf("�������ѧ����%s�ɼ�:\n",p1->cls.class3name);
        scanf("%lf",&p1->score.class3);
        printf("�������ѧ����%s�ɼ�:\n",p1->cls.class4name);
        scanf("%lf",&p1->score.class4);        
        printf("�������ѧ����%s�ɼ�:\n",p1->cls.class5name);
        scanf("%lf",&p1->score.class5);
	    p1->gpa=(p1->score.class1*p1->cls.class1credit+p1->score.class2*p1->cls.class2credit+p1->score.class3*p1->cls.class3credit+p1->score.class4*p1->cls.class4credit+p1->score.class5*p1->cls.class5credit)/(p1->cls.class1credit+p1->cls.class2credit+p1->cls.class3credit+p1->cls.class4credit+p1->cls.class5credit);
	    p1->next=NULL;
	    if(stuCnt == 0)
            {
			head=p1;
		    stuCnt++;
            }
        else
		    {
            num=0;
            p=head;
			while(p->gpa>p1->gpa)
                {
        	    if(p->next==NULL)
        	        {
				    num=2;
				    break;
					}
				pbefore=p;	
        	    p=p->next;
        	    num=1;
			    }
			if(num==2)
			    {
				p->next=p1;
				}    
            if(num==0)
                {
			    p1->next=p;
			    head=p1;
				}
			if(num==1)
			    {
				p1->next=p;
				pbefore->next=p1;
				}	
	        stuCnt++;
			}
		p=head;
		x=1;
		do                 //�޸����� 
	    	{
		    p->rank=x;
		    p=p->next;
		    x++;
	        }while(p!=NULL);
	    printf("����Ҫ�����������ǣ�1���˳���0��\n");
	    scanf("%d",&i);			
        }while(i==1);
        system("cls");
}

void Show()
{
    int i=1;
	struct student *p;
    if(stuCnt == 0)
    {
        printf("ϵͳ������ѧ����Ϣ����¼��������鿴\n");
    }
    else
    {
        printf("*   ѧ��\t*   ����\t*%-20s*%-20s*%-20s*%-20s*%-20s*ƽ��ѧ�ּ�\n",head->cls.class1name,head->cls.class2name,head->cls.class3name,head->cls.class4name,head->cls.class5name);
        p=head;
        do
            {
            printf("*%-10d\t*%-10s\t*%-20.2lf*%-20.2lf*%-20.2lf*%-20.2lf*%-20.2lf*%-8.2lf\n",p->id,p->name,p->score.class1,p->score.class2,p->score.class3,p->score.class4,p->score.class5,p->gpa);
            p=p->next;
            }while(p!=NULL);
    }
	do
    	{
		printf("�˳���0��\n");
	    scanf("%d",&i);
	    }while(i==1);
	system("cls");	
}

void Find()
{
	int i=-1;
	struct student *p;
	if(stuCnt == 0)
    {
        printf("ϵͳ������ѧ����Ϣ����¼�������\n");
    }
    else
    {
        printf("�����������ѧ��ѧ��\n");
		scanf("%d",&i);
		p=head;
	    do
            {
            if(p->id==i)
			{
			printf("*   ѧ��\t*   ����\t*%-20s*%-20s*%-20s*%-20s*%-20s*ƽ��ѧ�ּ�\n",p->cls.class1name,p->cls.class2name,p->cls.class3name,p->cls.class4name,p->cls.class5name);
			printf("*%-10d\t*%-10s\t*%-20.2lf*%-20.2lf*%-20.2lf*%-20.2lf*%-20.2lf*%-8.2lf\n",p->id,p->name,p->score.class1,p->score.class2,p->score.class3,p->score.class4,p->score.class5,p->gpa);
			break;
			}
            p=p->next;
            }while(p!=NULL);
    	if(p==NULL)
    	printf("û���ҵ�ѧ��");
    	
	}
	do
    	{
		printf("�˳���0��\n");
	    scanf("%d",&i);
	    }while(i==1);
	system("cls");
}

void Sort()
{
    int i=1;
	struct student *p;
    if(stuCnt == 0)
    {
        printf("ϵͳ������ѧ����Ϣ����¼��������鿴\n");
    }
    else
    {
        p=head;        
		printf("*   ѧ��\t*   ����\t*%-20s*%-20s*%-20s*%-20s*%-20s*ƽ��ѧ�ּ�\t*����\t*\n",p->cls.class1name,p->cls.class2name,p->cls.class3name,p->cls.class4name,p->cls.class5name);
        do
            {
            printf("*%-10d\t*%-10s\t*%-20.2lf*%-20.2lf*%-20.2lf*%-20.2lf*%-20.2lf*%-5.2lf\t\t*%-4d\t*\n",p->id,p->name,p->score.class1,p->score.class2,p->score.class3,p->score.class4,p->score.class5,p->gpa,p->rank);
            p=p->next;
            }while(p!=NULL);
    }
	do
    	{
		printf("�˳���0��\n");
	    scanf("%d",&i);
	    }while(i==1);
	system("cls");	
}

void Insert()
{
	struct student *p,*p1,*pbefore;
    int x=1,i=1,num=0;
	if(stuCnt == 0)
        {
        printf("ϵͳ������ѧ����Ϣ����¼�������\n");
        }
    else
	    {
		printf("���ڲ���ѧ����Ϣ...\n");
	    p1=(struct student *) malloc(STU);
	    strcpy(p1->cls.class1name,head->cls.class1name);
	    strcpy(p1->cls.class2name,head->cls.class2name);
	    strcpy(p1->cls.class3name,head->cls.class3name);
	    strcpy(p1->cls.class4name,head->cls.class4name);
	    strcpy(p1->cls.class5name,head->cls.class5name);
	    p1->cls.class1credit=head->cls.class1credit;
	    p1->cls.class2credit=head->cls.class2credit;
	    p1->cls.class3credit=head->cls.class3credit;
	    p1->cls.class4credit=head->cls.class4credit;
	    p1->cls.class5credit=head->cls.class5credit;	    
	    printf("�������ѧ����ѧ��:\n");
        scanf("%d",&p1->id);
        printf("�������ѧ��������:\n");
        scanf("%s",p1->name);
		printf("�������ѧ����%s�ɼ�:\n",p1->cls.class1name);
        scanf("%lf",&p1->score.class1);        
        printf("�������ѧ����%s�ɼ�:\n",p1->cls.class2name);
        scanf("%lf",&p1->score.class2);
        printf("�������ѧ����%s�ɼ�:\n",p1->cls.class3name);
        scanf("%lf",&p1->score.class3);
        printf("�������ѧ����%s�ɼ�:\n",p1->cls.class4name);
        scanf("%lf",&p1->score.class4);        
        printf("�������ѧ����%s�ɼ�:\n",p1->cls.class5name);
        scanf("%lf",&p1->score.class5);
	    p1->gpa=(p1->score.class1*p1->cls.class1credit+p1->score.class2*p1->cls.class2credit+p1->score.class3*p1->cls.class3credit+p1->score.class4*p1->cls.class4credit+p1->score.class5*p1->cls.class5credit)/(p1->cls.class1credit+p1->cls.class2credit+p1->cls.class3credit+p1->cls.class4credit+p1->cls.class5credit);
		p1->next=NULL;
	    num=0;
            p=head;
			while(p->gpa>p1->gpa)
                {
        	    if(p->next==NULL)
        	        {
				    num=2;
				    break;
					}
				pbefore=p;	
        	    p=p->next;
        	    num=1;
			    }
			if(num==2)
			    {
				p->next=p1;
				}    
            if(num==0)
                {
			    p1->next=p;
			    head=p1;
				}
			if(num==1)
			    {
				p1->next=p;
				pbefore->next=p1;
				}	
	        stuCnt++;
	    
		p=head;
		do                 //�޸����� 
	    	{
		    p->rank=x;
		    p=p->next;
		    x++;
	    }while(p!=NULL);
    }
	do
        {
	   	printf("�˳���0��\n");
	    scanf("%d",&i);
	    }while(i==1);
    system("cls");		    
}

void Delete()
{
	int i=-1,x=1,flag=0;
	struct student *p,*p1;
	if(stuCnt == 0)
    {
        printf("ϵͳ������ѧ����Ϣ����¼�������\n");
    }
    else
    {
        printf("������Ҫɾ����ѧ��ѧ��:\n");
		scanf("%d",&i);
		p=head;
	    do
            {
            if(p->id==i)
			    {
					flag=1;
                    stuCnt--;
                	printf("��ɾ��ѧ������\n");
                    if(stuCnt==0)
                        {
                    	free(p);
                    	break;
					    }
					if(p==head)
                        {
                        head=p->next;
                        free(p);
						break;
						}
                    else 
                        {
                        p1->next=p->next;
					    free(p);	
					    }    
			    break;
			    }
		    p1=p;    
            p=p->next;    
            }while(p!=NULL);
    	if(flag==0)           
    	printf("û���ҵ�ѧ��\n");	
	}
    p=head;
	do                 //�޸����� 
	    {
	    p->rank=x;
	    p=p->next;
	    x++;
	    }while(p!=NULL);
	x=1;		
	do
    	{
		printf("�˳���0��\n");
	    scanf("%d",&x);
	    }while(x==1);
	system("cls");			
}
