#include <stdio.h>
int main()
{
    int a=10, b=20;
    int temp=0;
    printf("before : a=%d, b=%d\n",a,b);
    temp=a;
    a=b;
    b=temp;
    printf("after : a=%d, b=%d\n",a,b);
    return 0;
}