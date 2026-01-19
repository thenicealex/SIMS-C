#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylist.h"

struct Node *creatList()
{
    struct Node *StudentListhead;
    StudentListhead = (struct Node *)malloc(sizeof(struct Node));
    if (StudentListhead == NULL) {
        return NULL;
    }
    StudentListhead->next = NULL;
    return StudentListhead;
}

void freeList(struct Node *head)
{
    if (head == NULL) {
        return;
    }

    struct Node *current = head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
}

struct Node *creatnode(struct student data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL) {
        return NULL;
    }

    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

void insertnode(struct Node *StudentListhead, struct student data)
{
    if (StudentListhead == NULL) {
        return;
    }

    struct Node *newnode = creatnode(data);
    if (newnode == NULL) {
        return;
    }

    newnode->next = StudentListhead->next;
    StudentListhead->next = newnode;
}

void Deletenode_byid(struct Node *StudentListhead, const char *id)
{
    if (StudentListhead == NULL || id == NULL) {
        return;
    }

    struct Node *posFrontNode = StudentListhead;
    struct Node *posNode = StudentListhead->next;

    if (posNode == NULL)
    {
        printf("\n\t\t\t\tNo data found! Cannot delete!\n");
        return;
    }
    else
    {
        while (posNode != NULL && strcmp(posNode->data.id, id) != 0)
        {
            posFrontNode = posNode;
            posNode = posFrontNode->next;
        }

        if (posNode == NULL)
        {
            printf("\n\t\t\t\tStudent not found! Cannot delete!\n");
            return;
        }

        posFrontNode->next = posNode->next;
        free(posNode);
        printf("\n\t\t\t\tDelete successful!\n");
    }
}

void Deletenode_byname(struct Node *StudentListhead, const char *name)
{
    if (StudentListhead == NULL || name == NULL) {
        return;
    }

    struct Node *posFrontNode = StudentListhead;
    struct Node *posNode = StudentListhead->next;

    if (posNode == NULL)
    {
        printf("\n\t\t\t\tNo data found! Cannot delete!\n");
        return;
    }
    else
    {
        while (posNode != NULL && strcmp(posNode->data.name, name) != 0)
        {
            posFrontNode = posNode;
            posNode = posFrontNode->next;
        }

        if (posNode == NULL)
        {
            printf("\n\t\t\t\tStudent not found! Cannot delete!\n");
            return;
        }

        posFrontNode->next = posNode->next;
        free(posNode);
        printf("\n\t\t\t\tDelete successful!\n");
    }
}

struct Node *searchnode_byid(const struct Node *StudentListhead, const char *id)
{
    if (StudentListhead == NULL || id == NULL) {
        return NULL;
    }

    const struct Node *pmove = StudentListhead->next;

    while (pmove != NULL)
    {
        if (strcmp(pmove->data.id, id) == 0)
        {
            return (struct Node *)pmove;
        }
        pmove = pmove->next;
    }

    return NULL;
}

struct Node *searchnode_byname(const struct Node *StudentListhead, const char *name)
{
    if (StudentListhead == NULL || name == NULL) {
        return NULL;
    }

    const struct Node *pmove = StudentListhead->next;

    while (pmove != NULL)
    {
        if (strcmp(pmove->data.name, name) == 0)
        {
            return (struct Node *)pmove;
        }
        pmove = pmove->next;
    }

    return NULL;
}

void printsearch(const struct Node *curnode)
{
    if (curnode == NULL) {
        return;
    }

    printf("\tID\t\tName\tGender\tAge\tMath\tEnglish\tTotal\n");
    printf("\t%-10s\t%-4s\t%-6s\t%-3d\t%.1f\t\t%.1f\t\t%.1f\n",
           curnode->data.id, curnode->data.name, curnode->data.gender,
           curnode->data.age, curnode->data.math, curnode->data.english,
           curnode->data.sumscore);
}

void printList(const struct Node *StudentListhead)
{
    if (StudentListhead == NULL) {
        return;
    }

    const struct Node *pmove = StudentListhead->next;

    printf("\tID\t\tName\tGender\tAge\tMath\tEnglish\tTotal\n");

    while (pmove != NULL)
    {
        printf("\t%-10s\t%-4s\t%-6s\t%-3d\t%.1f\t\t%.1f\t\t%.1f\n",
               pmove->data.id, pmove->data.name, pmove->data.gender,
               pmove->data.age, pmove->data.math, pmove->data.english,
               pmove->data.sumscore);
        pmove = pmove->next;
    }
    printf("\n");
}

static int compare_id(const void *a, const void *b)
{
    const struct student *sa = (const struct student *)a;
    const struct student *sb = (const struct student *)b;
    return strcmp(sa->id, sb->id);
}

static int compare_math(const void *a, const void *b)
{
    const struct student *sa = (const struct student *)a;
    const struct student *sb = (const struct student *)b;
    if (sa->math < sb->math) return 1;
    if (sa->math > sb->math) return -1;
    return 0;
}

static int compare_english(const void *a, const void *b)
{
    const struct student *sa = (const struct student *)a;
    const struct student *sb = (const struct student *)b;
    if (sa->english < sb->english) return 1;
    if (sa->english > sb->english) return -1;
    return 0;
}

static int compare_sumscore(const void *a, const void *b)
{
    const struct student *sa = (const struct student *)a;
    const struct student *sb = (const struct student *)b;
    if (sa->sumscore < sb->sumscore) return 1;
    if (sa->sumscore > sb->sumscore) return -1;
    return 0;
}

static void swap_nodes(struct student *a, struct student *b)
{
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

static size_t get_list_length(const struct Node *head)
{
    size_t count = 0;
    const struct Node *current = head->next;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

static void sort_list_nodes(struct Node *head, int (*compare)(const void *, const void *))
{
    if (head == NULL || head->next == NULL) {
        printf("\n\t\t\t\tNo data found! Cannot sort!\n");
        return;
    }

    size_t length = get_list_length(head);
    if (length == 0) {
        printf("\n\t\t\t\tNo data found! Cannot sort!\n");
        return;
    }

    struct student *array = (struct student *)malloc(length * sizeof(struct student));
    if (array == NULL) {
        printf("\n\t\t\t\tMemory allocation failed!\n");
        return;
    }

    struct Node *pmove = head->next;
    size_t index = 0;
    while (pmove != NULL && index < length) {
        array[index++] = pmove->data;
        pmove = pmove->next;
    }

    for (size_t i = 1; i < length; i++) {
        for (size_t j = 0; j < length - i; j++) {
            if (compare(&array[j], &array[j + 1]) > 0) {
                swap_nodes(&array[j], &array[j + 1]);
            }
        }
    }

    pmove = head->next;
    index = 0;
    while (pmove != NULL && index < length) {
        pmove->data = array[index++];
        pmove = pmove->next;
    }

    free(array);
}

void sortList_byid(struct Node *StudentListhead)
{
    sort_list_nodes(StudentListhead, compare_id);
}

void sortList_bymath(struct Node *StudentListhead)
{
    sort_list_nodes(StudentListhead, compare_math);
}

void sortList_byenglish(struct Node *StudentListhead)
{
    sort_list_nodes(StudentListhead, compare_english);
}

void sortList_bysumscore(struct Node *StudentListhead)
{
    sort_list_nodes(StudentListhead, compare_sumscore);
}

int readFromFile(const char *File_student, struct Node *StudentListhead)
{
    if (File_student == NULL || StudentListhead == NULL) {
        return -1;
    }

    FILE *fpstu = fopen(File_student, "r");
    if (fpstu == NULL)
    {
        fpstu = fopen(File_student, "w");
        if (fpstu == NULL) {
            return -1;
        }
        fclose(fpstu);
        return 0;
    }

    struct student tempData;
    int line_count = 0;
    int read_count;

    while ((read_count = fscanf(fpstu, "%14s\t%30s\t%10s\t%d\t%f\t\t%f\t\t%f\n",
                                tempData.id, tempData.name, tempData.gender,
                                &tempData.age, &tempData.math, &tempData.english,
                                &tempData.sumscore)) == 7)
    {
        insertnode(StudentListhead, tempData);
        line_count++;
    }

    if (ferror(fpstu)) {
        fclose(fpstu);
        return -1;
    }

    fclose(fpstu);
    return line_count;
}

int saveToFile(const char *File_student, struct Node *StudentListhead)
{
    if (File_student == NULL || StudentListhead == NULL) {
        return -1;
    }

    FILE *fpstu = fopen(File_student, "w");
    if (fpstu == NULL) {
        return -1;
    }

    struct Node *pmove = StudentListhead->next;
    int count = 0;

    while (pmove != NULL)
    {
        fprintf(fpstu, "%s\t%s\t%s\t%d\t%.1f\t\t%.1f\t\t%.1f\n",
                pmove->data.id, pmove->data.name, pmove->data.gender,
                pmove->data.age, pmove->data.math, pmove->data.english,
                pmove->data.sumscore);
        pmove = pmove->next;
        count++;
    }

    if (ferror(fpstu)) {
        fclose(fpstu);
        return -1;
    }

    fclose(fpstu);
    return count;
}
