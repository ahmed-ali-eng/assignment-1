#include <stdio.h>
#include <stdlib.h>
struct bday 
{
    int day;
    int month;
    int year;
};

struct student
{
    char *name;
    int ID;
    struct bday b_day;
    int score;
    struct student* next;
};
int main()
{
    printf("Welcome\n");
    return 0;
}