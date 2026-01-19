#ifndef _MYLIST_H_
	#define _MYLIST_H_

struct student
{
	char id[15];
	char name[10];
	char gender[10];
	int age;
	float math;
	float english;
	float sumscore;
};
struct Node
{
	struct student data;
	struct Node *next;
};
struct Node *creatList();
struct Node *creatnode(struct student data);
void insertnode(struct Node *StudentListhead,struct student data);
void Deletenode_byid(struct Node *StudentListhead,char *id);
void Deletenode_byname(struct Node *StudentListhead,char *name);
struct Node *searchnode_byid(struct Node *StudentListhead,char *id);
struct Node *searchnode_byname(struct Node *StudentListhead,char *name);
void printsearch(struct Node *curnode);
void printList(struct Node *StudentListhead);
void sortList_byid(struct Node *StudentListhead);
void sortList_bymath(struct Node *StudentListhead);
void sortList_byenglish(struct Node *StudentListhead);
void sortList_bysumscore(struct Node *StudentListhead);
void readFromFile(char *File_student,struct Node *StudentListhead);
void saveToFile(char *File_student,struct Node *StudentListhead);

#endif