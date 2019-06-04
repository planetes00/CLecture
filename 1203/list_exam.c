#include <stdio.h>

typedef struct tPerson {
    char name[64];
    char date_of_birth[16];
    struct tPerson *next;
} Person;

void DisplayByIndex(Person list[], int n);

int main()
{
    Person avengers[3] = {
        { "Tony Stark", "19700529", NULL},
        { "Steven Rogers", "19180704", NULL },
        { "Natasha Romanova", "19841122", NULL }
    };
    Person *head = NULL;


    // List all members
    DisplayByIndex(avengers, 3);


    // Connect members by age in ascending order
    head = &avengers[2];
    avengers[2].next=&avengers[0];
    avengers[0].next=&avengers[1];

    // List avengers following links



    return 0;
}


void DisplayByIndex(Person list[], int n)
{
    int i = 0;

    for(i = 0; i < n; i++)
        printf("%-24s %s\n", list[i].name, list[i].date_of_birth);
}

