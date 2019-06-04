#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <malloc.h> //윈도우에서는 필수

//#define SIZE 100

void DisplayArray(int array[], int n);

int main()
{
    //int data[SIZE];
    int *data=NULL;
    int n = 0;

    srand(time(NULL));

    printf("How many random number do you need? ");
    scanf("%d", &n);

   data=(int*)malloc(sizeof(int)*n);

    for(int i = 0; i < n; i++)
        data[i] = rand() % 100 + 1;

    DisplayArray(data, n);
    putchar('\n');
    free(data);
    return 0;
}

void DisplayArray(int array[], int n)
{
    int i = 0;

    for(i = 0; i < n; i++){
        printf("%3d ", array[i]);
        if((i+1)%10 == 0)
            putchar('\n');
    }
}