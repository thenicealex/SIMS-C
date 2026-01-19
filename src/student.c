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

struct Node *List = NULL;

void menu();
void function();
void login();
void login_Second();
void rebackPassword();
void addStudent(struct student tempData);
void searchStudent(struct student tempData);
void modifyStudent(struct student tempData);
void modifyStudent_Second(struct student tempData);
void deleteStudent(struct student tempData);
void sortStudent();

int main()
{
    SET_CONSOLE_TITLE("Student Information Management System");
    SET_CONSOLE_COLOR("color F0");
    system("mode con cols=90 lines=30");

    List = creatList();

    readFromFile("student.txt", List);

    menu();

    return 0;
}

void menu()
{
    printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t|\tWelcome to Student Management System\t|\n");
    printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t|\t1. Login\t\t\t|\n");
    printf("\t\t\t|\t2. Forgot Password\t\t|\n");
    printf("\t\t\t|\t3. Exit System\t\t\t|\n");
    printf("\t\t\t----------------------------------------\n");
    printf("\t\t\tPlease select (1-3) (press Enter to confirm):");

    int choice = 0;
    scanf("%d", &choice);

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    switch (choice)
    {
    case 1:
        {
            system("cls");
            login();
            break;
        }
    case 2:
        {
            system("cls");
            rebackPassword();
            break;
        }
    case 3:
        {
            printf("\n\t\t\t");
            exit(0);
        }
    default:
        {
            printf("\n\t\t\tInvalid input! Please try again.\n\t\t\t");
            system("pause");
            system("cls");

            menu();
            break;
        }
    }
}

void login()
{
    int i = 0;
    char Password[] = "123";
    char tempPass[10] = "0";

    printf("\t\t\t---------------Login System---------------\n\n");
    printf("\t\t\t\tAdmin Account: admin\n");
    for (i = 1; i <= 3; i++)
    {
        printf("\t\t\t\tAdmin Password:");
        scanf("%s", tempPass);

        char ch;
        while ((ch = getchar()) != '\n' && ch != EOF);

        if (!strcmp(Password, tempPass))
        {
            printf("\n\t\t\t\tLogin successful!");
            printf("\n\t\t\t\t");
            system("pause");
            system("cls");
            function();
        }
        else
        {
            if (3 == i)
            {
                printf("\n\t\t\t\tPassword incorrect 3 times! Please choose option.\n\n");
                printf("\t\t\t\t");
                system("pause");
            }
            else
            {
                printf("\n\t\t\t\tPassword incorrect %d time(s)! Please try again!\n", i);
            }
        }
    }
    if (4 == i)
    {
        system("cls");
        login_Second();
    }
}

void login_Second()
{
    printf("\t\t\t-------------------------------------\n");
    printf("\t\t\t|\t    1. Forgot Password\t\t    |\n");
    printf("\t\t\t|\t    2. Login Again\t\t    |\n");
    printf("\t\t\t|\t    3. Exit System\t\t    |\n");
    printf("\t\t\t-------------------------------------\n");
    printf("\t\t\t\t   Please select (1-3):");

    int choice = 0;
    scanf("%d", &choice);

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    switch (choice)
    {
    case 1:
        {
            system("cls");
            rebackPassword();
            break;
        }
    case 2:
        {
            system("cls");
            login();
            break;
        }
    case 3:
        {
            printf("\n\t\t\t\t");
            exit(0);
        }
    default:
        {
            printf("\n\t\t\t\tInvalid input! Please try again.\n\t\t\t\t");
            system("pause");
            system("cls");

            login_Second();
            break;
        }
    }
}

void rebackPassword()
{
    int question_one = 0;
    int question_two = 0;
    int question_three = 0;

    printf("\t\t\t    ------------Forgot Password------------\n\n");
    printf("\t\t\t\t    Security Questions:\n");
    printf("\n\t\t\t\t    1. What is your pet's name?\n");
    printf("\n\t\t\t\t      Answer:");

    scanf("%d", &question_one);
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("\n\t\t\t\t    2. What is your favorite color?\n");
    printf("\n\t\t\t\t      Answer:");

    scanf("%d", &question_two);
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("\n\t\t\t\t    3. What is your favorite food?\n");
    printf("\n\t\t\t\t      Answer:");

    scanf("%d", &question_three);
    while ((ch = getchar()) != '\n' && ch != EOF);

    if (1 == question_one && 2 == question_two && 3 == question_three)
    {
        printf("\n\n\t\t\t\t    Admin Password: 123\n\n\t\t\t\t    ");
        system("pause");
        system("cls");
    }
    else
    {
        printf("\n\t\t\t\t     Incorrect answer\n\n\t\t\t\t    ");
        system("pause");
        system("cls");
    }
    menu();
}

void function()
{
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\t|\tWelcome to Student Management System\t|\n");
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\t|\t1. Add Student Info\t\t\t|\n");
    printf("\t\t\t|\t2. View All Students\t\t\t|\n");
    printf("\t\t\t|\t3. Search Student\t\t\t|\n");
    printf("\t\t\t|\t4. Modify Student Info\t\t\t|\n");
    printf("\t\t\t|\t5. Delete Student\t\t\t|\n");
    printf("\t\t\t|\t6. Sort Students\t\t\t|\n");
    printf("\t\t\t|\t7. Return to Main Menu\t\t\t|\n");
    printf("\t\t\t|\t8. Exit System\t\t\t|\n");
    printf("\t\t\t-----------------------------------------\n");
    printf("\t\t\tPlease select (1-8):");

    struct student tempData = {"0", "0", "0", 0, 0.0, 0.0, 0.0};

    int choice = 0;
    scanf("%d", &choice);

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    switch (choice)
    {
    case 1:
        {
            addStudent(tempData);
            printf("\n\t\t\t\t");
            system("pause");
            system("cls");
            break;
        }
    case 2:
        {
            printf("\n\t\t\t--------------All Students--------------\n");
            printList(List);
            printf("\n\t\t\t\t");
            system("pause");
            system("cls");
            break;
        }
    case 3:
        {
            searchStudent(tempData);
            printf("\n\t\t\t\t");
            system("pause");
            system("cls");
            break;
        }
    case 4:
        {
            modifyStudent(tempData);
            printf("\n\t\t\t\t");
            system("pause");
            system("cls");
            break;
        }
    case 5:
        {
            deleteStudent(tempData);
            printf("\n\t\t\t\t");
            system("pause");
            system("cls");
            break;
        }
    case 6:
        {
            sortStudent();
            printf("\n\t\t\t\t");
            system("pause");
            system("cls");
            break;
        }
    case 7:
        {
            system("cls");
            menu();
            break;
        }
    case 8:
        {
            printf("\n\t\t\t\t");
            exit(0);
        }
    default:
        {
            printf("\n\t\t\t\tInvalid input! Please try again.\n");
            printf("\n\t\t\t\t");
            system("pause");
            system("cls");
            break;
        }
    }
    function();
}

void addStudent(struct student tempData)
{
    printf("\n\t\t\t--------------Add Student--------------\n");
    printf("\t\t\t\tStudent ID:");
    scanf("%s", tempData.id);
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("\t\t\t\tName:");
    scanf("%s", tempData.name);
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("\t\t\t\tGender:");
    scanf("%s", tempData.gender);
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("\t\t\t\tAge:");
    scanf("%d", &tempData.age);
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("\t\t\t\tMath Score:");
    scanf("%f", &tempData.math);
    while ((ch = getchar()) != '\n' && ch != EOF);

    printf("\t\t\t\tEnglish Score:");
    scanf("%f", &tempData.english);
    while ((ch = getchar()) != '\n' && ch != EOF);

    tempData.sumscore = tempData.math + tempData.english;
    printf("\t\t\t\tTotal Score: %.1f\n", tempData.sumscore);

    insertnode(List, tempData);
    saveToFile("student.txt", List);
    printf("\n\t\t\t\tAdd successful!\n");
}

void searchStudent(struct student tempData)
{
    printf("\n\t\t\t---------------Search Student--------------\n\n");
    printf("\t\t\t\t1. Search by ID\t\t\t\n");
    printf("\t\t\t\t2. Search by Name\t\t\t\n");
    printf("\t\t\t\tPlease select:");

    int choice = 0;
    scanf("%d", &choice);

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    switch (choice)
    {
    case 1:
        {
            printf("\n\t\t\tEnter the student ID to search:");
            scanf("%s", tempData.id);
            while ((ch = getchar()) != '\n' && ch != EOF);

            if (searchnode_byid(List, tempData.id) == NULL)
            {
                printf("\n\t\t\t\tStudent not found!\n");
            }
            else
            {
                printsearch(searchnode_byid(List, tempData.id));
            }
            break;
        }
    case 2:
        {
            printf("\n\t\t\tEnter the student name to search:");
            scanf("%s", tempData.name);
            while ((ch = getchar()) != '\n' && ch != EOF);

            if (searchnode_byname(List, tempData.name) == NULL)
            {
                printf("\n\t\t\t\tStudent not found!\n");
            }
            else
            {
                printsearch(searchnode_byname(List, tempData.name));
            }
            break;
        }
    default:
        {
            printf("\n\t\t\t\tInvalid input! Please try again.\n");
            break;
        }
    }
}

void modifyStudent(struct student tempData)
{
    printf("\n\t\t\t--------Modify Student Info--------\t\t\t\t\n");
    printList(List);
    printf("\t\t\t\t1. Modify by ID\t\t\t\t\n");
    printf("\t\t\t\t2. Modify by Name\t\t\t\t\n");
    printf("\t\t\t\tPlease select:");

    int choice = 0;
    scanf("%d", &choice);

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    switch (choice)
    {
    case 1:
        {
            printf("\n\t\t\tEnter the student ID to modify:");
            scanf("%s", tempData.id);
            while ((ch = getchar()) != '\n' && ch != EOF);

            if (searchnode_byid(List, tempData.id) == NULL)
            {
                printf("\n\t\t\t\tStudent not found!\n");
            }
            else
            {
                modifyStudent_Second(tempData);
            }
            break;
        }
    case 2:
        {
            printf("\n\t\t\t\tEnter the student name to modify:");
            scanf("%s", tempData.name);
            while ((ch = getchar()) != '\n' && ch != EOF);

            if (searchnode_byname(List, tempData.name) == NULL)
            {
                printf("\n\t\t\t\tStudent not found!\n");
            }
            else
            {
                modifyStudent_Second(tempData);
            }
            break;
        }
    default:
        {
            printf("\t\t\t\tInvalid input! Please try again.\n");
            function();
            break;
        }
    }
}

void modifyStudent_Second(struct student tempData)
{
    struct Node *curnode = searchnode_byid(List, tempData.id);
    printsearch(searchnode_byid(List, tempData.id));

    printf("\n");
    printf("\t\t\t\t1. Student ID\t\t\t\n");
    printf("\t\t\t\t2. Name\t\t\t\t\n");
    printf("\t\t\t\t3. Gender\t\t\t\n");
    printf("\t\t\t\t4. Age\t\t\t\t\n");
    printf("\t\t\t\t5. Math Score\t\t\t\n");
    printf("\t\t\t\t6. English Score\t\t\t\n");
    printf("\t\t\t\tPlease select the field to modify:");

    int choice = 0;
    scanf("%d", &choice);

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    switch (choice)
    {
        case 1:
        {
            printf("\n\t\t\t\tCurrent ID: %s\n", curnode->data.id);
            printf("\t\t\t\tEnter new ID:");

            scanf("%s", curnode->data.id);
            while ((ch = getchar()) != '\n' && ch != EOF);

            saveToFile("student.txt", List);
            printf("\n\t\t\t\tModify successful!\n");
            break;
        }
        case 2:
        {
            printf("\n\t\t\t\tCurrent Name: %s\n", curnode->data.name);
            printf("\t\t\t\tEnter new Name:");

            scanf("%s", curnode->data.name);
            while ((ch = getchar()) != '\n' && ch != EOF);

            saveToFile("student.txt", List);
            printf("\n\t\t\t\tModify successful!\n");
            break;
        }
        case 3:
        {
            printf("\n\t\t\t\tCurrent Gender: %s\n", curnode->data.gender);
            printf("\t\t\t\tEnter new Gender:");

            scanf("%s", curnode->data.gender);
            while ((ch = getchar()) != '\n' && ch != EOF);

            saveToFile("student.txt", List);
            printf("\n\t\t\t\tModify successful!\n");
            break;
        }
        case 4:
        {
            printf("\n\t\t\t\tCurrent Age: %d\n", curnode->data.age);
            printf("\t\t\t\tEnter new Age:");

            scanf("%d", &curnode->data.age);
            while ((ch = getchar()) != '\n' && ch != EOF);

            saveToFile("student.txt", List);
            printf("\n\t\t\t\tModify successful!\n");
            break;
        }
        case 5:
        {
            printf("\n\t\t\t\tCurrent Math Score: %.1f\n", curnode->data.math);
            printf("\t\t\t\tEnter new Math Score:");

            scanf("%f", &curnode->data.math);
            while ((ch = getchar()) != '\n' && ch != EOF);

            curnode->data.sumscore = curnode->data.math + curnode->data.english;

            saveToFile("student.txt", List);
            printf("\n\t\t\t\tModify successful!\n");
            break;
        }
        case 6:
        {
            printf("\n\t\t\t\tCurrent English Score: %.1f\n", curnode->data.english);
            printf("\t\t\t\tEnter new English Score:");

            scanf("%f", &curnode->data.english);
            while ((ch = getchar()) != '\n' && ch != EOF);

            curnode->data.sumscore = curnode->data.math + curnode->data.english;

            saveToFile("student.txt", List);
            printf("\n\t\t\t\tModify successful!\n");
            break;
        }
        default:
        {
            printf("\n\t\t\t\tInvalid input! Please try again.\n");
            break;
        }
    }
}

void deleteStudent(struct student tempData)
{
    printf("\n\t\t\t--------------Delete Student---------------\n");
    printList(List);
    printf("\t\t\t\t1. Delete by ID\t\t\t\t\n");
    printf("\t\t\t\t2. Delete by Name\t\t\t\t\n");
    printf("\t\t\t\tPlease select:");

    int choice = 0;
    scanf("%d", &choice);

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    switch (choice)
    {
    case 1:
        {
            printf("\n\t\t\tEnter the student ID to delete:");

            scanf("%s", tempData.id);
            while ((ch = getchar()) != '\n' && ch != EOF);

            Deletenode_byid(List, tempData.id);
            saveToFile("student.txt", List);

            break;
        }
    case 2:
        {
            printf("\n\t\t\tEnter the student name to delete:");

            scanf("%s", tempData.name);
            while ((ch = getchar()) != '\n' && ch != EOF);

            Deletenode_byname(List, tempData.name);
            saveToFile("student.txt", List);
            break;
        }
    default:
        {
            printf("\n\t\t\t\tInvalid input! Please try again.\n");
            break;
        }
    }
}

void sortStudent()
{
    printf("\n\t\t\t---------------Sort Students--------------\n");
    printf("\t\t\t\t1. Sort by ID (Low to High)\n");
    printf("\t\t\t\t2. Sort by Math Score (High to Low)\n");
    printf("\t\t\t\t3. Sort by English Score (High to Low)\n");
    printf("\t\t\t\t4. Sort by Total Score (High to Low)\n");
    printf("\t\t\t\tPlease select (1-4):");

    int choice = 0;
    scanf("%d", &choice);

    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);

    switch (choice)
    {
    case 1:
        {
            sortList_byid(List);
            saveToFile("student.txt", List);
            printList(List);
            break;
        }
    case 2:
        {
            sortList_bymath(List);
            printList(List);
            break;
        }
    case 3:
        {
            sortList_byenglish(List);
            printList(List);
            break;
        }
    case 4:
        {
            sortList_bysumscore(List);
            printList(List);
            break;
        }
    default:
        {
            printf("\n\t\t\t\tInvalid input! Please try again.\n");
            break;
        }
    }
}
