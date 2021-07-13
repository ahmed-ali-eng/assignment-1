//Ahmed Osama AbdulMaksoud Ali  BN : 1		Sec:1
//Ahmed Ali ElSayed	Ali			BN : 13		Sec:1
//Hussam Ali Ahmed Mohamed		BN : 56		Sec:1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<stdbool.h>
#include <time.h>

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
struct student* insert_begin(struct student* ptr2, int n_, int op);
void data_(struct student* ptr_d, int i);
void data_cpy(struct student* dest, struct student* src);
struct student* add_element_l(struct student* ptr2, int n, int op);
struct student* add_element_m(struct student* ptr2, int n, int op);
void print_(struct student* ptr, int m);
void data_auto(struct student* ptr_d);

//Linked_Lists_Functions
void linked_list();
void print_l(node* list);
void add_node(node** list, node** tail, int num_,int op, char order);
void addbet(node** list, int num_, int op);
void get_data(node* n, int num_);
void free_(node* list);
int add_integer(int* req);
void get_data_auto(node* n);

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
struct student* insert_begin(struct student* ptr2, int n_, int op) //dynamic array
{
    struct student* ptr3;
    ptr3 = (struct student*)malloc((n + 1) * sizeof(struct student));
    if (ptr3 == NULL)
    {
        printf("failed to allocate\n");
        return 0;
    }
    if(op == 1)
        data_(&ptr3[0], 1);
    if (op == 2)
        data_auto(&ptr3[0]);

    for (int i = 0; i < n; i++)
    {
        data_cpy(&ptr3[i + 1], &ptr2[i]);
    }
    n++;
    //print_(ptr3, n);
    return ptr3;
}
struct student* add_element_l(struct student* ptr2, int n_,int op) //dynamic array
{
    struct student* ptr3;
    ptr3 = (struct student*)realloc(ptr2, (n + 1) * sizeof(struct student));
    if (ptr3 == NULL)
    {
        printf("failed to allocate\n");
        return 0;
    }
    if(op == 1)
        data_(&ptr3[n], n + 1);
    if (op == 2)
        data_auto(&ptr3[n]);
    n++;
    return ptr3;
}
struct student* add_element_m(struct student* ptr2, int n_, int op)//dynamic array
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
    if(op == 1)
        data_(&ptr3[position_], position_ + 1);
    if (op == 2)
        data_auto(&ptr3[position_]);
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
void data_auto(struct student* ptr_d)
{
    char name[] = "Cayde";
    strcpy_s((ptr_d->name), 6, name);
    ptr_d->ID = 45;
    ptr_d->bday.day = 4;
    ptr_d->bday.month = 9;
    ptr_d->bday.year = 2018;
    ptr_d->score_ = 7777;
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
void add_node(node** list, node** tail, int spot,int op, char order) //linked lists
{
    node* n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("failed to allocate memory\n");
        return;
    }
    if( op == 1)
        get_data(n, spot);
    if (op == 2)
        get_data_auto(n);
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

void addbet(node** list, int num_ , int op)
{
    node* n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("failed to allocate memory\n");
        return;
    }
    if(op == 1)
        get_data(n, num_n / 2 + 1);
    if (op == 2)
        get_data_auto(n);
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
void get_data_auto(node* n) //new
{
    char name[] = "Cayde";
    strcpy_s((n->students.name), 6, name);
    n->students.ID = 6;
    n->students.bday.day = 4;
    n->students.bday.month = 9;
    n->students.bday.year = 2018;
    n->students.score_ = 7777;
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
        add_node(&list, &tail, i + 1,1, 't');
    }
    while (1)
    {
        printf("Enter the desired operation:-\n(1)insert at the beginning.\n(2)insert at the end.\n(3)insert at the middle.\n(4)Time complexity at the beginning.\n(5)Time complexity at the end\n(6)Time complexity in the middle\n(7)Exit\n");
        op = add_integer(&op);
        if (op == 7)
        {
            break;
        }
        do {
            
            switch (op)
            {
            case (1):
            {
                add_node(&list, &tail, num_,1, 'h');
                //get_data(list, 1);
                break;
            }
            case (2):
            {
                add_node(&list, &tail, num_,1, 't'); //end
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
                addbet(&list, num_,1);
                break;
            }
            case(4):
            {
                clock_t start;
                clock_t end;
                for (int i = 0; i < 500; i++)
                {
                    start = clock();
                    add_node(&list, &tail, num_, 2, 'h');
                    end = clock();
                    double TimeTaken = (double)(end - start) / CLOCKS_PER_SEC;
                    printf("Time Complexity for inserting at the beggining : %f\n", TimeTaken);
                }
                return;
            }
            case(5):
            {
                clock_t start;
                clock_t end;
                for (int i = 0; i < 500; i++)
                {
                    start = clock();
                    add_node(&list, &tail, num_, 2, 't');
                    end = clock();
                    double TimeTaken = (double)(end - start) / CLOCKS_PER_SEC;
                    printf("Time Complexity for inserting at the end : %f\n", TimeTaken);
                }
                return;
            }
            case(6):
            {
                clock_t start;
                clock_t end;
                for (int i = 0; i < 500; i++)
                {
                    start = clock();
                    addbet(&list, num_, 2);
                    end = clock();
                    double TimeTaken = (double)(end - start) / CLOCKS_PER_SEC;
                    printf("Time Complexity for inserting in the middle : %f\n", TimeTaken);
                }
                return;
            }
            case(7):
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
        printf("Enter the desired operation:-\n(1)insert at the beginning.\n(2)insert at the end.\n(3)insert in the middle.\n(4)Time complexity at the begining\n(5)Time complexity at the end\n(6) Time complexity in the middle \n(7)Exit\n");
        scanf_s("%i", &op1);
        if (op1 == 7)
            break;
        do {
            
            
            switch (op1)
            {
            case(1):
            {
                students = insert_begin(students, n,1);
                break;
            }
            case(2):
            {
                students = add_element_l(students, n,1);
                break;
            }
            case(3):
            {
                if (n <= 0)
                {
                    printf("insufficient number of students\n");
                    break;
                }

                students = add_element_m(students, n,1);
                break;
            }
            case(4):
            {
                clock_t start;
                clock_t end;
                for (int i = 0; i < 500; i++)
                {
                    start = clock();
                    students = insert_begin(students, n, 2);
                    end = clock();
                    double TimeTaken = (double)(end - start) / CLOCKS_PER_SEC;
                    printf("Time Complexity for inserting at the beggining : %f\n", TimeTaken);
                }
                return;
            }
            case(5):
            {
                clock_t start;
                clock_t end;
                for (int i = 0; i < 500; i++)
                {
                    start = clock();
                    students = add_element_l(students, n, 2);
                    end = clock();
                    double TimeTaken = (double)(end - start) / CLOCKS_PER_SEC;
                    printf("Time Complexity for inserting at the end : %f\n", TimeTaken);
                }
                return;
            }
            case(6):
            {
                clock_t start;
                clock_t end;
                for (int i = 0; i < 500; i++)
                {
                    start = clock();
                    students = add_element_m(students, n, 2);
                    end = clock();
                    double TimeTaken = (double)(end - start) / CLOCKS_PER_SEC;
                    printf("Time Complexity for inserting in the middle : %f\n", TimeTaken);
                }
                return;
            }
            case(7):
                break;
            }
        } while ((op1 > 4) || (op1 == 0));
        print_(students, n);
    }
   
    printf("the size of the structure is %i ", sizeof(struct student));
    free(students);
}