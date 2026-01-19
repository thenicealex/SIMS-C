#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"

struct Node *creatList()
{
    struct Node *StudentListhead;
    StudentListhead = (struct Node *)malloc(sizeof(struct Node));
    StudentListhead->next = NULL;

    return StudentListhead;
}

struct Node *creatnode(struct student data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void insertnode(struct Node *StudentListhead, struct student data)
{
    struct Node *newnode = creatnode(data);

    newnode->next = StudentListhead->next;
    StudentListhead->next = newnode;
}

void Deletenode_byid(struct Node *StudentListhead, char *id)
{
    struct Node *posFrontNode = StudentListhead;
    struct Node *posNode = StudentListhead->next;

    if (posNode == NULL)
    {
        printf("\n\t\t\t\tNo data found! Cannot delete!\n");
        return;
    }
    else
    {
        while (strcmp(posNode->data.id, id))
        {
            posFrontNode = posNode;
            posNode = posFrontNode->next;

            if (posNode == NULL)
            {
                printf("\n\t\t\t\tStudent not found! Cannot delete!\n");
                return;
            }
        }
        posFrontNode->next = posNode->next;
        free(posNode);
        printf("\n\t\t\t\tDelete successful!\n");
    }
}

void Deletenode_byname(struct Node *StudentListhead, char *name)
{
    struct Node *posFrontNode = StudentListhead;
    struct Node *posNode = StudentListhead->next;

    if (posNode == NULL)
    {
        printf("\n\t\t\t\tNo data found! Cannot delete!\n");
        return;
    }
    else
    {
        while (strcmp(posNode->data.name, name))
        {
            posFrontNode = posNode;
            posNode = posFrontNode->next;
            if (posNode == NULL)
            {
                printf("\n\t\t\t\tStudent not found! Cannot delete!\n");
                return;
            }
        }
        posFrontNode->next = posNode->next;
        free(posNode);
        printf("\n\t\t\t\tDelete successful!\n");
    }
}

struct Node *searchnode_byid(struct Node *StudentListhead, char *id)
{
    struct Node *pmove = StudentListhead->next;

    if (pmove == NULL)
    {
        return pmove;
    }
    else
    {
        while (strcmp(pmove->data.id, id))
        {
            pmove = pmove->next;

            if (pmove == NULL)
            {
                break;
            }
        }
        return pmove;
    }
}

struct Node *searchnode_byname(struct Node *StudentListhead, char *name)
{
    struct Node *pmove = StudentListhead->next;
    if (pmove == NULL)
    {
        return pmove;
    }
    else
    {
        while (strcmp(pmove->data.name, name))
        {
            pmove = pmove->next;
            if (pmove == NULL)
            {
                break;
            }
        }
        return pmove;
    }
}

void printsearch(struct Node *curnode)
{
    printf("\tID\t\tName\tGender\tAge\tMath\tEnglish\tTotal\n");
    printf("\t%-10s\t%-4s\t%-6s\t%-3d\t%.1f\t\t%.1f\t\t%.1f\n",
           curnode->data.id, curnode->data.name, curnode->data.gender,
           curnode->data.age, curnode->data.math, curnode->data.english,
           curnode->data.sumscore);
}

void printList(struct Node *StudentListhead)
{
    struct Node *pmove = StudentListhead->next;

    printf("\tID\t\tName\tGender\tAge\tMath\tEnglish\tTotal\n");

    while (pmove)
    {
        printf("\t%-10s\t%-4s\t%-6s\t%-3d\t%.1f\t\t%.1f\t\t%.1f\n",
               pmove->data.id, pmove->data.name, pmove->data.gender,
               pmove->data.age, pmove->data.math, pmove->data.english,
               pmove->data.sumscore);
        pmove = pmove->next;
    }
    printf("\n");
}

void sortList_byid(struct Node *StudentListhead)
{
    struct student temp;
    struct Node *posFrontNode = StudentListhead;
    struct Node *posNode = StudentListhead->next;

    if (posNode == NULL)
    {
        printf("\n\t\t\t\tNo data found! Cannot sort!\n");
        return;
    }

    while (posNode != NULL)
    {
        while (posNode->next != NULL)
        {
            if (strcmp(posNode->data.id, posNode->next->data.id) > 0)
            {
                temp = posNode->data;
                posNode->data = posNode->next->data;
                posNode->next->data = temp;
            }
            posNode = posNode->next;
        }
        posNode = posFrontNode->next;
        posFrontNode = posNode;
    }
}

void sortList_bymath(struct Node *StudentListhead)
{
    struct student temp;
    struct Node *posFrontNode = StudentListhead;
    struct Node *posNode = StudentListhead->next;
    if (posNode == NULL)
    {
        printf("\n\t\t\t\tNo data found! Cannot sort!\n");
        return;
    }
    while (posNode != NULL)
    {
        while (posNode->next != NULL)
        {
            if (posNode->data.math < posNode->next->data.math)
            {
                temp = posNode->data;
                posNode->data = posNode->next->data;
                posNode->next->data = temp;
            }
            posNode = posNode->next;
        }
        posNode = posFrontNode->next;
        posFrontNode = posNode;
    }
}

void sortList_byenglish(struct Node *StudentListhead)
{
    struct student temp;
    struct Node *posFrontNode = StudentListhead;
    struct Node *posNode = StudentListhead->next;
    if (posNode == NULL)
    {
        printf("\n\t\t\t\tNo data found! Cannot sort!\n");
        return;
    }
    while (posNode != NULL)
    {
        while (posNode->next != NULL)
        {
            if (posNode->data.english < posNode->next->data.english)
            {
                temp = posNode->data;
                posNode->data = posNode->next->data;
                posNode->next->data = temp;
            }
            posNode = posNode->next;
        }
        posNode = posFrontNode->next;
        posFrontNode = posNode;
    }
}

void sortList_bysumscore(struct Node *StudentListhead)
{
    struct student temp;
    struct Node *posFrontNode = StudentListhead;
    struct Node *posNode = StudentListhead->next;
    if (posNode == NULL)
    {
        printf("\n\t\t\t\tNo data found! Cannot sort!\n");
        return;
    }
    while (posNode != NULL)
    {
        while (posNode->next != NULL)
        {
            if (posNode->data.sumscore < posNode->next->data.sumscore)
            {
                temp = posNode->data;
                posNode->data = posNode->next->data;
                posNode->next->data = temp;
            }
            posNode = posNode->next;
        }
        posNode = posFrontNode->next;
        posFrontNode = posNode;
    }
}

void readFromFile(char *File_student, struct Node *StudentListhead)
{
    FILE *fpstu = fopen(File_student, "r");

    if (fpstu == NULL)
    {
        fpstu = fopen(File_student, "w");
    }

    struct student tempData = {"0", "0", "0", 0, 0.0, 0.0, 0.0};

    while (fscanf(fpstu, "%s\t%s\t%s\t%d\t%f\t\t%f\t\t%f\n", tempData.id,
                  tempData.name, tempData.gender, &tempData.age, &tempData.math,
                  &tempData.english, &tempData.sumscore) != EOF)
    {
        insertnode(StudentListhead, tempData);
    }

    fclose(fpstu);
}

void saveToFile(char *File_student, struct Node *StudentListhead)
{
    FILE *fpstu = fopen(File_student, "w");
    struct Node *pmove = StudentListhead->next;

    while (pmove)
    {
        fprintf(fpstu, "%s\t%s\t%s\t%d\t%.1f\t\t%.1f\t\t%.1f\n",
                pmove->data.id, pmove->data.name, pmove->data.gender,
                pmove->data.age, pmove->data.math, pmove->data.english,
                pmove->data.sumscore);
        pmove = pmove->next;
    }

    fclose(fpstu);
}
