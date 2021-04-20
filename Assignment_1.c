#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

struct b_day
{
    int day;
    int month;
    int year;
};

struct student
{
    char name[50];
    int ID;
    struct b_day bday;
    int score_;

};
//globals
int n;
char garbage;


//functions
int add_integer(int* req);
struct student* create_array(int n);
struct student* insert_begin(struct student* ptr2, int n_);
void data_(struct student* ptr_d, int i);
void data_cpy(struct student* dest, struct student* src);
struct student* add_element_l(struct student* ptr2, int n);
struct student* add_element_m(struct student* ptr2, int n);
void print_(struct student* ptr, int m);
void dynamic_array();

int main()
{
    int choice;
    printf("Choose an option to continue.\n(1)Linked lists.\n(2)Dynamic arrays.\nInput:");
    do {
        choice = add_integer(&choice);
    } while (choice != 1 && choice != 2);
    if (choice == 2)
    {
        dynamic_array;
    }
}
struct student* create_array(int n)

{
    struct student* ptr;
    ptr = (struct student*)malloc(n * sizeof(struct student));
    if (ptr == NULL)
    {
        printf("failed to allocate\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        data_(&ptr[i], i+1);
    }
    return ptr;
}
struct student* insert_begin(struct student* ptr2, int n_)
{
    struct student* ptr3;
    ptr3 = (struct student*)malloc((n + 1) * sizeof(struct student));
    if (ptr3 == NULL)
    {
        printf("failed to allocate\n");
        return 0;
    }
    data_(&ptr3[0], 1);

    for (int i = 0; i < n; i++)
    {
        data_cpy(&ptr3[i + 1], &ptr2[i]);
    }
    n++;
    //print_(ptr3, n);
    return ptr3;
}
struct student* add_element_l(struct student* ptr2, int n_)
{
    struct student* ptr3;
    ptr3 = (struct student*)realloc(ptr2, (n + 1) * sizeof(struct student));
    if (ptr3 == NULL)
    {
        printf("failed to allocate\n");
        return 0;
    }
    data_(&ptr3[n], n + 1);
    n++;
    return ptr3;
}
struct student* add_element_m(struct student* ptr2, int n_)
{
    struct student* ptr3;
    ptr3 = (struct student*)malloc((n + 1) * sizeof(struct student));
    if (ptr3 == NULL)
    {
        printf("failed to allocate\n");
        return 0;
    }
    int position_ = n / 2;
    //position_--;
    for (int i = 0; i < position_; i++)
    {
        data_cpy(&ptr3[i], &ptr2[i]);
    }
    data_(&ptr3[position_], position_ + 1);
    position_++;
    for (int i = position_; i <= n; i++)
    {
        data_cpy(&ptr3[i], &ptr2[i - 1]);
    }
    n++;
    return ptr3;
}

void data_(struct student* ptr_d, int i)
{
    struct student* ptr = (ptr_d);
    printf("\nEnter the name of student %d:", i );
    scanf_s("%c", &garbage, 1); //cin.ignore
    scanf_s("%[^\n]", ptr->name, 50);
    printf("Enter the ID of student %d: ", i );
    ptr->ID = add_integer(&ptr->ID);
    printf("Enter the birthday of the student %d\n", i);
    do {
        printf("Day : ");
        ptr->bday.day = add_integer(&ptr->bday.day); //added
    } while (ptr->bday.day > 31);
    do {
        printf("month : ");
        ptr->bday.month = add_integer(&ptr->bday.month);
    } while (ptr->bday.month > 12);
    printf("Year : ");
    ptr->bday.year = add_integer(&ptr->bday.year); //added
    printf("Score of student %d: ", i );
    ptr->score_ = add_integer(&ptr->score_);
}
void data_cpy(struct student* dest, struct student* src)
{
    strcpy_s(dest->name,50, src->name);
    dest->ID = src->ID;
    dest->score_ = src->score_;
    dest->bday.day = src->bday.day;
    dest->bday.month = src->bday.month;
    dest->bday.year = src->bday.year;

}
void print_(struct student* ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nThe name of student %i is %s\n",i+1, (ptr + i)->name);
        printf("ID of student number %i is %i\n",i+1, (ptr + i)->ID);
        printf("the student was born in %i/%i/%i\n",(ptr + i)->bday.day,(ptr+i)->bday.month, (ptr + i)->bday.year);
        printf("The grade of the student is %i\n", (ptr + i)->score_);
    }
}

int add_integer(int* req) //added
{
    while (1)
    {
        scanf_s("%c", &garbage, 1);
        if (scanf_s("%i", req) == 1)
            if(*req >=0)
                return *req;
    }
}
void dynamic_array()
{
    printf("Welcome\n");
    int position;
    int test;

    printf("please enter the size of the array: ");

    if (scanf_s("%i", &test) == 1 && test >= 0)
    {
        n = test;
    }
    else
    {
        printf("Invalid input\n");
        return 0;
    }
    struct student* students = NULL;
    students = create_array(n);
    int op1;
    do {
        printf("Enter the desired operation:-\n(1)insert at the beginning.\n(2)insert at the end.\n(3)insert in the middle.\n(4)Exit.\n");
        scanf_s("%i", &op1);
        switch (op1)
        {
        case(1):
        {
            students = insert_begin(students, n);
            break;
        }
        case(2):
        {
            students = add_element_l(students, n);
            break;
        }
        case(3):
        {
            if (n <= 0)
            {
                printf("insufficient number of students\n");
                break;
            }

            students = add_element_m(students, n);
            break;
        }
        case(4):
            break;
        }
    } while ((op1 > 4) || (op1 == 0));
    print_(students, n);
    printf("the size of the structure is %i ", sizeof(struct student));
    free(students);
}
