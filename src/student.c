/*  ��Ŀ������C���Ե�ѧ������ϵͳ�������ļ���
	���ߣ�Microsoft Visual C++ 2010 ѧϰ��
	�����ˣ���곽��
	ʱ�䣺2020.1.16-2020.2.2 �����깤
	      2020.4.15-2020.6.25 һ���Ż�
		  2020.7.25-2020.7.30 �����Ż�
	ϰ�ã�C���Ե������Ĵ�������ӡ�����ң�ɾ���������ļ����������������
		  ����ģ�黯������Ի��������ա�
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"

#ifdef _WIN32
#include <windows.h>
#define SET_CONSOLE_TITLE(title) SetConsoleTitleA(title)
#define SET_CONSOLE_COLOR(color) system(color)
#else
#include <unistd.h>
#define SET_CONSOLE_TITLE(title) printf("\033]0;%s\007", title)
#define SET_CONSOLE_COLOR(color) system(color)
#endif

struct Node *List=NULL;//���������ڵ�


void menu();//������
void function();//���ܽ���
void login();//��¼����
void login_Second();//��¼�ֽ���
void rebackPassword();//�һ�����
void addStudent(struct student tempData);//����ѧ����Ϣ
void searchStudent(struct student tempData);//����ѧ����Ϣ
void modifyStudent(struct student tempData);//�޸�ѧ����Ϣ
void modifyStudent_Second(struct student tempData);//�޸�ѧ����Ϣ���ܵĲ��ִ���
void deleteStudent(struct student tempData);//ɾ��ѧ����Ϣ
void sortStudent();//����ѧ����Ϣ


//������
int main()
{
	SET_CONSOLE_TITLE("学生信息管理系统");
	SET_CONSOLE_COLOR("color F0");
	system("mode con cols=90 lines=30");

	//����һ���������洢ѧ����Ϣ
	List=creatList();

	//��ȡstudent.txt�ļ���Ϣ��������
    //student.txt���ڴ�������е�ѧ����Ϣ
	readFromFile("student.txt",List);
	//����������
	menu();

	return 0;
}
//������
void menu()
{
	printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t|\t��ӭ������ǧѧ������ϵͳ\t|\n");
    printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t|\t1.��½\t\t\t\t|\n");
    printf("\t\t\t|\t2.�һ�����\t\t\t|\n");
    printf("\t\t\t|\t3.�˳�ϵͳ\t\t\t|\n");
    printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t��ѡ����(1-3)(���س���ȷ��):");

	//��ȡѡ��
	int choice = 0;
	scanf("%d",&choice);

	//���������
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)//�ж�ѡ��
	{
	case 1:
		{
			system("cls");//ˢ�½���
			login();//����login()�������е�¼
			break;
		}
	case 2:
		{
			system("cls");
			rebackPassword();//����rebackPassword()�����һ�����
			break;
		}
	case 3:
		{
			printf("\n\t\t\t");
			exit(0);//�˳�ϵͳ
		}
	default:
		{
			//�����벻��ָ��ѡ��ʱ
			printf("\n\t\t\t����������������룡\n\t\t\t");
			system("pause");//��ͣ����
			system("cls");//ˢ�½���

			menu();//���µ��ñ�����
			break;
		}
	}
}
//��¼����
void login()
{
	int i = 0;
	char Password[]="123";//��¼����
	char tempPass[10]="0";//������˻�ȡ������

	printf("\t\t\t---------------��½ϵͳ---------------\n\n");
	printf("\t\t\t\t����Ա�˺�:��ǧ\n");
	for(i=1;i<=3;i++)
	{
		printf("\t\t\t\t����Ա����:");
		//��ȡ�������������
		scanf("%s",tempPass);

		//���������
		char ch;
		while((ch = getchar()) != '\n' && ch != EOF);

		//�жϵ�¼����ͻ�ȡ�������Ƿ���ͬ
        //strcmp()�����ַ����Ƚϣ����ַ�����ͬʱ����0
		if(!strcmp(Password,tempPass))
		{
			printf("\n\t\t\t\t��½�ɹ�!");
			printf("\n\t\t\t\t");
			system("pause");//������ͣ
			system("cls");//ˢ�½���
			function();//����fuction()�������빦�ܽ���
		}else
		{
			//�������ﵽ����
			if(3 == i)
			{
				printf("\n\t\t\t\t�����������3��!������ѡ��\n\n");
				printf("\t\t\t\t");
				system("pause");
			}else
			{
				printf("\n\t\t\t\t�����������%d��!����������!\n",i);
			}
		}
	}
	if(4 == i)
	{
		system("cls");
		//��¼����ʧ�ܺ�����¼�ֽ���
		login_Second();
	}
}
//��¼�ֽ��棬�������������󳬹����κ�
void login_Second()
{
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\t|\t    1.�һ�����\t\t    |\n");
	printf("\t\t\t|\t    2.���µ�¼\t\t    |\n");
	printf("\t\t\t|\t    3.�˳�ϵͳ\t\t    |\n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\t\t   ��ѡ��(1-3)��");

	//��ȡѡ��
	int choice = 0;
	scanf("%d",&choice);

	//���������
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);
	switch(choice)
	{
	case 1:
		{
			system("cls");//ˢ�½���
			rebackPassword();//����rebackPassword()�����һ�����
			break;
		}
	case 2:
		{
			system("cls");
			login();//����login()�������е�¼
			break;
		}
	case 3:
		{
			printf("\n\t\t\t\t");
			exit(0);//�˳�ϵͳ
		}
	default:
		{
			printf("\n\t\t\t\t����������������룡\n\t\t\t\t");
			system("pause");//��ͣ����
			system("cls");//ˢ�½���

			login_Second();//���µ��ñ�����
			break;
		}
	}
}
//�һ�����
void rebackPassword()
{
	int question_one=0;
	int question_two=0;
	int question_three=0;

	printf("\t\t\t    ------------�һ�����------------\n\n");
	printf("\t\t\t\t    �������ܱ����⣺");
	printf("\n\t\t\t\t    1.��Сʱ����������?");
	printf("\n\t\t\t\t      ��:");

	scanf("%d",&question_one);//��ȡ�ܱ�һ��
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);//���������

	printf("\n\t\t\t\t    2.���δ���������ĸ�?");
	printf("\n\t\t\t\t      ��:");

	scanf("%d",&question_two);//��ȡ�ܱ�����
	while((ch = getchar()) != '\n' && ch != EOF);//���������

	printf("\n\t\t\t\t    3.���Ը����ʲô?");
	printf("\n\t\t\t\t      ��:");

	scanf("%d",&question_three);//��ȡ�ܱ�����
	while((ch = getchar()) != '\n' && ch != EOF);//���������

	if(1 == question_one && 2 == question_two && 3 == question_three)//�ж��ܱ��Ƿ���ȷ
	{
		printf("\n\n\t\t\t\t    ����Ա����:123\n\n\t\t\t\t    ");
		system("pause");//��ͣϵͳ
		system("cls");//ˢ�½���
	}else
	{
		printf("\n\t\t\t\t     �𰸴���\n\n\t\t\t\t    ");
		system("pause");
		system("cls");
	}
	menu();//�������
	
}
//���ܽ���
void function()
{
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\t|\t��ӭʹ����ǧѧ������ϵͳ\t|\n");
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\t|\t1.����ѧ����Ϣ\t\t\t|\n");
    printf("\t\t\t|\t2.ͳ��ѧ����Ϣ\t\t\t|\n");
    printf("\t\t\t|\t3.����ѧ����Ϣ\t\t\t|\n");
    printf("\t\t\t|\t4.�޸�ѧ����Ϣ\t\t\t|\n");
    printf("\t\t\t|\t5.ɾ��ѧ����Ϣ\t\t\t|\n");
    printf("\t\t\t|\t6.����ѧ����Ϣ\t\t\t|\n");
    printf("\t\t\t|\t7.������һ��\t\t\t|\n");
	printf("\t\t\t|\t8.�˳�����\t\t\t|\n");
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\t��ѡ����(1-8):");
	
	//�洢��ʱ����
	struct student tempData={"0","0","0",0,0.0,0.0,0.0};

	//��ȡѡ��
	int choice = 0;
	scanf("%d",&choice);
	//���������
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)
	{
	case 1:
		{
			//����addStudent()��������ѧ����Ϣ
			addStudent(tempData);
			printf("\n\t\t\t\t");
			system("pause");//��ͣ����
			system("cls");//ˢ�½���
			break;
		}
	case 2:
		{
			printf("\n\t\t\t--------------ͳ��ѧ����Ϣ--------------\n");
			//����printList()������ӡ����ѧ����Ϣ
			printList(List);
			printf("\n\t\t\t\t");
			system("pause");
			system("cls");
			break;
		}
	case 3:
		{
			//����searchStudent()��������ѧ����Ϣ
			searchStudent(tempData);
			printf("\n\t\t\t\t");
			system("pause");
			system("cls");
			break;
		}
	case 4:
		{
			//����modifyStudent()�����޸�ѧ����Ϣ
			modifyStudent(tempData);
			printf("\n\t\t\t\t");
			system("pause");
			system("cls");
			break;
		}
	case 5:
		{
			//����deleteStudent()����ɾ��ѧ����Ϣ
			deleteStudent(tempData);
			printf("\n\t\t\t\t");
			system("pause");
			system("cls");
			break;
		}
	case 6:
		{
			//����sortStudent()��������ѧ����Ϣ
			sortStudent();
			printf("\n\t\t\t\t");
			system("pause");
			system("cls");
			break;
		}
	case 7:
		{
			system("cls");
			menu();//����������
			break;
		}
	case 8:
		{
			printf("\n\t\t\t\t");
			exit(0);//�˳�ϵͳ
		}
	default:
		{
			printf("\n\t\t\t\t����������������룡\n");
			printf("\n\t\t\t\t");
			system("pause");//��ͣ����
			system("cls");//ˢ�½���
			break;
		}
	}
	function();//���µ��ñ�����
}
//����ѧ����Ϣ
void addStudent(struct student tempData)
{
	printf("\n\t\t\t--------------����ѧ����Ϣ--------------\n");
	printf("\t\t\t\tѧ�ţ�");
	scanf("%s",tempData.id);//��ȡѧ��ѧ��
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);//���������

	printf("\t\t\t\t������");
	scanf("%s",tempData.name);//��ȡѧ������
	while((ch = getchar()) != '\n' && ch != EOF);

	printf("\t\t\t\t�Ա�");
	scanf("%s",tempData.gender);//��ȡѧ���Ա�
	while((ch = getchar()) != '\n' && ch != EOF);

	printf("\t\t\t\t���䣺");
	scanf("%d",&tempData.age);//��ȡѧ������
	while((ch = getchar()) != '\n' && ch != EOF);

	printf("\t\t\t\t��ѧ��");
	scanf("%f",&tempData.math);//��ȡѧ����ѧ�ɼ�
	while((ch = getchar()) != '\n' && ch != EOF);

	printf("\t\t\t\tӢ��ɼ���");
	scanf("%f",&tempData.english);//��ȡѧ��Ӣ��ɼ�
	while((ch = getchar()) != '\n' && ch != EOF);

	tempData.sumscore=tempData.math+tempData.english;//����ѧ���ܳɼ�
	printf("\t\t\t\t�ܳɼ�Ϊ��%.1f\n",tempData.sumscore);//��ӡѧ���ܳɼ�

	insertnode(List,tempData);//�������в���ѧ����Ϣ
	saveToFile("student.txt",List);//�������е�ѧ����Ϣ���浽�ļ�student.txt
	printf("\n\t\t\t\t���ӳɹ���\n");
}
//����ѧ����Ϣ
void searchStudent(struct student tempData)
{
	printf("\n\t\t\t---------------����ѧ����Ϣ--------------\n\n");
	printf("\t\t\t\t1.��ѧ�Ų���\t\t\t\t\n");
	printf("\t\t\t\t2.����������\t\t\t\t\n");
	printf("\t\t\t\t��ѡ����:");

	//��ȡѡ��
    int choice = 0;
	scanf("%d",&choice);
	//���������
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)
	{
	case 1:
		{
			printf("\n\t\t\t������Ҫ���ҵ�ѧ����ѧ��:");
			scanf("%s",tempData.id);//��ȡѧ��ѧ��
			while((ch= getchar()) != '\n' && ch != EOF);//���������

			//searchnode_byid()����ֵΪ���ָ���NULL
            //����NULL��˵��δ�鵽
			if(searchnode_byid(List,tempData.id) == NULL)
			{
				//�������в����ڸ�ѧ��
				printf("\n\t\t\t\t���޴���!\n");	
			}else
			{
				//��ӡ���ҵ�ѧ����Ϣ
				printsearch(searchnode_byid(List,tempData.id));
			}
			break;
		}
	case 2:
		{
			printf("\n\t\t\t������Ҫ���ҵ�ѧ��������:");
			scanf("%s",tempData.name);//��ȡѧ������
			while((ch = getchar()) != '\n' && ch != EOF);//���������

			//searchnode_byname()����ֵΪ���ָ���NULL
            //����NULL��˵��δ�鵽
			if(searchnode_byname(List,tempData.name) == NULL)
			{
				//�������в����ڸ�����
				printf("\n\t\t\t\t���޴���!\n");
			}else
			{
				//��ӡ���ҵ�ѧ����Ϣ
				printsearch(searchnode_byname(List,tempData.name));
			}
			break;
		}
	default:
		{
			printf("\n\t\t\t\t����������������룡\n");
			break;
		}
	}
}
//�޸�ѧ����Ϣ
void modifyStudent(struct student tempData)
{
	printf("\n\t\t\t--------�޸�ѧ����Ϣ--------\t\t\t\t\n");
	//�ȵ���printList()������ӡȫ��ѧ����Ϣ
	printList(List);
	printf("\t\t\t\t1.��ѧ���޸�\t\t\t\t\n");
	printf("\t\t\t\t2.�������޸�\t\t\t\t\n");
	printf("\t\t\t\t��ѡ����:");

	//��ȡѡ��
	int choice = 0;
	scanf("%d",&choice);
	//���������
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)
	{
	case 1:
		{
			printf("\n\t\t\t������Ҫ�޸ĵ�ѧ����ѧ�ţ�");

			scanf("%s",tempData.id);//��ȡѧ����ѧ��
			while((ch = getchar()) != '\n' && ch != EOF);

			if(searchnode_byid(List,tempData.id) == NULL)
			{
				//�������в����ڸ�ѧ��
				printf("\n\t\t\t\t���޴���!\n");
			}else
			{
				//�޸�ѧ����Ϣ�ķֺ���
				modifyStudent_Second(tempData);
			}
			break;
		}
	case 2:
		{
			printf("\n\t\t\t\t������Ҫ�޸ĵ�ѧ����������");
			scanf("%s",tempData.name);//��ȡѧ������
			while((ch = getchar()) != '\n' && ch != EOF);

			if(searchnode_byname(List,tempData.name)==NULL)
			{
				//�������в����ڸ�����
				printf("\n\t\t\t\t���޴���!\n");
			}else
			{
				modifyStudent_Second(tempData);
			}
			break;
		}
	default:
		{
			printf("\t\t\t\t����������������룡\n");
			function();//���빦�ܽ���
			break;
		}
	}
}
void modifyStudent_Second(struct student tempData)
{
	//���¶���һ��ָ�벢ָ��Ҫ�޸ĵ�ѧ������Ϣ�Ľ��
	struct Node *curnode=searchnode_byid(List,tempData.id);
	//����printsearch()������ӡҪ�޸�ѧ������Ϣ
	printsearch(searchnode_byid(List,tempData.id));

	printf("\n");
	printf("\t\t\t\t1.ѧ��\t\t\t\t\n");
	printf("\t\t\t\t2.����\t\t\t\t\n");
	printf("\t\t\t\t3.�Ա�\t\t\t\t\n");
	printf("\t\t\t\t4.����\t\t\t\t\n");
	printf("\t\t\t\t5.�����ɼ�\t\t\t\t\n");
	printf("\t\t\t\t6.Ӣ��ɼ�\t\t\t\t\n");
	printf("\t\t\t\t��ѡ��Ҫ�޸ĵ����ݣ�");

	//��ȡѡ��
	int choice = 0;
	scanf("%d",&choice);
	//���������
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)
	{
		case 1:
		{
			printf("\n\t\t\t\t�޸�ǰ��ѧ�ţ�%s\n",curnode->data.id);
			printf("\t\t\t\t�������޸ĺ��ѧ�ţ�");

			scanf("%s",curnode->data.id);
			while((ch = getchar()) != '\n' && ch != EOF);

			//���޸ĺ����Ϣ���浽�ļ�
			saveToFile("student.txt",List);
			printf("\n\t\t\t\t�޸ĳɹ�!\n");
			break;
		}
		case 2:
		{
			printf("\n\t\t\t\t�޸�ǰ��������%s\n",curnode->data.name);
			printf("\t\t\t\t�������޸ĺ��������");

			scanf("%s",curnode->data.name);
			while((ch = getchar()) != '\n' && ch != EOF);

			saveToFile("student.txt",List);
			printf("\n\t\t\t\t�޸ĳɹ�!\n");
			break;
		}
		case 3:
		{
			printf("\n\t\t\t\t�޸�ǰ���Ա�%s\n",curnode->data.gender);
			printf("\t\t\t\t�������޸ĺ���Ա�");

			scanf("%s",curnode->data.gender);
			while((ch= getchar()) != '\n' && ch != EOF);

			saveToFile("student.txt",List);
			printf("\n\t\t\t\t�޸ĳɹ�!\n");
			break;
		}
		case 4:
		{
			printf("\n\t\t\t\t�޸�ǰ�����䣺%d\n",curnode->data.age);
			printf("\t\t\t\t�������޸ĺ�����䣺");

			scanf("%d",&curnode->data.age);
			while((ch = getchar()) != '\n' && ch != EOF);

			saveToFile("student.txt",List);
			printf("\n\t\t\t\t�޸ĳɹ�!\n");
			break;
		}
		case 5:
		{
			printf("\n\t\t\t\t�޸�ǰ�ĸ����ɼ���%.1f\n",curnode->data.math);
			printf("\t\t\t\t�������޸ĺ�ĸ����ɼ���");

			scanf("%f",&curnode->data.math);
			while((ch = getchar()) != '\n' && ch != EOF);

			//�����ܳɼ�
			curnode->data.sumscore=curnode->data.math+curnode->data.english;

			saveToFile("student.txt",List);
			printf("\n\t\t\t\t�޸ĳɹ�!\n");
			break;
		}
		case 6:
		{
			printf("\n\t\t\t\t�޸�ǰ��Ӣ��ɼ���%.1f\n",curnode->data.english);
			printf("\t\t\t\t�������޸ĺ��Ӣ��ɼ���");

			scanf("%f",&curnode->data.english);
			while((ch = getchar()) != '\n' && ch != EOF);

			curnode->data.sumscore=curnode->data.math+curnode->data.english;

			saveToFile("student.txt",List);
			printf("\n\t\t\t\t�޸ĳɹ�!\n");
			break;
		}
		default:
		{
			printf("\n\t\t\t\t����������������룡\n");
			break;
		}
	}
}
//ɾ��ѧ����Ϣ
void deleteStudent(struct student tempData)
{
	printf("\n\t\t\t--------------ɾ��ѧ����Ϣ---------------\n");
	//����printList()������ӡȫ��ѧ����Ϣ
	printList(List);
	printf("\t\t\t\t1.��ѧ��ɾ��\t\t\t\t\n");
	printf("\t\t\t\t2.������ɾ��\t\t\t\t\n");
	printf("\t\t\t\t��ѡ����:");

	//��ȡѡ��
	int choice = 0;
	scanf("%d",&choice);
	//���������
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)
	{
	case 1:
		{
			printf("\n\t\t\t������Ҫɾ����ѧ����ѧ��:");

			scanf("%s",tempData.id);
			while((ch = getchar()) != '\n' && ch != EOF);

			//��������ɾ��ѧ����Ϣ
			Deletenode_byid(List,tempData.id);
			//��ʣ����Ϣ���浽�ļ�
			saveToFile("student.txt",List);
			
			break;
		}
	case 2:
		{
			printf("\n\t\t\t������Ҫɾ����ѧ��������:");

			scanf("%s",tempData.name);
			while((ch = getchar()) != '\n' && ch != EOF);

			Deletenode_byname(List,tempData.name);
			saveToFile("student.txt",List);
			break;
		}
	default:
		{
			printf("\n\t\t\t\t����������������룡\n");
			break;
		}
	}
}
//����
void sortStudent()
{
	printf("\n\t\t\t---------------����ѧ����Ϣ--------------\n");
	printf("\t\t\t\t1.����ѧ������(�ӵ͵���)\n");
	printf("\t\t\t\t2.������ѧ�ɼ�����(�Ӹߵ���)\n");
	printf("\t\t\t\t3.����Ӣ��ɼ�����(�Ӹߵ���)\n");
	printf("\t\t\t\t4.�����ܳɼ�����(�Ӹߵ���)\n");
	printf("\t\t\t\t��ѡ����(1-4):");

	//��ȡѡ��
	int choice = 0;
	scanf("%d",&choice);
	//���������
	char ch;
	while((ch = getchar()) != '\n' && ch != EOF);

	switch(choice)
	{
	case 1:
		{
			//��ѧ�Ŵӵ͵�����������
			sortList_byid(List);
			//����������Ϣ���浽�ļ�
			saveToFile("student.txt",List);
			//��ӡ�����е���Ϣ
			printList(List);
			break;
		}
	case 2:
		{
			//����ѧ�ɼ��Ӹߵ�����������
			sortList_bymath(List);
			printList(List);
			break;
		}
	case 3:
		{
			//��Ӣ��ɼ��Ӹߵ�����������
			sortList_byenglish(List);
			printList(List);
			break;
		}
	case 4:
		{
			//���ܳɼ��Ӹߵ�����������
			sortList_bysumscore(List);
			printList(List);
			break;
		}
	default:
		{
			printf("\n\t\t\t\t����������������룡\n");
			break;
		}
	}
}
