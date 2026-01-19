//条件编译
#ifndef _MYLIST_H_//如果没有引入头文件mylist.h
	#define _MYLIST_H_//那就引入头文件mylist.h

struct student//学生信息
{
	char id[15];
	char name[10];
	char gender[10];
	int age;
	float math;
	float english;
	float sumscore;
};
struct Node//链表结点
{
	struct student data;
	struct Node *next;
};
//创建一个有表头链表
struct Node *creatList();
//创建一个新结点
struct Node *creatnode(struct student data);
//插入新结点:录入信息
void insertnode(struct Node *StudentListhead,struct student data);
//按学号删除学生信息
void Deletenode_byid(struct Node *StudentListhead,char *id);
//按姓名删除学生信息
void Deletenode_byname(struct Node *StudentListhead,char *name);
//按学号查找学生
struct Node *searchnode_byid(struct Node *StudentListhead,char *id);
//按姓名查找学生
struct Node *searchnode_byname(struct Node *StudentListhead,char *name);
//打印查找
void printsearch(struct Node *curnode/*当前结点*/);
//打印学生信息
void printList(struct Node *StudentListhead);
//按照学号排序
void sortList_byid(struct Node *StudentListhead);
//按照数学成绩排序
void sortList_bymath(struct Node *StudentListhead);
//按照英语成绩排序
void sortList_byenglish(struct Node *StudentListhead);
//按照总成绩排序
void sortList_bysumscore(struct Node *StudentListhead);
//从文件中读取学生信息
void readFromFile(char *File_student,struct Node *StudentListhead);
//将学生信息存入文件
void saveToFile(char *File_student,struct Node *StudentListhead);

#endif