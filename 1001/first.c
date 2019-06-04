#include <stdio.h>

int main()
{
    int sum=0,x=0;
    int testEOF=0;

    printf("ENTER YOUR NUMBERS <EOF> TO STOP \n");
    do{
        testEOF=scanf("%d",&x);
        if(testEOF!=EOF){
            sum+=x;
        }
    }
    while (testEOF!=EOF);
    printf("total : %d\n",sum);
    return 0;
}