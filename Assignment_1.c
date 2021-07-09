//Ahmed Osama AbdulMaksoud Ali  BN : 1		Sec:1
//Ahmed Ali ElSayed	Ali			BN : 13		Sec:1
//Hussam Ali Ahmed Mohamed		BN : 56		Sec:1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
    struct student* next;
};

typedef struct node
{
    struct student students;
    struct node* next;
}node;

//Global_Variables
int n;
int num_n;
int num_;
char garbage;

//Dynamic_Array_Functions
void dynamic_array();
struct student* create_array(int n);
struct student* insert_begin(struct student* ptr2, int n_);
void data_(struct student* ptr_d, int i);
void data_cpy(struct student* dest, struct student* src);
struct student* add_element_l(struct student* ptr2, int n);
struct student* add_element_m(struct student* ptr2, int n);
void print_(struct student* ptr, int m);

//Linked_Lists_Functions
void linked_list();
void print_l(node* list);
void add_node(node** list, node** tail, int num_, char order);
void addbet(node** list, int num_);
void get_data(node* n, int num_);
void free_(node* list);
int add_integer(int* req);

int main()
{
    int choice;
    printf("Choose an option to continue.\n(1)Linked lists.\n(2)Dynamic arrays.\nInput:");
    scanf_s("%d", &choice);
    if (choice == 1)
    {
        linked_list();
    }
    else if (choice == 2)
    {
        dynamic_array();
    }
    else
    {
        printf("Invalid Input");
        return 0;
    }
}
struct student* create_array(int n) //dynamic array

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
        data_(&ptr[i], i + 1);
    }
    return ptr;
}
struct student* insert_begin(struct student* ptr2, int n_) //dynamic array
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
struct student* add_element_l(struct student* ptr2, int n_) //dynamic array
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
struct student* add_element_m(struct student* ptr2, int n_)//dynamic array
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
void data_(struct student* ptr_d, int i) //dyanmic array
{
    struct student* ptr = (ptr_d);
    printf("\nEnter the name of student %d:", i);
    scanf_s("%c", &garbage, 1); //cin.ignore
    scanf_s("%[^\n]", ptr->name, 50);
    printf("Enter the ID of student %d: ", i);
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
    printf("Score of student %d: ", i);
    ptr->score_ = add_integer(&ptr->score_);
}
void data_cpy(struct student* dest, struct student* src)
{
    strcpy_s(dest->name, 50, src->name);
    dest->ID = src->ID;
    dest->score_ = src->score_;
    dest->bday.day = src->bday.day;
    dest->bday.month = src->bday.month;
    dest->bday.year = src->bday.year;

}
void print_(struct student* ptr, int n) //dynamic array
{
    for (int i = 0; i < n; i++)
    {
        printf("\nThe name of student %i is %s\n", i + 1, (ptr + i)->name);
        printf("ID of student number %i is %i\n", i + 1, (ptr + i)->ID);
        printf("the student was born in %i/%i/%i\n", (ptr + i)->bday.day, (ptr + i)->bday.month, (ptr + i)->bday.year);
        printf("The grade of the student is %i\n", (ptr + i)->score_);
    }
}
void add_node(node** list, node** tail, int spot, char order) //linked lists
{
    node* n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("failed to allocate memory\n");
        return;
    }
    get_data(n, spot);
    if (order == 'h' || order == 'H')
    {
        n->next = (*list);
        (*list) = n;
        num_n++;
    }
    else if (order == 't' || order == 'T')
    {
        if ((*tail) == NULL)
        {
            n->next = (*tail);
            (*tail) = n;
            (*list) = (*tail);
            num_n++;
            return;
        }
        (*tail)->next = n;
        n->next = NULL;
        (*tail) = n;
        num_n++;
    }
    return;
}

void addbet(node** list, int num_)
{
    node* n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("failed to allocate memory\n");
        return;
    }
    get_data(n, num_n / 2 + 1);
    node* tmpb = (*list);
    for (int i = 1; i < num_n / 2; i++)
    {
        tmpb = tmpb->next;
    }
    n->next = tmpb->next;
    tmpb->next = n;
    num_n++;
}

void print_l(node* list)
{
    int z = 0;
    for (node* tmp_ = list; tmp_ != NULL; tmp_ = tmp_->next)
    {
        printf("\nthe name of student %i is %s\n", z + 1, tmp_->students.name);
        printf("The ID of student number %i is %i\n", z + 1, tmp_->students.ID);
        printf("The student was born in %i/%i/%i\n", tmp_->students.bday.day, tmp_->students.bday.month, tmp_->students.bday.year);
        printf("The grade of the student is%i\n\n", tmp_->students.score_);
        z++;
    }
}
void free_(node* list)
{
    if (list == NULL)
    {
        return;
    }
    free_(list->next);
    free(list);
}

void get_data(node* n, int pos)
{
    printf("\nEnter the name of student number %i : ", pos);
    scanf_s("%c", &garbage, 1);
    scanf_s("%[^\n]", n->students.name, 50);
    printf("Enter the ID of student number %i : ", pos);
    n->students.ID = add_integer(&n->students.ID);
    printf("Enter the birth day of student %i. \n", pos);
    printf("Day : ");
    do
    {
        n->students.bday.day = add_integer(&n->students.bday.day);
    } while (n->students.bday.day > 31);
    printf("Month : ");
    do
    {
        n->students.bday.month = add_integer(&n->students.bday.month);
    } while (n->students.bday.month > 12);
    printf("Year : ");
    n->students.bday.year = add_integer(&n->students.bday.year);
    printf("Score: ");
    n->students.score_ = add_integer(&n->students.score_);
}

int add_integer(int* req) //added
{
    while (1)
    {
        scanf_s("%c", &garbage, 1);
        if (scanf_s("%i", req) == 1)
            if (*req >= 0)
                return *req;
    }
}
void linked_list()
{
    int test;
    printf("Welcome\n");
    node* list = NULL;
    node* tail = NULL;
    printf("please enter the number of students: ");

    if (scanf_s("%i", &test) == 1 && test >= 0)
    {
        num_ = test;
    }
    else
    {
        printf("Invalid input\n");
        return;
    }
    num_n = 0;
    int op;

    for (int i = 0; i < num_; i++)
    {
        add_node(&list, &tail, i + 1, 't');
    }
    while (1)
    {
        printf("Enter the desired operation:-\n(1)insert at the beginning.\n(2)insert at the end.\n(3)insert at the middle.\n(4)Exit.\n");
        op = add_integer(&op);
        if (op == 4)
        {
            break;
        }
        do {

            switch (op)
            {
            case (1):
            {
                add_node(&list, &tail, num_, 'h');
                //get_data(list, 1);
                break;
            }
            case (2):
            {
                add_node(&list, &tail, num_, 't'); //end
                //get_data(tail, num_ + 1);
                break;
            }
            case (3):
            {
                if (num_n <= 1)
                {
                    printf("Insufficient number of students.\n");
                    break;
                }
                addbet(&list, num_);
                break;
            }
            case(4):
                break;
            }
        } while ((op > 4) || (op == 0));
        print_l(list);
    }

    printf("\nThe number of nodes is : %i\n", num_n);
    printf("The size of the structure is %i\n", sizeof(struct student));
    printf("The size of a node is %i\n", sizeof(node));
    free_(list);
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
        return;
    }
    struct student* students = NULL;
    students = create_array(n);
    int op1;
    while (1)
    {
        printf("Enter the desired operation:-\n(1)insert at the beginning.\n(2)insert at the end.\n(3)insert in the middle.\n(4)Exit.\n");
        scanf_s("%i", &op1);
        if (op1 == 4)
            break;
        do {


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
    }

    printf("the size of the structure is %i ", sizeof(struct student));
    free(students);
}