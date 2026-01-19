#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "mylist.h"

//创建一个有表头链表
struct Node *creatList()
{
	//有表头链表：第一个结点不存放数据
	//无表头链表：第一个结点存放数据
	//产生一个结构体变量
	struct Node *StudentListhead;
	//为其动态分配内存
	//程序结束后，系统自动回收
	StudentListhead=(struct Node*)malloc(sizeof(struct Node));
	//初始化
	StudentListhead->next =NULL;

	return StudentListhead;
}
//创建一个新结点
struct Node *creatnode(struct student data)
{
	//新结点动态分配内存
	//程序结束后，系统自动回收
	struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));

	newnode->data = data;
	newnode->next=NULL;

	return newnode;
}
//插入新结点:录入信息
void insertnode(struct Node *StudentListhead,struct student data)
{
	//接收creatnode()返回值
	struct Node *newnode=creatnode(data);

	//使用头插法将新结点插入链表中
	newnode->next=StudentListhead->next;
	StudentListhead->next=newnode;
}
//按学号删除学生信息
void Deletenode_byid(struct Node *StudentListhead,char *id)
{
	//定义前置结点并指向头结点
	struct Node *posFrontNode=StudentListhead;
	//定义一个位置结点并指向头结点的下一个结点
	struct Node *posNode=StudentListhead->next;

	if(posNode==NULL)//当位置结点为NULL，即链表为空时
	{
		printf("\n\t\t\t\t无相关内容，无法删除!\n");
		return;
	}
	else
	{
		//若链表不为空，循环链表，查找要删除的学生
		while(strcmp(posNode->data.id,id))
		{
			posFrontNode=posNode;
			posNode= posFrontNode->next;

			if(posNode == NULL)//未找到相关学生
			{
				printf("\n\t\t\t\t无相关内容，无法删除!\n");
				return;
			}
		}
		//若找到，则删除相关学生
		posFrontNode->next=posNode->next;
		free(posNode);
		printf("\n\t\t\t\t删除成功！\n");
	}
}
//按姓名删除学生信息
void Deletenode_byname(struct Node *StudentListhead,char *name)
{
	//定义前置结点并指向头结点
	struct Node *posFrontNode=StudentListhead;
	//定义一个位置结点并指向头结点的下一个结点
	struct Node *posNode=StudentListhead->next;

	if(posNode==NULL)//当位置结点为NULL，即链表为空时
	{
		printf("\n\t\t\t\t无相关内容，无法删除!\n");
		return;
	}
	else
	{
		while(strcmp(posNode->data.name,name))
		{
			posFrontNode=posNode;
			posNode= posFrontNode->next;
			if(posNode == NULL)
			{
				printf("\n\t\t\t\t无相关内容，无法删除!\n");
				return;
			}
		}
		posFrontNode->next=posNode->next;
		free(posNode);
		printf("\n\t\t\t\t删除成功！\n");
	}
}
//按学号查找学生
struct Node *searchnode_byid(struct Node *StudentListhead,char *id)
{
	//定义移动结点并指向头结点的下一个结点
	struct Node *pmove=StudentListhead->next;

	if(pmove==NULL)//链表为空
	{
		return pmove;
	}
	else
	{
		//若链表不为空，循环链表，查找学生
		while(strcmp(pmove->data.id,id))
		{
			pmove=pmove->next;
			
			//若未查到
			if(pmove==NULL)
			{
				break;
			}
		}
		return pmove;
	}
}
//按姓名查找学生
struct Node *searchnode_byname(struct Node *StudentListhead,char *name)
{
	struct Node *pmove=StudentListhead->next;
	if(pmove==NULL)
	{
		return pmove;
	}
	else
	{
		while(strcmp(pmove->data.name,name))
		{
			pmove=pmove->next;
			if(pmove==NULL)
			{
				break;
			}
		}
		return pmove;
	}
}
//打印查找的学生信息
void printsearch(struct Node *curnode/*当前结点*/)
{
	printf("\t学号\t\t姓名\t性别\t年龄\t高数成绩\t英语成绩\t成绩总和\n");
	printf("\t%-10s\t%-4s\t%-6s\t%-3d\t%.1f\t\t%.1f\t\t%.1f\n",curnode->data.id,curnode->data.name,curnode->data.gender,curnode->data.age,curnode->data.math,curnode->data.english,curnode->data.sumscore);
}
//打印学生信息
void printList(struct Node *StudentListhead)
{
	struct Node *pmove=StudentListhead->next;

	//按格式打印
	printf("\t学号\t\t姓名\t性别\t年龄\t高数成绩\t英语成绩\t成绩总和\n");

	while(pmove)//pmove为NULL时，退出循环
	{
		//格式化输出打印
		printf("\t%-10s\t%-4s\t%-6s\t%-3d\t%.1f\t\t%.1f\t\t%.1f\n",pmove->data.id,pmove->data.name,pmove->data.gender,pmove->data.age,pmove->data.math,pmove->data.english,pmove->data.sumscore);
		//pmove指向下一个结点，以此遍历链表
		pmove=pmove->next;
	}
	printf("\n");
}
//按照学号排序
void sortList_byid(struct Node *StudentListhead)
{
	//定义临时结构体变量
	struct student temp;
	//定义前置结点并指向头结点
	struct Node *posFrontNode=StudentListhead;
	//定义一个位置结点并指向头结点的下一个结点
	struct Node *posNode=StudentListhead->next;

	if(posNode==NULL)//当位置结点为NULL，即链表为空时
	{
		printf("\n\t\t\t\t无相关内容，无法排序!\n");
		return;
	}
	//遍历链表
	while(posNode!=NULL)
	{
		while(posNode->next != NULL)
		{
			if(strcmp(posNode->data.id,posNode->next->data.id) > 0)//按学号从低到高排序
			{
				temp=posNode->data;
				posNode->data=posNode->next->data;
				posNode->next->data=temp;
			}
			posNode=posNode->next;
		}
		posNode=posFrontNode->next;
		posFrontNode=posNode;
	}

}
//按照数学成绩排序
void sortList_bymath(struct Node *StudentListhead)
{
	struct student temp;
	struct Node *posFrontNode=StudentListhead;
	struct Node *posNode=StudentListhead->next;
	if(posNode==NULL)
	{
		printf("\n\t\t\t\t无相关内容，无法排序!\n");
		return;
	}
	while(posNode!=NULL)
	{
		while(posNode->next != NULL)
		{
			if(posNode->data.math < posNode->next->data.math)
			{
				temp=posNode->data;
				posNode->data=posNode->next->data;
				posNode->next->data=temp;
			}
			posNode=posNode->next;
		}
		posNode=posFrontNode->next;
		posFrontNode=posNode;
	}

}
//按照英语成绩排序
void sortList_byenglish(struct Node *StudentListhead)
{
	struct student temp;
	struct Node *posFrontNode=StudentListhead;
	struct Node *posNode=StudentListhead->next;
	if(posNode==NULL)
	{
		printf("\n\t\t\t\t无相关内容，无法排序!\n");
		return;
	}
	while(posNode!=NULL)
	{
		while(posNode->next != NULL)
		{
			if(posNode->data.english < posNode->next->data.english)
			{
				temp=posNode->data;
				posNode->data=posNode->next->data;
				posNode->next->data=temp;
			}
			posNode=posNode->next;
		}
		posNode=posFrontNode->next;
		posFrontNode=posNode;
	}

}
//按照总成绩排序
void sortList_bysumscore(struct Node *StudentListhead)
{
	struct student temp;
	struct Node *posFrontNode=StudentListhead;
	struct Node *posNode=StudentListhead->next;
	if(posNode==NULL)
	{
		printf("\n\t\t\t\t无相关内容，无法排序!\n");
		return;
	}
	while(posNode!=NULL)
	{
		while(posNode->next != NULL)
		{
			if(posNode->data.sumscore < posNode->next->data.sumscore)
			{
				temp=posNode->data;
				posNode->data=posNode->next->data;
				posNode->next->data=temp;
			}
			posNode=posNode->next;
		}
		posNode=posFrontNode->next;
		posFrontNode=posNode;
	}

}
//从文件中读取学生信息
void readFromFile(char *File_student,struct Node *StudentListhead)
{
	//定义文件指针并指向一个文件
	FILE *fpstu=fopen(File_student,"r");
	//如果不存在该文件，重新创建
	if(fpstu==NULL)
	{
		fpstu=fopen(File_student,"w");
	}

	//临时变量
	struct student tempData = {"0","0","0",0,0.0,0.0,0.0};

	//遍历文件
	while(fscanf(fpstu,"%s\t%s\t%s\t%d\t%f\t\t%f\t\t%f\n",tempData.id,
		tempData.name,tempData.gender,&tempData.age,&tempData.math,&tempData.english,&tempData.sumscore)!=EOF)
	{
		//将学生信息插入到链表
		insertnode(StudentListhead,tempData);
	}
	//关闭文件
	fclose(fpstu);
}
//将学生信息存入文件
void saveToFile(char *File_student,struct Node *StudentListhead)
{
	//定义文件指针并指向一个文件
	FILE *fpstu=fopen(File_student,"w");
	//定义临时结点指针
	struct Node *pmove=StudentListhead->next;

	while(pmove)//遍历链表
	{
		//将链表中学生信息存储到文件中
		fprintf(fpstu,"%s\t%s\t%s\t%d\t%.1f\t\t%.1f\t\t%.1f\n",pmove->data.id,
			pmove->data.name,pmove->data.gender,pmove->data.age,pmove->data.math,pmove->data.english,pmove->data.sumscore);
		pmove=pmove->next;
	}
	//关闭文件
	fclose(fpstu);
}