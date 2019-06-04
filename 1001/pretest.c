#include <stdio.h>

int main()
{
    int n=0,i=0;

    printf("this is a pretest loop\n");
    printf("input a number: ");
    scanf("%d",&n);
    while(i<n){
        printf("i=%d\n",i);
        i++;
    }
    return 0;
}