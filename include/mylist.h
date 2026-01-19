#ifndef _MYLIST_H_
#define _MYLIST_H_

#define NAME_LEN 31
#define ID_LEN 16
#define GENDER_LEN 11
#define MAX_INPUT_LEN 256

struct student
{
	char id[ID_LEN];
	char name[NAME_LEN];
	char gender[GENDER_LEN];
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
void freeList(struct Node *head);
struct Node *creatnode(struct student data);
void insertnode(struct Node *StudentListhead,struct student data);
void Deletenode_byid(struct Node *StudentListhead,const char *id);
void Deletenode_byname(struct Node *StudentListhead,const char *name);
struct Node *searchnode_byid(const struct Node *StudentListhead,const char *id);
struct Node *searchnode_byname(const struct Node *StudentListhead,const char *name);
void printsearch(const struct Node *curnode);
void printList(const struct Node *StudentListhead);
void sortList_byid(struct Node *StudentListhead);
void sortList_bymath(struct Node *StudentListhead);
void sortList_byenglish(struct Node *StudentListhead);
void sortList_bysumscore(struct Node *StudentListhead);
int readFromFile(const char *File_student,struct Node *StudentListhead);
int saveToFile(const char *File_student,struct Node *StudentListhead);

#endif