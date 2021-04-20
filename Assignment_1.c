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
//globals
int num_n;
int num_;
char garbage;
//functions
void print_l(node* list);
void add_node(node** list, node** tail, int num_, char order);
void addbet(node** list, int num_);
void get_data(node* n, int num_);
void free_(node* list);
int add_integer(int* req);
void linked_list();

int main()
{
	int choice;
	printf("Choose an option to continue.\n(1)Linked lists.\n(2)Dynamic arrays.\nInput:");
	do {
		choice = add_integer(&choice);
	} while ((choice != 1) && (choice != 2));
	//scanf_s("%i", &choice);
	if (choice == 1)
	{
		linked_list();
	}


}

void add_node(node** list, node** tail, int spot, char order)
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

	do {
		printf("Enter the desired operation:-\n(1)insert at the beginning.\n(2)insert at the end.\n(3)insert at the middle.\n(4)Exit.\n");
		op = add_integer(&op);
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
	printf("\nThe number of nodes is : %i\n", num_n);
	printf("The size of the structure is %i\n", sizeof(struct student));
	printf("The size of a node is %i\n", sizeof(node));
	free_(list);
}