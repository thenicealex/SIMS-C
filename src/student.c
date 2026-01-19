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

#define CLS_COMMAND "clear"
#define PAUSE_MESSAGE "Press Enter to continue..."

static void clear_input_buffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

static void clear_screen(void)
{
#ifdef _WIN32
    clear_screen();
#else
    system(CLS_COMMAND);
#endif
}

static void pause_system(void)
{
    printf(PAUSE_MESSAGE);
    fflush(stdout);
    clear_input_buffer();
}

static struct Node *List = NULL;

static int read_line(char *buffer, size_t size)
{
    if (buffer == NULL || size == 0) {
        return 0;
    }

    if (fgets(buffer, size, stdin) == NULL) {
        return 0;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    return 1;
}

static void read_string(const char *prompt, char *buffer, size_t size)
{
    if (buffer == NULL || size == 0) {
        return;
    }

    printf("\t\t\t\t%s:", prompt);
    buffer[0] = '\0';

    while (buffer[0] == '\0') {
        if (!read_line(buffer, size)) {
            clear_input_buffer();
            printf("\t\t\t\tInvalid input. Please try again: ");
        }
    }
}

static int read_int(const char *prompt, int min, int max)
{
    int value;
    int result;

    printf("\t\t\t\t%s:", prompt);

    while (1) {
        result = scanf("%d", &value);
        clear_input_buffer();

        if (result != 1) {
            printf("\t\t\t\tInvalid input. Please enter a number: ");
            continue;
        }

        if (value < min || value > max) {
            printf("\t\t\t\tPlease enter a number between %d and %d: ", min, max);
            continue;
        }

        return value;
    }
}

static float read_float(const char *prompt, float min, float max)
{
    float value;
    int result;

    printf("\t\t\t\t%s:", prompt);

    while (1) {
        result = scanf("%f", &value);
        clear_input_buffer();

        if (result != 1) {
            printf("\t\t\t\tInvalid input. Please enter a number: ");
            continue;
        }

        if (value < min || value > max) {
            printf("\t\t\t\tPlease enter a number between %.1f and %.1f: ", min, max);
            continue;
        }

        return value;
    }
}

static void menu();
static void function();
static void login();
static void login_Second();
static void rebackPassword();
static void addStudent(void);
static void searchStudent(void);
static void modifyStudent(void);
static void modifyStudent_Second(const char *id);
static void deleteStudent(void);
static void sortStudent(void);

int main(void)
{
#ifdef _WIN32
    SET_CONSOLE_TITLE("Student Information Management System");
    SET_CONSOLE_COLOR("color F0");
    system("mode con cols=90 lines=30");
#else
    SET_CONSOLE_TITLE("Student Information Management System");
#endif

    List = creatList();
    if (List == NULL) {
        fprintf(stderr, "Failed to create list. Exiting.\n");
        return 1;
    }

    int lines = readFromFile("student.txt", List);
    if (lines < 0) {
        printf("\t\t\t\tWarning: Could not load data file.\n");
    }

    menu();

    saveToFile("student.txt", List);
    freeList(List);
    List = NULL;

    return 0;
}

static void menu(void)
{
    printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t|\tWelcome to Student Management System\t|\n");
    printf("\t\t\t----------------------------------------\n");
    printf("\t\t\t|\t1. Login\t\t\t|\n");
    printf("\t\t\t|\t2. Forgot Password\t\t|\n");
    printf("\t\t\t|\t3. Exit System\t\t\t|\n");
    printf("\t\t\t----------------------------------------\n");

    int choice = read_int("Please select (1-3)", 1, 3);

    switch (choice)
    {
    case 1:
        {
            clear_screen();
            login();
            break;
        }
    case 2:
        {
            clear_screen();
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
            pause_system();
            clear_screen();
            menu();
            break;
        }
    }
}

static void login(void)
{
    int i;
    char Password[] = "123";
    char tempPass[MAX_INPUT_LEN] = {0};

    printf("\t\t\t---------------Login System---------------\n\n");
    printf("\t\t\t\tAdmin Account: admin\n");
    for (i = 1; i <= 3; i++)
    {
        printf("\t\t\t\tAdmin Password:");

        if (!read_line(tempPass, sizeof(tempPass))) {
            clear_input_buffer();
            tempPass[0] = '\0';
        }

        if (strcmp(Password, tempPass) == 0)
        {
            printf("\n\t\t\t\tLogin successful!");
            printf("\n\t\t\t\t");
            pause_system();
            clear_screen();
            function();
            return;
        }
        else
        {
            if (3 == i)
            {
                printf("\n\t\t\t\tPassword incorrect 3 times! Please choose option.\n\n");
                printf("\t\t\t\t");
                pause_system();
            }
            else
            {
                printf("\n\t\t\t\tPassword incorrect %d time(s)! Please try again!\n", i);
            }
        }
    }
    if (4 == i)
    {
        clear_screen();
        login_Second();
    }
}

static void login_Second(void)
{
    printf("\t\t\t-------------------------------------\n");
    printf("\t\t\t|\t    1. Forgot Password\t\t    |\n");
    printf("\t\t\t|\t    2. Login Again\t\t    |\n");
    printf("\t\t\t|\t    3. Exit System\t\t    |\n");
    printf("\t\t\t-------------------------------------\n");
    printf("\t\t\t\t   Please select (1-3):");

    int choice = read_int("Please select", 1, 3);

    switch (choice)
    {
    case 1:
        {
            clear_screen();
            rebackPassword();
            break;
        }
    case 2:
        {
            clear_screen();
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
            pause_system();
            clear_screen();
            login_Second();
            break;
        }
    }
}

static void rebackPassword(void)
{
    int question_one, question_two, question_three;

    printf("\t\t\t    ------------Forgot Password------------\n\n");
    printf("\t\t\t\t    Security Questions:\n");
    printf("\n\t\t\t\t    1. What is your pet's name?\n");
    printf("\n\t\t\t\t      Answer:");

    question_one = read_int("Answer", 1, 100);

    printf("\n\t\t\t\t    2. What is your favorite color?\n");
    printf("\n\t\t\t\t      Answer:");

    question_two = read_int("Answer", 1, 100);

    printf("\n\t\t\t\t    3. What is your favorite food?\n");
    printf("\n\t\t\t\t      Answer:");

    question_three = read_int("Answer", 1, 100);

    if (1 == question_one && 2 == question_two && 3 == question_three)
    {
        printf("\n\n\t\t\t\t    Admin Password: 123\n\n\t\t\t\t    ");
        pause_system();
        clear_screen();
    }
    else
    {
        printf("\n\t\t\t\t     Incorrect answer\n\n\t\t\t\t    ");
        pause_system();
        clear_screen();
    }
    menu();
}

static void function(void)
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

    int choice = read_int("Please select", 1, 8);

    switch (choice)
    {
    case 1:
        {
            addStudent();
            printf("\n\t\t\t\t");
            pause_system();
            clear_screen();
            break;
        }
    case 2:
        {
            printf("\n\t\t\t--------------All Students--------------\n");
            printList(List);
            printf("\n\t\t\t\t");
            pause_system();
            clear_screen();
            break;
        }
    case 3:
        {
            searchStudent();
            printf("\n\t\t\t\t");
            pause_system();
            clear_screen();
            break;
        }
    case 4:
        {
            modifyStudent();
            printf("\n\t\t\t\t");
            pause_system();
            clear_screen();
            break;
        }
    case 5:
        {
            deleteStudent();
            printf("\n\t\t\t\t");
            pause_system();
            clear_screen();
            break;
        }
    case 6:
        {
            sortStudent();
            printf("\n\t\t\t\t");
            pause_system();
            clear_screen();
            break;
        }
    case 7:
        {
            clear_screen();
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
            pause_system();
            clear_screen();
            break;
        }
    }
    function();
}

static void addStudent(void)
{
    struct student tempData;

    printf("\n\t\t\t--------------Add Student--------------\n");

    read_string("Student ID", tempData.id, sizeof(tempData.id));
    read_string("Name", tempData.name, sizeof(tempData.name));
    read_string("Gender", tempData.gender, sizeof(tempData.gender));

    tempData.age = read_int("Age", 1, 150);
    tempData.math = read_float("Math Score (0-100)", 0.0f, 100.0f);
    tempData.english = read_float("English Score (0-100)", 0.0f, 100.0f);

    tempData.sumscore = tempData.math + tempData.english;
    printf("\t\t\t\tTotal Score: %.1f\n", tempData.sumscore);

    insertnode(List, tempData);
    saveToFile("student.txt", List);
    printf("\n\t\t\t\tAdd successful!\n");
}

static void searchStudent(void)
{
    printf("\n\t\t\t---------------Search Student--------------\n\n");
    printf("\t\t\t\t1. Search by ID\t\t\t\n");
    printf("\t\t\t\t2. Search by Name\t\t\t\n");
    printf("\t\t\t\tPlease select:");

    int choice = read_int("Please select", 1, 2);

    switch (choice)
    {
    case 1:
        {
            char id[ID_LEN];
            printf("\n\t\t\tEnter the student ID to search:");
            read_string("Student ID", id, sizeof(id));

            struct Node *result = searchnode_byid(List, id);
            if (result == NULL)
            {
                printf("\n\t\t\t\tStudent not found!\n");
            }
            else
            {
                printsearch(result);
            }
            break;
        }
    case 2:
        {
            char name[NAME_LEN];
            printf("\n\t\t\tEnter the student name to search:");
            read_string("Student Name", name, sizeof(name));

            struct Node *result = searchnode_byname(List, name);
            if (result == NULL)
            {
                printf("\n\t\t\t\tStudent not found!\n");
            }
            else
            {
                printsearch(result);
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

static void modifyStudent(void)
{
    printf("\n\t\t\t--------Modify Student Info--------\t\t\t\t\n");
    printList(List);
    printf("\t\t\t\t1. Modify by ID\t\t\t\t\n");
    printf("\t\t\t\t2. Modify by Name\t\t\t\t\n");
    printf("\t\t\t\tPlease select:");

    int choice = read_int("Please select", 1, 2);

    switch (choice)
    {
    case 1:
        {
            char id[ID_LEN];
            printf("\n\t\t\tEnter the student ID to modify:");
            read_string("Student ID", id, sizeof(id));

            struct Node *result = searchnode_byid(List, id);
            if (result == NULL)
            {
                printf("\n\t\t\t\tStudent not found!\n");
            }
            else
            {
                modifyStudent_Second(id);
            }
            break;
        }
    case 2:
        {
            char name[NAME_LEN];
            printf("\n\t\t\t\tEnter the student name to modify:");
            read_string("Student Name", name, sizeof(name));

            struct Node *result = searchnode_byname(List, name);
            if (result == NULL)
            {
                printf("\n\t\t\t\tStudent not found!\n");
            }
            else
            {
                modifyStudent_Second(result->data.id);
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

static void modifyStudent_Second(const char *id)
{
    struct Node *curnode = searchnode_byid(List, id);
    if (curnode == NULL) {
        return;
    }

    printsearch(curnode);

    printf("\n");
    printf("\t\t\t\t1. Student ID\t\t\t\n");
    printf("\t\t\t\t2. Name\t\t\t\t\n");
    printf("\t\t\t\t3. Gender\t\t\t\n");
    printf("\t\t\t\t4. Age\t\t\t\t\n");
    printf("\t\t\t\t5. Math Score\t\t\t\n");
    printf("\t\t\t\t6. English Score\t\t\t\n");
    printf("\t\t\t\tPlease select the field to modify:");

    int field_choice = read_int("Please select", 1, 6);

    switch (field_choice)
    {
        case 1:
        {
            printf("\n\t\t\t\tCurrent ID: %s\n", curnode->data.id);
            printf("\t\t\t\tEnter new ID:");
            read_string("New ID", curnode->data.id, sizeof(curnode->data.id));
            saveToFile("student.txt", List);
            printf("\n\t\t\t\tModify successful!\n");
            break;
        }
        case 2:
        {
            printf("\n\t\t\t\tCurrent Name: %s\n", curnode->data.name);
            printf("\t\t\t\tEnter new Name:");
            read_string("New Name", curnode->data.name, sizeof(curnode->data.name));
            saveToFile("student.txt", List);
            printf("\n\t\t\t\tModify successful!\n");
            break;
        }
        case 3:
        {
            printf("\n\t\t\t\tCurrent Gender: %s\n", curnode->data.gender);
            printf("\t\t\t\tEnter new Gender:");
            read_string("New Gender", curnode->data.gender, sizeof(curnode->data.gender));
            saveToFile("student.txt", List);
            printf("\n\t\t\t\tModify successful!\n");
            break;
        }
        case 4:
        {
            printf("\n\t\t\t\tCurrent Age: %d\n", curnode->data.age);
            curnode->data.age = read_int("New Age", 1, 150);
            saveToFile("student.txt", List);
            printf("\n\t\t\t\tModify successful!\n");
            break;
        }
        case 5:
        {
            printf("\n\t\t\t\tCurrent Math Score: %.1f\n", curnode->data.math);
            curnode->data.math = read_float("New Math Score (0-100)", 0.0f, 100.0f);
            curnode->data.sumscore = curnode->data.math + curnode->data.english;
            saveToFile("student.txt", List);
            printf("\n\t\t\t\tModify successful!\n");
            break;
        }
        case 6:
        {
            printf("\n\t\t\t\tCurrent English Score: %.1f\n", curnode->data.english);
            curnode->data.english = read_float("New English Score (0-100)", 0.0f, 100.0f);
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

static void deleteStudent(void)
{
    printf("\n\t\t\t--------------Delete Student---------------\n");
    printList(List);
    printf("\t\t\t\t1. Delete by ID\t\t\t\t\n");
    printf("\t\t\t\t2. Delete by Name\t\t\t\t\n");
    printf("\t\t\t\tPlease select:");

    int choice = read_int("Please select", 1, 2);

    switch (choice)
    {
    case 1:
        {
            char id[ID_LEN];
            printf("\n\t\t\tEnter the student ID to delete:");
            read_string("Student ID", id, sizeof(id));

            Deletenode_byid(List, id);
            saveToFile("student.txt", List);
            break;
        }
    case 2:
        {
            char name[NAME_LEN];
            printf("\n\t\t\tEnter the student name to delete:");
            read_string("Student Name", name, sizeof(name));

            Deletenode_byname(List, name);
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

static void sortStudent(void)
{
    printf("\n\t\t\t---------------Sort Students--------------\n");
    printf("\t\t\t\t1. Sort by ID (Low to High)\n");
    printf("\t\t\t\t2. Sort by Math Score (High to Low)\n");
    printf("\t\t\t\t3. Sort by English Score (High to Low)\n");
    printf("\t\t\t\t4. Sort by Total Score (High to Low)\n");
    printf("\t\t\t\tPlease select (1-4):");

    int choice = read_int("Please select", 1, 4);

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
