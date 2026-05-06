#ifndef MYLIST_H_
#define MYLIST_H_

#define MYLIST_NAME_LEN 31
#define MYLIST_ID_LEN 16
#define MYLIST_GENDER_LEN 11
#define MYLIST_MAX_INPUT_LEN 256

struct mylist_student
{
	char id[MYLIST_ID_LEN];
	char name[MYLIST_NAME_LEN];
	char gender[MYLIST_GENDER_LEN];
	int age;
	float math;
	float english;
	float total;
};

struct mylist_node
{
	struct mylist_student data;
	struct mylist_node *next;
};

#ifdef __cplusplus
extern "C" {
#endif

struct mylist_node *mylist_create(void);
void mylist_free(struct mylist_node *head);
struct mylist_node *mylist_node_create(struct mylist_student data);
void mylist_insert_front(struct mylist_node *head, struct mylist_student data);
void mylist_remove_by_id(struct mylist_node *head, const char *id);
void mylist_remove_by_name(struct mylist_node *head, const char *name);
struct mylist_node *mylist_find_by_id(const struct mylist_node *head, const char *id);
struct mylist_node *mylist_find_by_name(const struct mylist_node *head, const char *name);
void mylist_print_one(const struct mylist_node *node);
void mylist_print_all(const struct mylist_node *head);
void mylist_sort_by_id(struct mylist_node *head);
void mylist_sort_by_math(struct mylist_node *head);
void mylist_sort_by_english(struct mylist_node *head);
void mylist_sort_by_total(struct mylist_node *head);
int mylist_load_file(const char *filename, struct mylist_node *head);
int mylist_save_file(const char *filename, struct mylist_node *head);

#ifdef __cplusplus
}
#endif

#endif /* MYLIST_H_ */

#ifdef MYLIST_IMPLEMENTATION

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mylist_node *mylist_create(void)
{
    struct mylist_node *head = (struct mylist_node *)malloc(sizeof(struct mylist_node));
    if (head == NULL) {
        return NULL;
    }
    head->next = NULL;
    return head;
}

void mylist_free(struct mylist_node *head)
{
    if (head == NULL) {
        return;
    }

    struct mylist_node *current = head;
    while (current != NULL) {
        struct mylist_node *next = current->next;
        free(current);
        current = next;
    }
}

struct mylist_node *mylist_node_create(struct mylist_student data)
{
    struct mylist_node *node = (struct mylist_node *)malloc(sizeof(struct mylist_node));
    if (node == NULL) {
        return NULL;
    }

    node->data = data;
    node->next = NULL;

    return node;
}

void mylist_insert_front(struct mylist_node *head, struct mylist_student data)
{
    if (head == NULL) {
        return;
    }

    struct mylist_node *node = mylist_node_create(data);
    if (node == NULL) {
        return;
    }

    node->next = head->next;
    head->next = node;
}

void mylist_remove_by_id(struct mylist_node *head, const char *id)
{
    if (head == NULL || id == NULL) {
        return;
    }

    struct mylist_node *prev = head;
    struct mylist_node *curr = head->next;

    if (curr == NULL)
    {
        printf("\n\t\t\t\tNo data found! Cannot delete!\n");
        return;
    }

    while (curr != NULL && strcmp(curr->data.id, id) != 0)
    {
        prev = curr;
        curr = prev->next;
    }

    if (curr == NULL)
    {
        printf("\n\t\t\t\tStudent not found! Cannot delete!\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
    printf("\n\t\t\t\tDelete successful!\n");
}

void mylist_remove_by_name(struct mylist_node *head, const char *name)
{
    if (head == NULL || name == NULL) {
        return;
    }

    struct mylist_node *prev = head;
    struct mylist_node *curr = head->next;

    if (curr == NULL)
    {
        printf("\n\t\t\t\tNo data found! Cannot delete!\n");
        return;
    }

    while (curr != NULL && strcmp(curr->data.name, name) != 0)
    {
        prev = curr;
        curr = prev->next;
    }

    if (curr == NULL)
    {
        printf("\n\t\t\t\tStudent not found! Cannot delete!\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
    printf("\n\t\t\t\tDelete successful!\n");
}

struct mylist_node *mylist_find_by_id(const struct mylist_node *head, const char *id)
{
    if (head == NULL || id == NULL) {
        return NULL;
    }

    const struct mylist_node *curr = head->next;

    while (curr != NULL)
    {
        if (strcmp(curr->data.id, id) == 0)
        {
            return (struct mylist_node *)curr;
        }
        curr = curr->next;
    }

    return NULL;
}

struct mylist_node *mylist_find_by_name(const struct mylist_node *head, const char *name)
{
    if (head == NULL || name == NULL) {
        return NULL;
    }

    const struct mylist_node *curr = head->next;

    while (curr != NULL)
    {
        if (strcmp(curr->data.name, name) == 0)
        {
            return (struct mylist_node *)curr;
        }
        curr = curr->next;
    }

    return NULL;
}

void mylist_print_one(const struct mylist_node *node)
{
    if (node == NULL) {
        return;
    }

    printf("\tID\t\tName\tGender\tAge\tMath\tEnglish\tTotal\n");
    printf("\t%-10s\t%-4s\t%-6s\t%-3d\t%.1f\t\t%.1f\t\t%.1f\n",
           node->data.id, node->data.name, node->data.gender,
           node->data.age, node->data.math, node->data.english,
           node->data.total);
}

void mylist_print_all(const struct mylist_node *head)
{
    if (head == NULL) {
        return;
    }

    const struct mylist_node *curr = head->next;

    printf("\tID\t\tName\tGender\tAge\tMath\tEnglish\tTotal\n");

    while (curr != NULL)
    {
        printf("\t%-10s\t%-4s\t%-6s\t%-3d\t%.1f\t\t%.1f\t\t%.1f\n",
               curr->data.id, curr->data.name, curr->data.gender,
               curr->data.age, curr->data.math, curr->data.english,
               curr->data.total);
        curr = curr->next;
    }
    printf("\n");
}

static int compare_id(const void *a, const void *b)
{
    const struct mylist_student *sa = (const struct mylist_student *)a;
    const struct mylist_student *sb = (const struct mylist_student *)b;
    return strcmp(sa->id, sb->id);
}

static int compare_math(const void *a, const void *b)
{
    const struct mylist_student *sa = (const struct mylist_student *)a;
    const struct mylist_student *sb = (const struct mylist_student *)b;
    if (sa->math < sb->math) return 1;
    if (sa->math > sb->math) return -1;
    return 0;
}

static int compare_english(const void *a, const void *b)
{
    const struct mylist_student *sa = (const struct mylist_student *)a;
    const struct mylist_student *sb = (const struct mylist_student *)b;
    if (sa->english < sb->english) return 1;
    if (sa->english > sb->english) return -1;
    return 0;
}

static int compare_total(const void *a, const void *b)
{
    const struct mylist_student *sa = (const struct mylist_student *)a;
    const struct mylist_student *sb = (const struct mylist_student *)b;
    if (sa->total < sb->total) return 1;
    if (sa->total > sb->total) return -1;
    return 0;
}

static void swap_nodes(struct mylist_student *a, struct mylist_student *b)
{
    struct mylist_student temp = *a;
    *a = *b;
    *b = temp;
}

static size_t get_list_length(const struct mylist_node *head)
{
    size_t count = 0;
    const struct mylist_node *curr = head->next;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}

static void sort_nodes(struct mylist_node *head, int (*compare)(const void *, const void *))
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

    struct mylist_student *array = (struct mylist_student *)malloc(length * sizeof(struct mylist_student));
    if (array == NULL) {
        printf("\n\t\t\t\tMemory allocation failed!\n");
        return;
    }

    struct mylist_node *curr = head->next;
    size_t index = 0;
    while (curr != NULL && index < length) {
        array[index++] = curr->data;
        curr = curr->next;
    }

    for (size_t i = 1; i < length; i++) {
        for (size_t j = 0; j < length - i; j++) {
            if (compare(&array[j], &array[j + 1]) > 0) {
                swap_nodes(&array[j], &array[j + 1]);
            }
        }
    }

    curr = head->next;
    index = 0;
    while (curr != NULL && index < length) {
        curr->data = array[index++];
        curr = curr->next;
    }

    free(array);
}

void mylist_sort_by_id(struct mylist_node *head)
{
    sort_nodes(head, compare_id);
}

void mylist_sort_by_math(struct mylist_node *head)
{
    sort_nodes(head, compare_math);
}

void mylist_sort_by_english(struct mylist_node *head)
{
    sort_nodes(head, compare_english);
}

void mylist_sort_by_total(struct mylist_node *head)
{
    sort_nodes(head, compare_total);
}

int mylist_load_file(const char *filename, struct mylist_node *head)
{
    if (filename == NULL || head == NULL) {
        return -1;
    }

    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        fp = fopen(filename, "w");
        if (fp == NULL) {
            return -1;
        }
        fclose(fp);
        return 0;
    }

    struct mylist_student temp;
    int line_count = 0;
    int read_count;

    while ((read_count = fscanf(fp, "%14s\t%30s\t%10s\t%d\t%f\t\t%f\t\t%f\n",
                                temp.id, temp.name, temp.gender,
                                &temp.age, &temp.math, &temp.english,
                                &temp.total)) == 7)
    {
        mylist_insert_front(head, temp);
        line_count++;
    }

    if (ferror(fp)) {
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return line_count;
}

int mylist_save_file(const char *filename, struct mylist_node *head)
{
    if (filename == NULL || head == NULL) {
        return -1;
    }

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        return -1;
    }

    struct mylist_node *curr = head->next;
    int count = 0;

    while (curr != NULL)
    {
        fprintf(fp, "%s\t%s\t%s\t%d\t%.1f\t\t%.1f\t\t%.1f\n",
                curr->data.id, curr->data.name, curr->data.gender,
                curr->data.age, curr->data.math, curr->data.english,
                curr->data.total);
        curr = curr->next;
        count++;
    }

    if (ferror(fp)) {
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return count;
}

#endif /* MYLIST_IMPLEMENTATION */
